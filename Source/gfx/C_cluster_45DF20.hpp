// C_cluster_45DF20 — cluster anchored at 0x45DF20 (gfx region).
// This TU carries the 6-byte global function-pointer thunk at 0x5ECE5C. The
// target pointer lives in runtime data at 0x61C014.
#pragma once

#include "Function.hpp"

// Object at +0x18: slot +0x08 takes one argument, slot +0x20 takes five.
class T45DFObj {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_08(int a1);                                    // +0x08
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_20(int a1, int a2, int a3, int a4, int a5);    // +0x20
    char pad_24[0xa0 - 0x24];
    int field_a0;                 // +0xA0
    int field_a4;                 // +0xA4
};

class C_cluster_45DF20 {
public:
    char pad_00[0x18];
    int field_18;                 // +0x18 object pointer
    char pad_1c[0x54 - 0x1c];
    int field_54;                 // +0x54
    int field_58;                 // +0x58
    int field_5c;                 // +0x5C
    int field_60;                 // +0x60
    int field_64;                 // +0x64

    void M_5ECE5C();
    void M_45DF20(int a1);
};
