#include "Function.hpp"

// sub_4B84F0 (VA 0x4B84F0) - member: stores the arg at +0x238 then calls the virtual
// slot 0x20 with the constant 1.
class S4B84F0 {
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

    char pad_04[0x238 - 4];
    int field_0x238;

    void M_4B84F0(int v);
};

MATCH_FUNC(0x4B84F0)
void S4B84F0::M_4B84F0(int v)
{
    field_0x238 = v;
    Vat_20(1);
}
