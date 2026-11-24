#include "Function.hpp"

// sub_41AAC0 (VA 0x41AAC0) - member: over the +4 list, calls virtual slot 0x28
// on each node's object with (arg, field_8).
class T41AAC0 {
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
    virtual void Vat_28(int a, int b);
};
struct N41AAC0 {
    T41AAC0* obj_0;
    int field_4;
    N41AAC0* next_8;
};
class S41AAC0 {
public:
    char pad_00[4];
    N41AAC0* list_4;
    int field_8;
    void M_41AAC0(int arg, int unused1, int unused2);   // ret 0xc
};

MATCH_FUNC(0x41AAC0)
void S41AAC0::M_41AAC0(int arg, int unused1, int unused2)
{
    for (N41AAC0* n = list_4; n; n = n->next_8)
        n->obj_0->Vat_28(arg, field_8);
}
