#include "Function.hpp"

// sub_4921F0 (VA 0x4921F0) - member: when [+8]->+0x18 exists, calls virtual
// slot 0x40 with it and returns 1; else 0.
class T4921F0 {
public:
    char pad_00[0x18];
    char* field_18;
};
class S4921F0 {
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
    virtual void Vat_40(char* p);
    char pad_04[8 - 4];
    char* field_8;
    int M_4921F0();
};

MATCH_FUNC(0x4921F0)
int S4921F0::M_4921F0()
{
    char* q = ((T4921F0*)field_8)->field_18;
    if (q != 0) {
        Vat_40(q);
        return 1;
    }
    return 0;
}
