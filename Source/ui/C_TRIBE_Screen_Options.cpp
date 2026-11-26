#include "C_TRIBE_Screen_Options.hpp"
#pragma intrinsic(strcpy)
#pragma intrinsic(strlen)

extern void __cdecl Free_5F90B0(void* p);
extern void* __cdecl sub_5F8F80(int size);

extern void (__stdcall *g_61C06C)(void* a1, int a2);
extern int (__stdcall *g_61C098)(void* a1);
extern int (__stdcall *g_61C088)(int a1, int a2, int a3, int a4);

MATCH_FUNC(0x4A0890)
void C_TRIBE_Screen_Options::M_4A0890(int a1, int a2, int a3, int a4)
{
    slot_06(0, a1, a2, 0, 0, a3, a3, a4, a4, 0, 0, 0, 0);
}

MATCH_FUNC(0x4A07A0)
void C_TRIBE_Screen_Options::M_4A07A0(int v)
{
    if (field_6C == v)
        return;
    field_6C = v;
    if (v != 0) {
        slot_08(1);
        return;
    }
    this->Hook_4A1CD0();
    if (field_40)
        field_40->Vt_08(1);
}

MATCH_FUNC(0x4A0C60)
void C_TRIBE_Screen_Options::M_4A0C60()
{
    TField20Obj* sub = field_20;
    field_38 = 0;
    if (sub->field_38)
        g_61C06C(sub->field_38, 0);
    field_20->Hook_460660(0);
    field_F7 = 0;
}

MATCH_FUNC(0x407C00)
int C_TRIBE_Screen_Options::M_407C00(int a, int b)
{
    (void)a; (void)b;
    return 0;
}

MATCH_FUNC(0x407C10)
int C_TRIBE_Screen_Options::M_407C10(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    return 0;
}

MATCH_FUNC(0x4237A0)
void C_TRIBE_Screen_Options::M_4237A0()
{
}

MATCH_FUNC(0x4364F0)
int C_TRIBE_Screen_Options::M_4364F0(int a, int b)
{
    (void)a; (void)b;
    return 0;
}

MATCH_FUNC(0x4474F0)
int C_TRIBE_Screen_Options::Get_4474F0()
{
    return *(int*)((char*)this + 0xfc);
}

MATCH_FUNC(0x447500)
int C_TRIBE_Screen_Options::Get_447500()
{
    return *(int*)((char*)this + 0xf8);
}

MATCH_FUNC(0x4A0BB0)
void C_TRIBE_Screen_Options::M_4A0BB0(int v)
{
    field_F6 = 1;
    Vat_34(v);
    field_F6 = 0;
}

MATCH_FUNC(0x4A2040)
void C_TRIBE_Screen_Options::M_4A2040(int a, int b)
{
    field_60 = a;
    field_64 = b;
    field_74 = 1;
}

MATCH_FUNC(0x4A22F0)
void C_TRIBE_Screen_Options::Get_4A22F0(int* out)
{
    out[0] = *(int*)((char*)this + 0x90);
    out[1] = *(int*)((char*)this + 0x94);
    out[2] = *(int*)((char*)this + 0x98);
    out[3] = *(int*)((char*)this + 0x9c);
}

MATCH_FUNC(0x4A3410)
void C_TRIBE_Screen_Options::SetF8_4A3410(int a, int b)
{
    field_F8 = a;
    field_FC = b;
}

MATCH_FUNC(0x5C6890)
int C_TRIBE_Screen_Options::M_5C6890(int a, int b, int c, int d, int e)
{
    (void)a; (void)b; (void)c; (void)d; (void)e;
    return 0;
}

MATCH_FUNC(0x4A0780)
void C_TRIBE_Screen_Options::M_4A0780(unsigned char v)
{
    field_F3 = v;
    if (field_6C)
        slot_08(2);
}

MATCH_FUNC(0x4A2280)
void C_TRIBE_Screen_Options::M_4A2280()
{
    T4A2280Node* n = field_58;
    while (n)
    {
        n->field_0->Vt_56();
        n = n->field_8;
    }
}

MATCH_FUNC(0x4A22D0)
void C_TRIBE_Screen_Options::M_4A22D0()
{
    T4A2280Node* n = field_58;
    while (n)
    {
        n->field_0->Vt_59();
        n = n->field_8;
    }
}

// 0x4A0AB0 — swap the four +0x24 dwords with an incoming four-dword object,
// notify slot +0x30, then restore the original quad.
MATCH_FUNC(0x4A0AB0)
void C_TRIBE_Screen_Options::M_4A0AB0(int* a1)
{
    struct Quad { int a, b, c, d; };
    Quad* q = (Quad*)((char*)this + 0x24);
    Quad old = *q;
    *q = *(Quad*)a1;
    slot_12();
    *q = old;
}

// 0x4A4830 — stage the four a8 copies in a local block and dispatch them with
// a1..a7, a9..a11 and the trailing -1/0 to the +0x11C slot.
WIP_FUNC(0x4A4830)
void C_TRIBE_Screen_Options::M_4A4830(int a1, int a2, int a3, int a4, int a5,
                                      int a6, int a7, int a8, int a9, int a10,
                                      int a11)
{
    struct Quad { int a, b, c, d; };
    Quad block;
    block.a = a8;
    block.b = a8;
    block.c = a8;
    block.d = a8;
    slot_71(a1, a2, a3, a4, a5, a6, a7, (int*)&block, a9, a10, a11, -1, 0);
}

// 0x4A07E0 — thirteen-argument display configuration: store the +0x34,
// +0x44..+0x50 and +0xA0..+0xBC fields in the original emission order, then
// dispatch slot +0x50 with the +0x20 subobject's +0x18/+0x1C pair (or two
// zeros), and notify slot +0x20 with 2 when +0x6C is set.
WIP_FUNC(0x4A07E0)
void C_TRIBE_Screen_Options::M_4A07E0(int a1, int a2, int a3, int a4, int a5,
                                     int a6, int a7, int a8, int a9, int a10,
                                     int a11, int a12, int a13)
{
    field_34 = a1;
    field_A8 = a4;
    field_A4 = a3;
    field_B4 = a7;
    field_A0 = a2;
    field_B0 = a6;
    field_44 = a10;
    field_AC = a5;
    field_BC = a9;
    field_50 = a13;
    field_B8 = a8;
    field_4c = a12;
    field_48 = a11;
    if (field_20 != 0)
        slot_20(field_20->field_18, field_20->field_1c);
    else
        slot_20(0, 0);
    if (field_6C != 0)
        slot_08(2);
}

// 0x4A0630 — rectangle configuration: store the +0x0C/+0x10/+0x14/+0x18
// corners and the +0x90..+0x9C/+0x24..+0x30 copy, clamp against the +0x40
// object's +0x24..+0x30 edges when its +0xF5 byte is set, clamp to the +0x20
// subobject's +0x18/+0x1C bounds and to zero, release the +0x8C handle, then
// allocate it through 0x61C088 while setting +0x70, and notify slot +0x20.
WIP_FUNC(0x4A0630)
void C_TRIBE_Screen_Options::M_4A0630(int a1, int a2, int a3, int a4)
{
    int right = a1 + a3 - 1;
    int bottom = a2 + a4 - 1;
    field_14 = a3;
    field_18 = a4;
    field_c = a1;
    field_10 = a2;
    field_90 = a1;
    field_94 = a2;
    field_98 = right;
    field_9C = bottom;
    field_24[0] = a1;
    field_24[1] = a2;
    field_24[2] = right;
    field_24[3] = bottom;
    R4A0630Target* t = (R4A0630Target*)field_40;
    if (t != 0 && field_F5 != 0)
    {
        if (a1 < t->field_24)
            field_24[0] = t->field_24;
        if (a2 < t->field_28)
            field_24[1] = t->field_28;
        if (right > t->field_2c)
            field_24[2] = t->field_2c;
        if (bottom > t->field_30)
            field_24[3] = t->field_30;
    }
    if (field_24[0] < 0)
        field_24[0] = 0;
    if (field_24[1] < 0)
        field_24[1] = 0;
    if (field_20 != 0 && field_24[2] >= field_20->field_18)
        field_24[2] = field_20->field_18 - 1;
    if (field_20 != 0 && field_24[3] >= field_20->field_1c)
        field_24[3] = field_20->field_1c - 1;
    if (field_8c != 0)
    {
        g_61C098((void*)field_8c);
        field_8c = 0;
    }
    if (field_24[2] >= field_24[0] && field_24[3] >= field_24[1])
    {
        field_70 = 1;
        field_8c = g_61C088(field_24[0], field_24[1], field_24[2],
                            field_24[3]);
    }
    else
    {
        field_70 = 0;
    }
    if (field_6C != 0)
        slot_08(2);
}

// 0x4A2070 — replace the +0x1C name buffer: empty/NULL input frees the buffer
// and clears the pointer; otherwise reuse the buffer when it already fits,
// or free and allocate strlen(input) bytes, then inline-strcpy the text in.
MATCH_FUNC(0x4A2070)
void C_TRIBE_Screen_Options::M_4A2070(char* a1)
{
    if (a1 != 0 && strlen(a1) != 0)
    {
        if (field_1c == 0 || strlen((char*)field_1c) < strlen(a1))
        {
            if (field_1c != 0)
                Free_5F90B0((void*)field_1c);
            field_1c = (int)sub_5F8F80((int)strlen(a1) + 1);
        }
        strcpy((char*)field_1c, a1);
    }
    else if (field_1c != 0)
    {
        Free_5F90B0((void*)field_1c);
        field_1c = 0;
    }
}
#pragma function(strlen)
#pragma function(strcpy)

// 0x4A4570 — format the third argument into a 0x200-byte local buffer through
// 0x4A2140 (which returns 1 on success), then dispatch slot +0x128 with the
// eleven arguments, substituting the buffer for the fourth position.
MATCH_FUNC(0x4A4570)
void C_TRIBE_Screen_Options::M_4A4570(int a1, int a2, int a3, int a4, int a5,
                                      int a6, int a7, int a8, int a9, int a10,
                                      int a11)
{
    char buf[0x200];
    Hook_4A2140(a3, buf, 0x200);
    slot_74(a1, a2, (int)buf, a4, a5, a6, a7, a8, a9, a10, a11);
}
