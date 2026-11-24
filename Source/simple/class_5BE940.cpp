#include "Function.hpp"

class S5BEItem {
public:
    char pad_00[4];
    unsigned char flag_4;
    char pad_05[0xa - 0x05];
    unsigned char flag_a;
    unsigned char flag_b;
    char pad_0c[0xe - 0xc];
    unsigned char flag_e;
    char pad_0f[0x10 - 0xf];
    unsigned char flag_10;
    unsigned char array_10[0x20];
};

class S5BE940 {
public:
    S5BEItem** array_0;
    int field_4;
    char pad_08[0x1c - 0x08];
    int field_1c;
    char pad_20[0x34 - 0x20];
    int field_34;
    int field_38;
    char gap_3c[4];
    int field_40;
    int field_44;
    int field_48;
    int field_4c;
    int field_50;
    int field_54;
    int field_58;
    char pad_5c[0x68 - 0x5c];
    int field_68;
    int field_6c;
    int field_70;

    void SetIndex_5BE8D0(int index);
    bool Set_5BE940(int a, int b);
    bool Read_5BEB10(int index, int* out);
    bool GetBoth_5BEB40(int* a, int* b);
    bool GetFlags_5BEBB0(int* a, int* b);
    bool GetFlag4_5BEC10(int* a, int* b);
    bool Set4_5BE970(int a, int b, int c, int d);
    bool Get4_5BEB70(int* a, int* b, int* c, int* d);
    bool Get2_5BEBE0(int* a, int* b);
    void Adjust_5BEC40(int limit);
};

MATCH_FUNC(0x5BE8D0)
void S5BE940::SetIndex_5BE8D0(int index)
{
    field_4 = index;
}

MATCH_FUNC(0x5BE940)
bool S5BE940::Set_5BE940(int a, int b)
{
    S5BEItem* item = array_0[field_4];
    if (item->flag_e == 0)
        return false;
    field_44 = a;
    field_48 = b;
    return true;
}

MATCH_FUNC(0x5BEB10)
bool S5BE940::Read_5BEB10(int index, int* out)
{
    S5BEItem* item = array_0[field_4];
    if (((unsigned char*)item)[index] == 0)
        return false;
    *out = ((int*)this)[(0xc / 4) + index];
    return true;
}

MATCH_FUNC(0x5BEB40)
bool S5BE940::GetBoth_5BEB40(int* a, int* b)
{
    S5BEItem* item = array_0[field_4];
    if (item->flag_e == 0)
        return false;
    *a = field_44;
    *b = field_48;
    return true;
}

MATCH_FUNC(0x5BEBB0)
bool S5BE940::GetFlags_5BEBB0(int* a, int* b)
{
    S5BEItem* item = array_0[field_4];
    if (item->flag_a == 0)
        return false;
    *a = field_6c;
    *b = field_34;
    return true;
}

MATCH_FUNC(0x5BEC10)
bool S5BE940::GetFlag4_5BEC10(int* a, int* b)
{
    S5BEItem* item = array_0[field_4];
    if (item->flag_4 == 0)
        return false;
    *a = field_68;
    *b = field_1c;
    return true;
}

MATCH_FUNC(0x5BE970)
bool S5BE940::Set4_5BE970(int a, int b, int c, int d)
{
    S5BEItem* item = array_0[field_4];
    if (item->flag_10 == 0)
        return false;
    field_4c = a;
    field_50 = b;
    field_54 = c;
    field_58 = d;
    return true;
}

MATCH_FUNC(0x5BEB70)
bool S5BE940::Get4_5BEB70(int* a, int* b, int* c, int* d)
{
    S5BEItem* item = array_0[field_4];
    if (item->flag_10 == 0)
        return false;
    *a = field_4c;
    *b = field_50;
    *c = field_54;
    *d = field_58;
    return true;
}

MATCH_FUNC(0x5BEBE0)
bool S5BE940::Get2_5BEBE0(int* a, int* b)
{
    S5BEItem* item = array_0[field_4];
    if (item->flag_b == 0)
        return false;
    *a = field_70;
    *b = field_38;
    return true;
}

MATCH_FUNC(0x5BEC40)
void S5BE940::Adjust_5BEC40(int limit)
{
    if (field_4 == 8 || field_4 == 9) {
        if (field_40 == limit)
            field_40 = -1;
        int value = field_40;
        if (value > limit)
            field_40 = value - 1;
    }
}
