#include "C_cluster_437740.hpp"

extern int g_669558;
extern void __cdecl Hook_4378C0_V(int a1, ...);

// 0x437740 — when the index is below count, mark dword +28 in the 36-byte
// record and return the byte index times nine; invalid indices pass through.
MATCH_FUNC(0x437740)
int C_cluster_437740::MarkRecord_437740(unsigned index)
{
    int result = index;
    if (index < this->count) {
        result = 9 * index;
        *(int*)((char*)this->records + 4 * result + 28) = 1;
    }
    return result;
}

// 0x437490 — for every record whose key matches, whose count is nonzero and
// whose state is still -1, report the entry through the empty 0x4378C0 logger
// and mark it through 0x437740.
WIP_FUNC(0x437490)
void C_cluster_437740::M_437490(int key)
{
    Hook_4378C0_V(g_669558, 0x650EAC, key);
    for (unsigned int i = 0; i <= field_4; i++)
    {
        R437490Row* r = (R437490Row*)records + i;
        if (r->field_10 != key)
            continue;
        if (r->field_14 <= 0)
            continue;
        if (r->field_1c != -1)
            continue;
        Hook_4378C0_V(g_669558, 0x650E64, i, r->field_8, r->field_4,
                      r->field_10, r->field_14, r->field_18, r->field_0);
        this->MarkRecord_437740(i);
    }
}

#pragma intrinsic(memset)

// 0x437100 — initializer: clamp the first argument to at least 0x14 and store
// it at +0x08; clear +0x00/+0x04/+0x10C/+0x8E8/+0x8EC/+0x8F0, set +0x110 = 1,
// fill the 0x1F4-int table at +0x118 with -1 and the 0x20-int table at +0x8FC
// with 0, invoke 0x437210(count), then set +0x984/+0x988 = -1, clear
// +0x980/+0x97C/+0x98C/+0x114 and return this.
WIP_FUNC(0x437100)
C_cluster_437740* C_cluster_437740::Init_437100(int a1)
{
    if (a1 < 0x14)
        a1 = 0x14;
    count = a1;
    int* p = table_118;
    field_0 = 0;
    field_4 = 0;
    field_10c = 0;
    field_8ec = 0;
    field_8f0 = 0;
    field_110 = 1;
    field_8e8 = 0;
    memset(p, -1, 0x1f4 * 4);
    p = table_8fc;
    memset(p, 0, 0x20 * 4);
    field_984 = -1;
    field_980 = 0;
    field_988 = -1;
    field_97c = 0;
    field_98c = 0;
    records = 0;
    Hook_437210(count);
    return this;
}

#pragma function(memset)
