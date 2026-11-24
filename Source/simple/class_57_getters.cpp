#include "Function.hpp"

class S57GetBulk {
public:
    int Get_579580();
    int Get_579590();
    int Get_5795A0();
    int Get_5795B0();
    int Get_5795C0();
    int Get_5795D0();
    int Get_5795F0();
};

MATCH_FUNC(0x579580)
int S57GetBulk::Get_579580()
{
    return *(int*)((char*)this + 0xfc);
}

MATCH_FUNC(0x579590)
int S57GetBulk::Get_579590()
{
    return *(int*)((char*)this + 0x10c);
}

MATCH_FUNC(0x5795A0)
int S57GetBulk::Get_5795A0()
{
    return *(int*)((char*)this + 0xa14);
}

MATCH_FUNC(0x5795B0)
int S57GetBulk::Get_5795B0()
{
    return *(int*)((char*)this + 0x110);
}

MATCH_FUNC(0x5795C0)
int S57GetBulk::Get_5795C0()
{
    return *(int*)((char*)this + 0xa18);
}

MATCH_FUNC(0x5795D0)
int S57GetBulk::Get_5795D0()
{
    return *(int*)((char*)this + 0x11c);
}

MATCH_FUNC(0x5795F0)
int S57GetBulk::Get_5795F0()
{
    return *(int*)((char*)this + 0x14c);
}
