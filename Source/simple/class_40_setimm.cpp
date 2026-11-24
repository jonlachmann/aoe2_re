#include "Function.hpp"

class S40SetImmBulk {
public:
    void Set_407C90();
    void Set_409E80();
    void Set_40A0C0();
};

MATCH_FUNC(0x409E80)
void S40SetImmBulk::Set_409E80()
{
    *(int*)((char*)this + 0x4) = 0x0;
}

