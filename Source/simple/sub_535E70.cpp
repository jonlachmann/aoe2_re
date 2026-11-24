#include "Function.hpp"

// sub_535E70 (VA 0x535E70) - stdcall: true for ids 0x32 and 0x2d.
MATCH_FUNC(0x535E70)
extern "C" bool __stdcall sub_535E70(int id)
{
    if (id == 0x32 || id == 0x2d)
        return true;
    return false;
}
