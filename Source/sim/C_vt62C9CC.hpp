// C_vt62C9CC — vtable class 0x62C9CC (skeleton: Source/skeleton/sim/
// C_vt62C9CC_62C9CC.h holds all slots and lifted methods).
// This TU carries the byte getter at +0x29 (0x5E68D0) and the slot dispatcher
// 0x5E4380. Slot +0x34 needs 13 placeholders; they occupy the implicit vptr so
// field_29 stays at +0x29 after a pad of 0x25 from +0x04.
#pragma once

#include "Function.hpp"

// Subobject at [this+0x34] used by 0x5E3BE0. It dispatches slot +0x08 (index 2)
// with the four outer arguments.
class T5E3BE0Sub {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2(int a, int b, int c, int d);
};

class C_vt62C9CC {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual void Vt_6();
    virtual void Vt_7();
    virtual void Vt_8();
    virtual void Vt_9();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vat_34(int v);

    char pad_04[0x29 - 0x04];
    char field_29;                // +0x29
    char pad_2A[0x34 - 0x2A];
    T5E3BE0Sub* field_34;         // +0x34, subobject dispatched by 0x5E3BE0

    char Get_5E68D0();
    void M_5E4380(int arg);
    void M_5E3BE0(int a, int b, int c, int d);
};
