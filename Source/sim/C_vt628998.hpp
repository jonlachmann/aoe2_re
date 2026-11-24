// C_vt628998 — vtable class 0x628998 (skeleton: Source/skeleton/sim/
// C_vt628998_628998.h holds all slots and lifted methods).
// This TU carries the 2 byte-verified methods. Both use the pointer at +8, but
// through different chains, so it is a generic void* with per-body casts.
#pragma once

#include "Function.hpp"

struct C544FD0 {
    int field_0;
    float field_4;
};

struct B544FD0 {
    char pad_00[0xa8];
    C544FD0* field_a8;
};

struct A544FD0 {
    char pad_00[0xc];
    B544FD0* field_c;
};

class C_vt628998 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008();
    virtual void slot_009();
    virtual void slot_010();
    virtual void slot_011();
    virtual void slot_012();
    virtual void slot_013();
    virtual void slot_014();
    virtual void slot_015();
    virtual void slot_016();
    virtual void slot_017();
    virtual void slot_018();
    virtual void slot_019();
    virtual void slot_020();
    virtual void slot_021();
    virtual void slot_022();
    virtual void Vat_5c(int v);

    char pad_04[0x08 - 4];
    void* field_08;               // +0x08, generic pointer in both methods
    unsigned char field_0C;       // +0x0C
    char pad_0D[0x2C - 0x0D];
    int field_2C;                 // +0x2C

    void M_544E70(unsigned char v);
    int M_544FD0();
};
