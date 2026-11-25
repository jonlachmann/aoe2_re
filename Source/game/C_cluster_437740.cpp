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
