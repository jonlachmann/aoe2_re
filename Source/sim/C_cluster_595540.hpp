// C_cluster_595540 — cluster anchored at 0x595540 (sim region).
// This TU carries the single byte-verified node word getter at +0x10.
#pragma once

#include "Function.hpp"

struct S595540Node {
    char pad_00[0x0C];
    int field_C;                  // +0x0C
    int field_10;                 // +0x10
};

class C_cluster_595540 {
public:
    int Count_595540(S595540Node* p);
};
