#include "Function.hpp"

class S49C100 {
public:
    char pad_00[0x1ea];
    unsigned char field_1ea;
    int field_1ec;
    int field_1f0;
    int field_1f4;
    void Set_49C1B0(int a, int b);
    void Set_49C2F0(unsigned char a, int b);
};

MATCH_FUNC(0x49C1B0)
void S49C100::Set_49C1B0(int a, int b)
{
    field_1f0 = a;
    field_1f4 = b;
}

MATCH_FUNC(0x49C2F0)
void S49C100::Set_49C2F0(unsigned char a, int b)
{
    field_1ea = a;
    field_1ec = b;
}
