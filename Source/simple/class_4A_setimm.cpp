#include "Function.hpp"

class S4ASetImmBulk {
public:
    void Set_4A64F0();
    void Set_4A8310();
};

MATCH_FUNC(0x4A64F0)
void S4ASetImmBulk::Set_4A64F0()
{
    *(int*)((char*)this + 0x494) = 0x0;
}

MATCH_FUNC(0x4A8310)
void S4ASetImmBulk::Set_4A8310()
{
    *(int*)((char*)this + 0x0) = 0x6222d4;
}
