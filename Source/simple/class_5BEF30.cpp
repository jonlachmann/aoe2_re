#include "Function.hpp"

class S5BEF30 {
public:
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    char pad_06[0x8 - 0x06];
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
    int field_38;
    int field_3c;
    S5BEF30* Init_5BEF30(int v);
};

MATCH_FUNC(0x5BEF30)
S5BEF30* S5BEF30::Init_5BEF30(int v)
{
    field_4 = 0;
    field_5 = 0;
    field_8 = 0;
    field_c = 0;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
    field_20 = 0;
    field_24 = 0;
    field_28 = 0;
    field_2c = 0;
    field_30 = 0;
    field_34 = 0;
    field_38 = 0;
    field_0 = 1;
    field_10 = -1;
    field_3c = v;
    return this;
}
