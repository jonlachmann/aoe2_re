#include "C_cluster_45DF20.hpp"

extern void (*g_pfn_61c014)();

MATCH_FUNC(0x5ECE5C)
__declspec(naked) void C_cluster_45DF20::M_5ECE5C()
{
    __asm {
        jmp dword ptr [g_pfn_61c014]
    }
}
