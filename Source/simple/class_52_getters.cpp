#include "Function.hpp"

class S52GetBulk {
public:
    int Get_52CB50();
    int Get_52CB60();
};

MATCH_FUNC(0x52CB50)
int S52GetBulk::Get_52CB50()
{
    return *(int*)((char*)this + 0x1a0);
}

MATCH_FUNC(0x52CB60)
int S52GetBulk::Get_52CB60()
{
    return *(int*)((char*)this + 0x23c);
}
