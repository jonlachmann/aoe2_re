#include "Function.hpp"

class S52ADSub {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual void Vt_6();
    virtual void Vat_1c(int a, int b);
};

class S52ADE0 {
public:
    char pad_00[0x10];
    int field_10;
    char pad_14[0x18 - 0x14];
    S52ADSub* field_18;
    void Call_52ADE0(int v);
};

MATCH_FUNC(0x52ADE0)
void S52ADE0::Call_52ADE0(int v)
{
    if (field_10 != 0 && field_18 != 0)
        field_18->Vat_1c(field_10, v);
}
