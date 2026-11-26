# Matched-only build status

Goal: a standalone binary that boots to the menu from byte-verified matched C++
bodies, not from `Source/lifted` recompilation.

`Scripts/build_boot.sh` (read-only, not edited) links only
`lifted_w/recomp_0*.c`, `recomp_dispatch.c` and `Source/host/*.c`. It contains no
matched TU, so `build/boot/aoe_boot` boots entirely from lifted code.

## New separate path: `Scripts/build_matched.sh`

Compiles every TU that owns a matched body (from `data/function_map.json`) with
the host compiler into `build/matched/*.o`, then links the objects that have no
undefined symbols together with `Scripts/matched_probe.cpp` into a native
executable and runs it.

Evidence (current run):

- matched TUs in `data/function_map.json`: 162
- natively compiled by the host compiler: 151
- failed to compile: 11, all because the TU contains `__declspec(naked)` /
  `__asm` bodies (MS-style inline assembly is unsupported on arm64 and is not
  C++, so these violate the "matches must be C++, not asm" rule):
  `Source/crt/free_crt.cpp`, `Source/crt/free_crt_s.cpp`,
  `Source/engine-late/C_cluster_42E3E0.cpp`,
  `Source/game/C_cluster_42E650.cpp`, `Source/gfx/C_cluster_45DF20.cpp`,
  `Source/ui/C_cluster_49FE60.cpp`, `Source/ui/C_cluster_4B4550.cpp`,
  `Source/ui/C_pnl_edit.cpp`, `Source/ui/C_vt6234C8.cpp`,
  `Source/ui/C_vt623E50.cpp`, `Source/ui/free_ui.cpp`
- objects with no undefined symbols (self-contained): 74
- those 74 link together with no lifted code, no guest-memory map and no
  wrapper: link exit 0, `probe: 0 failures`

The probe exercises two recovered bodies on host-allocated instances:
`C_cluster_405790::Init_405790` (writes `+0x00` vtbl, `+0x04` arg, `+0x08` zero)
and `C_cluster_40F0C0::Check_40F4B0` (`+0xEA4 == 0x32`).

## Remaining gaps toward booting to the menu

1. The 74 self-contained objects are a core, not a boot path. The rest reference
   guest globals and/or other guest functions as undefined symbols
   (e.g. `_F_441330`, `_Hook_473AE0`, `_SetWindowTextA`, member stubs).
2. Guest memory: matched bodies derive pointers from guest VAs stored in fields
   and globals (e.g. `*(int*)g_664524`), and call `ADDR`-style addresses without
   a host mapping. A native link either needs a mapped guest image at the guest
   VAs plus symbol definitions for `g_*`, or a rewritten access layer.
3. Guest ABI: calls between matched bodies use guest conventions (`ecx` = this,
   stdcall/`ret n`) while includes/headers declare plain C++ members. A wrapper
   layer translating guest registers and stack discipline is needed for the
   cross-TU calls.
4. Coverage: phase docs still show 416/815 phase-1 matched (289 left, 23 WIP,
   110 CRT/library), so even a wired build would boot lifted, not matched, code.
5. Asm-based "matches" must be rewritten as C++ first; they cannot enter this
   build at all.

## Reproduce

```
./Scripts/build_matched.sh
# matched TUs compiled: ... ok, ... failed
# self-contained objects: ...
# probe: 0 failures
# native matched probe: OK
```
