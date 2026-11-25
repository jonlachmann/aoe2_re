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
