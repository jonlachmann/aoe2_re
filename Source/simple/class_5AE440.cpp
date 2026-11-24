#include "Function.hpp"

// Family 0x5AE440/70/A0/D0: four setters writing three consecutive dwords in the
// block at +0x100 (+0x10c, +0x118, +0x124), each then calling virtual slot 0x20
// with 1.
class S5AE440 {
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
    char pad_04[0x100 - 0x04];
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;

    void M_5AE440(int a, int b, int c);
    void M_5AE470(int a, int b, int c);
    void M_5AE4A0(int a, int b, int c);
    void M_5AE4D0(int a, int b, int c);
};

MATCH_FUNC(0x5AE440)
void S5AE440::M_5AE440(int a, int b, int c)
{
    f100 = a;
    f104 = b;
    f108 = c;
    Vat_20(1);
}

MATCH_FUNC(0x5AE470)
void S5AE440::M_5AE470(int a, int b, int c)
{
    f10c = a;
    f110 = b;
    f114 = c;
    Vat_20(1);
}

MATCH_FUNC(0x5AE4A0)
void S5AE440::M_5AE4A0(int a, int b, int c)
{
    f118 = a;
    f11c = b;
    f120 = c;
    Vat_20(1);
}

MATCH_FUNC(0x5AE4D0)
void S5AE440::M_5AE4D0(int a, int b, int c)
{
    f124 = a;
    f128 = b;
    f12c = c;
    Vat_20(1);
}
