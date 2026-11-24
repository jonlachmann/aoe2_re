#include "Function.hpp"

class S464D90 {
public:
    int field_0;
    int field_4;
    bool Set_464D90(int value);
};
MATCH_FUNC(0x464D90)
bool S464D90::Set_464D90(int value)
{
    if (value < field_4) {
        field_0 = value;
        return true;
    }
    field_0 = -1;
    return false;
}

class S473AA0 {
public:
    char pad_00[0x24];
    unsigned char field_24;
    void Set_473AA0(unsigned char value);
};
MATCH_FUNC(0x473AA0)
void S473AA0::Set_473AA0(unsigned char value)
{
    if (value > 0)
        field_24 = value;
}

class S4AF4B0 {
public:
    char pad_00[0xf8];
    void Set_4AF4B0(short index, int a, int b);
};
MATCH_FUNC(0x4AF4B0)
void S4AF4B0::Set_4AF4B0(short index, int a, int b)
{
    *(int*)((char*)this + 0xf8 + index * 4) = a;
    *(int*)((char*)this + 0x11c + index * 4) = b;
}

class S5DCC30 {
public:
    char pad_00[0x2c];
    void Init_5DCC30();
};

class S4CE550 {
public:
    char pad_00[0x1930];
    void Set_4CE550(int index, int value);
};
MATCH_FUNC(0x4CE550)
void S4CE550::Set_4CE550(int index, int value)
{
    if (index >= 0 && index < 0x10)
        *(int*)((char*)this + 0x1930 + index * 4) = value;
}

class S4CE570 {
public:
    char pad_00[0x1970];
    void Set_4CE570(int index, int value);
};
MATCH_FUNC(0x4CE570)
void S4CE570::Set_4CE570(int index, int value)
{
    if (index >= 0 && index < 0x10)
        *(int*)((char*)this + 0x1970 + index * 4) = value;
}

class S4CE590 {
public:
    char pad_00[0x19b0];
    void Set_4CE590(int index, int value);
};
MATCH_FUNC(0x4CE590)
void S4CE590::Set_4CE590(int index, int value)
{
    if (index >= 0 && index < 0x10)
        *(int*)((char*)this + 0x19b0 + index * 4) = value;
}

class S562F00 {
public:
    char pad_00[0x108];
    void Set_562F00(int index, int value);
};
MATCH_FUNC(0x562F00)
void S562F00::Set_562F00(int index, int value)
{
    if (index >= 0 && index < 0x28)
        *(int*)((char*)this + 0x108 + index * 4) = value;
}

class S567770 {
public:
    char pad_00[0x130c];
    void Set_567770(int index, unsigned char value);
};
MATCH_FUNC(0x567770)
void S567770::Set_567770(int index, unsigned char value)
{
    if (index >= 0 && index < 9)
        *(unsigned char*)((char*)this + 0x130c + index) = value;
}

class S567790 {
public:
    char pad_00[0x1315];
    void Set_567790(int index, unsigned char value);
};
MATCH_FUNC(0x567790)
void S567790::Set_567790(int index, unsigned char value)
{
    if (index >= 0 && index < 9)
        *(unsigned char*)((char*)this + 0x1315 + index) = value;
}

class S5C1510 {
public:
    char pad_00[0x19f4];
    void Set_5C1510(int index, int value);
};
MATCH_FUNC(0x5C1510)
void S5C1510::Set_5C1510(int index, int value)
{
    if (index >= 0 && index < 0x10)
        *(int*)((char*)this + 0x19f4 + index * 24) = value;
}

class S5C1530 {
public:
    char pad_00[0x19f8];
    void Set_5C1530(int index, int value);
};
MATCH_FUNC(0x5C1530)
void S5C1530::Set_5C1530(int index, int value)
{
    if (index >= 0 && index < 0x10)
        *(int*)((char*)this + 0x19f8 + index * 24) = value;
}

class S5C1550 {
public:
    char pad_00[0x19fc];
    void Set_5C1550(int index, int value);
};
MATCH_FUNC(0x5C1550)
void S5C1550::Set_5C1550(int index, int value)
{
    if (index >= 0 && index < 0x10)
        *(int*)((char*)this + 0x19fc + index * 24) = value;
}

class S5C1570 {
public:
    char pad_00[0x1a00];
    void Set_5C1570(int index, int value);
};
MATCH_FUNC(0x5C1570)
void S5C1570::Set_5C1570(int index, int value)
{
    if (index >= 0 && index < 0x10)
        *(int*)((char*)this + 0x1a00 + index * 24) = value;
}

class S4A3CF0 {
public:
    char pad_00[0x348];
    void Get_4A3CF0(int* a, int* b);
};
MATCH_FUNC(0x4A3CF0)
void S4A3CF0::Get_4A3CF0(int* a, int* b)
{
    *a = *(int*)((char*)this + 0x348);
    *b = *(int*)((char*)this + 0x34c);
}

