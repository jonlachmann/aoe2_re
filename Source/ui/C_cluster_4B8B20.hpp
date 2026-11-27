// C_cluster_4B8B20 — cluster anchored at 0x4B8B20 (ui region). Evidence from
// 0x4B8B20 shows a vtable at +0 with at least 9 slots (the entry dispatches
// slot +0x20 last), so this is a virtual class; field offsets below stay at
// their proven positions from the +4 data start.
#pragma once

#include "Function.hpp"

class C_cluster_4B8B20 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008(int a1);

    char pad_04[0xfc - 0x04];
    int field_fc;                 // +0xFC divisor/id base
    char pad_100[0x108 - 0x100];
    int field_108;                // +0x108 stored input
    char pad_10c[0x124 - 0x10c];
    int field_124;                // +0x124 element extent
    int field_128;                // +0x128 secondary position
    int field_12c;                // +0x12C secondary low bound
    int field_130;                // +0x130 secondary high bound
    char pad_134[0x138 - 0x134];
    int field_138;                // +0x138 primary position
    int field_13c;                // +0x13C primary low bound
    int field_140;                // +0x140 primary high bound
    char pad_144[0x1b8 - 0x144];
    int field_1b8;                // +0x1B8 mode (1 = primary)

    void Hook_4B8B20(int a1);     // unresolved callee at 0x4B8B20
    void M_4B8C10(int a1, int a2);
    void M_4B8A80();              // unresolved callee at 0x4B8A80
    void M_4B8B20(int a1);
};
