#include "Function.hpp"

class S436B20Sub {
public:
    char pad_00[0x18];
    int field_18;
};

class S436B20 {
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
    virtual void Vat_40(int v);
    char pad_04[0x8 - 4];
    S436B20Sub* field_8;
    int M_436B20();
};

MATCH_FUNC(0x436B20)
int S436B20::M_436B20()
{
    Vat_40(field_8->field_18);
    return 1;
}
