#include "Function.hpp"

class S5F0CC0Node {
public:
    char pad_00[4];
    int field_4;
};



class S5F0CC0 {
public:
    char pad_00[8];
    void* field_8;
    S5F0CC0Node* field_c;
};

MATCH_FUNC(0x5F0CC0)
int Get_5F0CC0(S5F0CC0* obj)
{
    if (obj->field_8 != 0)
        return 0;
    return obj->field_c->field_4;
}
