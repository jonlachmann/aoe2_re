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

- stage 11 — full WinMain body + native dispatch:
  `Source/ui/free_boot.cpp` now carries a complete `WIP_FUNC(0x47AE20)` body
  (2096 vs 2035 bytes; frame 0x1B88). It reproduces the whole init sequence:
  timer period 1, timeGetTime-seeded rand, `rand()%0x1000` buffer at cfg+4,
  language init 0x47B620, the title/version (`sprintf("%s")`), 26 further
  inline strcpy config strings (data/sound/savegame/scenario/campaign/ai/avi/
  taunt/random trees and command line), the config numeric fields (+0x40c..
  +0x934), the 0x1C94 allocation, the 0x5B0EC0 object and its vtable slots
  (+0x00/+0x04/+0x18/+0x24/+0x28), MessageBoxA resource dialog, 0x473BF0,
  free and timeEndPeriod. `Source/host/matched_imports.cpp` adds trampolines
  for MessageBoxA (0x61C37C) and timeEndPeriod (0x61C3C4) alongside the six
  earlier slots, and `matched_winmain()` calls the native body directly (not
  `hle_call_guest`, which only dispatches recomp-model VAs) with a valid empty
  command-line pointer (the earlier 0 pointer crashed the command-line strcpy).
  Evidence: the boot run now passes language init (`0x47B620 returned 1`) and
  executes the full native WinMain body: `WinMain body 0x47AE20 returned 0`,
  exit 0, no fault. The remaining unmatched internals (0x5B0EC0, 0x5FCE14,
  0x5F8EE0 malloc) are still host stubs, so the body returns before menu.
  Gate `[1766/1766] MATCH_FUNCs OK, 44 WIP`; matched TUs 167 ok/0 failed; 528
  stubs; all-object link 170; boot link 172 objects.

- stage 12 — host CRT heap/format band (exempt) + coherent cluster ownership:
  `Source/crt/free_crt.cpp` now *defines* the library-band backing rather than
  leaving generated stubs: `sub_5F8EE0` (malloc backing), `sub_5F8FF0`
  (count*elem array allocator used by the 0x4732xx tables), `sub_5FA280` (free
  behind 0x5F90B0) and `sub_5FCE14` (variadic sprintf via vsprintf). The 0x5F8F60
  marker was corrected from `void(void*)` to `void*(int)` so its bytes still
  match (`MATCH_FUNC OK`) while WinMain's `malloc` call resolves to that native
  body; the old `void(void*)` declaration was what kept the boot path on a stub
  that returned 0. The CRT band is library code and these replacements are not
  counted as matches. Evidence: the boot run now allocates real buffers and runs
  all 26 inline strcpys plus sprintf with no fault, where before malloc returned
  null. The WIP WinMain also keeps the rand buffer in a local `buf` (host pointers
  are 64-bit, and storing one at cfg+4 let the cfg+8 string clobber its high
  dword), while cfg+4 still carries the original 4-byte layout slot.
  Ownership fix: 0x4732E0 is no longer its own ui cluster — its `+0x08` row
  count, `+0x0C` block pointer table and `+0x10` capacity table are exactly the
  rows 0x473200 passes, so the body moved into `C_global_6645C4`
  (`Source/ui/C_cluster_4732E0.*` deleted). 0x473200 is now a WIP member that
  allocates two a1+1 tables, copies the live row/capacity arrays, frees the old
  ones and calls `M_4732E0`; 0x522D90 is a WIP member of C_cluster_522D20.
  Gate `[1786/1788] MATCH_FUNCs OK, 15 WIP`; matched TUs 166 ok/0 failed (one
  fewer because the folded TU is gone); 528 stubs; all-object link 170; boot
  link 172 objects; boot run exit 0, language init returns 1, native WinMain
  returns 0 without fault, but the sim-object constructor remains the stop.

- stage 13 — the sim/config object constructors and a native vtable:
  WinMain `0x47AE20` is now a byte-exact `MATCH_FUNC` (the frame is modelled as
  `result`, `buf`, the 0x1980 info block passed to the constructor, caption and
  text; gate reports `?sub_47AE20...: OK`). The constructor call is declared on
  the WinMain-side `TWinMainObj` as `Init_5B0EC0`; that method forwards to the
  real owner class `C_vt62C1E0::M_5B0EC0`, so the call site stays direct and the
  marker stays exact. `Source/sim/C_vt62C1E0.hpp` now extends the layout through
  the constructor's tail (+0x1C54/+0x1C58/+0x1C8C/+0x1C90, total 0x1C94) and
  declares `M_41B760` / `M_5B0EC0`.
  The base constructor `0x41B760` is a WIP member (1504 vs 1175 bytes): it zeroes
  the 0x1C94 block, sets the base pregame scalars (+0x08..+0x18 = -1, +0x30 = 1,
  +0x44..+0x50 = -1, +0x70 = 2, +0x1C4/+0x1F4/+0x1F8/+0x9E0 = 1, the 0x41C/0x530/
  0x914/0xB38 groups), folds the 0x421Axx/0x421Bxx setter families inline where
  their owner TU models them in separate local classes, writes the +0x9A9..+0xB5
  and +0x9C0.. bytes, takes the original failed-device branch status +0x60=0xE
  (its 0x41DC10/0x41DC80/0x41BC80 chain is still lifted), stores the parent config
  pointer at +0x24 last, and publishes `this` into g_6645c4.
  The derived constructor `0x5B0EC0` is a WIP member (432 vs 686 bytes): it calls
  the base, clears the +0x1460 scene block, installs the 0x62C1E0 vtable, calls the
  matched 0x5BAxxx/0x5BBxxx setters in the original order with their original
  arguments, clears the nine +0x1AB8 dwords, folds 0x421B90(4) and the 0x5BC460
  clear, and on the caller flag follows the 0x5B17D0 failure branch (+0x60=1).
  A native 87-slot vtable replica is built under MATCHED_NATIVE: slot +0x00 is the
  matched deleting destructor 0x5B1170 through `Sd5B1170::D_5B1170`, +0x18 reads
  the byte-verified +0x60 status getter, +0x24 is the 0x41C920 resource-fill
  equivalent, +0x04/+0x28 and all unmatched slots go to a zero-returning trap.
  MessageBoxA's trampoline now prints native stack caption/text instead of passing
  them to the guest-pointer HLE (that marshalling faulted with `sig=10`).
  Evidence: boot exit 0, no fault; counters show the native path really ran:
  `sim ctor hits: 41B760=1 5B0EC0=1; vtable slots 00=1 18=1 24=1` and the
  `[MessageBox]` line is reached. Gate `[1794/1794] MATCH_FUNCs OK, 11 WIP`;
  matched TUs 166 ok/0 failed; 527 stubs; all-object link 170; boot link 172.

- stage 14 — the 0x41DC10 device-context build and the 0x41DC80 parser WIP:
  `0x41DC10` is now byte-exact (`MATCH_FUNC OK`, 106 bytes) as
  `C_vt61DF78::slot36_41DC10` in `Source/app/C_vt61DF78.cpp`. Its source shape
  is `new T41DC10Obj(path)` — the CRT operator new at 0x5F8F60, operator delete
  at 0x5F90B0 — which is exactly what produces the original's fs:[0] EH frame:
  the constructor can throw, so the unwind funclet frees the 0x110 allocation.
  The body stores the constructed pointer at +0x1D4 and returns non-null as an
  int (the original's `xor edx; setne dl; mov eax,edx` tail). The TU-local
  constructor forwards to the already-matched `S4BDE90::M_4BDE90`, and the
  9-argument slot 0x61C008 is now identified as RegCreateKeyExA and patched with
  a native trampoline (headless boot succeeds without registry marshalling).
  `0x41DC80` is a WIP member (448 vs 461 bytes) of the same class: it copies the
  config's +0x518 path with 0x5FCB40, finds LOGDIR:/LOGNAME: with 0x5FD7C3, walks
  the text through 0x5FD7A5/0x5FD716/0x5FD66E into 0x651164/0x66955C, and builds
  the 0xCEC object at +0x1C8 with the 0x440A90 constructor and 0x440B40/B80/BC0
  setters. The miss is in the two parser loops' register/argument scheduling and
  the pointer-difference tail, not the calls. The DC80 helper band is CRT/library
  and now has host replacements in `free_crt.cpp` (strncpy/strstr/advance/ASCII
  check/copy).
  The base constructor 0x41B760 now runs the real chain under MATCHED_NATIVE:
  it calls the byte-verified `slot36_41DC10` through its owner class, writes
  g_66451C from +0x1D4, and takes the 0x41DC80-failure branch (+0x60 = 0xF) as a
  stand-in while DC80 is not wired. Evidence: boot exit 0, no fault, and the
  counters show `DC10=1 status=F` — the device-context object was really built
  natively and the status advanced from the old 0xE stop to 0xF. Gate
  `[1795/1795] MATCH_FUNCs OK, 12 WIP`; matched TUs 166 ok/0 failed; 534 stubs;
  all-object link 170 probe OK; boot link 172 objects. Ownership feedback:
  0x41B760/0x41DC10/0x41DC80 belong to the base vtable class 0x61DF78
  (`C_vt61DF78`), whose slots +0x090/+0x094/+0x0B0 they are; 0x41B760 sets
  vtable 0x61DF78 and is called by the derived 0x5B0EC0 (vtable 0x62C1E0).

- stage 15 — boot past the MessageBox and into the menu/message-pump branch:
  the base device chain now runs natively through `0x41DC10` (MATCH) and the
  WIP `0x41DC80`, and the derived creator `0x5B17D0` is modelled as a WIP member
  that calls the `0x41BC80` (slot +0x74) bring-up. `0x41BC80` itself is a WIP
  success contract (only registry-free control state: status 0, return 1); its
  original 1700-byte body drives the resolution/option reads, the +0x78/+0x158/
  +0x7C and +0x80/+0x84/+0x88/+0x8C/+0x98/+0x9C/+0xA0/+0xA4/+0xA8 virtual init
  slots, the 0x41F200/0x41F3A0/0x41F0C0/0x465270 subsystem builders and the
  +0x1B0/+0x1C/+0x20 object/window creation chain; those slots are still lifted.
  The menu pump slot +0x04 `0x41CF70` is a WIP member with its real control flow:
  a 7-dword MSG block, GetMessageA/PeekMessageA gates, Translate/Dispatch,
  WM_QUIT and the 0x6645C8 latch, and the +0xCC/+0xD0 virtual idle/message hooks.
  A headless GetMessage stands in for WM_QUIT so the loop enters once and exits
  cleanly. Slot +0x04 is wired in the native 0x62C1E0 vtable replica and the
  API slots are installed as lowercase-slot trampolines (DispatchMessageA,
  TranslateMessage, GetMessageA, PeekMessageA). Evidence: boot exit 0, no fault,
  no MessageBox, `DC10=1 status=0 DC80=1 BC80=1 5B17D0=1 menu-loop=1`, WinMain
  returns 0; slot 0x24 is not called because status 0 takes the success branch.
  Gate `[1795/1795] MATCH_FUNCs OK, 12 WIP`; matched TUs 166 ok; boot objects
  172. Ownership feedback: `0x41BC80` is base vtable 0x61DF78 slot +0x074
  (index 29), not +0x0B0; `0x41CF70` is slot +0x004 (index 1); `0x41B760`,
  `0x41DC10` and `0x41DC80` remain the base class `C_vt61DF78`.
  WIP files: `Source/app/C_vt61DF78.cpp` (BC80/CF70/DC80),
  `Source/sim/C_vt62C1E0.cpp` (5B17D0).

- stage 16 — window creation and the two menu-screen shells now run from
  native C++: the full 0x41BC80 bring-up body is a WIP member (1200 bytes vs
  original 1700) that follows the original order: timeGetTime seed, registry
  resolution/option reads through the matched 0x4BE080/0x4BDF50 helpers,
  config +0x8F4/+0x8FC/+0x8CC/+0x8D4/+0x8E0/+0x8F8 writes, the 0x41F200/
  0x41F3A0/0x41F0C0/0x465270 gates as success contracts, SystemParametersInfoA
  mouse-speed probes, the +0x7C/+0x80/+0x84 window slots, all +0x8C..+0xA8
  screen slots, the 0x274 object at +0x1B0 through the matched 0x462B50 ctor,
  the +0x0C/+0xB4 setters, the +0xFC child init, and ShowWindow/UpdateWindow/
  SetFocus/SetTimer. The window slots are now real Win32 behaviours, not guest
  IAT calls: `0x41D5D0` registers a WNDCLASS with a headless WndProc, `0x41D6A0`
  reads desktop metrics, creates the window and stores the handle at +0x28 /
  g_664528, and the imports layer exposes direct `Native_*` wrappers so host
  stack/config pointers never reach the guest-VA trampolines. `0x41DE50` and
  `0x41E070` allocate and record the 0x47C4 / 0x7B0 / 0x5C0 screen shells at
  +0x1B0/+0x80/+0x90 and g_664520/g_664518; the matched 0x425750 / 0x5200F0
  setters remain lifted because the shells' internal 0x15FC-style subobjects
  are not modelled yet. Evidence: boot exit 0, no fault, no MessageBox,
  `DC10=1 status=0 DC80=1 BC80=1 5B17D0=1 menu-loop=1`, WinMain returns 0, and
  `window class/create=2 hwnd=1A2B3C4D menu-screen DE50=1 E070=1`. Gate
  `[1796/1796] MATCH_FUNCs OK, 33 WIP`.
  Ownership feedback: 0x41D070 (slot +0x078), 0x41D5D0 (+0x07C), 0x41D6A0
  (+0x080), 0x41D7F0 (+0x084), 0x41DAA0 (+0x08C), 0x41DBA0 (+0x098), 0x41DE50
  (+0x09C), 0x41E070 (+0x0A0), 0x41E760 (+0x0A4), 0x41E5D0 (+0x0A8), 0x41E4A0
  (+0x0AC), 0x41EA60 (+0x0B0), 0x420D10 (+0x0FC) and 0x422340 (+0x154) are all
  base-vtable 0x61DF78 members `C_vt61DF78`; 0x41F200/0x41F3A0/0x41F0C0/
  x465270 are free functions. Native 64-bit field shifts are a real hazard:
  pointer members at non-8-aligned guest offsets (e.g. `Sc422180`'s +0x24
  pointer) are padded to +0x28 under clang, so the WIP bring-up guards the
  matched 0x422180 gate and reads config through the side pointer
  `cv_config_ptr` rather than truncating the guest dword at +0x24.

- stage 17 — three more phase-1 boot-match candidates are byte-exact:
  0x420BE0 (226 bytes) is a base member that sets +0x30 from arg3, gates the
  +0x1D8 display state in {4,6,7} and +0xB38, clears the flag and calls
  0x41F730(0,0) on the set branch, then reads the 0x66ea48/0x49F620 global twice
  and dispatches the +0xEC virtual slot before +0x074; the clear branch gates
  on 0x4217B0==1, the 0x664544 byte and 0x41F660(1)==0, sets +0xB38 and calls
  0x41F730(1,0), then dispatches +0x075. 0x41DBA0 (99 bytes) allocates a 0x12C
  menu object, constructs it with the window handle at +0x28, records the
  pointer at 0x664524, and returns construction success; `new` reproduces the
  original VC6 EH frame (the ctor is kept non-trivial so VC6 emits the frame)
  and the operator-new/free-unwind sequence. The needed ctor at 0x422980 is
  modelled as a minimal WIP stub `T422980::T422980` (real construction still
  lifted). 0x420D10 (147 bytes) is the +0x0FC display update: arg3==1 returns
  immediately, otherwise it forwards four args to the +0x68 `S45EDE0` device,
  copies that device's +0x2C/+0x30 pair into config +0x8E4/+0x8E8, reads the
  0x49F620 global twice and dispatches its +0x50 virtual with that pair, then
  dispatches the +0x138 base slot. Evidence: TU gate `[25/25] MATCH_FUNCs OK,
  19 WIP`; full gate `[1799/1799] MATCH_FUNCs OK, 31 WIP`; boot exit 0, no
  fault, `DC10 status=0 DC80=1 BC80=1 5B17D0=1 menu-loop=1`, window class/create
  2, hwnd 0x1A2B3C4D, DE50/E070 screens 1, WinMain returns 0. Ownership feedback:
  the header now declares the previously skipped base slots +0x138..+0x150
  (slot_078..slot_084) so slot85_422340 keeps its real +0x154 index; those
  slots are still lifted/undefined, so the native bring-up skips the +0x138
  dispatch instead of calling a raw guest word.

- stage 18 — 0x422340 (212 bytes, base slot +0x154) is byte-exact. It
  allocates the 0x208 screen/state object with the 0x64DAA8 name through a
  non-trivial ctor stub (keeping the original VC6 EH frame), stores the pointer
  at +0x10A0, runs the 0x45FB60 five-argument mode call with the +0x68 pointer,
  and on a zero result destroys/frees the object, clears +0x10A0 and returns 0;
  nonzero returns 1. The source layout returns 1 only after the cleanup block
  so VC6 emits the original block order. Evidence: TU gate `[26/26]
  MATCH_FUNCs OK, 18 WIP`; full gate `[1800/1800] MATCH_FUNCs OK, 30 WIP`; boot
  exit 0, no fault, `DC10 status=0 DC80=1 BC80=1 5B17D0=1 menu-loop=1`, window
  class/create 2, hwnd 0x1A2B3C4D, DE50/E070 screens 1, WinMain returns 0.
  The base slots +0x138..+0x150 are now declared (slot_078..slot_084) so
  slot85_422340 keeps the real +0x154 index. 0x460EC0 (TDrawArea::SetMode,
  95 bytes) remains WIP: its emitted bytes are identical to the original except
  the three inner-branch targets (VC6 merges them to the later epilogue at
  +0x59 instead of +0x4C); nested-if, early-return and goto forms all still
  chose the later target, so it stays a documented WIP.

Gaps now:
1. The native run now passes the MessageBox and executes the WinMain success
   branch: status 0, `Vt_04` (slot +0x04 `0x41CF70`) entered once and exited
   cleanly in headless mode. That is the menu/message-pump entry, but the actual
   menu UI is not yet built: 0x41BC80's WIP body skips its real 0x41D070/+0x78
   window and screen init chain, and 0x5B17D0's WIP body skips the session-screen
   builders (0x4320E0/0x421710/0x421AF0). 0x41DC80 remains 448 vs 461; the base
   and derived constructors 0x41B760 (1504 vs 1175) and 0x5B0EC0 (432 vs 686)
   remain WIP. Slot +0x28 (0x5B2F20, 2088) remains lifted.
2. Import ABI (partially done): stages 10-11 install trampolines for
   LoadLibraryA/GetProcAddress/FreeLibrary, timeBeginPeriod/timeGetTime/
   timeEndPeriod, GlobalFree and MessageBoxA, marshalling image pointers to
   guest VAs. Limits: only EBUEula has a native export wrapper; LoadStringA and
   GlobalAlloc are not installed yet, and host heap/stack pointers passed to
   shims are not translated into guest memory.
3. Guest ABI: matched-to-matched calls are consistent because all bodies are
   compiled by the host compiler; the gap is only at boundaries to unmatched
   lifted code/external imports, which need guest-ABI wrappers.
4. Coverage: phase docs show 428/815 phase-1 matched (268 left, 11 WIP, 119
   CRT/library); the map reflects the current workspace, so the matched count
   includes in-progress bodies not yet in this wave. Even a wired build would
   still boot lifted code through the remaining stubs.
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
