#include "Function.hpp"

class S41B6E0 {
public:
    char pad_00[0x14];
    unsigned short field_14;
    char pad_16[0x20 - 0x16];
    unsigned short field_20;
    unsigned char field_22;
    void Move_41B6E0();
};

MATCH_FUNC(0x41B6E0)
void S41B6E0::Move_41B6E0()
{
    unsigned short v = field_14;
    field_22 = 1;
    field_20 = v;
    field_14 = 0;
}
