// C_cluster_5C30C0 — cluster anchored at 0x5C30C0 (sim region).
// This TU carries the single byte-verified initializer (method 0x5D0370).
// vtbl_0 stores the vtable constant; owner_c is kept as a pointer field.
#pragma once

#include "Function.hpp"

class C_cluster_5C30C0 {
public:
    int vtbl_0;                   // +0x00
    int field_4;                  // +0x04
    int field_8;                  // +0x08
    C_cluster_5C30C0* owner_C;    // +0x0C
    unsigned char field_10;       // +0x10
    char pad_11[0x14 - 0x11];
    int field_14;                 // +0x14
    int field_18;                 // +0x18
    int field_1C;                 // +0x1C
    int field_20;                 // +0x20
    int field_24;                 // +0x24

    C_cluster_5C30C0* Init_5D0370(C_cluster_5C30C0* owner);
};
