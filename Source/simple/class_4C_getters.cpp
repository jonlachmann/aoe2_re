#include "Function.hpp"

class S4CGetBulk {
public:
    int Get_4CE680();
    int Get_4CE690();
    char* Get_4CE6A0();
    char* Get_4CE6B0();
    char* Get_4CE6C0();
    char* Get_4CE6D0();
};

MATCH_FUNC(0x4CE680)
int S4CGetBulk::Get_4CE680()
{
    return *(int*)((char*)this + 0x1050);
}

MATCH_FUNC(0x4CE690)
int S4CGetBulk::Get_4CE690()
{
    return *(int*)((char*)this + 0x1054);
}

MATCH_FUNC(0x4CE6A0)
char* S4CGetBulk::Get_4CE6A0()
{
    return (char*)this + 0x156c;
}

MATCH_FUNC(0x4CE6B0)
char* S4CGetBulk::Get_4CE6B0()
{
    return (char*)this + 0x164c;
}

MATCH_FUNC(0x4CE6C0)
char* S4CGetBulk::Get_4CE6C0()
{
    return (char*)this + 0x172c;
}

MATCH_FUNC(0x4CE6D0)
char* S4CGetBulk::Get_4CE6D0()
{
    return (char*)this + 0x180c;
}
