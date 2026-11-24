// C_cluster_42AEE0 — cluster anchored at 0x42AEE0 (game region).
// This TU carries the single byte-verified row-table clear.
#pragma once

#include "Function.hpp"

struct S42AF60Row {
    char pad_00[0x10];
    int slot_10[(0x38 - 0x10) / 4];
};

class C_cluster_42AEE0 {
public:
    char pad_00[0x1DD8];
    S42AF60Row* rows_1DD8;        // +0x1DD8, 0x38-byte rows

    void M_42AF60(int arg);
};
