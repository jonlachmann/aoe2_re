#include "Function.hpp"

// sub_5C13A0 (VA 0x5C13A0) - member: field_5224 = arg; also sets the +0xc
// byte to 1 unless the arg is 4.
class S5C13A0 {
public:
    char pad_00[0xc];
    unsigned char field_c;
    char pad_0D[0x5224 - 0x0D];
    int field_5224;
    void M_5C13A0(int v);
};

MATCH_FUNC(0x5C13A0)
void S5C13A0::M_5C13A0(int v)
{
    field_5224 = v;
    if (v != 4)
        field_c = 1;
}
