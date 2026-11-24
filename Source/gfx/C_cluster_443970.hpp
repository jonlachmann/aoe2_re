// C_cluster_443970 — cluster anchored at 0x443970 (gfx region).
// This TU carries the single byte-verified array/flag reset; the method lives
// at sim address 0x5C53B0.
#pragma once

#include "Function.hpp"

class C_cluster_443970 {
public:
    char pad_00[0x924];
    int arr_924[10];              // +0x924
    int arr_94C[10];              // +0x94C
    int field_974;                // +0x974

    void M_5C53B0();
};
