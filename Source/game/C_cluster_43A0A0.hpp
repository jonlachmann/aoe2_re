// C_cluster_43A0A0 — cluster anchored at 0x43A0A0 (game region).
// This TU carries the single byte-verified dword setter at +0x10.
#pragma once

#include "Function.hpp"

class C_cluster_43A0A0 {
public:
    char pad_00[0x10];
    int field_10;                 // +0x10

    void SetInt_43A0A0(int v);
};
