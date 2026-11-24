#include "Function.hpp"

// sub_472420 (VA 0x472420) - stdcall: returns p, or p's +0x1c4 object when the
// +0x4e byte is 0x50 and that object exists.
struct S472420 {
    char pad_00[0x4e];
    unsigned char field_4e;
    char pad_4f[0x1c4 - 0x4f];
    char* field_1c4;
};
