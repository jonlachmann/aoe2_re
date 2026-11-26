#include "C_cluster_45DF20.hpp"

extern void (*g_pfn_61c014)();
extern void* (__stdcall *g_61C050)(int a1, int a2, int a3, int a4);
extern int (__stdcall *g_61C034)(int a1, int a2);
extern void (__stdcall *g_61C04C)(int a1);
extern int __stdcall Hook_5ECE5C(int a1, int a2, int a3);

MATCH_FUNC(0x5ECE5C)
__declspec(naked) void C_cluster_45DF20::M_5ECE5C()
{
    __asm {
        jmp dword ptr [g_pfn_61c014]
    }
}

// 0x45DF20 — with a zero argument, set +0x54 = 1, create the 0x64DAA0 object
// through 0x61C050, read its 8 and 0xA values through 0x61C034, release it via
// 0x61C04C and latch +0x58/+0x5C/+0x60/+0x64 for values crossing 0x320/0x400/
// 0x500. With a nonzero argument, ensure the +0x18 object exists through the
// 0x5ECE5C thunk (returning early on failure), dispatch its +0x20 slot, and if
// the object was newly created call its +0x08 slot and clear +0x18.
WIP_FUNC(0x45DF20)
void C_cluster_45DF20::M_45DF20(int a1)
{
    if (a1 == 0)
    {
        field_54 = (0x64DAA0 != 0);
        void* p = g_61C050((int)0x64DAA0, 0, 0, 0);
        if (p == 0)
            return;
        int v = g_61C034((int)p, 8);
        v = g_61C034((int)p, 0xA);
        g_61C04C((int)p);
        if (v >= 0x320)
            field_58 = 1;
        if (v >= 0x400)
            field_5c = 1;
        if (v >= 0x500)
        {
            field_60 = 1;
            field_64 = 1;
        }
        return;
    }
    int fresh;
    if (field_18 == 0)
    {
        if (Hook_5ECE5C(0, (int)&field_18, 0) != 0)
            return;
        fresh = 0;
    }
    else
        fresh = 1;
    T45DFObj* obj = (T45DFObj*)field_18;
    obj->Vt_20((int)obj, 0, 0, (int)this, 0x45DFE0);
    if (fresh != 0)
        return;
    obj->Vt_08((int)obj);
    field_18 = 0;
}
