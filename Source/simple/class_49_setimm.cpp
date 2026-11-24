#include "Function.hpp"

class S49SetImmBulk {
public:
    void Set_49FFB0();
    void Set_49FFC0();
};

MATCH_FUNC(0x49FFB0)
void S49SetImmBulk::Set_49FFB0()
{
    *(int*)((char*)this + 0xad4) = 0x1;
}

MATCH_FUNC(0x49FFC0)
void S49SetImmBulk::Set_49FFC0()
{
    *(int*)((char*)this + 0xad4) = 0x0;
}
