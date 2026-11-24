// C_cluster_525610 — cluster anchored at 0x525610 (sim region).
// This TU carries the single byte-verified dword clear/byte set (method 0x525870).
#pragma once

#include "Function.hpp"

class C_cluster_525610 {
public:
    char pad_00[0x14];
    unsigned char field_14;       // +0x14
    char pad_15[0x1C - 0x15];
    int field_1C;                 // +0x1C

    void Set_525870(int unused);
};
