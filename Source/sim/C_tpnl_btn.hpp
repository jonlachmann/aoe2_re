// C_tpnl_btn — recovered panel-button class (vtable 0x62B970, 63 slots). The
// declarations preserve every vtable offset so slot calls in the body stay
// byte-exact. Fields begin after the implicit vtable pointer.
#pragma once

#include "Function.hpp"

class C_tpnl_btn {
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
    virtual void slot_019();
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
    virtual void slot_061();
    virtual void slot_062();

    char pad_04[0x2f0 - 0x04];     // +0x04..+0x2F0
    int field_2f0;                 // +0x2F0 running total
    char pad_2f4[0x5fc - 0x2f4];   // +0x2F4..+0x5FC
    unsigned char field_5fc;       // +0x5FC enabled flag
    char pad_5fd[0x5fe - 0x5fd];   // +0x5FD
    unsigned char field_5fe;       // +0x5FE reset flag
    char pad_5ff[0x600 - 0x5ff];   // +0x5FF..+0x600
    int field_600;                 // +0x600 base value
    char pad_604[0x608 - 0x604];   // +0x604..+0x608
    int field_608;                 // +0x608 tick counter
    unsigned int field_60c;        // +0x60C elapsed threshold
    unsigned int field_610;        // +0x610 last timestamp

    int M_5A6680();
};
