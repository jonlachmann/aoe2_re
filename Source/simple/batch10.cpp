#include "Function.hpp"

extern int g_66d4b0;
extern int g_66d4b4;
extern int g_66d4b8;

extern int g_66e3e8;
extern int g_66e3ec;
extern int g_66e3f0;

extern int g_66f630;
extern int g_66f634;
extern int g_66f638;

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

class S437710 {
public:
    char pad_00[0x980];
    void Get_437710(int* a, int* b, int* c);
};

class S4A22F0 {
public:
    char pad_00[0x90];
    void Get_4A22F0(int* out);
};

class S48A890 {
public:
    char pad_00[0x118];
    void Set_48A890(int a, int b, int c, int d);
};

class S4B8C30 {
public:
    char pad_00[0x10c];
    void Set_4B8C30(int a, int b, int c, int d, int e);
};

class S5BC4D0 {
public:
    char pad_00[0x11c0];
    void Set_5BC4D0(int a, int b, int c, int d);
};

class S5D6120 {
public:
    char pad_00[0x122];
    void Get_5D6120(unsigned short* a, unsigned short* b);
};


class S409E90 {
public:
    void Set_409E90(unsigned char a, int b, unsigned char c,
                    unsigned char d, unsigned char e, unsigned char f);
};

class S4A3920 {
public:
    char pad_00[0x328];
    void Set_4A3920(unsigned char a, unsigned char b, unsigned char c,
                    unsigned char d, unsigned char e, unsigned char f);
};

class S4E8270 {
public:
    char pad_00[0x1200];
    int* field_1200;
    int Get_4E8270(int index);
};
