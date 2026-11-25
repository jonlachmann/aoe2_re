// C_cluster_438ED0 — game cluster anchored at 0x438ED0. This TU carries the
// byte-verified owner/state reset (0x438ED0) and the shared init (0x439950).
// Fields +0x00/+0x04/+0x0C/+0xE54/+0xE58 are proven across those bodies.
#pragma once

#include "Function.hpp"

// Object reached through [C_cluster_438ED0+0x00]; +0x160C is read by 0x439950.
class T438ED0Obj {
public:
    char pad_00[0x160c];
    int field_160c;               // +0x160C
};

class C_cluster_438ED0 {
public:
    T438ED0Obj* field_0;          // +0x00
    int field_4;                  // +0x04
    char pad_08[0x0c - 0x08];
    int field_0c;                 // +0x0C
    char pad_10[0xe54 - 0x10];
    int field_e54;                // +0xE54
    int field_e58;                // +0xE58

    void Hook_439030();           // unresolved callee at 0x439030
    void Hook_439410(int* out);   // unresolved callee at 0x439410
    void M_439950();
    C_cluster_438ED0* M_438ED0(T438ED0Obj* owner);
};
