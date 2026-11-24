#include "Function.hpp"

// sub_4AF8D0 (VA 0x4AF8D0) - member: stores the word arg at +0x202, then
// calls virtual slot 0x20 with 1.
class S4AF8D0 {
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
    char pad_04[0x202 - 0x04];
    short field_202;
    void M_4AF8D0(short v);
};

