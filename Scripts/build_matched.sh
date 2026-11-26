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
  if "$CC" -x c++ -std=c++98 -w -O2 -DMATCHED_NATIVE \
      -fms-extensions -Wno-cast-pointer-to-smaller-type -fno-stack-protector \
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

# PE-named forwarding aliases for matched bodies (generated TU outside the
# function-map owner list). It defines the binary's mangled class/method names
# by calling the equivalent byte-exact matched code, so callers bind to real
# code instead of host stubs.
if "$CC" -x c++ -std=c++98 -w -O2 \
    -fms-extensions -Wno-cast-pointer-to-smaller-type -fno-stack-protector \
    -I"$R/Source" -I"$R/Source/ui" -I"$R/Source/game" -I"$R/Source/gfx" \
    -I"$R/Source/sim" -I"$R/Source/app" -I"$R/Source/crt" \
    -I"$R/Source/engine-late" \
    -c "$R/Source/host/matched_pe_aliases.cpp" -o "$B/matched_pe_aliases.o" \
    2>"$B/matched_pe_aliases.err"; then
  echo "PE alias TU compiled"
else
  echo "PE alias TU: FAILED (see $B/matched_pe_aliases.err)"
  head -5 "$B/matched_pe_aliases.err"
fi
if "$CC" -std=c++98 -w -O2 -I"$R/Source" -I"$R/Source/host" \
    -c "$R/Source/host/matched_guest_image.cpp" -o "$B/matched_guest_image.o" \
    2>"$B/matched_guest_image.err"; then
  echo "guest image TU compiled"
else
  echo "guest image TU: FAILED (see $B/matched_guest_image.err)"
  head -5 "$B/matched_guest_image.err"
fi

# Standard matched objects only (exclude generated glue/extra probes).
OBJ=""
for o in "$B"/*.o; do
  case "$(basename "$o")" in
    matched_globals.o|matched_stubs.o|va_*|probe_*) ;;
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
    -I"$R/Source" "$B/matched_guest_image.o" $SELF "$R/Scripts/matched_probe.cpp" -o "$B/probe" 2>"$B/link.err"; then
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
    if base.startswith(("va_", "probe_", "matched_globals", "matched_guest", "matched_pe_aliases")):
        continue
    for l in subprocess.run(["nm", "-u", o], capture_output=True, text=True).stdout.splitlines():
        s = l.strip()
        if s.startswith("_g_") and not s.startswith(("_g_matched_image", "_g_matched_base")):
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
# Generated sync from the mapped guest image: guarantees each g_* array holds
# the same bytes as the image at its guest VA.
sync = ["#include <string.h>", "", "extern \"C\" char* g_matched_image;",
        "extern \"C\" long g_matched_image_size;", ""]
for n in sorted(names):
    sync.append("extern char %s[0x1000];" % n)
sync += ["", "extern \"C\" void SyncGuestGlobals()", "{",
         "    char* im = g_matched_image;",
         "    if (im == 0) return;"]
synced = 0
for n in sorted(names):
    m = re.search(r"g_(?:pfn_|vt_)?([0-9a-fA-F]{6,8})$", n)
    if not m: continue
    va = int(m.group(1), 16)
    off = va - 0x400000
    if 0 <= off and off + 0x1000 <= 0x400000:
        sync.append("    memcpy(%s, im + 0x%X, 0x1000);" % (n, off))
        synced += 1
sync.append("}")
open(root + "/Scripts/matched_guest_sync.cpp", "w").write("\n".join(sync) + "\n")
sys.stderr.write("seeded %d globals from %s; synced %d globals\n" % (seeded, bin_path, synced))
print(len(names))
PY
GN=$(cat "$B/globals.txt")
"$CC" -std=c++98 -w -O2 -I"$R/Source" -c "$R/Scripts/matched_globals.cpp" \
  -o "$B/matched_globals.o"
"$CC" -std=c++98 -w -O2 -I"$R/Source" -I"$R/Source/host" \
  -c "$R/Scripts/matched_guest_sync.cpp" -o "$B/matched_guest_sync.o"
# Guest-image probe: load the PE-backed image, sync globals, verify contents.
if "$CC" -std=c++98 -w -O2 -Wl,-no_pie -DMATCHED_NATIVE \
    -I"$R/Source" -I"$R/Source/host" \
    "$B/matched_guest_image.o" "$B/matched_guest_sync.o" "$B/matched_globals.o" \
    "$R/Scripts/matched_probe_image.cpp" -o "$B/probe_image" \
    2>"$B/link_image.err"; then
  AOE_BIN="${AOE_BIN:-}" "$B/probe_image"
  echo "guest image: OK"
else
  echo "guest image: FAILED (see $B/link_image.err)"
  head -6 "$B/link_image.err"
fi
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
    "$B/matched_globals.o" "$B/matched_guest_image.o" $GLINK "$R/Scripts/matched_probe.cpp" -o "$B/probe_globals" \
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
    "$B/matched_globals.o" "$B/matched_guest_image.o" $GEXEC "$R/Scripts/matched_probe_globals.cpp" \
    -o "$B/probe_globals_exec" 2>"$B/link_globals_exec.err"; then
  "$B/probe_globals_exec"
  echo "globals exec probe: OK ($(echo "$GEXEC" | wc -w | tr -d ' ') objects)"
else
  echo "globals exec probe: FAILED"
  head -8 "$B/link_globals_exec.err"
fi

# Stage 5: link every matched object into one executable. Symbols the object
# set itself does not define get host stubs (asm-label functions returning 0,
# opaque data storage) so the remaining cross-TU/import references resolve;
# libSystem names are left to the linker. This proves the whole object set can
# link and run as one native binary; stubs are link fillers, not guest code.
"$R"/venv/bin/python - "$R" "$B" <<'PY'
import subprocess, glob, sys
root, B = sys.argv[1], sys.argv[2]
objs = [o for o in sorted(glob.glob(B + "/*.o"))
        if not any(k in o for k in ("matched_globals", "matched_stubs", "va_", "probe"))]
defined = set()
for o in objs:
    for l in subprocess.run(["nm", "-g", "--defined-only", o], capture_output=True, text=True).stdout.splitlines():
        p = l.split()
        if len(p) >= 3:
            defined.add(p[2])
und = set()
for o in objs:
    for l in subprocess.run(["nm", "-u", o], capture_output=True, text=True).stdout.splitlines():
        s = l.strip()
        if s:
            und.add(s)
allow = {"_bzero", "_free", "_malloc", "_calloc", "_memcpy", "_memset", "_memset_pattern16",
         "_strcmp", "_strcpy", "_strlen", "_fopen", "_fread", "_fclose",
         "__Unwind_Resume", "__gxx_personality_v0", "___gxx_personality_v0",
         "___chkstk_darwin",
         # C++ runtime allocations must come from libc++abi, never a 0-returning
         # stub: runtime/static initializers allocate through operator new.
         "__Znwm", "__Znwj", "__Znaj", "__ZdlPv", "__ZdlPvm", "__ZdaPv", "__ZdaPvm"}
extern = sorted(s for s in und if not s.startswith("_g_") and s not in defined)
funs = [s for s in extern if s not in allow and s != "_gTab_741758"]
data = [s for s in extern if s == "_gTab_741758"]
lines = ["// Generated host stubs for extern symbols the matched object set does not define.",
         "// Function stubs return 0 and carry the original symbol name via an asm label;",
         "// data stubs provide opaque storage. Used only to grow the matched-only link.",
         ""]
for i, s in enumerate(funs):
    lines.append('extern "C" int stub_%d() __asm__("%s");' % (i, s))
    lines.append("int stub_%d() { return 0; }" % i)
    lines.append("")
for i, s in enumerate(data):
    lines.append('extern "C" char stub_data_%d[0x4000] __asm__("%s");' % (i, s))
    lines.append("char stub_data_%d[0x4000];" % i)
open(root + "/Scripts/matched_stubs.cpp", "w").write("\n".join(lines) + "\n")
print("%d function stubs, %d data stubs" % (len(funs), len(data)))
PY
"$CC" -std=c++98 -w -O2 -fms-extensions -Wno-cast-pointer-to-smaller-type -fno-stack-protector \
  -I"$R/Source" -c "$R/Scripts/matched_stubs.cpp" -o "$B/matched_stubs.o"
ALLOBJ=""
for o in $OBJ; do ALLOBJ="$ALLOBJ $o"; done
# shellcheck disable=SC2086
if "$CC" -std=c++98 -w -O2 -Wl,-no_pie -I"$R/Source" \
    "$B/matched_globals.o" "$B/matched_stubs.o" $ALLOBJ \
    "$R/Scripts/matched_probe_globals.cpp" -o "$B/probe_all" 2>"$B/link_all.err"; then
  "$B/probe_all"
  echo "all matched objects linked: $(echo "$ALLOBJ" | wc -w | tr -d ' '); probe_all: OK"
else
  echo "all matched objects link: FAILED (see $B/link_all.err)"
  head -8 "$B/link_all.err"
fi

# Stage 3: portable guest-VA access layer (ADDR) under -DMATCHED_NATIVE.
if "$CC" -std=c++98 -w -O2 -DMATCHED_NATIVE -I"$R/Source" \
    -c "$R/Source/ui/C_vt6234C8.cpp" -o "$B/va_C_vt6234C8.o" \
    2>"$B/va_compile.err" &&
   "$CC" -std=c++98 -w -O2 -Wl,-no_pie -DMATCHED_NATIVE -I"$R/Source" \
    "$B/va_C_vt6234C8.o" "$B/matched_guest_image.o" "$R/Scripts/matched_probe_va.cpp" -o "$B/probe_va" \
    2>"$B/va_link.err"; then
  "$B/probe_va"
  echo "guest-VA access layer: OK"
else
  echo "guest-VA access layer: FAILED"
  head -5 "$B/va_compile.err" "$B/va_link.err"
fi
