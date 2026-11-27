#include "C_pnl_inp.hpp"

extern void __cdecl Free_5F90B0(void* p);

extern unsigned char g_73e355;
extern void (__stdcall *g_61C318)(int a1, char* a2);
extern "C" char* __cdecl Hook_5FCB40(char* dst, char* src, int n);

MATCH_FUNC(0x4BBCE0)
void C_pnl_inp::M_4BBCE0(int a1)
{
    this->Hook_4A07A0(a1);
    if (field_14c != 0 && field_148 != 0) {
        T4BBCE0Sub* sub = field_148;
        if (field_6c != 0)
            sub->Vat_14(field_184);
        else
            sub->Vat_14(0);
    }
}

MATCH_FUNC(0x4BD4B0)
char* C_pnl_inp::M_4BD4B0(int index)
{
    int i = 0;
    for (T4BD4B0Node* node = field_f8; node; node = node->next_24)
    {
        if (i == index)
            return (char*)node->field_0;
        i++;
    }
    g_73e355 = 0;
    return (char*)&g_73e355;
}

MATCH_FUNC(0x408050)
void C_pnl_inp::M_408050(int a, int b)
{
    (void)a; (void)b;
}

MATCH_FUNC(0x4B4600)
void C_pnl_inp::SetInt_4B4600(int v)
{
    *(int*)((char*)this + 0x188) = v;
}

MATCH_FUNC(0x4BAF60)
void C_pnl_inp::M_4BAF60(int a, int b, int c, int d)
{
    (void)c; (void)d;
    Vat_f4(a, b);
}

MATCH_FUNC(0x4BCE20)
int C_pnl_inp::M_4BCE20(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    T4BCE20Sub* s = field_40;
    if (s)
        s->Vat_C4(this, 1, 0, 0);
    return 0;
}

// 0x4BADD0 — build a 0x1000-byte stack buffer, pass it through the 0x4A2140
// capture helper, then hand it to vtable slot 0xFC with the zero mode.
MATCH_FUNC(0x4BADD0)
void C_pnl_inp::M_4BADD0(int a1)
{
    char buffer[0x1000];
    Other_4A2140(a1, buffer, 0x1000);
    Vat_fc(buffer, 0);
}

// 0x4BD4E0 — walk the +0xF8 indexed node chain to the matching index and copy
// the +0x00/+0x0C results; when the +0x10 flag is set and both optional output
// pointers exist, copy one of the two +0x14/+0x18 or +0x1C/+0x20 pairs.
MATCH_FUNC(0x4BD4E0)
void C_pnl_inp::M_4BD4E0(int index, void* a2, void* a3, int* a4, int* a5,
                         unsigned char flag)
{
    *(void**)a2 = 0;
    *(void**)a3 = 0;
    int i = 0;
    for (T4BD4B0Node* node = field_f8; node; node = node->next_24)
    {
        if (i == index)
        {
            *(void**)a2 = node->field_0;
            *(void**)a3 = node->field_c;
            if (node->field_10 != 0 && a4 != 0 && a5 != 0)
            {
                if (flag != 0)
                {
                    *a4 = node->field_1c;
                    *a5 = node->field_20;
                }
                else
                {
                    *a4 = node->field_14;
                    *a5 = node->field_18;
                }
            }
        }
        i++;
    }
}

// 0x4BD5F0 — tear down the +0xF8 indexed node chain: free each node's +0x00
// and +0x04 pointers, unlink and free the +0x0C chain through +0x08, then
// release the node itself and continue through +0x24; finally clear +0xF8 and
// the +0xFC word, reset the +0x00 list through 0x4BBD30 and notify slot +0x20.
// WIP: the `if (field_f8)` + local copy form puts the +0xF8 store after
// `pop edi` like the original; the only remaining diff is `this` in ebx
// (ours) vs ebp (original). Tried: self alias, do/while, for, goto, hoisted
// locals, typed chain locals, next/old temp orders -- none move the phase.
WIP_FUNC(0x4BD5F0)
void C_pnl_inp::M_4BD5F0()
{
    if (field_f8 != 0)
    {
        T4BD4B0Node* n = field_f8;
        while (n != 0)
        {
            if (n->field_0 != 0)
                Free_5F90B0(n->field_0);
            if (n->field_4 != 0)
                Free_5F90B0(n->field_4);
            while (n->field_c != 0)
            {
                T4BD5F0Chain* c = (T4BD5F0Chain*)n->field_c;
                void* next = c->next_8;
                Free_5F90B0(n->field_c);
                n->field_c = next;
            }
            T4BD4B0Node* old = n;
            n = n->next_24;
            Free_5F90B0(old);
        }
        field_f8 = n;
    }
    field_fc = 0;
    Hook_4BBD30(1);
    slot_008(1);
}

// 0x4BBC20 — store the first argument at +0x188, the six byte arguments at
// +0x18C/+0x18D/+0x18E/+0x18F/+0x190/+0x191, then select +0x198 from the
// (a1-1) switch: 1 for indices 0/1/4, 2 for 2/5, 3 for 3/6 and 0 otherwise;
// finish by pushing 1 through 0x4BBD30.
MATCH_FUNC(0x4BBC20)
void C_pnl_inp::M_4BBC20(int a1, char a2, char a3, char a4, char a5, char a6, char a7)
{
    field_188 = a1;
    field_18c = a2;
    field_18d = a3;
    field_18e = a4;
    field_18f = a5;
    field_190 = a6;
    field_191 = a7;
    switch (a1 - 1)
    {
    case 0:
    case 1:
    case 4:
        field_198 = 1;
        break;
    case 2:
    case 5:
        field_198 = 2;
        break;
    case 3:
    case 6:
        field_198 = 3;
        break;
    default:
        field_198 = 0;
        break;
    }
    Hook_4BBD30(1);
}

#pragma intrinsic(memset)

// 0x4B3160 — string setter: when +0xF8 is set, clear the +0x100 buffer of the
// signed +0xFC capacity, copy up to capacity-1 bytes from the argument through
// 0x5FCB40, terminate, store the measured length at +0x104; a null argument
// clears the first byte and length. Then notify 61C318(+0xF8, buffer), clear
// +0x150 and always dispatch slot +0x20 with 1.
MATCH_FUNC(0x4B3160)
void C_pnl_inp::M_4B3160(char* a2)
{
    if (field_f8 != 0)
    {
        if (a2 != 0)
        {
            memset(field_100, 0, field_fc);
            Hook_5FCB40(field_100, a2, field_fc - 1);
            field_100[field_fc - 1] = 0;
            field_104 = strlen(field_100);
        }
        else
        {
            *(char*)field_100 = 0;
            field_104 = 0;
        }
        g_61C318((int)field_f8, field_100);
        field_150 = 0;
    }
    slot_008(1);
}

#pragma function(memset)

// Callee owners reached from the +0x40 subobject (duplicated as minimal class
// declarations so the mangled symbols resolve to the matched bodies).
class C_cluster_47DA00 { public: int Get_47DA00(); };
class S49F620 { public: int Get_49F620(); };
class C_TRIBE_Screen_Options {
public:
    void M_4A0630(int a1, int a2, int a3, int a4);
};

extern int (__stdcall *g_61C088)(int a1, int a2, int a3, int a4);
extern int (__stdcall *g_61C098)(void* a1);

extern void __cdecl Free_5F90B0(void* p);

// 0x4BA410 — panel-input update. Seed +0x0C/+0x10/+0x14/+0x18 through
// M_4A0630. When +0x14C is set, copy +0x14 into +0x17C and, with a +0x148
// subobject, notify its slot +0x14 with 0 and clear +0x184; compute the +0xC
// and +0x10 deltas through the +0x40 subobject when present (else use the raw
// values), then dispatch the +0x148 slot +0x1C with (span, delta10, +0x180,
// +0x18). Afterwards call 0x4BBD30(1). When +0x178 is set, release +0x194
// through 0x61C098 and clear it; with +0x70 set, build ( +0x24, +0x28,
// clamp(+0x90 + +0x178 - 0xA, +0x2C), +0x30) and allocate through 0x61C088
// into +0x194.
WIP_FUNC(0x4BA410)
void C_pnl_inp::M_4BA410(int a1, int a2, int a3, int a4)
{
    ((C_TRIBE_Screen_Options*)this)->M_4A0630(a1, a2, a3, a4);
    if (field_14c != 0)
    {
        *(int*)((char*)this + 0x17c) = *(int*)((char*)this + 0x14);
        if (field_148 != 0)
        {
            field_148->Vat_14(0);
            *(int*)((char*)this + 0x184) = 0;
            int d0c;
            int d10;
            if (field_40 != 0)
            {
                d0c = *(int*)((char*)this + 0xc) -
                      ((C_cluster_47DA00*)field_40)->Get_47DA00();
                d10 = *(int*)((char*)this + 0x10) -
                      ((S49F620*)field_40)->Get_49F620();
            }
            else
            {
                d0c = *(int*)((char*)this + 0xc);
                d10 = *(int*)((char*)this + 0x10);
            }
            int base = *(int*)((char*)this + 0x180);
            int h = *(int*)((char*)this + 0x90) + *(int*)((char*)this + 0x178) - 0xa;
            int lim = *(int*)((char*)this + 0x2c);
            if (h > lim)
                h = lim;
            int span = *(int*)((char*)this + 0x17c) - base + d0c;
            field_148->Vat_1c(span, d10, base, *(int*)((char*)this + 0x18));
        }
    }
    Hook_4BBD30(1);
    if (*(int*)((char*)this + 0x178) != 0)
    {
        if (*(int*)((char*)this + 0x194) != 0)
        {
            g_61C098((void*)*(int*)((char*)this + 0x194));
            *(int*)((char*)this + 0x194) = 0;
        }
        if (*(int*)((char*)this + 0x70) != 0)
        {
            int x0 = *(int*)((char*)this + 0x24);
            int x1 = *(int*)((char*)this + 0x28);
            int x3 = *(int*)((char*)this + 0x30);
            int h = *(int*)((char*)this + 0x90) + *(int*)((char*)this + 0x178) - 0xa;
            int lim = *(int*)((char*)this + 0x2c);
            if (h > lim)
                h = lim;
            *(int*)((char*)this + 0x194) = g_61C088(x0, x1, h, x3);
        }
    }
}

// Minimal +0x40 view whose slot +0x20 takes one argument (the release mode).
class TField40Slot8 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void slot_008(int a1);
};

class C_cluster_4BAE20 {
public:
    void M_4BCF90(int a1, int a2, int a3);
};

extern char* __cdecl sub_5FF4EC(char* a1, int a2);   // CRT strchr-like (exempt band)

// 0x4BA5C0 — text splitter over the input buffer. Bump +0xE4, notify the +0x40
// subobject slot 8 with 1, then dispatch slot +0x120. With a null a1 it returns
// when the +0x150 word is zero, else feeds (0x662BE0, 0, 0) to 0x4BCF90; with an
// empty a1 it feeds the same. Otherwise, when +0x12C is clear and +0x124 is not
// 6, it splits a1 on '\n' (sub_5FF4EC): each segment is copied into a 0x100
// buffer (Hook_5FCB40), terminated, and fed to 0x4BCF90(buffer, 0, 0); after the
// last segment it feeds (remainder, 0, a2). When +0x12C is set or +0x124 is 6,
// it word-wraps a1 through Hook_4BA810(a1, a2, 0) and frees a2's +0x08 chain.
WIP_FUNC(0x4BA5C0)
void C_pnl_inp::M_4BA5C0(char* a1, char* a2)
{
    char buf[0x100];
    *(int*)((char*)this + 0xe4) = *(int*)((char*)this + 0xe4) + 1;
    if (field_40 != 0)
        ((TField40Slot8*)field_40)->slot_008(1);
    Vat_120();
    if (a1 == 0)
    {
        if (*(short*)((char*)this + 0x150) == 0)
            goto done;
        ((C_cluster_4BAE20*)this)->M_4BCF90(0x662be0, 0, 0);
        return;
    }
    if (*a1 == 0)
    {
        ((C_cluster_4BAE20*)this)->M_4BCF90(0x662be0, 0, 0);
        return;
    }
    short n;
    if (*(int*)((char*)this + 0x12c) == 0 &&
        *(int*)((char*)this + 0x124) != 6)
    {
        char* nl;
split_cond:
        nl = sub_5FF4EC(a1, 0xa);
        if (nl == 0)
            goto split_done;
        n = (short)(nl - a1);
        Hook_5FCB40(buf, a1, n);
        buf[n] = 0;
        ((C_cluster_4BAE20*)this)->M_4BCF90((int)buf, 0, 0);
        a1 = nl + 1;
        goto split_cond;
split_done:
        ((C_cluster_4BAE20*)this)->M_4BCF90((int)a1, 0, (int)a2);
        return;
    }
    Hook_4BA810(a1, a2, 0);
    while (a2 != 0)
    {
        void* next = *(void**)((char*)a2 + 8);
        Free_5F90B0(a2);
        a2 = (char*)next;
    }
done:
    ;
}
