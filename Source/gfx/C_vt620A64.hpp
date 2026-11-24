// C_vt620A64 — vtable class 0x620A64 (skeleton: Source/skeleton/gfx/
// C_vt620A64_620A64.h holds all 43 slots and lifted methods).
// This TU carries the 26 byte-verified methods. Only the virtual slots needed
// by 0x4886F0 (+0x28 and +0x4C) are declared here; the rest stay in the
// evidence skeleton. The +0x64/+0x70 regions are 3-int subobjects (Three46).
#pragma once

#include "Function.hpp"

struct Three46 {
    int a;
    int b;
    int c;
};

class C_vt620A64 {
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
    virtual void Vat_28(int v);
    virtual void slot_11();
    virtual void slot_12();
    virtual void slot_13();
    virtual void slot_14();
    virtual void slot_15();
    virtual void slot_16();
    virtual void slot_17();
    virtual void slot_18();
    virtual void Vat_4c(int v);

    char pad_04[0x64 - 4];
    Three46 field_64;             // +0x64
    Three46 field_70;             // +0x70
    char pad_7C[0x94 - 0x7C];
    float field_94;               // +0x94
    float field_98;               // +0x98
    float field_9C;               // +0x9C
    char pad_A0[0xAC - 0xA0];
    int field_AC;                 // +0xAC
    int field_B0;                 // +0xB0

    C_vt620A64* Ref_46A900();
    C_vt620A64* Ref_46A940();
    C_vt620A64* Ref_46A950();
    C_vt620A64* Ref_46A960();
    C_vt620A64* Ref_46A970();
    void Copy_46A980(Three46* src);
    float Get_46A9A0();
    void SetInt_46A9B0(int v);
    void SetInt_46A9C0(int v);
    float Get_46A9D0();
    void SetInt_46A9E0(int v);
    float Get_46A9F0();
    void SetInt_46AA00(int v);
    C_vt620A64* Ref_46AA10();
    void Copy_46AA20(Three46* src);
    float Get_46AA40();
    void SetInt_46AA50(int v);
    float Get_46AA60();
    void SetInt_46AA70(int v);
    float Get_46AA80();
    void SetInt_46AA90(int v);
    float Get_46AAA0();
    float Get_46AAB0();
    float Get_46AAC0();
    void SetInt_46AB60(int v);
    void M_4886F0();
};
