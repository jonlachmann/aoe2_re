// C_cluster_4732E0 — ui cluster that owns two parallel per-index arrays.
// The thiscall at 0x4732E0 grows one index's block to `val` entries of 0x0C
// bytes, copying the existing entries, freeing the old block, and putting -1
// in each newly added entry. Discovery: the body reads this+0x08 (array length),
// this+0x0C (block pointer array) and this+0x10 (entry-count array); the
// catalog had no class for it, so it is modeled here as its own cluster.
#pragma once

#include "Function.hpp"

class C_cluster_4732E0 {
public:
    char pad_00[8];
    int field_8;                  // +0x08 array length
    int** field_c;                // +0x0C per-index block pointers
    int* field_10;                // +0x10 per-index entry counts
    bool M_4732E0(int a1, int a2);
};
