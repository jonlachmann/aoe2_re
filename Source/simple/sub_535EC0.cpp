#include "Function.hpp"

class S535EC0Sub {
public:
    char pad_00[0x16];
    short field_16;
};

class S535EC0 {
public:
    char pad_00[8];
    S535EC0Sub* field_8;
    unsigned char IsOther_535EC0();
};

MATCH_FUNC(0x535EC0)
unsigned char S535EC0::IsOther_535EC0()
{
    int v = field_8->field_16;
    if (v == 0x15 || v == 2)
        return 0;
    return 1;
}
