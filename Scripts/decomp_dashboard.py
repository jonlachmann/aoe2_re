#!/usr/bin/env python3
"""decomp_dashboard.py -- the readable track's registry and dashboard.

Merges every naming/verification source into one function registry
(data/function_states.json) and renders MATCHING.md: per-module progress of
the promotion pipeline  lifted -> autoported/verified -> promoted -> active.

Sources (all measured, none hand-maintained):
  data/disasm32_catalog.json   19,140 functions (disasm32 view)
  data/functions.json          7,113 IDA-view functions with calls/imports
  data/verified_functions.json 479 differentially verified reconstructions
  data/engine_strings.json     625 engine-debug strings, 148 with owners
  data/string_named_functions.json  11 string-named functions
  docs/symbol_map.md           scoped-assert names (Class::method)
  Source/autopilot|verified|engine/*.c(pp)   reconstruction files on disk
  Source/host/overrides.c      active overrides (weak-symbol pilot)

Modules follow docs/matching_plan.md's map; a function is classified by, in
order: its verified file's directory, its scoped-assert name's class prefix,
its address band (CRT / THIS_COD), the Win32 libraries its code touches
(dplayx->net, winmm->sound/music, ddraw/gdi->gfx, ...), else "unclassified".
"""
import json
import os
import re
import sys
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA = os.path.join(ROOT, "data")
DOCS = os.path.join(ROOT, "docs")

MODULES = ["app", "win", "gfx", "data", "game", "net", "sound", "crt", "thiscod", "unclassified"]

# address bands (docs/matching_plan.md inventory)
CRT_LO, CRT_HI = 0x5F0000, 0x610000
THISCOD_LO, THISCOD_HI = 0x210000, 0x400000

# library -> module, from the import a function calls (docs/platform_imports.md)
LIB_OF_IMPORT = {
    "dplayx": "net", "wsock32": "net", "ws2_32": "net",
    "winmm": "sound", "dsound": "sound",
    "ddraw": "gfx", "gdi32": "gfx", "msvfw32": "gfx", "d3d": "gfx",
    "user32": "win", "shell32": "win", "advapi32": "win", "imm32": "win",
    "kernel32": None,  # CRT/utility: not evidence of a module
    "ole32": None, "oleaut32": None, "comctl32": None, "lz32": None,
}

# scoped-assert class prefixes -> module (docs/symbol_map.md vocabulary)
CLASS_PREFIX = [
    ("diam_map", "gfx"), ("stat_obj", "game"), ("mouseptr", "win"),
    ("pnl_", "win"), ("scr_", "win"), ("panel_", "win"),
    ("TribePopUpHelp", "win"), ("TribeTechHelp", "win"),
    ("Tribe", "win"), ("basegame", "app"), ("comm", "net"), ("COMM", "net"),
    ("RGE_", "game"), ("mixer", "sound"),
]


def load_catalog():
    cat = json.load(open(os.path.join(DATA, "disasm32_catalog.json")))
    out = {}
    for f in cat["functions"]:
        out[f["address"]] = {"name": f["name"], "size": f["size"],
                             "calls_to": f.get("calls_to", []),
                             "is_thunk": f.get("is_thunk", False)}
    return out


def load_ida_view():
    """data/functions.json: imports + calls as symbol names."""
    out = {}
    for f in json.load(open(os.path.join(DATA, "functions.json"))):
        out[int(f["addr"], 16)] = f
    return out


def scoped_names():
    """docs/symbol_map.md resolved table: 0xADDR | Name | func list."""
    names = {}
    txt = open(os.path.join(DOCS, "symbol_map.md")).read()
    for m in re.finditer(r"^\| 0x([0-9a-f]+) \| `([A-Za-z_][\w:]*)` \| ([^|]+)\|",
                         txt, re.M):
        ident = m.group(2)
        for fn in re.findall(r"sub_([0-9A-Fa-f]{6,8})", m.group(3)):
            names.setdefault(int(fn, 16), set()).add(ident)
    return names


def engine_string_names():
    """engine_strings.json owners: '0x41bc80 sub_41BC80'."""
    out = {}
    for e in json.load(open(os.path.join(DATA, "engine_strings.json"))):
        if not e.get("owners"):
            continue
        s = e["string"]
        if not re.match(r"^[A-Za-z_]\w*::\w+$|^[A-Za-z_]\w+$", s):
            continue
        for o in e["owners"]:
            va = int(o.split()[0], 16)
            out.setdefault(va, set()).add(s)
    # string_named_functions.json: debug strings naming their function
    for va, v in json.load(open(os.path.join(DATA, "string_named_functions.json"))).items():
        out.setdefault(int(va, 16), set()).update(v.get("strings", []))
    return out


MARKER = re.compile(r"\b(MATCH|WIP)_FUNC\(\s*0x([0-9A-Fa-f]+)\s*\)")


def recon_files():
    """Readable-track files on disk: addr -> [(path, state)]. Engine modules
    (Source/<module>/ per docs/decomp.md) hold hand-written reconstructions;
    autopilot/ holds the mechanical ports. A filename carries the address; a
    file whose name has none (e.g. geom_compare.cpp) states it in a header
    comment `sub_XXXXXXXX`."""
    found = {}
    subs = [(m, "promoted") for m in ("app", "win", "gfx", "data", "game", "net", "sound", "crt")]
    subs += [("engine", "promoted"), ("verified", "promoted"), ("autopilot", "autoported")]
    for sub, state in subs:
        d = os.path.join(ROOT, "Source", sub)
        if not os.path.isdir(d):
            continue
        for fn in sorted(os.listdir(d)):
            path = os.path.join("Source", sub, fn)
            vas = set()
            text = open(os.path.join(d, fn), errors="replace").read()
            marked = {int(a, 16) for k, a in MARKER.findall(text)}
            if marked:                           # MATCH_FUNC/WIP_FUNC markers (docs/matching.md)
                for k, a in MARKER.findall(text):
                    found.setdefault(int(a, 16), []).append((path, "matched" if k == "MATCH" else state))
                continue
            m = re.search(r"(?:sub_)?([0-9A-Fa-f]{6,8})", fn)
            if m:
                vas.add(int(m.group(1), 16))
            else:                                # read the VA from the header comment
                head = open(os.path.join(d, fn), errors="replace").read(400)
                m2 = re.search(r"sub_([0-9A-Fa-f]{6,8})\b", head)
                if m2:
                    vas.add(int(m2.group(1), 16))
            for va in vas:
                found.setdefault(va, []).append((path, state))
    return found


def active_overrides():
    """Addresses overridden in Source/host/overrides.c."""
    path = os.path.join(ROOT, "Source", "host", "overrides.c")
    out = set()
    if os.path.exists(path):
        for m in re.finditer(r"void sub_([0-9A-Fa-f]{8})\(", open(path).read()):
            out.add(int(m.group(1), 16))
    return out


def classify(va, name, ida, scoped, strings, recon):
    """Module for one function; first evidence wins (docs/matching_plan.md)."""
    if recon:
        sub = recon[0][0]
        m = re.match(r"Source/(\w+)/", sub)
        if m and m.group(1) in ("app", "win", "gfx", "data", "game", "net", "sound", "crt"):
            return m.group(1)                   # the module dir is the claim
        if "/engine/" in sub or "/verified/" in sub:
            return "game"                       # refined by hand below
    if va < THISCOD_HI:
        return "thiscod"
    if CRT_LO <= va < CRT_HI:
        return "crt"
    for ident in set(scoped.get(va, set())) | set(strings.get(va, set())):
        cls = ident.split("::")[0] if "::" in ident else ident
        for prefix, mod in CLASS_PREFIX:
            if cls.startswith(prefix):
                return mod
    if ida:
        for imp in ida.get("imports", []):
            lib = re.match(r"__imp_(\w+?)_(A|W)\d*$", imp)
            lib = lib.group(1) if lib else re.match(r"__imp_(\w+)", imp)
            if lib:
                mod = LIB_OF_IMPORT.get(lib.group(1).lower())
                if mod:
                    return mod
    return "unclassified"


def build():
    cat = load_catalog()
    ida = load_ida_view()
    scoped = scoped_names()
    strings = engine_string_names()
    recon = recon_files()
    overrides = active_overrides()
    verified = {int(a, 16) for a in json.load(open(os.path.join(DATA, "verified_functions.json")))}

    funcs = {}
    for va, f in cat.items():
        names = sorted(scoped.get(va, set()) | strings.get(va, set()))
        ida_f = ida.get(va, {})
        files = recon.get(va, [])
        # highest stage wins: active > verified (a file that passed difftest)
        # > autoported (a mechanical port, tested) > promoted-file > lifted
        state = "lifted"
        if files:
            state = "autoported"
        if va in verified:
            state = "verified"
        if files and any(s == "promoted" for _, s in files) and va not in verified:
            state = "promoted"
        if any(s == "matched" for _, s in files):
            state = "matched"                    # byte-exact under VC6 (Scripts/match.py)
        if va in overrides:
            state = "active"
        funcs[va] = {
            "name": f["name"],
            "names": names,
            "size": f["size"],
            "is_thunk": f["is_thunk"],
            "module": classify(va, f["name"], ida_f, scoped, strings, files),
            "state": state,
            "files": [p for p, _ in files],
            "ncalls_out": ida_f.get("ncalls_out", len(f.get("calls_to", []))),
            "imports": ida_f.get("imports", []),
        }
    return funcs


def render_md(funcs, out_path):
    by_mod = defaultdict(list)
    for va, f in sorted(funcs.items()):
        by_mod[f["module"]].append((va, f))
    # per-module counts by state
    states = ["active", "matched", "promoted", "verified", "autoported", "lifted"]
    total = len(funcs)
    lines = []
    lines.append("# MATCHING — readable-track dashboard\n")
    lines.append("Generated by `Scripts/decomp_dashboard.py` from measured data; do not edit.\n")
    lines.append("\n## Pipeline: lifted -> autoported -> verified -> promoted -> matched -> active\n")
    lines.append("| module | funcs | named | " + " | ".join(states) + " |")
    lines.append("|---|---:|---:|" + "---:|" * len(states))
    gtot = defaultdict(int)
    for mod in MODULES:
        fs = by_mod.get(mod, [])
        if not fs:
            continue
        named = sum(1 for _, f in fs if f["names"])
        counts = [sum(1 for _, f in fs if f["state"] == s) for s in states]
        for s, c in zip(states, counts):
            gtot[s] += c
        lines.append(f"| {mod} | {len(fs)} | {named} | " + " | ".join(str(c) for c in counts) + " |")
    lines.append(f"| **total** | **{total}** | "
                 f"**{sum(1 for f in funcs.values() if f['names'])}** | "
                 + " | ".join(f"**{gtot[s]}**" for s in states) + " |")
    lines.append("\n(`verified` = differentially tested vs original bytes; `promoted` = a "
                 "hand-written readable file exists in `Source/engine|verified`; `matched` = "
                 "byte-exact under VC6, `MATCH_FUNC` checked by `Scripts/match.py`; `active` = "
                 "wired in as an override in `Source/host/overrides.c`.)\n")

    # Named functions, the visible structure so far
    lines.append("\n## Named functions (scoped asserts + engine strings)\n")
    lines.append("| VA | name(s) | module | state |")
    lines.append("|---|---|---|---|")
    for va, f in sorted(funcs.items()):
        if f["names"]:
            lines.append(f"| 0x{va:06X} | {', '.join(f['names'])} | {f['module']} | {f['state']} |")

    # The biggest unlifted callers, as promotion targets
    lines.append("\n## Promotion targets: largest unnamed functions still `lifted`\n")
    lines.append("| VA | size | ncalls_out | imports |")
    lines.append("|---|---:|---:|---|")
    big = [(va, f) for va, f in sorted(funcs.items(), key=lambda kv: -kv[1]["size"])
           if not f["names"] and f["state"] == "lifted" and not f["is_thunk"]][:40]
    for va, f in big:
        lines.append(f"| 0x{va:06X} | {f['size']} | {f['ncalls_out']} | {', '.join(i.replace('__imp_','') for i in f['imports'][:4])} |")
    open(out_path, "w").write("\n".join(lines) + "\n")


def main():
    funcs = build()
    with open(os.path.join(DATA, "function_states.json"), "w") as fh:
        json.dump({f"0x{va:06X}": f for va, f in sorted(funcs.items())}, fh, indent=1)
    render_md(funcs, os.path.join(ROOT, "MATCHING.md"))
    n_named = sum(1 for f in funcs.values() if f["names"])
    print(f"registry: {len(funcs)} functions, {n_named} named -> data/function_states.json, MATCHING.md")


if __name__ == "__main__":
    main()