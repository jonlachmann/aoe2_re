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

class C_vt61CE24;

// Forward target used by the 0x407E30/407FB0/408010/408030 wrappers.
class T4058C0Target {
public:
    void Clear_4058C0();          // unresolved callee at 0x4058C0
    void Clear_405860();          // unresolved callee at 0x405860
};

// Subobject at [this+0x20] used by 0x52AF30. It dispatches slot +0xEC (index
// 59) and receives the outer object as its only argument.
class T52AF30Sub {
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
    virtual void Vt_52();
    virtual void Vt_53();
    virtual void Vt_54();
    virtual void Vt_55();
    virtual void Vt_56();
    virtual void Vt_57();
    virtual void Vt_58();
    virtual void Vat_EC(C_vt61CE24* owner);
};

class C_vt61CE24 {
public:
    // Only the virtual slots up to +0x40 are needed here: 0x4921B0/0x4921D0
    // dispatch through slot +0x40 on this object.
    virtual void slot_000();
    virtual void M_407E50(int a1, int a2, int a3, int a4, int a5);  // slot +0x04
    virtual void M_407E30();      // slot +0x08
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008();
    virtual void slot_009();
    virtual void slot_010();
    virtual void M_407FB0();      // slot +0x2C
    virtual void slot_012();
    virtual void slot_013();
    virtual void slot_014();
    virtual void slot_015();
    virtual void Vat_40(void* p);
    virtual void slot_017();
    virtual void slot_018();
    virtual void slot_019();
    virtual void slot_020();
    virtual void slot_021();
    virtual void slot_022();
    virtual void M_408010(int a1);  // slot +0x5C
    virtual void slot_024();
    virtual void slot_025();
    virtual void slot_026();
    virtual void slot_027();
    virtual void M_408030();      // slot +0x70
    virtual void slot_029();
    virtual void slot_030();
    virtual void slot_031();
    virtual void slot_032();
    virtual void slot_033();
    virtual void slot_034();
    virtual void slot_035();
    virtual void slot_036();
    virtual void slot_037();
    virtual void slot_038();
    virtual void slot_039();
    virtual void slot_040();
    virtual void slot_041();
    virtual void slot_042();
    virtual void slot_043();
    virtual void slot_044();
    virtual void slot_045();
    virtual void slot_046();
    virtual void slot_047();
    virtual void slot_048();
    virtual void slot_049();
    virtual void slot_050();
    virtual void slot_051();
    virtual void slot_052();
    virtual void slot_053();
    virtual void slot_054();
    virtual void slot_055();
    virtual void slot_056();
    virtual void slot_057();
    virtual void slot_058();
    virtual void slot_059();
    virtual void slot_060();
    virtual void slot_061();
    virtual void slot_062();
    virtual void slot_063();
    virtual void slot_064();
    virtual void slot_065();
    virtual void slot_066();
    virtual void slot_067();
    virtual void slot_068();
    virtual void slot_069();
    virtual void slot_070();
    virtual void slot_071();
    virtual void slot_072();
    virtual void slot_073();
    virtual void slot_074();
    virtual void slot_075();
    virtual void slot_076();
    virtual void slot_077();
    virtual void slot_078();
    virtual void slot_079();
    virtual void slot_080();
    virtual void slot_081();
    virtual void slot_082();
    virtual void slot_083();
    virtual void slot_084();
    virtual void slot_085();
    virtual void slot_086();
    virtual void slot_087();
    virtual void slot_088();
    virtual void slot_089();
    virtual void slot_090();
    virtual void slot_091();
    virtual void slot_092();
    virtual void slot_093();
    virtual void slot_094();
    virtual void slot_095();
    virtual void slot_096();
    virtual void slot_097();
    virtual void slot_098();
    virtual void slot_099();
    virtual void slot_100();
    virtual void slot_101();
    virtual void slot_102();
    virtual void slot_103();
    virtual void slot_104();
    virtual void slot_105();
    virtual void slot_106();
    virtual void slot_107();
    virtual void slot_108();
    virtual void slot_109();
    virtual void slot_110();
    virtual void slot_111();
    virtual void slot_112();
    virtual void slot_113();
    virtual void slot_114();
    virtual void slot_115();
    virtual void slot_116();
    virtual void slot_117();
    virtual void slot_118();
    virtual void slot_119();
    virtual void slot_120();
    virtual void slot_121();
    virtual void slot_122();
    virtual void slot_123();
    virtual void slot_124();
    virtual void slot_125();
    virtual void slot_126();
    virtual void slot_127();
    virtual void slot_128();
    virtual void slot_129();
    virtual void slot_130();
    virtual void slot_131();
    virtual void slot_132();
    virtual void slot_133();
    virtual void slot_134();
    virtual void slot_135();
    virtual void slot_136();
    virtual void slot_137();
    virtual void slot_138();
    virtual void slot_139();
    virtual void slot_140();
    virtual void slot_141();
    virtual void slot_142();
    virtual void slot_143();
    virtual void slot_144();
    virtual void slot_145();
    virtual void slot_146();
    virtual void slot_147();
    virtual void slot_148();
    virtual void slot_149();
    virtual void slot_150();
    virtual void slot_151();
    virtual void slot_152();
    virtual void slot_153();
    virtual void slot_154();
    virtual void slot_155();
    virtual void slot_156();
    virtual void slot_157();
    virtual void slot_158();
    virtual void slot_159();
    virtual void slot_160();
    virtual void slot_161();
    virtual void slot_162();
    virtual void slot_163();
    virtual void slot_164();
    virtual void slot_165();
    virtual void slot_166();
    virtual void slot_167();
    virtual void slot_168();
    virtual void slot_169();
    virtual void slot_170();
    virtual void slot_171();
    virtual void slot_172();
    virtual void slot_173();
    virtual void slot_174();
    virtual void slot_175();
    virtual void slot_176();
    virtual void slot_177();
    virtual void slot_178();
    virtual void slot_179();
    virtual void slot_180();
    virtual void slot_181();
    virtual void slot_182();
    virtual void slot_183();
    virtual void slot_184();
    virtual void slot_185();
    virtual void slot_186();
    virtual void slot_187();
    virtual void slot_188();
    virtual void Vat_2F4();
    virtual void slot_190();
    virtual void slot_191();
    virtual void slot_192();
    virtual void slot_193();
    virtual void Vat_308(void* a1, int a2, int a3, int a4, int a5, int a6);

    char pad_04[8 - 4];
    void* field_08;               // +0x08, generic subobject pointer
    int field_0C;                 // +0x0C
    void* field_10;               // +0x10, generic subobject pointer
    char pad_14[0x18 - 0x14];
    void* field_18;               // +0x18, generic subobject pointer
    char pad_1C[0x20 - 0x1C];
    T52AF30Sub* field_20;         // +0x20, subobject dispatched by 0x52AF30
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
    char pad_118[0x12c - 0x118];
    char byte_12c;                // +0x12C
    char pad_12d[0x130 - 0x12d];
    T4058C0Target* field_130;     // +0x130
    char byte_134;                // +0x134

    void Hook_526CA0();           // unresolved callee at 0x526CA0
    void Hook_529AF0();           // unresolved callee at 0x529AF0
    void Hook_52A990();           // unresolved callee at 0x52A990
    void Hook_48C240(int a1, int a2, int a3, int a4, int a5);  // unresolved callee at 0x48C240

    void M_408060(void* a1, int a2, int a3, int a4);
    void M_52AF30();
    void M_48D470(void* p);
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
