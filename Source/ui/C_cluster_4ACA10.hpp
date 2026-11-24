// C_cluster_4ACA10 — cluster anchored at 0x4ACA10 (ui region).
// This TU carries the single byte-verified word pair setter at +0x170/+0x172.
#pragma once

#include "Function.hpp"

class C_cluster_4ACA10 {
public:
    char pad_00[0x170];
    unsigned short field_170;     // +0x170
    unsigned short field_172;     // +0x172

    void Set_4ACA10(unsigned short a, unsigned short b);
};
