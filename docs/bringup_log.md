# Bring-up log (lifted game on win32hle)

## Status 2026-11-22

The lifted game boots through the CRT, runs the constructor table, enters the
WinMain stub, and executes real game code: it loads EBUEula.dll (answered via
a shim; `k_GetProcAddress` patched to consult the shim registry by export name
for guest-mapped DLLs) and LANGUAGE.DLL from the local install tree, reads string
resources, and formats config strings.

### Current crash

Guest fault (read or write at guest VA 0) inside the CRT's byte-copy loop
(inline `rep movsb`-shaped code, faulting host instruction
`and x19, x12, #0x3` + `ldrb/strb` loop — a memcpy tail), reached from the
CRT printf engine `sub_00602B06` (0x248-byte frame, `__output` routine) after
the chain:

    CRT entry -> WinMain stub (0x47AE20) -> real init (0x47AE8E..)
    -> 0x5F9D20 (empires2.dat magic 0xBEAD check)
    -> 0x47B620 (language init) -> 0x473AE0 x2 (string ids 0x3EF/0x3F0)
    -> 0x5FDCD4 -> 0x5FDCEB -> 0x6043DA -> 0x601BED -> 0x5FCE14 (sprintf)
    -> 0x602B06 (printf engine) -> 0x603247 (putc) xN -> fault

### What we know

- The faulting code is in the tail-merged body the lifter put inside
  `sub_0047AE20` (static 0x1004edfc8, +0x1050); the g_cur_func global still
  says 0x47AE20 because the path enters via tail-merge, not RECOMP_ENTER.
- The guest stack is healthy (0x3FFxxx region) at every function entry — the
  null write/read happens mid-body (live register file only synced at
  boundaries; host arm64 x19-x28 hold the live state).
- Config-string pool at 0x653020.. is intact in guest memory (matches the
  file): `data\empires2.dat`, `tr_wrld.txt`, `00.14.14.0914`,
  `Age of Empires II`, `Software\Microsoft\Microso...`.
- The real WinMain start (0x47AE8E) copies pool strings into stack buffers
  and calls 0x5FCE14 (sprintf-family) with format "%s" from 0x64D2B8.
- String ids 0x3EF (1007) and 0x3F0 (1008) are read from LANGUAGE.DLL:
  1007 is empty in the local install's DLL too; 1008 = `WARRANTY.RTF`.
- `k_GetStdHandle` now returns 0 (a GUI app has no console); the crash is
  unchanged, so the printf destination is a sprintf buffer, not stdout.
- The crash register dump: esi -> 0x65302A (pool), ebx=0, eax=0 — consistent
  with a copy whose SOURCE pointer came out NULL after the string reads.

### Diagnostics added (committed)

- Fault handler: host backtrace, live arm64 registers (x19-x28), guest
  register file, config-pool dump, guest esp ring (4096 entries at every
  RECOMP_ENTER), trace ring enlarged 1024 -> 65536.
- `--watch 0x603247` dumps the putc cursor/FILE object at every entry.

### Next steps

1. `--argobj`/`--watch` on 0x473AE0 (string reader): log its return value and
   the destination buffer contents for ids 0x3EF/0x3F0 — find which consumer
   gets a NULL/empty and feeds the memcpy.
2. Identify the exact guest function of the faulting memcpy (find which
   `and ecx, 3` tail matches the host asm at static 0x1004edfc8 by register
   allocation pattern).
3. The game's EULA path wants registry key
   `Software\Microsoft\Microsoft Games\Age of Empires\2.0\EULA` — the win32hle
   registry layer may need the key synthesized for the check to pass.

## Diagnosis progress 2026-11-22 (later)

**The fault is identified.** The guest fault (access at guest VA 0) is the
`repne scasb` (strlen) at `0x47AF7A` reading through `edi` - and `edi` was
loaded from `[esp+0x1BB0]` at `0x47AF70`, which is **NULL**.

That read is one of the WinMain body's argument reads: per the docs the body
reads `hInstance/lpCmdLine/nShowCmd` from `[esp+0x1BA8..0x1BB4]` - i.e.
`[esp+0x1BB0]` = **lpCmdLine**. But the actual args (pushed by the CRT
startup) sit at `[esp+0x1B98..0x1BA8]`:

    +0x1B98  0x00400000   hInstance (image base - GetModuleHandleA result)
    +0x1B9C  0            hPrevInstance
    +0x1BA0  0x10401598   lpCmdLine (the strdup'd command line, guest heap)
    +0x1BA4  0x0000000A   nShowCmd (10)

So the body's read lands **0x10 (4 dwords) above lpCmdLine**, in the stale
slot where the startup's `GetModuleHandleA` argument (esi) was pushed and
popped - and the startup's esi at that point was 0, so the slot holds 0.

Stack archaeology so far:

- The "chkstk" the stub calls at `0x47AE25` (`sub_005FE370`) ends with
  `mov esp, ecx` - it performs the `sub esp, eax` allocation (eax = 0x1B88).
  (Correction 2026-11-23: that is the stock MSVC6 `__chkstk`.)
- The stub then runs its checks (timeBeginPeriod/timeGetTime via IAT slots
  `0x61C3D8`/`0x61C3C8` - shims verified correct: `RET(v, n)` pops n*4+4).
- At `0x47AE8E` (the body) esp = E-0x1B90 (E = WinMain entry esp).
- The CRT startup (`sub_00600281`) builds the args: nShowCmd from
  GetStartupInfoA's SI (buffer at `[ebp-0x5C]`, `SI.dwFlags` at `[ebp-0x30]`
  cross-checked), lpCmdLine = the `sub_00606040` command-line parse result
  stored at `[ebp-0x64]`, hInstance = `GetModuleHandleA(esi)`.

Open question: on real Windows the body's `[esp+0x1BB0]` read must land on a
valid string (the game worked), so either the docs' `+0x1BA8..+0x1BB4` range
is relative to a different esp point in the body (the body's esp moves between
`0x47AF70` and the arg reads at `0x47B066+`), or the startup leaves a string
there that our host's default command line (`"game.exe"`,
`hle_set_command_line` never called by our driver) fails to produce.

Next steps:

1. Verify the body's esp at `0x47B066+` vs `0x47AF70` (do the two read sites
   agree on where the args are?).
2. Give the host a real command line via `hle_set_command_line` (full exe
   path) - the CRT parses it to find the exe path; the default `"game.exe"`
   may break the parse into a NULL.
3. Check what the startup's esi holds at the `GetModuleHandleA(esi)` call
   (the stale slot the body reads) - on Windows it must be a string pointer;
   find which startup local it is and why ours is 0.

## Resolved 2026-11-23: EBUEula shim popped its arguments

Root cause of the NULL lpCmdLine: **`s_EBUEula` (Source/host/aoe_shims.c) was
written as stdcall (`RET(1, 4)`) but `EBUEula` is cdecl** - its caller
`sub_47B620` cleans up itself (`call edi; add esp, 0x10` at `0x47B706`). Each
call left esp 16 bytes high, so WinMain's `[esp+0x1BB0]` read landed 0x10
above lpCmdLine. Fixed with `RET(1, 0)`.

How it was found: the static esp walk of the stub + body is consistent
(at `0x47AF70` esp = E-0x1BA4, so `[esp+0x1BB0]` = E+0xC = lpCmdLine - the
offset was never wrong). The esp ring (one entry per RECOMP_ENTER) lined up
against the entry trace showed `sub_47B620` entered at the expected esp but
the next call (`sprintf` at `0x47AEEE`) entered 0x10 high; the only
non-guest call inside `sub_47B620` is the `GetProcAddress`'d `EBUEula`.
Caveat for future dumps: the fault handler's `esp=` is `g_esp`, synced only at
function boundaries, so `[esp+N]` dumps mid-body are relative to a stale esp.

**Rule for every new shim: check the caller's cleanup.** `add esp, 4*n` after
the call = cdecl = `RET(v, 0)`; no cleanup = stdcall = `RET(v, n)`. A wrong
argc does not crash at the call - it corrupts esp silently and faults later.

Also removed: the temporary `[DIAG startup]` block in `recomp_0039.c` and the
`RECOMP_MOVS_CHECK` in `recomp_types.h` (both served this hunt).

### Build / run on macOS

- `Scripts/bootstrap_mac.sh` installs SDL dependencies and fetches the
  git-ignored pcrecomp runtime at the pinned host-patch commit.
- `Scripts/build_mac.sh` -> `build/boot/aoe_boot` (incremental, ~2 min CPU /
  ~16 s wall from scratch on 10 cores). Host main is
  `Source/host/aoe_host.c`.
- `Scripts/run_mac.sh` runs it from `$AOE2_GAME_DIR` with `AOE_BIN`, logs to
  `build/boot/run.log`, killed after `$SECS` (40) s.

## Resolved 2026-11-23: DirectX 6.1a check (DirectPlay)

Boot now gets past language init and exits with
`MessageBox: Age of Empires II requires DirectX 6.1a or higher.`

The check is `sub_465270`. It decides the DirectX version **from DirectPlay**:

1. `DirectPlayCreate(&guid@0x642F88, &dp, NULL)` (dplayx #1) - failure -> "too old".
2. `dp->QueryInterface(IID_IDirectPlay4 {0AB1C530-4745-11D1-A7A1-0000F803ABFC})`
   - failure -> "too old"; then both objects are Released (vtable +8).
3. `GetModuleHandleA("dplayx")` -> `GetModuleFileNameA` ->
   `GetFileVersionInfoSizeA/GetFileVersionInfoA/VerQueryValueA("\\")` and
   tests the VS_FIXEDFILEINFO file version (ms.hi.ms.lo.ls.hi.ls.lo): passes
   for >= 4.06.03.0516 (DX 6.1a's dplayx is 4.06.03.0518), any 4.07+, any 5+.

Today `aoe_shims.c` answers dplayx #1/#2/#4 with `DPERR_UNAVAILABLE` (all
callers check the HRESULT), and win32hle's VERSION shims (advapi32.c) report
"no version info". To pass, the host needs:

- `s_DirectPlayCreate` returning an `hle_com_new` object whose vtable has
  `hle_com_QueryInterface/AddRef/Release` (QI already answers any IID with
  S_OK); the remaining IDirectPlay methods can fail with DPERR_UNAVAILABLE
  until multiplayer is reached.
- VERSION.dll answering for the `dplayx.dll` path with a fixed file version
  4.6.3.518. **Registration order matters:** `hle_resolve` takes the *first*
  shim registered under a name (host_lite.c), and `win32hle_aoe` is registered
  after the built-ins, so an `aoe_shims.c` entry named `GetFileVersionInfoA`
  is shadowed. Either fix `v_GetFileVersionInfo*` in win32hle (refs/pcrecomp,
  upstream) or make `win32hle_register` let later entries override.

Longer term (SDL3 plan): DirectPlay is only needed for this check and for
multiplayer - see `docs/platform_imports.md` for every dplayx/wsock32 call
site. Replacing `sub_465270`'s answer (or the whole net module) in the
readable track removes the need to emulate DirectPlay at all.

**Resolved the same day** (Source/host/aoe_shims.c): DirectPlayCreate returns
an `hle_com_new` object (QI/AddRef/Release real, slots 3..63 named
unimplemented stubs `IDirectPlay::slotN`); VERSION.dll answers 4.06.03.0518
for `dplayx.dll` only. `win32hle_aoe` is now registered *before*
`recomp_host_init()` (Source/host/aoe_host.c) so our shims win name clashes.

Also: the previous session's uncommitted win32hle edits in `refs/pcrecomp`
(git-ignored) are saved as `patches/pcrecomp-win32hle.patch` (against
pcrecomp a67767b). Re-apply with `git -C refs/pcrecomp apply` after a fresh clone.

## Current blocker 2026-11-23: mciSendCommandA

Boot now sets `800x600x8`, creates the DirectDraw primary surface, opens
dsound (coreaudio 44100 Hz), then stops:
`FATAL: unimplemented import mciSendCommandA called from guest 0x004988E0`
(MCI = media audio / MIDI music; winmm). See docs/agent_plan.md step 1.

## Resolved 2026-11-23: mciSendCommandA (media-audio / MCI music driver)

Boot stopped at `FATAL: unimplemented import mciSendCommandA called from guest
0x004988E0`. The caller is the game's MCI music driver (function at 0x4988E0,
called via the winmm IAT slot 0x61C3CC): it opens a media-audio device
(`MCI_OPEN` with `MCI_OPEN_TYPE_ID`, device type 0x204 = MCI_DEVTYPE_CD_AUDIO),
then `MCI_SET` (time format -> TMSF) and `MCI_STATUS` (number of tracks).
It is stdcall (no `add esp` after `call edi`), so the shim pops 4 args.

Fix (Source/host/aoe_shims.c): `mciSendCommandA` answers the way a Windows box
without MCI devices would - `MCIERR_DEVICE_NOT_INSTALLED` (306) for MCI_OPEN,
`MCIERR_INVALID_DEVICE_ID` (257) for anything else. The driver's error path
(0x498AAD) returns 0 cleanly, so the game boots without media audio/MIDI.

Next stop was not a crash but a stall: after dsound the boot crawled in the
GDI font code - the main thread spent ~100% of its time in
`hle_font_file`'s `popen("fc-match ...")`, which forks a shell on every
call (see next entry).

## Resolved 2026-11-23: GDI font resolution stall + `sizeof` truncation (win32hle)

Two bugs in `refs/pcrecomp/runtime/win32hle/gdidc.c` (saved in
patches/pcrecomp-win32hle.patch):

1. **Font resolution forked a shell per lookup.** `hle_font_file` ran
   `fc-match` (popen = fork+exec of /bin/sh) on every cache miss, and the
   game's title screen probes hundreds of faces (font enumeration), so the
   boot crawled. MacPorts' fontconfig also answered with X11 fonts - here a
   Hiragino `.ttc` SDL_ttf could not use. Fix: a 128-entry (face, bold,
   italic) memo with round-robin eviction; on macOS the direct font dirs
   (`/System/Library/Fonts/Supplemental/` etc.) are consulted *before*
   fc-match, which is now a Linux-only last resort that must return a regular
   file (`access(R_OK)` also passes for directories).
2. **`sizeof path` on a `char *` parameter = 8.** Every `snprintf(path,
   sizeof path, ...)` in `hle_font_file_uncached` truncated its output to 7
   chars + NUL: "/System/Library/Fonts/Supplemental/Arial.ttf" became
   "/System", which then passed `access(R_OK)` (it is a readable directory!)
   and was handed to `TTF_OpenFont`. Fonts therefore never opened and every
   text call retried. Fixed by using the real buffer size (512).

With both fixed, zero font failures, and the SDL window shows the main menu.

## Current status 2026-11-23: MAIN MENU RENDERS (Step 1 done)

`build_boot.sh` + `run_boot.sh` reaches the Age of Empires II main menu: the
800x600x8 DirectDraw primary is presented in an SDL window with the full
medieval-market backdrop, Microsoft/Ensemble banner and button plaques
(screenshot captured). Mouse motion/clicks reach the game (the guest's
WM_MOUSEMOVE/WM_LBUTTONDOWN path lights up a menu plaque).

Known gap (next blocker): the menu button labels are not drawn - the wooden
plaques are empty. Likely the game's UI text path (GDI TextOutA/DrawTextA with
a CreateFontA face, or its own DRS bitmap font) still fails silently. Also
MCI music is muted because no platform media device is available. Step 2 (override mechanism,
pilot sub_465270) is next per docs/agent_plan.md.

## Resolved 2026-11-23: override mechanism (step 2, pilot sub_465270)

Lifted function definitions are now compiled weak: Scripts/build_boot.sh makes
a line-identical shadow copy of `Source/lifted/recomp_0*.c` in
`build/boot/lifted_w/` with `^void sub_` marked `__attribute__((weak))` and
compiles the copies (recomp_funcs.h is copied alongside). A strong
`sub_XXXXXXXX` in `Source/host/overrides.c` then wins at link time - the
dispatch table, the declarations and every direct `RECOMP_CALL` bind to it
(verified: the table's 0x00465270 entry points at the override, and the
binary's other 19153 lifted symbols stayed weak).

Pilot: `sub_00465270` - the DirectX version check (DirectPlayCreate ->
QueryInterface -> GetModuleHandle("dplayx") -> GetModuleFileName ->
GetFileVersionInfo* -> VerQueryValue("\\") -> version compare) - is replaced
by `RET(1, 0)`, and the DirectPlay + VERSION emulation is deleted from
`aoe_shims.c`. The boot reaches the main menu without them, headless.

An override runs inside the lifted model like a win32hle shim: g_esp points at
[ret][args...]; `RET(value, argc)` sets eax and pops `ret + argc*4` - for a
caller-pops original use `RET(value, 0)`. Guest registers are caller-saved
(RECOMP_REGS_OUT/IN around every call), so overrides may clobber them.

## Known issue: menu text not drawn

The main menu's button labels and the Single Player submenu's captions are
missing (empty plaques; one black caption bar). Graphics and layout are
correct, so the game's renderer works - the text path is next.

## Investigating 2026-11-23: menu text (labels not drawn)

The menu's button labels and the Single Player submenu's captions are empty.
Findings so far:

- The game's GDI text cluster (`0x45AFE0..0x45B1xx`, TribePopUpHelp::draw and
  friends) makes zero `TextOutA` calls during the menu (traced with
  `HLE_TEXTTRACE=1` in gdidc.c) - the menu text does not go through GDI.
- `basegame::setup_fonts` (`sub_41E760`, named via its assert string) ran
  during the boot and used GDI `GetTextMetricsA` - the GDI fonts the game
  creates measure fine; the menu just does not draw text with them.
- The game's own glyph renderer is `sub_45FED0` (called from the
  `pnl_btn::draw`/`pnl_txt` cluster): it blits glyph bitmaps from the game's
  font data (interfac.drs) into the primary with colour-key transparency.
  The menu art (SLPs from graphics.drs) renders correctly, so the DRS/SLP
  loader works; the failure is somewhere in the font-specific path (font
  data load, glyph cache `sub_460180`/`sub_460490`, or the keyed blit).

Next session: trace `sub_45FED0`'s data flow (which surface, which blit),
compare against a real screenshot of the menu. Note win32hle `g_TextOutA`
now supports 8-bit targets (pack/mix map colours through the DC's selected
palette or a DIB colour table) - needed for the help/popup text screens even
if the main menu does not use GDI text.

## 2026-11-23: readable-track structure (registry + dashboard + verify_one)

The promotion pipeline from docs/matching_plan.md Phase B now exists:

- `Scripts/decomp_dashboard.py` builds `data/function_states.json` (all
  19,140 functions: names, module, pipeline stage) and renders `MATCHING.md`
  (per-module counts + promotion targets).
- `Scripts/verify_one.py` verifies one reconstruction against the original
  bytes (unicorn, fuzzed inputs) — the step-4 gate of docs/decomp.md.
- Pilot: `sub_460F80` (glyph-buffer pixel offset, in the game's font-cache
  text path) promoted to readable C++ in `Source/gfx/`, 1300/1300 fuzzed
  cases green, registered `promoted/gfx`.

The menu-label investigation connects directly: sub_460F80's caller
(sub_462250) drives the glyph cache behind the game's own text renderer —
understanding that family is the next step for both the label bug and the
decompilation effort.

## Investigating 2026-11-23: menu text — the glyph pipeline runs, the ink is invisible

Traced the game's own text renderer end to end (calltrace of a headless
menu run, 82M entries sampled):

- The pipeline DOES run: `sub_460180` (glyph cache load) 49x, the glyph
  plotter `sub_461400` 12x, driven by `pnl_btn::draw` (sub_4AFAC0) via
  `sub_461130` -> `sub_461370`/`sub_461400` (clipped byte-plot into
  `this[+8]`, the locked surface buffer from `sub_45FD90`'s vtable+0x64
  lock), then `sub_45FEA0` (unlock) and `sub_4A0C60` (SelectClipRgn(NULL)
  + ValidateRect).
- No ddraw Blt/BltFast calls happen at all during the menu — the text is
  composited by direct pixel writes, not blits.
- Two frames 1.2 s apart during menu idle differ in ZERO pixels: the frame
  is static; the text was drawn once at panel setup.
- Pixel census of the black caption bar: dominated by palette index 10 =
  rgb(16,16,16) — near-black. The art palette is otherwise correct (the
  menu art colors are right), so index 10 is genuinely dark.

Working hypothesis: the label text IS drawn — with an ink palette index
that lands on a near-black entry (or the panel background is drawn over
it). Next: trace the ink color the game passes to the plotter
(`pnl_btn::draw2` sub_4AFAC0 -> the text color setup) and the font data
source (interfac.drs font SLPs loaded by `basegame::setup_fonts`,
sub_41E760). The glyph-plot family (sub_461130/1370/1400) is also the
next promotion target for the readable track — verifying them against
the original bytes will pin down the ink-index semantics.

## Resolved 2026-11-23: menu text renders (labels + copyright) — stale HLE objects

The labels were never missing from the *code*: `pnl_btn::draw2` (0x4AFAC0,
style 3 for the menu plaques) locks its text surface, gets an HDC through
`TDrawArea::GetDC` (0x45FE50), then `SetClipRgn`/`SelectObject`/`SetBkMode`/
`GetTextExtentPoint32A`/`TextOutA`/`SetTextColor` around 0x4AFD0F..0x4AFE8E.
`HLE_TEXTTRACE` showed zero TextOutA because **no gdidc shim ran at all** —
the running binary's win32hle objects were stale.

Root cause: `Scripts/build_boot.sh`'s per-file compile loop reads
`i1 i2 i3 src`, but the win32hle and `Source/host` lines emitted only two
include fields, so `src` was empty and those objects never rebuilt. Every
`.o` in `build/boot/` from `10:18` predated the 8-bit `g_TextOutA` patch
(in `patches/pcrecomp-win32hle.patch`): 8bpp TextOutA fell into the "not
drawn" branch, and `sf_GetDC`/`sf_Lock` had no working implementations in
the linked object. Fixed the script (third `-I` field on those lines) and
fixed a pre-existing compile error in the `HLE_BLITTRACE` print in ddraw.c.

Fresh rebuild result (headless, `--shots` every 2 s): the menu now shows
"Learn to Play", "History", "Single Player", "Multiplayer", "Map Editor",
"Options", "Exit" and the Microsoft/Ensemble copyright panel. The text path
is GDI on the 8-bit primary through `TDrawArea::GetDC` (DDRAW
IDirectDrawSurface::GetDC at vtable+0x44), not the glyph plotter.

A second latent regression surfaced with the honest rebuild: with the old
`aoe_shims.o` still containing retired DirectPlay shims the boot passed
0x437932; a fresh build hit `FATAL: unimplemented import dplayx.dll#2`.
Restored permissive dplayx ordinal shims (`dplayx.dll#1/#2/#4`): the boot
network-provider init calls DirectPlayEnumerateA (ord 2) with a callback,
which now completes with no providers; create/lobby return E_FAIL.

Build/trace additions: `--mem ADDR` + `--memtrig VA` (dump dwords at named
addresses on entry, used for vtable slots), and `HLE_TRACE_SURF` prints in
`sf_GetDC`/`sf_Lock` (env-gated).

Known gaps now: MCI music muted by design; no ddraw Blt happens in the menu
(text/art are direct pixel writes). Step 2 override pilot remains in place.

## Reached the running game: Random Map plays (2026-11-23, later)

After the menu text fix, driving the headless FIFO through the real UI path
now boots a match:

1. click Single Player (350,25) -> the no-profile dialog "New Player";
2. click the Name edit, type keys `T e s t`, click OK -> single-player menu
   (Campaigns / Random Map / Regicide / Death Match / ...);
3. click Random Map -> the map setup screen (Dark Age, Coastal, Small,
   Standard resources, 1 player + 2 computer);
4. click Start Game -> a live match: grass terrain, Town Center with four
   villagers, 200/200/100/200 resources, 3/5 population, Dark Age HUD.

Two blockers solved on the way:

- **Local install-media check (`sub_41F0C0`)**. A successful "New Player"
  then "Start Game" reached a platform media-validation dialog. The function
  asks `GetDriveTypeA` for a device type and compares a volume label; the HLE
  filesystem is a fixed disk, so validation failed. `Source/host/overrides.c`
  now treats the installed local layout as valid for this path (ret 4), and
  the dialog advances into the single-player menu.
- **`DrawTextExA`** was unimplemented (fatal from `sub_4B4030`); added to
  user32 HLE as DrawTextA + DTTOPSTRUCT args (6, stdcall), with DT_CALCRECT
  and the same fixed-pitch line box. The dialog and player name now draw.

- **Deflate decoder fault (`sub_005ED4F6`)** on Start Game: the game's x86
  coroutine inflater resumed with a lost state pointer (guest fault at
  0x8207). A lift cannot resume the stack-copy contract. `overrides.c` now
  replaces the decoder entry `sub_005ED91B` with host zlib raw-deflate
  behind the original 8-arg contract `(in, off, &in_len, out, off,
  &out_len, state, final)`: state is the guest 0xAD90 block, resume index
  +0xA958, 0=again / -1=end / -2=corrupt. Guest VAs are mapped via ADDR.
  The random-map load then ran to the match; no fault in the loader.

Headless driver now also accepts `rdown / rup / rclick x y` (WM_RBUTTON
0x204/0x205), so unit orders are scriptable. A click on the villager then a
right-click on a tree selects it and issues the gather order.

Still open inside the match: the minimap diamond is black (no minimap
terrain/render yet), and the mouse pointer is not composited under
`--headless`. MCI music stays muted; the media query is answered for the installed local layout.

## In-match verification and driver fixes (2026-11-23, evening)

The random-map match was driven further through the headless FIFO and the
core loop holds up:

- **Selection**: clicking the Town Center selects it (blue selection ring,
  unit panel shows "Town Center", 2400/2400 HP, owner "test"); the command
  panel appears on the left with villager/research buttons.
- **Training**: clicking the Create Villager button costs 50 food
  (200 -> 150) and shows a progress bar ("Creating: 51% Villager"). The
  queue advances over successive frames.
- **Gathering**: selecting a villager and right-clicking a tree issues the
  gather order; the unit walks and wood rises (200 -> 250 over ~8 s), so
  orders and the simulation tick run.
- **Keyboard**: a *held* right-arrow scrolls the viewport (`kdown`/`kup`
  added to the driver); the view moves and stops at the map edge, where
  terrain is black (expected map bound, not a render fault). An instant
  `key` down+up did not scroll because the game polls the key state between
  ticks, which is why the hold commands were added.
- **Blits traced**: `HLE_BLITTRACE` now also logs `Blt` (not only BltFast).
  Each frame composites its 800x600 UI/terrain surface over the primary,
  then copies a small 24x32 rect back and forth (a software cursor pair).
  The HUD and command-panel art arrive by these `Blt` calls.

Still black: the diamond minimap in the lower-right HUD panel. A pixel
census of its 531..705 x 514..590 region in the 800x600 UI surface finds
only the frame/button colors (indices 11/12/13 gray, 128 dark; 173/180/246
icon tones) and 2168..2273 non-zero pixels (two alternating counts from the
button animation); the map interior stays palette index 0 and no terrain
colors ever appear. No `Blt` covers the minimap region; the HUD reaches the
primary by a full-frame `Blt`. The SWGB recomp screenshot shows the same
black diamond, so this looks like the engine's explored-map/minimap surface
path rather than a DDraw compositing failure; it stays a known gap. The
`[mini]` line under `HLE_TRACE_SURF` reports the region's nonzero count and
hash on each UI unlock.

All Visible test: with Reveal Map set to `All Visible`, the minimap is still
black. `--firsthit 0x443900 0x444400` shows `diam_map::draw` (`0x444370`)
runs every UI frame but its subdraws (`0x444540` clear, `0x444740` explored,
`0x4446D0` all tiles) never run. `--watch 0x444370 --watchspan 0 0x180` shows
why: the live object has `[ecx+0x100]=0` and `[ecx+0x12c]=[ecx+0x130]=0`.
`0x444370` returns at `0x4444d6` before any tile drawing. `[ecx+0xf8]` is set
by a map-assignment call to `0x443D90` during screen init, but that call first
checks `[ecx+0x12c]`; it is zero, so `0x443D90` sets `+0xf8` and bails without
setting `+0x100`. The tile-buffer setup `0x443B50` (called with
`0x654390`=`"map800.bmp"` and id `0xC4EB`) is entered after `0x443D90` at boot,
but it does not leave `+0x12c` set; its `4A9AE0 -> 4A9D80 -> 4BE550/4464E0`
bitmap-load path is where it stops. Therefore this is not fog state and not a
compositing gap: the minimap tile buffer is never populated. `HLE_GBLITTRACE`
also records no `BitBlt`/`StretchBlt` calls anywhere in the live match, so
DDraw/GDI blit plumbing is not the cause.

### Root cause: no C: drive for the DRS decompression temp file (2026-11-24)

The minimap failure is a host mapping gap, not the minimap object. The DRS
resource loader `0x4BE550` finds the `anib` entry in `interfac.drs` through
`0x4BE490`/`0x4BE3B0`, then decompresses it through a Windows temporary file:
`GetTempPathA` returns `C:\\WINDOWS\\TEMP\\`, `GetTempFileNameA` makes
`tem0001.TMP`, and `0x5FCE01`/`0x5FFC19` write the inflated entry there before
`0x4A9D80` builds the bitmap. win32hle maps `Z:` by default but no `C:` drive,
so `hle_host_path` returned no path and every temp write failed
(`CreateFileA "C:\\WINDOWS\\TEMP\\tem0001.TMP" -> ... No such file`). The
loader returned zero and `0x4A9D80` fell back to `OpenFile "map800.bmp"`, which
is not a loose CD file and not a PE resource either. That fallback is the only
reason `map800.bmp` appeared in the file trace.

Fix in `aoe_host.c`: after registration, map `C:` to the current install root
and create its `WINDOWS/TEMP` directory. Re-run: temp files `tem0001` through
`tem0004` open, no `map800.bmp` probe remains, and the minimap crop now contains
terrain palette colors (2389 non-black pixels, reds/browns) instead of only the
frame/button palette. The map interior renders.


Readable track: byte-exact `sub_560660`/`sub_560680`/`sub_5606A0` (word-type
checks), `sub_5E68A0` (index compare), `sub_52A440` (forwarder), plus a WIP
`sub_4B4550` (tail-call form); now 179/179 MATCH, 22 WIP.

### Cursor: invisible in menus, flickering in a match (2026-11-24)

Menus: `mouseptr` (`0x48B4F0`) uses the Windows cursor there,
`SetCursor(LoadCursorA(NULL, IDC_ARROW))`; the host never set
`hle_screen_cursor_hook`, so screen.c kept the window's cursor hidden. Fix in
`aoe_host.c`: show it while the game has a cursor set and `ShowCursor` allows.
In a match the game calls `SetCursor(NULL)` and draws its own.

Match: `mouseptr::draw` (`0x48B000`) asks the back buffer for its clipper
before drawing the sprite and only accepts `DD_OK` or
`DDERR_NOCLIPPERATTACHED` (`0x88760238`). win32hle defined that error as
`0x88760082`, so the game returned early after the save-under blits and never
drew the cursor. Fixed in the saved win32hle patch; the cursor is now in every frame.

### Call phases: boot -> menu -> match (2026-11-25)

New host flag `--phases FILE`: each lifted entry bumps a per-VA counter, and the
driver command `mark LABEL` writes the functions called since the previous mark
and resets. A headless run marked each step: main menu up, 6 s menu idle, Single
Player, Random Map, Start Game until the match was live, 6 s in the match. The
raw data is `data/call_phases.tsv`. `Scripts/phase_report.py` turns it into
`docs/call_phases/` (one file per phase). Of the 2976 distinct functions, 815 run from boot to the
main menu and 2161 more from the menu into the match, 1955 of those after Start
Game. Menu idle and match idle add no new functions. Alias stubs are counted
under the function they forward to, and strong host overrides (`overrides.c`)
do not appear.
