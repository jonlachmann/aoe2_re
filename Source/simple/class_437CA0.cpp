#include "Function.hpp"

class S437CA0 {
public:
    char pad_00[0x204];
    int Get_437CA0(int index);
    int Get_437CC0(int index);
    char* Get_437CE0(int index);
};

MATCH_FUNC(0x437CA0)
int S437CA0::Get_437CA0(int index)
{
    return *(int*)((char*)this + 0x204 + index * 616);
}

MATCH_FUNC(0x437CC0)
int S437CA0::Get_437CC0(int index)
{
    return *(int*)((char*)this + 0x208 + index * 616);
}

MATCH_FUNC(0x437CE0)
char* S437CA0::Get_437CE0(int index)
{
    return (char*)this + 0x22c + index * 616;
}
