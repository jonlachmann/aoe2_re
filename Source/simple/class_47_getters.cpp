#include "Function.hpp"

class S47GetBulk {
public:
    float Get_473C70();
    float Get_473C80();
    float Get_473C90();
    float Get_473CA0();
    float Get_477990(int unused);
    int Get_47ADA0();
    int Get_47D9E0();
};

MATCH_FUNC(0x473C70)
float S47GetBulk::Get_473C70()
{
    return *(float*)((char*)this + 0xe4);
}

MATCH_FUNC(0x473C80)
float S47GetBulk::Get_473C80()
{
    return *(float*)((char*)this + 0xe8);
}

MATCH_FUNC(0x473C90)
float S47GetBulk::Get_473C90()
{
    return *(float*)((char*)this + 0xec);
}

MATCH_FUNC(0x473CA0)
float S47GetBulk::Get_473CA0()
{
    return *(float*)((char*)this + 0xf4);
}

MATCH_FUNC(0x477990)
float S47GetBulk::Get_477990(int unused)
{
    return *(float*)((char*)this + 0xc4);
}

MATCH_FUNC(0x47ADA0)
int S47GetBulk::Get_47ADA0()
{
    return *(int*)((char*)this + 0xa8);
}

MATCH_FUNC(0x47D9E0)
int S47GetBulk::Get_47D9E0()
{
    return *(int*)((char*)this + 0x8e8c);
}
