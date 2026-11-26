#include "C_vt621F64.hpp"
#include "matched_mem.h"

extern char g_vt_621F64f;
extern void* g_6645c4;
extern int (__stdcall *g_61C098)(void* a1);
extern int (__stdcall *g_61C378)(int a1);
extern void (__stdcall *g_61C2F8)(int a1, int a2, void* a3, int a4);
extern void* __cdecl sub_5F8FF0(int a1, int a2);

// 0x49F4E0 — vtable constructor clearing the four ten-entry record arrays.
MATCH_FUNC(0x49F4E0)
C_vt621F64* C_vt621F64::Init_49F4E0()
{
    field_ac4 = 1;
    field_ad4 = 1;
    field_4 = 0;
    field_8 = 0;
    field_c = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
    field_ac0 = 0;
    field_ac8 = 0;
    field_acc = 0;
    field_ad0 = 0;
    field_ad8 = 0;
    *(void**)this = &g_vt_621F64f;
    for (int i = 0; i < 10; i++) {
        array_20[i] = 0;
        array_48[i * 0x104] = 0;
        array_a70[i] = 0;
        array_a98[i] = 0;
    }
    this->M_49F9F0();
    return this;
}

// 0x49F9F0 — allocate the +0x14 pool and the two +0xADC/+0xAE0 node pools.
MATCH_FUNC(0x49F9F0)
int C_vt621F64::M_49F9F0()
{
    field_14 = (int)sub_5F8FF0(1, 0xc);
    if (!field_14)
        return 0;
    *(int*)field_14 = 0;
    int (__stdcall *fn)(int) = g_61C378;
    *(int*)(field_14 + 4) = field_14;
    *(int*)(field_14 + 8) = field_14;
    field_adc = fn(5);
    field_ae0 = fn(8);
    field_ad8 = 1;
    return 1;
}

// 0x49FED0 — lazy load of the 0x64 record from the global 0x6645C4 object.
MATCH_FUNC(0x49FED0)
void C_vt621F64::M_49FED0()
{
    if (field_acc != 0)
        return;
    void* r = (((T6645Slot*)ADDR(g_6645c4)))->Vt_08(0x64);
    if (r != 0 && *(char*)r == '1') {
        g_61C2F8(0x6e, 0, (void*)((char*)this + 0xad0), 0);
        field_acc = 1;
    }
}

// 0x49FE00 — drop one reference from the indexed +0x20/+0xA70 record pair.
MATCH_FUNC(0x49FE00)
void C_vt621F64::M_49FE00(int a1)
{
    for (int i = 0; i < 10; i++) {
        if (array_20[i] == a1) {
            if (--array_a70[i] == 0) {
                g_61C098((void*)array_20[i]);
                array_20[i] = 0;
                array_48[i * 0x104] = 0;
            }
            return;
        }
    }
}
