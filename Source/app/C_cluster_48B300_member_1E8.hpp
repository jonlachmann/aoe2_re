// C_cluster_48B300_member_1E8 — app cluster (anchor 0x48B300, member +0x1E8).
// This TU carries the byte-verified dialog teardown (0x41F920). Fields
// +0x28/+0x74/+0x1E8/+0x1F4/+0x1F8 are proven by that body.
#pragma once

#include "Function.hpp"

// Subobject at [C_cluster_48B300_member_1E8+0x1E8].
class T48B490 {
public:
    void Hook_48B490();           // unresolved callee at 0x48B490
};

class C_cluster_48B300_member_1E8 {
public:
    char pad_00[0x28];
    void* field_28;               // +0x28
    char pad_2c[0x74 - 0x2c];
    int field_74;                 // +0x74
    char pad_78[0x1e8 - 0x78];
    T48B490* field_1e8;           // +0x1E8
    char pad_1ec[0x1f4 - 0x1ec];
    int field_1f4;                // +0x1F4
    int field_1f8;                // +0x1F8

    void M_41F920();
};
