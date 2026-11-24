#include "Function.hpp"

class S42SetImmBulk {
public:
    void Set_428C10();
};

MATCH_FUNC(0x428C10)
void S42SetImmBulk::Set_428C10()
{
    *(unsigned char*)((char*)this + 0x1e30) = 0x0;
}
