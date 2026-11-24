#include "Function.hpp"

extern int g_66d4b0;
extern int g_66d4b4;
extern int g_66d4b8;
WIP_FUNC(0x4654D0)
void Init_4654D0()
{
    *(volatile int*)&g_66d4b0 = 0;
    *(volatile int*)&g_66d4b4 = 0x3f800000;
    *(volatile int*)&g_66d4b8 = 0;
}

extern int g_66e3e8;
extern int g_66e3ec;
extern int g_66e3f0;
WIP_FUNC(0x48BAD0)
void Init_48BAD0()
{
    *(volatile int*)&g_66e3e8 = 0;
    *(volatile int*)&g_66e3ec = 0x3f800000;
    *(volatile int*)&g_66e3f0 = 0;
}

extern int g_66f630;
extern int g_66f634;
extern int g_66f638;
WIP_FUNC(0x4A6E40)
void Init_4A6E40()
{
    *(volatile int*)&g_66f630 = 0;
    *(volatile int*)&g_66f634 = 0;
    *(volatile int*)&g_66f638 = 0;
}

extern int g_7715f0;
extern int g_7715f4;
extern int g_7715f8;
WIP_FUNC(0x5CFAF0)
void Init_5CFAF0()
{
    *(volatile int*)&g_7715f0 = 0;
    *(volatile int*)&g_7715f4 = 0;
    *(volatile int*)&g_7715f8 = 0;
}

class S41EB30 {
public:
    char pad_00[0x564];
    void Init_41EB30();
};
MATCH_FUNC(0x41EB30)
void S41EB30::Init_41EB30()
{
    int one = 1;
    *(int*)((char*)this + 0x580) = one;
    *(int*)((char*)this + 0x5a0) = one;
    *(int*)((char*)this + 0x5c0) = one;
    *(int*)((char*)this + 0x6a0) = one;
    *(int*)((char*)this + 0x700) = one;
    *(int*)((char*)this + 0x564) = one;
    *(int*)((char*)this + 0x5e4) = one;
}

class S437710 {
public:
    char pad_00[0x980];
    void Get_437710(int* a, int* b, int* c);
};
MATCH_FUNC(0x437710)
void S437710::Get_437710(int* a, int* b, int* c)
{
    *a = *(int*)((char*)this + 0x980);
    *b = *(int*)((char*)this + 0x984);
    *c = *(int*)((char*)this + 0x988);
}

class S4A22F0 {
public:
    char pad_00[0x90];
    void Get_4A22F0(int* out);
};
MATCH_FUNC(0x4A22F0)
void S4A22F0::Get_4A22F0(int* out)
{
    out[0] = *(int*)((char*)this + 0x90);
    out[1] = *(int*)((char*)this + 0x94);
    out[2] = *(int*)((char*)this + 0x98);
    out[3] = *(int*)((char*)this + 0x9c);
}

class S48A890 {
public:
    char pad_00[0x118];
    void Set_48A890(int a, int b, int c, int d);
};
MATCH_FUNC(0x48A890)
void S48A890::Set_48A890(int a, int b, int c, int d)
{
    *(int*)((char*)this + 0x118) = a;
    *(int*)((char*)this + 0x11c) = b;
    *(int*)((char*)this + 0x120) = c;
    *(int*)((char*)this + 0x124) = d;
}

class S4B8C30 {
public:
    char pad_00[0x10c];
    void Set_4B8C30(int a, int b, int c, int d, int e);
};
MATCH_FUNC(0x4B8C30)
void S4B8C30::Set_4B8C30(int a, int b, int c, int d, int e)
{
    *(int*)((char*)this + 0x10c) = a;
    *(int*)((char*)this + 0x110) = b;
    *(int*)((char*)this + 0x114) = c;
    *(int*)((char*)this + 0x118) = d;
    *(int*)((char*)this + 0x11c) = e;
}

class S5BC4D0 {
public:
    char pad_00[0x11c0];
    void Set_5BC4D0(int a, int b, int c, int d);
};
MATCH_FUNC(0x5BC4D0)
void S5BC4D0::Set_5BC4D0(int a, int b, int c, int d)
{
    *(int*)((char*)this + 0x11c0) = a;
    *(int*)((char*)this + 0x11c4) = b;
    *(int*)((char*)this + 0x11c8) = c;
    *(int*)((char*)this + 0x11cc) = d;
}

class S5D6120 {
public:
    char pad_00[0x122];
    void Get_5D6120(unsigned short* a, unsigned short* b);
};
MATCH_FUNC(0x5D6120)
void S5D6120::Get_5D6120(unsigned short* a, unsigned short* b)
{
    *a = *(unsigned short*)((char*)this + 0x122);
    *b = *(unsigned short*)((char*)this + 0x124);
}

MATCH_FUNC(0x5FC8EC)
void Init_5FC8EC()
{
    *(int*)0x661cac = 0x600f6b;
    *(int*)0x661ca8 = 0x6012d6;
    *(int*)0x661cb0 = 0x600fd1;
    *(int*)0x661cb4 = 0x600f11;
    *(int*)0x661cb8 = 0x600fb9;
    *(int*)0x661cbc = 0x6012d6;
}

class S409E90 {
public:
    void Set_409E90(unsigned char a, int b, unsigned char c,
                    unsigned char d, unsigned char e, unsigned char f);
};
MATCH_FUNC(0x409E90)
void S409E90::Set_409E90(unsigned char a, int b, unsigned char c,
                         unsigned char d, unsigned char e, unsigned char f)
{
    *(unsigned char*)((char*)this) = a;
    *(int*)((char*)this + 4) = b;
    *(unsigned char*)((char*)this + 8) = c;
    *(unsigned char*)((char*)this + 9) = d;
    *(unsigned char*)((char*)this + 0xa) = e;
    *(unsigned char*)((char*)this + 0xb) = f;
}

class S4A3920 {
public:
    char pad_00[0x328];
    void Set_4A3920(unsigned char a, unsigned char b, unsigned char c,
                    unsigned char d, unsigned char e, unsigned char f);
};
MATCH_FUNC(0x4A3920)
void S4A3920::Set_4A3920(unsigned char a, unsigned char b, unsigned char c,
                         unsigned char d, unsigned char e, unsigned char f)
{
    *(unsigned char*)((char*)this + 0x328) = a;
    *(unsigned char*)((char*)this + 0x329) = b;
    *(unsigned char*)((char*)this + 0x32a) = c;
    *(unsigned char*)((char*)this + 0x32b) = d;
    *(unsigned char*)((char*)this + 0x32c) = e;
    *(unsigned char*)((char*)this + 0x32d) = f;
}

class S4E8270 {
public:
    char pad_00[0x1200];
    int* field_1200;
    int Get_4E8270(int index);
};
MATCH_FUNC(0x4E8270)
int S4E8270::Get_4E8270(int index)
{
    int* p = *(int**)((char*)field_1200 + 0x4c);
    return *(short*)((char*)p[index] + 0x4f8);
}
