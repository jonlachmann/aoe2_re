#include "Function.hpp"

MATCH_FUNC(0x414300)
void M_414300()
{
}

MATCH_FUNC(0x440740)
void M_440740()
{
}

MATCH_FUNC(0x440750)
void M_440750()
{
}

MATCH_FUNC(0x446D10)
void M_446D10()
{
}

MATCH_FUNC(0x569C70)
void M_569C70()
{
}

MATCH_FUNC(0x5EC8EE)
void M_5EC8EE()
{
}

MATCH_FUNC(0x5FB460)
void M_5FB460()
{
}

MATCH_FUNC(0x5FC8EB)
void M_5FC8EB()
{
}

class S4060A0 {
public:
    char pad_00[8];
    int field_8;
    bool Check_4060A0();
};
WIP_FUNC(0x4060A0)
bool S4060A0::Check_4060A0()
{
    return (bool)field_8;
}

class S40F4A0 {
public:
    char pad_00[0xea4];
    int field_ea4;
    bool Check_40F4A0();
};
MATCH_FUNC(0x40F4A0)
bool S40F4A0::Check_40F4A0()
{
    return field_ea4 == 0;
}

class S40F4B0 {
public:
    char pad_00[0xea4];
    int field_ea4;
    bool Check_40F4B0();
};

class S419810 {
public:
    char pad_00[0x180];
    int field_180;
    bool Check_419810();
};
MATCH_FUNC(0x419810)
bool S419810::Check_419810()
{
    return field_180 != 0;
}

class S42D210 {
public:
    char pad_00[0x1e38];
    int field_1e38;
    bool Check_42D210();
};
MATCH_FUNC(0x42D210)
bool S42D210::Check_42D210()
{
    return field_1e38 == 4;
}

class S431740 {
public:
    char pad_00[0x17e4];
    int field_17e4;
    bool Check_431740();
};
MATCH_FUNC(0x431740)
bool S431740::Check_431740()
{
    return field_17e4 != -1;
}

class S431750 {
public:
    char pad_00[0x1a50];
    int field_1a50;
    bool Check_431750();
};
MATCH_FUNC(0x431750)
bool S431750::Check_431750()
{
    return field_1a50 != -1;
}

class S5D17D0 {
public:
    char pad_00[0x10];
    bool field_10;
    bool Check_5D17D0();
};
WIP_FUNC(0x5D17D0)
bool S5D17D0::Check_5D17D0()
{
    return field_10 == 2;
}

extern unsigned char g_62ebf8;
MATCH_FUNC(0x5EDCB0)
bool Check_5EDCB0()
{
    return g_62ebf8 == 0xc;
}

MATCH_FUNC(0x5F0CB0)
bool Check_5F0CB0(int* p)
{
    return *(int*)((char*)p + 8) == 0;
}

extern int* g_741f68;
MATCH_FUNC(0x5542C0)
int Check_5542C0(int value)
{
    return *(unsigned char*)((char*)g_741f68 + 0x155) == value;
}
