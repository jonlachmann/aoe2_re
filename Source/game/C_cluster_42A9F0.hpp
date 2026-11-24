// C_cluster_42A9F0 — cluster anchored at 0x42A9F0 (game region).
// This TU carries the 2 byte-verified methods. The +0x10E0/+0x10E4 pair is
// reconstructed; 0x433500 indexes a raw slot table at +0x46BC beyond it.
#pragma once

#include "Function.hpp"

class C_cluster_42A9F0 {
public:
    char pad_00[0x10E0];
    int field_10E0;               // +0x10E0
    int field_10E4;               // +0x10E4

    int Get_42D470();
    int Set_433500(int index, int value);
};
