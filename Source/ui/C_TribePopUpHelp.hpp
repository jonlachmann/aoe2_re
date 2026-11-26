// C_TribePopUpHelp — vtable class 0x620274 (gfx anchor, ui method). This TU
// carries the byte-verified toggle (0x4A1E20): outer slot +0x20 and the +0xD0
// slot of the subobject at +0x3C. Fields +0x3C and +0x78 are proven there.
#pragma once

#include "Function.hpp"

// Subobject at [C_TribePopUpHelp+0x3C]. It dispatches one argument through
// slot +0xD0 (index 52), so a 52-slot base precedes the used slot.
class T4A1E20SubBase {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
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
};

class T4A1E20Sub : public T4A1E20SubBase {
public:
    virtual void Vat_d0(int v);   // +0xD0 (index 52)
};

// Node reached through the chain at +0x58: object pointer at +0x00, next node
// at +0x08. The object dispatches one-argument slot +0x20 and plain slot +0x54.
struct T4A1440Node {
    void* obj_0;                  // +0x00
    char pad_4[4];                // +0x04..+0x08
    T4A1440Node* field_8;         // +0x08 next node
};

class T4A1440Obj {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08(int v);    // +0x20
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
    virtual void Vt_21();         // +0x54
};

// Object at +0x40: +0x7C gate and a three-argument slot +0x24 (index 9).
class T4A1440Field40 {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
    virtual void Vt_09(int a1, int a2, int a3);  // +0x24
    char pad_04[0x7c - 0x04];
    int field_7c;                 // +0x7C
};

// Object at +0x20 with the gate word at +0x04.
struct T4A1440Field20 {
    char pad_00[4];
    int field_4;                  // +0x04
};

class C_TribePopUpHelp {
public:
    virtual void slot_00();
    virtual void slot_01();
    virtual void slot_02();
    virtual void slot_03();
    virtual void slot_04();
    virtual void slot_05();
    virtual void slot_06();
    virtual void slot_07();
    virtual void slot_08(int v);  // +0x20
    virtual void slot_09(int a1, int a2, int a3); // +0x24
    virtual void slot_10();       // +0x28
    virtual void slot_11();       // +0x2C
    virtual void slot_12();       // +0x30
    virtual void slot_13();       // +0x34
    virtual void slot_14();       // +0x38
    virtual void slot_15();       // +0x3C
    virtual void slot_16();       // +0x40
    virtual void slot_17();       // +0x44
    virtual void slot_18();       // +0x48
    virtual void slot_19();       // +0x4C
    virtual void slot_20();       // +0x50
    virtual void slot_21();       // +0x54

    char pad_04[0x20 - 4];
    int field_20;                 // +0x20 gate object
    char pad_24[0x38 - 0x24];
    int field_38;                 // +0x38 active data
    T4A1E20Sub* field_3c;         // +0x3C
    int field_40;                 // +0x40 gate object
    char pad_44[0x58 - 0x44];
    T4A1440Node* field_58;        // +0x58 node chain head
    char pad_5c[0x6c - 0x5c];
    int field_6c;                 // +0x6C
    int field_70;                 // +0x70
    char pad_74[0x78 - 0x74];
    int field_78;                 // +0x78
    char pad_7c[0x84 - 0x7c];
    int field_84;                 // +0x84

    void M_4A1E20(int v);
    int M_4A1440();
};
