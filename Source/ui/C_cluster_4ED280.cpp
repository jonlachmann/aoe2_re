#include "C_cluster_4ED280.hpp"
#include "matched_mem.h"

extern int g_664524;
extern void __cdecl sub_5F90B0(void* a1);
extern int __cdecl sub_5FF460(char* a1, char* a2);

class S4AF400 {
public:
    void M_4AF400(int* a1, short a2);
};
class C_cluster_4AF870 {
public:
    int M_4AF870();
};
class S421FB0 {
public:
    int Get_421FB0();
};

// 0x4ED280 — dispatch the object's +0x10C slot (this, &field_97c, 0x24E,
// 0x181, 0x1C, 0x1C, 0, 0); when nonzero dispatch +0x120 (this, &field_978,
// 0x2536, 0x272, 0x17E, 0x9E, 0x26, 0xB, 0, 1, 1); when nonzero require the
// 0x664524 global, run its 0x422A70 entry, then the 0x58A800 entry on the
// result; only when that entry returns zero call the +0x97C object's +0xF4
// slot with 1.
MATCH_FUNC(0x4ED280)
void T4ED280Self::M_4ED280()
{
    if (Vt_67((int)this, (int*)&field_97c, 0x24E, 0x181, 0x1C, 0x1C, 0, 0) == 0)
        return;
    if (Vt_72((__int16**)this, (__int16**)field_978, 0x2536, 0x272, 0x17E, 0x9E, 0x26, 0xB,
              0, 1, 1) == 0)
        return;
    T4ED280Global* g = ((T4ED280Global*)ADDR(g_664524));
    if (g == 0)
        return;
    int r = g->M_422A70();
    if (r == 0)
        return;
    if (((T4ED280Bulk*)r)->M_58A800() != 0)
        return;
    ((T4ED280Obj*)field_97c)->Vt_61(1);
}

// 0x4ED180 — build the +0x948 panel with twelve-argument slot calls. First a
// +0x120 call (self, self, +0x948, 0x253D, 700, 230, 98, 40, 11, 0, 1, 1).
// When it succeeds, scan rows from +0x964 with a +0x120 call
// (self, self, i-6, v3+0x253A, 730, v4, 100, 30, 11, 0, 1, 0) and an +0x110
// call (self, self, i, 700, v4, 28, 28, 0, 0), stepping tick 270 by 30 per row
// up to 360. At exhaustion it runs 0x4AF400(base,3) over the three +0x964
// entries, then dispatches by (0x421FB0(0x6645C4) - 1): case 0 releases +0x96C,
// case 1 releases +0x968, default releases +0x964, each through 0x4AF870, and
// returns that release result.
WIP_FUNC(0x4ED180)
int T4ED280Self::M_4ED180()
{
    int result;
    int v3;
    int v4;
    __int16** i;
    int v6;
    int** v7;
    int v8;

    result = Vt_72((__int16**)this,
                   (__int16**)((char*)this + 0x948), 0x253d, 0x2bc, 0xe6,
                   0x62, 0x28, 0xb, 0, 1, 1);
    if (result)
    {
        v3 = 0;
        v4 = 0x10e;
        for (i = (__int16**)((char*)this + 0x964); ; ++i)
        {
            result = Vt_72((__int16**)this, i - 6, v3 + 0x253a, 0x2da,
                           v4, 0x64, 0x1e, 0xb, 0, 1, 0);
            if (!result)
                break;
            result = Vt_68((__int16**)this, i, 0x2bc, v4, 0x1c, 0x1c, 0, 0);
            if (!result)
                break;
            v4 += 0x1e;
            ++v3;
            if (v4 >= 0x168)
            {
                v6 = 3;
                v7 = (int**)((char*)this + 0x964);
                do
                {
                    ((S4AF400*)*v7)->M_4AF400((int*)((char*)this + 0x964), 3);
                    ++v7;
                    --v6;
                }
                while (v6 != 0);
                v8 = ((S421FB0*)*(int*)ADDR(0x6645c4))->Get_421FB0() - 1;
                if (!v8)
                    return ((C_cluster_4AF870*)*(int*)((char*)this + 0x96c))
                        ->M_4AF870();
                if (v8 == 1)
                    return ((C_cluster_4AF870*)*(int*)((char*)this + 0x968))
                        ->M_4AF870();
                return ((C_cluster_4AF870*)*(int*)((char*)this + 0x964))
                    ->M_4AF870();
            }
        }
    }
    return result;
}

