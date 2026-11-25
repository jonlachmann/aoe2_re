#include "C_pnl_lst.hpp"

extern "C" int __stdcall sub_4BCF50(int v);

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
