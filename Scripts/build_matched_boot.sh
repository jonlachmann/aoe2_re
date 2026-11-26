#!/bin/sh
# Matched-only boot executable: link the byte-verified C++ owner objects plus the
# PE-backed guest image and the win32hle runtime into one standalone binary,
# then run it from the game's WinMain VA instead of the lifted CRT entry.
#
# This is deliberately separate from Scripts/build_boot.sh (which links lifted
# C). It assumes Scripts/build_matched.sh has produced build/matched/*.o.
set -e
R=$(cd "$(dirname "$0")/.." && pwd)
P=${PCRE_TREE:-$R/refs/pcrecomp}
W=$P/runtime/win32hle
B=$R/build/matched
BB=$R/build/matched_boot
CC=${CC:-clang++}          # C++ objects / link driver
CC_C=${CC_C:-cc}           # C objects (win32hle runtime, host glue)
mkdir -p "$BB"

[ -f "$W/win32hle.h" ] || {
  echo "win32hle runtime missing; run Scripts/bootstrap_mac.sh (or set PCRE_TREE)" >&2
  exit 1
}
[ -f "$B/matched_guest_image.o" ] && [ -f "$B/matched_stubs.o" ] || {
  echo "matched objects missing; run Scripts/build_matched.sh first" >&2
  exit 1
}
BREW_PREFIX=${HOMEBREW_PREFIX:-$(command -v brew >/dev/null 2>&1 && brew --prefix || true)}
[ -n "$BREW_PREFIX" ] || {
  echo "Homebrew not found; install SDL2 deps or set HOMEBREW_PREFIX" >&2
  exit 1
}
SDL="-I$BREW_PREFIX/include/SDL2 -D_THREAD_SAFE"
SDLLIBS="-L$BREW_PREFIX/lib"
CF="-O1 -g -w -DRECOMP_MEM_BASE=0x100000000000ull -DRECOMP_TRACE $SDL"

# win32hle runtime objects (no selftests).
for f in "$W"/*.c; do
  case "$(basename "$f")" in *_selftest.c) continue ;; esac
  o="$BB/$(basename "$f" .c).o"
  [ -f "$o" ] && [ "$o" -nt "$f" ] && continue
  "$CC_C" $CF -I"$W" -I"$W/../recomp32" -c "$f" -o "$o"
done

# Host glue: aoe_host.c main + shims + trace + fault mapping. The launch harness
# is unchanged; only its run step is redirected to the matched WinMain call.
o="$BB/aoe_host.o"
src="$R/Source/host/aoe_host.c"
[ -f "$o" ] && [ "$o" -nt "$src" ] && [ "$o" -nt "$R/Source/host/matched_run.c" ] || \
  "$CC_C" $CF -I"$W" -I"$W/../recomp32" -I"$R/Source/host" \
    -Drecomp_host_run=matched_recomp_host_run -c "$src" -o "$o"
for f in aoe_shims.c recomp_trace_portable.c eh32_portable.c; do
  o="$BB/$(basename "$f" .c).o"
  src="$R/Source/host/$f"
  [ -f "$o" ] && [ "$o" -nt "$src" ] && continue
  "$CC_C" $CF -I"$W" -I"$W/../recomp32" -I"$R/Source/host" -c "$src" -o "$o"
done
"$CC_C" $CF -I"$W" -I"$W/../recomp32" -I"$R/Source/host" -I"$R/Source" \
  -c "$R/Source/host/matched_run.c" -o "$BB/matched_run.o"

# Matched owner objects + alias/image/sync/globals/stubs. Exclude the prototype
# probes and va_ test object so only the real matched tree is linked.
ALLOBJ=""
for o in "$B"/*.o; do
  case "$(basename "$o")" in
    probe*|va_*) ;;
    *) ALLOBJ="$ALLOBJ $o" ;;
  esac
done
echo "matched objects for boot: $(echo "$ALLOBJ" | wc -w | tr -d ' ')"

# shellcheck disable=SC2086
"$CC" -Wl,-no_pie $CF -DMATCHED_NATIVE \
  -I"$R/Source" -I"$W" -I"$W/../recomp32" \
  $ALLOBJ "$BB"/aoe_host.o "$BB"/aoe_shims.o "$BB"/recomp_trace_portable.o \
  "$BB"/eh32_portable.o "$BB"/matched_run.o \
  $(ls "$BB"/*.o | grep -v -E 'aoe_host|aoe_shims|recomp_trace|eh32|matched_run') \
  -o "$BB/aoe_matched_boot" $SDLLIBS \
    -lSDL2 -lSDL2_ttf -framework Cocoa -lpthread -lm -lz 2>"$BB/link.err"
echo "linked $BB/aoe_matched_boot ($(nm "$BB/aoe_matched_boot" | grep -c ' T ' ) text symbols)"

if [ "${RUN:-1}" = 1 ]; then
  AOE_BIN=${AOE_BIN:-reference/AOE2.EXE}
  echo "running: AOE_BIN=$AOE_BIN $BB/aoe_matched_boot --headless"
  AOE_BIN="$AOE_BIN" "$BB/aoe_matched_boot" --headless
fi
