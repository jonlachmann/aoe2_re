#include "Function.hpp"

class S58A130 {
public:
    void* vtbl_0;
    int field_4;
    unsigned short field_8;
    S58A130* Init_58A130();
};

MATCH_FUNC(0x58A130)
S58A130* S58A130::Init_58A130()
{
    vtbl_0 = (void*)0x62aa3c;
    field_8 = 0;
    field_4 = 0;
    return this;
}
