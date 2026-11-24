#include "Function.hpp"

class S46GetBulk {
public:
    int Get_463260();
    int Get_464290();
    float Get_46AAA0();
    float Get_46AAB0();
    float Get_46AAC0();
};

MATCH_FUNC(0x463260)
int S46GetBulk::Get_463260()
{
    return *(int*)((char*)this + 0x100);
}

MATCH_FUNC(0x464290)
int S46GetBulk::Get_464290()
{
    return *(int*)((char*)this + 0x118);
}

