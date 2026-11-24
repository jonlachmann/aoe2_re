#include "Function.hpp"

// sub_41A040 (VA 0x41A040, 0xB bytes) - stdcall (ret 0x14): clears the pointee
// of the fifth argument and returns -1.
MATCH_FUNC(0x41A040)
extern "C" int __stdcall sub_41A040(int a1, int a2, int a3, int a4, int* out)
{
    *out = 0;
    return -1;
}
