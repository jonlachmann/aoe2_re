#include "Function.hpp"

extern unsigned char g_772bc1[256];   // _mbctype + 1

// _mbsinc: skip a lead byte's trail byte. CRT code is size-optimized (movzx
// instead of xor+mov).
#pragma optimize("s", on)

MATCH_FUNC(0x5FF5E6)
char* Skip_5FF5E6(char* p)
{
    if (g_772bc1[(unsigned char)*p++] & 4)
        ++p;
    return p;
}
