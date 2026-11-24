// C_cluster_520720 — cluster anchored at 0x520720 (sim region).
// This TU carries the single byte-verified field initializer (method 0x520750).
#pragma once

#include "Function.hpp"

class C_cluster_520720 {
public:
    int field_0;                  // +0x00
    unsigned char field_4;        // +0x04
    unsigned char field_5;        // +0x05
    char pad_06[0xC - 0x06];
    int field_C;                  // +0x0C
    int field_10;                 // +0x10
    int field_14;                 // +0x14
    unsigned char field_18;       // +0x18
    char pad_19[0x1C - 0x19];
    int field_1C;                 // +0x1C

    void Init_520750();
};
