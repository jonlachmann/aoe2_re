#include "Function.hpp"

class S406220 {
public:
    void Clear_406220(char* p);
};

class S41AF50 {
public:
    char pad_00[0x14];
    void Set_41AF50(unsigned short v);
};

class S4BCE90 {
public:
    char pad_00[0x102];
    void Set_4BCE90(unsigned short v);
};

class S4BCEA0 {
public:
    char pad_00[0x100];
    void Set_4BCEA0(unsigned short v);
};

class S49F240 {
public:
    char pad_00[0x68];
    void Zero_49F240(int index);
};

class S525870 {
public:
    char pad_14[0x14];
    unsigned char field_14;
    char pad_15[7];
    int field_1c;
    void Set_525870(int unused);
};

class S437960 {
public:
    char pad_00[0x2580];
    int field_2580;
    int Inc_437960();
};

class S438690 {
public:
    char pad_00[0x210];
    int field_210;
    int Inc_438690();
};

class S4118B0 {
public:
    void Init_4118B0();
};

class S41ADA0 {
public:
    void Init_41ADA0();
};

class S43F8B0 {
public:
    S43F8B0* Reset_43F8B0();
};

class S497D80 {
public:
    S497D80* Reset_497D80();
};

class S4AF0D0 {
public:
    char pad_00[8];
    int field_8;
    int Take_4AF0D0();
};

class S4ACA10 {
public:
    char pad_00[0x170];
    void Set_4ACA10(unsigned short a, unsigned short b);
};

class S5BFBB0 {
public:
    char pad_00[0x14];
    int field_14;
    void Get_5BFBB0(int* out);
};
MATCH_FUNC(0x5BFBB0)
void S5BFBB0::Get_5BFBB0(int* out)
{
    *out = *(int*)((char*)this + 0x14);
}

extern int g_77267c;
class S5DE800 {
public:
    void Set_5DE800(int v);
};

extern int g_661c14;

class S487740 {
public:
    char pad_00[4];
    int field_4;
    int field_8;
    char pad_0c[0x18 - 0x0c];
    unsigned char field_18;
    bool Set_487740(int a, int b, unsigned char c);
};

class S5A5490 {
public:
    char pad_00[0x1bae];
    void Set_5A5490(int unused, int index);
};
MATCH_FUNC(0x5A5490)
void S5A5490::Set_5A5490(int unused, int index)
{
    *(unsigned char*)((char*)this + 0x1bae + index) = 1;
}
