#include "Function.hpp"

// sub_4ADF90 (VA 0x4ADF90) - stdcall with 7 args: clears the last two pointer
// args and returns 0.
MATCH_FUNC(0x4ADF90)
extern "C" int __stdcall sub_4ADF90(int a1, int a2, int a3, int a4, int a5, int* p6, int* p7)
{
    *p6 = 0;
    *p7 = 0;
    return 0;
}
