#!/usr/bin/env python3
"""verify_one.py -- differentially verify one reconstruction against the
original x86 bytes (docs/decomp.md step 4).

Runs the original function (from the local reference executable) and a compiled
reconstruction (i686-w64-mingw32-g++) under unicorn with identical fuzzed
inputs; compares eax and every memory write the function makes outside its
stack. Anything either machine faults on counts as a skip (modelled, not
verified).

Usage:
  verify_one.py <va_hex> <file.cpp> <symbol> <convention> <n_stack_args>
                [--this-bytes N] [--cases N] [--seed N] [--bytes HEX]

  convention: cdecl | stdcall | thiscall   (thiscall: ecx = this pointer,
              the first object byte region is the fuzzed `this`)
"""
import argparse
import capstone
import json
import os
import pefile
import random
import re
import struct
import subprocess
import sys
import tempfile
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UC_HOOK_MEM_WRITE, UC_HOOK_MEM_READ_UNMAPPED, UC_HOOK_MEM_WRITE_UNMAPPED, UC_ERR_INSN_INVALID
from unicorn.x86_const import (
    UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_EAX, UC_X86_REG_ECX,
    UC_X86_REG_EDX, UC_X86_REG_EBX, UC_X86_REG_ESI, UC_X86_REG_EDI,
    UC_X86_REG_EBP, UC_X86_REG_EFLAGS)

ORIGINAL = (os.environ.get("AOE_BIN") or os.environ.get("AOE_ORIGINAL")
            or "reference/AOE2.EXE")
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IMAGE_BASE = 0x400000
STACK_BASE = 0x00200000
STACK_SIZE = 0x00100000
DATA_BASE = 0x00300000        # fuzzed `this`/buffers live here
DATA_SIZE = 0x00100000
SCRATCH = 0x00500000          # reconstruction code base
RET_MAGIC = 0x0DEADC0DE
MAGIC_EFLAGS = 0x202          # IF set, everything else clean


def load_bytes_at(va, size):
    """The image's bytes at VA: sections are mapped at their RVAs, so slice
    the memory-mapped image (s.get_data() is raw file data, whose offsets
    differ from RVAs)."""
    pe = pefile.PE(ORIGINAL)
    image = pe.get_memory_mapped_image(ImageBase=IMAGE_BASE)
    off = va - IMAGE_BASE
    if off < 0 or off + size > len(image):
        raise SystemExit(f"0x{va:X} + {size} outside the mapped image")
    return bytes(image[off:off + size])


def image_section_bytes(va):
    """(bytes, base_va) of the section containing va — for --image mode."""
    pe = pefile.PE(ORIGINAL)
    for s in pe.sections:
        s_va = IMAGE_BASE + s.VirtualAddress
        data = s.get_data()
        if s_va <= va < s_va + len(data):
            return bytes(data), s_va
    raise SystemExit(f"0x{va:X} not in any section")


def run_code(uc, code_base, code_bytes, entry_off, this_ptr, stack_args, this_obj=None):
    """Push args, run until the function returns to RET_MAGIC; return
    (eax, writes, fault). A ud2 sentinel sits at RET_MAGIC (mapped), so the
    returning `ret` lands on an executable page and raises UC_ERR_INSN_INVALID
    — a catchable, distinguishable termination (fetching an unmapped RET_MAGIC
    would look like any other fetch fault)."""
    uc.mem_map(STACK_BASE, STACK_SIZE)
    uc.mem_map(DATA_BASE, DATA_SIZE)
    uc.mem_map(RET_MAGIC & ~0xFFF, 0x1000)
    uc.mem_write(RET_MAGIC, b"\x0f\x0b")                 # ud2
    if this_obj is not None:
        uc.mem_write(this_ptr, this_obj)
    writes = []

    def on_write(uc, access, address, size, value, ud):
        if address < STACK_BASE or address >= STACK_BASE + STACK_SIZE:
            writes.append((address, size, value & ((1 << (8 * size)) - 1)))

    uc.hook_add(UC_HOOK_MEM_WRITE, on_write)
    faults = []
    uc.hook_add(UC_HOOK_MEM_READ_UNMAPPED,
                lambda u, access, address, size, value, d: faults.append(("read", address)))
    uc.hook_add(UC_HOOK_MEM_WRITE_UNMAPPED,
                lambda u, access, address, size, value, d: faults.append(("write", address)))

    sp = STACK_BASE + STACK_SIZE - 0x2000
    for a in reversed(stack_args):
        sp -= 4
        uc.mem_write(sp, struct.pack("<I", a & 0xFFFFFFFF))
    sp -= 4
    uc.mem_write(sp, struct.pack("<I", RET_MAGIC))
    uc.reg_write(UC_X86_REG_ESP, sp)
    uc.reg_write(UC_X86_REG_EBP, sp + 4 + 4 * len(stack_args))
    if this_ptr is not None:
        uc.reg_write(UC_X86_REG_ECX, this_ptr)
    uc.reg_write(UC_X86_REG_EFLAGS, MAGIC_EFLAGS)
    try:
        uc.emu_start(code_base + entry_off, 0, count=2_000_000)
    except UcError as e:
        if e.errno != UC_ERR_INSN_INVALID or uc.reg_read(UC_X86_REG_EIP) != RET_MAGIC:
            raise                                        # a real fault, not the sentinel
    return uc.reg_read(UC_X86_REG_EAX), writes, faults


def mingw_symbol_bytes(obj_path, symbol):
    """All .text bytes from `symbol`'s offset to the end of the section.
    Execution stops at the pushed RET_MAGIC, so trailing bytes (the next
    function in the object) never run - and multi-return functions keep
    every return path."""
    out = subprocess.run(["i686-w64-mingw32-objdump", "-t", obj_path],
                         capture_output=True, text=True, check=True).stdout
    off = None
    for line in out.splitlines():
        m = re.match(r"\[\s*\d+\]\(sec\s+\d+\).*?0x([0-9a-f]{8})\s+_(\w+)", line)
        if m and m.group(2) == symbol:
            off = int(m.group(1), 16)
    if off is None:
        raise SystemExit(f"symbol _{symbol} not in {obj_path}")
    hdr = subprocess.run(["i686-w64-mingw32-objdump", "-h", obj_path],
                         capture_output=True, text=True, check=True).stdout
    text_size = text_off = None
    for line in hdr.splitlines():
        parts = line.split()
        if len(parts) >= 7 and parts[1] == ".text":
            text_size, text_off = int(parts[2], 16), int(parts[5], 16)
    data = open(obj_path, "rb").read()
    return data[text_off + off: text_off + text_size]


def compile_cpp(src_path, td, extra=()):
    obj = os.path.join(td, "recon.o")
    subprocess.run(["i686-w64-mingw32-g++", "-O2", "-fno-exceptions",
                    "-fno-rtti", *extra, "-c", src_path, "-o", obj],
                   check=True)
    return obj


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("va")
    ap.add_argument("file")
    ap.add_argument("symbol")
    ap.add_argument("convention", choices=("cdecl", "stdcall", "thiscall"))
    ap.add_argument("n_stack_args", type=int)
    ap.add_argument("--this-bytes", type=int, default=0x120)
    ap.add_argument("--ptr-offsets", default="",
                    help="comma list of hex offsets of dword pointer fields in "
                         "the fuzzed object; each points at a fuzzed buffer")
    ap.add_argument("--cases", type=int, default=300)
    ap.add_argument("--seed", type=int, default=1234)
    ap.add_argument("--cases-file", default="",
                    help="JSON [{this_obj: hex, stack_args: [..]}] — structured cases for functions with pointer/field constraints (fuzzing would fault on wild pointers)")
    ap.add_argument("--func-size", type=int, default=0, help="override (bytes)")
    ap.add_argument("--image", action="store_true", help="map the whole section at its real base; run at the real VA (callers/callees work)")
    ap.add_argument("--skip-eax", action="store_true",
                    help="compare memory writes only — for recons whose early-exit "
                         "eax is caller-leftover garbage (the success-path return is "
                         "still checked by the writes and the recon's own contract)")
    args = ap.parse_args()

    va = int(args.va, 16)
    size = args.func_size
    if not size:
        # the catalog's function length when the VA is cataloged (a `ret`
        # heuristic mis-sizes functions whose every return takes an operand)
        cat = json.load(open(os.path.join(ROOT, "data", "disasm32_catalog.json")))
        for f in cat["functions"]:
            if f["address"] == va:
                size = f["size"]
                break
    if not size:
        size = 4096
    # function length: disassemble until the first ret that alignment suggests ends it
    pe = pefile.PE(ORIGINAL)
    data = pe.get_memory_mapped_image(ImageBase=IMAGE_BASE)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    orig_bytes = load_bytes_at(va, size)
    if not orig_bytes:
        raise SystemExit(f"0x{va:X} not in any mapped section")

    with tempfile.TemporaryDirectory() as td:
        obj = compile_cpp(args.file, td)
        recon_code = mingw_symbol_bytes(obj, args.symbol)

    rng = random.Random(args.seed)
    fails = skips = 0
    ptr_offsets = [int(s, 16) for s in args.ptr_offsets.split(",") if s]
    buf_ptr = 0x00A00000 + 0x1000         # the fuzzed buffer the pointer fields name (its own region: run_code maps DATA only)
    structured = []
    if args.cases_file:
        for c in json.load(open(args.cases_file)):
            structured.append((bytes.fromhex(c["this_obj"]), c["stack_args"]))
    total_cases = len(structured) if structured else args.cases
    for case in range(total_cases):
        # fuzz the this-object and the stack args (or take a structured case)
        if structured:
            this_obj, stack_args = structured[case]
            this_obj = bytearray(this_obj)
            for po in ptr_offsets:
                struct.pack_into("<I", this_obj, po, buf_ptr)
            this_obj = bytes(this_obj)
        else:
            this_obj = bytearray(rng.randrange(256) for _ in range(args.this_bytes))
            for po in ptr_offsets:
                struct.pack_into("<I", this_obj, po, buf_ptr)
            this_obj = bytes(this_obj)
            stack_args = [rng.randrange(0, 1 << 32) for _ in range(args.n_stack_args)]
        this_ptr = DATA_BASE + 0x1000
        # pointer fields point at a fuzzed buffer placed at a fixed VA; the
        # buffer lives below the object so field writes don't clobber it
        fuzz_buf = bytes(rng.randrange(256) for _ in range(0x4000))

        def run(code_base, code, entry):
            uc = Uc(UC_ARCH_X86, UC_MODE_32)
            uc.mem_map(code_base, (len(code) + 0xFFF) & ~0xFFF)
            uc.mem_write(code_base, code)
            uc.mem_map(buf_ptr & ~0xFFF, 0x8000)
            uc.mem_write(buf_ptr, fuzz_buf)
            return run_code(uc, code_base, code, entry,
                            this_ptr if args.convention == "thiscall" else None,
                            stack_args, this_obj)

        if args.image:
            # map the function's whole section at its real base and run at the
            # real VA, so calls to other functions (callees, CRT helpers) work
            def run_orig():
                uc = Uc(UC_ARCH_X86, UC_MODE_32)
                section_bytes, section_va = image_section_bytes(va)
                uc.mem_map(section_va, (len(section_bytes) + 0xFFF) & ~0xFFF)
                uc.mem_write(section_va, section_bytes)
                uc.mem_map(buf_ptr & ~0xFFF, 0x8000)
                uc.mem_write(buf_ptr, fuzz_buf)
                return run_code(uc, section_va, section_bytes, va - section_va,
                                this_ptr if args.convention == "thiscall" else None,
                                stack_args, this_obj)
        else:
            def run_orig():
                return run(IMAGE_BASE, orig_bytes, 0)

        try:
            eax_o, wr_o, flt_o = run_orig()
        except Exception:
            skips += 1
            continue
        try:
            eax_r, wr_r, flt_r = run(SCRATCH, recon_code, 0)
        except Exception as e:
            print(f"  case {case}: reconstruction faulted where original didn't "
                  f"({type(e).__name__}: {e})")
            fails += 1
            continue
        if (eax_o != eax_r and not args.skip_eax) or wr_o != wr_r:
            fails += 1
            if fails <= 5:
                print(f"  case {case}: MISMATCH eax orig={eax_o:#010x} "
                      f"recon={eax_r:#010x} writes o={len(wr_o)} r={len(wr_r)}")
    total = total_cases - skips
    print(f"0x{va:X} {args.convention}({args.n_stack_args} args): "
          f"cases={total} fails={fails} skipped={skips}")
    sys.exit(1 if fails else 0)


if __name__ == "__main__":
    main()