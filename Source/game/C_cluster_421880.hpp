// C_cluster_421880 — cluster anchored at 0x421880 (game region).
// This TU carries the single byte-verified packed-byte table getter.
#pragma once

#include "Function.hpp"

class C_cluster_421880 {
public:
    char pad_00[0x9B5];
    unsigned char array_9B5[0xB];  // +0x9B5

    int Get_421880(int index);
};
