// C_cluster_43EB70 — cluster anchored at 0x43EB70 (game region).
// This TU carries the single byte-verified four-field initializer.
#pragma once

#include "Function.hpp"

class C_cluster_43EB70 {
public:
    int field_00;                 // +0x00
    int field_04;                 // +0x04
    char pad_08[0xA8 - 0x08];
    int field_A8;                 // +0xA8
    char pad_AC[0x1A4C - 0xAC];
    int field_1A4C;               // +0x1A4C

    void Init_43EB90();
};
