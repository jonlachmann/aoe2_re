// C_pnl_lst — recovered panel-list class. Vtable 0x622B50 has 73 slots; the
// declarations preserve every slot offset so vtable calls in the bodies stay
// byte-exact. Data fields begin after the implicit vtable pointer.
#pragma once

#include "Function.hpp"

class C_pnl_lst {
public:
    virtual void slot_000();  // slot +0x000
    virtual void slot_001();  // slot +0x004
    virtual void slot_002();  // slot +0x008
    virtual void slot_003(int a1, int a2, int a3, int a4);  // slot +0x00C
    virtual void slot_004();  // slot +0x010
    virtual void slot_005();  // slot +0x014
    virtual void slot_006();  // slot +0x018
    virtual void slot_007();  // slot +0x01C
    virtual void slot_008(int a1);  // slot +0x020
    virtual void slot_009();  // slot +0x024
    virtual void slot_010();  // slot +0x028
    virtual void slot_011();  // slot +0x02C
    virtual void slot_012();  // slot +0x030
    virtual void slot_013();  // slot +0x034
    virtual void slot_014();  // slot +0x038
    virtual void slot_015();  // slot +0x03C
    virtual void slot_016();  // slot +0x040
    virtual void slot_017();  // slot +0x044
    virtual void slot_018();  // slot +0x048
    virtual void slot_019();  // slot +0x04C
    virtual void slot_020();  // slot +0x050
    virtual void slot_021();  // slot +0x054
    virtual void slot_022();  // slot +0x058
    virtual void slot_023();  // slot +0x05C
    virtual void slot_024();  // slot +0x060
    virtual void slot_025();  // slot +0x064
    virtual void slot_026();  // slot +0x068
    virtual void slot_027();  // slot +0x06C
    virtual void slot_028();  // slot +0x070
    virtual void slot_029();  // slot +0x074
    virtual void slot_030();  // slot +0x078
    virtual void slot_031();  // slot +0x07C
    virtual void slot_032();  // slot +0x080
    virtual void slot_033();  // slot +0x084
    virtual void slot_034();  // slot +0x088
    virtual void slot_035();  // slot +0x08C
    virtual void slot_036();  // slot +0x090
    virtual void slot_037();  // slot +0x094
    virtual void slot_038();  // slot +0x098
    virtual void slot_039();  // slot +0x09C
    virtual void slot_040();  // slot +0x0A0
    virtual void slot_041();  // slot +0x0A4
    virtual void slot_042();  // slot +0x0A8
    virtual void slot_043();  // slot +0x0AC
    virtual void slot_044();  // slot +0x0B0
    virtual void slot_045();  // slot +0x0B4
    virtual void slot_046();  // slot +0x0B8
    virtual void slot_047();  // slot +0x0BC
    virtual void slot_048();  // slot +0x0C0
    virtual void slot_049();  // slot +0x0C4
    virtual void slot_050();  // slot +0x0C8
    virtual void slot_051();  // slot +0x0CC
    virtual void slot_052();  // slot +0x0D0
    virtual void slot_053();  // slot +0x0D4
    virtual void slot_054();  // slot +0x0D8
    virtual void slot_055();  // slot +0x0DC
    virtual void slot_056();  // slot +0x0E0
    virtual void slot_057();  // slot +0x0E4
    virtual void slot_058();  // slot +0x0E8
    virtual void slot_059();  // slot +0x0EC
    virtual void slot_060();  // slot +0x0F0
    virtual void slot_061();  // slot +0x0F4
    virtual void slot_062();  // slot +0x0F8
    virtual void slot_063();  // slot +0x0FC
    virtual void slot_064();  // slot +0x100
    virtual void slot_065();  // slot +0x104
    virtual void slot_066();  // slot +0x108
    virtual void slot_067();  // slot +0x10C
    virtual void slot_068();  // slot +0x110
    virtual void slot_069();  // slot +0x114
    virtual void slot_070();  // slot +0x118
    virtual void slot_071();  // slot +0x11C
    virtual void slot_072();  // slot +0x120

    char pad_04[0x0c - 0x04];     // +0x04..+0x0C
    int field_c;                  // +0x0C
    int field_10;                 // +0x10
    int field_14;                 // +0x14
    int field_18;                 // +0x18
    char pad_1c[0xfc - 0x1c];     // +0x1C..+0xFC
    short field_fc;               // +0xFC clamp bound
    short field_fe;               // +0xFE
    short field_100;              // +0x100
    short field_102;              // +0x102
    short field_104;              // +0x104
    char pad_106[0x150 - 0x106];  // +0x106..+0x150
    short field_150;              // +0x150
    char pad_152[0x154 - 0x152];  // +0x152..+0x154
    int field_154;                // +0x154
    unsigned char field_158;      // +0x158
    unsigned char field_159;      // +0x159
    unsigned char field_15a;      // +0x15A
    unsigned char field_15b;      // +0x15B
    unsigned char field_15c;      // +0x15C
    unsigned char field_15d;      // +0x15D
    char pad_15e[0x160 - 0x15e];  // +0x15E..+0x160
    int field_160;                // +0x160 display mode
    int field_164;                // +0x164
    unsigned char field_168;      // +0x168
    char pad_169[0x16c - 0x169];  // +0x169..+0x16C
    int field_16c;                // +0x16C
    unsigned char field_170;      // +0x170
    char pad_171[0x188 - 0x171];  // +0x171..+0x188
    int field_188;                // +0x188
    unsigned char field_18c;      // +0x18C
    unsigned char field_18d;      // +0x18D
    unsigned char field_18e;      // +0x18E
    unsigned char field_18f;      // +0x18F
    unsigned char field_190;      // +0x190
    unsigned char field_191;      // +0x191
    char pad_192[0x198 - 0x192];  // +0x192..+0x198
    int field_198;                // +0x198 active flag
    int field_19c;                // +0x19C mode
    char pad_1a0[0x1ac - 0x1a0];  // +0x1A0..+0x1AC
    int field_1ac;                // +0x1AC last tick
    int field_1b0;                // +0x1B0 tick interval
    int field_1b4;                // +0x1B4 one-shot mode
    int field_1b8;                // +0x1B8 one-shot gate
    char pad_1bc[0x1c0 - 0x1bc];  // +0x1BC..+0x1C0
    int field_1c0;                // +0x1C0
    char pad_1c4[0x40];           // +0x1C4..

    int Other_4BBD30(int v);
    void M_4BBC20(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    void Other_4BCF90(int a1, int a2, int a3);

    static int __stdcall M_4B6840(int v);
    void M_4BCEB0(short v);
    void M_4BAE20(int* a1, short a2);
    void Hook_4A1160();           // unresolved callee at 0x4A1160
    void Hook_4B60B0(int a1, short a2, int a3); // unresolved callee at 0x4B60B0
    void Hook_4BA5C0(int a1, int a2); // unresolved callee at 0x4BA5C0
    void Hook_4BBF20(int a1, short a2, int a3); // unresolved callee at 0x4BBF20
    void M_4B5690();
    void Hook_4BA250(int a1, int a2, int a3, int a4, int a5, int a6, int* a7,
                     int a8, int a9, int a10, int a11, int a12, int a13,
                     int a14, int a15, int a16, int a17);
    void M_4BA390(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                  int a8, int a9, int a10, int a11, int a12, int a13,
                  int a14, int a15, int a16, int a17);
    int M_4B5AB0();
    void M_4B5A10(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    void M_4B3760(int a1, unsigned char a2, unsigned char a3, unsigned char a4, unsigned char a5, unsigned char a6, unsigned char a7);
};
