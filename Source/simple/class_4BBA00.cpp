#include "Function.hpp"

// Family at 0x4BBA00: two setters that store adjacent fields +0x128/+0x12c and
// then call virtual slot 0x20 with 1.
class S4BBA00 {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual void Vt_6();
    virtual void Vt_7();
    virtual void Vat_20(int v);

    char pad_04[0x128 - 0x04];
    int field_128;
    int field_12c;
    int field_130;
    int field_134;
    char pad_138[0x164 - 0x138];
    int field_164;
    unsigned char field_168;

    void M_4BBA00(int v);
    void M_4BBA20(int v);
    void M_4BBA40(int v);
    void M_4BBA60(int v);
    void M_4BBAC0(int a, unsigned char b);
};

MATCH_FUNC(0x4BBA00)
void S4BBA00::M_4BBA00(int v)
{
    field_128 = v;
    Vat_20(1);
}

MATCH_FUNC(0x4BBA20)
void S4BBA00::M_4BBA20(int v)
{
    field_12c = v;
    Vat_20(1);
}

MATCH_FUNC(0x4BBA40)
void S4BBA00::M_4BBA40(int v)
{
    field_130 = v;
    Vat_20(1);
}

MATCH_FUNC(0x4BBA60)
void S4BBA00::M_4BBA60(int v)
{
    field_134 = v;
    Vat_20(1);
}

MATCH_FUNC(0x4BBAC0)
void S4BBA00::M_4BBAC0(int a, unsigned char b)
{
    field_164 = a;
    field_168 = b;
}
