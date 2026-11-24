#include "Function.hpp"

class S44GetBulk {
public:
    int Get_440730();
    int Get_4474F0();
    int Get_447500();
    int Get_44B9E0();
};

MATCH_FUNC(0x440730)
int S44GetBulk::Get_440730()
{
    return *(int*)((char*)this + 0xf0);
}

MATCH_FUNC(0x4474F0)
int S44GetBulk::Get_4474F0()
{
    return *(int*)((char*)this + 0xfc);
}

MATCH_FUNC(0x447500)
int S44GetBulk::Get_447500()
{
    return *(int*)((char*)this + 0xf8);
}

MATCH_FUNC(0x44B9E0)
int S44GetBulk::Get_44B9E0()
{
    return *(int*)((char*)this + 0x818);
}
