#include "Function.hpp"

// sub_555010 (VA 0x555010) - cdecl: whether the dword at [global 0x741F68 +
// 0x9c] equals the arg.
extern char* g_741F68;
MATCH_FUNC(0x555010)
extern "C" bool __cdecl sub_555010(int v)
{
    return *(int*)(g_741F68 + 0x9c) == v;
}
