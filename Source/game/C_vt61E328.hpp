// C_vt61E328 — vtable class 0x61E328 (skeleton: Source/skeleton/game/
// C_vt61E328_61E328.h holds all slots and lifted methods).
// This TU carries the 8 byte-verified methods. Only the virtual slot used by
// 0x436B20 (+0x40) is declared; fields start after the vptr.
#pragma once

#include "Function.hpp"

struct S436B20Sub {
public:
    char pad_00[0x18];
    int field_18;
};

class C_vt61E328 {
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
    virtual void Vat_40(int v);

    char pad_04[0x08 - 4];
    void* field_08;               // +0x08, generic pointer to a subobject
    char pad_0C[0x168 - 0x0C];
    float field_168;              // +0x168

    float Get_434BE0(int unused);
    unsigned char M_435810();
    void M_4359B0(int* a, int* b);
    void M_4359E0(int* a, int* b);
    int M_436B20();
    float Get_436B40();
    float Get_436C50();
    float Get_436C60();
};
