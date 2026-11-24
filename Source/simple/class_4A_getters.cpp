#include "Function.hpp"

class S4AGetBulk {
public:
    int Get_4A21A0();
    char* Get_4A3CB0();
    int Get_4A3CC0();
    int Get_4A3CD0();
    int Get_4A3CE0();
    int Get_4A3D10();
    char* Get_4A3D20();
    int Get_4A3D30();
    unsigned char Get_4AD430();
};

MATCH_FUNC(0x4A21A0)
int S4AGetBulk::Get_4A21A0()
{
    return *(int*)((char*)this + 0xe8);
}

MATCH_FUNC(0x4A3CB0)
char* S4AGetBulk::Get_4A3CB0()
{
    return (char*)this + 0x100;
}

MATCH_FUNC(0x4A3CC0)
int S4AGetBulk::Get_4A3CC0()
{
    return *(int*)((char*)this + 0x204);
}

MATCH_FUNC(0x4A3CD0)
int S4AGetBulk::Get_4A3CD0()
{
    return *(int*)((char*)this + 0x208);
}

MATCH_FUNC(0x4A3CE0)
int S4AGetBulk::Get_4A3CE0()
{
    return *(int*)((char*)this + 0x210);
}

MATCH_FUNC(0x4A3D10)
int S4AGetBulk::Get_4A3D10()
{
    return *(int*)((char*)this + 0x350);
}

MATCH_FUNC(0x4A3D20)
char* S4AGetBulk::Get_4A3D20()
{
    return (char*)this + 0x354;
}

MATCH_FUNC(0x4A3D30)
int S4AGetBulk::Get_4A3D30()
{
    return *(int*)((char*)this + 0x458);
}

MATCH_FUNC(0x4AD430)
unsigned char S4AGetBulk::Get_4AD430()
{
    return *(unsigned char*)((char*)this + 0x154);
}
