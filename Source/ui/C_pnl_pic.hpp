// C_pnl_pic — recovered panel-picture class. Vtable 0x622D6C has 61 slots;
// the declaration chain preserves every slot offset. Data fields begin after
// the implicit vtable pointer.
#pragma once

#include "Function.hpp"

class C_pnl_pic {
public:
    virtual void slot_000();  // slot +0x000
    virtual void slot_001();  // slot +0x004
    virtual void slot_002();  // slot +0x008
    virtual void slot_003();  // slot +0x00C
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
    virtual void slot_038(int a, int b, int c, int d);  // slot +0x098
    virtual void slot_039();  // slot +0x09C
    virtual void slot_040();  // slot +0x0A0
    virtual void slot_041();  // slot +0x0A4
    virtual void slot_042();  // slot +0x0A8
    virtual void slot_043(int a, int b, int c, int d);  // slot +0x0AC
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

    char pad_04[0x5c - 0x04];     // +0x04..+0x5C
    void* field_5c;                // +0x5C node chain head
    char pad_60[0x6c - 0x60];      // +0x60..+0x6C
    void* field_6c;                // +0x6C active subobject
    char pad_70[0xc0 - 0x70];      // +0x70..+0xC0
    int field_c0;                  // +0xC0 threshold
    char pad_c4[0xc8 - 0xc4];      // +0xC4..+0xC8
    int field_c8;                  // +0xC8
    int field_cc;                  // +0xCC
    int field_d0;                  // +0xD0
    int field_d4;                  // +0xD4
    int field_d8;                  // +0xD8 elapsed base
    char pad_dc[0xf0 - 0xdc];      // +0xDC..+0xF0
    unsigned char field_f0;        // +0xF0 state
    unsigned char field_f1;        // +0xF1 mode
    char pad_f2[0xf8 - 0xf2];      // +0xF2..+0xF8
    int field_f8;                  // +0xF8
    int field_fc;                  // +0xFC
    char pad_100[0x120 - 0x100];   // +0x100..+0x120
    int field_120;                 // +0x120
    int field_124;                 // +0x124
    char pad_128[0x1b8 - 0x128];   // +0x128..+0x1B8
    int field_1b8;                 // +0x1B8 mode
    char pad_1bc[0x218 - 0x1bc];   // +0x1BC..+0x218
    int field_218;                // +0x218
    int field_21c;                // +0x21C
    char pad_220[0x224 - 0x220];  // +0x220..+0x224
    int field_224;                // +0x224
    int field_228;                // +0x228
    int field_22c;                // +0x22C

    void M_4B8510();
    int M_4A1160();
    int M_4B88B0(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                 int a8, int a9, int a10, int a11, int a12, int a13,
                 int a14, int a15);
    int M_4A0460(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};
