#include "Function.hpp"

// sub_472420 (VA 0x472420) - stdcall: returns p, or p's +0x1c4 object when the
// +0x4e byte is 0x50 and that object exists.
struct S472420 {
    char pad_00[0x4e];
    unsigned char field_4e;
    char pad_4f[0x1c4 - 0x4f];
    char* field_1c4;
};
MATCH_FUNC(0x472420)
extern "C" S472420* __stdcall sub_472420(S472420* p)
{
    if (p->field_4e == 0x50) {
        char* q = p->field_1c4;
        if (q != 0)
            p = (S472420*)q;
    }
    return p;
}
