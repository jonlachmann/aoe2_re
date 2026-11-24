#include "Function.hpp"

// sub_49C2C0 (VA 0x49C2C0) - member: stores three args at +0x1dc, +476, +480.
class S49C2C0 {
public:
    char pad_00[0x1dc];
    int field_a;
    int field_b;
    int field_c;
    void M_49C2C0(int a, int b, int c);
};

MATCH_FUNC(0x49C2C0)
void S49C2C0::M_49C2C0(int a, int b, int c)
{
    field_a = a;
    field_b = b;
    field_c = c;
}
