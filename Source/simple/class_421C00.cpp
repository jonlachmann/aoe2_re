#include "Function.hpp"

class S421C00 {
public:
    char pad_00[0x9af];
    unsigned char field_9af;
    char pad_9b0[0x9b5 - 0x9b0];
    unsigned char array_9b5[0xb];
    unsigned char array_9c0[0x9e4 - 0x9c0];
    int array_9e4[(0xa10 - 0x9e4) / 4];
    int array_a10[0x40];

    int Get_421880(int index);
    void Set_421C00(int index, unsigned char v);
    void Set_421C30(int index, unsigned char v);
    void Set_421C60(unsigned char v);
    void Set_422220(int index, int v);
    void Clear_422240(int index);
    int Get_422210(int index);
    void GetBounds_422290(int index, int* out);
};

MATCH_FUNC(0x421C00)
void S421C00::Set_421C00(int index, unsigned char v)
{
    array_9b5[index] = v;
}

MATCH_FUNC(0x421C30)
void S421C00::Set_421C30(int index, unsigned char v)
{
    array_9c0[index] = v;
}

MATCH_FUNC(0x421C60)
void S421C00::Set_421C60(unsigned char v)
{
    field_9af = v;
}

MATCH_FUNC(0x422220)
void S421C00::Set_422220(int index, int v)
{
    array_9e4[index] = v;
}

MATCH_FUNC(0x422240)
void S421C00::Clear_422240(int index)
{
    array_a10[index] = -1;
}

MATCH_FUNC(0x422210)
int S421C00::Get_422210(int index)
{
    return array_9e4[index];
}

MATCH_FUNC(0x422290)
void S421C00::GetBounds_422290(int index, int* out)
{
    if (index < 0 || index >= 9)
        *out = 0;
    else
        *out = array_a10[index];
}
