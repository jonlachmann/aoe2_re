#include "Function.hpp"

class S5CGetBulk {
public:
    int Get_5C1390();
    int Get_5C13C0();
    int Get_5C13E0();
    int Get_5C1400();
    int Get_5C19D0();
    int Get_5C19E0();
    int Get_5C19F0();
    int Get_5C47D0();
};

MATCH_FUNC(0x5C1390)
int S5CGetBulk::Get_5C1390()
{
    return *(int*)((char*)this + 0x4ccc);
}

MATCH_FUNC(0x5C13C0)
int S5CGetBulk::Get_5C13C0()
{
    return *(int*)((char*)this + 0x5224);
}

MATCH_FUNC(0x5C13E0)
int S5CGetBulk::Get_5C13E0()
{
    return *(int*)((char*)this + 0x5228);
}

MATCH_FUNC(0x5C1400)
int S5CGetBulk::Get_5C1400()
{
    return *(int*)((char*)this + 0x522c);
}

MATCH_FUNC(0x5C19D0)
int S5CGetBulk::Get_5C19D0()
{
    return *(int*)((char*)this + 0x1b74);
}

MATCH_FUNC(0x5C19E0)
int S5CGetBulk::Get_5C19E0()
{
    return *(int*)((char*)this + 0x1b7c);
}

MATCH_FUNC(0x5C19F0)
int S5CGetBulk::Get_5C19F0()
{
    return *(int*)((char*)this + 0x1b84);
}

MATCH_FUNC(0x5C47D0)
int S5CGetBulk::Get_5C47D0()
{
    return *(int*)((char*)this + 0x170);
}
