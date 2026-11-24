# aoe2_re

Research reconstruction of the Genie engine used by **Age of Empires II: The Age of Kings** (1999), based on the publicly documented Genie architecture and a locally supplied game executable.

This repository contains **source code, analysis notes, and tooling only**. It does not include or distribute any proprietary game binaries, data archives, graphics, audio, or other game assets.

## Local reference executable

To run analysis and byte-matching tooling, point `AOE_BIN` at a reference executable from your own lawful local installation:

```bash
export AOE_BIN=/absolute/path/to/your/local/reference-executable
```

Alternatively, place the executable under the git-ignored `reference/` directory. The path is never tracked or distributed by this repository.

## Project layout

```
Source/        reconstructed C/C++ sources, grouped by engine subsystem
Source/lifted/ machine-generated analysis output from a local reference image
docs/          architecture, boot, matching, and platform notes
Scripts/       analysis, lifting, matching, and differential-test tooling
data/          analysis catalogs and match-state metadata
patches/       host-platform compatibility patches
```

## Workflow

1. Analyze the locally supplied reference executable with Ghidra, IDA, Hopper, or rea.
2. Write byte-exact C/C++ reconstructions in `Source/<module>/`.
3. Compile with the matching-era MSVC toolchain and compare against the local reference.
4. Cross-reference openage/genieutils data-format documentation and related Genie-engine reconstruction projects.

Useful entry points:

- `docs/agent_plan.md` — platform-layer roadmap
- `docs/matching.md` — byte-exact matching workflow and compiler quirks
- `Scripts/match.py` — compile-and-compare harness (`AOE_BIN` required)
- `Scripts/build_boot.sh` / `Scripts/run_boot.sh` — local executable-track boot harness

## Related work

- [CriminalRETeam/gta2_re](https://github.com/CriminalRETeam/gta2_re) — project layout and matching workflow
- [morluto/rea](https://github.com/morluto/rea) — binary-analysis tooling
- openage / genieutils — Genie data-format documentation
- Other public Genie-engine reverse-engineering projects

## Legal note

Age of Empires II and its assets are the property of their respective rights holders. This project is an independent research reconstruction and is not affiliated with or endorsed by the rights holders. Users must supply their own lawful local copy for analysis; no proprietary game content is hosted in this repository.
