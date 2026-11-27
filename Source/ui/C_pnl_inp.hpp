// C_pnl_inp — recovered panel-input class (skeleton: Source/skeleton/ui/
// C_pnl_inp_<vtable>.h). This TU carries the 3 byte-verified methods. 0x4BAF60
// dispatches through slot +0xF4, so placeholder slots run to that index.
#pragma once

#include "Function.hpp"

class C_pnl_inp;

// Indexed node chain reached from C_pnl_inp::field_f8 (0x4BD4B0). Each node
// holds the result at +0x00 and the successor at +0x24.
class T4BD5F0Chain {
public:
    char pad_00[8];
    T4BD5F0Chain* next_8;         // +0x08
};

class T4BD4B0Node {
public:
    void* field_0;                // +0x00 output A
    void* field_4;                // +0x04 output A2
    char pad_08[0xc - 8];
    void* field_c;                // +0x0C output B
    unsigned char field_10;       // +0x10 optional geometry flag
    char pad_11[0x14 - 0x11];
    int field_14;                 // +0x14
    int field_18;                 // +0x18
    int field_1c;                 // +0x1C
    int field_20;                 // +0x20
    T4BD4B0Node* next_24;         // +0x24
};

// Subobject at [C_pnl_inp+0x148] used by 0x4BBCE0; it dispatches +0x14 (slot 5).
class T4BBCE0Sub {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vat_14(int v);        // slot +0x14 (index 5)
    virtual void Vt_05();              // slot +0x18 (index 6)
    virtual void Vat_1c(int a1, int a2, int a3, int a4);  // slot +0x1C (index 7)
};

// Subobject at [this+0x40] used by 0x4BCE20. It dispatches slot +0xC4 (index
// 49) and receives the outer object plus three literal flags.
class T4BCE20Sub {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
    virtual void Vt_09();
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
    virtual void Vat_C4(C_pnl_inp* owner, int a, int b, int c);
};

class C_pnl_inp {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008(int a1);
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
    virtual void slot_023();
    virtual void slot_024();
    virtual void slot_025();
    virtual void slot_026();
    virtual void slot_027();
    virtual void slot_028();
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
    virtual void Vat_f4(int a, int b);
    virtual void Vat_f8();
    virtual void Vat_fc(char* a1, int a2);
    virtual void slot_064();
    virtual void slot_065();
    virtual void slot_066();
    virtual void slot_067();
    virtual void slot_068();
    virtual void slot_069();
    virtual void slot_070();
    virtual void slot_071();
    virtual void Vat_120();       // slot +0x120 (index 72)

    char pad_04[0x40 - 4];
    T4BCE20Sub* field_40;         // +0x40, subobject dispatched by 0x4BCE20
    char pad_44[0x6c - 0x44];
    int field_6c;                 // +0x6C
    char pad_70[0xf8 - 0x70];
    T4BD4B0Node* field_f8;        // +0xF8 head of the indexed node chain
    short field_fc;               // +0xFC capacity
    char pad_fe[0x100 - 0xfe];    // +0xFE..+0x100
    char* field_100;              // +0x100 text buffer
    int field_104;                // +0x104 text length
    char pad_108[0x148 - 0x108];  // +0x108..+0x148
    T4BBCE0Sub* field_148;        // +0x148 subobject dispatched by 0x4BBCE0
    int field_14c;                // +0x14C gate
    int field_150;                // +0x150 text flag
    char pad_154[0x184 - 0x154];  // +0x154..+0x184
    int field_184;                // +0x184
    int field_188;                // +0x188
    unsigned char field_18c;      // +0x18C
    unsigned char field_18d;      // +0x18D
    unsigned char field_18e;      // +0x18E
    unsigned char field_18f;      // +0x18F
    unsigned char field_190;      // +0x190
    unsigned char field_191;      // +0x191
    char pad_192[0x198 - 0x192];  // +0x192..+0x198
    int field_198;                // +0x198

    void Hook_4A07A0(int a1);     // unresolved shared slot body at 0x4A07A0
    void Other_4A2140(int a1, char* a2, int a3);
    void M_408050(int a, int b);
    void M_4BBCE0(int a1);
    void M_4BA410(int a1, int a2, int a3, int a4);
    void M_4BA5C0(char* a1, char* a2);
    void Hook_4BA810(void* a1, void* a2, int a3);
    void M_4BADD0(int a1);
    char* M_4BD4B0(int index);
    void M_4BD4E0(int index, void* a2, void* a3, int* a4, int* a5, unsigned char flag);
    void SetInt_4B4600(int v);
    void Hook_4BBD30(int a1);
    void M_4B3160(char* a2);
    void M_4BBC20(int a1, char a2, char a3, char a4, char a5, char a6, char a7);
    void M_4BD5F0();
    void M_4BAF60(int a, int b, int c, int d);
    int M_4BCE20(int a, int b, int c, int d);
    int M_4B36D0(int a2);
};
