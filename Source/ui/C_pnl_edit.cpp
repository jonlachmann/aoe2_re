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
__declspec(naked) void C_pnl_edit::M_5ED9F4()
{
    __asm {
        jmp dword ptr [g_pfn_61c0b8]
    }
}

MATCH_FUNC(0x5ED9FA)
__declspec(naked) void C_pnl_edit::M_5ED9FA()
{
    __asm {
        jmp dword ptr [g_pfn_61c0bc]
    }
}
