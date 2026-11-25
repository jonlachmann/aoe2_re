// C_vt61C800 — vtable class 0x61C800 (skeleton: Source/skeleton/app/
// C_vt61C800_61C800.h). This TU carries the 29-byte guard 0x403A20. It compares
// the raw int at +0x20 with the bit pattern of -1.0f and dispatches slot +0x5C.
#pragma once

#include "Function.hpp"

class C_vt61C800 {
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
    virtual int M_403C90(float unused, float a1, float a2, float a3);  // slot +0x34
    virtual void slot_14();
    virtual void slot_15();
    virtual void slot_16();
    virtual void slot_17();
    virtual void slot_18();
    virtual void slot_19();
    virtual void slot_20();
    virtual void slot_21();
    virtual void slot_22();
    virtual void Vat_5C(int v);

    char pad_04[0x1c];            // +0x04..+0x20
    float field_20;               // +0x20
    float field_24;               // +0x24
    float field_28;               // +0x28

    void M_403A20(int unused);
};
