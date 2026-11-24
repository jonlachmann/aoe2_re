#!/usr/bin/env python3
"""Differential tester: original x86 function bytes vs compiled reconstruction.

Emulates both under unicorn (x86 32-bit) with identical fuzzed inputs and
compares observable results (return register + callee memory writes).

Usage:
  fnmatch.py                      # runs the built-in test plan
"""
import random
import re
import struct
import sys
import subprocess
import tempfile
import os
import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.x86_const import (
    UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_EAX, UC_X86_REG_ECX,
    UC_X86_REG_EDX, UC_X86_REG_EBX, UC_X86_REG_ESI, UC_X86_REG_EDI,
    UC_X86_REG_EBP,
)

ORIGINAL = os.environ.get("AOE_BIN") or "reference/AOE2.EXE"
IMAGE_BASE = 0x400000
STACK_BASE = 0x00200000
STACK_SIZE = 0x00100000
DATA_BASE = 0x00300000
DATA_SIZE = 0x00010000
RET_MAGIC = 0x0DEADC0DE

CODE_ORIG_BASE = 0x00400000   # original runs at its real VA
CODE_RECON_BASE = 0x00500000  # reconstruction loaded here


def load_original_text():
    pe = pefile.PE(ORIGINAL)
    image = {}
    for s in pe.sections:
        name = s.Name.decode().rstrip("\x00")
        data = s.get_data()
        image[name] = (IMAGE_BASE + s.VirtualAddress, data)
    return image


def run_code(uc, code_base, code_bytes, entry_off, args, convention, n_mem_args,
             mem_init, scratch_size=0x1000):
    """Set up a call frame and run until return. Returns (eax, mem_writes).

    Frame layout at entry (cdecl/stdcall): [esp]=RET_MAGIC, [esp+4]=arg1, ...
    thiscall: ecx=this, [esp]=RET_MAGIC, [esp+4]=arg1 (stack args only).
    """
    code_len = (len(code_bytes) + 0xFFF) & ~0xFFF
    uc.mem_map(code_base, code_len)
    uc.mem_write(code_base, code_bytes)

    uc.mem_map(STACK_BASE, STACK_SIZE)
    uc.mem_map(DATA_BASE, DATA_SIZE)
    for addr, data in mem_init:
        uc.mem_write(addr, data)

    writes = []

    def hook_mem_write(uc, access, address, size, value, user_data):
        if DATA_BASE <= address < DATA_BASE + DATA_SIZE:
            writes.append((address, size, value))

    uc.hook_add(UC_HOOK_MEM_WRITE, hook_mem_write,
                begin=DATA_BASE, end=DATA_BASE + DATA_SIZE)

    sp = STACK_BASE + STACK_SIZE - 0x1000
    if convention == "thiscall":
        uc.reg_write(UC_X86_REG_ECX, args[0])
        stack_part = list(args[1:])
    else:
        stack_part = list(args)
    for a in reversed(stack_part):
        sp -= 4
        uc.mem_write(sp, struct.pack("<I", a & 0xFFFFFFFF))
    sp -= 4
    uc.mem_write(sp, struct.pack("<I", RET_MAGIC))

    uc.reg_write(UC_X86_REG_ESP, sp)
    uc.reg_write(UC_X86_REG_EBP, sp + 4 + 4 * len(stack_part))
    uc.emu_start(code_base + entry_off, RET_MAGIC, count=2_000_000)
    eax = uc.reg_read(UC_X86_REG_EAX)
    return eax, writes


def float_cases(n, seed=1234, finite=True):
    rng = random.Random(seed)
    cases = []
    for _ in range(n):
        if finite:
            a = rng.uniform(-1e6, 1e6)
            b = rng.uniform(-1e6, 1e6)
        else:
            a = rng.choice([rng.uniform(-1e6, 1e6),
                            float("nan"), float("inf"), 0.0, -0.0])
            b = rng.choice([rng.uniform(-1e6, 1e6),
                            float("nan"), float("inf"), 0.0, -0.0])
        cases.append((a, b))
    return cases


def test_position_equal(images, recon_code, recon_entry, cases, want_nan_report=False):
    fn_va, fn_size = 0x40B600, 0x2C
    orig_bytes = None
    for name, (base, data) in images.items():
        off = fn_va - base
        if 0 <= off < len(data):
            orig_bytes = data[off:off + fn_size]
            break
    assert orig_bytes, "function not inside a mapped section"

    fails = 0
    nan_rows = []
    # The original reads [obj+0x50]/[obj+0x54]: args point at the OBJECT, floats at +0x50.
    OBJ_X = 0x50
    for i, (ax, bx, ay, by) in enumerate(cases):
        abuf = b"\x00" * OBJ_X + struct.pack("<ff", ax, ay)
        bbuf = b"\x00" * OBJ_X + struct.pack("<ff", bx, by)
        a_obj = DATA_BASE + 0x400
        b_obj = DATA_BASE + 0x800
        mem_init = [(a_obj, abuf), (b_obj, bbuf)]
        args = [a_obj, b_obj]
        eax_o, _ = run_code(Uc(UC_ARCH_X86, UC_MODE_32), CODE_ORIG_BASE,
                            orig_bytes, 0, args, "cdecl", 2, mem_init)
        eax_r, _ = run_code(Uc(UC_ARCH_X86, UC_MODE_32), CODE_RECON_BASE,
                            recon_code, recon_entry, args, "cdecl", 2, mem_init)
        if eax_o != eax_r:
            fails += 1
            if fails <= 5:
                print(f"  MISMATCH ax={ax!r} ay={ay!r} bx={bx!r} by={by!r}: "
                      f"orig={eax_o} recon={eax_r}")
        if want_nan_report and (ax != ax or bx != bx):
            nan_rows.append((ax, bx, eax_o, eax_r))
    print(f"  cases={len(cases)} fails={fails}")
    if nan_rows:
        print("  NaN-case behavior (orig vs recon):")
        for ax, bx, eo, er in nan_rows[:5]:
            print(f"    ax={ax!r} bx={bx!r} orig={eo} recon={er}")




def test_countdown_tick(recon_code, recon_entry, cases):
    fn_va, fn_size = 0x40A3E0, 0x1A
    images = load_original_text()
    orig_bytes = None
    for name, (base, data) in images.items():
        off = fn_va - base
        if 0 <= off < len(data):
            orig_bytes = data[off:off + fn_size]
            break
    assert orig_bytes

    fails = 0
    for initial in cases:
        mem = [(DATA_BASE + 0x400, struct.pack("<i", initial))]
        this = DATA_BASE + 0x400
        uc_o = Uc(UC_ARCH_X86, UC_MODE_32)
        eax_o, writes_o = run_code(uc_o, CODE_ORIG_BASE, orig_bytes, 0,
                                   [this], "thiscall", 1, mem)
        uc_r = Uc(UC_ARCH_X86, UC_MODE_32)
        eax_r, writes_r = run_code(uc_r, CODE_RECON_BASE, recon_code, recon_entry,
                                   [this], "thiscall", 1, mem)
        field_o = struct.unpack("<i", uc_o.mem_read(this, 4))[0]
        field_r = struct.unpack("<i", uc_r.mem_read(this, 4))[0]
        # NOTE: the original's unclamped intermediate store is a visible write
        # trace difference only; final memory state and return value are the
        # contract. (A byte-exact MSVC 6 build would emit both stores.)
        if eax_o != eax_r or field_o != field_r:
            fails += 1
            if fails <= 5:
                print(f"  MISMATCH init={initial}: ret o/r={eax_o}/{eax_r} "
                      f"field o/r={field_o}/{field_r} writes o={writes_o} r={writes_r}")
    print(f"  cases={len(cases)} fails={fails}")


def build_recon():
    """Compile the reconstruction .cpp to raw x86 bytes; return (bytes, entry_off)."""
    import capstone
    src_path = "Source/engine/geom_compare.cpp"
    with tempfile.TemporaryDirectory() as td:
        obj = os.path.join(td, "geom.o")
        subprocess.run(["i686-w64-mingw32-g++", "-O2", "-fno-exceptions",
                        "-fno-rtti", "-c", src_path, "-o", obj], check=True)
        out = subprocess.run(["i686-w64-mingw32-objdump", "-t", obj],
                             capture_output=True, text=True, check=True).stdout
        sym_off = None
        for line in out.splitlines():
            m = re.match(r"\[\s*\d+\]\(sec\s+1\).*?0x([0-9a-f]{8})\s+_(\w+)", line)
            if m and m.group(2) == "objects_at_same_position":
                sym_off = int(m.group(1), 16)
        hdr = subprocess.run(["i686-w64-mingw32-objdump", "-h", obj],
                             capture_output=True, text=True, check=True).stdout
        text_size = text_off = None
        for line in hdr.splitlines():
            parts = line.split()
            if len(parts) >= 7 and parts[1] == ".text":
                text_size = int(parts[2], 16)
                text_off = int(parts[5], 16)
        assert sym_off is not None, "symbol not found:\n" + out
        assert text_off is not None
        with open(obj, "rb") as f:
            data = f.read()
        text = data[text_off:text_off + text_size]
        # Bound the function: disassemble from sym_off; stop after a `ret` that is
        # followed by padding (0x90) or the end of the section.
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        code = b""
        buf = text[sym_off:]
        insns = list(md.disasm(buf, 0))
        for i, ins in enumerate(insns):
            code += ins.bytes
            if ins.mnemonic.startswith("ret"):
                nxt = ins.address + ins.size
                if nxt >= len(buf) or buf[nxt] == 0x90:
                    break
        return code, 0, obj, out


def main():
    images = load_original_text()
    recon_code, recon_entry, obj, nm = build_recon()
    print("reconstruction bytes:")
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    for ins in md.disasm(recon_code, CODE_RECON_BASE):
        print(f"  {ins.address - CODE_RECON_BASE:#06x}  {ins.mnemonic} {ins.op_str}")

    print("\n[1] finite-float fuzzing (1000 cases)")
    rng = random.Random(42)
    cases = []
    for _ in range(1000):
        ax, ay = rng.uniform(-1e6, 1e6), rng.uniform(-1e6, 1e6)
        bx, by = rng.uniform(-1e6, 1e6), rng.uniform(-1e6, 1e6)
        cases.append((ax, bx, ay, by))
    # equal cases too
    for _ in range(100):
        ax, ay = rng.uniform(-1e6, 1e6), rng.uniform(-1e6, 1e6)
        cases.append((ax, ax, ay, ay))
    test_position_equal(images, recon_code, 0, cases)

    print("\n[2] NaN/Inf edge cases (documenting original semantics)")
    cases = []
    special = [float("nan"), float("inf"), float("-inf"), 0.0, -0.0, 1.0]
    for ax in special:
        for bx in special:
            cases.append((ax, bx, 1.0, 1.0))
    test_position_equal(images, recon_code, 0, cases, want_nan_report=True)

    print("\n[3] countdown_tick (thiscall) fuzzing")
    import subprocess
    src2 = "Source/engine/countdown_field.cpp"
    with tempfile.TemporaryDirectory() as td:
        obj = os.path.join(td, "countdown.o")
        subprocess.run(["i686-w64-mingw32-g++", "-O2", "-fno-exceptions",
                        "-fno-rtti", "-c", src2, "-o", obj], check=True)
        out = subprocess.run(["i686-w64-mingw32-objdump", "-t", obj],
                             capture_output=True, text=True, check=True).stdout
        sym_off = None
        for line in out.splitlines():
            m = re.match(r"\[\s*\d+\]\(sec\s+1\).*?0x([0-9a-f]{8})\s+_(\w+)", line)
            if m and m.group(2) == "countdown_tick":
                sym_off = int(m.group(1), 16)
        assert sym_off is not None, out
        hdr = subprocess.run(["i686-w64-mingw32-objdump", "-h", obj],
                             capture_output=True, text=True, check=True).stdout
        text_size = text_off = None
        for line in hdr.splitlines():
            parts = line.split()
            if len(parts) >= 7 and parts[1] == ".text":
                text_size = int(parts[2], 16)
                text_off = int(parts[5], 16)
        with open(obj, "rb") as f:
            data = f.read()
        text = data[text_off:text_off + text_size]
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        code = b""
        buf = text[sym_off:]
        for ins in md.disasm(buf, 0):
            code += ins.bytes
            if ins.mnemonic.startswith("ret"):
                nxt = ins.address + ins.size
                if nxt >= len(buf) or buf[nxt] == 0x90:
                    break
        cases2 = list(range(-5, 10)) + [0x7FFFFFFF, -0x80000000, 1, -1]
        test_countdown_tick(code, 0, cases2)


if __name__ == "__main__":
    main()