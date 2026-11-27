// C_vt621F6C — base object for the 0x621F6C vtable (61 slots). The vtable is
// installed by the constructors at 0x4A0270/0x4A00E0 and reset by the
// destructor path 0x4A03B0. Data fields start at +4; only offsets proven by
// the matched bodies are named. The reconstructed ctor class carries the
// function address in its name so the VC6 constructor symbol is byte-comparable.
#pragma once

#include "Function.hpp"

class C_vt621F6C_4A0270 {
public:
    int field_00;                  // +0x00 vtable word (raw, no virtual decl)
    int field_04;                  // +0x04
    int field_08;                  // +0x08
    int field_0c;                  // +0x0C
    int field_10;                  // +0x10
    int field_14;                  // +0x14
    int field_18;                  // +0x18
    int field_1c;                  // +0x1C
    int field_20;                  // +0x20
    char pad_24[0x34 - 0x24];
    int field_34;                  // +0x34
    int field_38;                  // +0x38 default 2
    int field_3c;                  // +0x3C
    int field_40;                  // +0x40
    int field_44;                  // +0x44
    int field_48;                  // +0x48
    int field_4c;                  // +0x4C
    int field_50;                  // +0x50
    int field_54;                  // +0x54
    int field_58;                  // +0x58
    int field_5c;                  // +0x5C
    int field_60;                  // +0x60
    int field_64;                  // +0x64
    int field_68;                  // +0x68
    int field_6c;                  // +0x6C default 1
    int field_70;                  // +0x70
    int field_74;                  // +0x74
    int field_78;                  // +0x78
    int field_7c;                  // +0x7C default 1
    int field_80;                  // +0x80 default 1
    char pad_84[0x88 - 0x84];
    int field_88;                  // +0x88 default 1
    int field_8c;                  // +0x8C
    int field_90;                  // +0x90
    int field_94;                  // +0x94
    int field_98;                  // +0x98
    int field_9c;                  // +0x9C
    int field_a0;                  // +0xA0
    int field_a4;                  // +0xA4
    int field_a8;                  // +0xA8
    int field_ac;                  // +0xAC
    int field_b0;                  // +0xB0
    int field_b4;                  // +0xB4
    int field_b8;                  // +0xB8
    int field_bc;                  // +0xBC
    int field_c0;                  // +0xC0 default 0xFA
    int field_c4;                  // +0xC4
    int field_c8;                  // +0xC8
    int field_cc;                  // +0xCC
    int field_d0;                  // +0xD0
    int field_d4;                  // +0xD4
    int field_d8;                  // +0xD8
    int field_dc;                  // +0xDC
    int field_e0;                  // +0xE0
    int field_e4;                  // +0xE4
    int field_e8;                  // +0xE8 default -1
    int field_ec;                  // +0xEC default -1
    unsigned char field_f0;        // +0xF0
    unsigned char field_f1;        // +0xF1
    unsigned char field_f2;        // +0xF2
    unsigned char field_f3;        // +0xF3
    unsigned char field_f4;        // +0xF4
    unsigned char field_f5;        // +0xF5
    unsigned char field_f6;        // +0xF6

    C_vt621F6C_4A0270();
};

// C_pnl_txt_4B9F70 — the C_pnl_txt constructor at 0x4B9F70. It derives from the
// 0x621F6C base object, calls the base ctor at 0x4A0270, extends the layout from
// +0xF8 to +0x1A4, then installs the C_pnl_txt vtable 0x623318 at +0.
// The reconstruction class carries the ctor address in its name so the VC6
// constructor symbol is byte-comparable.
class C_pnl_txt_4B9F70 : public C_vt621F6C_4A0270 {
public:
    int field_f8;                  // +0xF8
    short field_fc;                // +0xFC
    short field_fe;                // +0xFE
    short field_100;               // +0x100
    short field_102;               // +0x102
    short field_104;               // +0x104
    short field_106;               // +0x106
    int field_108;                 // +0x108
    int field_10c;                 // +0x10C
    int field_110;                 // +0x110
    int field_114;                 // +0x114
    int field_118;                 // +0x118
    int field_11c;                 // +0x11C
    int field_120;                 // +0x120
    int field_124;                 // +0x124
    int field_128;                 // +0x128 default 7
    int field_12c;                 // +0x12C
    int field_130;                 // +0x130 default 2
    int field_134;                 // +0x134 default 2
    int field_138;                 // +0x138 default 0xFFFFFF
    int field_13c;                 // +0x13C
    int field_140;                 // +0x140 default 0xFFFF
    int field_144;                 // +0x144
    int field_148;                 // +0x148
    int field_14c;                 // +0x14C
    short field_150;               // +0x150
    int field_154;                 // +0x154
    int field_158;                 // +0x158
    int field_15c;                 // +0x15C
    short field_160;               // +0x160
    short field_162;               // +0x162
    int field_164;                 // +0x164
    unsigned char field_168;       // +0x168 default 0xFF
    char pad_169[0x16c - 0x169];
    int field_16c;                 // +0x16C
    unsigned char field_170;       // +0x170
    char pad_171[0x174 - 0x171];
    int field_174;                 // +0x174
    int field_178;                 // +0x178
    int field_17c;                 // +0x17C
    int field_180;                 // +0x180
    int field_184;                 // +0x184
    int field_188;                 // +0x188
    unsigned char field_18c;       // +0x18C
    unsigned char field_18d;       // +0x18D
    unsigned char field_18e;       // +0x18E
    unsigned char field_18f;       // +0x18F
    unsigned char field_190;       // +0x190
    unsigned char field_191;       // +0x191
    char pad_192[0x194 - 0x192];
    int field_194;                 // +0x194
    int field_198;                 // +0x198
    int field_19c;                 // +0x19C
    char pad_1a0[0x1a4 - 0x1a0];
    int field_1a4;                 // +0x1A4

    C_pnl_txt_4B9F70();
};
