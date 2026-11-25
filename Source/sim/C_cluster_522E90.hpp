// C_cluster_522E90 — cluster anchored at 0x522E90 (sim region).
// This TU carries the single byte-verified three-field clear plus copy/increment
// (method 0x522E90).
#pragma once

#include "Function.hpp"

class C_cluster_522E90 {
public:
    char pad_00[0x10];
    int field_10;                 // +0x10
    int field_14;                 // +0x14
    int field_18;                 // +0x18
    int field_1C;                 // +0x1C
    int field_20;                 // +0x20
    char pad_24[0x38 - 0x24];
    int field_38;                 // +0x38
    void* field_3C;               // +0x3C
    void* field_40;               // +0x40
    void* field_44;               // +0x44
    void* field_48;               // +0x48
    void* field_4C;               // +0x4C
    int field_50;                 // +0x50

    void M_522E90();
    void M_523060();
};
