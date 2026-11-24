#!/bin/zsh
# Ghidra decompile functions by address: ./Scripts/decomp.sh 0x460ec0 [addr...]
: "${GHIDRA_HOME:?set GHIDRA_HOME to your Ghidra installation directory}"
GH="$GHIDRA_HOME"
AOE_BIN="${AOE_BIN:-reference/AOE2.EXE}"
mkdir -p /tmp/opencode/ghidra_proj
"$GH/support/analyzeHeadless" /tmp/opencode/ghidra_proj aoe -import "$AOE_BIN" -noanalysis -scriptPath Scripts/ghidra -postScript decomp.py "$@" 2>/dev/null
