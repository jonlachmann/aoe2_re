#include "Function.hpp"

// sub_4B6840 (VA 0x4B6840) - stdcall: whether helper 0x4BCF50's result is >= 0.
extern "C" int __stdcall sub_4BCF50(int v);
MATCH_FUNC(0x4B6840)
extern "C" int __stdcall sub_4B6840(int v)
{
    return sub_4BCF50(v) >= 0;
}
