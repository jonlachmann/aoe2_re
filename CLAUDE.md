# aoe2_re — agent instructions

## Goal
1:1 re-implementation of vanilla Age of Empires 2: The Age of Kings (1999) from the original x86 binary.

## Key facts
- Reference target: a user-supplied local game executable selected by `AOE_BIN` (PE32 i386, 2.1MB `.text` + `THIS_COD` section, MSVC 6, timestamp 0x37DDFC16). The executable is git-ignored and never distributed.
- Local-install details and entry-point notes: see `docs/entry_point.md`.
- Engine: Genie (Ensemble Studios). App framework: global object `dword_6645C4`, vtable `off_61DF78` (message loop sub_41CF70, WndProc sub_41FAC0, idle tick sub_420450).
- Sibling projects (cloned in `refs/`, git-ignored): `sp00nznet/swgb-recomp` (SWGB static recomp, same engine/toolchain — read its docs/lifting.md), `samuelcaldas/age-of-empires-2-decomp` (matching decomp of Conquerors 1.0c + AoK 2.0a + PS2 — coordinate, don't duplicate). See docs/cross_references.md.
- Data formats documented by openage / genieutils — use them for DAT/DRS/SLP semantics rather than re-deriving.
- `docs/symbol_map.md`: 50 engine functions named via scoped assert strings (`diam_map::draw`, `pnl_txt::draw`, …); ~99 more via engine-debug strings (`data/engine_strings.json`).
- **Full-game lift done**: `Source/lifted/` — pcrecomp lifted 10,112 functions + 9,028 alias stubs (1.39M lines C, 0 errors) from the 19,140-function disasm32 catalog (`data/disasm32_catalog.json`). Difftest harness: `refs/pcrecomp/tools/lift/difftest.py`.
- Inflater coroutine (SWGB sub_0062343B analogue): ours at `0x5ED30C`, state block 0xAD90 bytes, resume index +0xA958 — miniz HLE contract maps 1:1 (see docs/cross_references.md §4).

## Matching (readable track) — read docs/matching.md
- Bar: byte-exact under real VC6 (`/O2`, wine). `MATCH_FUNC(0xADDR)` above the function, name ends in `_ADDR`; `WIP_FUNC` until it matches.
- Loop: `Scripts/match.py --next 20` → `--target 0xADDR` → write it in `Source/<module>/<class>.cpp` → `Scripts/match.py <file.cpp>` until OK → `Scripts/match.py` (all) → `Scripts/decomp_dashboard.py` → commit.
- **Never break a MATCH_FUNC**: `Scripts/match.py` must print `[N/N]` before every commit. Breaking one is OK only if N goes up overall; say so in the commit.
- Differential testing (`verify_one.py`) is not a substitute: it passed a reconstruction that wrote to the wrong row.

## Conventions
- Reconstructed code goes in `Source/<module>/`, one directory per engine subsystem.
- Keep functions in original order where known; match MSVC 6 codegen (see gta2_re docs/matching_quirks.md for patterns).
- Track progress with `Scripts/match.py` + `MATCHING.md` (reccmp needs a linked exe + PDB; not set up).
- Analysis notes in `docs/`; never commit proprietary binaries, assets, or extracted game content. Keep reference files under the git-ignored local `reference/` directory or outside the repository.

## Useful commands
- **Start here:** `docs/agent_plan.md` (step-by-step plan toward an SDL3 platform layer).
- Boot the lifted game: `Scripts/build_boot.sh` then `Scripts/run_boot.sh` (log: `build/boot/run.log`). Status + current blocker: `docs/bringup_log.md` (newest section last).
- Win32 surface the game touches, per DLL, with caller functions: `docs/platform_imports.md` (regenerate: `./venv/bin/python Scripts/platform_imports.py`). This is the map for replacing DirectX/DirectPlay/winmm with SDL3.
- Host shims (`Source/host/aoe_shims.c`): `RET(v, n)` pops n args — check the caller: `add esp,4n` after the call means cdecl → `RET(v, 0)`. A wrong n corrupts esp silently and faults much later.
- Analyze with rea: `npx -y rea-agents@latest` native analysis commands (needs a native analysis engine: Ghidra/Hopper/IDA).
- Diff/match: `reccmp` (see reccmp-project.yml).
- Python env for scripts: `./venv/bin/python` (pefile, capstone, lief installed).

## Local resources
- Local game install tree: kept outside the repository.
- Local runtime logs (behavior reference): kept outside the repository; never commit them.