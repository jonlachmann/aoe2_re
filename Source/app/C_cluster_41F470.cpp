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

// 0x41F470 — window/session state handler. When +0x2C is clear it runs the
// 0x41F540 handoff and releases +0x28; otherwise it checks 0x61C2A0, and when
// +0x30 is clear attempts 0x61C29C and the 0x45EF10 update. The nonzero +0x30
// path switches on (0x45E930 & 0xff): 1 returns 0, 2 runs the matched
// 0x45EA60 clear + 0x422420 mark and returns 1, 3 releases +0x28 and 0x61C2EC,
// and any other value returns 1.
extern void (__stdcall *g_61C298)(void* a1, int a2);
extern int (__stdcall *g_61C2A0)(int a1);
extern int (__stdcall *g_61C29C)(void* a1, void* a2, int a3);
extern void (__stdcall *g_61C2EC)(void* a1);
class S45EA60 {
public:
    int M_45E930();
    void Clear_45EA60();
    void M_45EF10(int* a1);
};
class S422420 {
public:
    void Mark_422420();
};

MATCH_FUNC(0x41F470)
int C_cluster_41F470::M_41F470()
{
    if (field_2c == 0)
    {
        M_41F540();
        g_61C298(field_28, 0);
        return 0;
    }
    if (g_61C2A0((int)field_28) != 0)
    {
        g_61C298(field_28, 0);
        return 0;
    }
    if (field_30 == 0)
    {
        int local[4];
        if (g_61C29C(field_28, local, 0) != 0)
            ((S45EA60*)field_68)->M_45EF10(local);
        g_61C298(field_28, 0);
        return 0;
    }
    switch (((S45EA60*)field_68)->M_45E930() & 0xff)
    {
    case 1:
        return 0;
    case 2:
        ((S45EA60*)field_68)->Clear_45EA60();
        ((S422420*)this)->Mark_422420();
        break;
    case 3:
        g_61C298(field_28, 0);
        g_61C2EC(field_28);
        return 0;
    }
    return 1;
}
