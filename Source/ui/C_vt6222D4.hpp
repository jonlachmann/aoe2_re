// C_vt6222D4 — vtable class 0x6222D4 (skeleton: Source/skeleton/ui/
// C_vt6222D4_6222D4.h holds all slots and lifted methods).
// This TU carries the vtable-pointer store (0x4A8310) and the initializer
// (0x4A8320). The object is huge (~0xce63c bytes): the initializer clears
// three large regions at +0x14, +0xfe18 and +0x4f61c, then sets the four
// tail fields at +0xce62c..+0xce638.
#pragma once

#include "Function.hpp"

class C_vt6222D4 {
public:
    void SetVt_4A8310();
    bool M_4A8320(int a1, int a2, int a3, int a4);
    C_vt6222D4* Hook_4A8240(int a1, int a2, int a3, int a4, int a5);

    int vtbl_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    char region_14[0xfe04];       // 0x14..0xfe18
    char region_fe18[0x3f804];    // 0xfe18..0x4f61c
    char region_4f61c[0x7f010];   // 0x4f61c..0xce62c
    int field_ce62c;
    int field_ce630;
    char field_ce634;
    char pad_ce635[3];
    int field_ce638;
    char pad_ce63c[0xce83c - 0xce63c];
    int field_ce83c;
    int field_ce840;
    int field_ce844;
    int field_ce848;
};
