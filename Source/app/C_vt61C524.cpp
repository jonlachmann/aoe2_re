#include "C_vt61C524.hpp"

MATCH_FUNC(0x409A00)
unsigned short C_vt61C524::Get_409A00()
{
    return *(unsigned short*)((char*)this + 0x4);
}

MATCH_FUNC(0x409A20)
bool C_vt61C524::M_409A20(int unused)
{
    (void)unused;
    return false;
}

MATCH_FUNC(0x409A30)
bool C_vt61C524::M_409A30(int a, int b)
{
    (void)a; (void)b;
    return false;
}

MATCH_FUNC(0x4015E0)
int C_vt61C524::M_4015E0()
{
    Vat_5C(1);
    return 1;
}

MATCH_FUNC(0x402960)
void C_vt61C524::M_402960(int a1)
{
    if (a1 != this->field_10)
    {
        int p = (int)this->field_08;
        *(int*)((char*)p + 0x164) = 0;
    }
    this->Hook_409AD0(a1);
}
