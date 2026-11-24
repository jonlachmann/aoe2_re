#include "Function.hpp"

class S410530 {
public:
    char pad_00[0x3fc];
    int* field_3fc;
    void Init_410530();
};

class S416DA0 {
public:
    char pad_00[0x34];
    int field_34;
    int field_38;
    char pad_3c[0x1c];
    int field_58;
    int field_5c;
    void Set_416DA0(int a, int b, int c, int d, int e);
};

class S45AE80 {
public:
    char pad_00[0x150];
    void Set_45AE80(int a, int b, int c, int d, int unused1, int unused2);
};
MATCH_FUNC(0x45AE80)
void S45AE80::Set_45AE80(int a, int b, int c, int d, int unused1, int unused2)
{
    *(int*)((char*)this + 0x150) = a;
    *(int*)((char*)this + 0x154) = c;
    *(int*)((char*)this + 0x158) = b;
    *(int*)((char*)this + 0x160) = 0x40;
    *(int*)((char*)this + 0x164) = 0x40;
    *(int*)((char*)this + 0x15c) = d;
    *(int*)((char*)this + 0x168) = 0x24;
    *(int*)((char*)this + 0x16c) = 0x24;
    *(int*)((char*)this + 0x170) = 0xe;
    *(int*)((char*)this + 0x174) = 3;
}

class S4AF930 {
public:
    char pad_00[0x2b8];
    void Set_4AF930(int a, unsigned char b, unsigned char c,
                    unsigned char d, unsigned char e, unsigned char f,
                    unsigned char g);
};
MATCH_FUNC(0x4AF930)
void S4AF930::Set_4AF930(int a, unsigned char b, unsigned char c,
                          unsigned char d, unsigned char e, unsigned char f,
                          unsigned char g)
{
    *(int*)((char*)this + 0x2b8) = a;
    *(unsigned char*)((char*)this + 0x2bc) = b;
    *(unsigned char*)((char*)this + 0x2bd) = c;
    *(unsigned char*)((char*)this + 0x2be) = d;
    *(unsigned char*)((char*)this + 0x2bf) = e;
    *(unsigned char*)((char*)this + 0x2c0) = f;
    *(unsigned char*)((char*)this + 0x2c1) = g;
}

class S4B8C70 {
public:
    char pad_00[0x1bc];
    void Set_4B8C70(int a, unsigned char b, unsigned char c,
                    unsigned char d, unsigned char e, unsigned char f,
                    unsigned char g);
};
MATCH_FUNC(0x4B8C70)
void S4B8C70::Set_4B8C70(int a, unsigned char b, unsigned char c,
                          unsigned char d, unsigned char e, unsigned char f,
                          unsigned char g)
{
    *(int*)((char*)this + 0x1bc) = a;
    *(unsigned char*)((char*)this + 0x1c0) = b;
    *(unsigned char*)((char*)this + 0x1c1) = c;
    *(unsigned char*)((char*)this + 0x1c2) = d;
    *(unsigned char*)((char*)this + 0x1c3) = e;
    *(unsigned char*)((char*)this + 0x1c4) = f;
    *(unsigned char*)((char*)this + 0x1c5) = g;
}

class S5ADE20 {
public:
    char pad_00[0x180];
    void Set_5ADE20(int a, unsigned char b, unsigned char c,
                    unsigned char d, unsigned char e, unsigned char f,
                    unsigned char g);
};
MATCH_FUNC(0x5ADE20)
void S5ADE20::Set_5ADE20(int a, unsigned char b, unsigned char c,
                          unsigned char d, unsigned char e, unsigned char f,
                          unsigned char g)
{
    *(int*)((char*)this + 0x180) = a;
    *(unsigned char*)((char*)this + 0x184) = b;
    *(unsigned char*)((char*)this + 0x185) = c;
    *(unsigned char*)((char*)this + 0x186) = d;
    *(unsigned char*)((char*)this + 0x187) = e;
    *(unsigned char*)((char*)this + 0x188) = f;
    *(unsigned char*)((char*)this + 0x189) = g;
}
