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
files = sorted({r["file"] for r in fm if r.get("state") in ("matched", "wip") and r.get("file")})
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

# Standard matched objects only (exclude generated glue/extra probes).
OBJ=""
for o in "$B"/*.o; do
  case "$(basename "$o")" in
    matched_globals.o|va_*|probe_*) ;;
    *) OBJ="$OBJ $o" ;;
  esac
done

# Stage 1: objects with no undefined symbols are pure self-contained C++.
SELF=""
for o in $OBJ; do
  [ "$(nm -u "$o" 2>/dev/null | wc -l | tr -d ' ')" = 0 ] && SELF="$SELF $o"
done
echo "self-contained objects: $(echo "$SELF" | wc -w | tr -d ' ')"
# shellcheck disable=SC2086
if "$CC" -std=c++98 -w -O2 -Wl,-no_pie \
    -I"$R/Source" $SELF "$R/Scripts/matched_probe.cpp" -o "$B/probe" 2>"$B/link.err"; then
  "$B/probe"
  echo "self-contained link: OK (link.err $(wc -c < "$B/link.err" | tr -d ' ') bytes)"
else
  echo "self-contained link: FAILED (see $B/link.err)"
  head -5 "$B/link.err"
fi

# Stage 2: define every guest global (`g_*`) the objects reference as opaque
# storage, so objects whose only undefined symbols are globals can link.
"$R"/venv/bin/python - "$R" "$B" > "$B/globals.txt" <<'PY'
import subprocess, glob, sys, re, os
root, B = sys.argv[1], sys.argv[2]
names = set()
for o in glob.glob(B + "/*.o"):
    base = o.rsplit("/", 1)[-1]
    if base.startswith(("va_", "probe_", "matched_globals")):
        continue
    for l in subprocess.run(["nm", "-u", o], capture_output=True, text=True).stdout.splitlines():
        s = l.strip()
        if s.startswith("_g_"):
            names.add(s[1:])

pe = None
bin_path = os.environ.get("AOE_BIN")
if bin_path and os.path.exists(bin_path):
    import pefile
    pe = pefile.PE(bin_path)

lines = ["// Generated guest-global storage from the matched objects.",
         "// Initializers come from the reference binary's data image (AOE_BIN).", ""]
seeded = 0
for n in sorted(names):
    init = ""
    m = re.search(r"g_(?:pfn_|vt_)?([0-9a-fA-F]{6,8})$", n)
    if pe and m:
        va = int(m.group(1), 16)
        if va >= 0x400000:
            try:
                d = pe.get_data(va - 0x400000, 0x40)
                init = " = {%s}" % ",".join("0x%02x" % b for b in d)
                seeded += 1
            except Exception:
                pass
    lines.append("char %s[0x1000]%s;" % (n, init))
open(root + "/Scripts/matched_globals.cpp", "w").write("\n".join(lines) + "\n")
sys.stderr.write("seeded %d globals from %s\n" % (seeded, bin_path))
print(len(names))
PY
GN=$(cat "$B/globals.txt")
"$CC" -std=c++98 -w -O2 -I"$R/Source" -c "$R/Scripts/matched_globals.cpp" \
  -o "$B/matched_globals.o"
GLINK=""
for o in $OBJ; do
  u="$(nm -u "$o" 2>/dev/null)"
  if [ -z "$u" ] || { [ -n "$u" ] && [ -z "$(printf '%s\n' "$u" | grep -v '^_g_')" ]; }; then
    GLINK="$GLINK $o"
  fi
done
echo "guest globals defined: $GN; globals-linkable objects: $(echo "$GLINK" | wc -w | tr -d ' ')"
# shellcheck disable=SC2086
if "$CC" -std=c++98 -w -O2 -Wl,-no_pie -I"$R/Source" \
    "$B/matched_globals.o" $GLINK "$R/Scripts/matched_probe.cpp" -o "$B/probe_globals" \
    2>"$B/link_globals.err"; then
  "$B/probe_globals"
  echo "globals link: OK"
else
  echo "globals link: FAILED (see $B/link_globals.err)"
  head -5 "$B/link_globals.err"
fi

# Stage 4: execute matched bodies that read PE-initialized guest globals.
GEXEC=""
for o in $OBJ; do
  u="$(nm -u "$o" 2>/dev/null)"
  if [ -n "$u" ] && [ -z "$(printf '%s\n' "$u" | grep -v '^_g_')" ]; then
    GEXEC="$GEXEC $o"
  fi
done
# shellcheck disable=SC2086
if "$CC" -std=c++98 -w -O2 -Wl,-no_pie -I"$R/Source" \
    "$B/matched_globals.o" $GEXEC "$R/Scripts/matched_probe_globals.cpp" \
    -o "$B/probe_globals_exec" 2>"$B/link_globals_exec.err"; then
  "$B/probe_globals_exec"
  echo "globals exec probe: OK ($(echo "$GEXEC" | wc -w | tr -d ' ') objects)"
else
  echo "globals exec probe: FAILED"
  head -8 "$B/link_globals_exec.err"
fi

# Stage 3: portable guest-VA access layer (ADDR) under -DMATCHED_NATIVE.
if "$CC" -std=c++98 -w -O2 -DMATCHED_NATIVE -I"$R/Source" \
    -c "$R/Source/ui/C_vt6234C8.cpp" -o "$B/va_C_vt6234C8.o" \
    2>"$B/va_compile.err" &&
   "$CC" -std=c++98 -w -O2 -Wl,-no_pie -DMATCHED_NATIVE -I"$R/Source" \
    "$B/va_C_vt6234C8.o" "$R/Scripts/matched_probe_va.cpp" -o "$B/probe_va" \
    2>"$B/va_link.err"; then
  "$B/probe_va"
  echo "guest-VA access layer: OK"
else
  echo "guest-VA access layer: FAILED"
  head -5 "$B/va_compile.err" "$B/va_link.err"
fi
