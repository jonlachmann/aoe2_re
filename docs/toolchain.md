# Toolchain setup (macOS, Apple Silicon host)

Status: working — REA → headless IDA (idalib) → Hex-Rays pseudocode of the
user-supplied local reference executable (`AOE_BIN`).

## Components

| Tool | Notes |
|---|---|
| rea CLI | npm `rea-agents`; use a supported Node release for your version |
| IDA Pro | a user-supplied, properly licensed IDA installation with idalib |
| ida-pro-mcp | upstream ida-pro-mcp in a local Python venv |
| reccmp | local Python environment + `reccmp-project.yml` |
| Python scripts | local `venv` with pefile, capstone, lief, pyyaml |

Use each vendor's supported headless/licensing setup. This repository does
not include or document modifications to third-party binaries or licensing
checks.

## Analysis-provider configuration

Configure the rea MCP provider for your own local IDA installation, for
example with `IDADIR` pointing at the IDA application's `Contents/MacOS`
directory. Keep machine-specific paths and credentials outside the
repository.

## Usage

```bash
# decompile a function by address (1:1 workflow: pick address from Ghidra/IDA)
rea decompile "$AOE_BIN" 0x42c2a0 --json

# function dossier with callees/xrefs
rea function "$AOE_BIN" 0x42c2a0 --json

# strings / callgraph
rea search-strings "$AOE_BIN" --pattern "civilization"
rea callgraph "$AOE_BIN" 0x42c2a0 --json

# reccmp once build/aoe2_re.exe exists
./venv/bin/reccmp-reccmp --target aoe2 --json
```

First headless open of the ~2MB reference image takes ~1–2 min (auto-analysis).
Set `AOE_BIN` to your local reference image before running analysis commands.
