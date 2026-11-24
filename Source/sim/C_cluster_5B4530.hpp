// C_cluster_5B4530 — cluster anchored at 0x5B4530 (sim region).
// This TU carries the 2 byte-verified setters. Both fields are reconstructed.
#pragma once

#include "Function.hpp"

class C_cluster_5B4530 {
public:
    char pad_00[0x1458];
    int field_1458;               // +0x1458
    unsigned char field_145C;     // +0x145C

    void SetInt_5B4530(int v);
    void SetByte_5B4550(unsigned char v);
};
