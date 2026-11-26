#include "C_vt623E50.hpp"

// 0x4CD410 — measure the +0x10 string: null yields 0xC, otherwise
// strlen + 0xC (the tail is the compiler's strlen+1 idiom followed by an add).
WIP_FUNC(0x4CD410)
int C_vt623E50::M_4CD410()
{
    char* s = *(char**)((char*)this + 0x10);
    if (s != 0)
        return strlen(s) + 1 + 0xc;
    return 0xc;
}
