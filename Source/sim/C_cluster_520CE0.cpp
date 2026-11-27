#include "C_cluster_520CE0.hpp"
#pragma intrinsic(memset)

MATCH_FUNC(0x5214E0)
void C_cluster_520CE0::M_5214E0()
{
    if (field_0 == 0) {
        this->Hook_521580();
        this->Hook_521500();
        this->M_522C30();
    }
}

MATCH_FUNC(0x5219B0)
int C_cluster_520CE0::Find_5219B0(int a2)
{
    int* v2 = *(int**)((char*)this + 0x80);
    while (v2) {
        if (*(int*)(*(int*)((char*)v2 + 8)) == a2)
            return *(int*)((char*)v2 + 8);
        v2 = *(int**)((char*)v2 + 4);
    }
    return 0;
}

MATCH_FUNC(0x5219E0)
int C_cluster_520CE0::Find_5219E0(int a2)
{
    int* v2 = *(int**)((char*)this + 0x7c);
    while (v2) {
        if (*(int*)(*(int*)((char*)v2 + 8)) == a2)
            return *(int*)((char*)v2 + 8);
        v2 = *(int**)((char*)v2 + 4);
    }
    return 0;
}

extern void (__stdcall *g_pfn_61c2f4)(void* a, int b, int c, int d);
extern void (__stdcall *g_pfn_61c2ec)(void* p);

MATCH_FUNC(0x522C30)
void C_cluster_520CE0::M_522C30()
{
    void* p = *(void**)((char*)this + 0x5bc);
    if (p)
        g_pfn_61c2f4(p, 0x184, 0, 0);
}

MATCH_FUNC(0x522C50)
void C_cluster_520CE0::M_522C50()
{
    g_pfn_61c2ec(*(void**)((char*)this + 0x5bc));
    *(void**)((char*)this + 0x5bc) = 0;
}

// 0x5204C0 — walk the +0x79C count, +0x29C pointer table and +0x69C byte
// table on the object pointed to by g_6645c4+0x80, dispatching each entry.
MATCH_FUNC(0x5204C0)
void C_cluster_520CE0::M_5204C0()
{
    for (int i = 0; i < *(int*)((char*)this + 0x79c); i++)
        ((C_cluster_5207B0*)*(int**)((char*)this + 0x29c + i * 4))->Hook_520A80(
            *(char*)((char*)this + i + 0x69c));
}

// 0x521500 — sweep the +0x598 entries through Find_5219E0; for each hit,
// either hand it to 0x521BE0 when 0x5217F0 accepts the +0x00 key, or, when the
// +0x04 bit 1 and +0x210 byte are set, decrement +0x5B0 and pass the key to
// 0x521470.
MATCH_FUNC(0x521500)
void C_cluster_520CE0::Hook_521500()
{
    if (field_7c == 0)
        return;
    for (int i = 0; i < field_598; i++)
    {
        int e = Find_5219E0(i);
        if (e != 0)
        {
            if (M_5217F0(*(int*)e) != 0)
            {
                M_521BE0(e);
            }
            else if ((*(unsigned char*)(e + 4) & 1) != 0 &&
                     *(unsigned char*)(e + 0x210) != 0)
            {
                field_5b0--;
                M_521470(*(int*)e);
            }
        }
    }
}

// 0x521580 — sweep the +0x598 entries through Find_5219B0; for each entry with
// a non-zero +0x2C byte and +0x08 bit 1, when 0x5217F0 rejects the +0x00 key,
// decrement +0x5B0 and pass the key to 0x521470.
MATCH_FUNC(0x521580)
void C_cluster_520CE0::Hook_521580()
{
    if (field_80 == 0)
        return;
    for (int i = 0; i < field_598; i++)
    {
        int e = Find_5219B0(i);
        if (e != 0 && *(unsigned char*)(e + 0x2c) != 0 &&
            (*(unsigned char*)(e + 8) & 1) != 0)
        {
            if (M_5217F0(*(int*)e) == 0)
            {
                field_5b0--;
                M_521470(*(int*)e);
            }
        }
    }
}

// 0x5217F0 — key lookup over the +0x00 gate: try Find_5219E0 then +0x258's
// dispatch table, otherwise Find_5219B0 then +0x4C's table; the successful
// dispatch fills a flags local (VC6 reuses the dead a1 slot for it), which
// then yields 1 for bit 0 or bit 2.
class T5217F0Dispatch {
public:
    char pad_00[0x24];
    int (__stdcall *fn_24)(void* a1, int* a2);
    char pad_28[0x30 - 0x28];
    void (__stdcall *fn_30)(void* a1, int a2, int a3, int a4);
    void (__stdcall *fn_34)(void* a1, int a2);
    char pad_38[0x3c - 0x38];
    int (__stdcall *fn_3c)(void* a1, int a2);
};
class T5217F0Sub {
public:
    T5217F0Dispatch* field_00;
};

MATCH_FUNC(0x5217F0)
int C_cluster_520CE0::M_5217F0(int a1)
{
    unsigned int flags;
    if (field_0 == 0)
    {
        int t = Find_5219B0(a1);
        int obj = Find_5219E0(a1);
        T5217F0Sub* sub;
        if ((obj != 0 && (sub = *(T5217F0Sub**)(obj + 0x258)) != 0 &&
             sub->field_00->fn_24(sub, (int*)&flags) == 0) ||
            (t != 0 && (sub = *(T5217F0Sub**)(t + 0x4c)) != 0 &&
             sub->field_00->fn_24(sub, (int*)&flags) == 0))
        {
            if (flags & 1)
                return 1;
            flags &= 0xff;      // kept as a separate statement: the folded
            return (flags >> 2) & 1;  // form drops the original's and eax,0xff
        }
    }
    return 0;
}

// 0x521780 — two-argument lookup: gate on +0x00, find through
// Find_5219B0/Find_5219E0, then report success of the +0x258 object's +0x3C
// dispatch (after reading its +0x298 flag) or of the +0x4C subobject's +0x3C
// dispatch; false on every miss.
MATCH_FUNC(0x521780)
int C_cluster_520CE0::M_521780(int a1, int a2)
{
    if (field_0 == 0)
    {
        int t = Find_5219B0(a1);
        int obj = Find_5219E0(a1);
        if (obj != 0)
        {
            // Both arms are identical; VC6 cross-jumps them and leaves the
            // dead test of the +0x298 byte.
            int r;
            T5217F0Sub* sub;
            if (*(unsigned char*)(obj + 0x298) != 0)
            {
                sub = *(T5217F0Sub**)(obj + 0x258);
                r = !sub->field_00->fn_3c(sub, a2);
            }
            else
            {
                sub = *(T5217F0Sub**)(obj + 0x258);
                r = !sub->field_00->fn_3c(sub, a2);
            }
            return r;
        }
        if (t != 0)
        {
            T5217F0Sub* sub = *(T5217F0Sub**)(t + 0x4c);
            return sub->field_00->fn_3c(sub, a2) == 0;
        }
    }
    return 0;
}

// 0x520D20 — full reset: zero the five +0x84/+0x188/+0x28C/+0x390/+0x494
// 0x104-byte blocks, the +0x10 0x60-byte block and the +0x70..+0x80 scalars
// (setting +0x78 to 6), then clear the +0x598..+0x5BC counters and the key.
MATCH_FUNC(0x520D20)
void C_cluster_520CE0::M_520D20()
{
    field_7c = 0;
    field_80 = 0;
    field_70 = 0;
    field_74 = 0;
    field_8 = 0;
    field_78 = 6;
    memset((char*)this + 0x84, 0, 0x104);
    memset((char*)this + 0x188, 0, 0x104);
    memset((char*)this + 0x28c, 0, 0x104);
    memset((char*)this + 0x390, 0, 0x104);
    memset((char*)this + 0x494, 0, 0x104);
    memset((char*)this + 0x10, 0, 0x60);
    field_59c = 0;
    field_598 = 0;
    field_5a0 = 0;
    field_5a4 = 0;
    field_5a8 = 0;
    field_5b0 = 0;
    field_5ac = 0;
    field_5b4 = 0;
    field_5bc = 0;
    field_5b8 = 0;
    field_0 = 0;
}
#pragma function(memset)

extern void __stdcall sub_5EE380(int a1);

// 0x5215F0 — one-argument activation of a found entry. Gate on +0x00; resolve
// Find_5219B0 then Find_5219E0; the first hit (t) drives its +0x4C subobject's
// +0x24 flags probe, and on bit 0 clear it runs the +0x3C/+0x34/+0x30
// dispatches and sets t's +0x2C byte. The second hit (obj) drives +0x258's
// subobject the same way; on bit 0 clear it optionally runs sub_5EE380(+0x29C),
// runs +0x3C with this->+0x5AC, +0x34 with obj's +0x280, M_521DC0(obj), copies
// +0x28C into +0x23C, then +0x30 and sets obj's +0x210 byte. Either success
// path returns 1 (bit 0 set short-circuits straight to 1); every miss returns 0.
MATCH_FUNC(0x5215F0)
int C_cluster_520CE0::M_5215F0(int a1)
{
    if (field_0 != 0)
        return 0;
    int t = Find_5219B0(a1);
    int obj = Find_5219E0(a1);
    unsigned int flags;
    if (t != 0)
    {
        if (*(T5217F0Sub**)(t + 0x4c) == 0)
            return 0;
        (*(T5217F0Sub**)(t + 0x4c))->field_00->fn_24(
            *(T5217F0Sub**)(t + 0x4c), (int*)&flags);
        if (flags & 1)
            goto success;
        (*(T5217F0Sub**)(t + 0x4c))->field_00->fn_3c(
            *(T5217F0Sub**)(t + 0x4c), field_5ac);
        (*(T5217F0Sub**)(t + 0x4c))->field_00->fn_34(
            *(T5217F0Sub**)(t + 0x4c), 0);
        (*(T5217F0Sub**)(t + 0x4c))->field_00->fn_30(
            *(T5217F0Sub**)(t + 0x4c), 0, 0, 0);
        *(unsigned char*)(t + 0x2c) = 1;
        return 1;
    }
    if (obj != 0)
    {
        if (*(T5217F0Sub**)(obj + 0x258) == 0)
            return 0;
        (*(T5217F0Sub**)(obj + 0x258))->field_00->fn_24(
            *(T5217F0Sub**)(obj + 0x258), (int*)&flags);
        if (flags & 1)
            goto success;
        if (*(unsigned char*)(obj + 0x298) != 0)
            sub_5EE380(*(int*)(obj + 0x29c));
        (*(T5217F0Sub**)(obj + 0x258))->field_00->fn_3c(
            *(T5217F0Sub**)(obj + 0x258), field_5ac);
        (*(T5217F0Sub**)(obj + 0x258))->field_00->fn_34(
            *(T5217F0Sub**)(obj + 0x258), *(int*)(obj + 0x280));
        M_521DC0(obj);
        *(int*)(obj + 0x23c) = *(int*)(obj + 0x28c);
        (*(T5217F0Sub**)(obj + 0x258))->field_00->fn_30(
            *(T5217F0Sub**)(obj + 0x258), 0, 0, 1);
        *(unsigned char*)(obj + 0x210) = 1;
    }
    else
        return 0;
success:
    return 1;
}
