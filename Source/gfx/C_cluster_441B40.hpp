// C_cluster_441B40 — cluster anchored at 0x441B40 (gfx region).
// This TU carries the single byte-verified fill helper, a plain global entry
// point in the original, so it stays static.
#pragma once

#include "Function.hpp"

class C_cluster_441B40 {
public:
    static void Fill_441C20(int* dest, int value, unsigned int count);
};
