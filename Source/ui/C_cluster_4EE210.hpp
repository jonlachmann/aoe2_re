// C_cluster_4EE210 — ui cluster anchored at 0x4EE210.
// Free entry 0x4EE210 lazily initializes two -1 fields of the global 0x6645C4
// object through the +0x90 subobject, then issues one-time update calls.
#pragma once

#include "Function.hpp"

// The +0x90 subobject, with the three thiscall methods 0x4EE210 uses.
class T4EE210Obj {
public:
    int M_521090(int a1, int a2, int a3, int a4);
    void M_521780(int a1, int a2);
    void M_5215F0(int a1);
};

// Global 0x6645C4 layout used here: id fields at +0x08/+0x0C, the +0x84
// gate object and the +0x90 subobject.
class T4EE210Global {
public:
    char pad_00[8];
    int field_8;                  // +0x08
    int field_c;                  // +0x0C
    char pad_10[0x84 - 0x10];
    int field_84;                 // +0x84 gate object
    char pad_88[0x90 - 0x88];
    int field_90;                 // +0x90 subobject
};

// Gate object at +0x84, read at +0x254.
class T4EE210Gate {
public:
    char pad_00[0x254];
    int field_254;                // +0x254
};
