// C_vt61DF78 — vtable class 0x61DF78 (basegame; skeleton: Source/skeleton/
// app/C_vt61DF78_61DF78.h holds all 87 slots and lifted methods).
// This TU carries the 16 byte-verified methods. The three self-dispatching
// methods need their exact vtable offsets, so the placeholder slots run from
// +0x000 through +0x134; the rest stay in the evidence skeleton.
#pragma once

#include "Function.hpp"

// Subobject at [this+0x1b0] used by 0x4213D0.
class T42FAE0 {
public:
    void M_42FAE0(char* buf, int size);
};

class C_vt61DF78 {
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
    virtual void slot_009(char* a, char* buf, int size);
    virtual void slot_010(int a, int b, int e, int c, int d);
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
    virtual int slot_072(int a, int b);
    virtual int Vat_124();
    virtual void slot_074();
    virtual void slot_075();
    virtual int Vat_130();
    virtual int Vat_134();

    char pad_04[0x28 - 4];
    void* field_28;               // +0x28, window handle for SetWindowTextA
    char pad_2C[0x60 - 0x2C];
    int field_60;                 // +0x60
    char pad_64[0x1B0 - 0x64];
    void* field_1B0;              // +0x1B0, subobject for 0x4213D0
    char pad_1B4[0x1D8 - 0x1B4];
    int field_1D8;                // +0x1D8
    int field_1DC;                // +0x1DC
    int field_1E0;                // +0x1E0
    char pad_1E4[0x430 - 0x1E4];
    char text_430[0x100];         // +0x430
    char pad_530[0x924 - 0x530];
    char buf_924[0xB0];           // +0x924

    bool M_4208B0(int a, int b, int c, int d);
    char* M_41C900(char* a);
    void M_41C950(int a, int b, int c, int d);
    void SetInt_41BC00(int v);
    void M_41BC10(int a, int b, int c, int d, int e);
    int M_41BC20();
    int M_41BC30(int a, int b, int c, int d, int e, int f);
    int M_41BC40(int a, int b, int c, int d, int e);
    int M_41BC50(int a, int b);
    int Get_41C8F0();
    void Init_41EB30();
    void Set_41F610(int a, int b);
    bool M_4208D0(int a, int b, int c, int d);
    bool M_420CD0(int a, int b, int c, int d);
    bool M_420CF0(int a, int b, int c, int d);
    void SetText_4213B0();
    void Wrap_4213D0();
    char* ClearGlobal_421A40();
    void M_5E2CC0(int a, int b);
};
