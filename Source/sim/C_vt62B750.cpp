#include "C_vt62B750.hpp"

// 0x5A46C0 — clear five consecutive (offset pair) dspots from 0x1C40 through
// 0x1C58 and return the first dword past the cleared tail (0x1C5C).
MATCH_FUNC(0x5A46C0)
int* C_vt62B750::ClearTail_5A46C0()
{
    int* result = (int*)this + 1810;
    int v2 = 5;
    do {
        *(result - 2) = 0;
        *result = 0;
        result += 4;
        --v2;
    } while (v2);
    return result;
}
