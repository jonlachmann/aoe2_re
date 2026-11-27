// C_cluster_520CE0 — cluster anchored at 0x520CE0 (sim region).
// This TU carries the 2 byte-verified WIP searches. Their head fields sit at
// different offsets (+0x80 and +0x7C), so no shared member field is declared.
#pragma once

#include "Function.hpp"

class C_cluster_5207B0 {
public:
    void Hook_520A80(char a1);     // unresolved callee at 0x520A80
};

class C_cluster_520CE0 {
public:
    int field_0;                  // +0x00 key
    char pad_04[0x08 - 0x04];     // +0x04..+0x08
    int field_8;                  // +0x08
    char pad_0c[0x10 - 0x0c];     // +0x0C..+0x10
    int field_10[0x18];           // +0x10..+0x70 (0x60 bytes)
    int field_70;                 // +0x70
    int field_74;                 // +0x74
    int field_78;                 // +0x78
    int field_7c;                 // +0x7C search gate
    void* field_80;               // +0x80 node chain head
    int field_84[0x41];           // +0x84..+0x188 (0x104 bytes)
    int field_188[0x41];          // +0x188..+0x28C (0x104 bytes)
    int field_28c[0x41];          // +0x28C..+0x390 (0x104 bytes)
    int field_390[0x41];          // +0x390..+0x494 (0x104 bytes)
    int field_494[0x41];          // +0x494..+0x598 (0x104 bytes)
    int field_598;                // +0x598 entry count
    int field_59c;                // +0x59C
    int field_5a0;                // +0x5A0
    int field_5a4;                // +0x5A4
    int field_5a8;                // +0x5A8
    int field_5ac;                // +0x5AC
    int field_5b0;                // +0x5B0 entry cursor
    int field_5b4;                // +0x5B4
    int field_5b8;                // +0x5B8
    int field_5bc;                // +0x5BC
    void Hook_521580();           // unresolved callee at 0x521580
    void Hook_521500();
    int Find_5219B0(int a2);
    int Find_5219E0(int a2);
    int M_5217F0(int a1);
    int M_521780(int a1, int a2);
    int M_5215F0(int a1);
    int M_521DC0(int a1);
    void M_521BE0(int a1);
    void M_521470(int a1);
    void M_5214E0();
    void M_522C30();
    void M_522C50();
    void M_5204C0();
    void M_520D20();
};
