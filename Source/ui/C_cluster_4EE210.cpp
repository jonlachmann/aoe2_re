#include "C_cluster_4EE210.hpp"
#include "matched_mem.h"

extern void* g_6645c4;
extern int g_740690;

// 0x4EE210 — do nothing when the +0x90 subobject is null; otherwise fill the
// +0x08/+0x0C fields with 0x521090(0x654658/0x654648, 0, 0, 8) while they equal
// -1, and when the 0x740690 one-shot flag is clear, run one update pair through
// 0x521780/0x5215F0 if the +0x84 gate object's +0x254 value is above -0x2328,
// then set 0x740690 = 1.
MATCH_FUNC(0x4EE210)
void Free_4EE210()
{
    T4EE210Obj* sub = (T4EE210Obj*)(((T4EE210Global*)ADDR(g_6645c4)))->field_90;
    if (sub == 0)
        return;
    if ((((T4EE210Global*)ADDR(g_6645c4)))->field_8 == -1)
        (((T4EE210Global*)ADDR(g_6645c4)))->field_8 = sub->M_521090(0x654658, 0, 0, 8);
    if ((((T4EE210Global*)ADDR(g_6645c4)))->field_c == -1)
        (((T4EE210Global*)ADDR(g_6645c4)))->field_c = sub->M_521090(0x654648, 0, 0, 8);
    if (g_740690 != 0)
        return;
    if ((((T4EE210Global*)ADDR(g_6645c4)))->field_84 != 0)
    {
        int v = ((T4EE210Gate*)(((T4EE210Global*)ADDR(g_6645c4)))->field_84)->field_254;
        if (v > -0x2328)
        {
            ((T4EE210Obj*)(((T4EE210Global*)ADDR(g_6645c4)))->field_90)->M_521780(
                (((T4EE210Global*)ADDR(g_6645c4)))->field_8, v);
            ((T4EE210Obj*)(((T4EE210Global*)ADDR(g_6645c4)))->field_90)->M_5215F0(
                (((T4EE210Global*)ADDR(g_6645c4)))->field_8);
        }
    }
    g_740690 = 1;
}
