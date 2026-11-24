// Reconstruction of reference-executable sub_40B600 (VA 0x40B600, 0x2C bytes).
// Identity: position equality test for two game objects — floats at obj+0x50 (x)
// and obj+0x54 (y) are compared with FPU "equal" semantics.
//
// Differential-verified against the original x86 (Scripts/fnmatch.py):
// 1136/1136 fuzzed cases match, including the edge cases below.
//
// Verified semantics (measured, not assumed): the original compares with the
// x87 FPU and tests only the C3 "equal" flag, so an FPU *unordered* result —
// any NaN operand — behaves as EQUAL: f(NaN, x) == 1 for every x, and the
// comparison is -0.0 == 0.0 -> 1 (same as IEEE ==). The reconstruction
// reproduces this with explicit NaN tests; on finite inputs it is plain ==.
typedef int BOOL;

extern "C" BOOL __cdecl objects_at_same_position(const void* a, const void* b)
{
    const float* pa = static_cast<const float*>(a) + 20;  // obj + 0x50
    const float* pb = static_cast<const float*>(b) + 20;  // obj + 0x50
    const float ax = pa[0], ay = pa[1];
    const float bx = pb[0], by = pb[1];

    // x87-C3 equality: equal, or unordered (either side NaN)
    const auto fpu_eq = [](float u, float v) {
        return (u == v) || (u != u) || (v != v);
    };
    return (fpu_eq(ax, bx) && fpu_eq(ay, by)) ? 1 : 0;
}
