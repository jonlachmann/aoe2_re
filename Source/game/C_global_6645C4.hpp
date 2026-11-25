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
    char pad_1c[0x154 - 0x1c];
    int field_154;                // +0x154
    char pad_158[0x2cc - 0x158];
    int field_2cc;                // +0x2CC

    int Hook_41F6E0(int a1);      // unresolved callee at 0x41F6E0
    bool M_473110(int i, int v);
    void M_4732B0(int a1);
    void M_4B0EA0(int a1);
};
