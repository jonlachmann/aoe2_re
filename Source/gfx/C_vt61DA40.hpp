// C_vt61DA40 — vtable class 0x61DA40 (skeleton: Source/skeleton/gfx/
// C_vt61DA40_61DA40.h holds all 187 slots and lifted methods).
// This TU carries the 15 byte-verified methods. 0x41A0D0/0x41A110/0x52C430
// are thiscall methods returning a 12-byte float triple by value (hidden
// return pointer); the named local + return copy gives the original temp.
#pragma once

#include "Function.hpp"

struct S41A0D0Triple {
    float field_00;
    float field_04;
    float field_08;
    S41A0D0Triple() {}
    S41A0D0Triple(float a, float b, float c)
    {
        field_00 = a;
        field_04 = b;
        field_08 = c;
    }
};

class C_vt61DA40 {
public:
    char pad_00[8];
    void* field_08;               // +0x08, generic pointer in 0x52C610/0x41A060
    char pad_0C[0x38 - 0x0C];
    float field_38;               // +0x38
    float field_3C;               // +0x3C
    float field_40;               // +0x40

    void M_41A030(int a, int b, int c, int d);
    static int __stdcall M_41A040(int a1, int a2, int a3, int a4, int* out);
    bool M_41A050(int a, int b, int c, int d);
    int Get_41A060(int a, int b, int c, int d);
    int M_41A070(int a, int b, int c, int d, int e, int f, int g, int h, int i);
    int M_41A080(int a, int b, int c, int d, int e, int f, int g, int h,
                 int i, int j, int k, int l);
    float Get_41A090(int a, int b, int c);
    int M_41A0B0();
    int M_41A0C0(int a, int b, int c);
    S41A0D0Triple M_41A0D0(int a2, int a3);
    S41A0D0Triple M_41A110();
    float Get_474810();
    S41A0D0Triple Copy_52C430();
    float Get_52C610();
    bool M_547EE0();
};
