#include "C_vt61C800.hpp"

extern float g_61c584;
MATCH_FUNC(0x403C90)
int C_vt61C800::M_403C90(float unused, float a1, float a2, float a3)
{
    (void)unused;
    if (a1 >= g_61c584 && a2 >= g_61c584)
    {
        this->field_20 = a1;
        this->field_24 = a2;
        this->field_28 = a3;
        Vat_5C(0xb);
    }
    else
        Vat_5C(3);
    return 1;
}

MATCH_FUNC(0x403A20)
void C_vt61C800::M_403A20(int unused)
{
    (void)unused;
    if (*(int*)((char*)this + 0x20) == (int)0xbf800000)
        Vat_5C(3);
    else
        Vat_5C(0xb);
}
