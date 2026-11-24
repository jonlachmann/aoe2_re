#include "Function.hpp"

class S4B6860 {
public:
    char pad_00[0x1c0];
    int field_1c0;
    unsigned char field_1c4;
    void Set_4B6860(int a, unsigned char b);
};

MATCH_FUNC(0x4B6860)
void S4B6860::Set_4B6860(int a, unsigned char b)
{
    field_1c0 = a;
    field_1c4 = b;
}
