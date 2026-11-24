#include "Function.hpp"

class S407BD0 {
public:
    bool M_407BD0(int unused);
};
MATCH_FUNC(0x407BD0)
bool S407BD0::M_407BD0(int unused)
{
    return true;
}

MATCH_FUNC(0x407BE0)
bool M_407BE0()
{
    return true;
}

MATCH_FUNC(0x5E51F0)
bool M_5E51F0()
{
    return true;
}

MATCH_FUNC(0x5FB450)
int M_5FB450()
{
    return 1;
}

MATCH_FUNC(0x5FBDE7)
int M_5FBDE7()
{
    return 1;
}

class S411C20 {
public:
    int M_411C20(int unused);
};
MATCH_FUNC(0x411C20)
int S411C20::M_411C20(int unused)
{
    return 1;
}

class S415750 {
public:
    int M_415750(int unused);
};
MATCH_FUNC(0x415750)
int S415750::M_415750(int unused)
{
    return 1;
}

class S41AF90 {
public:
    bool M_41AF90(int unused);
};
MATCH_FUNC(0x41AF90)
bool S41AF90::M_41AF90(int unused)
{
    return true;
}

MATCH_FUNC(0x41BC20)
int M_41BC20()
{
    return 1;
}

class S41BC30 {
public:
    int M_41BC30(int a, int b, int c, int d, int e, int f);
};
MATCH_FUNC(0x41BC30)
int S41BC30::M_41BC30(int a, int b, int c, int d, int e, int f)
{
    return 1;
}

class S41BC40 {
public:
    int M_41BC40(int a, int b, int c, int d, int e);
};
MATCH_FUNC(0x41BC40)
int S41BC40::M_41BC40(int a, int b, int c, int d, int e)
{
    return 1;
}

class S41BC50 {
public:
    int M_41BC50(int a, int b);
};
MATCH_FUNC(0x41BC50)
int S41BC50::M_41BC50(int a, int b)
{
    return 1;
}

class S4FA920 {
public:
    int M_4FA920(int a, int b);
};
MATCH_FUNC(0x4FA920)
int S4FA920::M_4FA920(int a, int b)
{
    return 1;
}

class S589AE0 {
public:
    int M_589AE0(int unused);
};
MATCH_FUNC(0x589AE0)
int S589AE0::M_589AE0(int unused)
{
    return 5;
}

class S5A4A60 {
public:
    int M_5A4A60(int a, int b, int c, int d, int e);
};
MATCH_FUNC(0x5A4A60)
int S5A4A60::M_5A4A60(int a, int b, int c, int d, int e)
{
    return 1;
}

MATCH_FUNC(0x41A0B0)
int M_41A0B0()
{
    return 0x7fffffff;
}

MATCH_FUNC(0x422E00)
int M_422E00()
{
    return 0x32;
}

MATCH_FUNC(0x443960)
int M_443960()
{
    return 0x3817c;
}

MATCH_FUNC(0x5ED915)
int M_5ED915()
{
    return 0xad90;
}

WIP_FUNC(0x5F9100)
int M_5F9100()
{
    return (int)0xffffffffu;
}

class S43FAB0 {
public:
    S43FAB0* Self_43FAB0();
};
MATCH_FUNC(0x43FAB0)
S43FAB0* S43FAB0::Self_43FAB0()
{
    return this;
}

class S4CEAE0 {
public:
    char pad_00[0x13dc];
    char Get_4CEAE0(int index);
};
MATCH_FUNC(0x4CEAE0)
char S4CEAE0::Get_4CEAE0(int index)
{
    return *(char*)((char*)this + 0x13dc + index);
}

class S412BC0 {
public:
    char pad_00[4];
    int* field_4;
    int Get_412BC0();
};
MATCH_FUNC(0x412BC0)
int S412BC0::Get_412BC0()
{
    return *(int*)((char*)field_4 + 0xc);
}

class S421FB0 {
public:
    char pad_00[0x24];
    int* field_24;
    int Get_421FB0();
};
MATCH_FUNC(0x421FB0)
int S421FB0::Get_421FB0()
{
    return *(short*)((char*)field_24 + 0x8f8);
}

class S53F060 {
public:
    char pad_00[8];
    int* field_8;
    int Get_53F060();
};
MATCH_FUNC(0x53F060)
int S53F060::Get_53F060()
{
    int* p = *(int**)((char*)field_8 + 8);
    return *(int*)((char*)p + 0x11c);
}

class S540BD0 {
public:
    char pad_00[8];
    int* field_8;
    int Get_540BD0();
};
MATCH_FUNC(0x540BD0)
int S540BD0::Get_540BD0()
{
    int* p = *(int**)((char*)field_8 + 8);
    return *(int*)((char*)p + 0xc8);
}

class S5477D0 {
public:
    char pad_00[0x30];
    int* field_30;
    int Get_5477D0();
};
MATCH_FUNC(0x5477D0)
int S5477D0::Get_5477D0()
{
    return *(int*)((char*)field_30 + 0x34);
}

class S408BC0 {
public:
    char pad_00[8];
    float* field_8;
    float Get_408BC0();
};
MATCH_FUNC(0x408BC0)
float S408BC0::Get_408BC0()
{
    return *(float*)((char*)field_8 + 0x100);
}

class S436B40 {
public:
    char pad_00[8];
    float* field_8;
    float Get_436B40();
};
MATCH_FUNC(0x436B40)
float S436B40::Get_436B40()
{
    return *(float*)((char*)field_8 + 0x140);
}

class S436C50 {
public:
    char pad_00[8];
    float* field_8;
    float Get_436C50();
};
MATCH_FUNC(0x436C50)
float S436C50::Get_436C50()
{
    return *(float*)((char*)field_8 + 0x134);
}

class S436C60 {
public:
    char pad_00[8];
    float* field_8;
    float Get_436C60();
};
MATCH_FUNC(0x436C60)
float S436C60::Get_436C60()
{
    return *(float*)((char*)field_8 + 0x158);
}

class S52C610 {
public:
    char pad_00[8];
    float* field_8;
    float Get_52C610();
};
MATCH_FUNC(0x52C610)
float S52C610::Get_52C610()
{
    return *(float*)((char*)field_8 + 0x2c);
}

extern int g_665340;
MATCH_FUNC(0x42F0A0)
int Get_42F0A0()
{
    return g_665340;
}

extern int g_741f90;
MATCH_FUNC(0x5542B0)
int Get_5542B0()
{
    return g_741f90;
}

extern int g_741f78;
MATCH_FUNC(0x5546C0)
int Get_5546C0()
{
    return g_741f78;
}

extern int g_741f7c;
MATCH_FUNC(0x5561B0)
int Get_5561B0()
{
    return g_741f7c;
}

extern int* g_741f60;
MATCH_FUNC(0x5562D0)
int Get_5562D0()
{
    return *(int*)((char*)g_741f60 + 0x1320);
}

extern int* g_741f5c;
MATCH_FUNC(0x5566F0)
int Get_5566F0()
{
    return *(int*)((char*)g_741f5c + 0x1074);
}

extern int g_741b58[];
MATCH_FUNC(0x55A0C0)
int Get_55A0C0(int index)
{
    return g_741b58[index];
}

extern int g_77279c;
MATCH_FUNC(0x6004B7)
int Get_6004B7()
{
    return g_77279c;
}

extern int g_772a1c;
MATCH_FUNC(0x6004BD)
int Get_6004BD()
{
    return g_772a1c;
}
