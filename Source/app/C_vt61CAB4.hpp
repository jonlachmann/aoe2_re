// C_vt61CAB4 — vtable class 0x61CAB4 (skeleton: Source/skeleton/app/
// C_vt61CAB4_61CAB4.h holds all slots and lifted methods).
// This TU carries the 2 byte-verified methods. 0x4061C0 walks a linked list at
// +0x08 and dispatches slot +0x40 on each node object.
#pragma once

#include "Function.hpp"

struct N4061C0 {
    char* obj_0;
    N4061C0* next_4;
};

class T4061C0 {
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
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vat_40(int v);
};

class C_vt61CAB4 {
public:
    char pad_00[8];
    N4061C0* field_08;            // +0x08 list head

    void M_4061C0(int v);
    void Clear_406220(char* p);
};
