#include "Function.hpp"

class S41GetBulk {
public:
    int Get_411590();
    int Get_41A060(int a,int b,int c,int d);
    int Get_41C8E0();
};

MATCH_FUNC(0x41C8E0)
int S41GetBulk::Get_41C8E0()
{
    return *(int*)((char*)this + 0x540);
}
