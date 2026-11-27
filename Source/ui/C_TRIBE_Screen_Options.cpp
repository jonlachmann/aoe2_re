#include "C_TRIBE_Screen_Options.hpp"
#include "matched_mem.h"
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

// 0x4A4830 — fill a four-int local block with a8 (a loop: explicit stores
// sink below the pushes) and dispatch it with a1..a7, a9..a11 and the trailing
// -1/0 to the +0x11C slot.
MATCH_FUNC(0x4A4830)
void C_TRIBE_Screen_Options::M_4A4830(int a1, int a2, int a3, int a4, int a5,
                                      int a6, int a7, int a8, int a9, int a10,
                                      int a11)
{
    int block[4];
    for (int i = 0; i < 4; i++)
        block[i] = a8;
    slot_71(a1, a2, a3, a4, a5, a6, a7, block, a9, a10, a11, -1, 0);
}

// 0x4A07E0 — thirteen-argument display configuration: store the +0x34,
// +0xA0..+0xBC and +0x44..+0x50 fields in argument order, then
// dispatch slot +0x50 with the +0x20 subobject's +0x18/+0x1C pair (or two
// zeros), and notify slot +0x20 with 2 when +0x6C is set.
MATCH_FUNC(0x4A07E0)
void C_TRIBE_Screen_Options::M_4A07E0(int a1, int a2, int a3, int a4, int a5,
                                     int a6, int a7, int a8, int a9, int a10,
                                     int a11, int a12, int a13)
{
    field_34 = a1;
    field_A0 = a2;
    field_A4 = a3;
    field_A8 = a4;
    field_AC = a5;
    field_B0 = a6;
    field_B4 = a7;
    field_B8 = a8;
    field_BC = a9;
    field_44 = a10;
    field_48 = a11;
    field_4c = a12;
    field_50 = a13;
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
MATCH_FUNC(0x4A0630)
void C_TRIBE_Screen_Options::M_4A0630(int a1, int a2, int a3, int a4)
{
    field_c = a1;
    field_10 = a2;
    field_14 = a3;
    field_18 = a4;
    int right = a1 + a3 - 1;
    int bottom = a2 + a4 - 1;
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

// 0x4A3D40 — format the third and fourth arguments into two 0x78-byte local
// buffers through 0x4A2140, then dispatch slot +0x108 (slot 66) with both
// buffers following the first two arguments.
MATCH_FUNC(0x4A3D40)
void C_TRIBE_Screen_Options::M_4A3D40(int a1, int a2, int a3, int a4, int a5,
                                      int a6, int a7, int a8, int a9, int a10,
                                      int a11)
{
    char buf1[0x78];
    char buf2[0x78];
    Hook_4A2140(a3, buf1, 0x78);
    Hook_4A2140(a4, buf2, 0x78);
    slot_66(a1, a2, (int)buf1, (int)buf2, a5, a6, a7, a8, a9, a10, a11);
}

// 0x4A0460 — seven-argument init: store the +0x40 subobject pointer, conditionally
// seed the +0xA0..+0xBC block only when +0x34 is clear, set +0x20 and dispatch
// slot +0x50 with the +0x20 subobject's (field_18, field_1C) pair (or zeros),
// notify slot +0x04 with a7, clear +0x68, and lazily allocate the +0x54
// 0xC-byte node through 0x5F8FF0(1,0xC); on success set node->this/0/0 and run
// the +0x40 object's 0x4A0530(node,0,0) when +0x40 is set. Returns 1, or 0 when
// the node allocation fails.
extern void* __cdecl sub_5F8FF0(unsigned int a1, int a2);
MATCH_FUNC(0x4A0460)
int C_TRIBE_Screen_Options::M_4A0460(int a1, int a2, int a3, int a4, int a5,
                                     int a6, int a7)
{
    *(int*)((char*)this + 0x40) = a2;
    *(int*)((char*)this + 0x20) = a1;
    if (*(int*)((char*)this + 0x34) == 0)
    {
        *(int*)((char*)this + 0xa0) = a3;
        *(int*)((char*)this + 0xa4) = a4;
        *(int*)((char*)this + 0xb0) = a5;
        *(int*)((char*)this + 0xb4) = a5;
        *(int*)((char*)this + 0xa8) = 0;
        *(int*)((char*)this + 0xac) = 0;
        *(int*)((char*)this + 0xb8) = a6;
        *(int*)((char*)this + 0xbc) = a6;
    }
    TField20Obj* p20 = (TField20Obj*)a1;
    if (p20 != 0)
        slot_20(p20->field_18, p20->field_1c);
    else
        slot_20(0, 0);
    slot_04(a7);
    int* existing = (int*)field_54;
    field_68 = 0;
    if (existing == 0)
    {
        int* n = (int*)sub_5F8FF0(1, 0xc);
        field_54 = n;
        if (n == 0)
            return 0;
        *n = (int)this;
        *(int*)((char*)field_54 + 4) = 0;
        *(int*)((char*)field_54 + 8) = 0;
        if (*(int*)((char*)this + 0x40) != 0)
            ((T4A2280Obj*)*(int*)((char*)this + 0x40))->M_4A0530(
                (int)field_54, 0, 0);
    }
    return 1;
}

// Helpers for the shared slot +0x48 input dispatcher (0x4A0CD0).
class S49GetBulk { public: int Get_49FFA0(); };
class S47D9F0 { public: int Get_47D9F0(); };
class C_cluster_47DA00 { public: int Get_47DA00(); };
class C_vt61CE24 { public: int Get_48F970(); };
extern "C" int __stdcall GetKeyState(int vk);

// 0x4A1C10 — split a packed short pair into the two caller-provided outputs:
// the low word goes to a3[0] and the high word to a3[1], each corrected by
// -0x10000 when above 0xEA60; the first argument's bit 4 goes to a5 and bit 8
// to a4 (both masks stored in that order). Five stack arguments (`ret 0x14`).
MATCH_FUNC(0x4A1C10)
int __stdcall sub_4A1C10(int a1, unsigned int a2, int* a3, int* a4, int* a5)
{
    int lo = (unsigned short)a2;
    int hi = (unsigned short)(a2 >> 16);
    *a3 = lo;
    a3[1] = hi;
    if (lo > 0xea60)
        *a3 = lo - 0x10000;
    if (hi > 0xea60)
        a3[1] = hi - 0x10000;
    *a4 = a1 & 8;
    *a5 = a1 & 4;
    return a1 & 4;
}

// 0x4A0CD0 (slot +0x48) — shared screen input dispatcher. It returns 0 when
// the +0x6C field is clear. Keyboard/char messages (<= 0x104) route to the
// focused input target's +0x58/+0x5C slots, with modifier bits from
// GetKeyState(18/17/16). Mouse messages (0x200..0x20D) split the packed
// coordinates through 0x4A1C10 and dispatch the matching +0x70..+0x88 target
// slot, including wheel cases 0x20A..0x20C. Every other message walks the
// +0x5C node chain, calling each node object's slot +0x48 and stopping on the
// first non-zero result; when the chain ends it falls back to the owner's
// +0x60/+0x64/+0x68/+0x6C slots for non-mouse input. WIP: the original keeps
// separate `this`, `v16`, `v8` pointers and folds both guards into shared
// epilogues; this reconstruction keeps the same behaviour but the compiler
// shape (and full 0x450 bytes) is not reproduced.
WIP_FUNC(0x4A0CD0)
int C_TRIBE_Screen_Options::M_4A0CD0(int a2, unsigned a3, unsigned a4, int a5)
{
    int* self = (int*)this;
    if (self[27] == 0)
        return 0;
    unsigned v6 = a3;
    int v7 = a5;

    if (a3 <= 0x104)
    {
        if (a3 != 0x104 && a3 != 0x100 && a3 != 0x102)
            goto LABEL_7;
        goto LABEL_42;
    }
    if (a3 >= 0x200 && a3 <= 0x20d)
    {
        if (a2 != *(int*)(self[8] + 4)
            || ((S49GetBulk*)ADDR(0x66ea48))->Get_49FFA0() == 0)
            return 0;
        int v17 = 0;
        int v18 = 0;
        int alt = a5;
        unsigned shift = a3;
        sub_4A1C10((char)a4, v7, &v17, &alt, (int*)&shift);
        int v13;
        if (((C_vt61CE24*)ADDR(0x66ea48))->Get_48F970() != 0)
            v13 = ((C_vt61CE24*)ADDR(0x66ea48))->Get_48F970();
        else if (((S47D9F0*)ADDR(0x66ea48))->Get_47D9F0() != 0)
            v13 = ((S47D9F0*)ADDR(0x66ea48))->Get_47D9F0();
        else if (((C_cluster_47DA00*)ADDR(0x66ea48))->Get_47DA00() != 0)
            v13 = ((C_cluster_47DA00*)ADDR(0x66ea48))->Get_47DA00();
        else
            v13 = (int)(size_t)self;
        int result;
        switch (v6)
        {
        case 0x200:
            result = ((TInputDisp*)v13)->Vt_29(v17, v18, alt, (int)shift);
            break;
        case 0x201:
            result = ((TInputDisp*)v13)->Vt_28(1, v17, v18, alt, (int)shift);
            break;
        case 0x202:
            result = ((TInputDisp*)v13)->Vt_30(1, v17, v18, alt, (int)shift);
            break;
        case 0x203:
            result = ((TInputDisp*)v13)->Vt_31(1, v17, v18, alt, (int)shift);
            break;
        case 0x204:
            result = ((TInputDisp*)v13)->Vt_28(2, v17, v18, alt, (int)shift);
            break;
        case 0x205:
            result = ((TInputDisp*)v13)->Vt_30(2, v17, v18, alt, (int)shift);
            break;
        case 0x206:
            result = ((TInputDisp*)v13)->Vt_31(2, v17, v18, alt, (int)shift);
            break;
        case 0x207:
            result = ((TInputDisp*)v13)->Vt_28(3, v17, v18, alt, (int)shift);
            break;
        case 0x208:
            result = ((TInputDisp*)v13)->Vt_30(3, v17, v18, alt, (int)shift);
            break;
        case 0x209:
            result = ((TInputDisp*)v13)->Vt_31(3, v17, v18, alt, (int)shift);
            break;
        case 0x20a:
            result = ((TInputDisp*)v13)->Vt_32(v6, a4, v7);
            break;
        case 0x20b:
        case 0x20c:
            result = ((TInputDisp*)v13)->Vt_34(v6, a4, v7);
            break;
        default:
            goto LABEL_42;
        }
        return result;
    }

LABEL_7:
    {
        void* v8 = (void*)(size_t)self[23];
        int v9 = a5;
        unsigned v10 = a4;
        while (v8 != 0)
        {
            int result = ((TInputDisp*)*(void**)v8)->Vt_18(a2, v6, v10, v9);
            if (result != 0)
                return result;
            v8 = *(void**)((char*)v8 + 4);
        }
        if (v6 > 0x115)
        {
            if (v6 == 1024)
                return ((TInputDisp*)self)->Vt_25(v10, v9);
        }
        else
        {
            if (v6 >= 0x114)
                return ((TInputDisp*)self)->Vt_27((int)(unsigned short)v10,
                                                (int)(v10 >> 16));
            unsigned v11 = v6 - 273;
            if (v11 == 0)
                return ((TInputDisp*)self)->Vt_24(v10, v9);
            if (v11 == 2)
                return ((TInputDisp*)self)->Vt_26(v10, v9);
        }
        return 0;
    }

LABEL_42:
    {
        unsigned v12 = a4;
        if (a2 == *(int*)(self[8] + 4)
            && ((S49GetBulk*)ADDR(0x66ea48))->Get_49FFA0() != 0)
        {
            int v14;
            if (((S47D9F0*)ADDR(0x66ea48))->Get_47D9F0() != 0)
                v14 = ((S47D9F0*)ADDR(0x66ea48))->Get_47D9F0();
            else if (((C_cluster_47DA00*)ADDR(0x66ea48))->Get_47DA00() != 0)
                v14 = ((C_cluster_47DA00*)ADDR(0x66ea48))->Get_47DA00();
            else
                v14 = (int)(size_t)self;
            if (v6 != 0x100 && v6 != 0x104)
                return ((TInputDisp*)v14)->Vt_23(v12, v7);
            int menuctrl = GetKeyState(18) < 0;
            int menualt = GetKeyState(17) < 0;
            int menushift = GetKeyState(16) < 0;
            return ((TInputDisp*)v14)->Vt_22(v12, v7, menuctrl, menualt, menushift);
        }
        return 0;
    }
}
