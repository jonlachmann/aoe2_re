#include "C_cluster_42E3E0.hpp"

extern void (*g_pfn_61c01c)();

MATCH_FUNC(0x5ECE44)
__declspec(naked) void C_cluster_42E3E0::M_5ECE44()
{
    __asm {
        jmp dword ptr [g_pfn_61c01c]
    }
}
