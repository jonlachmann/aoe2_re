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
void C_cluster_522D20::Hook_5DC590(int a1)
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

// 0x522D90 — pop the next record pointer. Empty queue first appends one via
// 0x522D20(field_24); a +0x10 head node is unlinked and returned; otherwise
// the +0x14/+0x18 bucket entry is taken (stride 0x10), the queue count drops,
// and the bucket rolls over when the size array marks its end.
// Not reachable in plain C++: the overrun check is a bare 0xCC (int3) with
// fall-through, which VC6 only emits for `__asm int 3` (no __debugbreak
// intrinsic in VC6). With `__asm int 3` in place of the volatile store this
// exact body is byte-exact (verified); every C stand-in (volatile store,
// extern call) shifts the register allocation (edi/ebx/ebp) of the whole
// bucket path.
WIP_FUNC(0x522D90)
void* C_cluster_522D20::M_522D90()
{
    if (field_20 == 0)
        M_522D20(field_24);

    if (field_10 != 0)
    {
        int* node = (int*)(size_t)field_10;
        field_10 = *node;
        --field_20;
        return node;
    }

    int idx = field_14;
    int n = field_18;
    int* entry = (int*)(field_0[idx] + n * 0x10);
    --field_20;
    ++field_18;
    if (field_18 == field_4[idx])
    {
        field_14 = ++idx;
        field_18 = 0;
        if (idx == field_8)
        {
            field_14 = -1;
            if (field_20 > 0)
                *(volatile char*)0 = 0;   // original: __asm int 3 (see above)
        }
    }
    return entry;
}
