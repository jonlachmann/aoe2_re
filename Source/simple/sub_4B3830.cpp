#include "Function.hpp"

// sub_4B3830 (VA 0x4B3830) - member: stores three args at +0x168, +360, +364.
class S4B3830 {
public:
    char pad_00[0x168];
    int field_a;
    int field_b;
    int field_c;
    void M_4B3830(int a, int b, int c);
};

MATCH_FUNC(0x4B3830)
void S4B3830::M_4B3830(int a, int b, int c)
{
    field_a = a;
    field_b = b;
    field_c = c;
}
