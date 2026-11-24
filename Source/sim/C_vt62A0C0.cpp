#include "C_vt62A0C0.hpp"

MATCH_FUNC(0x584F80)
int __stdcall C_vt62A0C0::M_584F80(char* p)
{
    if (p == 0)
        return 0;
    char* o = *(char**)(p + 8);
    short id = *(short*)(o + 0x16);
    if (id == 1 || id == 0x2a)
        return 0;
    return 1;
}

MATCH_FUNC(0x589AE0)
int C_vt62A0C0::M_589AE0(int unused)
{
    (void)unused;
    return 5;
}
