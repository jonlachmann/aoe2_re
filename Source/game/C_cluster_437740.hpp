// C_cluster_437740 — this-edge cluster; bounded record array.
#pragma once

#include "Function.hpp"

// Record layout used by 0x437490/0x437760: 36 bytes with the key at +0x10,
// the byte mode at +0x08, the state at +0x1C and the count at +0x14.
struct R437490Row {
    int field_0;                  // +0x00
    int field_4;                  // +0x04
    unsigned char field_8;        // +0x08
    char pad_9[0x0c - 0x9];
    int field_c;                  // +0x0C
    int field_10;                 // +0x10 key
    unsigned field_14;            // +0x14 count
    int field_18;                 // +0x18
    int field_1c;                 // +0x1C state, -1 when pending
    char pad_20[4];               // +0x20..+0x24
};

class C_cluster_437740 {
public:
    int field_0;                  // +0x00
    unsigned field_4;             // +0x04 last record index
    unsigned count;               // +0x08 bound used by 0x437740
    char pad_0C[0x114 - 0x0C];
    int* records;                 // 0x114, stride 36 bytes

    int MarkRecord_437740(unsigned index);
    void M_437490(int key);
};
