#include "Function.hpp"

// sub_540DF0 (VA 0x540DF0) - member: stores the arg byte at +0xc and, when
// it is 10, sets the float 3.0 at +0x2c.
class S540DF0 {
public:
    char pad_00[0xc];
    unsigned char field_c;
    char pad_0D[0x2c - 0x0D];
    float field_2c;
    void M_540DF0(unsigned char v);
};

