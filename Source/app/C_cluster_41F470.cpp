#include "C_cluster_41F470.hpp"

extern void* (__stdcall *g_61C2B0)(void* a1);
extern void (__stdcall *g_61C2C4)(void* a1, void* a2);
extern int (__stdcall *g_61C040)(int a1);
extern void (__stdcall *g_61C294)(void* a1, void* a2, int a3);
extern void (__stdcall *g_61C2B4)(void* a1, void* a2);

MATCH_FUNC(0x41F540)
void C_cluster_41F470::M_41F540()
{
    if (field_28) {
        void* got = g_61C2B0(field_28);
        char buf[16];
        g_61C2C4(field_28, buf);
        int size = g_61C040(4);
        g_61C294(got, buf, size);
        g_61C2B4(field_28, got);
    }
}
