// C_vt622368 — vtable class 0x622368 (skeleton: Source/skeleton/ui/
// C_vt622368_622368.h holds all slots and lifted methods).
// This TU carries the 5 byte-verified methods. The 0x4ADF90 entry point is an
// original __stdcall out-parameter helper, so it stays a static member.
#pragma once

#include "Function.hpp"

class S4AC9Sub {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3(int v);
};

class C_vt622368 {
public:
    char pad_00[0x84];
    void* field_84;               // +0x84, subobject pointer

    void M_4AA5D0(int a, int b, int c);
    void M_4AAFC0(int a, int b, int c, int d, int e);
    void Call_4AC9F0(int v);
    static int __stdcall M_4ADF90(int a1, int a2, int a3, int a4, int a5,
                                  int* p6, int* p7);
    void M_4AE900(int a, int b, int c, int d, int e, int f);
    void M_4AD530();
};
