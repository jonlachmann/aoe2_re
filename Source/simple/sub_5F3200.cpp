#include "Function.hpp"

class S5F3200 {
public:
    char pad_00[0xc];
    int field_c;
    int field_10;
    int field_14;
    int field_18;
};

MATCH_FUNC(0x5F3200)
void Set_5F3200(S5F3200* obj)
{
    int v = obj->field_c;
    obj->field_18 = 0;
    obj->field_10 = v;
    obj->field_14 = v;
}
