# Entry point & boot sequence analysis

Reference executable: supplied locally via `AOE_BIN` (image base `0x400000`; not distributed by this repository).

## CRT bootstrap

| Stage | Address | What happens |
|---|---|---|
| PE entry point | `0x600281` (`start`) | MSVC 6 CRT startup: `GetVersion`, `_heap_init`, `_ioinit`, `GetCommandLineA`, `_cinit` |
| `__cinit` | `0x5fe212` | Calls pre-user init table `0x64D040..0x64D054` (CRT internals), then the **user constructor table** `0x64D004..0x64D038` |
| User ctors | `0x64D004..0x64D038` | 14 C++ static initializers (zero-fill of float tables, sin/cos tables at `0x65329C`, a large game-state global `dword_66EA48` with vtable `off_621F64`, cursor/palette setup) |
| `WinMain` | `0x47ae20` | short entry stub; game-init continuation is at `0x47ae8e` — see below |

## WinMain entry continuation

`_WinMain@16` (`0x47ae20`, size `0x3d`) performs `timeBeginPeriod(1)`,
`timeGetTime()` stored to `dword_661C14` (a startup timestamp), then exits.
The game-init body continues at `0x47ae8e` with the `0x1B88` stack frame
prepared by the CRT startup path.

Evidence that `0x47ae8e` is the main initialization body:

- `0x47ae5f` — `push "language.dll"` (local installation resource)
- `0x47ae90` — builds the window title `"Age of Empires II"`,
  version `"00.14.14.0914"`, `tr_wrld.txt`, `"data\\empires2.dat"`,
  registry key `Software\Microsoft\Microsoft Games\Age of Empires\2.0`,
  `"AppIcon"`, `"palette"`, `"mcursors"`, `"AOE2"` window class
- `0x47b066+` — reads `hInstance`/`lpCmdLine`/`nShowCmd` from
  `[esp+1BA8h..1BB4h]` — the original WinMain stack frame
- Registry string `"Software\...\2.0"` xref `0x47af4e` sits inside this code

For the reconstruction, model the boot flow as
`start → CRT → ctors → game init at 0x47ae8e...`.

## Real WinMain body — init sequence (from `0x47ae8e`)

```
0x47ae8e  game WinMain body (stack frame 0x1B88 bytes)
  ├─ sub_47B620("language.dll")       load resource DLL, exit path if fail
  ├─ (assembles config struct: title, version, DAT path, registry key, icon, cursors)
  ├─ sub_5B0EC0                       checked before MessageBoxA error path @0x47b5df
  ├─ sub_473BF0                       GlobalFree(hMem) cleanup helper
  ├─ sub_47C120                       exit(22304) on error path
  ├─ LoadLibraryA/GetProcAddress x2   (0x47b634, 0x47b673 — DLL feature probes)
  ├─ sub_473AE0 x2                    (init helpers)
  ├─ sub_4BE980                       file/line reader
  ├─ sub_480360                       .shp shape table (32 entries, stride 416)
  ├─ sub_480750                       .shp table (16 entries, stride 1440)
  ├─ sub_480430 / sub_480820          .shp file readers (FILE*, word streams)
  ├─ sub_4813D0                       called ~30x (per-resource init, index in [esi+8EAEh..])
  ├─ sub_483010                       frees 17 slots + string table
  └─ ends around 0x47c117 (retn) / SEH-wrapped game-object methods after
```

## The application framework (engine hub)

- **Window class registration**: `sub_41D5D0` (vtable `off_61DF78`+0x7C)
  → `RegisterClassA`, `lpfnWndProc = sub_41D670`
- **WndProc trampoline**: `sub_41D670` forwards everything to
  `dword_6645C4` (the global app object) vtable+8 → **`sub_41FAC0` = real WndProc**
- **Message loop**: `sub_41CF70` (vtable+4) — classic
  `GetMessageA`/`PeekMessageA` pump; when idle (no messages, `byte_664544`
  game-active flag) calls **vtable+208 → `sub_420450` = the frame tick**
- **DirectDraw init**: `sub_45DF20` → `DirectDrawCreate`, mode probing via
  `CreateICA` + `GetDeviceCaps` (supports 800x600/1024x768/1280+ flags)

### App object vtable `off_61DF78` (partial map)

| Offset | Function | Role |
|---|---|---|
| +0x04 | `sub_41CF70` | message loop |
| +0x08 | `sub_41FAC0` | WndProc (WM_MOUSEMOVE 0x200, WM_TIMER 0x113→tick, WM_SYSCOMMAND 0x112, 0x212, 0x311, 785, 783 dispatch, plus vtable+72 hook via `sub_49F620(&unk_66EA48)` game-object) |
| +0xD0 (208) | `sub_420450` | **frame tick**: timing (`timeGetTime`), `sub_45F8A0` throttled at 250ms, `sub_5C6880` (msg 275 timer proc), `sub_5214E0`, `sub_4217C0`/`sub_427120` (timed block), vtable+332/+336 hooks |
| +0x7C | `sub_41D5D0` | RegisterClass |

`sub_41C800(id, ms)` — profiler/timer log (called with ids 14/15/16).

## Next steps

1. Decompile `sub_41D6A0` (vtable+0x80) and the WndProc handler helpers
   (vtable+212/244/248/256/260) to map the UI event flow.
2. Follow `sub_420450` → `sub_427120` (game update) → the simulation.
3. Trace `unk_66EA48` game object (vtable `off_621F64`, vtable+72 hook in
   WndProc, vtable+76 call in tick) — likely the screen/UI manager.
4. Locate `CreateWindowExA` caller for the main window handle → `a1[10]`.
5. Full function inventory: `rea decompile-all` → `docs/pseudocode/`.

## Tool reminders

- rea pipeline: `rea decompile "$AOE_BIN" <addr> --json`
- Direct idalib (fast exploration, shared DB next to the reference image):
  run from a local IDA work directory with `IDADIR` pointing to your licensed
  IDA installation's native-library directory.
- Set `AOE_BIN` to your local reference image; analysis databases are kept outside the repository.
