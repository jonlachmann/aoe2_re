#include "Function.hpp"

// sub_48D440 (VA 0x48D440) - member: stores three args at +0xac, +172, +176.
class S48D440 {
public:
    char pad_00[0xac];
    int field_a;
    int field_b;
    int field_c;
    void M_48D440(int a, int b, int c);
};

MATCH_FUNC(0x48D440)
void S48D440::M_48D440(int a, int b, int c)
{
    field_a = a;
    field_b = b;
    field_c = c;
}
