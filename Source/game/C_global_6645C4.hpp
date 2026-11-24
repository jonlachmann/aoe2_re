// C_global_6645C4 — global class anchored at 0x6645C4 (game region).
// This TU carries the single byte-verified bounded dword-table store (0x473110).
#pragma once

#include "Function.hpp"

class C_global_6645C4 {
public:
    char pad_00[4];
    int field_4;                  // +0x04 count
    char pad_08[0x18 - 0x08];
    int* arr_18;                  // +0x18 table base

    bool M_473110(int i, int v);
};
