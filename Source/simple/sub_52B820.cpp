#include "Function.hpp"

// sub_52B820 (VA 0x52B820) - member: stores three args at +0x38/+0x3c/+0x40.
class S52B820 {
public:
    char pad_00[0x38];
    int field_38;
    int field_3c;
    int field_40;
    void M_52B820(int a, int b, int c);
};

MATCH_FUNC(0x52B820)
void S52B820::M_52B820(int a, int b, int c)
{
    field_38 = a;
    field_3c = b;
    field_40 = c;
}
