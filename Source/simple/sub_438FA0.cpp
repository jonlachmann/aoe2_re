#include "Function.hpp"

// sub_438FA0 (VA 0x438FA0) - stdcall: copies a 16-byte (four dword) struct.
struct P438FA0 {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
};
MATCH_FUNC(0x438FA0)
extern "C" void __stdcall sub_438FA0(P438FA0* dst, P438FA0* src)
{
    *dst = *src;
}
