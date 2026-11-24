#include "Function.hpp"

// Family at 0x412BE0: a pair of "active" fields at +0x28/+0x30 with a saved
// copy at +0x50/+0x54. Each setter first snapshots the active value into the
// saved slot, then stores the new value.
class S412BE0 {
public:
    char pad_00[0x28 - 0x00];
    int field_28;             // +0x28
    int field_2c;             // +0x2c (unused here)
    int field_30;             // +0x30
    char pad_34[0x50 - 0x34];
    int field_50;             // +0x50 saved copy of field_28
    int field_54;             // +0x54 saved copy of field_30

    void M_412BE0(int v);
    void M_412BF0(int v);
};

MATCH_FUNC(0x412BE0)
void S412BE0::M_412BE0(int v)
{
    field_50 = field_28;
    field_28 = v;
}

MATCH_FUNC(0x412BF0)
void S412BE0::M_412BF0(int v)
{
    field_54 = field_30;
    field_30 = v;
}
