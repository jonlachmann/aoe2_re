#include "C_cluster_4B8B20.hpp"

MATCH_FUNC(0x4B8C10)
void C_cluster_4B8B20::M_4B8C10(int a1, int a2)
{
    field_fc = a1;
    this->Hook_4B8B20(a2);
}

// 0x4B8B20 — one-argument position setter. Store the input at +0x108, then:
// when +0x1B8 is 1, scale the primary position +0x138 by a1 when +0xFC > 0
// (element extent +0x124 / 2 plus the +0x140/+0x13C span, multiplied by a1,
// divided by +0xFC, added to +0x13C) and clamp it into [+0x13C, +0x140];
// otherwise, when +0xFC > 0, use +0x130 directly if a1 is +0xFC-1, else scale
// +0x128 the same way with the +0x130/+0x12C span, and clamp it into
// [+0x12C, +0x130]. Finally run 0x4B8A80 and dispatch slot 8 (+0x20) with 1.
MATCH_FUNC(0x4B8B20)
void C_cluster_4B8B20::M_4B8B20(int a1)
{
    field_108 = a1;
    if (field_1b8 == 1)
    {
        if (field_fc > 0)
        {
            field_138 = (field_124 / 2 + field_140 - field_13c) * a1 /
                        field_fc + field_13c;
        }
        if (field_138 < field_13c)
            field_138 = field_13c;
        else if (field_138 > field_140)
            field_138 = field_140;
    }
    else
    {
        if (field_fc > 0)
        {
            if (a1 == field_fc - 1)
                field_128 = field_130;
            else
                field_128 = (field_124 / 2 + field_130 - field_12c) * a1 /
                            field_fc + field_12c;
        }
        if (field_128 < field_12c)
            field_128 = field_12c;
        else if (field_128 > field_130)
            field_128 = field_130;
    }
    M_4B8A80();
    slot_008(1);
}
