#include "Function.hpp"

class S41A420 {
public:
    void* vtbl_0;
    int field_4;
    int field_8;
    S41A420* Init_41A420(int v);
};

MATCH_FUNC(0x41A420)
S41A420* S41A420::Init_41A420(int v)
{
    vtbl_0 = (void*)0x61ddb0;
    field_4 = 0;
    field_8 = v;
    return this;
}
