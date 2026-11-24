#!/bin/sh
# Build build/boot/aoe_boot: the lifted game (Source/lifted) + win32hle
# (refs/pcrecomp/runtime/win32hle) + our host glue (Source/host).
# Incremental: an object is rebuilt when its source or recomp_types.h is newer.
set -e
R=$(cd "$(dirname "$0")/.." && pwd)
W=$R/refs/pcrecomp/runtime/win32hle
B=$R/build/boot
mkdir -p "$B" "$B/lifted_w"
cd "$B"

# Lifted function definitions are marked weak (a shadow copy, line-identical
# to the source): a strong sub_XXXXXXXX in Source/host/overrides.c then wins
# at link time, in the dispatch table and at every direct RECOMP_CALL site.
# Regenerated only when a lifted source changes.
for f in "$R"/Source/lifted/recomp_0*.c; do
  o="lifted_w/$(basename "$f")"
  [ -f "$o" ] && [ "$o" -nt "$f" ] && continue
  sed 's/^void sub_/__attribute__((weak)) void sub_/' "$f" > "$o"
done
[ -f lifted_w/recomp_funcs.h ] || cp "$R"/Source/lifted/recomp_funcs.h lifted_w/
[ lifted_w/recomp_funcs.h -nt "$R"/Source/lifted/recomp_funcs.h ] || cp "$R"/Source/lifted/recomp_funcs.h lifted_w/

SDL="-I/opt/homebrew/include -I/opt/homebrew/include/SDL2 -I/opt/homebrew/opt/sdl2_ttf/include/SDL2"
CF="-O1 -g -w -DRECOMP_MEM_BASE=0x100000000000ull -DRECOMP_TRACE $SDL"
{
  for f in $(ls "$W"/*.c | grep -v _selftest.c); do echo "-I$W -I$W/../recomp32 -I$W $f"; done
  # the lift's own recomp_types.h must win over the runtime's copy; the weak
  # shadow copies are compiled (recomp_funcs.h comes from lifted_w too, so a
  # stray strong include cannot pick up the unmarked originals)
  for f in "$B"/lifted_w/recomp_0*.c "$R"/Source/lifted/recomp_dispatch.c; do echo "-I$R/Source/lifted -I$B/lifted_w -I$W $f"; done
  for f in "$R"/Source/host/*.c; do echo "-I$W -I$W/../recomp32 -I$W $f"; done
} | while read -r i1 i2 i3 src; do
  o=$(basename "$src" .c).o
  [ -f "$o" ] && [ "$o" -nt "$src" ] && [ "$o" -nt "$R/Source/lifted/recomp_types.h" ] && [ "$o" -nt "lifted_w/$(basename "$src")" ] && continue
  echo "cc $CF $i1 $i2 $i3 -c $src -o $o"
done | tr '\n' '\0' | xargs -0 -P "${JOBS:-10}" -n 1 sh -c
cc -o aoe_boot *.o -L/opt/homebrew/opt/sdl2-compat/lib -L/opt/homebrew/opt/sdl2_ttf/lib \
   -lSDL2 -lSDL2_ttf -framework Cocoa -lpthread -lm -lz
echo "built $B/aoe_boot"
