#!/usr/bin/env python3
"""Recover the binary's class skeleton from vtable evidence + known names.

Sources: data/disasm32_catalog.json (function starts), the lifted code's
constructor vtable stores (MEM32(this) = 0x61xxxxu), docs/symbol_map.md
(scoped Class::method strings), data/engine_strings.json, and the MATCH/WIP
markers already in Source/.

Outputs:
  data/function_map.json  every real function start, region, best name, state
  data/class_map.json     every recovered vtable class and its slot list
  docs/class_map.md       summary tables (generated)
"""
import glob, json, os, re, struct
import pefile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = os.path.abspath(os.environ.get("AOE_BIN")
                      or os.path.join(ROOT, "reference", "AOE2.EXE"))
CAT = os.path.join(ROOT, "data", "disasm32_catalog.json")
TEXT_LO, TEXT_HI = 0x401000, 0x5F0000

# address regions: coarse evidence only, not a class/module claim
REGIONS = [
    (0x000000, 0x400000, "thiscod"), (0x401000, 0x421000, "app"),
    (0x421000, 0x440000, "game"), (0x440000, 0x470000, "gfx"),
    (0x470000, 0x520000, "ui"), (0x520000, 0x5D0000, "sim"),
    (0x5D0000, 0x5F0000, "engine-late"), (0x5F0000, 0x610000, "crt"),
    (0x600000, 0x1000000, "runtime-data"),
]

MARKER = re.compile(r"\b(MATCH|WIP)_FUNC\(\s*0x([0-9A-Fa-f]+)\s*\)")


def region(va):
    for lo, hi, name in REGIONS:
        if lo <= va < hi:
            return name
    return "unclassified"


def section_map():
    pe = pefile.PE(EXE, fast_load=True)
    base = pe.OPTIONAL_HEADER.ImageBase
    secs = []
    for s in pe.sections:
        lo = s.VirtualAddress + base
        hi = lo + s.Misc_VirtualSize
        secs.append((lo, hi, s.get_data()))
    return base, secs


BASE, SECS = section_map()


def rd(addr, n):
    for lo, hi, data in SECS:
        if lo <= addr and addr + n <= hi:
            return data[addr - lo:addr - lo + n]
    return None


def r32(addr):
    d = rd(addr, 4)
    return struct.unpack("<I", d)[0] if d else None


def vtable_candidates():
    """Vtable constants written into an object at offset 0 by a constructor
    (`MEM32(esi) = 0x0061C524u` and siblings, any destination)."""
    cands = set()
    for path in glob.glob(os.path.join(ROOT, "Source", "lifted", "recomp_0*.c")):
        text = open(path, errors="replace").read()
        for m in re.finditer(r"MEM32\([^)]*\) = (0x00[0-9A-F]{6})u", text):
            va = int(m.group(1)[2:], 16)
            if 0x610000 <= va < 0x670000:
                cands.add(va)
    return sorted(cands)


def vtables():
    """Segment candidates at the next candidate: without RTTI the vtable
    arrays sit back-to-back, so the next constructor's vtable starts the
    next class."""
    cands = vtable_candidates()
    out = []
    for i, va in enumerate(cands):
        nxt = cands[i + 1] if i + 1 < len(cands) else None
        slots = []
        for k in range(0, 4096):
            addr = va + 4 * k
            if nxt is not None and addr >= nxt:
                break
            v = r32(addr)
            if v is None or not (TEXT_LO <= v < TEXT_HI):
                break
            slots.append(v)
        if slots:
            out.append((va, slots, nxt))
    return out


def scoped_names():
    named = {}
    text = open(os.path.join(ROOT, "docs", "symbol_map.md")).read()
    for m in re.finditer(r"\| `([A-Za-z_]\w*)::(\w+)` \| ([^|]+) \|", text):
        ident = f"{m.group(1)}::{m.group(2)}"
        for a in re.findall(r"sub_([0-9A-F]+)", m.group(3)):
            named.setdefault(int(a, 16), set()).add(ident)
    return named


def string_names():
    out = {}
    for e in json.load(open(os.path.join(ROOT, "data", "engine_strings.json"))):
        if not e.get("owners"):
            continue
        s = e["string"]
        if re.match(r"^[A-Za-z_]\w*::\w+$", s):
            for o in e["owners"]:
                out.setdefault(int(o.split()[0], 16), set()).add(s)
    return out


def marker_states():
    states = {}
    files = {}
    for path in glob.glob(os.path.join(ROOT, "Source", "**", "*.cpp"), recursive=True):
        if "/lifted/" in path:
            continue
        text = open(path, errors="replace").read()
        for kind, a in MARKER.findall(text):
            va = int(a, 16)
            states[va] = "matched" if kind == "MATCH" else "wip"
            files[va] = os.path.relpath(path, ROOT)
    return states, files


def autopilot_files():
    out = {}
    for path in glob.glob(os.path.join(ROOT, "Source", "autopilot", "auto_*.c")):
        m = re.search(r"auto_([0-9a-f]{6})\.c$", path)
        if m:
            out[int(m.group(1), 16)] = os.path.relpath(path, ROOT)
    return out


def import_modules():
    """ida function list: direct DLL import name -> module hint."""
    lib_of = {
        "dplayx": "net", "wsock32": "net", "ws2_32": "net",
        "winmm": "sound", "dsound": "sound",
        "ddraw": "gfx", "gdi32": "gfx", "msvfw32": "gfx",
        "user32": "win", "shell32": "win", "advapi32": "win", "imm32": "win",
    }
    out = {}
    for f in json.load(open(os.path.join(ROOT, "data", "functions.json"))):
        mods = set()
        for imp in f.get("imports", []):
            m = re.match(r"__imp_(\w+?)_(A|W)\d*$", imp) or re.match(r"__imp_(\w+)", imp)
            if m and m.group(1).lower() in lib_of:
                mods.add(lib_of[m.group(1).lower()])
        if len(mods) == 1:
            out[int(f["addr"], 16)] = mods.pop()
    return out


CLASS_PREFIX = [
    ("diam_map", "gfx"), ("stat_obj", "game"), ("mouseptr", "win"),
    ("pnl_", "ui"), ("scr_", "ui"), ("panel_", "ui"),
    ("TribePopUpHelp", "ui"), ("TribeTechHelp", "ui"), ("Tribe", "ui"),
    ("basegame", "app"), ("TRIBE_", "ui"), ("RGE_", "game"),
]


def module_of(va, names, imports):
    for ident in names:
        cls = ident.split("::")[0]
        for prefix, mod in CLASS_PREFIX:
            if cls.startswith(prefix):
                return mod
    if va in imports:
        return imports[va]
    return region(va)


def write_skeleton(classes, funcs):
    """Declarations-only skeleton so the remaining work is visible by class.
    Nothing here is compiled or marked MATCH/WIP; it is a map, not a claim."""
    skel = os.path.join(ROOT, "Source", "skeleton")
    for path in glob.glob(os.path.join(skel, "**", "*.h"), recursive=True):
        if "/generated-" in open(path, errors="replace").read(200):
            os.remove(path)
    seen = set()
    for c in classes:
        path = os.path.join(skel, c["region"], f"{c['class']}_{c['vtable'][2:]}.h")
        os.makedirs(os.path.dirname(path), exist_ok=True)
        name = c["class"]
        while name in seen:
            name += "_"
        seen.add(name)
        out = []
        out.append("// GENERATED by Scripts/class_map.py — declaration map, not built.\n")
        out.append(f"// Class candidate: {c['class']}; vtable {c['vtable']}; "
                   f"{c['slots']} slots; region {c['region']}.\n")
        out.append("// Evidence: a constructor writes this vtable at [object+0]; the slots\n")
        out.append("// below are consecutive pointers into .text. When no specific class\n")
        out.append("// name is proven, the class is labelled by vtable address only.\n")
        if c["known_class_names"]:
            out.append(f"// Known slot names: {', '.join(c['known_class_names'])} "
                       "(inherited names repeat).\n")
        out.append("#pragma once\n\n")
        out.append(f"class {name} {{\npublic:\n")
        for i, m in enumerate(c["methods"]):
            note = f"// slot +0x{4*i:03X}: {m['name']} [{m['state']}]"
            if m["file"]:
                note += f" — {m['file']}"
            out.append(f"    virtual void slot_{i:03d}();  {note}\n")
        out.append("};\n")
        open(path, "w").write("".join(out))
        os.chmod(path, 0o644)

    # free / non-virtual functions: no vtable evidence, so declarations grouped
    # by coarse region for the work map; signatures are placeholders.
    region_files = {}
    for f in funcs:
        if f["class"]:
            continue
        region_files.setdefault(f["region"], []).append(f)
    for reg, items in region_files.items():
        path = os.path.join(skel, "free", f"free_{reg}.h")
        os.makedirs(os.path.dirname(path), exist_ok=True)
        out = ["// GENERATED by Scripts/class_map.py — declaration map, not built.\n",
               f"// {len(items)} real functions with no vtable evidence, region {reg}.\n",
               "// Signatures are unknown; these are placeholders, not an ABI claim.\n",
               "#pragma once\n\n"]
        for f in sorted(items, key=lambda x: int(x["address"], 16)):
            note = f"  // size {f['size']}, calls {f['calls']}, {f['state']}, module {f['module']}"
            out.append(f"void {f['name']}();{note}\n")
        open(path, "w").write("".join(out))


def main():
    cat = {f["address"]: f for f in
           json.load(open(CAT))["functions"] if f.get("entry_kind") == "start"}
    scoped = scoped_names()
    strings = string_names()
    states, files = marker_states()
    auto = autopilot_files()
    imports = import_modules()

    def names_of(va):
        return sorted(scoped.get(va, set()) | strings.get(va, set()))

    def state_of(va):
        if va in states:
            return states[va]
        if va in auto:
            return "verified"
        return "lifted"

    vt = vtables()
    slot_class = {}
    classes = []
    for va, slots, nxt in vt:
        hit = {}
        for s in slots:
            for ident in names_of(s):
                hit.setdefault(ident.split("::")[0], []).append(ident)
        # A derived vtable repeats its base class methods (panel_ez, tpnl_*,
        # basegame). Name by the most specific class present; if only a base
        # class appears, the derived name is unknown, so keep the address.
        specific = {k: v for k, v in hit.items()
                    if k not in ("panel_ez", "basegame")}
        if specific:
            label = f"C_{max(specific, key=lambda k: len(specific[k]))}"
        else:
            label = f"C_vt{va:06X}"
        methods = []
        for s in slots:
            n = names_of(s)
            methods.append({
                "address": f"0x{s:06X}",
                "name": n[0] if n else f"sub_{s:06X}",
                "state": state_of(s),
                "file": files.get(s),
            })
            slot_class.setdefault(s, label)
        classes.append({
            "class": label,
            "vtable": f"0x{va:06X}",
            "slots": len(slots),
            "next_vtable": f"0x{nxt:06X}" if nxt else None,
            "known_class_names": sorted(hit),
            "region": region(slots[0]),
            "methods": methods,
        })

    funcs = []
    for va, f in sorted(cat.items()):
        n = names_of(va)
        funcs.append({
            "address": f"0x{va:06X}",
            "size": f["size"],
            "calls": len(f.get("calls_to", [])),
            "name": n[0] if n else f"sub_{va:06X}",
            "names": n,
            "class": slot_class.get(va),
            "module": module_of(va, n, imports),
            "region": region(va),
            "state": state_of(va),
            "file": files.get(va),
        })

    json.dump(funcs, open(os.path.join(ROOT, "data", "function_map.json"), "w"), indent=1)
    json.dump(classes, open(os.path.join(ROOT, "data", "class_map.json"), "w"), indent=1)
    write_skeleton(classes, funcs)

    # summary
    from collections import Counter
    slot_funcs = set(slot_class)
    st = Counter(x["state"] for x in funcs)
    mod = Counter(x["module"] for x in funcs)
    reg = Counter(x["region"] for x in funcs)
    named_classes = [c for c in classes if c["known_class_names"]]
    for c in classes:
        c["matched_slots"] = sum(1 for m in c["methods"] if m["state"] == "matched")
        c["state_counts"] = Counter(m["state"] for m in c["methods"])
    lines = []
    lines.append("# Class and function map (generated)\n")
    lines.append("Generated by `Scripts/class_map.py` from vtable constructor stores, the\n"
                 "catalog, symbol strings, and existing reconstruction markers. Regenerate\n"
                 "when a vtable or name is recovered. Machine-readable forms:\n"
                 "`data/function_map.json` and `data/class_map.json`.\n")
    lines.append("## What is evidence-backed\n")
    lines.append(f"- {len(funcs)} real function starts (`entry_kind == start`; the catalog's other\n"
                 f"  {len(json.load(open(CAT))['functions']) - len(funcs)} entries are interior/alias fragments).\n")
    lines.append(f"- {len(classes)} vtable classes recovered; {len(slot_funcs)} distinct functions are\n"
                 "  virtual slots. This is real class membership (constructor writes the vtable).\n")
    lines.append(f"- {len(named_classes)} of those vtables contain a scoped-assert `Class::method`;\n"
                 "  their names below are proven. The rest are address-labelled until named.\n")
    lines.append(f"- {len(scoped)} functions carry a scoped name; {len(strings)} carry an engine\n"
                 "  debug string name; the rest stay `sub_XXXXXX`. Names are evidence, not guesses.\n")
    lines.append("- Non-virtual classes are *not* recoverable from vtables. They can only be\n"
                 "  inferred from call-site `this` offsets / field clustering, and stay out of\n"
                 "  this map until that evidence is gathered.\n")
    lines.append("\n## Reconstruction state\n")
    lines.append("| State | Functions |\n|---|---|\n")
    for k in ["matched", "wip", "verified", "lifted"]:
        lines.append(f"| {k} | {st[k]} |\n")
    lines.append("\n## Vtable classes\n")
    lines.append("| Vtable | Class | Slots | Known names | Matched | Remaining |\n"
                 "|---|---|---|---|---|---|\n")
    for c in sorted(classes, key=lambda x: x["vtable"]):
        hs = c["state_counts"]
        remaining = c["slots"] - hs["matched"]
        known = ", ".join(c["known_class_names"]) or "—"
        lines.append(f"| `{c['vtable']}` | `{c['class']}` | {c['slots']} | "
                     f"{known} | {hs['matched']} | {remaining} |\n")
    lines.append("\n## Region distribution (coarse address evidence only)\n")
    lines.append("| Region | Functions |\n|---|---|\n")
    for k, n in reg.most_common():
        lines.append(f"| {k} | {n} |\n")
    lines.append("\n## Module hint distribution (names/imports, else falls back to region)\n")
    lines.append("| Module hint | Functions |\n|---|---|\n")
    for k, n in mod.most_common():
        lines.append(f"| {k} | {n} |\n")
    free = [f for f in funcs if not f["class"]]
    freest = Counter(f["state"] for f in free)
    lines.append("\n## Functions with no vtable evidence\n")
    lines.append("| Region | Functions | Matched | WIP | Left |\n|---|---|---|---|---|\n")
    for reg_name, n in reg.most_common():
        st2 = Counter(f["state"] for f in free if f["region"] == reg_name)
        lines.append(f"| {reg_name} | {n} | {st2['matched']} | {st2['wip']} | "
                     f"{n - st2['matched'] - st2['wip']} |\n")
    lines.append("\n## Skeleton tree\n")
    lines.append("`Source/skeleton/` holds declarations only, generated from this map and\n"
                 "not compiled by `Scripts/match.py` or the boot: one header per vtable class,\n"
                 "plus `Source/skeleton/free/free_<region>.h` for functions without vtable\n"
                 "evidence. Signatures there are placeholders, not ABI claims. Regenerate with\n"
                 "`Scripts/class_map.py`; do not hand-edit.\n")
    lines.append("\n## Limitations\n")
    lines.append(f"- {len(classes) - len(named_classes)} vtables have no proven class name and are\n"
                 "  labelled by address; the slot names inside are also mostly unknown.\n")
    lines.append("- Vtable boundaries are inferred from consecutive constructor writes; a class\n"
                 "  with no recovered constructor can be merged into a neighbour. Slot order is\n"
                 "  exact; the boundary is the inference.\n")
    lines.append("- Non-virtual (data-only) classes are absent: no vtable, no recovered `this` type.\n"
                 "  They show up only as free declarations in the skeleton.\n")
    lines.append("- `module` is a hint from known names/imports and falls back to the address\n"
                 "  region. It is not a claim about the original source file.\n")
    open(os.path.join(ROOT, "docs", "class_map.md"), "w").write("".join(lines))
    print(f"[{len(funcs)} functions] [{len(classes)} vtable classes, "
          f"{len(named_classes)} named] [{len(slot_funcs)} virtual slots]")


if __name__ == "__main__":
    main()
