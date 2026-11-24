#include "Function.hpp"

class S40GetBulk {
public:
    float Get_407C70();
    float Get_407C80();
    int Get_407CA0();
    int Get_407CE0();
    int Get_407CF0();
    int Get_40A320();
    int Get_40A330();
    int Get_40A340();
    int Get_40A350();
    int Get_40A360();
    int Get_40A390();
    int Get_40A400();
    int Get_40A430();
    unsigned char Get_40A460();
    char* Get_40C520();
};

MATCH_FUNC(0x40A320)
int S40GetBulk::Get_40A320()
{
    return *(int*)((char*)this + 0x80);
}

MATCH_FUNC(0x40A330)
int S40GetBulk::Get_40A330()
{
    return *(int*)((char*)this + 0x84);
}

MATCH_FUNC(0x40A340)
int S40GetBulk::Get_40A340()
{
    return *(int*)((char*)this + 0x88);
}

MATCH_FUNC(0x40A350)
int S40GetBulk::Get_40A350()
{
    return *(int*)((char*)this + 0x8c);
}

MATCH_FUNC(0x40A360)
int S40GetBulk::Get_40A360()
{
    return *(int*)((char*)this + 0x90);
}

MATCH_FUNC(0x40A400)
int S40GetBulk::Get_40A400()
{
    return *(int*)((char*)this + 0xa0);
}

MATCH_FUNC(0x40A430)
int S40GetBulk::Get_40A430()
{
    return *(int*)((char*)this + 0xa4);
}

MATCH_FUNC(0x40A460)
unsigned char S40GetBulk::Get_40A460()
{
    return *(unsigned char*)((char*)this + 0xac);
}

MATCH_FUNC(0x40C520)
char* S40GetBulk::Get_40C520()
{
    return (char*)this + 0x1f8;
}
