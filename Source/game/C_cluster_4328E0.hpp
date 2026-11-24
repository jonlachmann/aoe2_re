// C_cluster_4328E0 — cluster anchored at 0x4328E0 (game region).
// This TU carries the single byte-verified dword setter.
#pragma once

#include "Function.hpp"

class C_cluster_4328E0 {
public:
    char pad_00[0x26A4];
    int field_26A4;               // +0x26A4

    void Set26A4_432B60(int v);
};
