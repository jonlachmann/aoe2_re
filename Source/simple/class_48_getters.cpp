#include "Function.hpp"

class S48GetBulk {
public:
    int Get_48A860();
};

MATCH_FUNC(0x48A860)
int S48GetBulk::Get_48A860()
{
    return *(int*)((char*)this + 0x148);
}
