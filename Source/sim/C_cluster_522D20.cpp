#include "C_cluster_522D20.hpp"

extern void* __cdecl sub_5F8F80(int size);
extern void* __cdecl sub_5F8FF0(unsigned int a1, int a2);
extern void __cdecl Free_5F90B0(void* p);

// 0x522D20 — grow capacity when full, then record size, allocation and totals.
MATCH_FUNC(0x522D20)
void C_cluster_522D20::M_522D20(int a1)
{
    if (field_8 == field_c)
        this->Hook_5DC590(field_8 + 4);
    int idx = field_8;
    int* sizes = field_4;
    field_8 = idx + 1;
    int size = field_28 * a1;
    sizes[idx] = a1;
    field_0[idx] = (int)sub_5F8F80(size);
    field_34++;
    field_1c += a1;
    field_20 += a1;
    if (field_14 == -1) {
        field_14 = idx;
        field_18 = 0;
    }
}

// 0x5DC590 — grow the +0x00/+0x04 arrays to the requested capacity: when the
// capacity is not already large, allocate two new int arrays through
// 0x5F8FF0(cap, 4), copy the +0x08 live entries, free the old arrays and
// install the new ones with the +0x0C capacity.
MATCH_FUNC(0x5DC590)
void C_cluster_522D20::M_5DC590(int a1)
{
    if (a1 < field_c)
        return;
    int* a = (int*)sub_5F8FF0((unsigned int)a1, 4);
    int* b = (int*)sub_5F8FF0((unsigned int)a1, 4);
    if (field_0 != 0)
    {
        for (int i = 0; i < field_8; i++)
        {
            a[i] = field_0[i];
            b[i] = field_4[i];
        }
        Free_5F90B0(field_0);
        Free_5F90B0(field_4);
    }
    field_4 = b;
    field_0 = a;
    field_c = a1;
}
