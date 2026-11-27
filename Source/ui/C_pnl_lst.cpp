#include "C_pnl_lst.hpp"

extern "C" int __stdcall sub_4BCF50(int v);
extern int (__stdcall *g_61C3C8)();

MATCH_FUNC(0x4B6840)
int __stdcall C_pnl_lst::M_4B6840(int v)
{
    return sub_4BCF50(v) >= 0;
}

MATCH_FUNC(0x4BCEB0)
void C_pnl_lst::M_4BCEB0(short v)
{
    field_104 = v;
    Other_4BBD30(1);
}

// 0x4BAE20 — panel-list slot +0xF4: drive slot +0x120, then either re-add the
// +0x662BE0 registration when +0x150 is clear or re-add each element of an
// incoming array for the short count.
MATCH_FUNC(0x4BAE20)
void C_pnl_lst::M_4BAE20(int* a1, short a2)
{
    slot_072();
    if (a2 == 0)
    {
        if (field_150 != 0)
            Other_4BCF90(0x662be0, 0, 0);
        return;
    }
    if (a2 <= 0)
        return;
    while (a2 > 0)
    {
        Other_4BCF90(*a1, 0, 0);
        a1++;
        a2--;
    }
}

// 0x4B5A10 — set the +0x19C display mode from the seven-case argument, forward
// all seven arguments to 0x4BBC20, then activate +0x198 once with 0x4BBD30.
MATCH_FUNC(0x4B5A10)
void C_pnl_lst::M_4B5A10(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    switch (a1)
    {
    case 1:
    case 2:
    case 5:
        field_19c = 1;
        break;
    case 3:
    case 6:
        field_19c = 2;
        break;
    case 4:
    case 7:
        field_19c = 3;
        break;
    default:
        field_19c = 1;
        break;
    }
    M_4BBC20(a1, a2, a3, a4, a5, a6, a7);
    if (field_198 == 0)
    {
        field_198 = 1;
        Other_4BBD30(1);
    }
}

// 0x4B3760 — seven-argument display configuration: store +0x154 and the six
// +0x158..+0x15D bytes, map the first argument to +0x160 (1/2/5 -> 1,
// 3/6 -> 2, 4/7 -> 3, otherwise 0 — the 0x4B3808 table groups a1-1 values
// 0/1/4 -> 1, 2/5 -> 2 and 3/6 -> 3), propagate the four +0x0C..+0x18 values
// through slot +0x0C, then notify through slot +0x20 with 1.
MATCH_FUNC(0x4B3760)
void C_pnl_lst::M_4B3760(int a1, unsigned char a2, unsigned char a3, unsigned char a4,
                         unsigned char a5, unsigned char a6, unsigned char a7)
{
    field_154 = a1;
    field_158 = a2;
    field_159 = a3;
    field_15a = a4;
    field_15b = a5;
    field_15c = a6;
    field_15d = a7;
    switch (a1 - 1)
    {
    case 0:
    case 1:
    case 4:
        field_160 = 1;
        break;
    case 2:
    case 5:
        field_160 = 2;
        break;
    case 3:
    case 6:
        field_160 = 3;
        break;
    default:
        field_160 = 0;
        break;
    }
    slot_003(field_c, field_10, field_14, field_18);
    slot_008(1);
}

// 0x4B5AB0 — tick gate: run the 0x4A1160 update, return 0 when both +0x1B4/
// +0x1B8 are clear or the unsigned elapsed time since +0x1AC is still below
// the +0x1B0 interval; on expiry record the current tick, then when +0x1B4 is
// set re-sync +0x104 from the +0x100 word and dispatch the 3-arg slot 3 call,
// otherwise re-sync from the +0x102 word and dispatch slot 2.
MATCH_FUNC(0x4B5AB0)
int C_pnl_lst::M_4B5AB0()
{
    Hook_4A1160();
    if (field_1b4 == 0 && field_1b8 == 0)
        return 0;
    unsigned int now = (unsigned int)g_61C3C8();
    if ((now - (unsigned int)field_1ac) < (unsigned int)field_1b0)
        return 0;
    field_1ac = (int)now;
    if (field_1b4 != 0)
    {
        short v = field_100;
        if (field_104 != v)
            Hook_4B60B0(1, v, 1);
        Hook_4B60B0(3, 0, 1);
    }
    else
    {
        short v = field_102;
        if (field_104 != v)
            Hook_4B60B0(1, v, 1);
        Hook_4B60B0(2, 0, 1);
    }
    return 0;
}

// 0x4B5690 — flush the +0x1C0 subobject through 0x4BA5C0, clamp both captured
// +0x100/+0x104 shorts against +0xFC-1, store the clamped +0x104, dispatch the
// short-argument 0x4BBF20 setter with the original +0x100 word, then notify
// slot +0x20 with 1.
MATCH_FUNC(0x4B5690)
void C_pnl_lst::M_4B5690()
{
    short old100 = field_100;
    short old104 = field_104;
    Hook_4BA5C0(field_1c0, 0);
    short lim = field_fc;
    if (old104 >= lim)
        old104 = lim - 1;
    field_104 = old104;
    if (old100 >= lim)
        field_100 = lim - 1;
    M_4BBF20(1, old100, 1);
    slot_008(1);
}

// 0x4BA390 — fill a four-int temporary with the seventh argument (a loop:
// the unrolled stores schedule differently), then forward to the thiscall
// 0x4BA250 with the temporary in place of a7 and a8..a17 unchanged.
MATCH_FUNC(0x4BA390)
void C_pnl_lst::M_4BA390(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                         int a8, int a9, int a10, int a11, int a12, int a13,
                         int a14, int a15, int a16, int a17)
{
    int tmp[4];
    for (int i = 0; i < 4; i++)
        tmp[i] = a7;
    Hook_4BA250(a1, a2, a3, a4, a5, a6, tmp, a8, a9, a10, a11, a12, a13,
                a14, a15, a16, a17);
}

// 0x4BBF20 — switch on the low byte of the first argument to adjust the
// +0x100 word (adding/assigning the second short for 0/1, stepping it for 2/3,
// applying the +0xFE-derived deltas for 4/5, zeroing for 6 and clamping to
// +0xFC-1 for 7), then re-sync through 0x4BBD30(a3) and notify slot +0x20.
// The body is followed by the VC6 `lea ecx,[ecx]` (8D 49 00) jump-table
// alignment pad and the 8-entry table at 0x4BBFBC, as in the original.
MATCH_FUNC(0x4BBF20)
void C_pnl_lst::M_4BBF20(int a1, short a2, int a3)
{
    switch (a1 & 0xff)
    {
    case 0:
        field_100 += a2;
        break;
    case 1:
        field_100 = a2;
        break;
    case 2:
        field_100++;
        break;
    case 3:
        field_100--;
        break;
    case 4:
        field_100 += field_fe - 1;
        break;
    case 5:
        field_100 += 1 - field_fe;
        break;
    case 6:
        field_100 = 0;
        break;
    case 7:
        field_100 = field_fc - 1;
        break;
    }
    Other_4BBD30(a3);
    slot_008(1);
}

// 0x4BA190 — the sixteen-argument sibling of 0x4BA250: same 0x4A0460 seed and
// field stores, then the +0xFC slot with (a16,0) instead of the +0xF4 slot,
// zero arguments for 0x4BB9E0, and 0x4BBAE0(a10,-1).
MATCH_FUNC(0x4BA190)
int C_pnl_lst::M_4BA190(int a1, int a2, int a3, int a4, int a5, int a6, int* a7,
                        int a8, int a9, int a10, int a11, int a12, int a13,
                        int a14, int a15, int a16)
{
    M_4A0460(a1, a2, a3, a4, a5, a6, 0);
    field_164 = a11;
    field_168 = (unsigned char)a12;
    field_16c = a13;
    field_170 = (unsigned char)a14;
    field_150 = (short)a15;
    if (a13 != 0)
        field_188 = 1;
    slot_063(a16, 0);
    M_4BB990(a7, a8, a9);
    M_4BB9E0(0, 0);
    M_4BBAE0(a10, -1);
    return 1;
}

// 0x4BA250 — seventeen-argument sibling: the +0x4A0460 seed/store block, the
// +0xF4 slot with (a16,a17), 0x4BB990(a7,a8,a9), 0x4BB9E0(3,1) and
// 0x4BBAE0(a10,-1); returns 1 (the caller 0x4BA390 ignores it).
MATCH_FUNC(0x4BA250)
int C_pnl_lst::Hook_4BA250(int a1, int a2, int a3, int a4, int a5, int a6,
                          int* a7, int a8, int a9, int a10, int a11, int a12,
                          int a13, int a14, int a15, int a16, int a17)
{
    M_4A0460(a1, a2, a3, a4, a5, a6, 0);
    field_164 = a11;
    field_168 = (unsigned char)a12;
    field_16c = a13;
    field_170 = (unsigned char)a14;
    field_150 = (short)a15;
    if (a13 != 0)
        field_188 = 1;
    slot_061(a16, a17);
    M_4BB990(a7, a8, a9);
    M_4BB9E0(3, 1);
    M_4BBAE0(a10, -1);
    return 1;
}

// 0x51E7F0's 0x1C entry object: the ctor (0x51E7F0) takes (char*, int), the
// accessor (matched 0x51EB90) fills four outputs from the +0x10 entry array at
// index 0, and the destructor (matched 0x51EAE0) releases the +0x0C/+0x08
// buffers.
class T51E7F0Entry {
public:
    int field_0;                  // +0x00 release mode
    int field_4;                  // +0x04 transfer argument
    void* field_8;                // +0x08 owned buffer
    void* field_c;                // +0x0C conditional buffer
    void* field_10;               // +0x10 entry array
    unsigned char field_14;       // +0x14 valid flag
    char pad_15[0x18 - 0x15];
    int field_18;                 // +0x18 count
    T51E7F0Entry(char* a1, int a2);
    bool M_51EB90(int* a1, int* a2, int* a3, int* a4, int index);
    void M_51EAE0();
};

extern void __cdecl sub_5F90B0(int a1);

class C_cluster_4B8B20 {
public:
    void M_4B8C10(int a1, int a2);
};
class C_TRIBE_Screen_Options {
public:
    void M_4A0630(int a1, int a2, int a3, int a4);
};
class T4BBDSlot {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual int Vt_05(int a1);   // slot +0x14
};
extern void* __cdecl sub_5F8F60(unsigned int a1);

// 0x4BBAE0 — rebuild the +0x15C entry object. Release the current pointer
// (0x51EAE0 then 0x5F90B0) and zero +0x15C/+0x160/+0x162 when present. Then,
// unless a2 is -1 with a non-empty string a1, allocate a 0x1C entry via
// 0x5F8F60, construct it (0x51E7F0(a1,a2)), store it at +0x15C, and fill the
// entry's index-0 rectangle through the matched 0x51EB90 accessor into four
// locals; +0x160 becomes (c - a + 1) and +0x162 (d - b + 1).
// NOTE: +0x15C is written here as a pointer while 0x4B3760 writes a byte at the
// same offset; the two proofs conflict and +0x15C is accessed by raw offset.
WIP_FUNC(0x4BBAE0)
void C_pnl_lst::M_4BBAE0(int a1, int a2)
{
    T51E7F0Entry* old = *(T51E7F0Entry**)((char*)this + 0x15c);
    if (old != 0)
    {
        old->M_51EAE0();
        sub_5F90B0((int)old);
        *(void**)((char*)this + 0x15c) = 0;
        *(short*)((char*)this + 0x160) = 0;
        *(short*)((char*)this + 0x162) = 0;
    }
    if (a2 != -1 || a1 == 0 || *(char*)a1 == 0)
    {
        T51E7F0Entry* entry = new T51E7F0Entry((char*)a1, a2);
        int a, b, c, d;
        *(void**)((char*)this + 0x15c) = entry;
        entry->M_51EB90(&a, &b, &c, &d, 0);
        *(short*)((char*)this + 0x160) = (short)(c - a + 1);
        *(short*)((char*)this + 0x162) = (short)(d - b + 1);
    }
}

// 0x4BBD30 — recompute the +0xFE row height and the +0x100/+0x102/+0x104
// visible window from +0x11C, then update the list child at +0x148. The divisor
// is (+0x11C + 2), enlarged by 2*(+0x19C) - 1 when the +0x19C mode is set; when
// +0x11C is zero the height is forced to 1. The height divides
// (+0x18 - 2*+0x198). Clamp height to >=1; clamp +0x100 to <= +0xFC-1, then to
// <= +0xFC - height, then >=0. Set +0x102 = +0x100 + height - 1, clamp to
// [0, +0xFC-1]; clamp +0x104 to [0, +0xFC-1]. With a +0x148 child and v nonzero,
// run 0x4B8C10(child, v6-v7+1, v10). When +0x14C is set: if +0xFC <= +0xFE and
// +0x184 is already set, run 0x4A0630(this,+0xC,+0x10,+0x17C,+0x18) and clear
// +0x184, then when +0x6C is set dispatch child slot +0x14 with 0. If +0xFC >
// +0xFE and +0x184 is clear, run 0x4A0630(this,+0xC,+0x10,+0x17C-+0x180,+0x18),
// set +0x184, and when +0x6C is set dispatch child slot +0x14 with 1. Every exit
// stores +0x14 into +0x154 and returns it.
WIP_FUNC(0x4BBD30)
int C_pnl_lst::Other_4BBD30(int v)
{
    int v3 = *(int*)((char*)this + 0x11c);
    int v4 = v3 + 2;
    *(int*)((char*)this + 0x158) = v3 + 2;
    if (v3 == 0)
        *(short*)((char*)this + 0xfe) = 1;
    else
    {
        int v5 = *(int*)((char*)this + 0x19c);
        if (v5)
            v4 = v4 + 2 * v5 - 1;
        *(short*)((char*)this + 0xfe) =
            (short)((*(int*)((char*)this + 0x18) -
                     2 * *(int*)((char*)this + 0x198)) / v4);
    }
    if (*(short*)((char*)this + 0xfe) < 1)
        *(short*)((char*)this + 0xfe) = 1;
    short v6 = *(short*)((char*)this + 0xfc);
    if (*(short*)((char*)this + 0x100) >= v6)
        *(short*)((char*)this + 0x100) = v6 - 1;
    short v7 = *(short*)((char*)this + 0xfe);
    if (v6 - *(short*)((char*)this + 0x100) < v7)
        *(short*)((char*)this + 0x100) = v6 - v7;
    if (*(short*)((char*)this + 0x100) < 0)
        *(short*)((char*)this + 0x100) = 0;
    short v10 = *(short*)((char*)this + 0x100);
    short v11 = v10 + v7 - 1;
    *(short*)((char*)this + 0x102) = v11;
    if (v11 < 0)
        *(short*)((char*)this + 0x102) = 0;
    if (*(short*)((char*)this + 0x102) >= v6)
        *(short*)((char*)this + 0x102) = v6 - 1;
    if (*(short*)((char*)this + 0x104) < 0)
        *(short*)((char*)this + 0x104) = 0;
    if (*(short*)((char*)this + 0x104) >= v6)
        *(short*)((char*)this + 0x104) = v6 - 1;
    int* v12 = *(int**)((char*)this + 0x148);
    if (v12)
    {
        if (v != 0)
            ((C_cluster_4B8B20*)v12)->M_4B8C10(v6 - v7 + 1, v10);
        if (*(int*)((char*)this + 0x14c))
        {
            int v13 = *(int*)((char*)this + 0x184);
            if (*(short*)((char*)this + 0xfc) <= *(short*)((char*)this + 0xfe))
            {
                if (v13)
                {
                    ((C_TRIBE_Screen_Options*)this)->M_4A0630(
                        *(int*)((char*)this + 0xc), *(int*)((char*)this + 0x10),
                        *(int*)((char*)this + 0x17c), *(int*)((char*)this + 0x18));
                    int v16 = *(int*)((char*)this + 0x6c);
                    *(int*)((char*)this + 0x184) = 0;
                    if (v16)
                        ((T4BBDSlot*)v12)->Vt_05(0);
                }
            }
            else if (!v13)
            {
                ((C_TRIBE_Screen_Options*)this)->M_4A0630(
                    *(int*)((char*)this + 0xc), *(int*)((char*)this + 0x10),
                    *(int*)((char*)this + 0x17c) - *(int*)((char*)this + 0x180),
                    *(int*)((char*)this + 0x18));
                int v14 = *(int*)((char*)this + 0x6c);
                *(int*)((char*)this + 0x184) = 1;
                if (v14)
                {
                    ((T4BBDSlot*)v12)->Vt_05(1);
                    int result = *(int*)((char*)this + 0x14);
                    *(int*)((char*)this + 0x154) = result;
                    return result;
                }
            }
        }
    }
    int result = *(int*)((char*)this + 0x14);
    *(int*)((char*)this + 0x154) = result;
    return result;
}
