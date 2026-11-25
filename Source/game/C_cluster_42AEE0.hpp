// C_cluster_42AEE0 — cluster anchored at 0x42AEE0 (game region).
// This TU carries the single byte-verified row-table clear.
#pragma once

#include "Function.hpp"

struct S42AF60Row {
    int field_0;                  // +0x00
    int field_4;                  // +0x04
    int field_8;                  // +0x08
    int field_c;                  // +0x0C
    int slot_10[(0x38 - 0x10) / 4]; // +0x10..+0x38
};

struct R42AE50Row18 {
    int field_0;                  // +0x00
    int field_4;                  // +0x04
    int field_8;                  // +0x08
    int field_c;                  // +0x0C
    int field_10;                 // +0x10
    char pad_14[0x18 - 0x14];
};

class C_cluster_42AEE0 {
public:
    char pad_00[0x1DD8];
    S42AF60Row* rows_1DD8;        // +0x1DD8, 0x38-byte rows
    R42AE50Row18* rows_1DDC;      // +0x1DDC, 0x18-byte rows

    void M_42AF60(int arg);
    void M_42AE50();
};
