#include "C_cluster_48B300_member_1E8.hpp"

extern void (__stdcall *g_61C284)(int a1);
extern void (__stdcall *g_61C288)(void* a1, int a2, int a3);

MATCH_FUNC(0x41F920)
void C_cluster_48B300_member_1E8::M_41F920()
{
    if (field_1f4 != 0) {
        if (field_74 == 0 || field_1f8 != 0) {
            g_61C284(0);
            g_61C288(field_28, -0xc, 0);
        } else {
            field_1e8->Hook_48B490();
        }
        field_1f4 = 0;
    }
}
