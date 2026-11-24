// C_cluster_421430 — cluster anchored at 0x421430 (game region).
// This TU carries the single byte-verified raw dword store at +0x924.
#pragma once

#include "Function.hpp"

class C_cluster_421430 {
public:
    char pad_00[0x924];
    int field_924;                // +0x924

    void Set924Raw_421A70(int v);
};
