// free_sim — sim-region free functions migrated from Source/simple.
// Sections keep per-file order; preambles are carried only when the file's
// first marker lives in another module.
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
void sub_5CFAF0();

// 0x5CFAE0 — tail-call forwarder to the three-global init.
MATCH_FUNC(0x5CFAE0)
void sub_5CFAE0()
{
    sub_5CFAF0();
}

MATCH_FUNC(0x5CFAF0)
void Init_5CFAF0()
{
    *(volatile float*)&g_7715f0 = 0.0f;
    *(volatile float*)&g_7715f4 = 0.0f;
    *(volatile float*)&g_7715f8 = 0.0f;
}

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





MATCH_FUNC(0x569C70)
void M_569C70()
{
}




class S4060A0 {
public:
    char pad_00[8];
    int field_8;
    bool Check_4060A0();
};

class S40F4A0 {
public:
    char pad_00[0xea4];
    int field_ea4;
    bool Check_40F4A0();
};

class S40F4B0 {
public:
    char pad_00[0xea4];
    int field_ea4;
    bool Check_40F4B0();
};

class S419810 {
public:
    char pad_00[0x180];
    int field_180;
    bool Check_419810();
};

class S42D210 {
public:
    char pad_00[0x1e38];
    int field_1e38;
    bool Check_42D210();
};

class S431740 {
public:
    char pad_00[0x17e4];
    int field_17e4;
    bool Check_431740();
};

class S431750 {
public:
    char pad_00[0x1a50];
    int field_1a50;
    bool Check_431750();
};

class S5D17D0 {
public:
    char pad_00[0x10];
    bool field_10;
    bool Check_5D17D0();
};

extern unsigned char g_62ebf8;


extern int* g_741f68;
MATCH_FUNC(0x5542C0)
int Check_5542C0(int value)
{
    return *(unsigned char*)((char*)g_741f68 + 0x155) == value;
}

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

class S5CF950 {
public:
    char pad_00[0x28a];
    int Set_5CF950(int x, int y);
};
MATCH_FUNC(0x5CF950)
int S5CF950::Set_5CF950(int x, int y)
{
    if (x < 1 || x >= 9 || y < 1 || y > 5)
        return 0;
    *(unsigned char*)((char*)this + 0x28a + x) = (unsigned char)y;
    return 1;
}

class S5C1360 {
public:
    char pad_00[0x4ccc];
    int field_4ccc;
    int Set_5C1360(int value);
};
MATCH_FUNC(0x5C1360)
int S5C1360::Set_5C1360(int value)
{
    int result = value;
    if (result < 0)
        result = 0;
    else if (result > 1)
        result = 1;
    return field_4ccc = result;
}

class S5C1410 {
public:
    char pad_00[0x4cd4];
    int field_4cd4;
    int Set_5C1410(int value);
};

class S4BF6B0 {
public:
    void Set_4BF6B0(int* out);
};

class S5A3810 {
public:
    char pad_00[0x40];
    void Sub_5A3810(int index, float value);
};
MATCH_FUNC(0x5A3810)
void S5A3810::Sub_5A3810(int index, float value)
{
    unsigned idx = index & 0xff;
    float* p = (float*)((char*)this + 0x40 + idx * 4);
    *p -= value;
}

class S5A3760 {
public:
    char pad_00[0x40];
    void Add_5A3760(int index, float value);
};
MATCH_FUNC(0x5A3760)
void S5A3760::Add_5A3760(int index, float value)
{
    unsigned idx = index & 0xff;
    float* p = (float*)((char*)this + 0x40 + idx * 4);
    float t = value;
    t += *p;
    *p = t;
}

class T567BC0 {
public:
    int Get_567BC0(int index);
};
class S56ABD0 {
public:
    char pad_00[0x1658];
    void Wrap_56ABD0(int arg);
};

class T567BD0 {
public:
    int Get_567BD0(int index);
};
class S56ABF0 {
public:
    char pad_00[0x1658];
    void Wrap_56ABF0(int arg);
};

class T579640 {
public:
    int Get_579640(int index);
};
class S56ABB0 {
public:
    char pad_00[0x40e4];
    void Wrap_56ABB0(int arg);
};

class T579600 {
public:
    int Get_579600(int index);
};
class S56BC40 {
public:
    char pad_00[0x40e4];
    void Wrap_56BC40(int arg);
};
MATCH_FUNC(0x56BC40)
void S56BC40::Wrap_56BC40(int arg)
{
    ((T579600*)((char*)this + 0x40e4))->Get_579600(arg);
}

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
// Batch 20: verified leaf helpers written manually as class methods.
// Direct translations of Source/autopilot/auto_*.c with `self[N]` replaced by
// declared fields at the same byte offsets; arithmetic order preserved.

// 0x494DA0 fields from decompilation: self[50], self[51], self[52], self[53].
class S494DA0Body {
public:
    int* field_00;                // self[0]
    char pad_04[0xc8 - 4];
    float field_c8;               // self[50]
    float field_cc;               // self[51]
    float field_d0;               // self[52]
    float field_d4;               // self[53]

    int Compute_494DA0(float a2);
};


// 0x499BA0 — replace underscores with spaces in place; returns the terminator.
char __cdecl sub_499BA0(unsigned char* a1);


// 0x49BCA0 — merge a two-bit value into a member's flag byte.
int __stdcall sub_49BCA0(int a1, char a2);


// 0x4A9F20 — round a byte field up to a multiple of four.
class S4A9F20 {
public:
    char pad_00[20];
    char field_14;                // +20

    char Round_4A9F20();
};


// 0x4ADF40 — reset four trailing short slots to -1.
class S4ADF40 {
public:
    char pad_00[202*2];
    __int16 field_194;            // self[202], word stride
    __int16 field_196;            // self[203]
    __int16 field_198;            // self[204]
    __int16 field_19a;            // self[205]

    int Reset_4ADF40();
};


// 0x4AED50 — clear one of four dword slots by index.
class S4AED50 {
public:
    char pad_00[20*4];
    int slots[4];                 // self[20...]

    unsigned Clear_4AED50(unsigned a2);
};


// 0x4BF670 — copy four consecutive dwords into optional out params.
class S4BF670 {
public:
    char pad_00[10*4];
    int field_28;                 // self[10]
    int field_2c;                 // self[11]
    int field_30;                 // self[12]
    int field_34;                 // self[13]

    int* Copy_4BF670(int* a2, int* a3, int* a4, int* a5);
};


// 0x4E8230 — two-level live-object predicate.
class S4E8230 {
public:
    char pad_00[1152*4];
    int* field_1200;              // self[1152]

    char Check_4E8230(int a2);
};


// 0x501980 — member of vtable class C_vt625DA4: set a flag for two values.
class S501980 {
public:
    char pad_00[703*4];
    int field_afc;                // self[703]

    int Set_501980(int a2, int a3, int a4, int a5, int a6);
};

// 0x5219B0 — cluster C_cluster_520CE0. Search a singly linked node list.
class S5219B0 {
public:
    char pad_00[32*4];
    int* head;                    // self[32]

    int Find_5219B0(int a2);
};

// 0x5219E0 — same node search on the previous list head field.
class S5219E0 {
public:
    char pad_00[31*4];
    int* head;                    // self[31]

    int Find_5219E0(int a2);
};

// 0x524320 — first matching word pair in a small tag list.
class S524320 {
public:
    char pad_00[602*4];
    int* field_968;               // self[602]

    int Lookup_524320();
};

MATCH_FUNC(0x524320)
int S524320::Lookup_524320()
{
    int* v1 = this->field_968;
    if (!v1)
        return 0;
    if (*(unsigned char*)((char*)v1 + 4) != 70)
        return 0;
    __int16 v3 = *(__int16*)((char*)v1 + 290);
    int count = v3;
    int result = 0;
    if (count > 0) {
        __int16* v4 = *(__int16**)((char*)v1 + 292);
        do {
            if (*v4 == 3)
                result = v4[1];
            v4 += 2;
            --count;
        } while (count);
    }
    return result;
}

// 0x5247E0 — set or clear bit 4 of a member's byte flag.
int __stdcall sub_5247E0(int a1, int a2);

MATCH_FUNC(0x5247E0)
int __stdcall sub_5247E0(int a1, int a2)
{
    int result = a1;
    if (a1) {
        unsigned char* p = (unsigned char*)(a1 + 64);
        if (a2)
            *p &= 0xEF;
        else
            *p |= 0x10;
    }
    return result;
}

// 0x529B60 — word-indexed dword table through a member object.
class S529B60 {
public:
    char pad_00[3*4];
    int* field_0c;                // self[3]

    int Get_529B60(__int16 a2);
};

MATCH_FUNC(0x529B60)
int S529B60::Get_529B60(__int16 a2)
{
    if (a2 >= 0) {
        int* v2 = *(int**)((char*)this->field_0c + 140);
        if (a2 < *(__int16*)((char*)v2 + 64))
            return *(int*)((char*)*(int*)((char*)v2 + 68) + 4 * a2);
    }
    return 0;
}

// 0x52C430 — member of vtable class C_vt61DA40: copy three floats.
class S52C430 {
public:
    char pad_00[14*4];
    float field_38;               // self[14]
    float field_3c;               // self[15]
    float field_40;               // self[16]

    float* Copy_52C430(float* a2);
};

// 0x52C6A0 — member of vtable class C_vt61CE24: dereference a member pointer.
class S52C6A0 {
public:
    char pad_00[9*4];
    int* field_24;                // self[9]

    int Get_52C6A0();
};

// 0x531F00 — member of vtable class C_vt627428: bounded table read.
class S531F00 {
public:
    char pad_00[114*4];
    int* table[4];                // self[114...]

    int Get_531F00(int a2);
};

// 0x535E90 — member of vtable class C_vt627428: type predicate.
class S535E90 {
public:
    char pad_00[8];
    int* field_08;                // self[2]

    char Check_535E90(int a2);
};

// 0x539890 — find the Nth node at a fixed link offset, report through out.
class S539890 {
public:
    char pad_00[4];
    int* head;                    // self[1]

    char Find_539890(int a2, int* a3);
};

WIP_FUNC(0x539890)
char S539890::Find_539890(int a2, int* a3)
{
    int* v3 = this->head;
    int v4 = 1;
    if (v3) {
        while (v4 != a2) {
            v3 = *(int**)((char*)v3 + 24);
            ++v4;
            if (!v3) {
                *a3 = 0;
                return 0;
            }
        }
        *a3 = (int)v3;
        return 1;
    }
    *a3 = 0;
    return 0;
}

// 0x5398D0 — find a node by its key at offset 4, report through out.
class S5398D0 {
public:
    char pad_00[4];
    int* head;                    // self[1]

    char Find_5398D0(int a2, int* a3);
};

WIP_FUNC(0x5398D0)
char S5398D0::Find_5398D0(int a2, int* a3)
{
    int* v3 = this->head;
    if (v3) {
        while (*(int*)((char*)v3 + 4) != a2) {
            v3 = *(int**)((char*)v3 + 24);
            if (!v3) {
                *a3 = 0;
                return 0;
            }
        }
        *a3 = (int)v3;
        return 1;
    }
    *a3 = 0;
    return 0;
}

// 0x540BE0 — choose between a fallback and a table value using a signed index.
class S540BE0 {
public:
    char pad_00[8];
    int* field_08;                // self[2]

    int Get_540BE0();
};

MATCH_FUNC(0x540BE0)
int S540BE0::Get_540BE0()
{
    int* v1 = this->field_08;
    int* v2 = *(int**)((char*)v1 + 8);
    int v3 = *(int*)((char*)v2 + 428);
    if (v3 >= 0) {
        int* v4 = *(int**)((char*)*(int**)((char*)v1 + 12) + 140);
        int* v5 = *(int**)((char*)v4 + 68);
        return *(int*)((char*)v5 + 4 * v3);
    }
    return *(int*)((char*)v2 + 200);
}

// 0x54BDB0 — speed value with a zero-guarded fallback.
class S54BDB0 {
public:
    char pad_00[8];
    int* object;                  // self[2]
    char pad_0c[48 - 8 - 4];
    int* field_30;                // self[12]

    int Get_54BDB0();
};

WIP_FUNC(0x54BDB0)
int S54BDB0::Get_54BDB0()
{
    if (*(float*)((char*)this->object + 68) <= 0.0f)
        return *(int*)((char*)*(int**)((volatile char*)this + 48) + 52);
    int result = *(int*)((char*)*(int**)((volatile char*)this + 48) + 64);
    if (!result)
        return *(int*)((char*)*(int**)((volatile char*)this + 48) + 52);
    return result;
}

// 0x54BDE0 — same value choice through the object's own member.
class S54BDE0 {
public:
    char pad_00[8];
    int* object;                  // self[2]
    char pad_0c[48 - 8 - 4];
    int* field_30;                // self[12]

    int Get_54BDE0();
};

MATCH_FUNC(0x54BDE0)
int S54BDE0::Get_54BDE0()
{
    int* v1 = this->object;
    int* v2 = this->field_30;
    if (*(float*)((char*)v1 + 68) > 0.0f) {
        int result = *(int*)((char*)v2 + 64);
        if (result)
            return result;
    }
    return *(int*)((char*)*(int*)((char*)v1 + 8) + 24);
}

// 0x55F910 — lazily cache a value from a global-ish chain, field at 171.
class S55F910 {
public:
    char pad_00[64*4];
    int* base;                    // self[64]
    char pad_104[171*4 - 64*4 - 4];
    int field_2ac;                // self[171]

    int Get_55F910();
};

MATCH_FUNC(0x55F910)
int S55F910::Get_55F910()
{
    if (this->field_2ac == -1)
        this->field_2ac = *(int*)((char*)*(int*)((char*)*(int*)((char*)*(int*)((char*)this->base + 21112) + 140) + 52) + 8);
    return this->field_2ac;
}

// 0x55F940 — same lazy cache for the second chain value.
class S55F940 {
public:
    char pad_00[64*4];
    int* base;                    // self[64]
    char pad_104[172*4 - 64*4 - 4];
    int field_2b0;                // self[172]

    int Get_55F940();
};

MATCH_FUNC(0x55F940)
int S55F940::Get_55F940()
{
    if (this->field_2b0 == -1)
        this->field_2b0 = *(int*)((char*)*(int*)((char*)*(int*)((char*)*(int*)((char*)this->base + 21112) + 140) + 52) + 12);
    return this->field_2b0;
}

// 0x5716A0 — 20-entry bounded dword table.
class S5716A0 {
public:
    char pad_00[79*4];
    int values[20];               // self[79...]

    int Get_5716A0(int a2);
};

MATCH_FUNC(0x5716A0)
int S5716A0::Get_5716A0(int a2)
{
    if (a2 >= 0 && a2 < 0x14)
        return this->values[a2];
    return -1;
}

// 0x5716C0 — append into the same 20-entry table, bounded by its count.
class S5716C0 {
public:
    char pad_00[78*4];
    int count;                    // self[78]
    int values[20];               // self[79...]

    int Add_5716C0(int a2);
};

MATCH_FUNC(0x5716C0)
int S5716C0::Add_5716C0(int a2)
{
    int v2 = this->count;
    if (v2 < 19) {
        this->values[v2] = a2;
        ++this->count;
        return 1;
    }
    return 0;
}
// Batch 21: verified leaf helpers written manually as class methods.
// Direct translations of Source/autopilot/auto_*.c with declared fields at the
// same byte offsets. A catalog size that disagrees with the decompiled body is
// called out in the comment for that function.

// 0x579640 — 239-entry bounded dword table.
class S579640 {
public:
    char pad_00[106*4];
    int values[239];              // self[106...]

    int Get_579640(int a2);
};

MATCH_FUNC(0x579640)
int S579640::Get_579640(int a2)
{
    if (a2 < 0 || a2 >= 0xEF)
        return -1;
    return this->values[a2];
}

// 0x580AF0 — scan up to 50 records of stride 6 dwords for a match.
class S580AF0 {
public:
    char pad_00[345*4];
    int records[50 * 6];          // self[345...]

    int Contains_580AF0(int a2);
};

WIP_FUNC(0x580AF0)
int S580AF0::Contains_580AF0(int a2)
{
    int v2 = 0;
    int* i = (int*)this + 345;
    for (; *i != a2; i += 6) {
        ++v2;
        if (v2 == 50)
            return 0;
    }
    return 1;
}

// 0x580E50 — four-entry bounded table at self[826].
class S580E50 {
public:
    char pad_00[826*4];
    int values[4];                // self[826...]

    int Get_580E50(int a2);
};

MATCH_FUNC(0x580E50)
int S580E50::Get_580E50(int a2)
{
    if (a2 < 0 || a2 > 3)
        return -1;
    return this->values[a2];
}

// 0x5812E0 — sum a record field over a linked list matching tag 100.
class S5812E0 {
public:
    char pad_00[647*4];
    int sentinel_next;            // address self+647 is the loop sentinel
    char pad_a1c[661*4 - 647*4 - 4];
    int* head;                    // self[661]

    int Sum_5812E0();
};

MATCH_FUNC(0x5812E0)
int S5812E0::Sum_5812E0()
{
    int* v1 = this->head;
    int* v2 = (int*)this + 647;
    int result;
    for (result = 0; v1 != v2; v1 = *(int**)((char*)v1 + 56)) {
        if (!v1)
            break;
        if (*(int*)((char*)v1 + 72) == 100)
            result += *(int*)((char*)v1 + 240);
    }
    return result;
}

// 0x581310 — same sum for tag 102.
class S581310 {
public:
    char pad_00[647*4];
    int sentinel_next;            // address self+647
    char pad_a1c[661*4 - 647*4 - 4];
    int* head;                    // self[661]

    int Sum_581310();
};

MATCH_FUNC(0x581310)
int S581310::Sum_581310()
{
    int* v1 = this->head;
    int* v2 = (int*)this + 647;
    int result;
    for (result = 0; v1 != v2; v1 = *(int**)((char*)v1 + 56)) {
        if (!v1)
            break;
        if (*(int*)((char*)v1 + 72) == 102)
            result += *(int*)((char*)v1 + 240);
    }
    return result;
}

// 0x583670 — search the same list for tag 108 and a matching value field.
class S583670 {
public:
    char pad_00[647*4];
    int sentinel_next;            // address self+647
    char pad_a1c[661*4 - 647*4 - 4];
    int* head;                    // self[661]

    char Contains_583670(int a2);
};

MATCH_FUNC(0x583670)
char S583670::Contains_583670(int a2)
{
    int* v2 = this->head;
    int* v3 = (int*)this + 647;
    while (v2 != v3 && v2) {
        if (*(int*)((char*)v2 + 72) == 108 &&
            *(int*)((char*)v2 + 252) == a2)
            return 1;
        v2 = *(int**)((char*)v2 + 56);
    }
    return 0;
}

// 0x5955C0 — first element of an optional array behind byte flag +32.
int __stdcall sub_5955C0(char* a1);

MATCH_FUNC(0x5955C0)
int __stdcall sub_5955C0(char* a1)
{
    int result = -1;
    if (!a1)
        return result;
    if (*(unsigned char*)(a1 + 32) > 0)
        result = **(int**)(a1 + 36);
    return result;
}

// 0x5955E0 — same pattern with byte flag +24 and array +28.
int __stdcall sub_5955E0(char* a1);

MATCH_FUNC(0x5955E0)
int __stdcall sub_5955E0(char* a1)
{
    int result = -1;
    if (!a1)
        return result;
    if (*(unsigned char*)(a1 + 24) > 0)
        result = **(int**)(a1 + 28);
    return result;
}

// 0x59ABF0 — small category predicate over a byte tag.
char __stdcall sub_59ABF0(char a1);

MATCH_FUNC(0x59ABF0)
char __stdcall sub_59ABF0(char a1)
{
    if (a1 == 1)
        return a1;
    if (a1 == 22)
        return 1;
    if (a1 == 4)
        return 1;
    if (a1 == 23)
        return 1;
    char result = (a1 == 26);
    return result;
}

// 0x5A5AD0 — sum signed floats from three word-tagged slots.
class S5A5AD0 {
public:
    char pad_00[29*4];
    int* records;                 // self[29]

    double Sum_5A5AD0(int a2);
};

MATCH_FUNC(0x5A5AD0)
double S5A5AD0::Sum_5A5AD0(int a2)
{
    float result = 0.0;
    int* v3 = *(int**)((char*)this->records + 4 * a2);
    if (v3) {
        float* v4 = (float*)((char*)v3 + 120);
        __int16* v5 = (__int16*)((char*)v3 + 114);
        int v6 = 3;
        do {
            if (*v5 == 4)
                result = result - *v4;
            ++v5;
            ++v4;
            --v6;
        } while (v6);
    }
    return result;
}

// 0x5A67D0 — branch between two cached values and stores a flag.
class S5A67D0 {
public:
    char pad_00[188*4];
    int field_2f0;                // self[188]
    char pad_2f4[384*4 - 188*4 - 4];
    int field_600;                // self[384]
    char pad_604[390*4 - 384*4 - 4];
    int field_618;                // self[390]
    char pad_61c[392*4 - 390*4 - 4];
    int field_620;                // self[392]

    int Switch_5A67D0(int a2);
};

MATCH_FUNC(0x5A67D0)
int S5A67D0::Switch_5A67D0(int a2)
{
    int result = a2;
    if (a2) {
        result = this->field_620;
        this->field_618 = 1;
        this->field_2f0 = result;
    } else {
        int v3 = this->field_600;
        this->field_618 = 0;
        this->field_2f0 = v3;
    }
    return result;
}

// 0x5BB000 — store a byte in one of two parallel byte arrays.
class S5BB000 {
public:
    char pad_00[4636];
    char values[2];               // self[4636...]

    int Set_5BB000(int a2, int a3);
};

// 0x5BDBF0 — store a dword indexed through a byte-row pointer table.
class S5BDBF0 {
public:
    int** table;                  // self[0]
    int count;                    // self[1]
    char pad_08[4];
    int field_0c[0x100];          // self[3...]

    char Set_5BDBF0(int a2, int a3);
};

MATCH_FUNC(0x5BDBF0)
char S5BDBF0::Set_5BDBF0(int a2, int a3)
{
    int* row = this->table[this->count];
    if (!*(unsigned char*)((char*)row + a2))
        return 0;
    this->field_0c[a2] = a3;
    return 1;
}

// 0x5C14E0 — 16x16 bounded table, row-major.
class S5C14E0 {
public:
    char pad_00[4643 * 4];
    int values[0x100];            // base self[4643]

    int Get_5C14E0(int a2, int a3);
};

MATCH_FUNC(0x5C14E0)
int S5C14E0::Get_5C14E0(int a2, int a3)
{
    if (a2 < 0 || a2 >= 0x10 || a3 < 0 || a3 >= 0x10)
        return -1;
    else
        return this->values[16 * a2 + a3];
}

class S464D90 {
public:
    int field_0;
    int field_4;
    bool Set_464D90(int value);
};

class S473AA0 {
public:
    char pad_00[0x24];
    unsigned char field_24;
    void Set_473AA0(unsigned char value);
};

class S4AF4B0 {
public:
    char pad_00[0xf8];
    void Set_4AF4B0(short index, int a, int b);
};

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

class S4CE570 {
public:
    char pad_00[0x1970];
    void Set_4CE570(int index, int value);
};

class S4CE590 {
public:
    char pad_00[0x19b0];
    void Set_4CE590(int index, int value);
};

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

extern unsigned char g_75fdc4;

extern int g_66e3fc;

class S52BC00 {
public:
    S52BC00* Init_52BC00();
};
MATCH_FUNC(0x52BC00)
S52BC00* S52BC00::Init_52BC00()
{
    *(int*)((char*)this) = 0;
    return this;
}

extern int g_740b54[];
MATCH_FUNC(0x54F1C0)
void Set_54F1C0(int index, int value)
{
    if (index >= 1 && index <= 0x100)
        g_740b54[index] = value;
}

extern int g_741b58[];
MATCH_FUNC(0x54F1E0)
void Set_54F1E0(int index)
{
    if (index >= 0 && index < 0x100)
        g_741b58[index] = 1;
}

extern int g_741758[];
MATCH_FUNC(0x54DDE0)
void Zero_54DDE0(int unused, int index)
{
    if (index >= 0 && index < 0x100)
        g_741758[index] = 0;
}

class S48B530 {
public:
    char pad_00[0xc4];
    void Init_48B530();
};

class S410410 {
public:
    char pad_00[0xea4];
    int field_ea4;
    int array_ea8[0x100];
    int field_1e0;
    void Pop_410410();
};

class S493780 {
public:
    int count;
    char pad_04[8];
    int* array_0c;
    void Reset_493780();
};

class S522E10Node {
public:
    S522E10Node* next_0;
    S522E10Node* prev_4;
};

class S522E10 {
public:
    char pad_00[0x10];
    S522E10Node* head_10;
    char pad_14[0xc];
    int count_20;
    void Add_522E10(S522E10Node* node);
};
MATCH_FUNC(0x522E10)
void S522E10::Add_522E10(S522E10Node* node)
{
    node->next_0 = head_10;
    node->prev_4 = 0;
    head_10 = node;
    ++count_20;
}

class S410680 {
public:
    S410680* Init_410680();
};

class S4373F0 {
public:
    S4373F0* Init_4373F0();
};

class S465B10 {
public:
    S465B10* Init_465B10();
};

class S5B0800 {
public:
    S5B0800* Init_5B0800();
};
MATCH_FUNC(0x5B0800)
S5B0800* S5B0800::Init_5B0800()
{
    int negative = -1;
    *(int*)((char*)this + 4) = negative;
    *(int*)((char*)this + 8) = negative;
    *(int*)((char*)this + 0xc) = negative;
    *(unsigned char*)((char*)this) = 0xff;
    *(int*)((char*)this + 0x10) = 0xbf800000;
    *(int*)((char*)this + 0x14) = 0xbf800000;
    *(int*)((char*)this + 0x18) = 0xbf800000;
    return this;
}

class S5B0820 {
public:
    char pad_00[1];
    S5B0820* Init_5B0820(char* src);
};
MATCH_FUNC(0x5B0820)
S5B0820* S5B0820::Init_5B0820(char* src)
{
    int negative = -1;
    *(int*)((char*)this + 4) = negative;
    *(int*)((char*)this + 8) = negative;
    *(int*)((char*)this + 0xc) = negative;
    *(int*)((char*)this + 0x10) = 0xbf800000;
    *(int*)((char*)this + 0x14) = 0xbf800000;
    *(int*)((char*)this + 0x18) = 0xbf800000;
    *(unsigned char*)((char*)this) = 0xff;
    *(unsigned char*)((char*)this) = *(unsigned char*)src;
    *(int*)((char*)this + 4) = *(int*)(src + 4);
    *(int*)((char*)this + 0xc) = *(int*)(src + 0xc);
    *(int*)((char*)this + 0x10) = *(int*)(src + 0x10);
    *(int*)((char*)this + 0x14) = *(int*)(src + 0x14);
    *(int*)((char*)this + 0x18) = *(int*)(src + 0x18);
    return this;
}

class S5B0870 {
public:
    S5B0870* Init_5B0870();
};
MATCH_FUNC(0x5B0870)
S5B0870* S5B0870::Init_5B0870()
{
    int zero = 0;
    *(int*)((char*)this) = zero;
    *(int*)((char*)this + 4) = -1;
    *(int*)((char*)this + 8) = zero;
    *(int*)((char*)this + 0xc) = zero;
    *(int*)((char*)this + 0x10) = zero;
    *(unsigned char*)((char*)this + 0x14) = zero;
    *(unsigned char*)((char*)this + 0x15) = zero;
    *(int*)((char*)this + 0x18) = zero;
    *(int*)((char*)this + 0x1c) = zero;
    *(int*)((char*)this + 0x20) = zero;
    *(int*)((char*)this + 0x24) = zero;
    *(int*)((char*)this + 0x28) = zero;
    *(int*)((char*)this + 0x2c) = zero;
    *(int*)((char*)this + 0x30) = zero;
    *(int*)((char*)this + 0x34) = zero;
    *(int*)((char*)this + 0x38) = zero;
    *(int*)((char*)this + 0x3c) = zero;
    *(int*)((char*)this + 0x74) = zero;
    *(int*)((char*)this + 0xac) = zero;
    *(unsigned char*)((char*)this + 0x40) = zero;
    *(unsigned char*)((char*)this + 0x78) = zero;
    return this;
}

class S423A70 {
public:
    int field_0;
    int field_4;
    int field_8;
    char pad_0c[0x14 - 0x0c];
    unsigned char field_14;
    char pad_15[0x1c - 0x15];
    int field_1c;
    char pad_20[0x420 - 0x20];
    unsigned char field_420;
    char pad_421[0x524 - 0x421];
    int field_524;
    int field_528;
    int field_52c;
    int field_530;
    char pad_534[0x53c - 0x534];
    int field_53c;
    int field_540;
    char pad_544[0x548 - 0x544];
    int field_548;
    S423A70* Init_423A70();
};

class S469570 {
public:
    S469570* Init_469570();
};

// Inlined-constructor shape: returns this.
class S595DF0 {
public:
    int vtbl_0;
    S595DF0* owner_4;
    int field_8;
    short field_c;
    short field_e;
    float field_10;
    S595DF0* Init_595DF0(S595DF0* owner);
};
MATCH_FUNC(0x595DF0)
S595DF0* S595DF0::Init_595DF0(S595DF0* owner)
{
    owner_4 = owner;
    vtbl_0 = 0x62b024;
    field_8 = 0;
    field_c = 0;
    field_e = 0;
    field_10 = -1.0f;
    return this;
}

class S407BD0 {
public:
    bool M_407BD0(int unused);
};



class S411C20 {
public:
    int M_411C20(int unused);
};

class S415750 {
public:
    int M_415750(int unused);
};

class S41AF90 {
public:
    bool M_41AF90(int unused);
};

class S41BC30 {
public:
    int M_41BC30(int a, int b, int c, int d, int e, int f);
};

class S41BC40 {
public:
    int M_41BC40(int a, int b, int c, int d, int e);
};

class S41BC50 {
public:
    int M_41BC50(int a, int b);
};

class S4FA920 {
public:
    int M_4FA920(int a, int b);
};

class S589AE0 {
public:
    int M_589AE0(int unused);
};

class S5A4A60 {
public:
    int M_5A4A60(int a, int b, int c, int d, int e);
};
MATCH_FUNC(0x5A4A60)
int S5A4A60::M_5A4A60(int a, int b, int c, int d, int e)
{
    return 1;
}





class S43FAB0 {
public:
    S43FAB0* Self_43FAB0();
};

class S4CEAE0 {
public:
    char pad_00[0x13dc];
    char Get_4CEAE0(int index);
};

class S412BC0 {
public:
    char pad_00[4];
    int* field_4;
    int Get_412BC0();
};

class S421FB0 {
public:
    char pad_00[0x24];
    int* field_24;
    int Get_421FB0();
};

class S53F060 {
public:
    char pad_00[8];
    int* field_8;
    int Get_53F060();
};
MATCH_FUNC(0x53F060)
int S53F060::Get_53F060()
{
    int* p = *(int**)((char*)field_8 + 8);
    return *(int*)((char*)p + 0x11c);
}

class S540BD0 {
public:
    char pad_00[8];
    int* field_8;
    int Get_540BD0();
};
MATCH_FUNC(0x540BD0)
int S540BD0::Get_540BD0()
{
    int* p = *(int**)((char*)field_8 + 8);
    return *(int*)((char*)p + 0xc8);
}

class S5477D0 {
public:
    char pad_00[0x30];
    int* field_30;
    int Get_5477D0();
};
MATCH_FUNC(0x5477D0)
int S5477D0::Get_5477D0()
{
    return *(int*)((char*)field_30 + 0x34);
}

class S408BC0 {
public:
    char pad_00[8];
    float* field_8;
    float Get_408BC0();
};

class S436B40 {
public:
    char pad_00[8];
    float* field_8;
    float Get_436B40();
};

class S436C50 {
public:
    char pad_00[8];
    float* field_8;
    float Get_436C50();
};

class S436C60 {
public:
    char pad_00[8];
    float* field_8;
    float Get_436C60();
};

class S52C610 {
public:
    char pad_00[8];
    float* field_8;
    float Get_52C610();
};

extern int g_665340;

extern int g_741f90;
MATCH_FUNC(0x5542B0)
int Get_5542B0()
{
    return g_741f90;
}

extern int g_741f78;
MATCH_FUNC(0x5546C0)
int Get_5546C0()
{
    return g_741f78;
}

extern int g_741f7c;
MATCH_FUNC(0x5561B0)
int Get_5561B0()
{
    return g_741f7c;
}

class S5549A0Global {
public:
    char pad_00[0x2064];
    int field_2064;
};

extern S5549A0Global* g_741f60;
MATCH_FUNC(0x5562D0)
int Get_5562D0()
{
    return *(int*)((char*)g_741f60 + 0x1320);
}

extern int* g_741f5c;
MATCH_FUNC(0x5566F0)
int Get_5566F0()
{
    return *(int*)((char*)g_741f5c + 0x1074);
}

extern int g_741b58[];
MATCH_FUNC(0x55A0C0)
int Get_55A0C0(int index)
{
    return g_741b58[index];
}

class S424BC0 {
public:
    int field_0;
    int field_4;
    S424BC0* Init_424BC0(int v);
};


class S4260C0 {
public:
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    S4260C0* Clear_4260C0();
};


class S5B08F0 {
public:
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    S5B08F0* Fill_5B08F0();
};

MATCH_FUNC(0x5B08F0)
S5B08F0* S5B08F0::Fill_5B08F0()
{
    field_0 = -1;
    field_4 = -1;
    field_8 = -1;
    field_c = -1;
    field_10 = -1;
    return this;
}

class S52ADSub {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual void Vt_6();
    virtual void Vat_1c(int a, int b);
};

class S52ADE0 {
public:
    char pad_00[0x10];
    int field_10;
    char pad_14[0x18 - 0x14];
    S52ADSub* field_18;
    void Call_52ADE0(int v);
};

MATCH_FUNC(0x52ADE0)
void S52ADE0::Call_52ADE0(int v)
{
    if (field_10 != 0 && field_18 != 0)
        field_18->Vat_1c(field_10, v);
}

class S52SetImmBulk {
public:
    void Set_520500();
    void Set_52C120();
};

MATCH_FUNC(0x520500)
void S52SetImmBulk::Set_520500()
{
    *(int*)((char*)this + 0x79c) = 0x0;
}

class S52SetBulk {
public:
    void SetInt_520F50(int v);
    void SetByte_52BC90(unsigned char v);
};

MATCH_FUNC(0x520F50)
void S52SetBulk::SetInt_520F50(int v)
{
    *(int*)((char*)this + 0x70) = v;
}

class S54SetBulk {
public:
    void SetInt_548110(int v);
    void SetByte_54ADD0(unsigned char v);
    void SetInt_54FE60(int v);
};

MATCH_FUNC(0x548110)
void S54SetBulk::SetInt_548110(int v)
{
    *(int*)((char*)this + 0x40) = v;
}

MATCH_FUNC(0x54FE60)
void S54SetBulk::SetInt_54FE60(int v)
{
    *(int*)((char*)this + 0x5c0) = v;
}

class S55SetBulk {
public:
    void SetInt_550990(int v);
    void SetInt_55D910(int v);
};

MATCH_FUNC(0x550990)
void S55SetBulk::SetInt_550990(int v)
{
    *(int*)((char*)this + 0x314) = v;
}

MATCH_FUNC(0x55D910)
void S55SetBulk::SetInt_55D910(int v)
{
    *(int*)((char*)this + 0x100) = v;
}

class S56GetBulk {
public:
    char* Get_56F2D0();
};

MATCH_FUNC(0x56F2D0)
char* S56GetBulk::Get_56F2D0()
{
    return (char*)this + 0xf8;
}

class S56SetBulk {
public:
    void SetInt_565B70(int v);
};

MATCH_FUNC(0x565B70)
void S56SetBulk::SetInt_565B70(int v)
{
    *(int*)((char*)this + 0xf80) = v;
}

class S57GetBulk {
public:
    int Get_579580();
    int Get_579590();
    int Get_5795A0();
    int Get_5795B0();
    int Get_5795C0();
    int Get_5795D0();
    int Get_5795F0();
};

MATCH_FUNC(0x579580)
int S57GetBulk::Get_579580()
{
    return *(int*)((char*)this + 0xfc);
}

MATCH_FUNC(0x579590)
int S57GetBulk::Get_579590()
{
    return *(int*)((char*)this + 0x10c);
}

MATCH_FUNC(0x5795A0)
int S57GetBulk::Get_5795A0()
{
    return *(int*)((char*)this + 0xa14);
}

MATCH_FUNC(0x5795B0)
int S57GetBulk::Get_5795B0()
{
    return *(int*)((char*)this + 0x110);
}

MATCH_FUNC(0x5795C0)
int S57GetBulk::Get_5795C0()
{
    return *(int*)((char*)this + 0xa18);
}

MATCH_FUNC(0x5795D0)
int S57GetBulk::Get_5795D0()
{
    return *(int*)((char*)this + 0x11c);
}

MATCH_FUNC(0x5795F0)
int S57GetBulk::Get_5795F0()
{
    return *(int*)((char*)this + 0x14c);
}

class S57SetBulk {
public:
    void SetInt_573F50(int v);
};

MATCH_FUNC(0x573F50)
void S57SetBulk::SetInt_573F50(int v)
{
    *(int*)((char*)this + 0xf4) = v;
}

class S58GetBulk {
public:
    int Get_580B20(int unused);
    int Get_58A800();
};

MATCH_FUNC(0x580B20)
int S58GetBulk::Get_580B20(int unused)
{
    return *(int*)((char*)this + 0x3f8);
}

MATCH_FUNC(0x58A800)
int S58GetBulk::Get_58A800()
{
    return *(int*)((char*)this + 0x194);
}

class S58SetBulk {
public:
    void SetInt_58A7F0(int v);
};

MATCH_FUNC(0x58A7F0)
void S58SetBulk::SetInt_58A7F0(int v)
{
    *(int*)((char*)this + 0x194) = v;
}

class S5A4800 {
public:
    char pad_00[0x16cf];
    unsigned char array_16cf[0x40];
    unsigned char array_16d8[0x40];
    void SetA_5A4800(short index, unsigned char v);
    void SetB_5A4820(short index, unsigned char v);
};

MATCH_FUNC(0x5A4800)
void S5A4800::SetA_5A4800(short index, unsigned char v)
{
    ((unsigned char*)this)[0x16cf + index] = v;
}

MATCH_FUNC(0x5A4820)
void S5A4800::SetB_5A4820(short index, unsigned char v)
{
    ((unsigned char*)this)[0x16d8 + index] = v;
}

// Family 0x5AE440/70/A0/D0: four setters writing three consecutive dwords in the
// block at +0x100 (+0x10c, +0x118, +0x124), each then calling virtual slot 0x20
// with 1.
class S5AE440 {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual void Vt_6();
    virtual void Vt_7();
    virtual void Vat_20(int v);
    char pad_04[0x100 - 0x04];
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;

    void M_5AE440(int a, int b, int c);
    void M_5AE470(int a, int b, int c);
    void M_5AE4A0(int a, int b, int c);
    void M_5AE4D0(int a, int b, int c);
};

MATCH_FUNC(0x5AE440)
void S5AE440::M_5AE440(int a, int b, int c)
{
    f100 = a;
    f104 = b;
    f108 = c;
    Vat_20(1);
}

MATCH_FUNC(0x5AE470)
void S5AE440::M_5AE470(int a, int b, int c)
{
    f10c = a;
    f110 = b;
    f114 = c;
    Vat_20(1);
}

MATCH_FUNC(0x5AE4A0)
void S5AE440::M_5AE4A0(int a, int b, int c)
{
    f118 = a;
    f11c = b;
    f120 = c;
    Vat_20(1);
}

MATCH_FUNC(0x5AE4D0)
void S5AE440::M_5AE4D0(int a, int b, int c)
{
    f124 = a;
    f128 = b;
    f12c = c;
    Vat_20(1);
}

class S5AE500 {
public:
    char pad_00[0x16c];
    int field_16c;
    unsigned char field_170;
    void Set_5AE500(int a, unsigned char b);
};

MATCH_FUNC(0x5AE500)
void S5AE500::Set_5AE500(int a, unsigned char b)
{
    field_16c = a;
    field_170 = b;
}

class S5AGetBulk {
public:
    unsigned char Get_5A7940();
    int Get_5AC760();
};

MATCH_FUNC(0x5A7940)
unsigned char S5AGetBulk::Get_5A7940()
{
    return *(unsigned char*)((char*)this + 0x864);
}

MATCH_FUNC(0x5AC760)
int S5AGetBulk::Get_5AC760()
{
    return *(int*)((char*)this + 0x104);
}

class S5ASetImmBulk {
public:
    void Set_5A6780();
    void Set_5A6790();
    void Set_5A67A0();
};

MATCH_FUNC(0x5A6780)
void S5ASetImmBulk::Set_5A6780()
{
    *(unsigned char*)((char*)this + 0x2d4) = 0x0;
}

MATCH_FUNC(0x5A6790)
void S5ASetImmBulk::Set_5A6790()
{
    *(unsigned char*)((char*)this + 0x2d4) = 0x1;
}

MATCH_FUNC(0x5A67A0)
void S5ASetImmBulk::Set_5A67A0()
{
    *(int*)((char*)this + 0x61c) = 0x1;
}

class S5ASetBulk {
public:
    void SetInt_5AED50(int v);
    void SetInt_5AED60(int v);
};

MATCH_FUNC(0x5AED50)
void S5ASetBulk::SetInt_5AED50(int v)
{
    *(int*)((char*)this + 0x14c) = v;
}

MATCH_FUNC(0x5AED60)
void S5ASetBulk::SetInt_5AED60(int v)
{
    *(int*)((char*)this + 0x150) = v;
}

class S5BAFA0 {
public:
    char pad_00[0x11e4];
    int field_11e4;
    int field_11e8;
    unsigned char array_11ec[0xc];
    int array_11f8[0xb];
    unsigned char gap_1224;
    unsigned char array_1225[0x4c8c - 0x1225];
    int array_4c8c[(0x51d8 - 0x4c8c) / 4];
    int array_51d8[(0x51e4 - 0x51d8) / 4];
    int array_51e4[0x40];

    void Set_5BAF70(int a, int b);
    int GetId_5BAF90(int index);
    int Get_5BAFF0(int index);
    int Get_5BB030(int index);
    int Get_5BAFC0(int index);
    void SetByte_5BAFA0(int index, unsigned char v);
    void SetInt_5BAFD0(int index, int v);
    void SetByte2_5BB040(int index, unsigned char v);
    void SetInt2_5C1610(int index, int v);
    void SetInt3_5C1810(int index, int v);
    void SetInt4_5C1830(int index, int v);
};

MATCH_FUNC(0x5C1610)
void S5BAFA0::SetInt2_5C1610(int index, int v)
{
    array_4c8c[index] = v;
}

MATCH_FUNC(0x5C1810)
void S5BAFA0::SetInt3_5C1810(int index, int v)
{
    array_51d8[index] = v;
}

MATCH_FUNC(0x5C1830)
void S5BAFA0::SetInt4_5C1830(int index, int v)
{
    array_51e4[index] = v;
}

MATCH_FUNC(0x5BAF90)
int S5BAFA0::GetId_5BAF90(int index)
{
    return *(unsigned char*)((char*)this + 0x11ec + index);
}

MATCH_FUNC(0x5BAFF0)
int S5BAFA0::Get_5BAFF0(int index)
{
    return *(unsigned char*)((char*)this + 0x121c + index);
}

MATCH_FUNC(0x5BB030)
int S5BAFA0::Get_5BB030(int index)
{
    return *(unsigned char*)((char*)this + 0x1225 + index);
}

MATCH_FUNC(0x5BAFC0)
int S5BAFA0::Get_5BAFC0(int index)
{
    return array_11f8[index];
}

class S5BDBD0 {
public:
    char pad_00[4];
    int field_4;
    int field_8;
    int field_c;
    char pad_10[0x10 - 0xc - 4];
    void Init_5BDBD0();
};

MATCH_FUNC(0x5BDBD0)
void S5BDBD0::Init_5BDBD0()
{
    field_4 = 0;
    for (int i = 0; i < 0x10; ++i)
        ((int*)this)[3 + i] = -1;
}

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

class S5BEF30 {
public:
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    char pad_06[0x8 - 0x06];
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
    int field_38;
    int field_3c;
    S5BEF30* Init_5BEF30(int v);
};

MATCH_FUNC(0x5BEF30)
S5BEF30* S5BEF30::Init_5BEF30(int v)
{
    field_4 = 0;
    field_5 = 0;
    field_8 = 0;
    field_c = 0;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
    field_20 = 0;
    field_24 = 0;
    field_28 = 0;
    field_2c = 0;
    field_30 = 0;
    field_34 = 0;
    field_38 = 0;
    field_0 = 1;
    field_10 = -1;
    field_3c = v;
    return this;
}

class S5BGetBulk {
public:
    char* Get_5B42E0();
    int Get_5B4540();
    unsigned char Get_5B4560();
    unsigned char Get_5B4580();
    int Get_5BAD50();
    int Get_5BAD70();
    int Get_5BAEA0();
    char* Get_5BAEB0();
    int Get_5BAF10();
    int Get_5BAF30();
    int Get_5BAF50();
    int Get_5BAF60();
    int Get_5BB110();
    int Get_5BB120();
    unsigned char Get_5BB140();
    unsigned char Get_5BB150();
    unsigned char Get_5BB160();
    int Get_5BC9B0();
    unsigned char Get_5BCA00();
};

MATCH_FUNC(0x5B42E0)
char* S5BGetBulk::Get_5B42E0()
{
    return (char*)this + 0x17b0;
}

MATCH_FUNC(0x5B4560)
unsigned char S5BGetBulk::Get_5B4560()
{
    return *(unsigned char*)((char*)this + 0x145c);
}

MATCH_FUNC(0x5B4580)
unsigned char S5BGetBulk::Get_5B4580()
{
    return *(unsigned char*)((char*)this + 0x145d);
}

MATCH_FUNC(0x5BAF10)
int S5BGetBulk::Get_5BAF10()
{
    return *(int*)((char*)this + 0x11dc);
}

MATCH_FUNC(0x5BAF30)
int S5BGetBulk::Get_5BAF30()
{
    return *(int*)((char*)this + 0x11e0);
}

MATCH_FUNC(0x5BAF50)
int S5BGetBulk::Get_5BAF50()
{
    return *(int*)((char*)this + 0x11e4);
}

MATCH_FUNC(0x5BAF60)
int S5BGetBulk::Get_5BAF60()
{
    return *(int*)((char*)this + 0x11e8);
}

MATCH_FUNC(0x5BB110)
int S5BGetBulk::Get_5BB110()
{
    return *(int*)((char*)this + 0x1234);
}

MATCH_FUNC(0x5BB120)
int S5BGetBulk::Get_5BB120()
{
    return *(int*)((char*)this + 0x1238);
}

MATCH_FUNC(0x5BB140)
unsigned char S5BGetBulk::Get_5BB140()
{
    return *(unsigned char*)((char*)this + 0x123d);
}

MATCH_FUNC(0x5BB150)
unsigned char S5BGetBulk::Get_5BB150()
{
    return *(unsigned char*)((char*)this + 0x123e);
}

MATCH_FUNC(0x5BB160)
unsigned char S5BGetBulk::Get_5BB160()
{
    return *(unsigned char*)((char*)this + 0x123f);
}

MATCH_FUNC(0x5BC9B0)
int S5BGetBulk::Get_5BC9B0()
{
    return *(int*)((char*)this + 0x10a4);
}

MATCH_FUNC(0x5BCA00)
unsigned char S5BGetBulk::Get_5BCA00()
{
    return *(unsigned char*)((char*)this + 0x1ae4);
}

class S5BSetBulk {
public:
    void SetInt_5B4530(int v);
    void SetByte_5B4550(unsigned char v);
    void SetByte_5B4570(unsigned char v);
    void SetInt_5BAD60(int v);
    void SetInt_5BAF20(int v);
    void SetInt_5BAF40(int v);
    void SetByte_5BB170(unsigned char v);
    void SetByte_5BB180(unsigned char v);
    void SetByte_5BB190(unsigned char v);
    void SetByte_5BB1A0(unsigned char v);
    void SetInt_5BB1B0(int v);
    void SetInt_5BB1C0(int v);
    void SetByte_5BB1D0(unsigned char v);
    void SetByte_5BB1E0(unsigned char v);
    void SetByte_5BB1F0(unsigned char v);
    void SetByte_5BB200(unsigned char v);
    void SetByte_5BB210(unsigned char v);
    void SetInt_5BB220(int v);
    void SetByte_5BC9F0(unsigned char v);
    void SetByte_5BFB10(unsigned char v);
    void SetInt_5BFB20(int v);
    void SetByte_5BFBA0(unsigned char v);
};

MATCH_FUNC(0x5B4570)
void S5BSetBulk::SetByte_5B4570(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x145d) = v;
}

MATCH_FUNC(0x5BC9F0)
void S5BSetBulk::SetByte_5BC9F0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1ae4) = v;
}

MATCH_FUNC(0x5BFB10)
void S5BSetBulk::SetByte_5BFB10(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x5) = v;
}

MATCH_FUNC(0x5BFB20)
void S5BSetBulk::SetInt_5BFB20(int v)
{
    *(int*)((char*)this + 0x8) = v;
}

MATCH_FUNC(0x5BFBA0)
void S5BSetBulk::SetByte_5BFBA0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x4) = v;
}

class S5C1480 {
public:
    char pad_00[0x488c];
    void Init_5C1480();
};

MATCH_FUNC(0x5C1480)
void S5C1480::Init_5C1480()
{
    for (int i = 0; i < 0x100; ++i)
        ((int*)this)[(0x488c / 4) + i] = 3;
}

class S5CGetBulk {
public:
    int Get_5C1390();
    int Get_5C13C0();
    int Get_5C13E0();
    int Get_5C1400();
    int Get_5C19D0();
    int Get_5C19E0();
    int Get_5C19F0();
    int Get_5C47D0();
};

MATCH_FUNC(0x5C1390)
int S5CGetBulk::Get_5C1390()
{
    return *(int*)((char*)this + 0x4ccc);
}

MATCH_FUNC(0x5C13C0)
int S5CGetBulk::Get_5C13C0()
{
    return *(int*)((char*)this + 0x5224);
}

MATCH_FUNC(0x5C13E0)
int S5CGetBulk::Get_5C13E0()
{
    return *(int*)((char*)this + 0x5228);
}

MATCH_FUNC(0x5C1400)
int S5CGetBulk::Get_5C1400()
{
    return *(int*)((char*)this + 0x522c);
}

MATCH_FUNC(0x5C19D0)
int S5CGetBulk::Get_5C19D0()
{
    return *(int*)((char*)this + 0x1b74);
}

MATCH_FUNC(0x5C19E0)
int S5CGetBulk::Get_5C19E0()
{
    return *(int*)((char*)this + 0x1b7c);
}

MATCH_FUNC(0x5C19F0)
int S5CGetBulk::Get_5C19F0()
{
    return *(int*)((char*)this + 0x1b84);
}

MATCH_FUNC(0x5C47D0)
int S5CGetBulk::Get_5C47D0()
{
    return *(int*)((char*)this + 0x170);
}

class S5CSetBulk {
public:
    void SetInt_5C13D0(int v);
    void SetInt_5C13F0(int v);
    void SetInt_5C15C0(int v);
    void SetInt_5C15D0(int v);
    void SetInt_5C15E0(int v);
    void SetInt_5C15F0(int v);
    void SetInt_5C1600(int v);
    void SetInt_5C47C0(int v);
};

MATCH_FUNC(0x5C13D0)
void S5CSetBulk::SetInt_5C13D0(int v)
{
    *(int*)((char*)this + 0x5228) = v;
}

MATCH_FUNC(0x5C13F0)
void S5CSetBulk::SetInt_5C13F0(int v)
{
    *(int*)((char*)this + 0x522c) = v;
}

MATCH_FUNC(0x5C15C0)
void S5CSetBulk::SetInt_5C15C0(int v)
{
    *(int*)((char*)this + 0x1b78) = v;
}

MATCH_FUNC(0x5C15D0)
void S5CSetBulk::SetInt_5C15D0(int v)
{
    *(int*)((char*)this + 0x1b7c) = v;
}

MATCH_FUNC(0x5C15E0)
void S5CSetBulk::SetInt_5C15E0(int v)
{
    *(int*)((char*)this + 0x1b80) = v;
}

MATCH_FUNC(0x5C15F0)
void S5CSetBulk::SetInt_5C15F0(int v)
{
    *(int*)((char*)this + 0x1b84) = v;
}

MATCH_FUNC(0x5C1600)
void S5CSetBulk::SetInt_5C1600(int v)
{
    *(int*)((char*)this + 0x1b88) = v;
}

MATCH_FUNC(0x5C47C0)
void S5CSetBulk::SetInt_5C47C0(int v)
{
    *(int*)((char*)this + 0x170) = v;
}
class S428AE0 {
public:
    char pad_00[0x13bc];
    int Get_428AE0(int index);
};
class S431CD0 {
public:
    char pad_00[0x1bf0];
    int Get_431CD0(int index);
};
class S4334F0 {
public:
    char pad_00[0x46bc];
    int Get_4334F0(int index);
};
class S4CED70 {
public:
    char pad_00[0x1010];
    int Get_4CED70(int index);
};
class S5508F0 {
public:
    char pad_00[0x5c4];
    int Get_5508F0(int index);
};
class S567BC0 {
public:
    char pad_00[0x1ff4];
    int Get_567BC0(int index);
};
class S567BD0 {
public:
    char pad_00[0x2014];
    int Get_567BD0(int index);
};
class S567BE0 {
public:
    char pad_00[0x2034];
    int Get_567BE0(int index);
};
class S5C1A20 {
public:
    char pad_00[0x4c8c];
    int Get_5C1A20(int index);
};
class S5C1A30 {
public:
    char pad_00[0x51d8];
    int Get_5C1A30(int index);
};
class S5C1A40 {
public:
    char pad_00[0x51e4];
    int Get_5C1A40(int index);
};
class S5E68C0 {
public:
    char pad_00[0xd4];
    int Get_5E68C0(int index);
};
MATCH_FUNC(0x5508F0)
int S5508F0::Get_5508F0(int index)
{
    return *(int*)((char*)this + 0x5c4 + index * 4);
}
MATCH_FUNC(0x567BC0)
int S567BC0::Get_567BC0(int index)
{
    return *(int*)((char*)this + 0x1ff4 + index * 4);
}
MATCH_FUNC(0x567BD0)
int S567BD0::Get_567BD0(int index)
{
    return *(int*)((char*)this + 0x2014 + index * 4);
}
MATCH_FUNC(0x567BE0)
int S567BE0::Get_567BE0(int index)
{
    return *(int*)((char*)this + 0x2034 + index * 4);
}
MATCH_FUNC(0x5C1A20)
int S5C1A20::Get_5C1A20(int index)
{
    return *(int*)((char*)this + 0x4c8c + index * 4);
}
MATCH_FUNC(0x5C1A30)
int S5C1A30::Get_5C1A30(int index)
{
    return *(int*)((char*)this + 0x51d8 + index * 4);
}
MATCH_FUNC(0x5C1A40)
int S5C1A40::Get_5C1A40(int index)
{
    return *(int*)((char*)this + 0x51e4 + index * 4);
}
class S41B660 {
public:
    char pad_00[0x23];
    char Get_41B660();
};
class S4CF6F0 {
public:
    char pad_00[0xc];
    char Get_4CF6F0();
};
class S52BC80 {
public:
    char pad_00[0x76];
    char Get_52BC80();
};
class S5BFBC0 {
public:
    char pad_00[0x5];
    char Get_5BFBC0();
};
class S5BFC00 {
public:
    char pad_00[0x4];
    char Get_5BFC00();
};
class S5E68D0 {
public:
    char pad_00[0x29];
    char Get_5E68D0();
};
class S40A140 {
public:
    char pad_00[0x68];
    int Get_40A140();
};
class S40A310 {
public:
    char pad_00[0x74];
    int Get_40A310();
};
class S40B630 {
public:
    char pad_00[0x78];
    int Get_40B630();
};
class S40B640 {
public:
    char pad_00[0x7c];
    int Get_40B640();
};
class S412BD0 {
public:
    char pad_00[0x28];
    int Get_412BD0();
};
class S412C00 {
public:
    char pad_00[0x34];
    int Get_412C00();
};
class S412C10 {
public:
    char pad_00[0x38];
    int Get_412C10();
};
class S412C20 {
public:
    char pad_00[0x5c];
    int Get_412C20();
};
class S41C8F0 {
public:
    char pad_00[0x60];
    int Get_41C8F0();
};
class S440720 {
public:
    char pad_00[0x1c];
    int Get_440720();
};
class S47D9F0 {
public:
    char pad_00[0x8];
    int Get_47D9F0();
};
class S47DA00 {
public:
    char pad_00[0xc];
    int Get_47DA00();
};
class S48F970 {
public:
    char pad_00[0x4];
    int Get_48F970();
};
class S49F620 {
public:
    char pad_00[0x10];
    int Get_49F620();
};
class S4A2060 {
public:
    char pad_00[0x1c];
    int Get_4A2060();
};
class S52BDA0 {
public:
    char pad_00[0x6c];
    int Get_52BDA0();
};
class S5BF820 {
public:
    char pad_00[0x30];
    int Get_5BF820();
};
class S5BFA50 {
public:
    char pad_00[0x2c];
    int Get_5BFA50();
};
class S5BFBF0 {
public:
    int Get_5BFBF0();
};
class S5C05A0 {
public:
    char pad_00[0x18];
    int Get_5C05A0();
};
class S5C07A0 {
public:
    char pad_00[0x14];
    int Get_5C07A0();
};
class S409F40 {
public:
    char pad_00[0x0];
    int Get_409F40();
};
class S4107E0 {
public:
    char pad_00[0xc];
    int Get_4107E0();
};
class S520400 {
public:
    char pad_00[0x4];
    int Get_520400();
};
class S5BB0D0 {
public:
    char pad_00[0x122e];
    int Get_5BB0D0();
};
class S5BB0E0 {
public:
    char pad_00[0x122f];
    int Get_5BB0E0();
};
class S5BB0F0 {
public:
    char pad_00[0x1230];
    int Get_5BB0F0();
};
class S5BB100 {
public:
    char pad_00[0x1231];
    int Get_5BB100();
};
class S5BB130 {
public:
    char pad_00[0x123c];
    int Get_5BB130();
};
MATCH_FUNC(0x5BFBC0)
char S5BFBC0::Get_5BFBC0()
{
    return *(char*)((char*)this + 0x5);
}
MATCH_FUNC(0x5BFC00)
char S5BFC00::Get_5BFC00()
{
    return *(char*)((char*)this + 0x4);
}
MATCH_FUNC(0x52BDA0)
int S52BDA0::Get_52BDA0()
{
    return *(int*)((char*)this + 0x6c);
}
MATCH_FUNC(0x5BF820)
int S5BF820::Get_5BF820()
{
    return *(int*)((char*)this + 0x30);
}
MATCH_FUNC(0x5BFA50)
int S5BFA50::Get_5BFA50()
{
    return *(int*)((char*)this + 0x2c);
}
MATCH_FUNC(0x5BFBF0)
int S5BFBF0::Get_5BFBF0()
{
    return *(int*)((char*)this + 0x0);
}
MATCH_FUNC(0x5C05A0)
int S5C05A0::Get_5C05A0()
{
    return *(int*)((char*)this + 0x18);
}
MATCH_FUNC(0x5C07A0)
int S5C07A0::Get_5C07A0()
{
    return *(int*)((char*)this + 0x14);
}
MATCH_FUNC(0x520400)
int S520400::Get_520400()
{
    return *(unsigned char*)((char*)this + 0x4);
}
MATCH_FUNC(0x5BB0D0)
int S5BB0D0::Get_5BB0D0()
{
    return *(unsigned char*)((char*)this + 0x122e);
}
MATCH_FUNC(0x5BB0E0)
int S5BB0E0::Get_5BB0E0()
{
    return *(unsigned char*)((char*)this + 0x122f);
}
MATCH_FUNC(0x5BB0F0)
int S5BB0F0::Get_5BB0F0()
{
    return *(unsigned char*)((char*)this + 0x1230);
}
MATCH_FUNC(0x5BB100)
int S5BB100::Get_5BB100()
{
    return *(unsigned char*)((char*)this + 0x1231);
}
MATCH_FUNC(0x5BB130)
int S5BB130::Get_5BB130()
{
    return *(unsigned char*)((char*)this + 0x123c);
}

// sub_520F60 (VA 0x520F60, 0xF bytes) - member: post-increments the dword at
// +0x59c and returns the old value.
class S520F60 {
public:
    int M_520F60();
};

MATCH_FUNC(0x520F60)
int S520F60::M_520F60()
{
    int* f = (int*)this;
    return f[0x59c / 4]++;
}

// sub_529B40 (VA 0x529B40) - member: two-hop pointer: field_c -> +0x8c object,
// called with the arg.
class T5EA420 {
public:
    void Other_5EA420(int v);
};
class S529B40 {
public:
    char pad_00[0xc];
    char* field_c;
    void M_529B40(int v);
};

MATCH_FUNC(0x529B40)
void S529B40::M_529B40(int v)
{
    ((T5EA420*)*(char**)(field_c + 0x8c))->Other_5EA420(v);
}

// sub_52AD50 (VA 0x52AD50, 0x13 bytes) - member: true unless the +0x48 byte is
// below 3 or equal to 6.
class S52AD50 {
public:
    bool M_52AD50();
};

MATCH_FUNC(0x52AD50)
bool S52AD50::M_52AD50()
{
    unsigned char c = *(unsigned char*)((char*)this + 0x48);
    if (c < 3 || c == 6)
        return false;
    return true;
}

// sub_52AE00 (VA 0x52AE00) - member: when both +0x10 and +0x18 are set, calls
// virtual slot 4 of the +0x18 object with field_10 and returns its short; else 0.
class T52AE00 {
public:
    virtual void Vt_0();
    virtual short Vat_4(int v);
};
class S52AE00 {
public:
    char pad_00[0x10];
    int field_10;
    char pad_14[0x18 - 0x14];
    T52AE00* field_18;
    short M_52AE00();
};

MATCH_FUNC(0x52AE00)
short S52AE00::M_52AE00()
{
    if (field_10 != 0 && field_18 != 0)
        return field_18->Vat_4(field_10);
    return 0;
}

// sub_52B820 (VA 0x52B820) - member: stores three args at +0x38/+0x3c/+0x40.
class S52B820 {
public:
    char pad_00[0x38];
    int field_38;
    int field_3c;
    int field_40;
    void M_52B820(int a, int b, int c);
};

MATCH_FUNC(0x52B820)
void S52B820::M_52B820(int a, int b, int c)
{
    field_38 = a;
    field_3c = b;
    field_40 = c;
}

class S539870Node {
public:
    unsigned char key_0;
    char pad_01[0x18 - 0x01];
    S539870Node* field_18;
};

class S539870 {
public:
    char pad_00[4];
    S539870Node* field_4;
    S539870Node* Find_539870(unsigned char key);
};

MATCH_FUNC(0x539870)
S539870Node* S539870::Find_539870(unsigned char key)
{
    S539870Node* p = field_4;
    for (;;) {
        if (p == 0)
            return 0;
        if (p->key_0 == key)
            return p;
        p = p->field_18;
    }
}

// sub_54F160 (VA 0x54F160, 0x11 bytes) - cdecl: stores the arg at
// [global 0x7409E4 + 0x104].
extern char* g_7409E4;

MATCH_FUNC(0x54F160)
extern "C" void __cdecl sub_54F160(int v)
{
    *(int*)(g_7409E4 + 0x104) = v;
}

// sub_5548B0 (VA 0x5548B0) - cdecl: whether the dword at [global 0x741F60 +
// 0x104] equals the arg.
extern char* g_741F60;
MATCH_FUNC(0x5548B0)
extern "C" bool __cdecl sub_5548B0(int v)
{
    return *(int*)(g_741F60 + 0x104) == v;
}

MATCH_FUNC(0x5549A0)
bool Has_5549A0()
{
    return g_741f60->field_2064 > 0;
}

extern int g_741f80;
extern int g_741f84;

MATCH_FUNC(0x554E50)
bool IsFirst_554E50(int value)
{
    return value == g_741f80;
}

MATCH_FUNC(0x554E70)
bool IsSecond_554E70(int value)
{
    return value == g_741f84;
}

// sub_555010 (VA 0x555010) - cdecl: whether the dword at [global 0x741F68 +
// 0x9c] equals the arg.
extern char* g_741F68;
MATCH_FUNC(0x555010)
extern "C" bool __cdecl sub_555010(int v)
{
    return *(int*)(g_741F68 + 0x9c) == v;
}

// sub_5562A0 (VA 0x5562A0) - cdecl: whether global table 0x740B54[id]
// equals the second arg, for id in [1,0x100].
extern int g_740B54[];
MATCH_FUNC(0x5562A0)
extern "C" int __cdecl sub_5562A0(int id, int v)
{
    if (id < 1 || id > 0x100)
        return 0;
    return g_740B54[id] == v;
}

// The 0x560660 trio (VA 0x560660/680/6A0, 20 bytes each): compare a word at
// +0x16 of the pointer held at the argument's +8 against three type markers,
// returning int 1/0. The arg arrives on the stack (stdcall, ret 4).
struct S5606 {
    char pad_00[8];
    char* field_8;
};
MATCH_FUNC(0x560660)
int __stdcall sub_560660(int* p)
{
    char* q = ((S5606*)p)->field_8;
    return *(unsigned short*)(q + 0x16) == 0x1B;
}

MATCH_FUNC(0x560680)
int __stdcall sub_560680(int* p)
{
    char* q = ((S5606*)p)->field_8;
    return *(unsigned short*)(q + 0x16) == 0x27;
}

MATCH_FUNC(0x5606A0)
int __stdcall sub_5606A0(int* p)
{
    char* q = ((S5606*)p)->field_8;
    return *(unsigned short*)(q + 0x16) == 4;
}

// sub_562550 (VA 0x562550) - member: dword +8 of entry i in the 44-byte table
// at +0xf20, when entry+0 is nonzero and entry+4 >= 1.
struct E562550 {
    int field_0;
    int field_4;
    int field_8;
    char pad_c[0x2c - 0xc];
};
class S562550 {
public:
    char pad_00[0xf20];
    E562550 entries[1];
    int M_562550(int i);
};

MATCH_FUNC(0x562550)
int S562550::M_562550(int i)
{
    E562550* e = &entries[i];
    if (e->field_0 == 0 || e->field_4 < 1)
        return 0;
    return e->field_8;
}

class S564E80 {
public:
    int Scale_564E80(int n);
};

MATCH_FUNC(0x564E80)
int S564E80::Scale_564E80(int n)
{
    if (n <= 1)
        return 2;
    return n * n;
}

class S58A130 {
public:
    void* vtbl_0;
    int field_4;
    unsigned short field_8;
    S58A130* Init_58A130();
};

MATCH_FUNC(0x58A130)
S58A130* S58A130::Init_58A130()
{
    vtbl_0 = (void*)0x62aa3c;
    field_8 = 0;
    field_4 = 0;
    return this;
}

class S59A3B0 {
public:
    int Wrap_59A3B0(int value);
};

MATCH_FUNC(0x59A3B0)
int S59A3B0::Wrap_59A3B0(int value)
{
    value += 2;
    if (value >= 4)
        value -= 4;
    return value;
}

class S5A02C0Row {
public:
    char pad_00[0x5a];
    unsigned char field_5a;
};

class S5A02C0 {
public:
    char pad_00[0x74];
    S5A02C0Row** array_74;
    int Check_5A02C0(int index);
};

MATCH_FUNC(0x5A02C0)
int S5A02C0::Check_5A02C0(int index)
{
    S5A02C0Row* row = array_74[index];
    if ((row != 0 && row->field_5a != 0) || index == 0x6d)
        return 1;
    return 0;
}

class S5A67B0 {
public:
    char pad_00[0x600];
    int field_600;
    char pad_604[0x620 - 0x604];
    int field_620;
    void Set_5A67B0(int v);
};

MATCH_FUNC(0x5A67B0)
void S5A67B0::Set_5A67B0(int v)
{
    if (v < 0)
        v = field_600;
    field_620 = v;
}

// sub_5BB060 (VA 0x5BB060) - member: pointer to entry index of a 31-byte
// table starting at +0x10a8.
class S5BB060 {
public:
    char* M_5BB060(int index);
};

MATCH_FUNC(0x5BB060)
char* S5BB060::M_5BB060(int index)
{
    return (char*)this + 0x10a8 + index * 31;
}

class S5BC460 {
public:
    void Clear_5BC460();
};

MATCH_FUNC(0x5BC460)
void S5BC460::Clear_5BC460()
{
    int* p = (int*)((char*)this + 0x1ae5);
    for (int i = 0; i < 0x5a; ++i)
        p[i] = 0;
}

// sub_5BFBD0 (VA 0x5BFBD0) - member: writes field_c and field_10 into the
// two out pointers.
class S5BFBD0 {
public:
    char pad_00[0xc];
    int field_c;
    int field_10;
    void M_5BFBD0(int* a, int* b);
};

MATCH_FUNC(0x5BFBD0)
void S5BFBD0::M_5BFBD0(int* a, int* b)
{
    *a = field_c;
    *b = field_10;
}

// sub_5C0840 (VA 0x5C0840, 0xF bytes) - member: field_2c = 999999,
// field_24 = field_28 = 0.
class S5C0840 {
public:
    void M_5C0840();
};

MATCH_FUNC(0x5C0840)
void S5C0840::M_5C0840()
{
    int* f = (int*)this;
    f[0x2c / 4] = 999999;
    f[0x24 / 4] = 0;
    f[0x28 / 4] = 0;
}

// sub_5C13A0 (VA 0x5C13A0) - member: field_5224 = arg; also sets the +0xc
// byte to 1 unless the arg is 4.
class S5C13A0 {
public:
    char pad_00[0xc];
    unsigned char field_c;
    char pad_0D[0x5224 - 0x0D];
    int field_5224;
    void M_5C13A0(int v);
};

MATCH_FUNC(0x5C13A0)
void S5C13A0::M_5C13A0(int v)
{
    field_5224 = v;
    if (v != 4)
        field_c = 1;
}

// Tail-jump forwarders (address order), unclassed sim-region starts.
void sub_520770();
void sub_58A9A0();
void sub_5BD510();

MATCH_FUNC(0x520740)
void sub_520740()
{
    sub_520770();
}

MATCH_FUNC(0x58A7E0)
void sub_58A7E0()
{
    sub_58A9A0();
}

MATCH_FUNC(0x5BD500)
void sub_5BD500()
{
    sub_5BD510();
}
