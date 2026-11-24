#include "C_cluster_4B4550.hpp"

extern "C" int __stdcall ImmGetOpenStatus(void*);
extern void (*g_pfn_61c0b0)();

MATCH_FUNC(0x4B4550)
int C_cluster_4B4550::M_4B4550()
{
    void* h = handle_164;
    if (h != 0)
        return ImmGetOpenStatus(h);
    return 0;
}

MATCH_FUNC(0x5ED9E8)
__declspec(naked) void C_cluster_4B4550::M_5ED9E8()
{
    __asm {
        jmp dword ptr [g_pfn_61c0b0]
    }
}
