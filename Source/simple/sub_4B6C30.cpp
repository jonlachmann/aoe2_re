#include "Function.hpp"

// sub_4B6C30 (VA 0x4B6C30) - member: stores three args at +0x324, +804, +808.
class S4B6C30 {
public:
    char pad_00[0x324];
    int field_a;
    int field_b;
    int field_c;
    void M_4B6C30(int a, int b, int c);
};

MATCH_FUNC(0x4B6C30)
void S4B6C30::M_4B6C30(int a, int b, int c)
{
    field_a = a;
    field_b = b;
    field_c = c;
}
