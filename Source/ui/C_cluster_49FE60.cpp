#include "C_cluster_49FE60.hpp"

extern void (*g_pfn_61c0a8)();
extern int g_664528;
extern int __stdcall sub_5ED9D6(int a1, int a2);   // unresolved callee at 0x5ED9D6

MATCH_FUNC(0x49FE60)
void C_cluster_49FE60::M_49FE60()
{
    if (field_ac4 != 0) {
        field_ac0 = sub_5ED9D6(g_664528, 0);
        field_ac4 = 0;
    }
}

MATCH_FUNC(0x5ED9D6)
void C_cluster_49FE60::M_5ED9D6()
{
    g_pfn_61c0a8();
}
