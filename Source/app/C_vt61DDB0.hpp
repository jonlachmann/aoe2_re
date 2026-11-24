// C_vt61DDB0 — vtable class 0x61DDB0 (skeleton: Source/skeleton/app/
// C_vt61DDB0_61DDB0.h holds all slots and lifted methods).
// This TU carries the single byte-verified list dispatch (0x41AAC0). The node
// object dispatches through slot +0x28, so that slot is declared.
#pragma once

#include "Function.hpp"

class T41AAC0 {
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
    virtual void Vat_28(int a, int b);
};

struct N41AAC0 {
    T41AAC0* obj_0;
    int field_4;
    N41AAC0* next_8;
};

class C_vt61DDB0 {
public:
    char pad_00[4];
    N41AAC0* list_4;              // +0x04
    int field_8;                  // +0x08

    void M_41AAC0(int arg, int unused1, int unused2);
};
