// C_cluster_520170 — sim cluster anchored at 0x520170. This TU carries the
// byte-verified guarded string copy into +0x20 (0x5203C0).
#pragma once

#include "Function.hpp"

class C_cluster_520170 {
public:
    char pad_00[0x20];
    char field_20;                // +0x20 copy destination

    void M_5203C0(char* src);
};
