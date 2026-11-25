// C_vt61CAB4 — vtable class 0x61CAB4 (skeleton: Source/skeleton/app/
// C_vt61CAB4_61CAB4.h holds all slots and lifted methods).
// This TU carries the 2 byte-verified methods. 0x4061C0 walks a linked list at
// +0x08 and dispatches slot +0x40 on each node object.
#pragma once

#include "Function.hpp"

struct N4061C0 {
    char* obj_0;
    N4061C0* next_4;
};

class T4061C0 {
public:
    virtual void Vt_0(int v);
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual short Vt_6();         // slot +0x18
    virtual void Vt_7(int v);     // slot +0x1C
    virtual char Vt_8();          // slot +0x20
    virtual void Vt_9();          // slot +0x24
    virtual char Vt_10();         // slot +0x28
    virtual int Vt_11();          // slot +0x2C
    virtual int Vt_12(int a1, int a2, int a3, int a4);  // slot +0x30
    virtual int Vt_13(int a1, int a2, int a3, int a4);  // slot +0x34
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vat_40(int v);
    virtual void Vat_44(int a1, int a2, int a3);  // slot +0x44
};

class C_vt61CAB4 {
public:
    char pad_00[4];
    void* field_04;               // +0x04
    N4061C0* field_08;            // +0x08 list head

    void M_4061C0(int v);
    void Clear_406220(char* p);
    void Init_4057D0();
    void Clear_4058C0();
    void Hook_405FD0();           // unresolved callee at 0x405FD0
    int Get_4060F0();
    int M_406110(int a1, int a2, int a3, int a4);
    int M_406140(int a1, int a2, int a3, int a4);
    int Find_4060B0(int a1);
    void* Get_406180(int a1);
    void M_406060(int a1);
    void* M_406020();
    void M_405F00(int a1);
    char M_405E60();
    char M_405EB0();
    void M_4061F0(int a1, int a2, int a3);
};
