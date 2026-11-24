// C_cluster_4BD5A0 — cluster anchored at 0x4BD5A0 (ui region).
// This TU carries the single byte-verified linked-list index lookup at +0xF8.
#pragma once

#include "Function.hpp"

struct N4BD5B0 {
    char pad_00[8];
    int value_8;                  // +0x08
    char pad_0C[0x24 - 0x0C];
    N4BD5B0* next_24;             // +0x24
};

class C_cluster_4BD5A0 {
public:
    char pad_00[0xF8];
    N4BD5B0* list_F8;             // +0xF8

    int M_4BD5B0(int idx);
};
