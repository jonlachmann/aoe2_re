# Matched-only build status

Goal: a standalone binary that boots to the menu from byte-verified matched C++
bodies, not from `Source/lifted` recompilation.

`Scripts/build_boot.sh` (read-only, not edited) links only
`lifted_w/recomp_0*.c`, `recomp_dispatch.c` and `Source/host/*.c`. It contains no
matched TU, so `build/boot/aoe_boot` boots entirely from lifted code.

## New separate path: `Scripts/build_matched.sh`

Compiles every TU that owns a matched body (from `data/function_map.json`) with
the host compiler into `build/matched/*.o`, then links the objects that have no
undefined symbols together with `Scripts/matched_probe.cpp` into a native
executable and runs it.

Evidence (current run):

- matched/WIP-owner TUs compiled: 164 (every TU in `data/function_map.json` that owns a matched or WIP body)
- natively compiled by the host compiler: 164, 0 failed
- asm in matched TUs: 0 (see conversion note below)
- objects with no undefined symbols (self-contained): 74; link exit 0,
  `probe: 0 failures`
- stage 2 — 236 `g_*` guest globals generated as opaque storage from the
  objects' own undefined lists; 84 objects link with those globals and run
  `probe: 0 failures`
- stage 3 — portable guest-VA access layer: `Source/matched_mem.h` defines
  `ADDR(va)`, a plain cast under VC6 (byte-exact codegen unchanged) and a guest
  image base offset under `-DMATCHED_NATIVE`. `Scripts/matched_probe_va.cpp`
  maps a host guest image, stores guest VA 0x1000 in `g_6645c4`, and
  `M_4BDE70` reads the short at +0x424 through ADDR: `va probe: 0 failures`

The probe exercises two recovered bodies on host-allocated instances:
`C_cluster_405790::Init_405790` (writes `+0x00` vtbl, `+0x04` arg, `+0x08` zero)
and `C_cluster_40F0C0::Check_40F4B0` (`+0xEA4 == 0x32`).

## Asm removal wave

The 11 TUs that previously failed to compile contained `__declspec(naked)` /
`__asm` bodies. All of them were rewritten as C++:

- eight global-pointer tail-jump stubs (`5ECE44`, `5ECE4A`, `5ED9D6`, `5ED9E8`,
  `5ECE5C`, `5ED9F4`, `5ED9FA`) and their five owning TUs reproduce the original
  `jmp dword ptr [g]` exactly from a plain C++ call — these stayed byte-exact
  `MATCH_FUNC`.
- twelve hand-written asm bodies (`5FCA45`, `5FC8D4`, `5F9AA0`, `5F9A20`,
  `5F9D00`, `5FCDE1`, `5F9EF0`, `6026DB`, `5F9750`, `4BD560`, `4BDE70`,
  `4CD410`) were rewritten with equivalent C++ semantics but VC6 C++ codegen
  does not reproduce the hand-written register scheduling, so they are now
  `WIP_FUNC`. This intentionally reduced `[N/M]` from 1774 to 1762 matched while
  removing every asm marker; the recovered class/field layout is retained.
- `0x5FC8D4`'s `fnclex` has no C++ equivalent and was dropped (WIP body).

## Remaining gaps toward booting to the menu

1. 84 of 164 objects link (74 self-contained + 10 globals-only); the remaining
   80 reference function symbols (628 distinct) that are unmatched helpers,
   `_F_*` game functions, Win32 imports or member hook stubs, so they still need
   wrappers or matches.
2. Guest memory: most matched bodies still cast guest VAs in fields/globals
   directly. `ADDR` is proven on one body but not yet applied across the bodies
   or paired with an initialized guest image at boot.
3. Guest ABI: matched-to-matched calls are consistent because all bodies are
   compiled by the host compiler; the gap is only at boundaries to unmatched
   lifted code/external imports, which need guest-ABI wrappers.
4. Coverage: phase docs still show 416/815 phase-1 matched (289 left, 23 WIP,
   110 CRT/library), so even a wired build would boot lifted, not matched, code.
5. (Done) Asm-based "matches" were rewritten as C++; the tree now has zero
   `__asm` in matched bodies and all 162 matched TUs compile natively.

## Reproduce

```
./Scripts/build_matched.sh
# matched TUs compiled: ... ok, ... failed
# self-contained objects: ...
# probe: 0 failures
# native matched probe: OK
```
