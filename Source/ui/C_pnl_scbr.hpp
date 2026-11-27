// C_pnl_scbr — recovered vtable class (vtable 0x622E60, 61 slots).
// 0x4B8CC0 is slot +0x4C; field offsets are provisional.
#pragma once

#include "Function.hpp"

class C_pnl_scbr {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008(int a1);
    virtual void slot_009();
    virtual void slot_010();
    virtual void slot_011();
    virtual void slot_012();
    virtual void slot_013();
    virtual void slot_014();
    virtual void slot_015();
    virtual void slot_016();
    virtual void slot_017();
    virtual void slot_018();
    virtual int M_4B8CC0();
    virtual void slot_020();
    virtual void slot_021();
    virtual void slot_022();
    virtual void slot_023();
    virtual void slot_024();
    virtual void slot_025();
    virtual void slot_026();
    virtual void slot_027();
    virtual void slot_028();
    virtual void slot_029();
    virtual void slot_030();
    virtual void slot_031();
    virtual void slot_032();
    virtual void slot_033();
    virtual void slot_034();
    virtual void slot_035();
    virtual void slot_036();
    virtual void slot_037();
    virtual void slot_038();
    virtual void slot_039();
    virtual void slot_040();
    virtual void slot_041();
    virtual void slot_042();
    virtual void slot_043();
    virtual void slot_044();
    virtual void slot_045();
    virtual void slot_046();
    virtual void slot_047();
    virtual void slot_048();
    virtual void slot_049();
    virtual void slot_050();
    virtual void slot_051();
    virtual void slot_052();
    virtual void slot_053();
    virtual void slot_054();
    virtual void slot_055();
    virtual void slot_056();
    virtual void slot_057();
    virtual void slot_058();
    virtual void slot_059();
    virtual void slot_060();

    char pad_04[0x148 - 0x04];
    unsigned char field_148;      // +0x148 switch state
    char pad_149[0x14c - 0x149];
    int field_14c;               // +0x14C active flag
    int field_150;               // +0x150
    int field_154;               // +0x154
    unsigned char field_158;      // +0x158 mode byte
    char pad_159[0x15c - 0x159];
    int field_15c;               // +0x15C last tick
    int field_160;               // +0x160 first interval
    int field_164;               // +0x164 second interval
    char pad_168[0x198 - 0x168];
    char obj_198[0x10];          // +0x198 rectangle block
    char obj_1a8[0x10];          // +0x1A8 rectangle block

    void M_4B93B0(int a1, int a2);       // unresolved callee at 0x4B93B0
    int M_4A1D50(int a1, int a2, void* a3); // unresolved callee at 0x4A1D50
};
