#include "Function.hpp"

class S5ASetImmBulk {
public:
    void Set_5A6780();
    void Set_5A6790();
    void Set_5A67A0();
};

MATCH_FUNC(0x5A6780)
void S5ASetImmBulk::Set_5A6780()
{
    *(unsigned char*)((char*)this + 0x2d4) = 0x0;
}

MATCH_FUNC(0x5A6790)
void S5ASetImmBulk::Set_5A6790()
{
    *(unsigned char*)((char*)this + 0x2d4) = 0x1;
}

MATCH_FUNC(0x5A67A0)
void S5ASetImmBulk::Set_5A67A0()
{
    *(int*)((char*)this + 0x61c) = 0x1;
}
