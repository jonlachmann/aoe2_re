#include "Function.hpp"

// sub_405860 (VA 0x405860) - member: walks the list at +8 and calls virtual
// slot 0x10 on each node's object at +0.
struct N405860 {
    char* obj_0;
    N405860* next_4;
};
class T405860 {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vat_10();
};
class S405860 {
public:
    char pad_00[8];
    N405860* field_8;
    void M_405860();
};

MATCH_FUNC(0x405860)
void S405860::M_405860()
{
    N405860* n = field_8;
    while (n != 0) {
        ((T405860*)n->obj_0)->Vat_10();
        n = n->next_4;
    }
}
