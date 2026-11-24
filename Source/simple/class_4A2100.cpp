#include "Function.hpp"

class S4A2100 {
public:
    char pad_00[0xe8];
    int field_e8;
    int field_ec;
    char pad_f0[0xf8 - 0xf0];
    int field_f8;
    int field_fc;
    void SetE8_4A21B0(int a, int b);
    void SetF8_4A3410(int a, int b);
};

MATCH_FUNC(0x4A21B0)
void S4A2100::SetE8_4A21B0(int a, int b)
{
    field_e8 = a;
    field_ec = b;
}

