#include "C_cluster_4732E0.hpp"

extern void* __cdecl sub_5F8FF0(unsigned int a1, int a2);
extern void __cdecl Free_5F90B0(void* p);

// 0x4732E0 — grow index a1 of the cluster to a2 entries. Fail when the index
// is out of range or the index already has at least a2 entries; otherwise
// allocate a2*0x0C bytes, copy the old entries, free the old block, fill any
// new entries' first dword with -1, and record the new count and block.
WIP_FUNC(0x4732E0)
#pragma intrinsic(memcpy)
bool C_cluster_4732E0::M_4732E0(int a1, int a2)
{
    if (a1 < 0 || a1 >= field_8)
        return false;
    if (field_10[a1] >= a2)
        return false;

    int* buf = (int*)sub_5F8FF0(a2, 0xc);
    int old = field_10[a1];
    if (old > 0)
    {
        unsigned int bytes = old * 0xc;
        memcpy(buf, field_c[a1], bytes);
        Free_5F90B0(field_c[a1]);
    }
    if (old < a2)
    {
        int* p = buf + old * 3 + 1;
        for (int n = a2 - old; n > 0; n--)
        {
            *p = -1;
            p += 3;
        }
    }

    field_10[a1] = a2;
    field_c[a1] = (int*)buf;
    return true;
}
#pragma function(memcpy)
