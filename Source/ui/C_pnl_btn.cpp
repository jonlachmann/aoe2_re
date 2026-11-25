#include "C_pnl_btn.hpp"

MATCH_FUNC(0x4A0750)
void C_pnl_btn::slot02_4A0750(int a1, int a2, int a3, int a4)
{
    this->slot03_4AF9D0(a1, a2, a3 - a1 + 1, a4 - a2 + 1);
}

MATCH_FUNC(0x4AF9D0)
void C_pnl_btn::slot03_4AF9D0(int a, int b, int c, int d)
{
    this->Hook_4A0630(a, b, c, d);
}

MATCH_FUNC(0x4AF8D0)
void C_pnl_btn::M_4AF8D0(short v)
{
    field_202 = v;
    Vat_20(1);
}

MATCH_FUNC(0x4B0EE0)
void C_pnl_btn::M_4B0EE0()
{
    if (field_154 != 0)
        field_154 = 0;
}

MATCH_FUNC(0x5C6880)
int C_pnl_btn::M_5C6880(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    return 0;
}
