#!/usr/bin/env python3
"""Batch differential verifier.

Registry-driven: each entry describes an original function (VA, size,
convention, argument model) and the reconstruction source+symbol. The harness
emulates original bytes and compiled reconstruction under unicorn with the
same fuzzed inputs and compares return value + memory effects.

Usage: verify_batch.py [filter-substring]
"""
import os
import random
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from diffharness import (load_original_text, run_code, DATA_BASE, CODE_ORIG_BASE,
                     CODE_RECON_BASE)
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
import capstone

MINGW = "i686-w64-mingw32-g++"


def compile_recon(src, symbol, workdir):
    obj = os.path.join(workdir, "recon.o")
    subprocess.run([MINGW, "-O2", "-fno-exceptions", "-fno-rtti", "-c",
                    src, "-o", obj], check=True)
    nm = subprocess.run(["i686-w64-mingw32-nm", obj],
                        capture_output=True, text=True, check=True).stdout
    sym_off = None
    for line in nm.splitlines():
        parts = line.split()
        if len(parts) == 3 and parts[2] == "_" + symbol:
            sym_off = int(parts[0], 16)
    hdr = subprocess.run(["i686-w64-mingw32-objdump", "-h", obj],
                         capture_output=True, text=True, check=True).stdout
    text_size = text_off = None
    for line in hdr.splitlines():
        parts = line.split()
        if len(parts) >= 7 and parts[1] == ".text":
            text_size = int(parts[2], 16)
            text_off = int(parts[5], 16)
    assert sym_off is not None, f"symbol _{symbol} not found in {obj}:\n{out}"
    with open(obj, "rb") as f:
        data = f.read()
    text = data[text_off:text_off + text_size]
    # Bound the function: disassemble until a `ret` followed by padding/end.
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    code = b""
    buf = text[sym_off:]
    for ins in md.disasm(buf, 0):
        code += ins.bytes
        if ins.mnemonic.startswith("ret"):
            nxt = ins.address + ins.size
            if nxt >= len(buf) or buf[nxt] == 0x90:
                break
    return code


def original_bytes(images, va, size):
    for name, (base, data) in images.items():
        off = va - base
        if 0 <= off < len(data):
            return data[off:off + size]
    raise AssertionError(f"VA {va:#x} not in any section")


def run_case(code, base, args, convention, mem_init):
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    return run_code(uc, base, code, 0, args, convention, len(args), mem_init)


def compare_spec(spec, images, recon_code, n_cases, seed):
    va = int(spec["va"], 16)
    size = spec["size"]
    orig = original_bytes(images, va, size)
    convention = spec["convention"]
    argmodel = spec["args"]
    rng = random.Random(seed)
    fails = 0
    for i in range(n_cases):
        args, mem_init, check = argmodel(rng, i)
        eax_o, writes_o = run_case(orig, CODE_ORIG_BASE, args, convention, mem_init)
        eax_r, writes_r = run_case(recon_code, CODE_RECON_BASE, args, convention, mem_init)
        # final memory state over the scratch region
        uc_o = Uc(UC_ARCH_X86, UC_MODE_32)
        run_code(uc_o, CODE_ORIG_BASE, orig, 0, args, convention, len(args), mem_init)
        uc_r = Uc(UC_ARCH_X86, UC_MODE_32)
        run_code(uc_r, CODE_RECON_BASE, recon_code, 0, args, convention, len(args), mem_init)
        mem_o = uc_o.mem_read(DATA_BASE, 0x10000)
        mem_r = uc_r.mem_read(DATA_BASE, 0x10000)
        if eax_o != eax_r or mem_o != mem_r:
            fails += 1
            if fails <= 3:
                print(f"  MISMATCH case {i}: eax o/r={eax_o:#x}/{eax_r:#x}")
    return fails, n_cases
