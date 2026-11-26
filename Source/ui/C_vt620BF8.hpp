// C_vt620BF8 — ui vtable class 0x620BF8 (anchor 0x4734B0). The constructor
// 0x473410 fills +4/+8/+C/+10/+14/+18: a row width, a row count, the flat
// buffer pointer and the per-row pointer array. The destructor bodies 0x4734B0
// and 0x4734D0 are already matched under ad-hoc names in free_ui.cpp.
#pragma once

#include "Function.hpp"

class C_vt620BF8 {
public:
    virtual void slot_00();

    int field_4;                  // +0x04 row width
    int field_8;                  // +0x08 row count
    int field_c;                  // +0x0C
    int field_10;                 // +0x10
    int field_14;                 // +0x14 flat buffer
    int field_18;                 // +0x18 per-row pointer array

    C_vt620BF8* Init_473410(int a1, int a2, int a3);
};
