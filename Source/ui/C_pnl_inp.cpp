#include "C_pnl_inp.hpp"

MATCH_FUNC(0x408050)
void C_pnl_inp::M_408050(int a, int b)
{
    (void)a; (void)b;
}

MATCH_FUNC(0x4B4600)
void C_pnl_inp::SetInt_4B4600(int v)
{
    *(int*)((char*)this + 0x188) = v;
}

MATCH_FUNC(0x4BAF60)
void C_pnl_inp::M_4BAF60(int a, int b, int c, int d)
{
    (void)c; (void)d;
    Vat_f4(a, b);
}

MATCH_FUNC(0x4BCE20)
int C_pnl_inp::M_4BCE20(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    T4BCE20Sub* s = field_40;
    if (s)
        s->Vat_C4(this, 1, 0, 0);
    return 0;
}
