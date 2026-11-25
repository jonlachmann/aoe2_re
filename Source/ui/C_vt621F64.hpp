// C_vt621F64 — vtable class 0x621F64 (ui). The constructor 0x49F4E0 writes
// this vtable and clears the +0x20/+0x48/+0xA70/+0xA98 record arrays; helper
// 0x49F9F0 allocates the +0x14 pool. Layout evidence from those two bodies.
#pragma once

#include "Function.hpp"

// Global 0x6645C4 object viewed through its +0x20 dispatch slot (index 8).
class T6645Slot {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void* Vt_08(int a1);
};

class C_vt621F64 {
public:
    virtual void slot_000();
    virtual void slot_001();

    int field_4;                  // +0x04
    int field_8;                  // +0x08
    int field_c;                  // +0x0C
    int field_10;                 // +0x10
    int field_14;                 // +0x14 pool pointer
    int field_18;                 // +0x18
    int field_1c;                 // +0x1C
    int array_20[10];             // +0x20
    char array_48[10 * 0x104];    // +0x48, one byte per 0x104-byte record
    int array_a70[10];            // +0xA70
    int array_a98[10];            // +0xA98
    int field_ac0;                // +0xAC0
    int field_ac4;                // +0xAC4
    int field_ac8;                // +0xAC8
    int field_acc;                // +0xACC
    int field_ad0;                // +0xAD0
    int field_ad4;                // +0xAD4
    int field_ad8;                // +0xAD8
    int field_adc;                // +0xADC
    int field_ae0;                // +0xAE0

    C_vt621F64* Init_49F4E0();
    int M_49F9F0();
    void M_49FED0();
    void M_49FE00(int a1);
};
