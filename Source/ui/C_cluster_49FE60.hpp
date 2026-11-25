// C_cluster_49FE60 — cluster anchored at 0x49FE60 (ui region).
// This TU carries the 6-byte global function-pointer thunk at 0x5ED9D6. The
// target pointer lives in runtime data at 0x61C0A8.
#pragma once

#include "Function.hpp"

class C_cluster_49FE60 {
public:
    char pad_00[0xac0];
    int field_ac0;                // +0xAC0
    int field_ac4;                // +0xAC4

    void M_5ED9D6();
    void M_49FE60();
};
