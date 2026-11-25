// C_pnl_edit — recovered panel-edit class (skeleton: Source/skeleton/ui/
// C_pnl_edit_622934.h). This TU carries the single byte-verified empty body
// (0x4378C0); the original is a plain entry point, so it stays static.
#pragma once

#include "Function.hpp"

class C_pnl_edit {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot02_4A0750(int a1, int a2, int a3, int a4);
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot08_4B3690(int a1);

    char pad_04[0x6c - 4];
    int field_6c;                 // +0x6C
    char pad_70[0x80 - 0x70];
    int field_80;                 // +0x80
    char pad_84[0xf2 - 0x84];
    unsigned char field_f2;       // +0xF2
    char pad_f3[0xf8 - 0xf3];
    void* field_f8;               // +0xF8
    short field_fc;               // +0xFC
    char pad_fe[0x100 - 0xfe];
    int field_100;                // +0x100
    char pad_104[0x108 - 0x104];
    int field_108;                // +0x108
    int field_10C;                // +0x10C
    char pad_110[0x114 - 0x110];
    int field_114[6];             // +0x114..+0x12C
    char pad_12c[0x150 - 0x12c];
    int field_150;                // +0x150
    int field_154;                // +0x154
    unsigned char array_158[6];   // +0x158..+0x15E
    char pad_15e[0x160 - 0x15e];
    int field_160;                // +0x160
    int field_164;                // +0x164
    int field_168;                // +0x168
    int field_16C;                // +0x16C
    int field_170;                // +0x170

    void Hook_4A0270();           // unresolved shared base init at 0x4A0270
    void Hook_4A07A0(int a1);     // unresolved shared slot body at 0x4A07A0
    void Hook_4A08C0(int a1);     // unresolved shared slot body at 0x4A08C0
    static void M_4378C0();
    void M_5ED9F4();
    void M_5ED9FA();
    void M_4B32F0(int a1);
    C_pnl_edit* M_4B2D50();
};
