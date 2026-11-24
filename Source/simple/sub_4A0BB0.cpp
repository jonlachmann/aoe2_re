#include "Function.hpp"

// sub_4A0BB0 (VA 0x4A0BB0) - member: raises the +0xf6 byte flag, calls virtual
// slot 0x34 with the arg, then clears the flag.
class S4A0BB0 {
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
    virtual void Vat_34(int v);
    char pad_04[0xf6 - 0x04];
    unsigned char field_f6;
    void M_4A0BB0(int v);
};

MATCH_FUNC(0x4A0BB0)
void S4A0BB0::M_4A0BB0(int v)
{
    field_f6 = 1;
    Vat_34(v);
    field_f6 = 0;
}
