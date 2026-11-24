#include "Function.hpp"





MATCH_FUNC(0x569C70)
void M_569C70()
{
}




class S4060A0 {
public:
    char pad_00[8];
    int field_8;
    bool Check_4060A0();
};

class S40F4A0 {
public:
    char pad_00[0xea4];
    int field_ea4;
    bool Check_40F4A0();
};

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

extern unsigned char g_62ebf8;


extern int* g_741f68;
MATCH_FUNC(0x5542C0)
int Check_5542C0(int value)
{
    return *(unsigned char*)((char*)g_741f68 + 0x155) == value;
}
