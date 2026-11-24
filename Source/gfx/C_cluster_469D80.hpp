// C_cluster_469D80 — cluster anchored at 0x469D80 (gfx region).
// This TU carries the single byte-verified bounded dword-table search.
#pragma once

#include "Function.hpp"

class C_cluster_469D80 {
public:
    char pad_00[0xC];
    int count_C;                  // +0x0C
    char pad_10[0x14 - 0x10];
    int* arr_14;                  // +0x14

    int M_469DE0(int v);
};
