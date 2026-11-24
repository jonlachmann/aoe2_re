#include "Function.hpp"

// sub_4BF6E0 (VA 0x4BF6E0) - stdcall: detaches q = p->field_10, clearing
// q->field_14 and p->field_10.
struct S4BF6E0 {
    char pad_00[0x10];
    S4BF6E0* field_10;
    int field_14;
};
MATCH_FUNC(0x4BF6E0)
extern "C" void __stdcall sub_4BF6E0(S4BF6E0* p)
{
    S4BF6E0* q = p->field_10;
    if (q != 0) {
        q->field_14 = 0;
        p->field_10 = 0;
    }
}
