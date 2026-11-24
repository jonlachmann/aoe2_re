// C_cluster_5B4540 — cluster anchored at 0x5B4540 (sim region).
// This TU carries the single byte-verified dword getter at +0x1458.
#pragma once

#include "Function.hpp"

class C_cluster_5B4540 {
public:
    char pad_00[0x1458];
    int field_1458;               // +0x1458

    int Get_5B4540();
};
