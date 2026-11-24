#include "Function.hpp"

// sub_4829D0 (VA 0x4829D0) - stdcall: clears the four dwords at
// p+0x34..+0x40.
struct S4829D0 {
    char pad_00[0x34];
    int field_34;
    int field_38;
    int field_3c;
    int field_40;
};
MATCH_FUNC(0x4829D0)
extern "C" void __stdcall sub_4829D0(S4829D0* p)
{
    p->field_34 = 0;
    p->field_38 = 0;
    p->field_3c = 0;
    p->field_40 = 0;
}
