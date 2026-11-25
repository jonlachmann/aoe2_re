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

    char pad_04[0x1c8 - 4];
    int field_1c8;                // +0x1C8
    int field_1cc;                // +0x1CC

    void Hook_4B8730();           // unresolved callee at 0x4B8730
    void Hook_4B8910(int a1, int a2, int a3, int a4);   // unresolved callee at 0x4B8910
    C_vt6230B0* Init_4B9D20();
};
