#include "Function.hpp"

class S5BGetBulk {
public:
    char* Get_5B42E0();
    int Get_5B4540();
    unsigned char Get_5B4560();
    unsigned char Get_5B4580();
    int Get_5BAD50();
    int Get_5BAD70();
    int Get_5BAEA0();
    char* Get_5BAEB0();
    int Get_5BAF10();
    int Get_5BAF30();
    int Get_5BAF50();
    int Get_5BAF60();
    int Get_5BB110();
    int Get_5BB120();
    unsigned char Get_5BB140();
    unsigned char Get_5BB150();
    unsigned char Get_5BB160();
    int Get_5BC9B0();
    unsigned char Get_5BCA00();
};

MATCH_FUNC(0x5B42E0)
char* S5BGetBulk::Get_5B42E0()
{
    return (char*)this + 0x17b0;
}

MATCH_FUNC(0x5B4560)
unsigned char S5BGetBulk::Get_5B4560()
{
    return *(unsigned char*)((char*)this + 0x145c);
}

MATCH_FUNC(0x5B4580)
unsigned char S5BGetBulk::Get_5B4580()
{
    return *(unsigned char*)((char*)this + 0x145d);
}

MATCH_FUNC(0x5BAF10)
int S5BGetBulk::Get_5BAF10()
{
    return *(int*)((char*)this + 0x11dc);
}

MATCH_FUNC(0x5BAF30)
int S5BGetBulk::Get_5BAF30()
{
    return *(int*)((char*)this + 0x11e0);
}

MATCH_FUNC(0x5BAF50)
int S5BGetBulk::Get_5BAF50()
{
    return *(int*)((char*)this + 0x11e4);
}

MATCH_FUNC(0x5BAF60)
int S5BGetBulk::Get_5BAF60()
{
    return *(int*)((char*)this + 0x11e8);
}

MATCH_FUNC(0x5BB110)
int S5BGetBulk::Get_5BB110()
{
    return *(int*)((char*)this + 0x1234);
}

MATCH_FUNC(0x5BB120)
int S5BGetBulk::Get_5BB120()
{
    return *(int*)((char*)this + 0x1238);
}

MATCH_FUNC(0x5BB140)
unsigned char S5BGetBulk::Get_5BB140()
{
    return *(unsigned char*)((char*)this + 0x123d);
}

MATCH_FUNC(0x5BB150)
unsigned char S5BGetBulk::Get_5BB150()
{
    return *(unsigned char*)((char*)this + 0x123e);
}

MATCH_FUNC(0x5BB160)
unsigned char S5BGetBulk::Get_5BB160()
{
    return *(unsigned char*)((char*)this + 0x123f);
}

MATCH_FUNC(0x5BC9B0)
int S5BGetBulk::Get_5BC9B0()
{
    return *(int*)((char*)this + 0x10a4);
}

MATCH_FUNC(0x5BCA00)
unsigned char S5BGetBulk::Get_5BCA00()
{
    return *(unsigned char*)((char*)this + 0x1ae4);
}
