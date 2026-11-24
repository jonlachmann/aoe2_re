#include "Function.hpp"

// sub_4AF7D0 (VA 0x4AF7D0) - member: stores three args at +0x1f4/+0x1f44/+0x1f48 then calls
// virtual slot 0x20 with 1.
class S4AF7D0 {
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
    char pad_04[0x1f4 - 0x04];
    int f0;
    int f1;
    int f2;
    void M_4AF7D0(int a, int b, int c);
};

MATCH_FUNC(0x4AF7D0)
void S4AF7D0::M_4AF7D0(int a, int b, int c)
{
    f0 = a;
    f1 = b;
    f2 = c;
    Vat_20(1);
}
