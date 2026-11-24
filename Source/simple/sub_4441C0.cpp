#include "Function.hpp"

// sub_4441C0 (VA 0x4441C0) - member: stores the arg at +0xfc then calls the virtual
// slot 0x20 with the constant 2.
class S4441C0 {
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

    char pad_04[0xfc - 4];
    int field_0xfc;

    void M_4441C0(int v);
};

MATCH_FUNC(0x4441C0)
void S4441C0::M_4441C0(int v)
{
    field_0xfc = v;
    Vat_20(2);
}
