#!/bin/sh
# Run the native macOS boot binary against a local game installation.
set -eu
ROOT=$(cd "$(dirname "$0")/.." && pwd)
if [ -z "${AOE_BIN:-}" ]; then
  if [ -f "$ROOT/reference/AOE2.EXE" ]; then
    export AOE_BIN="$ROOT/reference/AOE2.EXE"
  else
    echo "Set AOE_BIN to your local reference executable (see README)." >&2
    exit 1
  fi
fi
[ -n "${AOE2_GAME_DIR:-}" ] || {
  echo "Set AOE2_GAME_DIR to your local game installation directory (see README)." >&2
  exit 1
}
[ -x "$ROOT/build/boot/aoe_boot" ] || {
  echo "Build first: Scripts/build_mac.sh" >&2
  exit 1
}
exec "$ROOT/Scripts/run_boot.sh" "$@"
