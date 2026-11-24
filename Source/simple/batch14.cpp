#include "Function.hpp"

class S407BF0 {
public:
    void M_407BF0(int, int, int, int, int, int);
};

class S407C50 {
public:
    void M_407C50(int);
};

class S408050 {
public:
    void M_408050(int, int);
};

class S408650 {
public:
    void M_408650(int);
};

class S409CB0 {
public:
    void M_409CB0(int, int, int);
};

class S41A030 {
public:
    void M_41A030(int, int, int, int);
};

class S41BC10 {
public:
    void M_41BC10(int, int, int, int, int);
};

class S43A080 {
public:
    void M_43A080(int, int, int, int, int, int, int, int, int);
};

MATCH_FUNC(0x43A080)
void S43A080::M_43A080(int, int, int, int, int, int, int, int, int)
{
}
class S4AA5D0 {
public:
    void M_4AA5D0(int, int, int);
};

class S4AAFC0 {
public:
    void M_4AAFC0(int, int, int, int, int);
};

class S4AE900 {
public:
    void M_4AE900(int, int, int, int, int, int);
};

class S5A12C0 {
public:
    void M_5A12C0(int, int, int, int);
};

class S5E2CC0 {
public:
    void M_5E2CC0(int, int);
};

class S409DE0 {
public:
    char pad_00[0x20];
    float Get_409DE0();
};

class S409DF0 {
public:
    char pad_00[0x24];
    float Get_409DF0();
};

class S409E00 {
public:
    char pad_00[0x28];
    float Get_409E00();
};

class S40A0E0 {
public:
    char pad_00[0x50];
    float Get_40A0E0();
};

class S40A0F0 {
public:
    char pad_00[0x54];
    float Get_40A0F0();
};

class S40A100 {
public:
    char pad_00[0x58];
    float Get_40A100();
};

class S40A110 {
public:
    char pad_00[0x5c];
    float Get_40A110();
};

class S40A120 {
public:
    char pad_00[0x60];
    float Get_40A120();
};

class S40A130 {
public:
    char pad_00[0x64];
    float Get_40A130();
};

class S46A9A0 {
public:
    char pad_00[0x6c];
    float Get_46A9A0();
};

class S46A9D0 {
public:
    char pad_00[0x68];
    float Get_46A9D0();
};

class S46A9F0 {
public:
    char pad_00[0x64];
    float Get_46A9F0();
};

class S46AA40 {
public:
    char pad_00[0x78];
    float Get_46AA40();
};

class S46AA60 {
public:
    char pad_00[0x74];
    float Get_46AA60();
};

class S46AA80 {
public:
    char pad_00[0x70];
    float Get_46AA80();
};

class S409A00 {
public:
    char pad_00[0x4];
    unsigned short Get_409A00();
};

class S41B5F0 {
public:
    char pad_00[0x14];
    unsigned short Get_41B5F0();
};

class S44B9D0 {
public:
    char pad_00[0x814];
    unsigned short Get_44B9D0();
};

class S4BCE40 {
public:
    char pad_00[0xfc];
    int Get_4BCE40();
};

MATCH_FUNC(0x4BCE40)
int S4BCE40::Get_4BCE40()
{
    return *(short*)((char*)this + 0xfc);
}
class S4BCE50 {
public:
    char pad_00[0xfe];
    int Get_4BCE50();
};

MATCH_FUNC(0x4BCE50)
int S4BCE50::Get_4BCE50()
{
    return *(short*)((char*)this + 0xfe);
}
class S4BCE60 {
public:
    char pad_00[0x104];
    int Get_4BCE60();
};

MATCH_FUNC(0x4BCE60)
int S4BCE60::Get_4BCE60()
{
    return *(short*)((char*)this + 0x104);
}
class S4AF9F0 {
public:
    char pad_00[0x202];
    int Get_4AF9F0();
};

MATCH_FUNC(0x4AF9F0)
int S4AF9F0::Get_4AF9F0()
{
    return *(short*)((char*)this + 0x202);
}
extern float g_61c598;
extern float g_61c5a8;
extern float g_61c584;
extern float g_61dd2c;
extern float g_621178;
extern float g_623e70;

class S407B90 {
public:
    float Get_407B90(int unused);
};

class S41A090 {
public:
    float Get_41A090(int a, int b, int c);
};

class S41A0A0 {
public:
    float Get_41A0A0(int a, int b, int c, int d);
};

class S434BE0 {
public:
    float Get_434BE0(int unused);
};

class S4747F0 {
public:
    float Get_4747F0(int unused);
};

class S4779A0 {
public:
    float Get_4779A0(int unused);
};

class S4779B0 {
public:
    float Get_4779B0(int unused);
};

MATCH_FUNC(0x4CEAD0)
float Get_4CEAD0()
{
    return g_623e70;
}

class S4AFA00 {
public:
    char pad_00[0x202];
    int Get_4AFA00();
};
MATCH_FUNC(0x4AFA00)
int S4AFA00::Get_4AFA00()
{
    int index = *(short*)((char*)this + 0x202);
    return *(int*)((char*)this + 0xf8 + index * 4);
}

class S4AFA10 {
public:
    char pad_00[0x202];
    int Get_4AFA10();
};
MATCH_FUNC(0x4AFA10)
int S4AFA10::Get_4AFA10()
{
    int index = *(short*)((char*)this + 0x202);
    return *(int*)((char*)this + 0x11c + index * 4);
}

class S40F4C0 {
public:
    char pad_00[0xea4];
    int Get_40F4C0();
};

