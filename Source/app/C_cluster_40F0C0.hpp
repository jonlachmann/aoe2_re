// C_cluster_40F0C0 — cluster anchored at 0x40F0C0 (app region).
// This TU carries the single byte-verified field comparison.
#pragma once

#include "Function.hpp"

class C_cluster_40F0C0 {
public:
    char pad_00[0xEA4];
    int field_EA4;                // +0xEA4

    bool Check_40F4B0();
};
