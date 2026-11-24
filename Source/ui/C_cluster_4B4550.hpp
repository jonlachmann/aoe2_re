// C_cluster_4B4550 — cluster anchored at 0x4B4550 (ui region).
// This TU carries the single byte-verified IME status forwarder.
#pragma once

#include "Function.hpp"

class C_cluster_4B4550 {
public:
    char pad_00[0x164];
    void* handle_164;             // +0x164

    int M_4B4550();
    void M_5ED9E8();
};
