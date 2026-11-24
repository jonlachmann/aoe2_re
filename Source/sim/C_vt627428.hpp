// C_vt627428 — vtable class 0x627428 (skeleton: Source/skeleton/sim/
// C_vt627428_627428.h holds all slots and lifted methods).
// This TU carries the 10 byte-verified methods. The layout is partial: fields
// at +0x08/+0x24 are generic pointers because two methods address different
// subobjects there; each body casts to its own helper type.
#pragma once

#include "Function.hpp"

struct S531B00Node {
    char pad_00[4];
    int field_4;
};

class S535EC0Sub {
public:
    char pad_00[0x16];
    short field_16;
};

class T537150 {
public:
    void M_537150();
};

class C_vt627428 {
public:
    char pad_00[8];
    void* field_08;               // +0x08, generic subobject pointer
    char pad_0C[0x24 - 0x0C];
    void* field_24;               // +0x24, generic subobject pointer
    char pad_28[0x1A0 - 0x28];
    int field_1A0;                // +0x1A0
    char pad_1A4[0x1C8 - 0x1A4];
    int* table[4];                // +0x1C8
    char pad_1D8[0x1F8 - 0x1D8];
    int field_1F8;                // +0x1F8
    char pad_1FC[0x23C - 0x1FC];
    int field_23C;                // +0x23C

    int Get_52CB50();
    int Get_52CB60();
    int Diff_531B00();
    int Get_531F00(int index);
    static bool __stdcall M_535E70(int id);
    char Check_535E90(int a2);
    unsigned char IsOther_535EC0();
    int Tick_537D50();
    int Pop_537D70();
    float M_537D90();
    void M_530AC0();

    float Sub_48E2D0();
};
