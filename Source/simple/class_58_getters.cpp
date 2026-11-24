#include "Function.hpp"

class S58GetBulk {
public:
    int Get_580B20(int unused);
    int Get_58A800();
};

MATCH_FUNC(0x580B20)
int S58GetBulk::Get_580B20(int unused)
{
    return *(int*)((char*)this + 0x3f8);
}

MATCH_FUNC(0x58A800)
int S58GetBulk::Get_58A800()
{
    return *(int*)((char*)this + 0x194);
}
