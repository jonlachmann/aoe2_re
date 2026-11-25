// C_TRIBE_Screen_Options — recovered name TRIBE_Screen_Options (also
// panel_ez); vtable 0x625F80, 87 slots; skeleton:
// Source/skeleton/ui/C_TRIBE_Screen_Options_625F80.h.
// This TU carries the 11 byte-verified methods. Only the virtual slot used by
// 0x4A0BB0 (+0x34) is declared here; data fields start after the vptr.
#pragma once

#include "Function.hpp"

// Object reached through the node chain walked by 0x4A2280/0x4A22D0. Slot
// +0xE0 (index 56) and +0xEC (index 59) are the ones those loops dispatch.
// Subobject reached through [C_TRIBE_Screen_Options+0x20] by 0x4A0C60.
class TField20Obj {
public:
    char pad_00[0x38];
    void* field_38;               // +0x38
    void Hook_460660(int a1);     // unresolved callee at 0x460660
};

class T4A2280Obj {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08(int v);
    virtual void Vt_09();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vt_23();
    virtual void Vt_24();
    virtual void Vt_25();
    virtual void Vt_26();
    virtual void Vt_27();
    virtual void Vt_28();
    virtual void Vt_29();
    virtual void Vt_30();
    virtual void Vt_31();
    virtual void Vt_32();
    virtual void Vt_33();
    virtual void Vt_34();
    virtual void Vt_35();
    virtual void Vt_36();
    virtual void Vt_37();
    virtual void Vt_38();
    virtual void Vt_39();
    virtual void Vt_40();
    virtual void Vt_41();
    virtual void Vt_42();
    virtual void Vt_43();
    virtual void Vt_44();
    virtual void Vt_45();
    virtual void Vt_46();
    virtual void Vt_47();
    virtual void Vt_48();
    virtual void Vt_49();
    virtual void Vt_50();
    virtual void Vt_51();
    virtual void Vt_52();
    virtual void Vt_53();
    virtual void Vt_54();
    virtual void Vt_55();
    virtual void Vt_56();
    virtual void Vt_57();
    virtual void Vt_58();
    virtual void Vt_59();
};

// Chain node at [this+0x58]: it holds the object pointer at +0x00 and the next
// node at +0x08.
class T4A2280Node {
public:
    T4A2280Obj* field_0;
    char pad_4[4];
    T4A2280Node* field_8;
};

class C_TRIBE_Screen_Options {
public:
    virtual void slot_00();
    virtual void slot_01();
    virtual void slot_02();
    virtual void slot_03();
    virtual void slot_04();
    virtual void slot_05();
    virtual void slot_06(int z0, int a1, int a2, int z1, int z2, int a3, int a3b, int a4, int a4b, int z3, int z4, int z5, int z6);
    virtual void slot_07();
    virtual void slot_08(int v);
    virtual void slot_09();
    virtual void slot_10();
    virtual void slot_11();
    virtual void slot_12();
    virtual void Vat_34(int v);

    char pad_04[0x20 - 4];
    TField20Obj* field_20;        // +0x20, subobject cleared by 0x4A0C60
    char pad_24[0x38 - 0x24];
    void* field_38;               // +0x38
    char pad_3c[0x40 - 0x3c];
    T4A2280Obj* field_40;         // +0x40, subobject toggled by 0x4A07A0
    char pad_44[0x58 - 0x44];
    T4A2280Node* field_58;        // +0x58, chain head
    char pad_5C[0x60 - 0x5C];
    int field_60;                 // +0x60
    int field_64;                 // +0x64
    char pad_68[0x6C - 0x68];
    int field_6C;                 // +0x6C
    char pad_70[0x74 - 0x70];
    int field_74;                 // +0x74
    char pad_78[0x90 - 0x78];
    int field_90;                 // +0x90
    int field_94;                 // +0x94
    int field_98;                 // +0x98
    int field_9C;                 // +0x9C
    char pad_A0[0xE8 - 0xA0];
    int field_E8;                 // +0xE8
    int field_EC;                 // +0xEC
    char pad_F0[0xF3 - 0xF0];
    unsigned char field_F3;       // +0xF3
    char pad_F4[0xF6 - 0xF4];
    unsigned char field_F6;       // +0xF6
    unsigned char field_F7;       // +0xF7, cleared by 0x4A0C60
    int field_F8;                 // +0xF8
    int field_FC;                 // +0xFC

    int M_407C00(int a, int b);
    int M_407C10(int a, int b, int c, int d);
    void M_4237A0();
    int M_4364F0(int a, int b);
    int Get_4474F0();
    int Get_447500();
    void Hook_4A1CD0();           // unresolved callee at 0x4A1CD0
    void M_4A0780(unsigned char v);
    void M_4A0890(int a1, int a2, int a3, int a4);
    void M_4A07A0(int v);
    void M_4A0C60();
    void M_4A2280();
    void M_4A22D0();
    void M_4A0BB0(int v);
    void M_4A2040(int a, int b);
    void Get_4A22F0(int* out);
    void SetF8_4A3410(int a, int b);
    int M_5C6890(int a, int b, int c, int d, int e);
};
