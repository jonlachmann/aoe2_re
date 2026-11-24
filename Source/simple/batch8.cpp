#include "Function.hpp"

class S408660Target {
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
    virtual void Vat_30(int arg);
    virtual void Vat_34(int arg);
};

class S408660 {
public:
    char pad_00[8];
    S408660Target* field_8;
    int field_c;
    void Wrap_408660();
};

class S408670 {
public:
    char pad_00[8];
    S408660Target* field_8;
    int field_c;
    void Wrap_408670();
};

// Not a free function: a thiscall on the object stored at +0x1b0 (the field
// is loaded into ecx, so `this` moves to eax).
class T42FAE0 {
public:
    void M_42FAE0(char* buf, int size);
};
class S4213D0 {
public:
    char pad_00[0x1b0];
    T42FAE0* field_1b0;
    char pad_1b4[0x924 - 0x1b4];
    char buf_924[0xb0];
    void Wrap_4213D0();
};

// Thiscall on the object at +0x149c, like Wrap_4213D0.
class T4DF8F0 {
public:
    void M_4DF8F0(char* a, char* b);
};
class S5B5C50 {
public:
    char pad_00[0x430];
    char buf_430[0x149c - 0x430];
    T4DF8F0* field_149c;
    char pad_14a0[0x19b8 - 0x14a0];
    char buf_19b8[4];
    void Wrap_5B5C50();
};
