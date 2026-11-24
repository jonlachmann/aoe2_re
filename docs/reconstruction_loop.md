# Class-first reconstruction loop

This is the operating procedure for the long-running byte-exact reconstruction.
It complements `docs/matching.md` (compiler/matching mechanics); this doc is the
state model, the per-iteration loop, the class-layout refinement rules, and the
legacy-staging exit path.

The rule that never changes: **a `MATCH_FUNC` must stay byte-identical** and the
full-suite `N` in `[N/M] MATCH_FUNCs OK` is the number to protect. A deliberate
regression is allowed only when a shared layout change raises `N`; say so in the
commit message.

## Three layers, one owner

| Layer | Location | Meaning |
|---|---|---|
| Staging | `Source/simple/*.cpp` | Old bodies. Mostly class-evidenced copies removed; non-class bodies still live here. |
| Class-first code | `Source/<module>/<class>.hpp/.cpp` | Real, compiled bodies and markers. One class/subsystem per TU. |
| Map | `Source/skeleton/**/*.h` | Generated declaration-only index for all recovered classes; never compiled, never marked. |

`Source/skeleton` is refreshed by `Scripts/class_map.py`; it is not a staging
copy and must not be deleted as "old code".

Generated evidence files:

- `data/function_map.json` — every real function start, class/module/region, state, owner file.
- `data/class_map.json` — recovered classes, vtables, slots, methods.
- `data/class_ownership.json` — per-class owner-TU feedback.
- `docs/class_map.md` / `docs/class_ownership.md` — generated review tables.

## Current snapshot (recompute, do not trust stale prose)

At the checkpoint after the class-first wave and declaration-only cleanup:

- Full suite: `[981/981] MATCH_FUNCs OK, 38 WIP`.
- Class-evidenced inventory: 93 classes, 314 functions; all 314 now have
  markers outside `Source/simple`.
- `Source/simple`: 229 marker files, 676 marker addresses (674 canonical
  functions after the two skipped aliases `0x45B5DC`, `0x58F232`): 647 MATCH,
  27 WIP, all with no class evidence currently.
- Class map: 534 recovered classes (221 vtable + 313 non-virtual), 67 named,
  3083 classed functions, 1887 virtual slots.
- Skeleton: 542 headers (534 classes + 8 free-region maps).
- Skipped aliases are not real starts; never migrate them as independent functions.

Recompute at the start of every long session:

```bash
AOE_BIN=/Users/jonlachmann/aoe2_game/empires2_cracked.exe ./venv/bin/python Scripts/match.py
AOE_BIN=/Users/jonlachmann/aoe2_game/empires2_cracked.exe ./venv/bin/python Scripts/class_map.py
git status --short
```

`Scripts/class_map.py` regenerates the maps, skeleton, ownership JSON, and the
ownership review table. The suite is the byte gate; the map is the work index.

## Per-iteration loop

Every iteration follows these steps. Do not skip the full-suite gate.

1. **Choose one target.** Prefer:
   - a WIP parked in a class TU,
   - a callee/caller of a recently matched function (same class/struct),
   - addresses adjacent to a matched method,
   - `match.py --target 0xADDR` for a known-sized start,
   - `match.py --next` only for cold starts.
2. **Read the evidence.** Left column of the diff is the original; right is ours.
   Check `ret N`, field offsets, struct-passing shape, inlining, and callee names
   before chasing codegen.
3. **Place the body in its class TU.** A class/subsystem TU is the ownership
   anchor (`data/class_map.json` region + class label). Methods may live at
   addresses outside that region and still belong to the class TU.
4. **Write the body manually.** No automatic body generator. Use `WIP_FUNC(0x...)`
   while iterating. Preserve the tcall/ABI shape exactly.
5. **Verify the TU.** `Scripts/match.py Source/<module>/<class>.cpp`. Iterate the
   body until every targeted marker is `OK` (or park an explained WIP).
6. **Promote.** Replace `WIP_FUNC` with `MATCH_FUNC` only after `OK`.
7. **Full-suite gate.** Run the suite. `N` must not drop. Record the new `[N/M]`.
8. **Refresh index.** Regenerate `class_map.py` when a class, slot, owner file,
   or state changed enough to affect the map/ownership output.
9. **Commit one class or one small wave.** Commit message: what moved, staged
   copies removed, suite numbers before/after, any shared-layout regression and
   the net gain that justified it.

Commands:

```bash
./venv/bin/python Scripts/match.py --target 0x461370
./venv/bin/python Scripts/match.py Source/gfx/draw_area.cpp
./venv/bin/python Scripts/match.py
./venv/bin/python Scripts/class_map.py
./venv/bin/python Scripts/decomp_dashboard.py   # when refreshing MATCHING.md
```

## Class-layout refinement rules

Class TUs were migrated byte-first, so declarations are structurally right but
semantically provisional. Refine them in this order, verifying after each change.

1. **Replace `char pad_XX` with named fields** once body accesses and offsets
   agree. Keep the offset in a comment.
2. **Name real fields.** Keep one declaration order that preserves every offset.
   Never reorder fields inside a TU without re-running the TU's matches.
3. **Replace provisional referenced structs** (`S595540Node`, `T41AAC0`,
   `A544FD0`, …) with proper cross-class references when proven. Promote them to
   shared class headers only if all owning TUs agree; then rerun each affected TU.
4. **Resolve generic `void*` fields** only when every body in that TU and its
   evidence agree on one type. Conflicting same-offset types keep raw casts or a
   generic field plus per-body casts.
5. **Remove raw-offset casts** (`*(int*)((char*)this + 0x...)`) in favour of named
   fields where the field is proven. Keep raw casts only where layouts conflict.
6. **Virtual placeholders stay** until the vtable slot ordering is proven. Slot
   +offset depends on declaration order; removing a placeholder can shift codegen.
7. **Do not rename evidence-derived class labels** (`C_vt...`, `C_cluster...`,
   `C_pnl...`) as if they were proven names. Rename only when a scoped/engine name
   is proven.
8. **Verify the TU immediately after each layout change**, then run the full gate
   at the end of the wave.

Class-first migration bars:

- Declarations for the work map stay generated in `Source/skeleton/`.
- Class-first TUs carry their own layout declarations for compiled bodies.
- A partial layout is acceptable during iteration; comments must distinguish
  proven fields from evidence-skeleton contents.
- Class TU module is the class-map anchor region, even when method addresses sit
  in another region.

## Legacy staging exit path

`Source/simple` cannot be deleted wholesale yet. It still owns the 674 canonical
non-class functions (647 MATCH + 27 WIP). The exit path is:

1. **Group by evidence.** Use `function_map` module/region, call sites, struct
   shapes, and `class_ownership` hints to assign each legacy body to a
   class/subsystem TU.
2. **Migrate one body or a coherent group.** Write the body manually in the
   target TU; adapt symbol qualification and field expressions only.
3. **Verify and promote.** TU-local `match.py`, then `MATCH_FUNC`.
4. **Remove the staged copy** only after the class TU verifies. Do not delete
   unverified or still-unmigrated staging.
5. **Prune empty files.** A staging file may be deleted only when it has no
   `MATCH_FUNC`/`WIP_FUNC` markers. Declaration-only leftovers are safe to
   remove; files owning markers are not.
6. **Full-suite gate.** The suite must remain `[981/981]`, 38 WIP (or higher) and
   show no compile errors or missing symbols.
7. **Regenerate maps** and commit the moved bodies plus the staged deletions.

Removal check for staged duplicates (never remove unmatched blocks):

- Collect addresses marked outside `Source/simple`.
- Remove only the staged blocks with those exact addresses, paired
  marker-to-definition in file order.
- Preserve shared declarations/structs that sit between stacked markers.
- Never delete a staging block whose target is still WIP-only elsewhere without
  confirming the class TU copy exists.

## Safety checklist for every long session

- [ ] Suite is green and recorded before edits.
- [ ] No unverified staged copy removed.
- [ ] No `MATCH_FUNC` broken without a documented net-gain regression.
- [ ] Aliases `0x45B5DC`, `0x58F232` skipped as starts.
- [ ] Class labels treated as evidence, not proven original names.
- [ ] Skeleton treated as a generated map, not compile input or old staging.
- [ ] Unrelated launcher work left uncommitted.
- [ ] Commit artifacts: class TUs, staging deletions, map/ownership refresh,
      tooling fixes. Exclude `README.md`, `Scripts/build_boot.sh`,
      `Source/host/aoe_host.c`, `docs/bringup_log.md`, patch edits, and play/sync
      scripts.

## Definition of done for the readable track

1. `Source/simple` holds no marker blocks (fully migrated or deleted).
2. Every matched/wip body has a class/subsystem owner TU.
3. Class TUs carry named fields and proven referenced classes, with slots ordered
   as the original.
4. Full suite reports all MATCH markers OK and the WIP set is explicitly parked.
5. `data/class_ownership.json` shows no staged owners and split ownership is
   resolved or explained.
