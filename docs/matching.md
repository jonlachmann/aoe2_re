# Byte-exact matching (the gta2_re workflow)

The readable track's bar is **byte-identical machine code**: the C++ in
`Source/<module>/` compiled with the real MSVC 6 compiler must produce the same
bytes as the user-supplied local reference executable (`AOE_BIN`). Differential testing (`verify_one.py`) can
pass wrong code: with random object fields nearly every case takes an early
clip-return, so the interesting path never runs. The first "verified"
`sub_461370` wrote to the wrong row and still went 281/281 green. A byte
match leaves no room for that.

The long-running class-first procedure, state layers, layout-refinement rules,
and legacy-staging exit path are in **`docs/reconstruction_loop.md`**. Read it
before starting a loop session; this doc covers compiler and matching mechanics.

## Toolchain

- VC6 `cl.exe` 12.00.8804 (SP5) under wine (`/opt/homebrew/bin/wine`, 9.0), taken from
  gta2_re's `gta2_re_compile_tools`. `Scripts/match.py` looks at `$VC6_ROOT`,
  else `refs/gta2_re_compile_tools` (git-ignored; clone it with
  `git clone https://github.com/CriminalRETeam/gta2_re_compile_tools refs/gta2_re_compile_tools`).
- The original's rich header says C++ 12.00.**8447** (SP3). No difference has
  shown up so far. Suspect it only for a near miss that nothing else explains.
- Flags: `/O2 /Gy`. Measured: the first four functions matched on the first compile.
- One cl run per directory takes about 6 s, nearly all of it wine startup.

## Markers (`Source/Function.hpp`)

```cpp
#include "Function.hpp"

MATCH_FUNC(0x461370)                 // byte-exact; match.py fails the run if it breaks
void TDrawArea::HLine_461370(int x, int y, int len, int color) { ... }

WIP_FUNC(0x4613F8)                   // written, not matching yet; diffed, never fails
```

- The function's name **ends in `_<ADDR>`** (gta2_re's `Name_ADDRESS`). That's how
  match.py finds its symbol in the object file.
- One TU per class/subsystem (`Source/gfx/draw_area.cpp` holds `TDrawArea`),
  functions in address order. Put a struct's fields where the asm says they are, with
  the offset in a comment, and use real names once a class is identified.
- Promote `WIP_FUNC` to `MATCH_FUNC` only when match.py says OK. match.py lists the WIPs
  that started matching.

## The loop (one function at a time)

```bash
./venv/bin/python Scripts/match.py --next 20          # small unmarked candidates (fewest calls, smallest first)
./venv/bin/python Scripts/match.py --target 0x461370  # original asm, callees named + sized from the catalog
# write it in Source/<module>/<class>.cpp under WIP_FUNC(0x...)
./venv/bin/python Scripts/match.py Source/gfx/draw_area.cpp   # compile that TU, side-by-side diff of every miss
# iterate; when OK -> MATCH_FUNC, then:
./venv/bin/python Scripts/match.py                    # every marked TU: [N/M] MATCH_FUNCs OK, exit 1 if one broke
./venv/bin/python Scripts/decomp_dashboard.py         # refresh MATCHING.md / function_states.json
git commit                                            # one function or one class per commit
```

Picking targets: `--next` is the cold start. After that, grow from what's
matched: the callers and callees of a matched function share its class and
struct, so each match makes the next one cheaper. Methods of one class sit
next to each other in the binary, so walk the addresses around a match.
The lifted C (`Source/lifted/recomp_00XX.c`, `sub_00XXXXXX`) and
`rea decompile` are the readable starting points.

**The number to protect is N in `[N/M]`.** Don't break a `MATCH_FUNC`. The
exception: a shared struct change that breaks one but makes more match, so N
goes up. Say so in the commit message.

## What the check does and doesn't see

- It compares the function's whole `/Gy` COMDAT section against the original,
  for exactly the catalog's size (`data/disasm32_catalog.json`). It ignores VC6's
  trailing `nop` padding to 16 bytes.
- It masks relocated fields: call targets, global addresses, jump tables. A call
  to the **wrong** function with the right shape still passes. Check callees
  against `--target`'s annotations by eye.
- A failed compile deletes the stale object, so the run goes red, never stale green.

## VC6 quirks found here

Read the public gta2_re repository's matching-quirks notes first. It's the same compiler, with
months of patterns (branch order, signedness, inlining budget, x87
scheduling). AoE2-specific findings go below:

- **The original calls `memset`, not the intrinsic.** `/O2` implies `/Oi`, which would
  expand it inline. `Function.hpp` has `#pragma function(memset)`. Add other CRT
  routines there when one shows up as a `call` in the original (measured:
  `sub_461370` → `0x5FE3A0`).
- **A garbage eax means `void`.** If an early-out path leaves whatever was in eax,
  the function returns nothing, and the eax on the main path is a callee's leftover
  (`sub_461370`: memset's dst). A reconstruction that returns 0 there gets an extra `xor eax,eax`.
- **x87 `==` tests only C3** (`fnstsw ax; test ah,40h`), so a NaN compares equal.
  A plain `a == b` in VC6 produces exactly that (`sub_40B600`).
- **EH frames need `/GX` — it's per-TU, not per-function.** `TDrawArea::SetClipBounds_460740`
  has the fs:[0] prologue, EH state var (`0 -> -1` around the ctor) and unwind funclets
  (handler 0x609F3B, FuncInfo 0x644F48, unwindMap0 = free) from `new TClipSpan`. With
  `/O2 /Gy` alone VC6 emits none of it (the function shortens by 54 bytes). Adding `/GX`
  made the frame appear and broke none of the TU's 10 existing matches.
- **The full SP3 VC98 tree (c2.dll 12.00.8447) compiles a TU identically to SP5** here.
  `VC6_ROOT=refs/vc6sp3` gave byte-identical output for every function in draw_area.cpp,
  including the two register-rotation WIPs. Don't spend a recompile on the rich-header
  version unless a near miss has no other explanation.
- **A register-rotation phase can be intrinsic to a function body, not the neighbours.**
  `SetClipBounds_460740` (310/310 bytes) and `FillRect_461490` differ only in which free
  register VC6 picks for argument preloads/first temporaries (e.g. original first temp in
  eax vs ours ecx; FillRect x0 in ebx vs ours ebp). Neither operand order, loop form
  (for/while/do-while/++y), nested ifs, local pointer copies, source order of definitions
  nor `/GX` moves the phase. Compiling the function in an isolated one-function TU gives
  the same miss, so it isn't inherited compiler state from a preceding function either.
  Park it and record the exact register pairs rather than hunting.
- **`push <reloc>` vs `push 0` can be a false diff.** For `SetClipBounds_460740`'s EH
  handler push the original's operand is a relocation and ours is masked, so the diff
  prints `push <reloc>` on the left and `push 0` on the right at offset 0x8; the bytes are
  equal under the mask. Read the mask before believing that line.

### Lessons from the WIP sweep (26 WIPs → MATCH)

- **Read the diff the right way round: left = original, right = ours.** Several WIPs
  had been "fixed" toward the wrong column.
- **A wrong `ret N` or field offset is a signature/layout bug, not codegen.** `41AAC0`
  ends in `ret 0xc`, so it takes three args (it uses one); its list node is
  `{obj, ?, next}` with next at +8. Check `ret N` and the offsets first, every time.
- **`add ecx, OFF` / `lea eax, [ecx+OFF]` then small displacements usually means a
  struct-typed value, not pointer arithmetic.** VC6 folds `(int*)((char*)this + OFF)`
  back into `[ecx+OFF]`. The base register comes from a struct copy:
  - `407CB0`/`407D00`: return a 3-int struct **by value** (hidden return pointer in
    eax, copy via edx/esi → `push esi; mov edx, eax`).
  - `42F0B0`: the four "int" args are one 16-byte struct **passed by value**;
    the body is `rect_12dc = r;`.
- **`mov eax, ecx` at entry + `ret` with eax == this → the function returns `this`.**
  `5D0370`/`595DF0` (vtable written as a literal) are inlined-ctor shapes: declare
  them `S* Init(...)` and `return this;`.
- **`mov eax, ecx; mov ecx, [eax+OFF]; ... call` is a thiscall on a member pointer**,
  not a stdcall free function (`4213D0`, `5B5C50`: `field_1b0->M(buf_924, 0xb0)`).
- **CRT code (≈0x5FE000+) is size-optimized.** `sahf`/`jb`, `push 1; pop eax` and
  `movzx` where /O2 gives `test ah,..`, `mov eax,1` and `xor`+`mov cl` mean
  `#pragma optimize("s", on)` at the top of the TU (`600FB9`, `5FF5E6` = `_mbsinc`).
- **Unsigned compare: `mov eax,K; cmp eax,x; sbb eax,eax; neg eax`** is
  `unsigned x > K`. `xor eax,eax; cmp; setg al` is the signed version (`42F620`).
- **`mov al, 1` vs `mov eax, 1` is the return type** (`bool` vs `int`, `487740`).
  The `class S487740` there also had field_8 at +0xc; real fields catch that.
- **A list walk that starts at `this` = the object is the head node.** `4A6A30`/`487710`:
  `p = this; while (p->next) p = p->next;` gives the original's register pattern and
  tail duplication, and none of the `n = head; do {...}` variants do.
- **Tail-duplicated compares come from an inlined getter**: `52AE20` is
  `int Value() { if (!f24) return 0; return f24->f4; }` +
  `if (Value() < x) return true; return false;`.
- **`push 1` / `push 0` in two arms before one call = two call sites that VC6
  cross-jumped** (`45FD90`). One call with a 0/1 argument gives `setne`.
- **`fld [mem]; fadd [g]` vs `fld [g]; fadd [mem]`: route through a local**
  (`float t = c->f4; t += g; c->f4 = t;`, `544FD0`).
- **A surviving duplicate store + load/inc/store instead of `inc [mem]`** was
  reproduced with a `volatile` field (`4A6930`). Treat it as a working hypothesis.
- **Natural code first.** `423A70`, `411900`, `465BB0`, `4BD5B0`, `5BE970`, `474400`,
  `42AF60`, `461C70` matched once they were rewritten with real fields/arrays and plain
  loops or `&&`. The `int zero = 0;` temporaries, manual strides and odd store orders
  had been chasing register choices that real types produce on their own.
- Experiment loop that stays out of other agents' way: copy `Source/` + `Scripts/` to a
  scratch dir (symlink local reference inputs: `reference/ data/ refs/`), write each variant as its own one-function TU
  in one directory (unique class names), and run match.py on all of them, which is one
  wine start. Keep the scratch path short or batch the TUs: one `cl` command line for
  ~300 files under a long path silently produces no objects.

Still WIP after the sweep: `43A420` (base-pointer stores, not reproduced by inline
ctor/Init/explicit ctor/return &t), `433E50` (dword load then `shr al`), `4238D0`
(explicit `test` after `add`), `4A6A90` (field loaded before the `v == 1` branch),
`460EC0`, `460740`, `461490` (see above).
