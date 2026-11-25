#!/usr/bin/env python3
"""Byte-exact matching against a user-supplied local reference executable with
the real MSVC 6 compiler under wine (the gta2_re workflow, object-level).

Every reconstructed function carries a marker on the line(s) above it and the
original address as a name suffix (Source/Function.hpp):

    MATCH_FUNC(0x461370)            // claimed byte-exact; checked, must stay green
    void TDrawArea::HLine_461370(...)

    WIP_FUNC(0x4613F8)              // written, not matching yet; diffed, never fails the run

The TU is compiled with VC6 cl.exe (/O2 /Gy: one COMDAT section per function),
the function's section is found by the `_<addr>` in its symbol name, and its
bytes are compared with the original at that VA. Relocated fields (calls to
other functions, globals, jump tables) are masked.

    match.py                       # all marked TUs; [N/M] MATCH_FUNCs OK; exit 1 on a broken match
    match.py Source/gfx/x.cpp      # one TU, diff every non-matching function
    match.py --target 0x461370     # original asm, call targets named from the catalog
    match.py --next 20             # smallest unmarked functions: candidates to match next

Toolchain: VC6_ROOT, else refs/gta2_re_compile_tools
(git clone https://github.com/CriminalRETeam/gta2_re_compile_tools refs/gta2_re_compile_tools).
"""
import argparse
import difflib
import glob
import json
import os
import re
import struct
import subprocess
import sys

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = os.path.abspath(os.environ.get("AOE_BIN")
                       or os.path.join(ROOT, "reference", "AOE2.EXE"))
CATALOG = os.path.join(ROOT, "data", "disasm32_catalog.json")
OUT = os.path.join(ROOT, "build", "vc6")
VC6 = os.environ.get("VC6_ROOT", os.path.join(ROOT, "refs", "gta2_re_compile_tools"))
# Measured on sub_461370: /O2 reproduces the original byte for byte. The
# original calls memset rather than inlining it, so intrinsics the original
# didn't use get `#pragma function(...)` in Source/Function.hpp.
# /GX: the original's TDrawArea functions carry EH frames (fs:[0] prologue +
# state var in sub_460740), so its TU was built with exception handling on;
# without it VC6 drops the frame and the new/delete dance loses its unwind
# bookkeeping. The plain-C leaves in obj_misc.cpp are unaffected.
CFLAGS = ["/nologo", "/c", "/O2", "/Gy", "/GX", "/W3", "/I", "Source"]
# CRT/runtime band (docs/matching_plan.md): library code, not picked by --next (docs/matching.md).
CRT_LO, CRT_HI = 0x5F0000, 0x610000
MARKER = re.compile(r"\b(MATCH|WIP)_FUNC\(\s*0x([0-9A-Fa-f]+)\s*\)")

md = Cs(CS_ARCH_X86, CS_MODE_32)


def winpath(p):
    return "Z:" + os.path.abspath(p).replace("/", "\\")


def compile_tus(cpps):
    """One cl.exe run per output directory (wine startup dominates)."""
    by_dir = {}
    for c in cpps:
        by_dir.setdefault(os.path.dirname(os.path.relpath(c, ROOT)), []).append(c)
    env = dict(os.environ, WINEDEBUG="-all",
               WINEPATH=f"{winpath(VC6 + '/Common/MSDev98/Bin')};{winpath(VC6 + '/VC98/Bin')}",
               INCLUDE=winpath(VC6 + "/VC98/Include"))
    ok = True
    for d, files in by_dir.items():
        od = os.path.join(OUT, d)
        os.makedirs(od, exist_ok=True)
        for f in files:                          # a failed compile must not leave a stale obj
            obj = os.path.join(od, os.path.splitext(os.path.basename(f))[0] + ".obj")
            if os.path.exists(obj):
                os.remove(obj)
        r = subprocess.run(["wine", os.path.join(VC6, "VC98", "Bin", "CL.EXE"), *CFLAGS,
                            "/Fo" + winpath(od) + "\\", *[winpath(f) for f in files]],
                           cwd=ROOT, env=env, capture_output=True, text=True, errors="replace")
        for line in r.stdout.splitlines():
            if re.search(r"error|warning", line):
                print(line)
        ok &= r.returncode == 0
    return ok


def read_coff(path):
    """{symbol name: (code bytes, set of masked byte offsets)} for every
    function symbol that starts a /Gy COMDAT section."""
    b = open(path, "rb").read()
    _, nsec, _, symoff, nsym, opt, _ = struct.unpack_from("<HHIIIHH", b, 0)
    strtab = symoff + nsym * 18
    secs = []
    for i in range(nsec):
        s = 20 + opt + i * 40
        size, raw, reloc, _, nreloc = struct.unpack_from("<IIIIH", b, s + 16)
        data = b[raw:raw + size]
        masked = set()
        for r in range(nreloc):
            rva, _, rtype = struct.unpack_from("<IIH", b, reloc + r * 10)
            masked.update(range(rva, rva + 4))   # ponytail: masks DIR32/REL32 targets, doesn't check them; resolve against the catalog when a wrong callee slips through
        secs.append((data, masked))
    funcs = {}
    i = 0
    while i < nsym:
        name, value, secnum, typ, sclass, naux = struct.unpack_from("<8sIhHBB", b, symoff + i * 18)
        if name[:4] == b"\0\0\0\0":
            o = strtab + struct.unpack_from("<I", name, 4)[0]
            name = b[o:b.index(b"\0", o)]
        name = name.rstrip(b"\0").decode()
        if typ == 0x20 and secnum > 0 and value == 0:
            funcs[name] = secs[secnum - 1]
        i += 1 + naux
    return funcs


def markers(cpp):
    return [(m.group(1), int(m.group(2), 16)) for m in MARKER.finditer(open(cpp, errors="replace").read())]


def find_symbol(funcs, va):
    """Match the address suffix in the function-name part only.

    The full mangled name includes the class, and many recovered class names
    embed the address of their anchor function (C_cluster_4CED80). Searching
    the whole symbol then finds every member of that class, not one function.
    """
    tag = f"_{va:X}"
    hits = []
    for n in funcs:
        bare = n[1:] if n[:1] in ("?", "_") else n
        name = bare.split("@", 1)[0]
        if re.search(tag + r"(?![0-9A-F])", name, re.I):
            hits.append(n)
    return hits[0] if len(hits) == 1 else (None if not hits else hits)


def original(va, size):
    pe = pefile.PE(EXE, fast_load=True)
    return pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, size)


def asm_lines(code, base, masked=()):
    out = []
    for ins in md.disasm(code, base):
        off = ins.address - base
        reloc = any(o in masked for o in range(off, off + ins.size))
        text = f"{ins.mnemonic} {ins.op_str}".strip()
        if reloc:                                # relocated operand: compare shape only
            text = re.sub(r"0x[0-9a-f]+", "<reloc>", text)
        out.append((off, text))
    return out


def show_diff(orig, ours, masked):
    a = asm_lines(orig, 0, masked)
    b = asm_lines(ours, 0, masked)
    sm = difflib.SequenceMatcher(a=[t for _, t in a], b=[t for _, t in b], autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        for k in range(max(i2 - i1, j2 - j1)):
            l = a[i1 + k] if i1 + k < i2 else None
            r = b[j1 + k] if j1 + k < j2 else None
            mark = " " if tag == "equal" else "!"
            ls = f"{l[0]:04x} {l[1]}" if l else ""
            rs = f"{r[0]:04x} {r[1]}" if r else ""
            print(f"  {mark} {ls:<44} {rs}")


def check(cpp, catalog, diff):
    obj = os.path.join(OUT, os.path.splitext(os.path.relpath(cpp, ROOT))[0] + ".obj")
    funcs = read_coff(obj) if os.path.exists(obj) else {}
    results = []
    for kind, va in markers(cpp):
        sym = find_symbol(funcs, va)
        if not isinstance(sym, str):
            why = "no symbol with suffix _%X in the obj" % va if not sym else f"ambiguous: {sym}"
            print(f"{kind}_FUNC 0x{va:X}: {why}")
            results.append((kind, va, False))
            continue
        ours, masked = funcs[sym]
        size = catalog.get(va, {}).get("size", len(ours))
        # A /Gy COMDAT section can carry local jump tables after the function
        # body, which the catalog's size does not count. Accept that tail only
        # when every extra byte is a masked relocation or nop/cc padding, so
        # appended real instructions still fail.
        extra = ours[size:] if len(ours) > size else b""
        tail_ok = all((size + i) in masked or b in (0x90, 0xcc)
                      for i, b in enumerate(extra))
        orig = original(va, size)
        same = len(ours) >= size and tail_ok and all(
            o in masked or orig[o] == ours[o] for o in range(size))
        status = "OK" if same else "FAIL!" if kind == "MATCH" else "differs"
        print(f"{kind}_FUNC 0x{va:X} {sym}: {status}"
              + ("" if same else f"  (ours {len(ours)} bytes, original {size})"))
        if not same and diff:
            show_diff(orig[:size], ours, masked)
        results.append((kind, va, same))
    return results


def load_catalog():
    return {f["address"]: f for f in json.load(open(CATALOG))["functions"]}


def target(va, catalog):
    f = catalog.get(va)
    if not f:
        sys.exit(f"0x{va:X} is not a function start in the catalog")
    code = original(va, f["size"])
    for ins in md.disasm(code, va):
        note = ""
        if ins.mnemonic == "call" and ins.op_str.startswith("0x"):
            t = int(ins.op_str, 16)
            note = f"   ; {catalog[t]['name'] if t in catalog else '?'} ({catalog.get(t, {}).get('size', '?')} bytes)"
        print(f"0x{ins.address:08x}  {ins.bytes.hex():<20} {ins.mnemonic} {ins.op_str}{note}")


def all_marked():
    return sorted(c for c in glob.glob(os.path.join(ROOT, "Source", "**", "*.cpp"), recursive=True)
                  if "/lifted/" not in c and markers(c))


def next_targets(n, catalog):
    done = {va for c in all_marked() for _, va in markers(c)}
    cand = [f for f in catalog.values()
            if not f["is_thunk"] and f["address"] not in done
            and not CRT_LO <= f["address"] < CRT_HI and 16 <= f["size"] <= 400]
    for f in sorted(cand, key=lambda f: (len(f["calls_to"]), f["size"]))[:n]:
        print(f"0x{f['address']:06X}  {f['size']:4d} bytes  {len(f['calls_to'])} calls")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("files", nargs="*")
    ap.add_argument("--target", help="print the original asm of a function")
    ap.add_argument("--next", type=int, metavar="N", help="list N unmarked candidates")
    ap.add_argument("-v", "--verbose", action="store_true", help="diff non-matching functions in the full run too")
    args = ap.parse_args()
    catalog = load_catalog()
    if args.target:
        return target(int(args.target, 16), catalog)
    if args.next:
        return next_targets(args.next, catalog)
    if not os.path.isdir(os.path.join(VC6, "VC98")):
        sys.exit(f"VC6 not found at {VC6} (set VC6_ROOT)")
    cpps = [os.path.abspath(f) for f in args.files] or all_marked()
    if not cpps:
        sys.exit("no TU with MATCH_FUNC/WIP_FUNC markers")
    compiled = compile_tus(cpps)
    results = [r for c in cpps for r in check(c, catalog, args.verbose or bool(args.files))]
    claimed = [r for r in results if r[0] == "MATCH"]
    ok = sum(1 for r in claimed if r[2])
    wip_ok = [f"0x{va:X}" for k, va, s in results if k == "WIP" and s]
    print(f"[{ok}/{len(claimed)}] MATCH_FUNCs OK, {len(results) - len(claimed)} WIP")
    if wip_ok:
        print("WIP now matching (promote to MATCH_FUNC): " + ", ".join(wip_ok))
    sys.exit(0 if compiled and ok == len(claimed) else 1)


if __name__ == "__main__":
    main()
