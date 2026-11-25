#include "C_cluster_42AEE0.hpp"
#pragma intrinsic(memset)

extern void __cdecl Free_5F90B0(void* p);

MATCH_FUNC(0x42AF60)
void C_cluster_42AEE0::M_42AF60(int arg)
{
    for (int k = 0; k < 0x1f6; k++)
        rows_1DD8[k].slot_10[arg] = 0;
}

// 0x42AE50 — release the 0x1F5 records in the +0x1DDC 0x18-stride array and
// the 0x1F5 rows in the +0x1DD8 0x38-stride array: free each head pointer and
// zero the head fields; the wide rows also clear their +0x10 0x28-byte tail.
WIP_FUNC(0x42AE50)
void C_cluster_42AEE0::M_42AE50()
{
    for (unsigned int i = 0; i < 0x1F5; i++)
    {
        R42AE50Row18* e = rows_1DDC + i;
        if (e->field_0 != 0)
            Free_5F90B0((void*)e->field_0);
        e->field_0 = 0;
        e->field_4 = 0;
        e->field_8 = 0;
        e->field_c = 0;
        e->field_10 = 0;
    }
    for (unsigned int j = 0; j < 0x1F5; j++)
    {
        S42AF60Row* e = rows_1DD8 + j;
        e->field_0 = 0;
        if (e->field_8 != 0)
            Free_5F90B0((void*)e->field_8);
        e->field_8 = 0;
        e->field_4 = 0;
        e->field_c = 0;
        memset(e->slot_10, 0, 0x28);
    }
}
#pragma function(memset)
