#include "Function.hpp"

class S421FSub {
public:
    char pad_00[0x8ec];
    int field_8ec;
    int field_8f0;
    int field_8f4;
    int unused_8f8;
    int field_8fc;
};

class S421F20 {
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
    virtual void Vat_58(int a, int b);
    char pad_04[0x24 - 4];
    S421FSub* field_24;
    char pad_28[0x5c - 0x28];
    int field_5c;
    void M_421F20();
    void M_421F40();
    void M_421F60(int a, int b);
};

MATCH_FUNC(0x421F20)
void S421F20::M_421F20()
{
    S421FSub* s = field_24;
    field_5c = 1;
    Vat_58(s->field_8f4, s->field_8fc);
}

MATCH_FUNC(0x421F40)
void S421F20::M_421F40()
{
    S421FSub* s = field_24;
    field_5c = 0;
    Vat_58(s->field_8ec, s->field_8f0);
}

MATCH_FUNC(0x421F60)
void S421F20::M_421F60(int a, int b)
{
    field_24->field_8f4 = a;
    field_24->field_8fc = b;
    if (field_5c != 0)
        Vat_58(a, b);
}
