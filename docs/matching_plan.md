# Full-game matching plan

Status snapshot and the roadmap from here to a complete 1:1
re-implementation of the user-supplied local reference executable (`AOE_BIN`).

## Where we are (the honest picture)

The project runs **two tracks** over the same binary:

| Track | What it is | State |
|---|---|---|
| **Executable track** (`Source/lifted/` + win32hle host) | pcrecomp mechanical lift of all 19,140 functions → 1.39M lines of state-machine C that compiles and *runs* under the portable Win32 host | Boots through CRT → ctors → EBUEula.dll → LANGUAGE.DLL → config strings → DirectX check → 800x600x8 DirectDraw + dsound; next stop mciSendCommandA (docs/bringup_log.md) |
| **Readable track** (`Source/autopilot/`, `Source/verified/`, `Source/engine/`) | Hand/mechanically-portable decompilation from the Hex-Rays corpus, one function per file, differentially verified against the original bytes | 479 functions verified; ~150 named |

**The lift is not meant to be cleaned up.** It is machine-generated
ground truth — a semantic oracle, not source. Hand-cleaning 1.39M lines
would be re-typing the decompilation by hand. Its value is (a) it *runs*,
and (b) any hand-written reconstruction can be differentially tested
against it (and against the original bytes) function-by-function. The
gta2_re workflow maps onto this as: readable C grows function-by-function
in `Source/<module>/`, each promotion verified via the difftest harness,
and the corresponding lift body retires.

### Inventory (measured)

| Region | VA range | Functions | Notes |
|---|---|---|---|
| Game code | `0x401000–0x5F0000` | 6,574 (IDA view) / ~18,600 (disasm32 view incl. EH funclets, thunks, split entries) | the actual game |
| CRT/runtime | `0x5F0000–0x610000` | 539 | MSVC 6 libc; unnamed |
| `THIS_COD` | `0x210000+` | 13 | legacy matrix/blit routines |
| Total | | **19,140** cataloged by disasm32, 95.0% byte coverage | `data/disasm32_catalog.json` |

### Verification state (the "matching" numbers)

| Metric | Count |
|---|---|
| Functions cataloged (disasm32) | 19,140 |
| Functions lifted (machine C) | 10,112 + 9,028 alias stubs |
| Lifted bodies difftested vs original bytes (unicorn) | **9,795 tested, 9,595 fully matching (98%)** |
| Divergent lifted functions | 200 — all classified cosmetic: 93 x87-fnstsw noise, 42 tail-continuation edges, 65 flag-model edges (`data/difftest_divergent*.txt/json`) |
| Hand/auto-ported functions differentially verified | **479** (`data/verified_functions.json`, 66 diverged = manual targets) |
| Functions named (scoped assert strings + engine-debug strings) | ~150 of 19,140 |
| Byte-exact recompile-matched (reccmp) | 0 — needs the VC6 toolchain (Phase D) |

Note the verification standard difference vs gta2_re: gta2_re proves
*compiler identity* (recompiled bytes == original bytes). Our lift track
proves *semantic identity* (emulated behavior == original behavior under
unicorn, on fuzzed inputs) — which is the pcrecomp/swgb-recomp standard.
Byte-exact recompilation remains the Phase D goal; semantic equivalence
is today's ground truth and is arguably the stronger correctness claim.

## Boot status (executable track)

The lifted game **boots and runs game code** under the win32hle host:
image mapped at 0x400000, 248 imports bound, CRT entry `0x600281` runs
heap/ioinit/env, the C++ ctor table runs, the entry stub runs its
timeBeginPeriod/timeGetTime prologue, `EBUEula.dll` is answered (shim +
`k_GetProcAddress` patch), `LANGUAGE.DLL` loads from the local install tree, string
resources are read, and the game formats its config strings
(`"Age of Empires II"`, version `"00.14.14.0914"`, `data\empires2.dat`,
registry key `Software\Microsoft\Microsoft Games\Age of Empires\2.0`).

Current fault: guest read of VA 0 at the `repne scasb` (strlen) at
`0x47AF7A`, through `edi` loaded from `[esp+0x1BB0]` at `0x47AF70` —
an argument-slot read in the WinMain body. Full diagnosis in
`docs/bringup_log.md`; remaining work is one stack-layout/arg-source
question, then the road to window creation (`sub_41D5D0`) and DirectDraw
init (`sub_45DF20`) is the same shim-per-fault loop that took SWGB from
boot to a playable menu.

## The plan

### Phase A — finish the boot (executable track) — *do first, ~days*

A running game is the single highest-value artifact: it produces dynamic
evidence (API call sequences, per-frame behavior, screenshotable frames)
that names and classes hundreds of functions — exactly how the SWGB
recomp recovered its engine vocabulary. Every day spent decompiling
blind costs more than a day of shim work.

1. Resolve the `0x47AF7A` NULL-read (stack layout / arg source; see
   `docs/bringup_log.md` next steps).
2. Shim-per-fault loop until window creation + DirectDraw init; then the
   800x600x8 mode set and the menu loop (SWGB's milestone list is the
   template: boot → genie/DAT inflate → directdraw → menu → exit).
3. Wire the miniz-behind-coroutine inflate contract at `0x5ED30C` when
   the DAT loader asks for it (contract documented in
   `docs/cross_references.md` §4).

### Phase B — gta2_re-style tracking infrastructure (parallel, ~a day)

Bring the readable track up to the gta2_re discipline:

1. **Function classes**: arrange reconstructions into
   `Source/<module>/` per engine subsystem — app framework
   (`dword_6645C4`, vtable `off_61DF78`), window/UI, graphics/DirectDraw,
   data formats (DAT/DRS/SLP), game loop, networking, sound, AI — the
   module map below. The engine is C++: recover classes from vtables and
   `this`-usage; the 50 scoped-assert names (`diam_map::draw`,
   `pnl_txt::draw`, …) are the seed class/method vocabulary.
2. **Per-function states** tracked in one registry
   (`data/function_states.json`, generated): `lifted` (machine C,
   semantically verified) → `decompiled` (readable C in `Source/`,
   difftest-verified vs original bytes and/or the lift body) → `matched`
   (byte-identical recompile — Phase D).
3. **Dashboard**: a script generating `MATCHING.md` (gta2_re style) with
   per-class matched/decompiled/lifted counts, from the catalog + symbol
   map + verification registry. Committed on every milestone.
4. **reccmp wiring**: `reccmp-project.yml` currently points at a
   placeholder build; wire it to the readable track's built objects and
   the symbol database so the dashboard and reccmp agree.

### Phase C — the decompilation loop (the long road)

Class-by-class, in boot-path and call-graph order:

1. **CRT/runtime layer** (0x5F0000–0x610000): already understood through
   the bring-up; write it down as readable C — it anchors everything.
2. **App framework**: `dword_6645C4` vtable family, message loop,
   WndProc, tick — the spine the whole game hangs on.
3. **Boot-path subsystems in execution order**: config/registry, DAT
   loader + inflater coroutine, DRS/SLP codecs, palette/resource setup,
   DirectDraw wrapper, window/paint classes, menu flow.
4. **Then breadth**: top-down by caller count (the corpus has the call
   graph), bottom-up leaf sweep in parallel via the autoport pipeline.
5. Every promoted function: readable C in `Source/<module>/`, difftest
   green vs original bytes, lift body marked retired in the registry.
6. Coordinate with `refs/aoe2-decomp` (same engine, Conquerors 1.0c +
   AoK 2.0a): import naming/vocabulary, don't duplicate work.

### Phase D — byte-exact recompilation (needs VC6)

True reccmp byte-matching needs `cl.exe` (VC 6) under an x86 Windows/
Linux box or VM — this Mac's wine can't run 32-bit x86 PE on Apple
Silicon. Sources are kept MSVC-6-flavored so they compile unmodified
when the toolchain exists; the difftest results carry over as the
semantic ground truth. gta2_re's `docs/matching_quirks.md` codegen
patterns are the reference for the port.

## Module map (class layout for `Source/`)

| Module | Anchors | Evidence |
|---|---|---|
| `app` | `dword_6645C4`, vtable `off_61DF78`, message loop `sub_41CF70`, WndProc `sub_41FAC0`, tick `sub_420450` | `docs/entry_point.md` |
| `win` | `sub_41D5D0` (RegisterClass), `sub_41D670` (WndProc trampoline) | |
| `gfx` | `sub_45DF20` (DirectDrawCreate), `diam_map::draw*` family | symbol map |
| `data` | DAT loader + inflater coroutine `0x5ED30C`, DRS/SLP codecs | `docs/cross_references.md` |
| `game` | game-loop functions from the tick | |
| `net` | DirectPlay imports (`DPLAYX.dll`) | pe imports |
| `sound` | `mixer*`/`mci*` imports (WINMM) | pe imports |
| `crt` | the 0x5F0000–0x610000 runtime layer | boot archaeology |
| `host` | win32hle shims + bring-up scaffolding (not game code) | |

## Autoport pipeline (readable-track engine)

`Scripts/auto_port.py` mechanically ports pure leaf functions from the
Hex-Rays corpus to standalone C, compiles them with `i686-w64-mingw32-g++`,
and differentially verifies each against the original bytes (40 fuzzed
cases per function; crash-on-both = model skip, any divergence = reject).

| Outcome | Count |
|---|---|
| Auto-ported & verified (sweep 1) | 403 |
| Diverged (manual targets) | 66 |
| Skipped (no corpus file / compile fail) | 85 |
| Second sweep | +51 |
| **Total distinct verified** | **479** |

Survivors live in `Source/autopilot/`; the 66 diverged functions are the
highest-value manual targets. The pipeline generalizes beyond leaf
functions as argument models are added — the same harness the readable
track uses for every promotion.