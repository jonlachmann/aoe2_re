#!/bin/sh
# Prepare macOS build dependencies for the executable-track boot binary.
# Installs Homebrew SDL packages and fetches the MIT-licensed pcrecomp runtime
# into the git-ignored refs/ tree, at the commit our host patch targets.
set -eu
ROOT=$(cd "$(dirname "$0")/.." && pwd)
[ "$(uname -s)" = Darwin ] || { echo "bootstrap_mac.sh: macOS host required" >&2; exit 1; }
command -v brew >/dev/null 2>&1 || {
  echo "Homebrew required: https://brew.sh" >&2
  exit 1
}

for pkg in sdl2-compat sdl2_ttf; do
  if ! brew list --formula "$pkg" >/dev/null 2>&1; then
    echo "installing Homebrew package: $pkg"
    brew install "$pkg"
  fi
done

PCRE_REPO=${PCRE_REPO:-https://github.com/sp00nznet/pcrecomp.git}
PCRE_COMMIT=${PCRE_COMMIT:-a67767bed6ee1085fc6614f34c80ebfc25908f72}
PCRE_TREE=${PCRE_TREE:-$ROOT/refs/pcrecomp}
PATCH=$ROOT/patches/pcrecomp-win32hle.patch

FRESH=0
if [ ! -e "$PCRE_TREE/.git" ]; then
  mkdir -p "$(dirname "$PCRE_TREE")"
  echo "fetching pcrecomp runtime dependency into $PCRE_TREE"
  git clone "$PCRE_REPO" "$PCRE_TREE"
  git -C "$PCRE_TREE" checkout --detach "$PCRE_COMMIT"
  FRESH=1
fi
[ -f "$PCRE_TREE/runtime/win32hle/win32hle.h" ] || {
  echo "pcrecomp checkout is missing runtime/win32hle at $PCRE_TREE" >&2
  exit 1
}

if git -C "$PCRE_TREE" apply --check "$PATCH" 2>/dev/null; then
  git -C "$PCRE_TREE" apply "$PATCH"
  echo "applied host runtime patch to $PCRE_TREE"
elif git -C "$PCRE_TREE" apply --reverse --check "$PATCH" 2>/dev/null; then
  echo "host runtime patch already present in $PCRE_TREE"
elif [ "$FRESH" = 1 ]; then
  echo "host runtime patch did not apply to fresh pcrecomp checkout" >&2
  exit 1
else
  echo "note: existing $PCRE_TREE has local changes beyond the saved host patch; continuing" >&2
fi

echo
echo "macOS build prerequisites ready."
echo "Next: Scripts/build_mac.sh"
