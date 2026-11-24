#include "Function.hpp"

// sub_440F70 (VA 0x440F70) - stdcall: returns one of two globals by flag.
extern int g_6514FC;
extern int g_6514E4;
MATCH_FUNC(0x440F70)
extern "C" int* __stdcall sub_440F70(int flag)
{
    return flag ? &g_6514FC : &g_6514E4;
}
