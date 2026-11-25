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
    int field_0;                  // +0x00
    char pad_04[0x7c - 0x04];     // +0x04..+0x7C
    int field_7c;                 // +0x7C search gate
    void* field_80;               // +0x80 node chain head
    char pad_84[0x598 - 0x84];    // +0x84..+0x598
    int field_598;                // +0x598 entry count
    char pad_59c[0x5b0 - 0x59c];  // +0x59C..+0x5B0
    int field_5b0;                // +0x5B0 entry cursor
    void Hook_521580();           // unresolved callee at 0x521580
    void Hook_521500();
    int Find_5219B0(int a2);
    int Find_5219E0(int a2);
    int M_5217F0(int a1);
    int M_521780(int a1, int a2);
    void M_521BE0(int a1);
    void M_521470(int a1);
    void M_5214E0();
    void M_522C30();
    void M_522C50();
    void M_5204C0();
};
