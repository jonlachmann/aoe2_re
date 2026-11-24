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


# ---------------------------------------------------------------------------
# Non-virtual class inference from call sites.
#
# The lift preserves every original instruction and names ecx assignments, so
# each direct call carries the object expression the callee receives:
#   ecx = esi          -> the callee acts on the caller's own object
#   ecx = esi + 0xNN   -> an embedded sub-object at that offset
#   ecx = MEM32(esi+NN)-> the object stored in that member pointer
#   ecx = MEM32(0xG)   -> a global singleton object
#   ecx = esp + 0xNN   -> a stack-local object
# A callee whose every call site supplies the same object identity is a member
# of that object's class. That is evidence, not address clustering.
REG = r'(eax|ebx|ecx|edx|esi|edi|ebp)'
_ASSIGN = re.compile(rf'^\s*{REG} = (.*);')
_CALL = re.compile(r'RECOMP_CALL\(sub_([0-9A-F]{6,8})\)')
_FUNC = re.compile(r'^void sub_([0-9A-F]{8})\(void\) \{')
_MEM = re.compile(r'MEM(?:8|16|32)\(([^)]*)\)')


def lifted_receivers():
    """va -> {thiscall, fields, calls: [(callee, identity)]}.

    Aliases are tracked only from ecx outward; a write of a non-this value
    clears the alias, so unrelated register copies do not count."""
    funcs = {}
    for path in glob.glob(os.path.join(ROOT, "Source", "lifted", "recomp_0*.c")):
        cur = None
        aliases = set()
        ecx_state = None
        fields = set()
        calls = []
        hits = 0

        def finish():
            if cur is not None:
                funcs[cur] = {"thiscall": hits > 0, "fields": set(fields),
                              "calls": list(calls)}

        for line in open(path, errors="replace"):
            m = _FUNC.match(line)
            if m:
                finish()
                cur = int(m.group(1), 16)
                aliases = {"ecx"}
                ecx_state = ("this",)
                fields = set()
                calls = []
                hits = 0
                continue
            if cur is None:
                continue
            for expr in _MEM.findall(line):
                m2 = re.match(r'^(\w+) \+ (0x[0-9A-F]+)$', expr)
                if m2 and m2.group(1) in aliases:
                    fields.add(int(m2.group(2), 16))
                    hits += 1
            ma = _ASSIGN.match(line)
            if ma:
                r, expr = ma.group(1), ma.group(2)
                if expr == "ecx" or expr in aliases:
                    aliases.add(r)
                else:
                    aliases.discard(r)
                    if r == "ecx":
                        p = re.match(r'^(\w+) \+ (0x[0-9A-F]+)$', expr)
                        mm = re.match(r'^MEM32\((\w+) \+ (0x[0-9A-F]+)\)$', expr)
                        gm = re.match(r'^MEM32\((0x[0-9A-F]+)\)$', expr)
                        lm = re.match(r'^esp \+ (0x[0-9A-F]+)$', expr)
                        if p and p.group(1) in aliases:
                            ecx_state = ("this+off", int(p.group(2), 16))
                        elif mm and mm.group(1) in aliases:
                            ecx_state = ("this_ptr", int(mm.group(2), 16))
                        elif gm:
                            ecx_state = ("global", int(gm.group(1), 16))
                        elif lm:
                            ecx_state = ("local", int(lm.group(1), 16))
                        else:
                            ecx_state = ("other", expr)
            mc = _CALL.search(line)
            if mc:
                calls.append((int(mc.group(1), 16), ecx_state))
        finish()
    return funcs


def receiver_key(caller, ident, class_of):
    """Normalize one call-site object expression into a class-identity key.
    Returns None when the expression is opaque or locally rooted."""
    if not ident:
        return None
    kind = ident[0]
    if kind == "global":
        return ("global", ident[1])
    owner = class_of.get(caller)
    if not owner:
        return None
    if kind == "this":
        return ("this", owner)
    if kind in ("this_ptr", "this+off"):
        return (("member" if kind == "this_ptr" else "embedded"), owner, ident[1])
    return None


def infer_nonvirtual(cat, slot_class_sets, receivers, seed=None):
    """Iteratively assign callees whose every call site agrees on one object
    identity. Returns (class_of, assignments va->(label, evidence), new class
    records). With `seed`, start from already inferred identities instead of
    vtable slots (used after the this-edge component pass)."""
    class_of = dict(seed) if seed else {}
    # a slot shared by several vtables is a base/inherited method: it cannot
    # pin a derived class, so only single-vtable slots seed propagation
    if not seed:
        for va, classes in slot_class_sets.items():
            if len(classes) == 1:
                class_of[va] = next(iter(classes))

    new_classes = {}
    assignments = {}
    for _round in range(4):
        changed = 0
        for callee in cat:
            if callee in class_of:
                continue
            es = receivers.get(callee, {}).get("calls", [])
            if not es:
                continue
            keys = {receiver_key(a, x, class_of) for a, x in es}
            if None in keys or len(keys) != 1:
                continue
            key = next(iter(keys))
            label = None
            if key[0] == "global":
                label = f"C_global_{key[1]:06X}"
                evidence = f"every call site passes the global object at 0x{key[1]:06X}"
                kind = "nonvirtual"
            elif key[0] == "this":
                label = key[1]
                evidence = "same object as the caller's class"
                kind = "member-of-vtable"
            elif key[0] == "member":
                label = f"{key[1]}_member_{key[2]:X}"
                evidence = f"member pointer at +0x{key[2]:X} of {key[1]}"
                kind = "nonvirtual"
            elif key[0] == "embedded":
                label = f"{key[1]}_embedded_{key[2]:X}"
                evidence = f"embedded object at +0x{key[2]:X} of {key[1]}"
                kind = "nonvirtual"
            if not label:
                continue
            if label not in class_of.values() and label not in new_classes:
                if key[0] in ("global", "member", "embedded"):
                    new_classes[label] = {
                        "class": label, "kind": kind, "evidence": evidence,
                        "anchor": f"0x{key[-1]:06X}", "members": [],
                    }
                elif key[0] == "this":
                    # existing class; record as a non-virtual method
                    pass
            class_of[callee] = label
            assignments[callee] = (label, evidence)
            changed += 1
        if not changed:
            break

    # extra methods per new class
    for va, (label, evidence) in assignments.items():
        if label in new_classes:
            new_classes[label]["members"].append(va)
    return class_of, assignments, new_classes


def this_components(class_of, receivers, cat):
    """Union every `ecx = caller's own this` edge. Components carry one class
    if their nodes already agree; components with conflicting classes are left
    alone; rootless components of 2+ functions become low-confidence clusters."""
    parent = {va: va for va in cat}

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union(a, b):
        ra, rb = find(a), find(b)
        if ra != rb:
            parent[rb] = ra

    for va, f in receivers.items():
        if va not in cat or not (0x401000 <= va < 0x5F0000):
            continue
        for callee, ident in f["calls"]:
            if callee not in cat or not (0x401000 <= callee < 0x5F0000):
                continue
            if ident and ident[0] == "this":
                union(va, callee)

    comps = {}
    for va in cat:
        comps.setdefault(find(va), []).append(va)

    assignments = {}
    new_classes = {}
    for root, nodes in comps.items():
        labels = {class_of[v] for v in nodes if v in class_of}
        if len(labels) == 1:
            label = next(iter(labels))
            evidence = "same object, connected by this-edge call sites"
        elif len(labels) > 1:
            continue                                  # inherited/generic mixing
        elif len(nodes) >= 2:
            anchor = min(nodes)
            label = f"C_cluster_{anchor:06X}"
            evidence = "this-edge component with no rooted object identity"
            new_classes[label] = {"class": label, "kind": "cluster",
                                  "evidence": evidence, "anchor": f"0x{anchor:06X}",
                                  "members": []}
        else:
            continue
        for va in nodes:
            if va in class_of:
                continue
            class_of[va] = label
            assignments[va] = (label, evidence)
            if label in new_classes:
                new_classes[label]["members"].append(va)
    return class_of, assignments, new_classes


def write_skeleton(classes, funcs):
    """Declarations-only skeleton so the remaining work is visible by class.
    Nothing here is compiled or marked MATCH/WIP; it is a map, not a claim."""
    skel = os.path.join(ROOT, "Source", "skeleton")
    for path in glob.glob(os.path.join(skel, "**", "*.h"), recursive=True):
        head = open(path, errors="replace").read(200)
        if "// GENERATED by Scripts/class_map.py" in head:
            os.remove(path)
    seen = set()
    for c in classes:
        anchor = (c["vtable"] or f"0x{c['anchor']}").split("0x")[-1].upper()
        path = os.path.join(skel, c["region"], f"{c['class']}_{anchor}.h")
        os.makedirs(os.path.dirname(path), exist_ok=True)
        name = c["class"]
        while name in seen:
            name += "_"
        seen.add(name)
        out = ["// GENERATED by Scripts/class_map.py — declaration map, not built.\n"]
        if c["kind"] == "vtable":
            out.append(f"// Class candidate: {c['class']}; vtable {c['vtable']}; "
                       f"{c['slots']} slots; region {c['region']}.\n")
            out.append("// Evidence: a constructor writes this vtable at [object+0]; the\n")
            out.append("// slots below are consecutive pointers into .text. When no specific\n")
            out.append("// class name is proven, the class is labelled by vtable address only.\n")
            if c["known_class_names"]:
                out.append(f"// Known slot names: {', '.join(c['known_class_names'])} "
                           "(inherited names repeat).\n")
            if c["extra_methods"]:
                out.append("// Extra non-virtual methods below are proven by call-site\n")
                out.append("// `ecx` identity: every caller passes this same object.\n")
        else:
            out.append(f"// Class candidate: {c['class']}; {c['kind']}; region {c['region']}.\n")
            out.append(f"// Evidence: {c['evidence']}.\n")
            out.append("// No vtable: this class exists only as an object identity shape.\n")
        out.append("#pragma once\n\n")
        out.append(f"class {name} {{\npublic:\n")
        if c["kind"] == "vtable":
            for i, m in enumerate(c["methods"]):
                note = f"// slot +0x{4*i:03X}: {m['name']} [{m['state']}]"
                if m["file"]:
                    note += f" — {m['file']}"
                out.append(f"    virtual void slot_{i:03d}();  {note}\n")
            for i, m in enumerate(c["extra_methods"]):
                note = f"// {m['name']} [{m['state']}]: {m['evidence']}"
                if m["file"]:
                    note += f" — {m['file']}"
                out.append(f"    void method_{i:03d}();  {note}\n")
        else:
            for i, m in enumerate(c["methods"]):
                note = f"// {m['name']} [{m['state']}]"
                if m["file"]:
                    note += f" — {m['file']}"
                out.append(f"    void method_{i:03d}();  {note}\n")
        out.append("};\n")
        open(path, "w").write("".join(out))

    # remaining functions with no class evidence: declarations grouped by
    # coarse region for the work map; signatures are placeholders.
    region_files = {}
    for f in funcs:
        if f["class"]:
            continue
        region_files.setdefault(f["region"], []).append(f)
    for reg, items in region_files.items():
        path = os.path.join(skel, "free", f"free_{reg}.h")
        os.makedirs(os.path.dirname(path), exist_ok=True)
        out = ["// GENERATED by Scripts/class_map.py — declaration map, not built.\n",
               f"// {len(items)} real functions with no class evidence, region {reg}.\n",
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
    slot_class_sets = {}
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
            slot_class_sets.setdefault(s, set()).add(label)
        classes.append({
            "class": label,
            "kind": "vtable",
            "vtable": f"0x{va:06X}",
            "anchor": f"0x{slots[0]:06X}",
            "slots": len(slots),
            "next_vtable": f"0x{nxt:06X}" if nxt else None,
            "known_class_names": sorted(hit),
            "region": region(slots[0]),
            "methods": methods,
            "extra_methods": [],
        })
    slot_class = {s: sorted(c)[0] for s, c in slot_class_sets.items()}

    # non-virtual class inference from call-site object identity:
    #   1. strict seeds: every call site agrees on one object identity
    #   2. this-edge components: one rooted class spreads across its methods
    #   3. strict again: member/embedded classes of the newly classed owners
    receivers = lifted_receivers()
    class_of, a1, n1 = infer_nonvirtual(cat, slot_class_sets, receivers)
    class_of, a2, n2 = this_components(class_of, receivers, cat)
    class_of, a3, n3 = infer_nonvirtual(cat, slot_class_sets, receivers, seed=class_of)
    all_assign = {**a1, **a2, **a3}
    all_new = {**n1, **n2, **n3}
    vt_labels = {c["class"] for c in classes}

    for label, rec in all_new.items():
        members = [va for va, lab in class_of.items() if lab == label]
        methods = []
        for va in sorted(members):
            n = names_of(va)
            methods.append({
                "address": f"0x{va:06X}",
                "name": n[0] if n else f"sub_{va:06X}",
                "state": state_of(va),
                "file": files.get(va),
            })
        anchor_va = (min(members) if members
                     else int(rec.get("anchor", "0x401000"), 16))
        classes.append({
            "class": rec["class"],
            "kind": rec["kind"],
            "vtable": None,
            "anchor": f"0x{anchor_va:06X}",
            "slots": len(methods),
            "next_vtable": None,
            "known_class_names": [],
            "evidence": rec["evidence"],
            "region": region(anchor_va),
            "methods": methods,
            "extra_methods": [],
        })
    by_label = {c["class"]: c for c in classes}
    for va, (label, evidence) in all_assign.items():
        c = by_label.get(label)
        if not c or c["kind"] != "vtable" or va in slot_class_sets:
            continue
        n = names_of(va)
        c["extra_methods"].append({
            "address": f"0x{va:06X}",
            "name": n[0] if n else f"sub_{va:06X}",
            "state": state_of(va),
            "file": files.get(va),
            "evidence": evidence,
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
            "class": slot_class.get(va) or class_of.get(va),
            "class_evidence": ("vtable slot" if va in slot_class_sets
                               else (all_assign.get(va) or (None, None))[1]),
            "slot_classes": sorted(slot_class_sets.get(va, ())),
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
    vt_classes = [c for c in classes if c["kind"] == "vtable"]
    nv_classes = [c for c in classes if c["kind"] != "vtable"]
    named_classes = [c for c in vt_classes if c["known_class_names"]]
    classed_funcs = set(slot_class_sets) | set(all_assign)
    extra_assignments = {va: e for va, e in all_assign.items()
                         if va not in slot_class_sets}
    for c in classes:
        all_m = c["methods"] + c["extra_methods"]
        c["total_methods"] = len(all_m)
        c["state_counts"] = Counter(m["state"] for m in all_m)
    lines = []
    lines.append("# Class and function map (generated)\n")
    lines.append("Generated by `Scripts/class_map.py` from vtable constructor stores, the\n"
                 "catalog, symbol strings, and call-site object identity in the lifted code.\n"
                 "Regenerate when a vtable or name is recovered. Machine-readable forms:\n"
                 "`data/function_map.json` and `data/class_map.json`.\n")
    lines.append("## What is evidence-backed\n")
    lines.append(f"- {len(funcs)} real function starts (`entry_kind == start`; the catalog's other\n"
                 f"  {len(json.load(open(CAT))['functions']) - len(funcs)} entries are interior/alias fragments).\n")
    lines.append(f"- {len(vt_classes)} vtable classes recovered; {len(slot_funcs)} distinct functions are\n"
                 "  virtual slots. This is real class membership (constructor writes the vtable).\n")
    lines.append(f"- {len(nv_classes)} non-virtual classes inferred from call-site `ecx` identity:\n"
                 "  every direct call to a member supplies the same global object, the same\n"
                 "  caller object, or the same member offset of the same owner class.\n")
    lines.append(f"- {len(classed_funcs)} real functions are now in a class: {len(slot_class_sets)}\n"
                 f"  virtual slots plus {len(extra_assignments)} non-virtual methods assigned by\n"
                 "  receiver identity. The remainder are still free/unknown in the skeleton.\n")
    lines.append(f"- {len(named_classes)} vtables contain a scoped-assert `Class::method`; those\n"
                 "  names are proven. Every other class label is address/evidence-derived.\n")
    lines.append(f"- {len(scoped)} functions carry a scoped name; {len(strings)} carry an engine\n"
                 "  debug string name; the rest stay `sub_XXXXXX`. Names are evidence, not guesses.\n")
    lines.append("\n## Reconstruction state\n")
    lines.append("| State | Functions |\n|---|---|\n")
    for k in ["matched", "wip", "verified", "lifted"]:
        lines.append(f"| {k} | {st[k]} |\n")
    lines.append("\n## Vtable classes\n")
    lines.append("| Vtable | Class | Slots | Extra methods | Known names | Matched | Remaining |\n"
                 "|---|---|---|---|---|---|---|\n")
    for c in sorted(vt_classes, key=lambda x: x["vtable"]):
        hs = c["state_counts"]
        remaining = c["total_methods"] - hs["matched"]
        known = ", ".join(c["known_class_names"]) or "—"
        lines.append(f"| `{c['vtable']}` | `{c['class']}` | {c['slots']} | "
                     f"{len(c['extra_methods'])} | {known} | {hs['matched']} | {remaining} |\n")
    lines.append("\n## Non-virtual classes (call-site object identity)\n")
    lines.append("| Class | Evidence | Methods | Matched | Remaining |\n"
                 "|---|---|---|---|---|\n")
    for c in sorted(nv_classes, key=lambda x: x["class"]):
        hs = c["state_counts"]
        lines.append(f"| `{c['class']}` | {c['evidence']} | {c['total_methods']} | "
                     f"{hs['matched']} | {c['total_methods'] - hs['matched']} |\n")
    lines.append("\n## Region distribution (coarse address evidence only)\n")
    lines.append("| Region | Functions |\n|---|---|\n")
    for k, n in reg.most_common():
        lines.append(f"| {k} | {n} |\n")
    lines.append("\n## Module hint distribution (names/imports, else falls back to region)\n")
    lines.append("| Module hint | Functions |\n|---|---|\n")
    for k, n in mod.most_common():
        lines.append(f"| {k} | {n} |\n")
    free = [f for f in funcs if not f["class"]]
    lines.append("\n## Functions with no class evidence\n")
    lines.append("| Region | Functions | Matched | WIP | Left |\n|---|---|---|---|---|\n")
    free_by_region = {}
    for f in free:
        free_by_region.setdefault(f["region"], []).append(f)
    for reg_name in sorted(free_by_region):
        items = free_by_region[reg_name]
        st2 = Counter(f["state"] for f in items)
        lines.append(f"| {reg_name} | {len(items)} | {st2['matched']} | {st2['wip']} | "
                     f"{len(items) - st2['matched'] - st2['wip']} |\n")
    lines.append("\n## Skeleton tree\n")
    lines.append("`Source/skeleton/` holds declarations only, generated from this map and\n"
                 "not compiled by `Scripts/match.py` or the boot: one header per vtable class,\n"
                 "one per inferred non-virtual class, plus `Source/skeleton/free/free_<region>.h`\n"
                 "for functions with no class evidence. Signatures are placeholders, not ABI\n"
                 "claims. Regenerate with `Scripts/class_map.py`; do not hand-edit.\n")
    lines.append("\n## Limitations\n")
    lines.append(f"- {len(vt_classes) - len(named_classes)} vtables have no proven class name and are\n"
                 "  labelled by address; the slot names inside are also mostly unknown.\n")
    lines.append("- Vtable boundaries are inferred from consecutive constructor writes; a class\n"
                 "  with no recovered constructor can be merged into a neighbour. Slot order is\n"
                 "  exact; the boundary is the inference.\n")
    n_clusters = sum(1 for c in nv_classes if c["kind"] == "cluster")
    lines.append(f"- {n_clusters} of the non-virtual classes are `cluster` candidates: a component of\n"
                 "  functions connected only by `ecx = this` edges, with no global/member root.\n"
                 "  They are a work grouping, not a proven class name.\n")
    lines.append("- A callee with call sites supplying *different* object identities is left\n"
                 "  unclassed: that is either an inherited method or a generic helper, and needs\n"
                 "  more evidence. Only agreeing call sites were assigned.\n")
    lines.append("- A shared vtable slot (present in several derived vtables) is treated as a\n"
                 "  base/inherited method for inference; it appears in each derived skeleton header\n"
                 "  as a slot but does not pin a derived class.\n")
    lines.append("- `module` is a hint from known names/imports and falls back to the address\n"
                 "  region. It is not a claim about the original source file.\n")
    open(os.path.join(ROOT, "docs", "class_map.md"), "w").write("".join(lines))
    print(f"[{len(funcs)} functions] [{len(vt_classes)} vtable classes, "
          f"{len(nv_classes)} non-virtual classes, {len(named_classes)} named] "
          f"[{len(classed_funcs)} classed functions, {len(slot_funcs)} virtual slots]")


if __name__ == "__main__":
    main()
