// C_cluster_421820 — cluster anchored at 0x421820 (game region).
// This TU carries the single byte-verified byte getter.
#pragma once

#include "Function.hpp"

class C_cluster_421820 {
public:
    char pad_00[0x9D0];
    unsigned char field_9D0;      // +0x9D0

    int Get9D0_421820();
};
