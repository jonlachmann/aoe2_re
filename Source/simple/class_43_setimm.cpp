#include "Function.hpp"

class S43SetImmBulk {
public:
    void Set_431D90();
    void Set_43A440();
    void Set_43F9B0();
};

MATCH_FUNC(0x431D90)
void S43SetImmBulk::Set_431D90()
{
    *(int*)((char*)this + 0x206c) = 0x0;
}

MATCH_FUNC(0x43A440)
void S43SetImmBulk::Set_43A440()
{
    *(int*)((char*)this + 0x25bc) = 0x0;
}

MATCH_FUNC(0x43F9B0)
void S43SetImmBulk::Set_43F9B0()
{
    *(int*)((char*)this + 0x0) = 0x0;
}
