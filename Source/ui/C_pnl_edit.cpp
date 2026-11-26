#include "C_pnl_edit.hpp"

extern void (*g_pfn_61c0b8)();
extern void (*g_pfn_61c0bc)();
extern void (__stdcall *g_61C2FC)(void* a1, int a2);

MATCH_FUNC(0x4B32F0)
void C_pnl_edit::M_4B32F0(int a1)
{
    this->Hook_4A07A0(a1);
    if (field_f8 != 0 && field_6c == 0) {
        g_61C2FC(field_f8, 0);
        field_108 = 1;
    }
}

MATCH_FUNC(0x4378C0)
void C_pnl_edit::M_4378C0()
{
}

MATCH_FUNC(0x5ED9F4)
void C_pnl_edit::M_5ED9F4()
{
    g_pfn_61c0b8();
}

MATCH_FUNC(0x5ED9FA)
void C_pnl_edit::M_5ED9FA()
{
    g_pfn_61c0bc();
}

extern void (__stdcall *g_61C278)(void* a1, int a2, int a3);

// 0x4B3690 — slot 8: clear the +0x6c flag then free the +0xf8 block.
MATCH_FUNC(0x4B3690)
void C_pnl_edit::slot08_4B3690(int a1)
{
    this->Hook_4A08C0(1);
    if (field_6c != 0 && a1 != 0 && field_f8 != 0 && field_108 == 0)
        g_61C278(field_f8, 0, 1);
}

// 0x4B2D50 — panel-edit reset constructor: run the base 0x4A0270 init and
// zero the +0xF8/+0x100/+0xFC/+0x10C/+0x114..+0x128/+0x150/+0x158..+0x15D/
// +0x160..+0x170 block, write the 0x622934 vtable pointer, set the +0x80/
// +0x108/+0x154 flags to 1, the +0xF2 mode byte to 0xA and return this.
WIP_FUNC(0x4B2D50)
C_pnl_edit* C_pnl_edit::M_4B2D50()
{
    this->Hook_4A0270();
    field_f8 = 0;
    field_100 = 0;
    field_fc = 0;
    field_10C = 0;
    field_114[0] = 0;
    field_114[1] = 0;
    field_114[2] = 0;
    field_114[3] = 0;
    field_114[4] = 0;
    field_114[5] = 0;
    field_150 = 0;
    array_158[0] = 0;
    array_158[1] = 0;
    array_158[2] = 0;
    array_158[3] = 0;
    array_158[4] = 0;
    array_158[5] = 0;
    field_160 = 0;
    field_164 = 0;
    field_168 = 0;
    field_16C = 0;
    field_170 = 0;
    *(int*)((char*)this) = 0x622934;
    field_80 = 1;
    field_108 = 1;
    field_154 = 1;
    field_f2 = 0xA;
    return this;
}
