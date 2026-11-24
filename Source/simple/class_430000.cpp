#include "Function.hpp"

class S430000 {
public:
    char pad_00[4];
    int field_4;
    char pad_08[0x10c8 - 0x08];
    unsigned int field_10c8;
    char pad_10cc[0x2010 - 0x10cc];
    int field_2010;
    char pad_2014[0x267c - 0x2014];
    int array_267c[0x40];

    int Cmp_42F620();
    int Get_42FB70(int* out);
    void Set_432B30(int index, int v);
};

MATCH_FUNC(0x42F620)
int S430000::Cmp_42F620()
{
    return field_10c8 > 6;
}

MATCH_FUNC(0x42FB70)
int S430000::Get_42FB70(int* out)
{
    *out = field_2010;
    return field_4;
}

MATCH_FUNC(0x432B30)
void S430000::Set_432B30(int index, int v)
{
    array_267c[index] = v;
}
