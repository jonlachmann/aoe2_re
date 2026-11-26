// C_cluster_45F5C0 — gfx cluster anchored at 0x45F5C0. The entry stores the
// argument at +0x08, fills a 0x400-byte stack buffer (direct fill callback or
// zero memset), writes both ends of the buffer and runs the 0x45F6F0 helper.
#pragma once

#include "Function.hpp"

class C_cluster_45F5C0 {
public:
    char pad_00[8];
    int field_8;                  // +0x08 source object

    void Hook_45F6F0(int a1, int a2, char* a3); // unresolved callee at 0x45F6F0
    void M_45F5C0(int a1);
};
