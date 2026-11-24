// C_cluster_48F830 — cluster anchored at 0x48F830 (ui region).
// This TU carries the single byte-verified dword clear at +0x60 (method 0x52C120).
#pragma once

#include "Function.hpp"

class C_cluster_48F830 {
public:
    char pad_00[0x60];
    int field_60;                 // +0x60

    void Set_52C120();
};
