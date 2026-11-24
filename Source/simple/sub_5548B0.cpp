#include "Function.hpp"

// sub_5548B0 (VA 0x5548B0) - cdecl: whether the dword at [global 0x741F60 +
// 0x104] equals the arg.
extern char* g_741F60;
MATCH_FUNC(0x5548B0)
extern "C" bool __cdecl sub_5548B0(int v)
{
    return *(int*)(g_741F60 + 0x104) == v;
}
