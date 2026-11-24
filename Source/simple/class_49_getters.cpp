#include "Function.hpp"

class S49GetBulk {
public:
    int Get_49FFA0();
};

MATCH_FUNC(0x49FFA0)
int S49GetBulk::Get_49FFA0()
{
    return *(int*)((char*)this + 0xad4);
}
