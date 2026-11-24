#include "Function.hpp"

class S4EGetBulk {
public:
    int Get_4E8530();
    int Get_4E8540();
    int Get_4E8550();
};

MATCH_FUNC(0x4E8530)
int S4EGetBulk::Get_4E8530()
{
    return *(int*)((char*)this + 0x1020);
}

MATCH_FUNC(0x4E8540)
int S4EGetBulk::Get_4E8540()
{
    return *(int*)((char*)this + 0x1024);
}

MATCH_FUNC(0x4E8550)
int S4EGetBulk::Get_4E8550()
{
    return *(int*)((char*)this + 0x101c);
}
