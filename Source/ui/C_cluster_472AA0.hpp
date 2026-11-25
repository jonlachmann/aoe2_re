// C_cluster_472AA0 — cluster anchored at 0x472AA0 (ui region).
// This TU carries the single byte-verified five-field clear (method 0x472B00).
#pragma once

#include "Function.hpp"

class C_cluster_472AA0 {
public:
    char pad_00[4];
    int field_4;                  // +0x04
    int field_8;                  // +0x08
    int field_C;                  // +0x0C
    int field_10;                 // +0x10
    int field_14;                 // +0x14
    int field_18;                 // +0x18

    void Hook_472B20(int a1, int a2);   // unresolved callee at 0x472B20
    void M_472B00();
    C_cluster_472AA0* Init_472AA0(int a1, int a2);
};
