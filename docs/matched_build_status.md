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

- matched/WIP-owner TUs compiled: 165 (every TU in `data/function_map.json` that owns a matched or WIP body)
- natively compiled by the host compiler: 165, 0 failed
- asm in matched TUs: 0 (see conversion note below)
- objects with no undefined symbols (self-contained): 74; link exit 0,
  `probe: 0 failures`
- stage 2 — 237 `g_*` guest globals generated from the objects' own undefined
  lists, 215 of them seeded from the reference binary's data image (`AOE_BIN`)
  rather than zeros; 86 objects link with those globals (`probe: 0 failures`)
- stage 4 — 12 globals-only objects execute against the seeded image:
  `matched_probe_globals.cpp` checks `Get_434BE0()==1.0`, the `M_435810`
  0.0 threshold and `Get_41A090()==FLT_MAX`: `globals exec probe: 0 failures`
  (12 objects)
- stage 5 — every matched object links into one native executable. The
  extern symbols the object set does not define get host stubs: currently 521
  asm-label functions returning 0 and 1 opaque data array, leaving libSystem
  names (`malloc`, `memcpy`, `strlen`, ...) and C++ runtime helpers to the
  linker. Result:
  `all matched objects linked: 168; probe_all: OK` (`probe: 0 failures`).
  These stubs are link fillers with host ABI, not guest implementations.
- stage 3 — portable guest-VA access layer: `Source/matched_mem.h` defines
  `ADDR(va)`, a plain cast under VC6 (byte-exact codegen unchanged) and a guest
  image base offset under `-DMATCHED_NATIVE`. `Scripts/matched_probe_va.cpp`
  maps a host guest image, stores guest VA 0x1000 in `g_6645c4`, and
  `M_4BDE70` reads the short at +0x424 through ADDR: `va probe: 0 failures`
- ADDR is now applied to the 20 typed guest-global pointer casts in the tree
  (`C_cluster_4EE210` 11, `C_vt6234C8` 1, `C_TribePopUpHelp`, `free_game`,
  `C_vt621F64`, `C_cluster_4ED280`, `free_gfx`, `free_app`, `free_sim` 6),
  and the full gate is unchanged at `[1762/1762]`, confirming the macro is
  codegen-neutral under VC6. Native semantics still need a guest-image layout
  so a global's *address* (symbol) maps like its *contents*.

The probe exercises two recovered bodies on host-allocated instances:
`C_cluster_405790::Init_405790` (writes `+0x00` vtbl, `+0x04` arg, `+0x08` zero)
and `C_cluster_40F0C0::Check_40F4B0` (`+0xEA4 == 0x32`).

## Asm removal wave

The 11 TUs that previously failed to compile contained `__declspec(naked)` /
`__asm` bodies. All of them were rewritten as C++:

- eight global-pointer tail-jump stubs (`5ECE44`, `5ECE4A`, `5ED9D6`, `5ED9E8`,
  `5ECE5C`, `5ED9F4`, `5ED9FA`) and their five owning TUs reproduce the original
  `jmp dword ptr [g]` exactly from a plain C++ call — these stayed byte-exact
  `MATCH_FUNC`.
- twelve hand-written asm bodies (`5FCA45`, `5FC8D4`, `5F9AA0`, `5F9A20`,
  `5F9D00`, `5FCDE1`, `5F9EF0`, `6026DB`, `5F9750`, `4BD560`, `4BDE70`,
  `4CD410`) were rewritten with equivalent C++ semantics but VC6 C++ codegen
  does not reproduce the hand-written register scheduling, so they are now
  `WIP_FUNC`. This intentionally reduced `[N/M]` from 1774 to 1762 matched while
  removing every asm marker; the recovered class/field layout is retained.
- `0x5FC8D4`'s `fnclex` has no C++ equivalent and was dropped (WIP body).

## Remaining gaps toward booting to the menu

1. (Link milestone) all 168 objects (165 owner TUs + alias TU + image TU + sync TU) link into one executable, but most
   external symbols are still host stubs returning 0. A first batch of naming
   fixes removed two: the PE-accurate mangling inventory shows ~150 extern
   symbols already have matched bodies under a different class/method name
   (e.g. `C_cluster_43EB70::Init_43EB90` vs `T43EB70::Other_43EB90`), so renaming
   those definitions to the PE's mangled names replaces stubs with real code.
   43EB90 and 43EB70 were re-homed into the PE-accurate `T43EB70` class
   (`Other_43EB90`, `Other_43EB70`, plus `Other_43EB80`), dropping the stub count
   from 603 to 601 with the gate unchanged. A scripted batch then renamed 21
   more confined cases (e.g. `S440B30::M_440B30` -> `T440B30::Other_440B30`,
   `S464FD0::M_464FD0` -> `T464FD0::Other_464FD0`, `S42GetBulk::Get_422A70` ->
   `T4ED280Global::M_422A70`, three same-class method renames) to 580. Then
   `C_cluster_49F630::M_49FA50(char*)` became the PE's `int` signature (579),
   and three C++ forwarding methods were added in `C_cluster_49F630.cpp` for
   the code-folded 0x5BE8D0 body (`T49F650Key::SetIndex_5BE8D0`,
   `T49FB00Obj::SetIndex_5BE8D0`, `C_global_66EA48::Hook_5BE8D0`) calling the
   real `S5BE940::SetIndex_5BE8D0` code, reaching 576 stubs. Every batch keeps
   the full gate at [1765/1765] and the all-object link at 168 objects (170
   objects including globals and stubs in the boot link). The
   remaining extern inventory is mostly broad-class renames or free-vs-member
   call-site mismatches, which need forwarding methods or caller fixes instead
   of wholesale class renames.
- stage 5b — `Source/host/matched_pe_aliases.cpp` holds generated PE-named C++
  forwarding methods: 43 member-vs-member cases with identical parameter lists
  where the PE symbol differs from the matched body's class/method name
  (e.g. `S522C70::M_522D20(int)` -> `C_cluster_522D20::M_522D20(int)`,
  `T4B88A0::Other_4B88A0()` -> `S4B88A0::M_4B88A0()`). Each wrapper calls the
  real byte-exact body, so the linker binds the PE mangled symbol to actual
  code. The build compiles this generated TU explicitly (it is not in the
  function-map owner list) and adds it to the all-object link, taking the stub
  count from 576 to 533 and the object count from 165 to 166 with no duplicate
  symbols; the full gate is unchanged because the alias TU has no markers.
  The same generator also emits eight free-function and member-to-free wrappers
  (`sub_4A6E40`, `sub_48BAD0`, `sub_5CFAF0`, `sub_4EE210`, `sub_4654D0`,
  `Free_5F90B0`, `Tr58A7E0::Other_58A7E0`, `C_pnl_inp::Other_4A2140`) taking
  the stub count from 533 to 525.
- stage 6 — native guest image: `Source/host/matched_guest_image.cpp` reads the
  reference PE, maps a 4 MB image over guest VAs 0x400000..0x800000, copies the
  section bytes, and sets `g_matched_base`. The build generator emits
  `Scripts/matched_guest_sync.cpp`, which copies all 215 seeded `g_*` arrays
  from the image at their guest VAs, so symbol contents equal image contents.
  `Source/matched_mem.h`'s native `ADDR` now returns an image-backed pointer
  unchanged (idempotent) and offsets guest VAs by `g_matched_base`; all matched
  TUs are compiled with `-DMATCHED_NATIVE` for the native links, so ADDR-based
  guest-VA dereferences land in the mapped image. Probe result:
  `guest image probe: 0 failures` for `g_61C000`, `g_6645c4`, `g_vt_62AAE0`;
  `all matched objects linked: 168; probe_all: OK`; `va probe: 0 failures`.
  Limit: the address of a generated `g_*` symbol is still its host array
  address, not image+VA; symbol references are consistent by contents (synced),
  while guest-VA constants go through the image.
- stage 7 — standalone matched boot executable:
  `Scripts/build_matched_boot.sh` links the matched owner/alias/image/sync/
  globals/stub objects with the win32hle runtime and the host launcher into
  `build/matched_boot/aoe_matched_boot`. It compiles the unchanged
  `Source/host/aoe_host.c` main with `-Drecomp_host_run=matched_recomp_host_run`,
  so the host setup (shims, drives, command line, screen) is reused and only the
  run step is replaced by `Source/host/matched_run.c`. That run step maps the
  PE-backed guest image, syncs the `g_*` arrays, and calls WinMain 0x47AE20 on
  the guest stack with
  (hInstance=0x400000,hPrev=0,cmdline=0,nCmdShow=1) through `hle_call_guest`.
  Entry chain: the reference PE entry is 0x600281 (CRT startup, region crt,
  lifted because CRT matching is skipped); the CRT calls WinMain 0x47AE20
  (region ui, catalog state lifted). The boot harness bypasses the lifted CRT
  entry and starts at WinMain, which is the first VA the boot-to-menu path needs.
  Evidence: `[host] booted: entry 0x00600281, 0 unresolved imports`,
  `guest image mapped ... g_* globals synced`, then
  `checkpoint: WinMain VA 0x0047AE20 reached` and
  `WinMain returned 0x00000000` — the harness works and the first checkpoint
  stops at unmatched WinMain (its dispatch entry is still a host stub).

  Two stub-generation defects found while bringing this link up, both fatal to
  dyld before `main`: the stub object used to define native runtime helpers
  (`___chkstk_darwin`, `___gxx_personality_v0`) and the C++ allocation
  operators (`__Znwm`, `__ZdlPv`). Any library initializer that called the
  stack probe or allocated through `new` got a 0-returning stub, crashing the
  process in a system framework initializer before the host ran. These symbols
  are now left to the linker/libc++abi; stub count 525 -> 523 -> 521.
- stage 8 — first boot-path bodies:
  `Source/ui/free_ui.cpp` gains a byte-exact `MATCH_FUNC(0x473BF0)`: the
  singleton teardown at 0x66DB6C calls the stdcall destructor through IAT
  0x61C168 and clears the global. `Source/ui/free_boot.cpp` (new TU) holds a
  `WIP_FUNC(0x47B620)` language-init body: load the module at 0x6530B4, resolve
  the export at 0x6530AC, load the language DLL argument, read string resources
  0x3EF/0x3F0 into two 0x104 stack arrays, probe the language string tail with
  sub_5FDCD4, call the export with either the block+8/language+4 pair or the
  zero/block+4 pair, then free both modules and return the export result.
  The WIP body compiles at 272 bytes against 261 (local array offsets and the
  branch layout still differ). Catalog correction: 0x47B620 takes a cdecl stack
  argument and never reads `this`, so it is modeled as free `sub_47B620`; the
  `C_cluster_47AE20` membership stays catalog-only.
  Evidence: full gate `[1766/1766] MATCH_FUNCs OK, 42 WIP`; matched TUs 166 ok,
  0 failed; 524 function stubs; `all matched objects linked: 169; probe_all:
  OK`; boot link 171 objects; run still prints the WinMain checkpoint because
  0x47AE20 itself remains unmatched.

- stage 9 — cluster-layout feedback from the boot path:
  0x4732E0 is a thiscall cluster grower (176 bytes) that the catalog had left
  unclassed: it reads this+0x08 (array length), this+0x0C (per-index block
  pointers) and this+0x10 (per-index entry counts), allocates a2*0x0C bytes
  through 0x5F8FF0, copies the old entries, frees the old block through
  0x5F90B0, and writes -1 into each new entry. A caller pair (0x472C7E and the
  0x473270 body, which also sets +0x08/+0x0C/+0x10) shows the same object, so
  the fields are modeled in `Source/ui/C_cluster_4732E0.hpp` and the body is a
  `WIP_FUNC` in `Source/ui/C_cluster_4732E0.cpp` (192 bytes vs 176: the
  compiler picks different callee-saved registers for `this`/index/buf).
  Evidence: full gate `[1766/1766] MATCH_FUNCs OK, 43 WIP`; matched TUs 167 ok,
  0 failed; 524 function stubs; `all matched objects linked: 170; probe_all:
  OK`; boot link 172 objects; boot run unchanged (WinMain checkpoint).
  Phase docs: 408 matched, 288 left (37 WIP), 119 CRT/library.

- stage 10 — native import-dispatch layer:
  `Source/host/matched_imports.cpp` installs native trampolines into the first
  dword of the generated IAT-slot arrays (`g_61c110`, `g_61c0d8`, `g_61c1a0`,
  `g_61c3d8`, `g_61c3c8`, `g_61c168`). A trampoline converts image pointers back
  to guest VAs and calls the win32hle shim through `hle_call_guest`, so the shim
  sees the guest ABI it expects; GetProcAddress additionally returns a native
  wrapper for the resolved export (EBUEula during the boot path).
  `Source/host/matched_run.c` now calls `InstallMatchedImports()` after syncing
  the `g_*` arrays and then runs the WIP language init 0x47B620 natively as a
  proof step (`matched_langtest`). Evidence: `LoadLibraryA("EBUEula.dll") ->
  0x10500000`, `GetProcAddress("") -> EBUEula wrapper`,
  `LoadLibraryA("language.dll") -> 0x10510000`, and
  `language init 0x47B620 returned 1` — a WIP C++ body now runs real game init
  through the HLE shims with no lifted code. Boot then continues to the WinMain
  checkpoint as before. Gate `[1766/1766] MATCH_FUNCs OK, 44 WIP`; matched TUs
  167 ok/0 failed; 526 stubs; all-object link 170; boot link 172 objects.
  The WIP WinMain 0x47AE20 prologue is now in `Source/ui/free_boot.cpp` (176
  bytes vs 2035; WIP stops after the language init). Phase docs: 408 matched,
  288 left (38 WIP), 119 CRT/library.

Gaps now:
1. WinMain 0x47AE20 is still unmatched (2035 bytes): a 0x1B88 stack frame, 27
   inline strcpy/strlen+memcpy expansions, a stack config struct, calls to
   0x47B620 and 0x5B0EC0, and vtable dispatch. Its dispatch entry is a stub, so
   the matched-only run stops there.
2. Import ABI (partially done): stage 10 installs trampolines for the six boot
   slots and marshals image pointers to guest VAs. Limits: only EBUEula has a
   native export wrapper; slots beyond those six (LoadStringA, MessageBoxA,
   GlobalAlloc, ...) are not installed yet, and host heap/stack pointers passed
   to shims are not translated into guest memory.
3. Guest ABI: matched-to-matched calls are consistent because all bodies are
   compiled by the host compiler; the gap is only at boundaries to unmatched
   lifted code/external imports, which need guest-ABI wrappers.
4. Coverage: phase docs show 408/815 phase-1 matched (288 left, 38 WIP, 119
   CRT/library), so even a wired build would boot lifted, not matched, code.
5. (Done) Asm-based "matches" were rewritten as C++; the tree now has zero
   `__asm` in matched bodies and all 167 matched TUs compile natively.

## Reproduce

```
./Scripts/build_matched.sh
# matched TUs compiled: ... ok, ... failed
# self-contained objects: ...
# probe: 0 failures
# native matched probe: OK
```
