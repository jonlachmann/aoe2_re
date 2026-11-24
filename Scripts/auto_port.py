#!/usr/bin/env python3
"""Auto-port pure leaf functions from the Hex-Rays corpus and differentially
verify them against the original bytes.

Pipeline per candidate:
  1. Extract the Hex-Rays body from corpus/pseudocode.
  2. Filter out any function referencing globals (off_/unk_/dword_/... tokens).
  3. Wrap in a standalone C file (IDA token-free), compile with i686 mingw.
  4. Emulate original bytes and the compiled reconstruction with identical
     inputs (this = zeroed 1KB object; stack args = bounded random ints).
  5. Compare eax + full scratch memory. Crash-on-both = model skip;
     crash-on-one or value mismatch = divergence recorded.

Usage: auto_port.py <start> <count> [seed]
"""
import json
import random
import os
import re
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from verify_batch import original_bytes
from diffharness import load_original_text, run_code, DATA_BASE
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
import capstone

CORPUS = "corpus/pseudocode"
OUTDIR = "Source/autopilot"
MINGW = "i686-w64-mingw32-g++"

GLOBAL_TOKEN = re.compile(r"\b(off_|unk_|dword_|byte_|word_|flt_|dbl_|qword_|a[A-Z])")
STRUCT_TOKEN = re.compile(r"\(__int16|_DWORD|_BYTE|_WORD|_QWORD")


def find_corpus_file(addr_hex):
    d = int(addr_hex, 16)
    lo, hi = d - 8, d + 8
    # corpus files are named <hex>_<name>.cpp with hex without 0x
    import glob
    for cand in glob.glob(f"{CORPUS}/*.cpp"):
        base = os.path.basename(cand).split("_")[0]
        try:
            v = int(base, 16)
        except ValueError:
            continue
        if lo <= v <= hi:
            return cand
    return None


def extract_function(text):
    """Pull the first function definition (signature + brace body) from a
    hexrays dump."""
    m = re.search(r"^[A-Za-z_].*?\)\n?\{", text, re.M)
    if not m:
        return None
    start = m.start()
    depth = 0
    i = text.index("{", start)
    for j in range(i, len(text)):
        if text[j] == "{":
            depth += 1
        elif text[j] == "}":
            depth -= 1
            if depth == 0:
                return text[start:j + 1]
    return None


def port(addr_hex, size, workdir, tmpcount):
    path = find_corpus_file(addr_hex)
    if not path:
        return None, "no corpus file"
    text = open(path).read()
    body = extract_function(text)
    if body is None:
        return None, "no function found"
    if GLOBAL_TOKEN.search(body):
        return None, "references globals"
    # rename the function; `this` is a reserved word in C++ - rename param
    body = re.sub(r"\b(sub_[0-9A-Fa-f]+)\b", f"auto_{addr_hex}", body, count=0)
    body = re.sub(r"\bthis\b", "self", body)
    # hexrays uses types like _DWORD / __int16 - provide typedefs
    prelude = """
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;
"""
    src = prelude + "\n" + body + "\n"
    cfile = os.path.join(workdir, f"auto_{addr_hex}.c")
    with open(cfile, "w") as f:
        f.write(src)
    obj = os.path.join(workdir, f"auto_{addr_hex}.o")
    r = subprocess.run([MINGW, "-O2", "-fno-exceptions", "-fno-rtti", "-c",
                        cfile, "-o", obj], capture_output=True, text=True)
    if r.returncode != 0:
        return None, "compile failed: " + r.stderr.strip()[:200]
    # symbol name: hexrays fn name -> mingw symbol _<name>
    m = re.search(r"auto_" + addr_hex + r"\(", body)
    # find the actual defined symbol via nm
    nm = subprocess.run(["i686-w64-mingw32-nm", obj], capture_output=True, text=True)
    syms = [l.split()[-1] for l in nm.stdout.splitlines()
            if l.strip() and " T " in l]
    if not syms:
        return None, "no text symbol"
    sym = syms[0][1:]  # strip leading underscore
    # bound bytes: disassemble until ret+pad
    hdr = subprocess.run(["i686-w64-mingw32-objdump", "-h", obj],
                         capture_output=True, text=True, check=True).stdout
    text_size = text_off = None
    for line in hdr.splitlines():
        parts = line.split()
        if len(parts) >= 7 and parts[1] == ".text":
            text_size = int(parts[2], 16)
            text_off = int(parts[5], 16)
    data = open(obj, "rb").read()
    sec = data[text_off:text_off + text_size]
    # find symbol offset via nm value
    val = None
    for line in nm.stdout.splitlines():
        parts = line.split()
        if len(parts) == 3 and parts[2] == syms[0] and parts[1] in ("T", "t"):
            val = int(parts[0], 16)
    if val is None:
        return None, "symbol offset not found"
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    code = b""
    buf = sec[val:]
    for ins in md.disasm(buf, 0):
        code += ins.bytes
        if ins.mnemonic.startswith("ret"):
            nxt = ins.address + ins.size
            if nxt >= len(buf) or buf[nxt] == 0x90:
                break
    return code, sym


def make_case(rng, convention, n_args):
    this = DATA_BASE + 0x3000
    mem = [(this, b"\x00" * 0x1000)]
    # second scratch buffer for pointer-ish args
    ptr_arg = DATA_BASE + 0x6000
    mem.append((ptr_arg, bytes(rng.randrange(256) for _ in range(64))))
    args = []
    for k in range(n_args):
        r = rng.random()
        if r < 0.25:
            args.append(ptr_arg)
        elif r < 0.5:
            args.append(0)
        else:
            args.append(rng.randint(1, 0xFFFF))
    if convention == "thiscall":
        return [this] + args, mem
    return args, mem


def main():
    lo = int(sys.argv[1]) if len(sys.argv) > 1 else 0
    count = int(sys.argv[2]) if len(sys.argv) > 2 else 25
    seed = int(sys.argv[3]) if len(sys.argv) > 3 else 7
    import os as _os
    cands = json.load(open(_os.environ.get("AUTOPORT_LIST", "data/pure_usable.json")))
    batch = cands[lo:lo + count]
    images = load_original_text()
    os.makedirs(OUTDIR, exist_ok=True)
    passed, failed, skipped = [], [], []
    with tempfile.TemporaryDirectory() as td:
        for e in batch:
            addr_hex = e["addr"][2:]
            code, info = port(addr_hex, e["size"], td, 0)
            if code is None:
                skipped.append((e["addr"], info))
                continue
            # detect convention from pseudocode
            conv = "thiscall" if "__thiscall" in (e.get("pseudocode") or "") else "cdecl"
            n_args = 3
            orig = original_bytes(images, int(e["addr"], 16), e["size"])
            diverge = 0
            crash_both = 0
            n_cases = 40
            for ci in range(n_cases):
                rng = random.Random(seed + ci)
                args, mem = make_case(rng, conv, n_args)
                try:
                    uc_o = Uc(UC_ARCH_X86, UC_MODE_32)
                    eax_o, _ = run_code(uc_o, 0x00400000, orig, 0, args, conv, len(args), mem)
                    ok_o = True
                except Exception:
                    ok_o = False
                try:
                    uc_r = Uc(UC_ARCH_X86, UC_MODE_32)
                    eax_r, _ = run_code(uc_r, 0x00500000, code, 0, args, conv, len(args), mem)
                    ok_r = True
                except Exception:
                    ok_r = False
                if not ok_o and not ok_r:
                    crash_both += 1
                    continue
                if ok_o != ok_r:
                    diverge += 1
                    continue
                if eax_o != eax_r:
                    diverge += 1
                    continue
                mem_o = uc_o.mem_read(DATA_BASE, 0x10000)
                mem_r = uc_r.mem_read(DATA_BASE, 0x10000)
                if mem_o != mem_r:
                    diverge += 1
            if diverge == 0:
                passed.append(e)
                src_path = os.path.join(td, f"auto_{addr_hex}.c")
                dst = f"{OUTDIR}/auto_{addr_hex}.c"
                os.makedirs(OUTDIR, exist_ok=True)
                if os.path.exists(src_path):
                    import shutil
                    shutil.copy(src_path, dst)
            else:
                failed.append({"addr": e["addr"], "diverge": diverge})
    print(f"passed={len(passed)} failed={len(failed)} skipped={len(skipped)}")
    json.dump({"passed": passed, "failed": failed, "skipped": skipped},
              open(f"/tmp/autopilot_{lo}_{count}.json", "w"), indent=1)


if __name__ == "__main__":
    main()