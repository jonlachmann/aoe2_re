#include "Function.hpp"

class S4ACB60Node {
public:
    char pad_00[4];
    int field_4;
};

class S4ACB60 {
public:
    char pad_00[0x158];
    S4ACB60Node* field_158;
    int Get_4ACB60();
};

MATCH_FUNC(0x4ACB60)
int S4ACB60::Get_4ACB60()
{
    return field_158 != 0 ? field_158->field_4 : -1;
}
