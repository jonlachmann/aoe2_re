// free_engine-late — engine-late region free functions migrated from
// Source/simple. Partial struct declarations travel with their bodies.
#include "Function.hpp"


// 0x5C1A00 — cluster C_cluster_4CED80: 20-byte record array at 0x1BAC,
// indexed by a2 + 12 * count (count at 0x4CD4).
class S5C1A00 {
public:
    char pad_00[1771 * 4];
    int records[0x3128 / 4];      // 0x1BAC .. 0x4CD4
    int count;                    // 0x4CD4

    int Get_5C1A00(int a2);
};

// 0x5D0C60 — clear a member when its tag is 7.
int __stdcall sub_5D0C60(int a1);

MATCH_FUNC(0x5D0C60)
int __stdcall sub_5D0C60(int a1)
{
    int result = *(int*)(a1 + 40);
    if (result) {
        if (*(unsigned char*)(result + 72) == 7) {
            *(unsigned char*)(a1 + 46) = 2;
            *(int*)(a1 + 40) = 0;
        }
    }
    return result;
}

class S5D17B0Node {
public:
    char pad_00[0x30];
    S5D17B0Node* field_30;
};

class S5D17B0 {
public:
    char pad_00[4];
    S5D17B0Node* field_4;
    S5D17B0Node* Index_5D17B0(int index);
};

MATCH_FUNC(0x5D17B0)
S5D17B0Node* S5D17B0::Index_5D17B0(int index)
{
    int i = 0;
    S5D17B0Node* p = field_4;
    while (p != 0) {
        if (i == index)
            return p;
        p = p->field_30;
        ++i;
    }
    return 0;
}

class S5D17D0 {
public:
    char pad_00[0x10];
    bool field_10;
    bool Check_5D17D0();
};
WIP_FUNC(0x5D17D0)
bool S5D17D0::Check_5D17D0()
{
    return field_10 == 2;
}

// 0x5D1F00 — last matching node value in a link chain.
class S5D1F00 {
public:
    char pad_00[5*4];
    int* head;                    // self[5]

    int Find_5D1F00(char a2);
};

MATCH_FUNC(0x5D1F00)
int S5D1F00::Find_5D1F00(char a2)
{
    int* v2 = this->head;
    int result;
    for (result = 0; v2; v2 = *(int**)((char*)v2 + 36)) {
        if (*(unsigned char*)((char*)v2 + 2) == (unsigned char)a2)
            result = *(int*)((char*)v2 + 24);
    }
    return result;
}

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
MATCH_FUNC(0x5D6120)
void S5D6120::Get_5D6120(unsigned short* a, unsigned short* b)
{
    *a = *(unsigned short*)((char*)this + 0x122);
    *b = *(unsigned short*)((char*)this + 0x124);
}

class S5DCC30 {
public:
    char pad_00[0x2c];
    void Init_5DCC30();
};
MATCH_FUNC(0x5DCC30)
void S5DCC30::Init_5DCC30()
{
    int zero = 0;
    *(int*)((char*)this + 0x2c) = zero;
    *(int*)((char*)this + 0x30) = zero;
    *(int*)((char*)this + 0x34) = zero;
    *(int*)((char*)this + 0x38) = zero;
}

extern int g_77267c;
class S5DE800 {
public:
    void Set_5DE800(int v);
};
MATCH_FUNC(0x5DE800)
void S5DE800::Set_5DE800(int v)
{
    g_77267c = v;
}

// sub_5E3100 (VA 0x5E3100, 20 bytes) - member: forwards the byte arg to the
// pointer at +0x34 (a settings store). Null does nothing.
class S5E3100;
class T47C1F0 {
public:
    char pad_00[0x8ecd];
    unsigned char field_8ecd;
    void Other_47C1F0(int v);
};

class S5E3100 {
public:
    char pad_00[0x34];
    void* field_34;
    void M_5E3100(int v);
};

MATCH_FUNC(0x5E3100)
void S5E3100::M_5E3100(int v)
{
    if (field_34 != 0)
        ((T47C1F0*)field_34)->Other_47C1F0(v);
}

// sub_5E3120 (VA 0x5E3120, 20 bytes) - member: forwards the arg to the pointer
// at +0x34 (the companion of sub_5E3100, a different store slot).
class S5E3120;
class T47C200 {
public:
    char pad_00[0x8ecd];
    void Other_47C200(int v);
};

class S5E3120 {
public:
    char pad_00[0x34];
    void* field_34;
    void M_5E3120(int v);
};

MATCH_FUNC(0x5E3120)
void S5E3120::M_5E3120(int v)
{
    if (field_34 != 0)
        ((T47C200*)field_34)->Other_47C200(v);
}

class S5ESetBulk {
public:
    void SetInt_5E5160(int v);
};

MATCH_FUNC(0x5E5160)
void S5ESetBulk::SetInt_5E5160(int v)
{
    *(int*)((char*)this + 0x24) = v;
}

// sub_5E68A0 (VA 0x5E68A0, 20 bytes) - member: compares the dword at +0xD0
// with the argument and returns int 1/0.
class S5E68A0 {
public:
    char pad_00[0xd0];
    int field_d0;
    int M_5E68A0(int v);
};

MATCH_FUNC(0x5E68A0)
int S5E68A0::M_5E68A0(int v)
{
    return field_d0 == v;
}
class S5E68C0 {
public:
    char pad_00[0xd4];
    int Get_5E68C0(int index);
};

MATCH_FUNC(0x5E68C0)
int S5E68C0::Get_5E68C0(int index)
{
    return *(int*)((char*)this + 0xd4 + index * 4);
}

// 0x5EA290 — saturating subtraction against the count at self[70].
class S5EA290 {
public:
    char pad_00[70*4];
    unsigned count;               // self[70]

    unsigned Sub_5EA290(unsigned a2);
};

MATCH_FUNC(0x5EA290)
unsigned S5EA290::Sub_5EA290(unsigned a2)
{
    unsigned result = this->count;
    if (result < a2) {
        this->count = 0;
        return result;
    }
    result -= a2;
    this->count = result;
    return result;
}

// sub_5EA3D0 (VA 0x5EA3D0, 0x11 bytes) - member: byte at [+0x34]->+0x8ecd, or true when
// the +0x34 pointer is null.
class S5EA3D0 {
public:
    bool M_5EA3D0();
};

MATCH_FUNC(0x5EA3D0)
bool S5EA3D0::M_5EA3D0()
{
    char* p = *(char**)((char*)this + 0x34);
    if (p == 0)
        return true;
    return *(bool*)(p + 0x8ecd);
}

// sub_5EA3F0 (VA 0x5EA3F0, 0x11 bytes) - member: byte at [+0x34]->+0x8ece, or false when
// the +0x34 pointer is null.
class S5EA3F0 {
public:
    bool M_5EA3F0();
};

MATCH_FUNC(0x5EA3F0)
bool S5EA3F0::M_5EA3F0()
{
    char* p = *(char**)((char*)this + 0x34);
    if (p == 0)
        return false;
    return *(bool*)(p + 0x8ece);
}

extern void* g_664534;
extern float g_64d4bc;

class S5EB2F0 {
public:
    char pad_00[0xa8];
    float field_a8;
    float Get_5EB2F0();
};

MATCH_FUNC(0x5EB2F0)
float S5EB2F0::Get_5EB2F0()
{
    if (g_664534 == 0)
        return field_a8;
    return g_64d4bc;
}

class S5EC090 {
public:
    char pad_00[0x408];
    int** array_408;
    unsigned char Get_5EC090(int byte_index, int row_index);
};

MATCH_FUNC(0x5EC090)
unsigned char S5EC090::Get_5EC090(int byte_index, int row_index)
{
    int* row = array_408[row_index];
    return ((unsigned char*)row)[byte_index];
}

class S5EC440 {
public:
    int field_0;
    int field_4;
    int field_8;
    S5EC440* Init_5EC440(int v);
};

MATCH_FUNC(0x5EC440)
S5EC440* S5EC440::Init_5EC440(int v)
{
    field_8 = v;
    field_0 = 0;
    field_4 = 0;
    return this;
}

MATCH_FUNC(0x5EC8EE)
void M_5EC8EE()
{
}

MATCH_FUNC(0x5ED915)
int M_5ED915()
{
    return 0xad90;
}

extern unsigned char g_62ebf8;
MATCH_FUNC(0x5EDCB0)
bool Check_5EDCB0()
{
    return g_62ebf8 == 0xc;
}

MATCH_FUNC(0x5EE460)
void Clear_5EE460(int* p)
{
    int zero = 0;
    p[0] = zero;
    p[1] = zero;
    *(int*)((char*)p + 0x2c) = zero;
    *(int*)((char*)p + 0x28) = zero;
    *(int*)((char*)p + 0x24) = zero;
    *(int*)((char*)p + 0x20) = zero;
    p[2] = zero;
}
