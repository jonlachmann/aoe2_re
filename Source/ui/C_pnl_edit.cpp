#include "C_pnl_edit.hpp"

extern void (*g_pfn_61c0b8)();
extern void (*g_pfn_61c0bc)();

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
