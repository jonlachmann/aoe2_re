// C_vt6230B0 — vtable class 0x6230B0 (ui region). Its constructor 0x4B9D20
// writes vtable 0x6230B0 and the two +0x1C8/+0x1CC flags; slot +0x00C forwards
// four arguments through one shared body (0x4B9E00).
#pragma once

#include "Function.hpp"

class C_vt6230B0 {
public:
    virtual void slot_00();
    virtual void slot_01();
    virtual void slot02_4A0750(int a1, int a2, int a3, int a4);
    virtual void slot03_4B9E00(int a1, int a2, int a3, int a4);
    virtual void slot_04();
    virtual void slot_05();

    // Layout shared with the 0x622E60 scrollbar base and 0x4B8A80's picture
    // rectangle fixups: screen-options origin words at +0x0C..+0x18, then the
    // +0x128..+0x1B8 coordinate block and two 4-word rectangle blocks.
    char pad_04[0x0c - 0x04];
    int field_c;                  // +0x0C
    int field_10;                 // +0x10
    int field_14;                 // +0x14
    int field_18;                 // +0x18
    char pad_1c[0x128 - 0x1c];
    int field_128;                // +0x128
    int field_12c;                // +0x12C
    int field_130;                // +0x130
    char pad_134[0x138 - 0x134];
    int field_138;                // +0x138
    int field_13c;                // +0x13C
    int field_140;                // +0x140
    char pad_144[0x168 - 0x144];
    int field_168;                // +0x168
    int field_16c;                // +0x16C
    int field_170;                // +0x170
    int field_174;                // +0x174
    int field_178;                // +0x178
    int field_17c;                // +0x17C
    int field_180;                // +0x180
    int field_184;                // +0x184
    int field_188;                // +0x188
    int field_18c;                // +0x18C
    int field_190;                // +0x190
    int field_194;                // +0x194
    int field_198;                // +0x198 rectangle 0 left
    int field_19c;                // +0x19C
    int field_1a0;                // +0x1A0
    int field_1a4;                // +0x1A4
    int field_1a8;                // +0x1A8 rectangle 1 left
    int field_1ac;                // +0x1AC
    int field_1b0;                // +0x1B0
    int field_1b4;                // +0x1B4
    int field_1b8;                // +0x1B8 rectangle mode
    char pad_1bc[0x1c8 - 0x1bc];
    int field_1c8;                // +0x1C8
    int field_1cc;                // +0x1CC

    void Hook_4B8730();           // unresolved callee at 0x4B8730
    int Hook_4B8910(int a1, int a2, int a3, int a4);   // 0x4B8910 rectangle layout
    C_vt6230B0* Init_4B9D20();
};
