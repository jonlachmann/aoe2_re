#!/bin/sh
# Run the lifted game for up to $SECS seconds (default 40); log to build/boot/run.log.
# Run from a local game install directory: win32hle resolves the game's DLLs
# (EBUEula.dll, language.dll) against the cwd.
R=$(cd "$(dirname "$0")/.." && pwd)
: "${AOE2_GAME_DIR:?set AOE2_GAME_DIR to your local game install directory}"
cd "$AOE2_GAME_DIR" || exit 1
"$R/build/boot/aoe_boot" "$@" > "$R/build/boot/run.log" 2>&1 &
p=$!
i=0; while [ $i -lt "${SECS:-40}" ] && kill -0 $p 2>/dev/null; do sleep 1; i=$((i+1)); done
kill $p 2>/dev/null
grep -v '^  0x\|esp\[' "$R/build/boot/run.log" | tail -40
