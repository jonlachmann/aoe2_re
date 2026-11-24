#include "C_cluster_42E650.hpp"

extern void (*g_pfn_61c024)();

MATCH_FUNC(0x5ECE4A)
__declspec(naked) void C_cluster_42E650::M_5ECE4A()
{
    __asm {
        jmp dword ptr [g_pfn_61c024]
    }
}
