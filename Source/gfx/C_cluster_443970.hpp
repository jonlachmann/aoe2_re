// C_cluster_443970 — cluster anchored at 0x443970 (gfx region).
// This TU carries the single byte-verified array/flag reset; the method lives
// at sim address 0x5C53B0.
#pragma once

#include "Function.hpp"

class C_cluster_443970 {
public:
    int field_0;                  // +0x00 vtable pointer
    char pad_04[0x80 - 0x04];     // +0x04..+0x80
    int field_80;                 // +0x80
    char pad_84[0xc4 - 0x84];     // +0x84..+0xC4
    int field_c4;                 // +0xC4
    char pad_c8[0xf2 - 0xc8];     // +0xC8..+0xF2
    unsigned char field_f2;       // +0xF2
    char pad_f3[0x188 - 0xf3];    // +0xF3..+0x188
    int field_188;                // +0x188
    char pad_18c[0x198 - 0x18c];  // +0x18C..+0x198
    int field_198;                // +0x198
    int field_19c;                // +0x19C
    char pad_1a0[0x1a8 - 0x1a0];  // +0x1A0..+0x1A8
    int field_1a8;                // +0x1A8
    int field_1ac;                // +0x1AC
    int field_1b0;                // +0x1B0
    int field_1b4;                // +0x1B4
    int field_1b8;                // +0x1B8
    int field_1bc;                // +0x1BC
    int field_1c0;                // +0x1C0
    unsigned char field_1c4;      // +0x1C4
    char pad_1c5[0x1c8 - 0x1c5];  // +0x1C5..+0x1C8
    int field_1c8;                // +0x1C8
    char pad_1cc[0x924 - 0x1cc];  // +0x1CC..+0x924
    int arr_924[10];              // +0x924
    int arr_94C[10];              // +0x94C
    int field_974;                // +0x974

    void Hook_4B9F70();
    C_cluster_443970* M_4B5950();
    void M_5C53B0();
};
