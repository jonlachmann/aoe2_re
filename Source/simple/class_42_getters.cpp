#include "Function.hpp"

class S42GetBulk {
public:
    int Get_422A70();
    int Get_422E10();
    int Get_42FBC0();
};

MATCH_FUNC(0x422A70)
int S42GetBulk::Get_422A70()
{
    return *(int*)((char*)this + 0x128);
}

MATCH_FUNC(0x422E10)
int S42GetBulk::Get_422E10()
{
    return *(int*)((char*)this + 0x120);
}

MATCH_FUNC(0x42FBC0)
int S42GetBulk::Get_42FBC0()
{
    return *(int*)((char*)this + 0x2008);
}
