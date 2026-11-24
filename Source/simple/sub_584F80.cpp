#include "Function.hpp"

// sub_584F80 (VA 0x584F80) - stdcall: 1 unless the object at p+8 has its +0x16
// word equal to 1 or 0x2a (or p is null).
MATCH_FUNC(0x584F80)
extern "C" int __stdcall sub_584F80(char* p)
{
    if (p == 0)
        return 0;
    char* o = *(char**)(p + 8);
    short id = *(short*)(o + 0x16);
    if (id == 1 || id == 0x2a)
        return 0;
    return 1;
}
