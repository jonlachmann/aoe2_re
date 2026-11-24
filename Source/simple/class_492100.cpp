#include "Function.hpp"

class S492100Sub {
public:
    char pad_00[0xc8];
    int* field_c8;
    int* field_cc;
};

class S492100 {
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
    virtual void Vat_40(int* p);
    char pad_04[0x8 - 4];
    S492100Sub* field_8;
    int UseCC_4921B0();
    int UseC8_4921D0();
};

MATCH_FUNC(0x4921B0)
int S492100::UseCC_4921B0()
{
    int* p = field_8->field_cc;
    if (p != 0) {
        Vat_40(p);
        return 1;
    }
    return 0;
}

MATCH_FUNC(0x4921D0)
int S492100::UseC8_4921D0()
{
    int* p = field_8->field_c8;
    if (p != 0) {
        Vat_40(p);
        return 1;
    }
    return 0;
}
