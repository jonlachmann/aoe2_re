// C_cluster_41F470 — app cluster anchored at 0x41F470. This TU carries the
// byte-verified five-step string handoff (0x41F540), all __stdcall thunks.
#pragma once

#include "Function.hpp"

class C_cluster_41F470 {
public:
    char pad_00[0x28];
    void* field_28;               // +0x28
    int field_2c;                 // +0x2C
    int field_30;                 // +0x30
    char pad_34[0x68 - 0x34];
    void* field_68;               // +0x68

    void M_41F540();
    int M_41F470();
};
