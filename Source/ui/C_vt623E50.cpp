#include "C_vt623E50.hpp"

// 0x4CD410 — measure the +0x10 string: null yields 0xC, otherwise
// strlen + 0xC (the tail is the compiler's strlen+1 idiom followed by an add).
MATCH_FUNC(0x4CD410)
int C_vt623E50::M_4CD410()
{
    // Return the +0x10 string's total size: strlen+1 bytes of text plus the
    // 0xC-byte header, or just the header when the pointer is null.
    char* s = *(char**)((char*)this + 0x10);
    int n;
    if (s != 0)
        n = strlen(s) + 1;
    else
        n = 0;
    return n + 0xc;
}
