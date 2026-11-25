// C_cluster_4B8B20 — cluster anchored at 0x4B8B20 (ui region).
// This TU carries the single byte-verified field-set plus one-arg slot
// forwarder (0x4B8C10). Only the +0xFC field is proven from that body.
#pragma once

#include "Function.hpp"

class C_cluster_4B8B20 {
public:
    char pad_00[0xfc];
    int field_fc;                 // +0xFC

    void Hook_4B8B20(int a1);     // unresolved callee at 0x4B8B20
    void M_4B8C10(int a1, int a2);
};
