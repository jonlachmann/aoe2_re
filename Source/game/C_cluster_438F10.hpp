// C_cluster_438F10 — game-side cluster (anchor 0x438F10).
#pragma once

#include "Function.hpp"

struct R438F10 {
    int field_0;                  // +0x00
    char pad_04[0x20 - 0x04];
};

class C_cluster_438F10 {
public:
    char pad_00[0xE54];
    R438F10* field_E54;           // +0xE54 0x20-stride record array
    int field_E58;                // +0xE58 record count

    void M_438F10();
};
