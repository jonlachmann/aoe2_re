// C_TRIBE_Screen_Options — recovered name TRIBE_Screen_Options (also
// panel_ez); vtable 0x625F80, 87 slots; skeleton:
// Source/skeleton/ui/C_TRIBE_Screen_Options_625F80.h.
// This TU carries the 11 byte-verified methods. Only the virtual slot used by
// 0x4A0BB0 (+0x34) is declared here; data fields start after the vptr.
#pragma once

#include "Function.hpp"

class C_TRIBE_Screen_Options {
public:
    virtual void slot_00();
    virtual void slot_01();
    virtual void slot_02();
    virtual void slot_03();
    virtual void slot_04();
    virtual void slot_05();
    virtual void slot_06();
    virtual void slot_07();
    virtual void slot_08();
    virtual void slot_09();
    virtual void slot_10();
    virtual void slot_11();
    virtual void slot_12();
    virtual void Vat_34(int v);

    char pad_04[0x60 - 4];
    int field_60;                 // +0x60
    int field_64;                 // +0x64
    char pad_68[0x74 - 0x68];
    int field_74;                 // +0x74
    char pad_78[0x90 - 0x78];
    int field_90;                 // +0x90
    int field_94;                 // +0x94
    int field_98;                 // +0x98
    int field_9C;                 // +0x9C
    char pad_A0[0xE8 - 0xA0];
    int field_E8;                 // +0xE8
    int field_EC;                 // +0xEC
    char pad_F0[0xF6 - 0xF0];
    unsigned char field_F6;       // +0xF6
    char pad_F7[0xF8 - 0xF7];
    int field_F8;                 // +0xF8
    int field_FC;                 // +0xFC

    int M_407C00(int a, int b);
    int M_407C10(int a, int b, int c, int d);
    void M_4237A0();
    int M_4364F0(int a, int b);
    int Get_4474F0();
    int Get_447500();
    void M_4A0BB0(int v);
    void M_4A2040(int a, int b);
    void Get_4A22F0(int* out);
    void SetF8_4A3410(int a, int b);
    int M_5C6890(int a, int b, int c, int d, int e);
};
