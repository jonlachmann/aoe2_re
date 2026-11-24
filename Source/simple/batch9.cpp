#include "Function.hpp"

class S407BD0 {
public:
    bool M_407BD0(int unused);
};



class S411C20 {
public:
    int M_411C20(int unused);
};

class S415750 {
public:
    int M_415750(int unused);
};

class S41AF90 {
public:
    bool M_41AF90(int unused);
};

class S41BC30 {
public:
    int M_41BC30(int a, int b, int c, int d, int e, int f);
};

class S41BC40 {
public:
    int M_41BC40(int a, int b, int c, int d, int e);
};

class S41BC50 {
public:
    int M_41BC50(int a, int b);
};

class S4FA920 {
public:
    int M_4FA920(int a, int b);
};

class S589AE0 {
public:
    int M_589AE0(int unused);
};

class S5A4A60 {
public:
    int M_5A4A60(int a, int b, int c, int d, int e);
};
MATCH_FUNC(0x5A4A60)
int S5A4A60::M_5A4A60(int a, int b, int c, int d, int e)
{
    return 1;
}





class S43FAB0 {
public:
    S43FAB0* Self_43FAB0();
};

class S4CEAE0 {
public:
    char pad_00[0x13dc];
    char Get_4CEAE0(int index);
};

class S412BC0 {
public:
    char pad_00[4];
    int* field_4;
    int Get_412BC0();
};

class S421FB0 {
public:
    char pad_00[0x24];
    int* field_24;
    int Get_421FB0();
};

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

class S436B40 {
public:
    char pad_00[8];
    float* field_8;
    float Get_436B40();
};

class S436C50 {
public:
    char pad_00[8];
    float* field_8;
    float Get_436C50();
};

class S436C60 {
public:
    char pad_00[8];
    float* field_8;
    float Get_436C60();
};

class S52C610 {
public:
    char pad_00[8];
    float* field_8;
    float Get_52C610();
};

extern int g_665340;

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

extern int g_772a1c;
