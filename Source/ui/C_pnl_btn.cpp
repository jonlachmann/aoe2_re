#include "C_pnl_btn.hpp"

extern void (__stdcall *g_61C2F4)(int a1, int a2, int a3, int a4);
extern short (__stdcall *g_61C2C0)(int a1);

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

// 0x4B0AE0 — for message ids 0x101/0x105 with a live +0x2C4 object matching
// the third argument (and either equal/zero +0x2A8, 0xD or 0x20), clear +0x2C4,
// reset +0x204 unless +0x148 is 2, notify slot +0x20, poll the +0x20 subobject's
// second word through the 0x61C2F4 callback, read 0x61C2C0(0x10) into the signed
// comparison and forward that to 0x4B0C30, returning 1. Otherwise forward all
// four arguments to 0x4A0CD0 and return its result.
MATCH_FUNC(0x4B0AE0)
int C_pnl_btn::M_4B0AE0(int a1, int a2, int a3, int a4)
{
    if (a2 == 0x101 || a2 == 0x105)
    {
        int cur = field_2c4;
        if (cur != 0 && a3 == cur)
        {
            int other = field_2a8;
            if (cur == other || other == 0 || cur == 0xD || cur == 0x20)
            {
                int state = field_148;
                field_2c4 = 0;
                if (state != 2)
                    field_204 = 0;
                Vat_20(1);
                int* sub = (int*)field_20;
                g_61C2F4(sub[1], 0xF, 0, 0);
                int less = g_61C2C0(0x10) < 0;
                Hook_4B0C30(less);
                return 1;
            }
        }
    }
    return Hook_4A0CD0(a1, a2, a3, a4);
}
