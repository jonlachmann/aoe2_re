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
