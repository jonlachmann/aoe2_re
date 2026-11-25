#include "C_cluster_520CE0.hpp"

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
