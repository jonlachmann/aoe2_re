#include "C_cluster_49FE60.hpp"

extern void (*g_pfn_61c0a8)();

MATCH_FUNC(0x5ED9D6)
__declspec(naked) void C_cluster_49FE60::M_5ED9D6()
{
    __asm {
        jmp dword ptr [g_pfn_61c0a8]
    }
}
