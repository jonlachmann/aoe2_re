#include "C_pnl_pic.hpp"

extern int (__cdecl *g_61C3C8)();

class T4A1160NodeObj {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
    virtual void Vt_09();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual int Vt_19();
};
class T4A1160Node {
public:
    T4A1160NodeObj* field_0;
    T4A1160Node* field_4;
};

// 0x4A1160 — advance the +0xF0 state machine when the +0x6C subobject and
// one-shot state are present, dispatching by the +0xF1 mode, then scan the
// +0x5C chain for the first object whose slot +0x4C reports success.
MATCH_FUNC(0x4A1160)
int C_pnl_pic::M_4A1160()
{
    if (field_6c != 0 && field_f0 == 1)
    {
        int t = g_61C3C8();
        if ((t - field_d8) >= field_c0)
        {
            field_f0 = 2;
            if (field_f1 == 1)
                slot_038(field_c8, field_cc, field_d0, field_d4);
            else
                slot_043(field_c8, field_cc, field_d0, field_d4);
        }
    }
    for (T4A1160Node* n = (T4A1160Node*)field_5c; n; n = n->field_4)
    {
        int r = n->field_0->Vt_19();
        if (r != 0)
            return r;
    }
    return 0;
}

// 0x4B8510 — tick a picture panel: when the +0x21C gate is set and the elapsed
// time since +0x22C reaches the +0x228 threshold, advance the +0x218 phase
// counter (wrapping at +0x224), drive slot +0x20 with one and stamp the clock
// into +0x22C; then forward the same-object 0x4A1160 update.
MATCH_FUNC(0x4B8510)
void C_pnl_pic::M_4B8510()
{
    if (field_21c != 0)
    {
        int t = g_61C3C8();
        unsigned int diff = (unsigned int)(t - field_22c);
        if (diff >= (unsigned int)field_228)
        {
            int phase = field_218;
            if (phase == field_224)
                field_218 = 0;
            else
                field_218 = phase + 1;
            slot_008(1);
            field_22c = t;
        }
    }
    M_4A1160();
}

// 0x4B88B0 — configure the display geometry: the +0x1B8 mode, the +0x120/
// +0x124 slot pair, the +0xF8/+0xFC range pair, then dispatch the seven
// plus-zero arguments to the +0x00 base initialiser 0x4A0460.
MATCH_FUNC(0x4B88B0)
int C_pnl_pic::M_4B88B0(int a1, int a2, int a3, int a4, int a5, int a6,
                        int a7, int a8, int a9, int a10, int a11, int a12,
                        int a13, int a14, int a15)
{
    field_1b8 = a15;
    field_120 = a11;
    field_124 = a12;
    field_f8 = a13;
    field_fc = a14;
    M_4A0460(a1, a2, a3, a4, a5, a6, 0);
    return 1;
}

// 0x4B8A80 — recompute the display geometry slots from the current +0x1B8 mode
// (1 uses +0x138/+0x18/+0x170/+0x178, otherwise +0x128/+0x14/+0x174/+0x17C).
MATCH_FUNC(0x4B8A80)
void C_pnl_pic::M_4B8A80()
{
    if (field_1b8 == 1)
    {
        field_188 = field_138;
        field_190 = field_18 + field_138 - 5;
        field_198 = field_170 + 1;
        field_1a0 = field_138 - 1;
        field_1a8 = field_190 + 1;
        field_1b0 = field_178 - 1;
        return;
    }
    field_18c = field_128;
    field_194 = field_14 + field_128 - 5;
    field_19c = field_174 + 1;
    field_1a4 = field_128 - 1;
    field_1ac = field_194 + 1;
    field_1b4 = field_17c - 1;
}

// 0x4B83D0 — release the owned +0x210/+0x214 objects when the +0x208 gate is
// set, then clear all three.
class T4B83D0Obj210 {
public:
    void M_4A9CA0();
};
class T4B83D0Obj214 {
public:
    void M_51EAE0();
};
extern void __cdecl sub_5F90B0(void* a1);
extern void* __cdecl sub_5F8FF0(unsigned int a1, int a2);
extern int __cdecl sub_5FCB40(void* dst, void* src, int n);
extern char* __cdecl sub_5FEE50(char* a1, int a2);

MATCH_FUNC(0x4B83D0)
void C_pnl_pic::M_4B83D0()
{
    void* p = field_210;
    if (p != 0)
    {
        if (field_208 != 0 && field_210 != 0)
        {
            ((T4B83D0Obj210*)field_210)->M_4A9CA0();
            sub_5F90B0(p);
        }
        field_210 = 0;
    }
    p = field_214;
    if (p != 0)
    {
        if (field_208 != 0 && field_214 != 0)
        {
            ((T4B83D0Obj214*)field_214)->M_51EAE0();
            sub_5F90B0(p);
        }
        field_214 = 0;
    }
    field_208 = 0;
}

// 0x4B7F20 — panel-picture reset constructor: run the base 0x4A0270 init and
// clear the +0x200/+0x208..+0x240 block (keeping +0x204 = 1), write the
// 0x622D6C vtable pointer, set the +0xF2 mode byte to 2 and +0x1FC to -1.
MATCH_FUNC(0x4B7F20)
C_pnl_pic* C_pnl_pic::M_4B7F20()
{
    this->Hook_4A0270();
    field_204 = 1;
    field_200 = 0;
    field_208 = 0;
    field_20c = 0;
    field_210 = 0;
    field_214 = 0;
    field_80 = 0;
    ((unsigned char*)this)[0xf8] = 0;
    field_218 = 0;
    field_21c = 0;
    field_220 = 0;
    field_224 = 0;
    field_228 = 0;
    field_22c = 0;
    field_230 = 0;
    field_234 = 0;
    field_238 = 0;
    field_23c = 0;
    field_23d = 0;
    field_240 = 0;
    *(int*)this = 0x622D6C;
    field_f2 = 2;
    field_1fc = -1;
    return this;
}

// 0x4B9D80 — setter forwarding 14 arguments to 0x4B88B0: record the +0x1C8/
// +0x1CC pair from the last two arguments, forward the rest with five zeros
// inserted at positions 8, 9, 11, 13 and 15; on success store the +0x100/
// +0x104 pair from the middle arguments and return 1, otherwise return 0.
MATCH_FUNC(0x4B9D80)
int C_pnl_pic::M_4B9D80(int a1, int a2, int a3, int a4, int a5, int a6,
                        int a7, int a8, int a9, int a10, int a11, int a12,
                        int a13, int a14)
{
    field_1c8 = a13;
    field_1cc = a14;
    if (M_4B88B0(a1, a2, a3, a4, a5, a6, a7, 0, 0, a8, 0, a9, 0, a10, 0) == 0)
        return 0;
    field_100 = a11;
    field_104 = a12;
    return 1;
}

// 0x4AF510 — free and rebuild the a2-indexed +0x1A4/+0x1C8 string pair. Release
// both current pointers through 0x5F90B0 and clear them, then when a non-empty
// Source is present split it at the first newline: the +0x1A4 buffer gets the
// prefix (newline-terminated; or the whole string when no newline), and, only
// when a newline exists, the +0x1C8 buffer gets the suffix after it including
// its terminator. Allocation is through 0x5F8FF0 as (len+1, 1), prefix copy
// through 0x5FCB40 and suffix inline-copy via strcpy. Always finish by
// dispatching vtable slot +0x20 with 1 and returning its result.
MATCH_FUNC(0x4AF510)
#pragma intrinsic(strlen)
#pragma intrinsic(strcpy)
int C_pnl_pic::M_4AF510(__int16 a2, char* Source)
{
    if (((int*)this)[a2 + 105])
    {
        sub_5F90B0((void*)((int*)this)[a2 + 105]);
        ((int*)this)[a2 + 105] = 0;
    }
    if (((int*)this)[a2 + 114])
    {
        sub_5F90B0((void*)((int*)this)[a2 + 114]);
        ((int*)this)[a2 + 114] = 0;
    }
    if (Source != 0 && *Source != 0)
    {
        char* v4 = sub_5FEE50(Source, 10);
        char* v5 = v4;
        __int16 v6;
        if (v4 != 0)
            v6 = (__int16)(v4 - Source);
        else
            v6 = (__int16)strlen(Source);
        size_t v7 = v6;
        char* v8 = (char*)sub_5F8FF0(v6 + 1, 1);
        ((int*)this)[a2 + 105] = (int)v8;
        if (v8 != 0)
        {
            sub_5FCB40(v8, Source, (int)v7);
            ((char*)((int*)this)[a2 + 105])[v7] = 0;
            if (v5 != 0)
            {
                char* v9 = v5 + 1;
                char* v10 = (char*)sub_5F8FF0(strlen(v9) + 1, 1);
                ((int*)this)[a2 + 114] = (int)v10;
                if (v10 != 0)
                    strcpy(v10, v9);
            }
        }
    }
    return slot_008(1);
}
#pragma function(strcpy)
#pragma function(strlen)
#pragma function(strlen)
