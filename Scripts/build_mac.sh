#!/bin/sh
# Build the native macOS boot binary:
#   build/boot/aoe_boot  (Mach-O for the current host architecture)
set -eu
ROOT=$(cd "$(dirname "$0")/.." && pwd)
PCRE_TREE=${PCRE_TREE:-$ROOT/refs/pcrecomp}
if [ ! -f "$PCRE_TREE/runtime/win32hle/win32hle.h" ]; then
  "$ROOT/Scripts/bootstrap_mac.sh"
fi
"$ROOT/Scripts/build_boot.sh"
[ -x "$ROOT/build/boot/aoe_boot" ] || {
  echo "build did not produce build/boot/aoe_boot" >&2
  exit 1
}
echo
echo "Native macOS binary: $ROOT/build/boot/aoe_boot"
echo "Run against a local installation with:"
echo "  export AOE_BIN=/path/to/local/reference-executable"
echo "  export AOE2_GAME_DIR=/path/to/local/game-install"
echo "  Scripts/run_mac.sh"
