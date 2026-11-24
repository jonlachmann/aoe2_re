# First matched functions (differential-verified)

Byte-exact matching needs the original MSVC 6 compiler; until that toolchain
is set up, functions here are verified with **differential testing**: the
original x86 bytes and the compiled reconstruction are emulated under unicorn
(32-bit x86) with identical fuzzed inputs, comparing return value, callee
memory writes, and final memory state.

Harness: `Scripts/fnmatch.py` (original bytes extracted from
the local reference executable (`AOE_BIN`); reconstruction compiled with `i686-w64-mingw32-g++`
and loaded as raw x86). This is the same verification standard used for the
rea dx-ball showcase reconstruction.

## Verified functions

### 1. `sub_40B600` — object position equality (`Source/engine/geom_compare.cpp`)

`BOOL __cdecl f(const void* a, const void* b)` — compares world positions
(floats at `obj+0x50`, `obj+0x54`).

- 1100 random finite cases + 100 equal cases: **0 mismatches**
- 36 NaN/Inf edge cases: **0 mismatches**
- Measured quirk: the original tests only the x87 C3 flag after `fcomp`, so
  an *unordered* comparison (any NaN operand) behaves as **equal** —
  `f(NaN, x) == 1`. Reproduced explicitly in the reconstruction.
- `-0.0 == 0.0` → 1 (same as IEEE).

### 2. `sub_40A3E0` — countdown field decrement (`Source/engine/countdown_field.cpp`)

`int __thiscall f(Obj* this)` — decrements the counter at `this+0x88`.

- 19 cases (range −5..9, INT_MAX, INT_MIN, ±1): **0 mismatches**
- Subtle semantics captured: the decremented value is **stored unclamped
  first**, then overwritten with 0 only if negative; the **return value is the
  raw decremented value** (can be negative while the stored field is 0).
  A naive `if (--v < 0) v = 0; return v;` reconstruction returns the clamped
  value and diverges — the differential harness caught the intermediate write
  trace, and the reconstruction documents the contract.

## Running

```bash
./venv/bin/python Scripts/fnmatch.py
```

## Next

- More leaf functions from the pure-candidate pool (983 small no-call
  functions identified; float-math ones are ideal for this harness).
- Byte-exact verification once an MSVC 6 toolchain is available (wine is
  installed; the compiler itself must come from a licensed source).
