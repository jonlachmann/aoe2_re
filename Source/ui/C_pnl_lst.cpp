#include "C_pnl_lst.hpp"

extern "C" int __stdcall sub_4BCF50(int v);
extern int (__stdcall *g_61C3C8)();

MATCH_FUNC(0x4B6840)
int __stdcall C_pnl_lst::M_4B6840(int v)
{
    return sub_4BCF50(v) >= 0;
}

MATCH_FUNC(0x4BCEB0)
void C_pnl_lst::M_4BCEB0(short v)
{
    field_104 = v;
    Other_4BBD30(1);
}

// 0x4BAE20 — panel-list slot +0xF4: drive slot +0x120, then either re-add the
// +0x662BE0 registration when +0x150 is clear or re-add each element of an
// incoming array for the short count.
MATCH_FUNC(0x4BAE20)
void C_pnl_lst::M_4BAE20(int* a1, short a2)
{
    slot_072();
    if (a2 == 0)
    {
        if (field_150 != 0)
            Other_4BCF90(0x662be0, 0, 0);
        return;
    }
    if (a2 <= 0)
        return;
    while (a2 > 0)
    {
        Other_4BCF90(*a1, 0, 0);
        a1++;
        a2--;
    }
}

// 0x4B5A10 — set the +0x19C display mode from the seven-case argument, forward
// all seven arguments to 0x4BBC20, then activate +0x198 once with 0x4BBD30.
MATCH_FUNC(0x4B5A10)
void C_pnl_lst::M_4B5A10(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    switch (a1)
    {
    case 1:
    case 2:
    case 5:
        field_19c = 1;
        break;
    case 3:
    case 6:
        field_19c = 2;
        break;
    case 4:
    case 7:
        field_19c = 3;
        break;
    default:
        field_19c = 1;
        break;
    }
    M_4BBC20(a1, a2, a3, a4, a5, a6, a7);
    if (field_198 == 0)
    {
        field_198 = 1;
        Other_4BBD30(1);
    }
}

// 0x4B3760 — seven-argument display configuration: store +0x154 and the six
// +0x158..+0x15D bytes, map the first argument to +0x160 (1/2/5 -> 1,
// 3/6 -> 2, 4/7 -> 3, otherwise 0), propagate the four +0x0C..+0x18 values
// through slot +0x0C, then notify through slot +0x20 with 1.
WIP_FUNC(0x4B3760)
void C_pnl_lst::M_4B3760(int a1, unsigned char a2, unsigned char a3, unsigned char a4,
                         unsigned char a5, unsigned char a6, unsigned char a7)
{
    field_158 = a2;
    field_159 = a3;
    field_154 = a1;
    field_15a = a4;
    field_15b = a5;
    field_15c = a6;
    field_15d = a7;
    switch (a1)
    {
    case 1:
    case 2:
    case 5:
        field_160 = 1;
        break;
    case 3:
    case 6:
        field_160 = 2;
        break;
    case 4:
    case 7:
        field_160 = 3;
        break;
    default:
        field_160 = 0;
        break;
    }
    slot_003(field_c, field_10, field_14, field_18);
    slot_008(1);
}

// 0x4B5AB0 — tick gate: run the 0x4A1160 update, return 0 when both +0x1B4/
// +0x1B8 are clear or the unsigned elapsed time since +0x1AC is still below
// the +0x1B0 interval; on expiry record the current tick, then when +0x1B4 is
// set re-sync +0x104 from the +0x100 word and dispatch the 3-arg slot 3 call,
// otherwise re-sync from the +0x102 word and dispatch slot 2.
MATCH_FUNC(0x4B5AB0)
int C_pnl_lst::M_4B5AB0()
{
    Hook_4A1160();
    if (field_1b4 == 0 && field_1b8 == 0)
        return 0;
    unsigned int now = (unsigned int)g_61C3C8();
    if ((now - (unsigned int)field_1ac) < (unsigned int)field_1b0)
        return 0;
    field_1ac = (int)now;
    if (field_1b4 != 0)
    {
        short v = field_100;
        if (field_104 != v)
            Hook_4B60B0(1, v, 1);
        Hook_4B60B0(3, 0, 1);
    }
    else
    {
        short v = field_102;
        if (field_104 != v)
            Hook_4B60B0(1, v, 1);
        Hook_4B60B0(2, 0, 1);
    }
    return 0;
}

// 0x4B5690 — flush the +0x1C0 subobject through 0x4BA5C0, clamp both captured
// +0x100/+0x104 shorts against +0xFC-1, store the clamped +0x104, dispatch the
// short-argument 0x4BBF20 setter with the original +0x100 word, then notify
// slot +0x20 with 1.
MATCH_FUNC(0x4B5690)
void C_pnl_lst::M_4B5690()
{
    short old100 = field_100;
    short old104 = field_104;
    Hook_4BA5C0(field_1c0, 0);
    short lim = field_fc;
    if (old104 >= lim)
        old104 = lim - 1;
    field_104 = old104;
    if (old100 >= lim)
        field_100 = lim - 1;
    M_4BBF20(1, old100, 1);
    slot_008(1);
}

// 0x4BA390 — copy the seventh argument into a four-word temporary, then forward
// seventeen arguments to 0x4BA250 with the temporary in the seventh slot and
// the fourteenth/fifteenth pair swapped (a15 then a14).
WIP_FUNC(0x4BA390)
void C_pnl_lst::M_4BA390(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                         int a8, int a9, int a10, int a11, int a12, int a13,
                         int a14, int a15, int a16, int a17)
{
    int tmp[4];
    tmp[0] = a7;
    tmp[1] = a7;
    tmp[2] = a7;
    tmp[3] = a7;
    Hook_4BA250(a1, a2, a3, a4, a5, a6, tmp, a7, a8, a9, a10, a11, a12,
                a13, a15, a14, a17);
}

// 0x4BBF20 — switch on the low byte of the first argument to adjust the
// +0x100 word (adding/assigning the second short for 0/1, stepping it for 2/3,
// applying the +0xFE-derived deltas for 4/5, zeroing for 6 and clamping to
// +0xFC-1 for 7), then re-sync through 0x4BBD30(a3) and notify slot +0x20.
WIP_FUNC(0x4BBF20)
void C_pnl_lst::M_4BBF20(int a1, short a2, int a3)
{
    switch (a1 & 0xff)
    {
    case 0:
        field_100 += a2;
        break;
    case 1:
        field_100 = a2;
        break;
    case 2:
        field_100++;
        break;
    case 3:
        field_100--;
        break;
    case 4:
        field_100 += field_fe - 1;
        break;
    case 5:
        field_100 += 1 - field_fe;
        break;
    case 6:
        field_100 = 0;
        break;
    case 7:
        field_100 = field_fc - 1;
        break;
    }
    Other_4BBD30(a3);
    slot_008(1);
}
