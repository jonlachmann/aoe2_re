// C_cluster_45F8A0 — gfx cluster anchored at 0x45F8A0.
// 0x45F8A0 gates on two +0x3C/+0x3D mode bytes and two object pointers, then
// dispatches slot +0x18 of the vtable stored at [field_24]. 0x45DDB0 is the
// initializer of the same dense object: it zeroes every scalar, sets +0x34 to
// 8, and publishes the four default color words through 0x619780.
#pragma once

#include "Function.hpp"

typedef void (__stdcall *T45F8Slot18)(void* a1, int a2, int a3, int a4,
                                     void* a5);

class C_cluster_45F8A0 {
public:
    int field_00;                 // +0x00
    int field_04;                 // +0x04
    int field_08;                 // +0x08
    int field_0c;                 // +0x0C
    int field_10;                 // +0x10
    int field_14;                 // +0x14
    int field_18;                 // +0x18
    void* field_1c;               // +0x1C guard pointer
    int field_20;                 // +0x20
    void* field_24;               // +0x24 object with vtable at +0x00
    int field_28;                 // +0x28
    int field_2c;                 // +0x2C
    int field_30;                 // +0x30
    int field_34;                 // +0x34 (= 8)
    int field_38;                 // +0x38
    unsigned char field_3c;       // +0x3C mode byte
    unsigned char field_3d;       // +0x3D mode byte
    int field_40;                 // +0x40
    int field_44;                 // +0x44
    int field_48;                 // +0x48
    int field_4c;                 // +0x4C
    int field_50;                 // +0x50
    int field_54;                 // +0x54
    int field_58;                 // +0x58
    int field_5c;                 // +0x5C
    int field_60;                 // +0x60
    int field_64;                 // +0x64
    int field_68;                 // +0x68
    int field_6c;                 // +0x6C
    int field_70;                 // +0x70
    int field_74;                 // +0x74
    int field_78;                 // +0x78
    int field_7c;                 // +0x7C
    int field_80;                 // +0x80
    int field_84;                 // +0x84
    int field_88;                 // +0x88
    int field_8c;                 // +0x8C
    int field_90;                 // +0x90
    int field_94;                 // +0x94
    int field_98;                 // +0x98
    int field_9c;                 // +0x9C
    int field_a0;                 // +0xA0
    int field_a4;                 // +0xA4
    int field_a8;                 // +0xA8
    int field_ac;                 // +0xAC
    int field_b0;                 // +0xB0
    int field_b4;                 // +0xB4
    unsigned char slot_b8;        // +0xB8 subobject base passed to the callee

    C_cluster_45F8A0* Init_45DDB0();
    void M_45F8A0();
};
