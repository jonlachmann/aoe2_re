#include "Function.hpp"

class S52B330 {
public:
    char pad_00[0x44];
    int field_44;
    char pad_48[4];
    unsigned short field_4c;
    void Set_52B330(unsigned short a, int b);
};

MATCH_FUNC(0x52B330)
void S52B330::Set_52B330(unsigned short a, int b)
{
    field_4c = a;
    field_44 = b;
}
