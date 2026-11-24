// C_vt61CE24 — vtable class 0x61CE24 (skeleton: Source/skeleton/app/
// C_vt61CE24_61CE24.h holds all 204 slots and every lifted method).
// This TU carries the 48 byte-verified methods. The layout is partial: only
// the offsets those methods touch are reconstructed. Fields at +0x08, +0x10,
// +0x18 and +0x24 are generic pointers because different methods address
// different subobjects there; each body casts to its own helper type.
#pragma once

#include "Function.hpp"

// 3-int struct returned by value from the pair of vec getters.
struct S407CB0Vec3 {
    int x, y, z;
};

// Subobject at [this+0x08] used by the 0x408660/0x408670 forwarders.
class S408660Target {
public:
    virtual void Vat_0();
    virtual void Vat_1();
    virtual void Vat_2();
    virtual void Vat_3();
    virtual void Vat_4();
    virtual void Vat_5();
    virtual void Vat_6();
    virtual void Vat_7();
    virtual void Vat_8();
    virtual void Vat_9();
    virtual void Vat_10();
    virtual void Vat_11();
    virtual void Vat_30(int arg);
    virtual void Vat_34(int arg);
};

// Subobject at [this+0x08] used by 0x4921B0/0x4921D0.
class S492100Sub {
public:
    char pad_00[0xc8];
    int* field_c8;
    int* field_cc;
};

// Subobject at [this+0x08] used by 0x4921F0.
class T4921F0 {
public:
    char pad_00[0x18];
    char* field_18;
};

// Subobject at [this+0x18] forwarded to by 0x52A440.
class T41A820 {
public:
    void Other_41A820(int v);
};

// Subobjects used by the inlined compare in 0x52AE20.
class S52AE20A {
public:
    char pad_00[4];
    int field_4;
};

class S52AE20B {
public:
    char pad_00[0x30];
    unsigned char field_30;
};

class C_vt61CE24 {
public:
    // Only the virtual slots up to +0x40 are needed here: 0x4921B0/0x4921D0
    // dispatch through slot +0x40 on this object.
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
    virtual void Vat_40(void* p);

    char pad_04[8 - 4];
    void* field_08;               // +0x08, generic subobject pointer
    int field_0C;                 // +0x0C
    void* field_10;               // +0x10, generic subobject pointer
    char pad_14[0x18 - 0x14];
    void* field_18;               // +0x18, generic subobject pointer
    char pad_1C[0x24 - 0x1C];
    void* field_24;               // +0x24, generic subobject pointer
    char pad_28[0x44 - 0x28];
    int field_44;                 // +0x44
    char pad_48[0x4C - 0x48];
    unsigned short field_4C;      // +0x4C
    char pad_4E[0x4F - 0x4E];
    char field_4F;                // +0x4F
    char pad_50[0x76 - 0x50];
    char field_76;                // +0x76
    char pad_77[0xA4 - 0x77];
    float field_A4;               // +0xA4
    char pad_A8[0xB8 - 0xA8];
    float field_B8;               // +0xB8
    char pad_BC[0xD8 - 0xBC];
    int* records;                 // +0xD8, 12-byte stride
    int count;                    // +0xDC
    char pad_E0[0xE4 - 0xE0];
    S407CB0Vec3 vec_E4;           // +0xE4
    S407CB0Vec3 vec_F0;           // +0xF0
    char pad_FC[0x108 - 0xFC];
    void* field_108;              // +0x108, generic subobject pointer
    char pad_10C[0x110 - 0x10C];
    void* field_110;              // +0x110, generic subobject pointer
    int field_114;                // +0x114

    bool M_407B30();
    int M_407B40();
    int M_407B80(int unused);
    float Get_407B90(int unused);
    int M_407BA0();
    float Get_407BB0();
    bool M_407BC0(int unused);
    bool M_407BD0(int unused);
    bool M_407BE0();
    void M_407BF0(int a, int b, int c, int d, int e, int f);
    int M_407C30(int a, int b, int c, int d, int e, int f);
    void M_407C50(int unused);
    int M_407C60(int unused);
    float Get_407C70();
    float Get_407C80();
    void Set_407C90();
    int Get_407CA0();
    S407CB0Vec3 CopyE4_407CB0();
    int Get_407CE0();
    int Get_407CF0();
    S407CB0Vec3 CopyF0_407D00();
    void M_408650(int unused);
    void Wrap_408660();
    void Wrap_408670();
    float Get_408BC0();
    float Get_41A0A0(int a, int b, int c, int d);
    char Dec_41A410(int unused);
    float Get_4747F0(int unused);
    float Get_474800();
    unsigned char M_48CB90();
    void Set_48CBB0();
    double Get_48E2D0();
    void SetByte_48E330(unsigned char v);
    int Get_48E340(int index);
    float M_48F470();
    float M_48F520();
    void M_48F950(int v);
    int Get_48F970();
    double Get_4919A0(int unused);
    int UseCC_4921B0();
    int UseC8_4921D0();
    int M_4921F0();
    void M_52A440(int v);
    bool Less_52AE20();
    void Set_52B330(unsigned short a, int b);
    char Get_52BC80();
    void SetByte_52BC90(unsigned char v);
    int Get_52C6A0();

    int Value()
    {
        if (!field_24)
            return 0;
        return ((S52AE20A*)field_24)->field_4;
    }
};
