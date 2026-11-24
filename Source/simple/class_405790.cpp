#include "Function.hpp"

class S405790 {
public:
    void* vtbl_0;
    int field_4;
    int field_8;
    S405790* Init_405790(int v);
};

MATCH_FUNC(0x405790)
S405790* S405790::Init_405790(int v)
{
    vtbl_0 = (void*)0x61cab4;
    field_4 = v;
    field_8 = 0;
    return this;
}
