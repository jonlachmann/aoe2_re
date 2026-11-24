// free_crt_s — size-optimized CRT leaves migrated from Source/simple.
// CRT code at 0x5FE000+ is compiled with #pragma optimize("s", on).
#include "Function.hpp"

#pragma optimize("s", on)

extern unsigned char g_772bc1[256];   // _mbctype + 1

// _mbsinc: skip a lead byte's trail byte. CRT code is size-optimized (movzx
// instead of xor+mov).

MATCH_FUNC(0x5FF5E6)
char* Skip_5FF5E6(char* p)
{
    if (g_772bc1[(unsigned char)*p++] & 4)
        ++p;
    return p;
}

extern double g_61c690;

// CRT code (0x5FE000+) is size-optimized: sahf/jb and `push 1; pop eax`.

MATCH_FUNC(0x600FB9)
int Cmp_600FB9(double* value)
{
    if (*value >= g_61c690)
        return 1;
    return 0;
}
