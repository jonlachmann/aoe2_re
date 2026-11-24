#include "Function.hpp"

class S48SetImmBulk {
public:
    void Set_48CBB0();
};

MATCH_FUNC(0x48CBB0)
void S48SetImmBulk::Set_48CBB0()
{
    *(int*)((char*)this + 0xa4) = 0x0;
}
