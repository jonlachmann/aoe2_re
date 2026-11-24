# Agent plan: from "boots on win32hle" to "platform layer on SDL3"

Written 2026-11-23. Work top to bottom; each step says when it is done.
Status of the boot lives in `docs/bringup_log.md` (newest section last).

## Where we are

- The lifted game (`Source/lifted/`, 1.39M lines) runs on win32hle through
  CRT init, language init and the DirectX check, sets 800x600x8, creates the
  primary surface and opens dsound. Next stop: `mciSendCommandA` (0x4988E0).
- `Scripts/build_boot.sh` / `Scripts/run_boot.sh` build and run it.
- `docs/platform_imports.md` maps every Win32 import to its caller functions.
- win32hle (`refs/pcrecomp/runtime/win32hle`, git-ignored) already sits on
  SDL: it links `sdl2-compat`, which runs on SDL3. Local edits to it are saved
  in `patches/pcrecomp-win32hle.patch` - refresh that file whenever you edit
  win32hle.

## The strategy in one paragraph

Don't port DirectX/DirectPlay to SDL3 one API call at a time. Genie already
wraps each platform API in a few engine classes (draw system, sound driver,
music, communications handler, registry and config). Find those classes,
rebuild them in the readable track, and swap them into the running lifted game
in place of the lifted versions. Then give them an SDL3 backend. The lifted
game stays the oracle the whole way: every replacement is checked against
the lifted function it replaces before the original is retired.

## Step 1 - keep the oracle booting (until the main menu renders)

Loop: `build_boot.sh` -> `run_boot.sh` -> read the FATAL / fault -> fix -> log it.

- A missing import: add a shim to `Source/host/aoe_shims.c`. **Check the
  caller's stack cleanup first** (`add esp,4n` after the call = cdecl =
  `RET(v, 0)`). A wrong argc corrupts esp silently and faults far away; that
  is how the EBUEula bug cost a day.
- Answer the way a Windows box without the feature would (e.g. MCI: no
  audio device -> `MCIERR_DEVICE_NOT_INSTALLED`) unless the game then refuses
  to run. If it refuses, emulate the minimum, as was done for DirectPlay.
- A guest fault: line up the esp ring with the entry trace (see the
  2026-11-23 bring-up entry). `esp=` in the fault dump is the value synced at
  function boundaries, not the live esp.
- One `## Resolved` / `## Current blocker` entry in bringup_log.md per stop.

Done when: the main menu draws (`aoe2-screen.png`-style capture) and a mouse
click reaches the game. Stretch: a skirmish starts.

## Step 2 - an override mechanism for lifted functions

Today every lifted function is a strong `void sub_XXXXXXXX(void)` and callers
use it by name, so nothing can replace one. Add a way:

- Preferred: mark lifted definitions weak (`__attribute__((weak))`; see the
  `RECOMP_WEAK` macro already in `recomp_types.h`). Either regenerate with
  the lifter (`refs/pcrecomp/tools/lift`) or rewrite the `^void sub_` lines
  in a build step. A strong `sub_XXXXXXXX` in `Source/host/` or a module
  directory then wins at link time. Check that Mach-O ld honors it and that
  the dispatch table (`recomp_dispatch.c`, used for indirect calls) picks up
  the override too.
- An override uses the guest ABI, like a shim: args from `MEM32(esp+4..)`,
  result in `eax`, and it pops only what the original's `ret n` popped.

Pilot: override `sub_465270` (the DirectX version check) with a function
that returns 1, and delete the DirectPlay/VERSION emulation from
`aoe_shims.c`. Done when the boot gets as far as before without them.

## Step 3 - map the engine's platform classes -> docs/platform_layer.md

Start from the creation sites in `docs/platform_imports.md` and walk up to
the owning class (constructor, vtable, fields, callers):

| Seam | Start here |
|---|---|
| video | `sub_45DF20`, `sub_45E4C0` (DirectDrawCreate); `diam_map::draw` family in `docs/symbol_map.md` |
| audio | `sub_520170` (DirectSoundCreate) |
| music / media | `0x4988E0` (mciSendCommandA) and other winmm `mci*` callers |
| net | `sub_465270`, `sub_42E650`, `sub_437AD0`, `sub_4378D0`, `sub_42E3E0`, `sub_433890` (dplayx); `sub_423670`.. (wsock32) |
| input / window | WndProc `sub_41FAC0`, RegisterClass `sub_41D5D0`, imm32 callers |
| config | advapi32 `Reg*` callers (`sub_4BDE90`, `sub_4EB4B0`, ...) |
| timing | winmm `timeGetTime` (487 callers: a free function, not a class) |

Name classes with the PS2 decomp's vocabulary (`refs/aoe2-decomp`) and
SWGB's lifted code (`refs/swgb-recomp`), as `docs/cross_references.md`
describes. For each class record its vtable, method list (address, args,
`ret n`), object size, and which game code calls it.

Done when every row above has a class (or "free functions") with its full
method list.

## Step 4 - rebuild the platform classes in the readable track

Per class, in `Source/<module>/` (gfx, sound, music, net, input, config):
reconstruct the methods as C/C++ with the original interface, verify each
against the lifted function (difftest harness, `Scripts/diffharness.py`),
then switch it in with the step-2 override. Order: config -> timing ->
music -> sound -> input -> gfx -> net (cheapest and most isolated first).

Done per class when the boot (and later a skirmish) behaves the same with
the override in as with the lifted original.

## Step 5 - SDL3 backends below the rebuilt classes

Put a small `Source/platform/` interface under the rebuilt classes with two
backends: a Win32/win32hle one (original behavior, used for diffing) and an
SDL3 one. SDL3 mapping:

- config: registry -> an ini/json file under `SDL_GetPrefPath`
- timing: `SDL_GetTicks`/`SDL_GetPerformanceCounter`
- gfx: an 8-bit surface + palette -> `SDL_Texture` (streaming); page flips -> present
- input: `SDL_Event` -> the messages WndProc used to get; IME -> `SDL_StartTextInput`
- sound: DirectSound buffers -> `SDL_AudioStream` per voice, or one mixer
- music: MCI media tracks -> audio files played through SDL3 audio
- AVI intros (msvfw32): last; skip with a flag until then
- net: DirectPlay -> SDL3_net (or plain sockets). Compatibility with the
  original's wire protocol is optional; decide when you get there.

Done when the game reaches the main menu with no DirectX/DirectPlay/winmm
shim in the call path.

## Rules carried over

- Never commit proprietary assets or binaries; keep local reference files outside the repository (see README).
- After each finished step: update `bringup_log.md` / this file, and commit
  with a message that says what now works.
