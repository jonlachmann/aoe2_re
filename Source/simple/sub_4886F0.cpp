#include "Function.hpp"

// sub_4886F0 (VA 0x4886F0) - member: two virtual calls at slots 0x28 and
// 0x4c, each with argument 0.
class S4886F0 {
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
    virtual void Vat_28(int v);
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vat_4c(int v);
    void M_4886F0();
};

MATCH_FUNC(0x4886F0)
void S4886F0::M_4886F0()
{
    Vat_28(0);
    Vat_4c(0);
}
