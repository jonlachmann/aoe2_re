#include "Function.hpp"

class S4BD7A0 {
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
    char pad_04[0x1a4 - 4];
    int field_1a4;
    void M_4BD7A0(int v);
};

MATCH_FUNC(0x4BD7A0)
void S4BD7A0::M_4BD7A0(int v)
{
    field_1a4 = v;
    Vat_20(1);
}
