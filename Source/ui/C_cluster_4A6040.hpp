// C_cluster_4A6040 — cluster anchored at 0x4A6040 (ui region).
// This TU carries the single byte-verified byte getter at +0x900 (method 0x514400).
#pragma once

#include "Function.hpp"

class C_cluster_4A6040 {
public:
    char pad_00[0x900];
    unsigned char field_900;      // +0x900

    unsigned char Get_514400();
};
