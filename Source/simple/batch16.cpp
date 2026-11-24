#include "Function.hpp"

class S4CED80 {
public:
    char pad_00[0x1930];
    int Get_4CED80(int index);
};

class S4CEDA0 {
public:
    char pad_00[0x1970];
    int Get_4CEDA0(int index);
};

class S4CEDC0 {
public:
    char pad_00[0x19b0];
    int Get_4CEDC0(int index);
};

class S562EE0 {
public:
    char pad_00[0x108];
    int Get_562EE0(int index);
};
MATCH_FUNC(0x562EE0)
int S562EE0::Get_562EE0(int index)
{
    if (index < 0 || index >= 0x28)
        return -1;
    return *(int*)((char*)this + 0x108 + index * 4);
}

class S5BF6B0 {
public:
    char pad_00[0x18];
    int* array_18;
    char pad_1c[4];
    int count_20;
    int Get_5BF6B0(int index);
};
MATCH_FUNC(0x5BF6B0)
int S5BF6B0::Get_5BF6B0(int index)
{
    if (index >= count_20 || index < 0)
        return 0;
    return array_18[index];
}

class S5BF970 {
public:
    char pad_00[0x28];
    int* array_28;
    char pad_2c[4];
    int count_30;
    int Get_5BF970(int index);
};
MATCH_FUNC(0x5BF970)
int S5BF970::Get_5BF970(int index)
{
    if (index >= count_30 || index < 0)
        return 0;
    return array_28[index];
}

class S5C06B0 {
public:
    char pad_00[0x10];
    int* array_10;
    char pad_14[4];
    int count_18;
    int Get_5C06B0(int index);
};
MATCH_FUNC(0x5C06B0)
int S5C06B0::Get_5C06B0(int index)
{
    if (index >= count_18 || index < 0)
        return 0;
    return array_10[index];
}

class S5C1910 {
public:
    char pad_00[0x1a08];
    int Get_5C1910(int index);
};
MATCH_FUNC(0x5C1910)
int S5C1910::Get_5C1910(int index)
{
    if (index < 0 || index >= 0x10)
        return 0;
    return *(int*)((char*)this + 0x1a08 + index * 24);
}

class S5C1930 {
public:
    char pad_00[0x1a04];
    int Get_5C1930(int index);
};
MATCH_FUNC(0x5C1930)
int S5C1930::Get_5C1930(int index)
{
    if (index < 0 || index >= 0x10)
        return 0;
    return *(int*)((char*)this + 0x1a04 + index * 24);
}

class S5C1950 {
public:
    char pad_00[0x19f4];
    int Get_5C1950(int index);
};
MATCH_FUNC(0x5C1950)
int S5C1950::Get_5C1950(int index)
{
    if (index < 0 || index >= 0x10)
        return 0;
    return *(int*)((char*)this + 0x19f4 + index * 24);
}

class S5C1970 {
public:
    char pad_00[0x19f8];
    int Get_5C1970(int index);
};
MATCH_FUNC(0x5C1970)
int S5C1970::Get_5C1970(int index)
{
    if (index < 0 || index >= 0x10)
        return 0;
    return *(int*)((char*)this + 0x19f8 + index * 24);
}

class S5C1990 {
public:
    char pad_00[0x19fc];
    int Get_5C1990(int index);
};
MATCH_FUNC(0x5C1990)
int S5C1990::Get_5C1990(int index)
{
    if (index < 0 || index >= 0x10)
        return 0;
    return *(int*)((char*)this + 0x19fc + index * 24);
}

class S5C19B0 {
public:
    char pad_00[0x1a00];
    int Get_5C19B0(int index);
};
MATCH_FUNC(0x5C19B0)
int S5C19B0::Get_5C19B0(int index)
{
    if (index < 0 || index >= 0x10)
        return 0;
    return *(int*)((char*)this + 0x1a00 + index * 24);
}

class S5CF980 {
public:
    char pad_00[0x28a];
    int Get_5CF980(int index);
};
MATCH_FUNC(0x5CF980)
int S5CF980::Get_5CF980(int index)
{
    if (index < 1 || index >= 9)
        return -1;
    return *(unsigned char*)((char*)this + 0x28a + index);
}

class S4CED60 {
public:
    char* Ref_4CED60(int index);
};
