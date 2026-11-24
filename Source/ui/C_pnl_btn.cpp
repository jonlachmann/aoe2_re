#include "C_pnl_btn.hpp"

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
