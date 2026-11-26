#!/bin/sh
# Prototype matched-only build: compile the byte-verified C++ TUs with the host
# compiler into native objects under build/matched. This is deliberately separate
# from Scripts/build_boot.sh (which links lifted C + win32hle) and does not touch it.
#
# The matched bodies are written against the guest ABI as plain C++ (thiscall
# members, guest-VA fields), so a native link additionally needs (1) a guest
# memory mapping/access layer for their direct VA dereferences and (2) guest-ABI
# entry wrappers. This script only proves the compile stage.
set -e
R=$(cd "$(dirname "$0")/.." && pwd)
B=$R/build/matched
CC=${CC:-clang++}
mkdir -p "$B"

# Every TU that owns at least one matched body (from data/function_map.json).
LIST=$B/tus.txt
"$R"/venv/bin/python - "$R" > "$LIST" <<'PY'
import json, sys
root = sys.argv[1]
fm = json.load(open(root + "/data/function_map.json"))
files = sorted({r["file"] for r in fm if r.get("state") == "matched" and r.get("file")})
for f in files:
    print(f)
PY

ok=0; bad=0
for f in $(cat "$LIST"); do
  out=$B/$(echo "$f" | sed 's|/|_|g;s|\.cpp$|.o|')
  if "$CC" -x c++ -std=c++98 -w -O2 \
      -fms-extensions -Wno-cast-pointer-to-smaller-type \
      -I"$R/Source" -I"$R/Source/lifted" -I"$R/Source/host" \
      -I"$R/Source/ui" -I"$R/Source/game" -I"$R/Source/gfx" \
      -I"$R/Source/sim" -I"$R/Source/app" -I"$R/Source/crt" \
      -I"$R/Source/engine-late" \
      -c "$R/$f" -o "$out" 2>"$B/$(basename "$out" .o).err"; then
    ok=$((ok+1))
  else
    bad=$((bad+1))
    echo "FAIL $f"
  fi
done
echo "matched TUs compiled: $ok ok, $bad failed (objects in $B)"

# Native link stage: objects with no undefined symbols can link without any
# lifted code, guest-memory map or wrapper — they are pure self-contained C++.
SELF=""
for o in "$B"/*.o; do
  [ "$(nm -u "$o" 2>/dev/null | wc -l | tr -d ' ')" = 0 ] && SELF="$SELF $o"
done
echo "self-contained objects: $(echo "$SELF" | wc -w | tr -d ' ')"
# shellcheck disable=SC2086
if "$CC" -std=c++98 -w -O2 -Wl,-no_pie \
    -I"$R/Source" $SELF "$R/Scripts/matched_probe.cpp" -o "$B/probe" 2>"$B/link.err"; then
  "$B/probe"
  echo "native matched probe: OK (link.err empty: $(wc -c < "$B/link.err" | tr -d ' ') bytes)"
else
  echo "native matched probe: link FAILED (see $B/link.err)"
  head -5 "$B/link.err"
fi
