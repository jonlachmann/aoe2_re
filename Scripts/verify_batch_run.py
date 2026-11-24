#!/usr/bin/env python3
"""Batch-verify a set of pure leaf functions via differential testing."""
import os
import random
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from verify_batch import compile_recon, original_bytes, run_case, DATA_BASE
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32

SPECS = [
    # 40a370: thiscall(int idx) -> this[idx+36] (dword array), -1 if idx not 1..2
    {
        "name": "sub_40A370", "va": "0x40A370", "size": 0x1E, "convention": "thiscall",
        "src": "Source/verified/sub_40A370.cpp", "symbol": "sub_40A370",
        "model": "arr36",
    },
    # 40e2a0: thiscall() -> word at (this[10]+8), -1 if this[10]==0
    {
        "name": "sub_40E2A0", "va": "0x40E2A0", "size": 0x10, "convention": "thiscall",
        "src": "Source/verified/sub_40E2A0.cpp", "symbol": "sub_40E2A0",
        "model": "ptrfield",
    },
    # 40f4a0: thiscall() -> this[937]==0
    {
        "name": "sub_40F4A0", "va": "0x40F4A0", "size": 0x0E, "convention": "thiscall",
        "src": "Source/verified/sub_40F4A0.cpp", "symbol": "sub_40F4A0",
        "model": "flag937_0",
    },
    # 40f4b0: thiscall() -> this[937]==50
    {
        "name": "sub_40F4B0", "va": "0x40F4B0", "size": 0x0F, "convention": "thiscall",
        "src": "Source/verified/sub_40F4B0.cpp", "symbol": "sub_40F4B0",
        "model": "flag937_50",
    },
]

OBJ_SCRATCH = 0x3000  # object buffer at DATA_BASE+0x3000 (1KB), zero-filled


def make_model(kind):
    def model(rng, i):
        mem = [(DATA_BASE + OBJ_SCRATCH, b"\x00" * 0x1000)]
        this = DATA_BASE + OBJ_SCRATCH
        if kind == "arr36":
            idx = rng.choice([0, 1, 2, 3, 50, -1])
            vals = [rng.randint(-2**31, 2**31 - 1) for _ in range(4)]
            for j, v in enumerate(vals):
                mem.append((this + 4 * (36 + 1 + j), struct.pack("<i", v)))
            return [this, idx], mem, None
        if kind == "ptrfield":
            inner = DATA_BASE + 0x800
            w = rng.randint(-32768, 32767)
            mem.append((inner + 8, struct.pack("<h", w)))
            if i % 3 == 0:
                return [this], mem, None  # this[10]=0
            mem.append((this + 40, struct.pack("<I", inner)))
            return [this], mem, None
        if kind == "flag937_0" or kind == "flag937_50":
            target = 0 if kind == "flag937_0" else 50
            v = rng.choice([target, target, rng.randint(-2**31, 2**31 - 1)])
            mem.append((this + 4 * 937, struct.pack("<i", v)))
            return [this], mem, None
        raise AssertionError(kind)
    return model


def main():
    from diffharness import load_original_text
    images = load_original_text()
    total_fails = 0
    for spec in SPECS:
        recon = compile_recon(spec["src"], spec["symbol"], "/tmp")
        orig = original_bytes(images, int(spec["va"], 16), spec["size"])
        model = make_model(spec["model"])
        fails = 0
        n = 300
        for i in range(n):
            args, mem_init, _ = model(random.Random(i), i)
            eax_o, w_o = run_case(orig, CODE_ORIG := 0x00400000, args,
                                  spec["convention"], mem_init) if False else (None, None)
            # run orig
            from diffharness import run_code
            uc_o = Uc(UC_ARCH_X86, UC_MODE_32)
            eax_o, w_o = run_code(uc_o, 0x00400000, orig, 0, args,
                                  spec["convention"], len(args), mem_init)
            uc_r = Uc(UC_ARCH_X86, UC_MODE_32)
            eax_r, w_r = run_code(uc_r, 0x00500000, recon, 0, args,
                                  spec["convention"], len(args), mem_init)
            mem_o = uc_o.mem_read(DATA_BASE, 0x10000)
            mem_r = uc_r.mem_read(DATA_BASE, 0x10000)
            if eax_o != eax_r or mem_o != mem_r:
                fails += 1
                if fails <= 3:
                    print(f"  MISMATCH {spec['name']} case {i}: "
                          f"eax o/r={eax_o:#x}/{eax_r:#x}")
        status = "PASS" if fails == 0 else f"FAIL({fails})"
        print(f"{spec['name']}  {spec['va']}  {spec['convention']:9s}  "
              f"n={n}  {status}")
        total_fails += fails
    print(f"\nTOTAL FAILS: {total_fails}")


if __name__ == "__main__":
    main()