#include "Function.hpp"

class S43GetBulk {
public:
    int Get_437950();
    int Get_438630();
    int Get_438680();
};

MATCH_FUNC(0x437950)
int S43GetBulk::Get_437950()
{
    return *(int*)((char*)this + 0x2580);
}

MATCH_FUNC(0x438630)
int S43GetBulk::Get_438630()
{
    return *(int*)((char*)this + 0x238);
}

MATCH_FUNC(0x438680)
int S43GetBulk::Get_438680()
{
    return *(int*)((char*)this + 0x124);
}
