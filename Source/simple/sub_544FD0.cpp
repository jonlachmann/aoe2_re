#include "Function.hpp"

// sub_544FD0 (VA 0x544FD0) - member: calls virtual slot 0x5c with 1, then adds
// global float 0x6289F8 into the float at [+8 -> +0xc -> +0xa8 + 4], returns 1.
extern float g_6289F8;
struct C544FD0 {
    int field_0;
    float field_4;
};
struct B544FD0 {
    char pad_00[0xa8];
    C544FD0* field_a8;
};
struct A544FD0 {
    char pad_00[0xc];
    B544FD0* field_c;
};
class S544FD0 {
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
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vat_5c(int v);
    char pad_04[8 - 4];
    A544FD0* field_8;
    int M_544FD0();
};

// The float goes through a local: fld [obj+4]; fadd [g] (a plain `+=` loads g first).
MATCH_FUNC(0x544FD0)
int S544FD0::M_544FD0()
{
    Vat_5c(1);
    C544FD0* c = field_8->field_c->field_a8;
    float t = c->field_4;
    t += g_6289F8;
    c->field_4 = t;
    return 1;
}
