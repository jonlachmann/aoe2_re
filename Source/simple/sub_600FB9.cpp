#include "Function.hpp"

extern double g_61c690;

// CRT code (0x5FE000+) is size-optimized: sahf/jb and `push 1; pop eax`.
#pragma optimize("s", on)

MATCH_FUNC(0x600FB9)
int Cmp_600FB9(double* value)
{
    if (*value >= g_61c690)
        return 1;
    return 0;
}
