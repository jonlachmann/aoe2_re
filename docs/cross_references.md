# Cross-references: sibling Genie engine projects

Status of the sister projects that share our engine, and what to mine from
each. Cloned under `refs/` (git-ignored — do not commit them).

## 1. sp00nznet/swgb-recomp — Star Wars: Galactic Battlegrounds static recomp

<https://github.com/sp00nznet/swgb-recomp> — MIT, active (v0.1.0-dev alpha).

Static recompilation of `Battlegrounds.exe` v1.1 (PE stamp `0x3C03FD69`,
2001-11-28, MSVC6, DirectDraw 8-bit, DirectPlay — the *same toolchain and
engine family* as our vanilla AoK exe) to ~4M lines of native C via the
author's [pcrecomp](https://github.com/sp00nznet/pcrecomp) toolchain.
14,272 functions cataloged, 14,313 lifted with 0 errors; main menu and a
scripted skirmish run headless.

What to mine:

- `docs/lifting.md` — the two-section code layout problem: SWGB's code is
  `.text` **plus a `THIS_COD` section** (matrix/blit routines). **Our binary
  has the same layout** (`THIS_COD` at VA `0x210000`, plus `THIS_DAT`,
  `Inf32Dat`). Any pcrecomp-style or reccmp-style pipeline must lay out *all*
  code sections at their VAs or functions lift to empty bodies and corrupt the
  stack.
- The engine's `genie.dat` / scenario / savegame streams are **raw deflate**,
  and Ensemble's inflater is hand-written x86 asm built as a *coroutine* that
  copies its guest stack into a state block and resumes by jump — it cannot be
  lifted; SWGB recomp HLEs it with miniz (`src/runtime/inflate.c`, same
  `(in, in_off, &in_len, out, out_off, &out_len, state, final)` contract).
  Expect the same function in our binary near their `sub_0062343B`.
- `softdd` software DirectDraw (from the X-Wing lineage) solves the
  "8-bit 800x600 modes or bust" problem (`"Could not initialize graphics
  system"`) for running the reconstruction on modern systems.
- Dialogs draw on `WM_PAINT` via `InvalidateRect` + wait — relevant to any
  headless harness we build.
- SWGB stores the CD letter in `CDPath` (HKLM virtualised to HKCU
  `VirtualStore`) and only checks that letter afterwards.

## 2. samuelcaldas/age-of-empires-2-decomp — matching decomp of our game

<https://github.com/samuelcaldas/age-of-empires-2-decomp> — active, objdiff-
based matching decompilation of:

- `AGE2_X1_1_0C_EN` — The Conquerors `age2_x1.exe` 1.0c (primary, real work
  happening there)
- `EMPIRES2_2_0A_EN` — **Age of Kings `empires2.exe` 2.0a** (secondary
  target; config stub exists but no hash pinned yet — our vanilla 1999 CD exe
  is the 2.0-era binary, timestamp `0x37DDFC16`, so this target is essentially
  *our* binary's patch lineage; coordinate rather than duplicate)
- PS2 `AOK.ELF` PAL/NTSC-J (Metrowerks MWCCPS2)

What to mine:

- `docs/ps2_binary_analysis.md` — debug strings in the PS2 ELF reveal Genie
  engine **source file names**: `tribegam.cpp` (main game loop, `TribeGame`),
  `obmanager.cpp` (object & zone management), `com_hand.cpp` (command handler
  & pre-game), `mydplay.cpp` (DirectPlay). The PC and PS2 engines share
  algorithms and struct layouts; cross-matching is explicitly feasible.
- `include/tribe_app.h` (`TRIBE_APP_SIZE 0x1948`), `include/screen_manager.h`,
  `src/app/tribe_app.cpp` — a matched Win32 event pump for `RGE_App` /
  `TRIBE_App`: quit-flag at `this+0x1C`, vtable method `0xA8` = message
  filter, `0xAC` = idle handler, matching the structure we measured in our
  binary (our app object `dword_6645C4`, vtable `off_61DF78`, message loop
  `sub_41CF70`, idle tick `sub_420450`).
- Engine class names visible in the PS2 slices: `BaseList`, `SubList`,
  `ScreenObj`, `MapZone`, `kt_mouse`, `BuildAI`, `ConAI`, `DiplomacyAI`,
  `TacticalAI2`, elevation mesh, spatial grid — a naming vocabulary for our
  `sub_XXXXXX` functions.
- `docs/open_empire_re_analysis.md` — DRS/SLP on-disk structs and the SLP
  scanline bytecode VM (matches openage's docs, C99-friendly).
- Their workflow (objdiff, per-version `config/`, pinned MSVC compilers) is a
  model for our reccmp setup.

## 3. Reference libraries (formats & naming)

- **sandsmark/genieutils** <https://github.com/sandsmark/genieutils> — C++
  library for Genie formats (AoE/AoK/SWGB); the de-facto public naming of
  `empires2.dat` structures.
- **sandsmark/freeaoe** <https://github.com/sandsmark/freeaoe> — engine that
  runs both AoE2 and SWGB data; proof of the shared data layer.
- **SiegeEngineers/genie-rs** <https://github.com/SiegeEngineers/genie-rs> —
  Rust DRS/SCX/DAT parsers from the AoE2 community tooling org.
- **openage** <https://github.com/SFTtech/openage> — canonical format docs.
- **glouw/openempire** (+ the RE blog series) — C99 recreation of the AoE2
  asset/terrain pipeline.

See also `docs/symbol_map.md` — the scoped assert strings in *our* binary
(`diam_map::draw`, `pnl_txt::draw`, `mouseptr::poll`, …) that pin 50 engine
methods to addresses.

## Relation to our targets

| Our finding | SWGB recomp | AoE2 decomp (PS2) |
|---|---|---|
| `dword_6645C4` app object, vtable `off_61DF78` | SWGB's app/window object | `TRIBE_App` / `RGE_App`, `TRIBE_APP_SIZE 0x1948` |
| Message loop `sub_41CF70`, idle tick `sub_420450` | same pump architecture | `func_00185230` event pump |
| `THIS_COD` section | `THIS_COD` blitters, jump tables | — |
| deflate savegame/scenario streams | coroutine inflater → HLE miniz | — |
| `data\empires2.dat` | `genie.dat` | `tribegam.cpp` main loop |

Working rule: when a `sub_XXXXXX` here resists naming, look for the
corresponding symbol in genieutils (data side) or the PS2 decomp's class
vocabulary (code side), and check SWGB recomp's lifted C for the same call
pattern (SWGB v1.1 is three years newer but the Genie core is the same).

## 4. SWGB recomp runtime architecture (from `refs/swgb-recomp/src/runtime/`)

The host model that would run our re-implementation, directly applicable:

- **Host is the process, game is the guest image**: host links at
  `/BASE:0x60000000` so the guest image (`0x400000..0xA5A000`) maps flat into
  the same address space; guest code runs at its original VAs.
- **Imports go to the real DLLs** (DirectSound, DirectPlay, winmm, VfW);
  **only DirectDraw is shimmed** by `softdd.c` — the game's fullscreen 8-bit
  mode rendered into a window (or nowhere under `--headless`).
- **Shims needed for a self-referencing game**: `GetModuleHandleA(NULL)` must
  return the guest image base, `GetModuleFileNameA(NULL)` the guest exe path
  (the game finds its own folder through them).
- **The deflate HLE contract**: the game's inflater is a stack-copying
  coroutine (`sub_0062343B` in SWGB; state block 0xAD90 bytes, resume index at
  +0xA958); the host replaces it with miniz behind the same
  `int inflate(in, in_off, &in_len, out, out_off, &out_len, state, final)`
  contract. Our binary will have an equivalent function near the same
  call sites (savegame/scenario/genie.dat streams).
- **`--headless` + `--shot`**: a private desktop + frame capture to .bmp —
  the harness pattern for conformance tests (their `conformance.py` runs
  scripted milestones: boot, data inflate, first frame, menu, exit).
- **Fault reporting**: every guest crash is reported with the faulting VA and
  the last native call — the same "lift wall" bookkeeping as
  `docs/lifting.md`.


## 5. Our inflater coroutine — confirmed and located

The state-block signature SWGB documented for their coroutine inflater
(`sub_0062343B`: 0xAD90-byte state block, resume index at +0xA958) exists in
our binary:

- **Coroutine body / resume dispatch**: `sub_005ED30C` (VA `0x5ED30C`) —
  the `MEM32(esi + 0xA958)` resume-index dispatch appears at `0x5ED339`,
  `0x5ED4D6`, `0x5ED9B1`
- **State allocator**: `sub_005ED915` (`mov eax, 0xAD90`)
- **Call surface**: 19 call sites into `sub_005ED30C`, and the CRT/asset
  readers funnel into the cluster: `sub_004BE980` (the byte-stream reader
  used all over WinMain's init) calls `0x5ED915`/`0x5ED91B`; the DRS/SLP
  layer (`sub_004B2E30`, `sub_004B3330`, `sub_0049FE60`…) calls the
  `0x5ED9D6..0x5ED9F4` stub family (thunk table into the cluster).

The miniz HLE contract from SWGB's `src/runtime/inflate.c` maps 1:1 onto
this cluster — same state block size, same resume-index convention.
