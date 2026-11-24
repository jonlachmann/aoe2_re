#include "Function.hpp"

class S41SetImmBulk {
public:
    void Set_4106A0();
    void Set_411420();
};

MATCH_FUNC(0x4106A0)
void S41SetImmBulk::Set_4106A0()
{
    *(int*)((char*)this + 0x10) = 0x0;
}

MATCH_FUNC(0x411420)
void S41SetImmBulk::Set_411420()
{
    *(int*)((char*)this + 0x0) = 0x61d604;
}
