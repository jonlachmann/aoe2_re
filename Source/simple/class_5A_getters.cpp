#include "Function.hpp"

class S5AGetBulk {
public:
    unsigned char Get_5A7940();
    int Get_5AC760();
};

MATCH_FUNC(0x5A7940)
unsigned char S5AGetBulk::Get_5A7940()
{
    return *(unsigned char*)((char*)this + 0x864);
}

MATCH_FUNC(0x5AC760)
int S5AGetBulk::Get_5AC760()
{
    return *(int*)((char*)this + 0x104);
}
