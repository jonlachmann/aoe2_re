#include "C_global_6645C4.hpp"

extern C_global_6645C4* g_p6645c4;             // global object pointer at 0x6645C4
extern "C" void* sub_5F8FF0(unsigned int a1, int a2);   // array allocator
extern void __cdecl Free_5F90B0(void* p);

MATCH_FUNC(0x4732B0)
void C_global_6645C4::M_4732B0(int a1)
{
    if (field_4 == 0) {
        field_4 = a1;
        arr_18 = (int*)sub_5F8FF0(a1 + 1, 4);
    }
}

MATCH_FUNC(0x4730D0)
bool C_global_6645C4::M_4730D0(int x, int y, int v)
{
    if (x < 0 || x >= field_8)
        return false;
    if (y < 0)
        return false;
    if (y >= field_10[x])
        return false;
    ((int*)field_c[x])[y * 3 + 1] = v;
    return true;
}

MATCH_FUNC(0x4B0EA0)
void C_global_6645C4::M_4B0EA0(int a1)
{
    field_2cc = a1;
    if (a1 == -1) {
        field_154 = 0;
    } else {
        field_154 = g_p6645c4->Hook_41F6E0(a1);
    }
}

MATCH_FUNC(0x473110)
bool C_global_6645C4::M_473110(int i, int v)
{
    if (i >= 0 && i < field_4) {
        arr_18[i] = v;
        return true;
    }
    return false;
}

// 0x4732E0 — grow index a1 of the cluster to a2 entries. Fail only when the
// index is out of range; when it already has at least a2 entries return true.
// Otherwise allocate a2*0x0C bytes, copy the old entries, free the old block,
// set dword +4 of each new entry to -1, and record the new count and block.
// field_10[a1] is re-read each time (no local), which is what matched.
MATCH_FUNC(0x4732E0)
#pragma intrinsic(memcpy)
bool C_global_6645C4::M_4732E0(int a1, int a2)
{
    if (a1 < 0 || a1 >= field_8)
        return false;
    if (field_10[a1] < a2)
    {
        int* buf = (int*)sub_5F8FF0(a2, 0xc);
        if (field_10[a1] > 0)
        {
            memcpy(buf, field_c[a1], field_10[a1] * 0xc);
            Free_5F90B0(field_c[a1]);
        }
        for (int i = field_10[a1]; i < a2; i++)
            buf[i * 3 + 1] = -1;
        field_10[a1] = a2;
        field_c[a1] = buf;
    }
    return true;
}
#pragma function(memcpy)

// 0x473200 — ensure row a1 has room for a2 entries: when field_8 already
// exceeds a1, just grow via 0x4732E0; otherwise allocate two a1+1 arrays, copy
// the live row-count and block-pointer tables, free the old ones, install the
// new tables and grow the row. Always returns true (0x4732E0's result is
// ignored). The first memcpy comes out as a bare `rep movsd` because VC6
// folds field_8*4 against the field_8 > 0 guard it just loaded.
MATCH_FUNC(0x473200)
#pragma intrinsic(memcpy)
bool C_global_6645C4::M_473200(int a1, int a2)
{
    if (a1 < 0)
        return false;
    if (field_8 <= a1)
    {
        int n = a1 + 1;
        int* rows = (int*)sub_5F8FF0(n, 4);
        int** blocks = (int**)sub_5F8FF0(n, 4);
        if (field_8 > 0)
        {
            memcpy(rows, field_10, field_8 * 4);
            Free_5F90B0(field_10);
            memcpy(blocks, field_c, field_8 * 4);
            Free_5F90B0(field_c);
        }
        field_10 = rows;
        field_8 = n;
        field_c = blocks;
    }
    M_4732E0(a1, a2);
    return true;
}
#pragma function(memcpy)
