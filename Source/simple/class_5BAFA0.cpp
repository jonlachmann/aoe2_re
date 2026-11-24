#include "Function.hpp"

class S5BAFA0 {
public:
    char pad_00[0x11e4];
    int field_11e4;
    int field_11e8;
    unsigned char array_11ec[0xc];
    int array_11f8[0xb];
    unsigned char gap_1224;
    unsigned char array_1225[0x4c8c - 0x1225];
    int array_4c8c[(0x51d8 - 0x4c8c) / 4];
    int array_51d8[(0x51e4 - 0x51d8) / 4];
    int array_51e4[0x40];

    void Set_5BAF70(int a, int b);
    int GetId_5BAF90(int index);
    int Get_5BAFF0(int index);
    int Get_5BB030(int index);
    int Get_5BAFC0(int index);
    void SetByte_5BAFA0(int index, unsigned char v);
    void SetInt_5BAFD0(int index, int v);
    void SetByte2_5BB040(int index, unsigned char v);
    void SetInt2_5C1610(int index, int v);
    void SetInt3_5C1810(int index, int v);
    void SetInt4_5C1830(int index, int v);
};

MATCH_FUNC(0x5C1610)
void S5BAFA0::SetInt2_5C1610(int index, int v)
{
    array_4c8c[index] = v;
}

MATCH_FUNC(0x5C1810)
void S5BAFA0::SetInt3_5C1810(int index, int v)
{
    array_51d8[index] = v;
}

MATCH_FUNC(0x5C1830)
void S5BAFA0::SetInt4_5C1830(int index, int v)
{
    array_51e4[index] = v;
}

MATCH_FUNC(0x5BAF90)
int S5BAFA0::GetId_5BAF90(int index)
{
    return *(unsigned char*)((char*)this + 0x11ec + index);
}

MATCH_FUNC(0x5BAFF0)
int S5BAFA0::Get_5BAFF0(int index)
{
    return *(unsigned char*)((char*)this + 0x121c + index);
}

MATCH_FUNC(0x5BB030)
int S5BAFA0::Get_5BB030(int index)
{
    return *(unsigned char*)((char*)this + 0x1225 + index);
}

MATCH_FUNC(0x5BAFC0)
int S5BAFA0::Get_5BAFC0(int index)
{
    return array_11f8[index];
}
