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

    char pad_04[0x3c - 4];
    T4A1E20Sub* field_3c;         // +0x3C
    char pad_40[0x78 - 0x40];
    int field_78;                 // +0x78

    void M_4A1E20(int v);
};
