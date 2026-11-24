// C_cluster_47DA00 — cluster anchored at 0x47DA00 (ui region).
// This TU carries the single byte-verified dword getter at +0x0C.
#pragma once

#include "Function.hpp"

class C_cluster_47DA00 {
public:
    char pad_00[0xC];
    int field_C;                  // +0x0C

    int Get_47DA00();
};
