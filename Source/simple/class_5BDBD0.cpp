#include "Function.hpp"

class S5BDBD0 {
public:
    char pad_00[4];
    int field_4;
    int field_8;
    int field_c;
    char pad_10[0x10 - 0xc - 4];
    void Init_5BDBD0();
};

MATCH_FUNC(0x5BDBD0)
void S5BDBD0::Init_5BDBD0()
{
    field_4 = 0;
    for (int i = 0; i < 0x10; ++i)
        ((int*)this)[3 + i] = -1;
}
