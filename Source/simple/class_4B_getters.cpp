#include "Function.hpp"

class S4BGetBulk {
public:
    int Get_4B67E0();
    int Get_4B7830();
};

MATCH_FUNC(0x4B67E0)
int S4BGetBulk::Get_4B67E0()
{
    return *(int*)((char*)this + 0x1bc);
}

MATCH_FUNC(0x4B7830)
int S4BGetBulk::Get_4B7830()
{
    return *(int*)((char*)this + 0x300);
}
