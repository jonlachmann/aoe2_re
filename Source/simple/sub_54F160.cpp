#include "Function.hpp"

// sub_54F160 (VA 0x54F160, 0x11 bytes) - cdecl: stores the arg at
// [global 0x7409E4 + 0x104].
extern char* g_7409E4;

MATCH_FUNC(0x54F160)
extern "C" void __cdecl sub_54F160(int v)
{
    *(int*)(g_7409E4 + 0x104) = v;
}
