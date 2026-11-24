// C_cluster_40E1C0 — cluster anchored at 0x40E1C0 (app region).
// This TU carries the single byte-verified bounded dword-table probe.
#pragma once

#include "Function.hpp"

class C_cluster_40E1C0 {
public:
    char pad_00[0x1C];
    short count_1C;               // +0x1C
    char pad_1E[0x20 - 0x1E];
    int* arr_20;                  // +0x20, stride 16 bytes

    int M_40E6E0(int i);
};
