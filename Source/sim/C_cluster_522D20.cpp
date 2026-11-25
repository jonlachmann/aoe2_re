#include "C_cluster_522D20.hpp"

extern void* __cdecl sub_5F8F80(int size);

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
