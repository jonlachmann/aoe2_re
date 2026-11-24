#include "Function.hpp"

// sub_5E68A0 (VA 0x5E68A0, 20 bytes) - member: compares the dword at +0xD0
// with the argument and returns int 1/0.
class S5E68A0 {
public:
    char pad_00[0xd0];
    int field_d0;
    int M_5E68A0(int v);
};

MATCH_FUNC(0x5E68A0)
int S5E68A0::M_5E68A0(int v)
{
    return field_d0 == v;
}
