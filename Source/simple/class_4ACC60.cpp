#include "Function.hpp"

class S4ACC84 {
public:
    bool M_5D17D0();
};

class S4ACC60 {
public:
    virtual void V0();
    virtual void V1(int);
    char pad_04[0x84 - 4];
    S4ACC84* field_84;
    char pad_88[0xa2 - 0x88];
    unsigned char field_a2;
    void SetOne_4ACB80();
    void SetTwo_4ACBA0();
    bool Check_4ACC60();
};

MATCH_FUNC(0x4ACB80)
void S4ACC60::SetOne_4ACB80()
{
    if (field_a2 == 0)
        V1(1);
}

MATCH_FUNC(0x4ACBA0)
void S4ACC60::SetTwo_4ACBA0()
{
    if (field_a2 == 0)
        V1(2);
}

MATCH_FUNC(0x4ACC60)
bool S4ACC60::Check_4ACC60()
{
    if (field_a2 != 2)
        return field_84->M_5D17D0();
    return true;
}
