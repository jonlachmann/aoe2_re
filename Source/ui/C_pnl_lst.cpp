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
