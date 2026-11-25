// C_cluster_522D20 — appendable record container anchored at 0x522D20 (sim).
// 0x522D20 stores an entry in the +0x00 pointer array and its size in the
// +0x04 count array, growing the +0x0C capacity through 0x5DC590 first.
#pragma once

#include "Function.hpp"

class C_cluster_522D20 {
public:
    int* field_0;                 // +0x00 record pointer array
    int* field_4;                 // +0x04 per-record size array
    int field_8;                  // +0x08 entry count
    int field_c;                  // +0x0C capacity
    int field_10;                 // +0x10 head node
    int field_14;                 // +0x14 current bucket, -1 when unset
    int field_18;                 // +0x18 bucket offset
    int field_1c;                 // +0x1C byte total
    int field_20;                 // +0x20 entry total
    int field_24;                 // +0x24 grow increment
    int field_28;                 // +0x28 record stride
    char pad_2c[0x34 - 0x2c];
    int field_34;                 // +0x34 appended counter

    void Hook_5DC590(int a1);     // unresolved grow callee at 0x5DC590
    void M_522D20(int a1);
};
