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

class S4AF930 {
public:
    char pad_00[0x2b8];
    void Set_4AF930(int a, unsigned char b, unsigned char c,
                    unsigned char d, unsigned char e, unsigned char f,
                    unsigned char g);
};

class S4B8C70 {
public:
    char pad_00[0x1bc];
    void Set_4B8C70(int a, unsigned char b, unsigned char c,
                    unsigned char d, unsigned char e, unsigned char f,
                    unsigned char g);
};

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
