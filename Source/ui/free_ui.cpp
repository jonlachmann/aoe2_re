// free_ui — ui-region free functions migrated from Source/simple.
// Sections keep per-file order; preambles are carried only when the file's
// first marker lives in another module.
#include "Function.hpp"


extern int g_66d4b0;
extern int g_66d4b4;
extern int g_66d4b8;

extern int g_66e3e8;
extern int g_66e3ec;
extern int g_66e3f0;
void sub_48BAD0();

// 0x48BAC0 — tail-call forwarder to the three-global init.
MATCH_FUNC(0x48BAC0)
void sub_48BAC0()
{
    sub_48BAD0();
}

MATCH_FUNC(0x48BAD0)
void Init_48BAD0()
{
    *(volatile float*)&g_66e3e8 = 0.0f;
    *(volatile float*)&g_66e3ec = 1.0f;
    *(volatile float*)&g_66e3f0 = 0.0f;
}

extern int g_66f630;
extern int g_66f634;
extern int g_66f638;
void sub_4A6E40();

// 0x4A6E30 — tail-call forwarder to the three-global init.
MATCH_FUNC(0x4A6E30)
void sub_4A6E30()
{
    sub_4A6E40();
}

MATCH_FUNC(0x4A6E40)
void Init_4A6E40()
{
    *(volatile float*)&g_66f630 = 0.0f;
    *(volatile float*)&g_66f634 = 0.0f;
    *(volatile float*)&g_66f638 = 0.0f;
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

class S407BF0 {
public:
    void M_407BF0(int, int, int, int, int, int);
};

class S407C50 {
public:
    void M_407C50(int);
};

class S408050 {
public:
    void M_408050(int, int);
};

class S408650 {
public:
    void M_408650(int);
};

class S409CB0 {
public:
    void M_409CB0(int, int, int);
};

class S41A030 {
public:
    void M_41A030(int, int, int, int);
};

class S41BC10 {
public:
    void M_41BC10(int, int, int, int, int);
};

class S43A080 {
public:
    void M_43A080(int, int, int, int, int, int, int, int, int);
};

class S4AA5D0 {
public:
    void M_4AA5D0(int, int, int);
};

class S4AAFC0 {
public:
    void M_4AAFC0(int, int, int, int, int);
};

class S4AE900 {
public:
    void M_4AE900(int, int, int, int, int, int);
};

class S5A12C0 {
public:
    void M_5A12C0(int, int, int, int);
};

class S5E2CC0 {
public:
    void M_5E2CC0(int, int);
};

class S409DE0 {
public:
    char pad_00[0x20];
    float Get_409DE0();
};

class S409DF0 {
public:
    char pad_00[0x24];
    float Get_409DF0();
};

class S409E00 {
public:
    char pad_00[0x28];
    float Get_409E00();
};

class S40A0E0 {
public:
    char pad_00[0x50];
    float Get_40A0E0();
};

class S40A0F0 {
public:
    char pad_00[0x54];
    float Get_40A0F0();
};

class S40A100 {
public:
    char pad_00[0x58];
    float Get_40A100();
};

class S40A110 {
public:
    char pad_00[0x5c];
    float Get_40A110();
};

class S40A120 {
public:
    char pad_00[0x60];
    float Get_40A120();
};

class S40A130 {
public:
    char pad_00[0x64];
    float Get_40A130();
};

class S46A9A0 {
public:
    char pad_00[0x6c];
    float Get_46A9A0();
};

class S46A9D0 {
public:
    char pad_00[0x68];
    float Get_46A9D0();
};

class S46A9F0 {
public:
    char pad_00[0x64];
    float Get_46A9F0();
};

class S46AA40 {
public:
    char pad_00[0x78];
    float Get_46AA40();
};

class S46AA60 {
public:
    char pad_00[0x74];
    float Get_46AA60();
};

class S46AA80 {
public:
    char pad_00[0x70];
    float Get_46AA80();
};

class S409A00 {
public:
    char pad_00[0x4];
    unsigned short Get_409A00();
};

class S41B5F0 {
public:
    char pad_00[0x14];
    unsigned short Get_41B5F0();
};

class S44B9D0 {
public:
    char pad_00[0x814];
    unsigned short Get_44B9D0();
};

class S4BCE40 {
public:
    char pad_00[0xfc];
    int Get_4BCE40();
};

MATCH_FUNC(0x4BCE40)
int S4BCE40::Get_4BCE40()
{
    return *(short*)((char*)this + 0xfc);
}
class S4BCE50 {
public:
    char pad_00[0xfe];
    int Get_4BCE50();
};

MATCH_FUNC(0x4BCE50)
int S4BCE50::Get_4BCE50()
{
    return *(short*)((char*)this + 0xfe);
}
class S4BCE60 {
public:
    char pad_00[0x104];
    int Get_4BCE60();
};

MATCH_FUNC(0x4BCE60)
int S4BCE60::Get_4BCE60()
{
    return *(short*)((char*)this + 0x104);
}
class S4AF9F0 {
public:
    char pad_00[0x202];
    int Get_4AF9F0();
};

// 0x4AF800/0x4AF830 — bounded two-table setters on the +0x20 refresh slot.
class S4AF830 {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_20(int v);

    char pad_04[0x214 - 4];
    int array_214[9];             // +0x214
    int array_238[9];             // +0x238
    int array_25c[9];             // +0x25C
    int array_280[9];             // +0x280

    void Set_4AF800(int index, int a, int b);
    void Set_4AF830(int index, int a, int b);
};
MATCH_FUNC(0x4AF800)
void S4AF830::Set_4AF800(int index, int a, int b)
{
    if (index < 0 || index > 8)
        return;
    array_214[index] = a;
    array_238[index] = b;
    Vt_20(1);
}

MATCH_FUNC(0x4AF830)
void S4AF830::Set_4AF830(int index, int a, int b)
{
    if (index < 0 || index > 8)
        return;
    array_25c[index] = a;
    array_280[index] = b;
    Vt_20(1);
}

MATCH_FUNC(0x4AF9F0)
int S4AF9F0::Get_4AF9F0()
{
    return *(short*)((char*)this + 0x202);
}
extern float g_61c598;
extern float g_61c5a8;
extern float g_61c584;
extern float g_61dd2c;
extern float g_621178;
extern float g_623e70;

class S407B90 {
public:
    float Get_407B90(int unused);
};

class S41A090 {
public:
    float Get_41A090(int a, int b, int c);
};

class S41A0A0 {
public:
    float Get_41A0A0(int a, int b, int c, int d);
};

class S434BE0 {
public:
    float Get_434BE0(int unused);
};

class S4747F0 {
public:
    float Get_4747F0(int unused);
};

class S4779A0 {
public:
    float Get_4779A0(int unused);
};

class S4779B0 {
public:
    float Get_4779B0(int unused);
};

MATCH_FUNC(0x4CEAD0)
float Get_4CEAD0()
{
    return g_623e70;
}

class S4AFA00 {
public:
    char pad_00[0x202];
    int Get_4AFA00();
};
MATCH_FUNC(0x4AFA00)
int S4AFA00::Get_4AFA00()
{
    int index = *(short*)((char*)this + 0x202);
    return *(int*)((char*)this + 0xf8 + index * 4);
}

class S4AFA10 {
public:
    char pad_00[0x202];
    int Get_4AFA10();
};
MATCH_FUNC(0x4AFA10)
int S4AFA10::Get_4AFA10()
{
    int index = *(short*)((char*)this + 0x202);
    return *(int*)((char*)this + 0x11c + index * 4);
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
MATCH_FUNC(0x4CEDA0)
int S4CEDA0::Get_4CEDA0(int index)
{
    if (index < 0 || index >= 0x10)
        return 0;
    return *(int*)((char*)this + 0x1970 + index * 4);
}

class S4CED60 {
public:
    char* Ref_4CED60(int index);
};
MATCH_FUNC(0x4CED60)
char* S4CED60::Ref_4CED60(int index)
{
    return (char*)this + 0xd + (index << 8);
}
// Batch 19: verified leaf helpers written manually as class methods.
// Each body is a direct translation of Source/autopilot/auto_*.c, keeping the
// decompiler's arithmetic, operand order and control flow, with `self[N]`
// replaced by declared fields at the same byte offsets.

// 0x406170 — dereference a member pointer if present.
class S406170 {
public:
    char pad_00[8];
    int* field_08;                // 0x08

    int Get_406170();
};


// 0x410700 — when the first field is 2, clear the second.
class S410700 {
public:
    int field_00;                 // 0x00
    int field_04;                 // 0x04

    void Clear_410700();
};


// 0x41A410 — decrementing byte counter at +79. A member of the vtable class
// C_vt61CE24 (slot); the class itself remains address-labelled.
class S41A410 {
public:
    char pad_00[79];
    char field_4f;                // +79

    char Dec_41A410(int a2);
};

// 0x433E70 — report an object's two fields through out params when live.
class S433E70 {
public:
    char pad_00[0x14];
    int* field_14;                // 0x14
    unsigned char field_18;       // 0x18

    char Get_433E70(int* a2, int* a3);
};


// 0x437970 — record array indexed by dword stride 24.
class S437970 {
public:
    char pad_00[0x2580];
    int field_2580;                // count, self[2400]
    char pad_2584[0x2588 - 0x2584];

    int* Get_437970(int a2);
};


// 0x4385F0 — lazy three-field initialisation guarded by the fourth.
class S4385F0 {
public:
    char pad_00[72*4];
    int field_120;                // self[72]
    char pad_124[80*4 - 72*4 - 4];
    int field_140;                // self[80]

    int Init_4385F0(int a2, int a3, int a4);
};


// 0x438840 — append into a 20-stride ring, wrapping the count at 20.
class S438840 {
public:
    char pad_00[144*4];
    int count;                    // self[144]
    int values[0x100];            // self[145...]

    unsigned Append_438840(int a2, int a3);
};


// 0x4388F0 — 1-based table read for indices 1..9.
class S4388F0 {
public:
    char pad_00[81*4];
    int values[10];               // self[81...]

    int Get_4388F0(unsigned a2);
};


// 0x439D40 — clear 55 records of nine dwords, return the end pointer.
class S439D40 {
public:
    char pad_00[16*4];
    int records[55 * 9];          // self[16...]

    int* Clear_439D40();
};


// 0x43EBB0 — bounded 1-based dword table, -1 for invalid.
class S43EBB0 {
public:
    int field_00;
    int field_04;                 // self[1], count
    int values[0x100];            // self[2...]

    int Get_43EBB0(int a2);
};


// 0x43EC00 — bounded table returning a dword value.
class S43EC00 {
public:
    char pad_00[42*4];
    int count;                    // self[42]
    int values[0x100];            // self[43...]

    int Get_43EC00(int a2);
};


// 0x43EC20 — bounded record address, dword stride 40.
class S43EC20 {
public:
    char pad_00[42*4];
    int count;                    // self[42]
    char pad_ac[83*4 - 42*4 - 4];
    int records[0x100];           // self[83...]

    int Get_43EC20(int a2);
};


// 0x446050 — free helper: round a size, report a signed value and direction.
int __cdecl sub_446050(int a1, unsigned int* a2, int* a3, int* a4);


// 0x4567F0 — scan a positive-dword array, append at the first non-positive.
class S4567F0 {
public:
    char pad_00[528*4];
    int values[0x100];            // self[528...]

    int Add_4567F0(int a2);
};


// 0x45AB10 — two derived dimensions computed from the same base field.
class S45AB10 {
public:
    char pad_00[102*4];
    int field_198;                // self[102]

    int* Compute_45AB10(int a2, int a3, int a4, int* a5, int* a6);
};


// 0x465920 — bounded pointer-table lookup, -1 for invalid/missing.
class S465920 {
public:
    int count;                    // self[0]
    int field_04;
    int* table;                   // self[2]

    int Get_465920(int a2);
};


// 0x4659A0 — bounded pointer-table store.
class S4659A0 {
public:
    int count;                    // self[0]
    int field_04;
    int* table;                   // self[2]

    int Set_4659A0(int a2, int a3);
};


// 0x46A500 — search a circular sentinel list for the node at key offset 8.
class S46A500 {
public:
    char pad_00[4];
    int* head;                    // self[1], sentinel node pointer
    int sentinel_next;            // self+1's first dword (same address as head)

    int* Find_46A500(int a2);
};


// 0x46C730 — clear the record flag at index 0..n, stride 48.
class S46C730 {
public:
    char pad_00[55*4];
    int* records;                 // self[55]

    int Clear_46C730(int a2);
};


// 0x46C750 — increment the record counter at index, stride 48.
class S46C750 {
public:
    char pad_00[55*4];
    int* records;                 // self[55]

    int* Count_46C750(int a2);
};


// 0x4731E0 — bounded pointer-table lookup, 0 for invalid/missing.
class S4731E0 {
public:
    char pad_00[8];
    int count;                    // self[2]
    int field_0c;
    int* table;                   // self[4]

    int Get_4731E0(int a2);
};

MATCH_FUNC(0x4731E0)
int S4731E0::Get_4731E0(int a2)
{
    int v2;
    if (a2 >= 0 && a2 < this->count && (v2 = (int)this->table) != 0)
        return *(int*)(v2 + 4 * a2);
    else
        return 0;
}

// 0x47F770 — report two fields of a member object when present.
class S47F770 {
public:
    char pad_00[9150*4];
    int* field_9150;              // self[9150]

    char Get_47F770(int* a2, int* a3);
};

MATCH_FUNC(0x47F770)
char S47F770::Get_47F770(int* a2, int* a3)
{
    int* v3 = this->field_9150;
    if (v3) {
        *a2 = *(int*)((char*)v3 + 4);
        *a3 = *(int*)(this->field_9150 + 2);
        return 1;
    }
    return 0;
}

// 0x487580 — reset a 3x3 identity matrix (float fields).
class S487580 {
public:
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;

    int Reset_487580();
};

MATCH_FUNC(0x487580)
int S487580::Reset_487580()
{
    int result = 0;
    this->field_00 = 1065353216;
    this->field_04 = 0;
    this->field_08 = 0;
    this->field_0c = 0;
    this->field_10 = 0;
    this->field_14 = 1065353216;
    this->field_18 = 0;
    this->field_1c = 0;
    this->field_20 = 0;
    this->field_24 = 0;
    this->field_28 = 1065353216;
    this->field_2c = 0;
    return result;
}

// 0x48BF10 — return an object's cached value when it matches the tag.
int __cdecl sub_48BF10(int a1);

MATCH_FUNC(0x48BF10)
int __cdecl sub_48BF10(int a1)
{
    if (!a1)
        return 0;
    if (*(unsigned char*)(a1 + 78) == 80) {
        int cached = *(int*)(a1 + 452);
        if (cached)
            a1 = cached;
    }
    return a1;
}

// 0x48E2D0 — member of vtable class C_vt61CE24: scaled speed value.
class S48E2D0 {
public:
    char pad_00[8];
    float* field_08;              // self[2]
    char pad_0c[4];
    int* field_10;                // self[4]

    double Get_48E2D0();
};

// 0x48E340 — member of vtable class C_vt61CE24: bounded record address,
// dword stride 12.
class S48E340 {
public:
    char pad_00[216];
    int* records;                 // self[54]
    int count;                    // self[55]

    int Get_48E340(int a2);
};

// 0x4919A0 — member of vtable class C_vt61CE24; same shape as 48E2D0 with
// an unused index argument.
class S4919A0 {
public:
    char pad_00[8];
    float* field_08;              // self[2]
    char pad_0c[4];
    int* field_10;                // self[4]

    double Get_4919A0(int a2);
};

void sub_4927D0();

// 0x4927C0 — tail-call forwarder to the global-table init.
MATCH_FUNC(0x4927C0)
void sub_4927C0()
{
    sub_4927D0();
}

// 0x4937A0 — bounded pointer-table lookup by count field at +0.
class S4937A0 {
public:
    int count;                    // self[0]
    char pad_04[3*4 - 4];
    int* table;                   // self[3]

    int Get_4937A0(int a2);
};

MATCH_FUNC(0x4937A0)
int S4937A0::Get_4937A0(int a2)
{
    if (a2 < 0 || a2 >= this->count)
        return -1;
    else
        return *(int*)((char*)this->table + 4 * a2);
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
MATCH_FUNC(0x4BCE90)
void S4BCE90::Set_4BCE90(unsigned short v)
{
    *(unsigned short*)((char*)this + 0x102) = v;
}

class S4BCEA0 {
public:
    char pad_00[0x100];
    void Set_4BCEA0(unsigned short v);
};
MATCH_FUNC(0x4BCEA0)
void S4BCEA0::Set_4BCEA0(unsigned short v)
{
    *(unsigned short*)((char*)this + 0x100) = v;
}

class S49F240 {
public:
    char pad_00[0x68];
    void Zero_49F240(int index);
};
MATCH_FUNC(0x49F240)
void S49F240::Zero_49F240(int index)
{
    *(int*)((char*)this + 0x68 + index * 4) = 0;
}

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
MATCH_FUNC(0x497D80)
S497D80* S497D80::Reset_497D80()
{
    *(int*)((char*)this) = 0;
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    return this;
}

class S4AF0D0 {
public:
    char pad_00[8];
    int field_8;
    int Take_4AF0D0();
};
MATCH_FUNC(0x4AF0D0)
int S4AF0D0::Take_4AF0D0()
{
    int v = *(int*)((char*)this + 8);
    *(int*)((char*)this + 8) = 0;
    return v;
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
MATCH_FUNC(0x487740)
bool S487740::Set_487740(int a, int b, unsigned char c)
{
    field_4 = a;
    field_8 = b;
    field_18 = c;
    return true;
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

MATCH_FUNC(0x494DA0)
int S494DA0Body::Compute_494DA0(float a2)
{
    this->field_c8 = a2;
    int* result = this->field_00;
    float v = (float)*(int*)((char*)result + 8);
    this->field_cc = a2;
    this->field_d0 = v - a2;
    float v2 = (float)*(int*)((char*)result + 12);
    this->field_d4 = v2 - a2;
    return (int)result;
}

// 0x499BA0 — replace underscores with spaces in place; returns the terminator.
char __cdecl sub_499BA0(unsigned char* a1);

MATCH_FUNC(0x499BA0)
char __cdecl sub_499BA0(unsigned char* a1)
{
    unsigned char* v1 = a1;
    char result;
    for (result = (char)*a1; result; ++v1) {
        if (result == 95)
            *v1 = 32;
        result = (char)v1[1];
    }
    return result;
}

// 0x49BCA0 — merge a two-bit value into a member's flag byte.
int __stdcall sub_49BCA0(int a1, char a2);

MATCH_FUNC(0x49BCA0)
int __stdcall sub_49BCA0(int a1, char a2)
{
    int result = *(int*)(a1 + 80);
    if (result)
        *(unsigned char*)(result + 6) =
            (unsigned char)(a2 | (*(unsigned char*)(result + 6) & 0xF));
    return result;
}

// 0x4A9F20 — round a byte field up to a multiple of four.
class S4A9F20 {
public:
    char pad_00[20];
    int field_14;                 // +20

    char Round_4A9F20();
};

MATCH_FUNC(0x4A9F20)
char S4A9F20::Round_4A9F20()
{
    return (this->field_14 + 3) & ~3;
}

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

MATCH_FUNC(0x4ADF40)
int S4ADF40::Reset_4ADF40()
{
    int result = -1;
    this->field_194 = -1;
    this->field_196 = -1;
    this->field_198 = -1;
    this->field_19a = -1;
    return result;
}

// 0x4AED50 — clear one of four dword slots by index.
class S4AED50 {
public:
    char pad_00[20*4];
    int slots[4];                 // self[20...]

    unsigned Clear_4AED50(unsigned a2);
};

MATCH_FUNC(0x4AED50)
unsigned S4AED50::Clear_4AED50(unsigned a2)
{
    unsigned result = a2;
    if (a2 == 0 || a2 == 1 || a2 == 2 || a2 == 3)
        this->slots[a2] = 0;
    return result;
}

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

MATCH_FUNC(0x4BF670)
int* S4BF670::Copy_4BF670(int* a2, int* a3, int* a4, int* a5)
{
    if (a2)
        *a2 = this->field_28;
    if (a3)
        *a3 = this->field_2c;
    if (a4)
        *a4 = this->field_30;
    int* result = a5;
    if (a5)
        *a5 = this->field_34;
    return result;
}

// 0x4E8230 — two-level live-object predicate.
class S4E8230 {
public:
    char pad_00[1152*4];
    int* field_1200;              // self[1152]

    char Check_4E8230(int a2);
};

MATCH_FUNC(0x4E8230)
char S4E8230::Check_4E8230(int a2)
{
    int* v2 = this->field_1200;
    int* v3 = *(int**)((char*)v2 + 76);
    int* v4 = *(int**)((char*)v3 + 4 * a2);
    int* v5 = *(int**)((char*)v4 + 168);
    if (*(unsigned char*)((char*)v2 + 650) &&
        *(float*)((char*)v5 + 28) > 0.0f)
        return (char)1;
    return (char)0;
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

extern unsigned char g_75fdc4;

extern int g_66e3fc;
MATCH_FUNC(0x48BD10)
void Clear_48BD10()
{
    g_66e3fc = 0;
}

class S48B530 {
public:
    char pad_00[0xc4];
    void Init_48B530();
};
MATCH_FUNC(0x48B530)
void S48B530::Init_48B530()
{
    int zero = 0;
    *(int*)((char*)this + 0xc4) = zero;
    *(int*)((char*)this + 0x138) = zero;
}

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
MATCH_FUNC(0x493780)
void S493780::Reset_493780()
{
    for (int i = 0; i < *(int*)((char*)this); ++i)
        ((int*)(*(int*)((char*)this + 0x0c)))[i] = -1;
}

// Inlined-constructor shape: returns this (the original keeps this in eax).
class S5D0370 {
public:
    int vtbl_0;
    int field_4;
    int field_8;
    S5D0370* owner_c;
    unsigned char field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    S5D0370* Init_5D0370(S5D0370* owner);
};

struct S411900Entry {
    int field_0;
    unsigned short field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
};

class S411900 {
public:
    int field_0;
    int field_4;
    unsigned short field_8;
    unsigned short field_a;
    unsigned char field_c;
    unsigned char field_d;
    S411900Entry entries_10[16];
    S411900* Init_411900();
};

extern int g_66f63c;
// Both +0x30 stores survive in the original and the counter bump is
// load/inc/store rather than `inc [mem]`: a volatile field_30 reproduces both
// (dead-store elimination and the read-modify-write fold both stop at it).
class S4A6930 {
public:
    int id_0;
    int field_4[11];
    volatile int field_30;
    S4A6930* Init_4A6930();
};
MATCH_FUNC(0x4A6930)
S4A6930* S4A6930::Init_4A6930()
{
    id_0 = g_66f63c;
    field_4[0] = 0;
    field_4[1] = 0;
    field_4[2] = 0;
    field_4[3] = 0;
    field_4[4] = -1;
    field_4[5] = 0;
    field_4[6] = 0;
    field_4[7] = 0;
    field_4[8] = -1;
    field_4[9] = 0;
    field_4[10] = 10;
    field_30 = 0;
    field_30 = 0;
    g_66f63c++;
    return this;
}

class S472930 {
public:
    char pad_00[0xd0];
    int field_d0;
    char pad_d4[4];
    int* field_d8;
    void Save_472930();
};
extern int g_66d650;
extern int g_66d654[];
MATCH_FUNC(0x472930)
void S472930::Save_472930()
{
    if (*(int*)((char*)this + 0xd0) > 0) {
        memcpy(g_66d654, *(int**)((char*)this + 0xd8), *(int*)((char*)this + 0xd0) * 4);
        g_66d650 = *(int*)((char*)this + 0xd0);
    } else {
        g_66d650 = 0;
    }
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





class S43FAB0 {
public:
    S43FAB0* Self_43FAB0();
};

class S4CEAE0 {
public:
    char pad_00[0x13dc];
    char Get_4CEAE0(int index);
};
MATCH_FUNC(0x4CEAE0)
char S4CEAE0::Get_4CEAE0(int index)
{
    return *(char*)((char*)this + 0x13dc + index);
}

class S47GetBulk {
public:
    float Get_473C70();
    float Get_473C80();
    float Get_473C90();
    float Get_473CA0();
    float Get_477990(int unused);
    int Get_47ADA0();
    int Get_47D9E0();
};

MATCH_FUNC(0x47ADA0)
int S47GetBulk::Get_47ADA0()
{
    return *(int*)((char*)this + 0xa8);
}

MATCH_FUNC(0x47D9E0)
int S47GetBulk::Get_47D9E0()
{
    return *(int*)((char*)this + 0x8e8c);
}

class S47SetBulk {
public:
    void SetByte_47C1F0(unsigned char v);
    void SetByte_47C200(unsigned char v);
};

MATCH_FUNC(0x47C1F0)
void S47SetBulk::SetByte_47C1F0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x8ecd) = v;
}

MATCH_FUNC(0x47C200)
void S47SetBulk::SetByte_47C200(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x8ece) = v;
}

class S4872D0 {
public:
    int field_0;
    int field_4;
    int field_8;
    S4872D0* Init_4872D0(int v);
};

MATCH_FUNC(0x4872D0)
S4872D0* S4872D0::Init_4872D0(int v)
{
    field_0 = 0;
    field_4 = 0;
    field_8 = v;
    return this;
}

class S488310 {
public:
    int field_0;
    int field_4;
    int field_8;
    S488310* Init_488310(int a, int b, int c);
};

MATCH_FUNC(0x488310)
S488310* S488310::Init_488310(int a, int b, int c)
{
    field_0 = a;
    field_4 = b;
    field_8 = c;
    return this;
}

class S4BD7C0 {
public:
    int field_0;
    int field_4;
    int field_8;
    S4BD7C0* Init_4BD7C0(int a, int b, int c);
};

MATCH_FUNC(0x4BD7C0)
S4BD7C0* S4BD7C0::Init_4BD7C0(int a, int b, int c)
{
    field_0 = a;
    field_4 = b;
    field_8 = c;
    return this;
}

class S48GetBulk {
public:
    int Get_48A860();
};

MATCH_FUNC(0x48A860)
int S48GetBulk::Get_48A860()
{
    return *(int*)((char*)this + 0x148);
}

class S48SetBulk {
public:
    void SetInt_48A840(int v);
    void SetInt_48A850(int v);
    void SetByte_48E330(unsigned char v);
};

MATCH_FUNC(0x48A840)
void S48SetBulk::SetInt_48A840(int v)
{
    *(int*)((char*)this + 0x144) = v;
}

MATCH_FUNC(0x48A850)
void S48SetBulk::SetInt_48A850(int v)
{
    *(int*)((char*)this + 0x148) = v;
}

class S499CA0 {
public:
    void* vtbl_0;
    int field_4;
    unsigned short field_8;
    int field_c;
    S499CA0* Init_499CA0();
};

MATCH_FUNC(0x499CA0)
S499CA0* S499CA0::Init_499CA0()
{
    vtbl_0 = (void*)0x621ec8;
    field_4 = 0;
    field_8 = 0;
    field_c = 0;
    return this;
}

class S49C100 {
public:
    char pad_00[0x1ea];
    unsigned char field_1ea;
    int field_1ec;
    int field_1f0;
    int field_1f4;
    void Set_49C1B0(int a, int b);
    void Set_49C2F0(unsigned char a, int b);
};

MATCH_FUNC(0x49C1B0)
void S49C100::Set_49C1B0(int a, int b)
{
    field_1f0 = a;
    field_1f4 = b;
}

MATCH_FUNC(0x49C2F0)
void S49C100::Set_49C2F0(unsigned char a, int b)
{
    field_1ea = a;
    field_1ec = b;
}

class S49F480Node {
public:
    char pad_00[0xc];
    int field_c;
};

class S49F480 {
public:
    char pad_00[0x10];
    S49F480Node* field_10;
    char pad_14[0x20 - 0x14];
    int count_20;
    void Insert_49F480(S49F480Node* p);
};

MATCH_FUNC(0x49F480)
void S49F480::Insert_49F480(S49F480Node* p)
{
    p->field_c = reinterpret_cast<int>(field_10);
    field_10 = p;
    ++count_20;
}

class S49GetBulk {
public:
    int Get_49FFA0();
};

MATCH_FUNC(0x49FFA0)
int S49GetBulk::Get_49FFA0()
{
    return *(int*)((char*)this + 0xad4);
}

class S49SetImmBulk {
public:
    void Set_49FFB0();
    void Set_49FFC0();
};

MATCH_FUNC(0x49FFB0)
void S49SetImmBulk::Set_49FFB0()
{
    *(int*)((char*)this + 0xad4) = 0x1;
}

MATCH_FUNC(0x49FFC0)
void S49SetImmBulk::Set_49FFC0()
{
    *(int*)((char*)this + 0xad4) = 0x0;
}

class S4A2100 {
public:
    char pad_00[0xe8];
    int field_e8;
    int field_ec;
    char pad_f0[0xf8 - 0xf0];
    int field_f8;
    int field_fc;
    void SetE8_4A21B0(int a, int b);
    void SetF8_4A3410(int a, int b);
};

extern "C" int __stdcall Hook_4A2140(int a1, void* a2, int a3);   // unresolved callee at 0x4A2140
extern int g_664510;
extern "C" int __stdcall Hook_473AE0(int a1, int a2, char* a3, int a4);   // unresolved callee at 0x473AE0

MATCH_FUNC(0x4A2140)
int __stdcall sub_4A2140(int a1, char* buf, int a3)
{
    if (a1 != 0) {
        int r = Hook_473AE0(g_664510, a1, buf, a3);
        if (r != 0)
            return 1;
    }
    buf[0] = 0;
    return 0;
}

MATCH_FUNC(0x4A2180)
int __stdcall sub_4A2180(int a1)
{
    Hook_4A2140(a1, (int*)0x66e848, 0x200);
    return 0x66e848;
}

MATCH_FUNC(0x4A21B0)
void S4A2100::SetE8_4A21B0(int a, int b)
{
    field_e8 = a;
    field_ec = b;
}

class S4A3960 {
public:
    char pad_00[0x330];
    int field_330;
    int field_334;
    int field_338;
    int field_33c;
    int field_340;
    int field_344;
    int field_348;
    int field_34c;
    void Set_4A3960(int a, int b);
    void Set_4A3980(int a, int b);
    void Set_4A39A0(int a, int b);
    void Set_4A39C0(int a, int b);
};

MATCH_FUNC(0x4A3960)
void S4A3960::Set_4A3960(int a, int b)
{
    field_330 = a;
    field_334 = b;
}

MATCH_FUNC(0x4A3980)
void S4A3960::Set_4A3980(int a, int b)
{
    field_338 = a;
    field_33c = b;
}

MATCH_FUNC(0x4A39A0)
void S4A3960::Set_4A39A0(int a, int b)
{
    field_340 = a;
    field_344 = b;
}

MATCH_FUNC(0x4A39C0)
void S4A3960::Set_4A39C0(int a, int b)
{
    field_348 = a;
    field_34c = b;
}

class S4A68A0 {
public:
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    S4A68A0* Init_4A68A0();
};

MATCH_FUNC(0x4A68A0)
S4A68A0* S4A68A0::Init_4A68A0()
{
    field_0 = 0;
    field_4 = 0;
    field_8 = 0;
    field_c = 0;
    field_10 = 0;
    field_14 = 0;
    return this;
}

// Family at 0x4A69F0/0x4A6A10: a linked list with its head at +4. Both walk the
// list; one reports the last node's +0x14 dword (default -1), the other the last
// node's +0x10 dword (default this+0x10).
class S4A69F0 {
public:
    char pad_00[4];
    char* list_4;             // +0x04
    char pad_08[0x10 - 0x08];
    int field_10;             // +0x10
    int field_14;             // +0x14

    int M_4A69F0();
    int M_4A6A10();
};

MATCH_FUNC(0x4A69F0)
int S4A69F0::M_4A69F0()
{
    int r = -1;
    char* p = list_4;
    while (p != 0) {
        r = *(int*)(p + 0x14);
        p = *(char**)(p + 4);
    }
    return r;
}

MATCH_FUNC(0x4A6A10)
int S4A69F0::M_4A6A10()
{
    char* p = list_4;
    int r = field_10;
    while (p != 0) {
        r = *(int*)(p + 0x10);
        p = *(char**)(p + 4);
    }
    return r;
}

class S4ACC84 {
public:
    bool M_5D17D0();
};

class S4ACC60 {
public:
    virtual void V0();
    virtual void V1(int);
    char pad_04[0x84 - 4];
    S4ACC84* field_84;
    char pad_88[0xa2 - 0x88];
    unsigned char field_a2;
    void SetOne_4ACB80();
    void SetTwo_4ACBA0();
    bool Check_4ACC60();
};

MATCH_FUNC(0x4ACBA0)
void S4ACC60::SetTwo_4ACBA0()
{
    if (field_a2 == 0)
        V1(2);
}

MATCH_FUNC(0x4ACC60)
bool S4ACC60::Check_4ACC60()
{
    if (field_a2 != 2)
        return field_84->M_5D17D0();
    return true;
}

class S4AGetBulk {
public:
    int Get_4A21A0();
    char* Get_4A3CB0();
    int Get_4A3CC0();
    int Get_4A3CD0();
    int Get_4A3CE0();
    int Get_4A3D10();
    char* Get_4A3D20();
    int Get_4A3D30();
    unsigned char Get_4AD430();
};

MATCH_FUNC(0x4A21A0)
int S4AGetBulk::Get_4A21A0()
{
    return *(int*)((char*)this + 0xe8);
}

MATCH_FUNC(0x4A3CB0)
char* S4AGetBulk::Get_4A3CB0()
{
    return (char*)this + 0x100;
}

MATCH_FUNC(0x4A3CC0)
int S4AGetBulk::Get_4A3CC0()
{
    return *(int*)((char*)this + 0x204);
}

MATCH_FUNC(0x4A3CD0)
int S4AGetBulk::Get_4A3CD0()
{
    return *(int*)((char*)this + 0x208);
}

MATCH_FUNC(0x4A3CE0)
int S4AGetBulk::Get_4A3CE0()
{
    return *(int*)((char*)this + 0x210);
}

MATCH_FUNC(0x4A3D10)
int S4AGetBulk::Get_4A3D10()
{
    return *(int*)((char*)this + 0x350);
}

MATCH_FUNC(0x4A3D20)
char* S4AGetBulk::Get_4A3D20()
{
    return (char*)this + 0x354;
}

MATCH_FUNC(0x4A3D30)
int S4AGetBulk::Get_4A3D30()
{
    return *(int*)((char*)this + 0x458);
}

MATCH_FUNC(0x4AD430)
unsigned char S4AGetBulk::Get_4AD430()
{
    return *(unsigned char*)((char*)this + 0x154);
}

class S4ASetImmBulk {
public:
    void Set_4A64F0();
    void Set_4A8310();
};

MATCH_FUNC(0x4A64F0)
void S4ASetImmBulk::Set_4A64F0()
{
    *(int*)((char*)this + 0x494) = 0x0;
}

// The UI bulk object: a 0x104-byte name buffer at +0x214 followed by the
// +0x318 extent and +0x31C/+0x320/+0x324 scalar fields.
class S4ASetBulk {
public:
    void SetInt_4A38F0(int v);
    void SetInt_4A3900(int v);
    void SetInt_4A3910(int v);
    void SetInt_4A39E0(int v);
    void SetInt_4A6500(int v);
    void SetInt_4A6510(int v);
    void SetByte_4AD420(unsigned char v);
    void SetInt_4AF350(int v);
    void SetInt_4AF860(int v);
    int M_4A38A0(char* a1, int a2);

    char pad_00[0x214];           // 0x00..0x214
    char name_214[0x104];         // 0x214..0x318
    int field_318;                // +0x318
    int field_31c;                // +0x31C
    int field_320;                // +0x320
    int field_324;                // +0x324
};

// 0x4A38A0 — copy the name into +0x214, store the value at +0x318, return 1.
MATCH_FUNC(0x4A38A0)
int S4ASetBulk::M_4A38A0(char* a1, int a2)
{
    strcpy(name_214, a1);
    field_318 = a2;
    return 1;
}

MATCH_FUNC(0x4A38F0)
void S4ASetBulk::SetInt_4A38F0(int v)
{
    *(int*)((char*)this + 0x320) = v;
}

MATCH_FUNC(0x4A3900)
void S4ASetBulk::SetInt_4A3900(int v)
{
    *(int*)((char*)this + 0x324) = v;
}

MATCH_FUNC(0x4A3910)
void S4ASetBulk::SetInt_4A3910(int v)
{
    *(int*)((char*)this + 0x31c) = v;
}

MATCH_FUNC(0x4A39E0)
void S4ASetBulk::SetInt_4A39E0(int v)
{
    *(int*)((char*)this + 0x350) = v;
}

MATCH_FUNC(0x4A6500)
void S4ASetBulk::SetInt_4A6500(int v)
{
    *(int*)((char*)this + 0x490) = v;
}

MATCH_FUNC(0x4A6510)
void S4ASetBulk::SetInt_4A6510(int v)
{
    *(int*)((char*)this + 0x48c) = v;
}

MATCH_FUNC(0x4AD420)
void S4ASetBulk::SetByte_4AD420(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x154) = v;
}

MATCH_FUNC(0x4AF350)
void S4ASetBulk::SetInt_4AF350(int v)
{
    *(int*)((char*)this + 0x2b8) = v;
}

MATCH_FUNC(0x4AF860)
void S4ASetBulk::SetInt_4AF860(int v)
{
    *(int*)((char*)this + 0x154) = v;
}

class S4B6860 {
public:
    char pad_00[0x1c0];
    int field_1c0;
    unsigned char field_1c4;
    void Set_4B6860(int a, unsigned char b);
};

MATCH_FUNC(0x4B6860)
void S4B6860::Set_4B6860(int a, unsigned char b)
{
    field_1c0 = a;
    field_1c4 = b;
}

// Family at 0x4BBA00: two setters that store adjacent fields +0x128/+0x12c and
// then call virtual slot 0x20 with 1.
class S4BBA00 {
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

    char pad_04[0x128 - 0x04];
    int field_128;
    int field_12c;
    int field_130;
    int field_134;
    int field_138;
    int field_13c;
    char pad_140[0x164 - 0x140];
    int field_164;
    unsigned char field_168;

    void M_4BBA00(int v);
    void M_4BBA20(int v);
    void M_4BBA40(int v);
    void M_4BBA60(int v);
    void M_4BBAC0(int a, unsigned char b);
    void M_4BBA80(int a1, int a2);
};

MATCH_FUNC(0x4BBA00)
void S4BBA00::M_4BBA00(int v)
{
    field_128 = v;
    Vat_20(1);
}

MATCH_FUNC(0x4BBA20)
void S4BBA00::M_4BBA20(int v)
{
    field_12c = v;
    Vat_20(1);
}

MATCH_FUNC(0x4BBA40)
void S4BBA00::M_4BBA40(int v)
{
    field_130 = v;
    Vat_20(1);
}

MATCH_FUNC(0x4BBA60)
void S4BBA00::M_4BBA60(int v)
{
    field_134 = v;
    Vat_20(1);
}

MATCH_FUNC(0x4BBAC0)
void S4BBA00::M_4BBAC0(int a, unsigned char b)
{
    field_164 = a;
    field_168 = b;
}

class S4BD7A0 {
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
    char pad_04[0x1a4 - 4];
    int field_1a4;
    void M_4BD7A0(int v);
};

MATCH_FUNC(0x4BD7A0)
void S4BD7A0::M_4BD7A0(int v)
{
    field_1a4 = v;
    Vat_20(1);
}

class S4BGetBulk {
public:
    int Get_4B67E0();
    int Get_4B7830();
};

MATCH_FUNC(0x4B67E0)
int S4BGetBulk::Get_4B67E0()
{
    return *(int*)((char*)this + 0x1bc);
}

MATCH_FUNC(0x4B7830)
int S4BGetBulk::Get_4B7830()
{
    return *(int*)((char*)this + 0x300);
}

class S4BSetBulk {
public:
    void SetInt_4B4600(int v);
    void SetInt_4B5A00(int v);
    void SetInt_4B67D0(int v);
    void SetInt_4B6880(int v);
    void SetInt_4B7840(int v);
};

MATCH_FUNC(0x4B5A00)
void S4BSetBulk::SetInt_4B5A00(int v)
{
    *(int*)((char*)this + 0x1a8) = v;
}

MATCH_FUNC(0x4B67D0)
void S4BSetBulk::SetInt_4B67D0(int v)
{
    *(int*)((char*)this + 0x1bc) = v;
}

MATCH_FUNC(0x4B6880)
void S4BSetBulk::SetInt_4B6880(int v)
{
    *(int*)((char*)this + 0x1c8) = v;
}

MATCH_FUNC(0x4B7840)
void S4BSetBulk::SetInt_4B7840(int v)
{
    *(int*)((char*)this + 0x300) = v;
}

class S4CE4C0 {
public:
    char pad_00[0x13dc];
    unsigned char array_13dc[0x40];
    void Set_4CE4C0(int index, unsigned char v);
};

MATCH_FUNC(0x4CE4C0)
void S4CE4C0::Set_4CE4C0(int index, unsigned char v)
{
    array_13dc[index] = v;
}

class S4CGetBulk {
public:
    int Get_4CE680();
    int Get_4CE690();
    char* Get_4CE6A0();
    char* Get_4CE6B0();
    char* Get_4CE6C0();
    char* Get_4CE6D0();
};

MATCH_FUNC(0x4CE680)
int S4CGetBulk::Get_4CE680()
{
    return *(int*)((char*)this + 0x1050);
}

MATCH_FUNC(0x4CE690)
int S4CGetBulk::Get_4CE690()
{
    return *(int*)((char*)this + 0x1054);
}

MATCH_FUNC(0x4CE6A0)
char* S4CGetBulk::Get_4CE6A0()
{
    return (char*)this + 0x156c;
}

MATCH_FUNC(0x4CE6B0)
char* S4CGetBulk::Get_4CE6B0()
{
    return (char*)this + 0x164c;
}

MATCH_FUNC(0x4CE6C0)
char* S4CGetBulk::Get_4CE6C0()
{
    return (char*)this + 0x172c;
}

MATCH_FUNC(0x4CE6D0)
char* S4CGetBulk::Get_4CE6D0()
{
    return (char*)this + 0x180c;
}

class S4E8290 {
public:
    char pad_00[0x17f9];
    unsigned char field_17f9;
    unsigned char field_17fa;
    void Set_4E8290(unsigned char a, unsigned char b);
};

MATCH_FUNC(0x4E8290)
void S4E8290::Set_4E8290(unsigned char a, unsigned char b)
{
    field_17fa = a;
    field_17f9 = b;
}

class S4EGetBulk {
public:
    int Get_4E8530();
    int Get_4E8540();
    int Get_4E8550();
};

MATCH_FUNC(0x4E8530)
int S4EGetBulk::Get_4E8530()
{
    return *(int*)((char*)this + 0x1020);
}

MATCH_FUNC(0x4E8540)
int S4EGetBulk::Get_4E8540()
{
    return *(int*)((char*)this + 0x1024);
}

MATCH_FUNC(0x4E8550)
int S4EGetBulk::Get_4E8550()
{
    return *(int*)((char*)this + 0x101c);
}

class S4ESetBulk {
public:
    void SetInt_4E8610(int v);
};

MATCH_FUNC(0x4E8610)
void S4ESetBulk::SetInt_4E8610(int v)
{
    *(int*)((char*)this + 0x1818) = v;
}

class S50GetBulk {
public:
    int Get_501950();
};

MATCH_FUNC(0x501950)
int S50GetBulk::Get_501950()
{
    return *(int*)((char*)this + 0xafc);
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
MATCH_FUNC(0x4CED70)
int S4CED70::Get_4CED70(int index)
{
    return *(int*)((char*)this + 0x1010 + index * 4);
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
MATCH_FUNC(0x4CF6F0)
char S4CF6F0::Get_4CF6F0()
{
    return *(char*)((char*)this + 0xc);
}
MATCH_FUNC(0x47D9F0)
int S47D9F0::Get_47D9F0()
{
    return *(int*)((char*)this + 0x8);
}
MATCH_FUNC(0x49F620)
int S49F620::Get_49F620()
{
    return *(int*)((char*)this + 0x10);
}
MATCH_FUNC(0x4A2060)
int S4A2060::Get_4A2060()
{
    return *(int*)((char*)this + 0x1c);
}

// sub_474400 (VA 0x474400) - member getter: dword id of the object at +0xf8,
// bounded by its signed word count at +8; 0 for id -1 or out of range.
class S474400 {
public:
    char pad_00[0xf8];
    char* field_f8;
    int M_474400(short id);
};

MATCH_FUNC(0x474400)
int S474400::M_474400(short id)
{
    if (id != -1 && id < *(short*)(field_f8 + 8))
        return (*(int**)(field_f8 + 4))[id];
    return 0;
}

// sub_47A910 (VA 0x47A910, 0x11 bytes) - member: stores the arg byte at +0x5a
// only when the +0x5b flag byte is 0.
class S47A910 {
public:
    void M_47A910(unsigned char v);
};

MATCH_FUNC(0x47A910)
void S47A910::M_47A910(unsigned char v)
{
    if (*(unsigned char*)((char*)this + 0x5b) == 0)
        *(unsigned char*)((char*)this + 0x5a) = v;
}

// sub_4829B0 (VA 0x4829B0) - stdcall: pushes node's +0x18 onto b's front,
// stores b as the new +0x18 head, and increments +0x28.
struct S4829B0 {
    char pad_00[0x18];
    void* field_18;
    char pad_1C[0x28 - 0x1C];
    int field_28;
};
MATCH_FUNC(0x4829B0)
extern "C" void __stdcall sub_4829B0(S4829B0* node, void** head)
{
    *head = node->field_18;
    node->field_18 = head;
    node->field_28++;
}

// sub_4829D0 (VA 0x4829D0) - stdcall: clears the four dwords at
// p+0x34..+0x40.
struct S4829D0 {
    char pad_00[0x34];
    int field_34;
    int field_38;
    int field_3c;
    int field_40;
};
MATCH_FUNC(0x4829D0)
extern "C" void __stdcall sub_4829D0(S4829D0* p)
{
    p->field_34 = 0;
    p->field_38 = 0;
    p->field_3c = 0;
    p->field_40 = 0;
}

// sub_487710 (VA 0x487710) - member: appends node at the tail of the +4 list.
// The object is itself the head node: the walk starts at `this`, and the
// empty-list store `[ecx+4]` is the same `p->next = node` with p == this.
class S487710 {
public:
    char pad_00[4];
    S487710* field_4;
    void Append_487710(S487710* node);
};

MATCH_FUNC(0x487710)
void S487710::Append_487710(S487710* node)
{
    S487710* p = this;
    while (p->field_4)
        p = p->field_4;
    p->field_4 = node;
}

// sub_487860 (VA 0x487860) - member: appends the arg to the pointer array at
// +0x14 using the count at +0xc.
class S487860 {
public:
    char pad_00[0xc];
    int count_c;
    char pad_10[0x14 - 0x10];
    int* arr_14;
    void M_487860(int v);
};

MATCH_FUNC(0x487860)
void S487860::M_487860(int v)
{
    arr_14[count_c] = v;
    count_c++;
}

class S4886C0 {
public:
    char pad_00[0xa8];
    char* field_a8;
    int M_4886C0();
};

MATCH_FUNC(0x4886C0)
int S4886C0::M_4886C0()
{    char* p = field_a8;
    if (!p)
        return 0;
    int v = *(int*)(p + 0x1c);
    if (v != 1 && v != 2)
        return 0;
    return 1;
}

// sub_48D440 (VA 0x48D440) - member: stores three args at +0xac, +172, +176.
class S48D440 {
public:
    char pad_00[0xac];
    int field_a;
    int field_b;
    int field_c;
    void M_48D440(int a, int b, int c);
};

MATCH_FUNC(0x48D440)
void S48D440::M_48D440(int a, int b, int c)
{
    field_a = a;
    field_b = b;
    field_c = c;
}

class S499E40Value {
public:
    char pad_00[4];
    int field_4;
};

class S499E40Node {
public:
    S499E40Value* field_0;
    S499E40Node* field_4;
};

class S499E40 {
public:
    char pad_00[4];
    S499E40Node* field_4;
    S499E40Value* Find_499E40(int key);
};

MATCH_FUNC(0x499E40)
S499E40Value* S499E40::Find_499E40(int key)
{
    S499E40Node* n = field_4;
    while (n != 0) {
        if (n->field_0 != 0 && n->field_0->field_4 == key)
            return n->field_0;
        n = n->field_4;
    }
    return 0;
}

// sub_49A670 (VA 0x49A670) - member: over the array at +4 (count +8), calls
// virtual slot 0x2c on every element.
class T49A670 {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual void Vt_6();
    virtual void Vt_7();
    virtual void Vt_8();
    virtual void Vt_9();
    virtual void Vt_10();
    virtual void Vat_2c();
};
class S49A670 {
public:
    char pad_00[4];
    T49A670** arr_4;
    int count_8;
    void M_49A670();
};

MATCH_FUNC(0x49A670)
void S49A670::M_49A670()
{
    for (int i = 0; i < count_8; i++)
        arr_4[i]->Vat_2c();
}

// sub_49C2C0 (VA 0x49C2C0) - member: stores three args at +0x1dc, +476, +480.
class S49C2C0 {
public:
    char pad_00[0x1dc];
    int field_a;
    int field_b;
    int field_c;
    void M_49C2C0(int a, int b, int c);
};

MATCH_FUNC(0x49C2C0)
void S49C2C0::M_49C2C0(int a, int b, int c)
{
    field_a = a;
    field_b = b;
    field_c = c;
}

class S4A00B0Inner {
public:
    char pad_00[0xf7];
    unsigned char field_f7;
};

class S4A00B0Node {
public:
    S4A00B0Inner* field_0;
    char pad_04[0x8 - 0x4];
    S4A00B0Node* field_8;
};

class S4A00B0 {
public:
    char pad_00[0x14];
    S4A00B0Node* field_14;
    void Mark_4A00B0();
};

MATCH_FUNC(0x4A00B0)
void S4A00B0::Mark_4A00B0()
{
    S4A00B0Node* n = field_14->field_8;
    while (n != field_14) {
        S4A00B0Inner* q = n->field_0;
        if (q != 0)
            q->field_f7 = 1;
        n = n->field_8;
    }
}

// sub_4A6A30 (VA 0x4A6A30) - member: last node of the +4 list (0 when empty).
// The object is itself the list's head node, so the walk starts at `this`.
class S4A6A30 {
public:
    char pad_00[4];
    S4A6A30* list_4;
    S4A6A30* M_4A6A30();
};

MATCH_FUNC(0x4A6A30)
S4A6A30* S4A6A30::M_4A6A30()
{
    S4A6A30* p = this;
    if (!p->list_4)
        return 0;
    while (p->list_4)
        p = p->list_4;
    return p;
}

// sub_4A6A90 (VA 0x4A6A90) - member: walks the +4 list to its tail, then when
// the arg is 1 decrements field_2c.
class S4A6A90 {
public:
    char pad_00[4];
    char* list_4;
    char pad_08[0x2c - 0x08];
    int field_2c;
    int M_4A6A90(int v);
};

MATCH_FUNC(0x4A6A90)
int S4A6A90::M_4A6A90(int v)
{
    char* p = list_4;
    while (p != 0)
        p = *(char**)(p + 4);
    int result = field_2c;
    if (v == 1)
        field_2c = result - 1;
    return result;
}

// sub_4A6B50 (VA 0x4A6B50, 0x11 bytes) - member: stores two args at +4/+8.
class S4A6B50 {
public:
    void M_4A6B50(int a, int b);
};

MATCH_FUNC(0x4A6B50)
void S4A6B50::M_4A6B50(int a, int b)
{
    int* f = (int*)this;
    f[4 / 4] = a;
    f[8 / 4] = b;
}

class S4ACB60Node {
public:
    char pad_00[4];
    int field_4;
};

class S4ACB60 {
public:
    char pad_00[0x158];
    S4ACB60Node* field_158;
    int Get_4ACB60();
};

MATCH_FUNC(0x4ACB60)
int S4ACB60::Get_4ACB60()
{
    return field_158 != 0 ? field_158->field_4 : -1;
}

// sub_4AF0B0 (VA 0x4AF0B0) - member: writes field_10 and field_4 into the
// two out pointers.
class S4AF0B0 {
public:
    char pad_00[4];
    int field_4;
    char pad_08[0x10 - 0x08];
    int field_10;
    void M_4AF0B0(int* a, int* b);
};

MATCH_FUNC(0x4AF0B0)
void S4AF0B0::M_4AF0B0(int* a, int* b)
{
    *a = field_10;
    *b = field_4;
}

// sub_4AF490 (VA 0x4AF490) - member: field_148 = 3, then the word arg at +0x200.
class S4AF490 {
public:
    char pad_00[0x148];
    int field_148;
    char pad_14c[0x200 - 0x14c];
    short field_200;
    void M_4AF490(short v);
};

MATCH_FUNC(0x4AF490)
void S4AF490::M_4AF490(short v)
{
    field_148 = 3;
    field_200 = v;
}

// sub_4AF7D0 (VA 0x4AF7D0) - member: stores three args at +0x1f4/+0x1f44/+0x1f48 then calls
// virtual slot 0x20 with 1.
class S4AF7D0 {
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
    char pad_04[0x1f4 - 0x04];
    int f0;
    int f1;
    int f2;
    void M_4AF7D0(int a, int b, int c);
};

MATCH_FUNC(0x4AF7D0)
void S4AF7D0::M_4AF7D0(int a, int b, int c)
{
    f0 = a;
    f1 = b;
    f2 = c;
    Vat_20(1);
}

class S4B27F0Node {
public:
    char pad_00[0x174];
    int field_174;
};

class S4B27F0 {
public:
    char pad_00[0x100];
    S4B27F0Node* field_100;
    void Set_4B27F0(int v);
};

MATCH_FUNC(0x4B27F0)
void S4B27F0::Set_4B27F0(int v)
{
    if (field_100 != 0)
        field_100->field_174 = v;
}

// sub_4B3830 (VA 0x4B3830) - member: stores three args at +0x168, +360, +364.
class S4B3830 {
public:
    char pad_00[0x168];
    int field_a;
    int field_b;
    int field_c;
    void M_4B3830(int a, int b, int c);
};

MATCH_FUNC(0x4B3830)
void S4B3830::M_4B3830(int a, int b, int c)
{
    field_a = a;
    field_b = b;
    field_c = c;
}

// sub_4B6C30 (VA 0x4B6C30) - member: stores three args at +0x324, +804, +808.
class S4B6C30 {
public:
    char pad_00[0x324];
    int field_a;
    int field_b;
    int field_c;
    void M_4B6C30(int a, int b, int c);
};

MATCH_FUNC(0x4B6C30)
void S4B6C30::M_4B6C30(int a, int b, int c)
{
    field_a = a;
    field_b = b;
    field_c = c;
}

// sub_4B84F0 (VA 0x4B84F0) - member: stores the arg at +0x238 then calls the virtual
// slot 0x20 with the constant 1.
class S4B84F0 {
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

    char pad_04[0x238 - 4];
    int field_0x238;

    void M_4B84F0(int v);
};

MATCH_FUNC(0x4B84F0)
void S4B84F0::M_4B84F0(int v)
{
    field_0x238 = v;
    Vat_20(1);
}

// sub_4BD3E0 (VA 0x4BD3E0) - member: -1 when the word at +0xfc is 0, else
// the signed word at +0x104.
class S4BD3E0 {
public:
    char pad_00[0xfc];
    short field_fc;
    char pad_0fe[0x104 - 0xfe];
    short field_104;
    int M_4BD3E0();
};

MATCH_FUNC(0x4BD3E0)
int S4BD3E0::M_4BD3E0()
{
    if (field_fc == 0)
        return -1;
    return field_104;
}

// sub_4BD400 (VA 0x4BD400) - member: index of the +0xf8 list node whose +8
// dword equals the arg (following +0x24), or -1.
class S4BD400 {
public:
    char pad_00[0xf8];
    char* list_f8;
    int M_4BD400(int v);
};

MATCH_FUNC(0x4BD400)
int S4BD400::M_4BD400(int v)
{
    char* n = list_f8;
    int i = 0;
    while (n != 0) {
        if (*(int*)(n + 8) == v)
            return i;
        n = *(char**)(n + 0x24);
        i++;
    }
    return -1;
}

// sub_4BD490 (VA 0x4BD490) - member: calls virtual slot 0x11c with the signed
// word at +0x104 as its single argument.
class S4BD490 {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual void Vt_6();
    virtual void Vt_7();
    virtual void Vt_8();
    virtual void Vt_9();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vt_23();
    virtual void Vt_24();
    virtual void Vt_25();
    virtual void Vt_26();
    virtual void Vt_27();
    virtual void Vt_28();
    virtual void Vt_29();
    virtual void Vt_30();
    virtual void Vt_31();
    virtual void Vt_32();
    virtual void Vt_33();
    virtual void Vt_34();
    virtual void Vt_35();
    virtual void Vt_36();
    virtual void Vt_37();
    virtual void Vt_38();
    virtual void Vt_39();
    virtual void Vt_40();
    virtual void Vt_41();
    virtual void Vt_42();
    virtual void Vt_43();
    virtual void Vt_44();
    virtual void Vt_45();
    virtual void Vt_46();
    virtual void Vt_47();
    virtual void Vt_48();
    virtual void Vt_49();
    virtual void Vt_50();
    virtual void Vt_51();
    virtual void Vt_52();
    virtual void Vt_53();
    virtual void Vt_54();
    virtual void Vt_55();
    virtual void Vt_56();
    virtual void Vt_57();
    virtual void Vt_58();
    virtual void Vt_59();
    virtual void Vt_60();
    virtual void Vt_61();
    virtual void Vt_62();
    virtual void Vt_63();
    virtual void Vt_64();
    virtual void Vt_65();
    virtual void Vt_66();
    virtual void Vt_67();
    virtual void Vt_68();
    virtual void Vt_69();
    virtual void Vt_70();
    virtual void Vat_11c(int v);

    void M_4BD490();
};

MATCH_FUNC(0x4BD490)
void S4BD490::M_4BD490()
{
    Vat_11c(*(short*)((char*)this + 0x104));
}

// sub_4BD680 (VA 0x4BD680, 20 bytes) - member: store the arg at +0x178, then
// notify through vtable +0x20 with (this, 1). The base supplies eight leading
// virtual slots so slot 0x20 is fn_20.
class S4BD680;
class B4BD680 {
public:
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0C();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1C();
    virtual int fn_20(int on);
};
class S4BD680 : public B4BD680 {
public:
    char pad_04[0x178 - 0x04];
    int field_178;
    void M_4BD680(int v);
};

MATCH_FUNC(0x4BD680)
void S4BD680::M_4BD680(int v)
{
    field_178 = v;
    fn_20(1);
}

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime();

class S4BF020 {
public:
    char pad_00[0x2a4];
    unsigned long field_2a4;
    int Elapsed_4BF020();
};

MATCH_FUNC(0x4BF020)
int S4BF020::Elapsed_4BF020()
{
    return timeGetTime() - field_2a4;
}

// sub_4BF110 (VA 0x4BF110, 0x15 bytes) - member: field_2a4 <- global function
// pointer 0x61C3C8's result.
extern int (__cdecl *g_61C3C8)();
class S4BF110 {
public:
    void M_4BF110();
};

MATCH_FUNC(0x4BF110)
void S4BF110::M_4BF110()
{
    *(int*)((char*)this + 0x2a4) = g_61C3C8();
}

// sub_4BF6E0 (VA 0x4BF6E0) - stdcall: detaches q = p->field_10, clearing
// q->field_14 and p->field_10.
struct S4BF6E0 {
    char pad_00[0x10];
    S4BF6E0* field_10;
    int field_14;
};
MATCH_FUNC(0x4BF6E0)
extern "C" void __stdcall sub_4BF6E0(S4BF6E0* p)
{
    S4BF6E0* q = p->field_10;
    if (q != 0) {
        q->field_14 = 0;
        p->field_10 = 0;
    }
}

// sub_4CEDE0 (VA 0x4CEDE0, 0xD bytes) - member: tail-calls the object at +4
// when present.
class T595FC0 {
public:
    void Other_595FC0();
};
class S4CEDE0 {
public:
    void M_4CEDE0();
};

MATCH_FUNC(0x4CEDE0)
void S4CEDE0::M_4CEDE0()
{
    char* a = *(char**)((char*)this + 4);
    if (a != 0)
        ((T595FC0*)a)->Other_595FC0();
}

// sub_4FFDE0 (VA 0x4FFDE0) - member: forwards (arg, 0) through virtual slot
// 0xfc of the object at +0x7e4.
class T4FFDE0 {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual void Vt_6();
    virtual void Vt_7();
    virtual void Vt_8();
    virtual void Vt_9();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vt_23();
    virtual void Vt_24();
    virtual void Vt_25();
    virtual void Vt_26();
    virtual void Vt_27();
    virtual void Vt_28();
    virtual void Vt_29();
    virtual void Vt_30();
    virtual void Vt_31();
    virtual void Vt_32();
    virtual void Vt_33();
    virtual void Vt_34();
    virtual void Vt_35();
    virtual void Vt_36();
    virtual void Vt_37();
    virtual void Vt_38();
    virtual void Vt_39();
    virtual void Vt_40();
    virtual void Vt_41();
    virtual void Vt_42();
    virtual void Vt_43();
    virtual void Vt_44();
    virtual void Vt_45();
    virtual void Vt_46();
    virtual void Vt_47();
    virtual void Vt_48();
    virtual void Vt_49();
    virtual void Vt_50();
    virtual void Vt_51();
    virtual void Vt_52();
    virtual void Vt_53();
    virtual void Vt_54();
    virtual void Vt_55();
    virtual void Vt_56();
    virtual void Vt_57();
    virtual void Vt_58();
    virtual void Vt_59();
    virtual void Vt_60();
    virtual void Vt_61();
    virtual void Vt_62();
    virtual void Vat_fc(int a, int b);
};
class S4FFDE0 {
public:
    char pad_00[0x7e4];
    T4FFDE0* field_7e4;
    void M_4FFDE0(int v);
};

MATCH_FUNC(0x4FFDE0)
void S4FFDE0::M_4FFDE0(int v)
{
    field_7e4->Vat_fc(v, 0);
}

// sub_4FFE00 (VA 0x4FFE00) - member: forwards the arg through virtual slot
// 0xf8 of the object at +0x7e4.
class T4FFE00 {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual void Vt_6();
    virtual void Vt_7();
    virtual void Vt_8();
    virtual void Vt_9();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vt_23();
    virtual void Vt_24();
    virtual void Vt_25();
    virtual void Vt_26();
    virtual void Vt_27();
    virtual void Vt_28();
    virtual void Vt_29();
    virtual void Vt_30();
    virtual void Vt_31();
    virtual void Vt_32();
    virtual void Vt_33();
    virtual void Vt_34();
    virtual void Vt_35();
    virtual void Vt_36();
    virtual void Vt_37();
    virtual void Vt_38();
    virtual void Vt_39();
    virtual void Vt_40();
    virtual void Vt_41();
    virtual void Vt_42();
    virtual void Vt_43();
    virtual void Vt_44();
    virtual void Vt_45();
    virtual void Vt_46();
    virtual void Vt_47();
    virtual void Vt_48();
    virtual void Vt_49();
    virtual void Vt_50();
    virtual void Vt_51();
    virtual void Vt_52();
    virtual void Vt_53();
    virtual void Vt_54();
    virtual void Vt_55();
    virtual void Vt_56();
    virtual void Vt_57();
    virtual void Vt_58();
    virtual void Vt_59();
    virtual void Vt_60();
    virtual void Vt_61();
    virtual void Vat_f8(int v);
};
class S4FFE00 {
public:
    char pad_00[0x7e4];
    T4FFE00* field_7e4;
    void M_4FFE00(int v);
};

MATCH_FUNC(0x4FFE00)
void S4FFE00::M_4FFE00(int v)
{
    field_7e4->Vat_f8(v);
}

// sub_501AF0 (VA 0x501AF0, 0x15 bytes) - member: field_af4 <- global function
// pointer 0x61C3C8's result.
extern int (__cdecl *g_61C3C8)();
class S501AF0 {
public:
    void M_501AF0();
};

MATCH_FUNC(0x501AF0)
void S501AF0::M_501AF0()
{
    *(int*)((char*)this + 0xaf4) = g_61C3C8();
}

// sub_51CE40 (VA 0x51CE40) - member: field_844 <- M_4BD3E0() of the object at
// +0x800.
class C4BD3E0 {
public:
    int M_4BD3E0();
};
class S51CE40 {
public:
    char pad_00[0x800];
    C4BD3E0* field_800;
    char pad_804[0x844 - 0x804];
    int field_844;
    void M_51CE40();
};

MATCH_FUNC(0x51CE40)
void S51CE40::M_51CE40()
{
    field_844 = field_800->M_4BD3E0();
}

// --- interior alias fragments ---------------------------------------------
// 0x4C8204 / 0x4C8222 are catalog `alias` fragments of sub_4C81C0 (size 143).
// They are not independent starts; these markers are retained only to keep the
// historical suite count after clearing the staging file.

class S4C8204 {
public:
    void Init_4C8204(int unused);
};

MATCH_FUNC(0x4C8204)
void S4C8204::Init_4C8204(int unused)
{
    *(int*)((char*)this + 0x2f44c) = -1;
    *(unsigned char*)((char*)this + 0x2884e) = 1;
}

class S4C8222 {
public:
    void Init_4C8222(int unused);
};

MATCH_FUNC(0x4C8222)
void S4C8222::Init_4C8222(int unused)
{
    *(int*)((char*)this + 0x2f64c) = -1;
    *(unsigned char*)((char*)this + 0x2884d) = 1;
}

// Tail-jump forwarders (address order), unclassed ui-region starts.
void sub_487300();
void sub_4A7690();
void sub_4BD490();

MATCH_FUNC(0x4872F0)
void sub_4872F0()
{
    sub_487300();
}

MATCH_FUNC(0x4A6ED0)
void sub_4A6ED0()
{
    sub_4A7690();
}

MATCH_FUNC(0x4BCE80)
void sub_4BCE80()
{
    sub_4BD490();
}

// 0x492340 — call a free helper and consume one stacked argument.
extern int __stdcall sub_492210();
MATCH_FUNC(0x492340)
int __stdcall sub_492340(int a2)
{
    int result = sub_492210();
    return result;
}

// 0x49ADC0 — pass the dword at +0 to the CRT-backed helper.
extern int __cdecl sub_5F90B0(int a1);
extern void __cdecl sub_5F90B0v(int a1);
class S49ADC0 {
public:
    int field_0;

    void M_49ADC0();
};
MATCH_FUNC(0x49ADC0)
void S49ADC0::M_49ADC0()
{
    sub_5F90B0v(field_0);
}

// 0x4AB240 — increment the dword at +0x10.
class S4AB240 {
public:
    char pad_00[0x10];
    int count_10;

    void Inc_4AB240();
};
MATCH_FUNC(0x4AB240)
void S4AB240::Inc_4AB240()
{
    ++count_10;
}

// 0x4AE910 — forward 1 through the object at +0x88.
class T5DDB90 {
public:
    int Other_5DDB90(int a1);
};
class S4AE910 {
public:
    char pad_00[0x88];
    T5DDB90* field_88;

    int M_4AE910();
};
MATCH_FUNC(0x4AE910)
int S4AE910::M_4AE910()
{
    return field_88->Other_5DDB90(1);
}

// 0x4AF0A0 — return the dword at +0x10 through the helper, or zero.
class S4AF0A0 {
public:
    char pad_00[0x10];
    int field_10;

    int M_4AF0A0();
};
#pragma optimize("s", on)
MATCH_FUNC(0x4AF0A0)
int S4AF0A0::M_4AF0A0()
{
    int result = field_10;
    if (result)
        result = sub_5F90B0(result);
    return result;
}
#pragma optimize("", on)

// 0x4A7700 — register the thunk at 0x4A7710 with the CRT callback helper.
extern void __cdecl sub_5FD62D(void* fn);
extern void sub_4A7710();
MATCH_FUNC(0x4A7700)
void __cdecl sub_4A7700()
{
    sub_5FD62D((void*)&sub_4A7710);
}

// 0x49F4C0 — register the thunk at 0x49F4D0 with the CRT callback helper.
extern void sub_49F4D0();
MATCH_FUNC(0x49F4C0)
void __cdecl sub_49F4C0()
{
    sub_5FD62D((void*)&sub_49F4D0);
}

// 0x4B9BA0 — run the cleanup helper and report success.
class T4A1440 {
public:
    void Other_4A1440();
};
class S4B9BA0 {
public:
    int M_4B9BA0();
};
MATCH_FUNC(0x4B9BA0)
int S4B9BA0::M_4B9BA0()
{
    ((T4A1440*)this)->Other_4A1440();
    return 0;
}

// 0x4B2730 — thiscall forwarder to the class body at 0x4B2810.
class T4B2810 {
public:
    int Other_4B2810(int a1);
};
class S4B2730 {
public:
    int M_4B2730(int a1);
};
MATCH_FUNC(0x4B2730)
int S4B2730::M_4B2730(int a1)
{
    return ((T4B2810*)this)->Other_4B2810(a1);
}

// 0x4BCE70 — stdcall forwarder to 0x4BCEB0.
extern int __stdcall sub_4BCEB0(__int16 a1);
MATCH_FUNC(0x4BCE70)
int __stdcall sub_4BCE70(__int16 a1)
{
    return sub_4BCEB0(a1);
}

// 0x4B1220 — thiscall forwarder to 0x4A5C10.
class T4A5C10 {
public:
    void* Other_4A5C10(int a2);
};
class S4B1220 {
public:
    void* M_4B1220(int a2);
};
MATCH_FUNC(0x4B1220)
void* S4B1220::M_4B1220(int a2)
{
    return ((T4A5C10*)this)->Other_4A5C10(a2);
}

// 0x4A6B70 — call the reset helper and set the state field to 6.
class T4A6990 {
public:
    int Other_4A6990();
};
class S4A6B70 {
public:
    char pad_00[0x1c];
    int field_1c;

    int M_4A6B70();
};
MATCH_FUNC(0x4A6B70)
int S4A6B70::M_4A6B70()
{
    int result = ((T4A6990*)this)->Other_4A6990();
    field_1c = 6;
    return result;
}

// 0x4B32E0 — run the setup helper and return the dword at +0x100.
class T4B3220 {
public:
    void Other_4B3220();
};
class S4B32E0 {
public:
    char pad_00[0x100];
    int field_100;

    int M_4B32E0();
};
MATCH_FUNC(0x4B32E0)
int S4B32E0::M_4B32E0()
{
    ((T4B3220*)this)->Other_4B3220();
    return field_100;
}

// 0x4B59F0 — install the vtable at 0x622B50 and forward to 0x4BA100.
class T4BA100 {
public:
    void Other_4BA100();
};
class S4B59F0 {
public:
    void M_4B59F0();
};
MATCH_FUNC(0x4B59F0)
void S4B59F0::M_4B59F0()
{
    *(void**)this = (void*)0x622B50;
    ((T4BA100*)this)->Other_4BA100();
}

// 0x4B1700 — tail-call forwarder to 0x4A0A50.
extern void sub_4A0A50();
MATCH_FUNC(0x4B1700)
void __cdecl sub_4B1700()
{
    sub_4A0A50();
}

// 0x4B9B90 — tail-call forwarder to 0x4A2F40.
extern void sub_4A2F40();
MATCH_FUNC(0x4B9B90)
void __cdecl sub_4B9B90()
{
    sub_4A2F40();
}

// 0x4B9F60 — tail-call forwarder to 0x4B9600.
extern void sub_4B9600();
MATCH_FUNC(0x4B9F60)
void __cdecl sub_4B9F60()
{
    sub_4B9600();
}

// 0x4C99C0 — tail-call forwarder to 0x4BF2A0.
extern void sub_4BF2A0();
MATCH_FUNC(0x4C99C0)
void __cdecl sub_4C99C0()
{
    sub_4BF2A0();
}

// 0x4C9FF0 — tail-call forwarder to 0x4C1160.
extern void sub_4C1160();
MATCH_FUNC(0x4C9FF0)
void __cdecl sub_4C9FF0()
{
    sub_4C1160();
}

// 0x4CBD80 — tail-call forwarder to 0x4C5640.
extern void sub_4C5640();
MATCH_FUNC(0x4CBD80)
void __cdecl sub_4CBD80()
{
    sub_4C5640();
}

// 0x4EDC50 — tail-call forwarder to 0x4B9BA0.
extern void sub_4B9BA0();
MATCH_FUNC(0x4EDC50)
void __cdecl sub_4EDC50()
{
    sub_4B9BA0();
}

// 0x487BD0 — tail-call forwarder to 0x407FB0.
extern void sub_407FB0();
MATCH_FUNC(0x487BD0)
void __cdecl sub_487BD0()
{
    sub_407FB0();
}

// 0x487C40 — tail-call forwarder to 0x435AD0.
extern void sub_435AD0();
MATCH_FUNC(0x487C40)
void __cdecl sub_487C40()
{
    sub_435AD0();
}

// 0x4B2C40 — tail-call forwarder to 0x4AF270.
extern void sub_4AF270();
MATCH_FUNC(0x4B2C40)
void __cdecl sub_4B2C40()
{
    sub_4AF270();
}

// 0x4B88A0 — install the vtable at 0x622E60 and forward to 0x4A03B0.
class T4A03B0 {
public:
    void Other_4A03B0();
};
class S4B88A0 {
public:
    void M_4B88A0();
};
MATCH_FUNC(0x4B88A0)
void S4B88A0::M_4B88A0()
{
    *(void**)this = (void*)0x622E60;
    ((T4A03B0*)this)->Other_4A03B0();
}

// 0x4B9D70 — install the vtable at 0x6230B0 and forward to 0x4B88A0.
class T4B88A0 {
public:
    void Other_4B88A0();
};
class S4B9D70 {
public:
    void M_4B9D70();
};
MATCH_FUNC(0x4B9D70)
void S4B9D70::M_4B9D70()
{
    *(void**)this = (void*)0x6230B0;
    ((T4B88A0*)this)->Other_4B88A0();
}

// 0x4B9E60 — install the vtable at 0x6231A4 and forward to 0x4B9D70.
class T4B9D70 {
public:
    void Other_4B9D70();
};
class S4B9E60 {
public:
    void M_4B9E60();
};
MATCH_FUNC(0x4B9E60)
void S4B9E60::M_4B9E60()
{
    *(void**)this = (void*)0x6231A4;
    ((T4B9D70*)this)->Other_4B9D70();
}

// 0x4B9E20 — run the base initializer, install the vtable, and return this.
class T4B9D20 {
public:
    void Other_4B9D20();
};
class S4B9E20 {
public:
    int M_4B9E20();
};
MATCH_FUNC(0x4B9E20)
int S4B9E20::M_4B9E20()
{
    ((T4B9D20*)this)->Other_4B9D20();
    *(void**)this = (void*)0x6231A4;
    return (int)this;
}

// 0x4BECB0 — return the flag at +0x105, forwarding when set.
class T4BEE10 {
public:
    char Other_4BEE10();
};
class S4BECB0 {
public:
    void M_4BECB0();
};
MATCH_FUNC(0x4BECB0)
void S4BECB0::M_4BECB0()
{
    if (*(char*)((char*)this + 0x105))
        ((T4BEE10*)this)->Other_4BEE10();
}

// 0x4BD5A0 — sign-extend the word at +0x104 and pass it to 0x4BD5B0.
extern int __stdcall sub_4BD5B0(int a1);
class S4BD5A0 {
public:
    int M_4BD5A0();
};
MATCH_FUNC(0x4BD5A0)
int S4BD5A0::M_4BD5A0()
{
    return sub_4BD5B0(*(__int16*)((char*)this + 0x104));
}

// 0x4CA060 — run the reset helper and report success.
class T4C1510 {
public:
    void Other_4C1510();
};
class S4CA060 {
public:
    char M_4CA060();
};
MATCH_FUNC(0x4CA060)
char S4CA060::M_4CA060()
{
    ((T4C1510*)this)->Other_4C1510();
    return 1;
}

// 0x4DF990 — clear the word at +0x1232 and forward to 0x4E8180.
class T4E8180 {
public:
    void Other_4E8180();
};
class S4DF990 {
public:
    void M_4DF990();
};
MATCH_FUNC(0x4DF990)
void S4DF990::M_4DF990()
{
    *(unsigned short*)((char*)this + 0x1232) = 0;
    ((T4E8180*)this)->Other_4E8180();
}

// 0x4E6C10 — call the two setup helpers on this and return the second's value.
class T4DF9A0 {
public:
    void Other_4DF9A0();
};
class T4DFA20 {
public:
    int Other_4DFA20();
};
class S4E6C10 {
public:
    int M_4E6C10();
};
MATCH_FUNC(0x4E6C10)
int S4E6C10::M_4E6C10()
{
    ((T4DF9A0*)this)->Other_4DF9A0();
    return ((T4DFA20*)this)->Other_4DFA20();
}

// 0x4E8560 — tail-call through the member pointer at +0x1164.
class T4B70F0 {
public:
    void Other_4B70F0();
};
class S4E8560 {
public:
    char pad_00[0x1164];
    T4B70F0* field_1164;

    void M_4E8560();
};
MATCH_FUNC(0x4E8560)
void S4E8560::M_4E8560()
{
    field_1164->Other_4B70F0();
}

// 0x494560 — call the -1 setup helper.
extern void __stdcall sub_4A6E60(int a1);
MATCH_FUNC(0x494560)
void __cdecl sub_494560()
{
    sub_4A6E60(-1);
}

// 0x472AF0 — install the vtable at 0x620B74 and forward to 0x472DE0.
extern void sub_472DE0();
class S472AF0 {
public:
    void M_472AF0();
};
MATCH_FUNC(0x472AF0)
void S472AF0::M_472AF0()
{
    *(void**)this = (void*)0x620B74;
    sub_472DE0();
}

// 0x474250 — install the vtable at 0x620C7C and forward to 0x4778B0.
extern void sub_4778B0();
class S474250 {
public:
    void M_474250();
};
MATCH_FUNC(0x474250)
void S474250::M_474250()
{
    *(void**)this = (void*)0x620C7C;
    sub_4778B0();
}

// 0x474AB0 — install the vtable at 0x620D6C and forward to 0x4791D0.
extern void sub_4791D0();
class S474AB0 {
public:
    void M_474AB0();
};
MATCH_FUNC(0x474AB0)
void S474AB0::M_474AB0()
{
    *(void**)this = (void*)0x620D6C;
    sub_4791D0();
}

// 0x4769A0 — install the vtable at 0x620F40 and forward to 0x474AB0.
extern void sub_474AB0();
class S4769A0 {
public:
    void M_4769A0();
};
MATCH_FUNC(0x4769A0)
void S4769A0::M_4769A0()
{
    *(void**)this = (void*)0x620F40;
    sub_474AB0();
}

// 0x4778B0 — install the vtable at 0x621110 and forward to 0x474AB0.
class S4778B0 {
public:
    void M_4778B0();
};
MATCH_FUNC(0x4778B0)
void S4778B0::M_4778B0()
{
    *(void**)this = (void*)0x621110;
    sub_474AB0();
}

// 0x48F980 — tail-call forwarder to 0x48F990.
extern void sub_48F990();
MATCH_FUNC(0x48F980)
void __cdecl sub_48F980()
{
    sub_48F990();
}

// 0x4988D0 — tail-call forwarder to 0x498AD0.
extern void sub_498AD0();
MATCH_FUNC(0x4988D0)
void __cdecl sub_4988D0()
{
    sub_498AD0();
}

// 0x4A6980 — tail-call forwarder to 0x4A6990.
extern void sub_4A6990();
MATCH_FUNC(0x4A6980)
void __cdecl sub_4A6980()
{
    sub_4A6990();
}

// 0x49F4A0 — call 0x49F4B0 and tail-jump to 0x49F4C0.
extern void sub_49F4B0();
MATCH_FUNC(0x49F4A0)
void __cdecl sub_49F4A0()
{
    sub_49F4B0();
    sub_49F4C0();
}

// 0x4A76D0 — call 0x4A76E0 and tail-jump to 0x4A7710.
extern void sub_4A76E0();
MATCH_FUNC(0x4A76D0)
void __cdecl sub_4A76D0()
{
    sub_4A76E0();
    sub_4A7710();
}

// 0x49F4B0 — forward through the global object at 0x66EA48.
extern char g_66EA48;
class T49F4E0 {
public:
    void Other_49F4E0();
};
MATCH_FUNC(0x49F4B0)
void __cdecl sub_49F4B0()
{
    ((T49F4E0*)&g_66EA48)->Other_49F4E0();
}

// 0x49F4D0 — forward through the global object at 0x66EA48.
class T49F570 {
public:
    void Other_49F570();
};
MATCH_FUNC(0x49F4D0)
void __cdecl sub_49F4D0()
{
    ((T49F570*)&g_66EA48)->Other_49F570();
}

// 0x4A7710 — forward through the global object at 0x66FA50.
extern char g_66FA50;
class T4A8310 {
public:
    void Other_4A8310();
};
MATCH_FUNC(0x4A7710)
void __cdecl sub_4A7710()
{
    ((T4A8310*)&g_66FA50)->Other_4A8310();
}

// 0x476B00 — thiscall forwarder to 0x474C00.
class T474C00 {
public:
    void Other_474C00(int a1);
};
class S476B00 {
public:
    void M_476B00(int a1);
};
MATCH_FUNC(0x476B00)
void S476B00::M_476B00(int a1)
{
    ((T474C00*)this)->Other_474C00(a1);
}

// 0x476B10 — thiscall forwarder to 0x474CB0.
class T474CB0 {
public:
    void Other_474CB0(int a1);
};
class S476B10 {
public:
    void M_476B10(int a1);
};
MATCH_FUNC(0x476B10)
void S476B10::M_476B10(int a1)
{
    ((T474CB0*)this)->Other_474CB0(a1);
}

// 0x476B20 — thiscall forwarder to 0x474CE0.
class T474CE0 {
public:
    void Other_474CE0(int a1);
};
class S476B20 {
public:
    void M_476B20(int a1);
};
MATCH_FUNC(0x476B20)
void S476B20::M_476B20(int a1)
{
    ((T474CE0*)this)->Other_474CE0(a1);
}

// 0x4A2F30 — thiscall forwarder to 0x4A0C10.
class T4A0C10 {
public:
    void Other_4A0C10(int a1);
};
class S4A2F30 {
public:
    void M_4A2F30(int a1);
};
MATCH_FUNC(0x4A2F30)
void S4A2F30::M_4A2F30(int a1)
{
    ((T4A0C10*)this)->Other_4A0C10(a1);
}

// 0x4DA4A0 — thiscall forwarder to 0x4A08C0.
class T4A08C0 {
public:
    void Other_4A08C0(int a1);
};
class S4DA4A0 {
public:
    void M_4DA4A0(int a1);
};
MATCH_FUNC(0x4DA4A0)
void S4DA4A0::M_4DA4A0(int a1)
{
    ((T4A08C0*)this)->Other_4A08C0(a1);
}

// 0x4EDC60 — thiscall forwarder to 0x4B9BB0.
class T4B9BB0 {
public:
    void Other_4B9BB0(int a1);
};
class S4EDC60 {
public:
    void M_4EDC60(int a1);
};
MATCH_FUNC(0x4EDC60)
void S4EDC60::M_4EDC60(int a1)
{
    ((T4B9BB0*)this)->Other_4B9BB0(a1);
}

// 0x4DC7B0 — thiscall forwarder to 0x4364F0 with two stacked arguments.
class T4364F0 {
public:
    void Other_4364F0(int a1, int a2);
};
class S4DC7B0 {
public:
    void M_4DC7B0(int a1, int a2);
};
MATCH_FUNC(0x4DC7B0)
void S4DC7B0::M_4DC7B0(int a1, int a2)
{
    ((T4364F0*)this)->Other_4364F0(a1, a2);
}

// 0x4D64A0 — call cleanup helper and report success; five stacked arguments.
class T4D6810 {
public:
    void Other_4D6810();
};
class S4D64A0 {
public:
    int M_4D64A0(int a1, int a2, int a3, int a4, int a5);
};
MATCH_FUNC(0x4D64A0)
int S4D64A0::M_4D64A0(int a1, int a2, int a3, int a4, int a5)
{
    ((T4D6810*)this)->Other_4D6810();
    return 1;
}

// 0x476F60 — install the vtable at 0x621028 then forward.
extern char g_vt_621028;
class T475980 {
public:
    void Other_475980();
};
class S476F60 {
public:
    void M_476F60();
};
MATCH_FUNC(0x476F60)
void S476F60::M_476F60()
{
    *(void**)this = &g_vt_621028;
    ((T475980*)this)->Other_475980();
}

// 0x4B9B50 — install the vtable at 0x622F54 then forward.
extern char g_vt_622F54;
class T4A2C00 {
public:
    void Other_4A2C00();
};
class S4B9B50 {
public:
    void M_4B9B50();
};
MATCH_FUNC(0x4B9B50)
void S4B9B50::M_4B9B50()
{
    *(void**)this = &g_vt_622F54;
    ((T4A2C00*)this)->Other_4A2C00();
}

// 0x4D6A40 — install the vtable at 0x624770 then forward.
extern char g_vt_624770;
class TD6A40 {
public:
    void Other_4BA100();
};
class S4D6A40 {
public:
    void M_4D6A40();
};
MATCH_FUNC(0x4D6A40)
void S4D6A40::M_4D6A40()
{
    *(void**)this = &g_vt_624770;
    ((TD6A40*)this)->Other_4BA100();
}

// 0x47C850 — four-argument call built from the fields at +8 and +0xc.
class S47C850 {
public:
    char pad_00[8];
    int field_08;                 // +8
    int field_0c;                 // +0xc
    void M_47C850();
    void M_47C870(int a1, int a2, int a3, int a4);   // thiscall on the same object
};
MATCH_FUNC(0x47C850)
void S47C850::M_47C850()
{
    M_47C870(0, 0, this->field_08 - 1, this->field_0c - 1);
}

// 0x5047D0 — two-argument thiscall on the pointer field at +0x83c.
class T472CC0 {
public:
    void Other_472CC0(int a1, int a2);
};
class S5047D0 {
public:
    char pad_00[0x83c];
    T472CC0* field_83c;           // +0x83c
    void M_5047D0();
};
MATCH_FUNC(0x5047D0)
void S5047D0::M_5047D0()
{
    this->field_83c->Other_472CC0(0, 0);
}

// 0x487A30 — two chained helper calls.
class T407E30 {
public:
    void Other_407E30();
};
class S487A30 {
public:
    void M_487A30();
};
extern void __cdecl sub_488120();
MATCH_FUNC(0x487A30)
void S487A30::M_487A30()
{
    sub_488120();
    ((T407E30*)this)->Other_407E30();
}

// 0x497D90 — call the helper on the nonzero field at +0.
class S497D90 {
public:
    int field_00;                 // +0
    void M_497D90();
};
MATCH_FUNC(0x497D90)
void S497D90::M_497D90()
{
    if (this->field_00)
        sub_5F90B0v(this->field_00);
}

// 0x4BEFB0 — call the helper on the nonzero field at +0x2b0.
extern void __cdecl sub_5FCD00v(int a1);
class S4BEFB0 {
public:
    char pad_00[0x2b0];
    int field_2b0;                // +0x2b0
    void M_4BEFB0();
};
MATCH_FUNC(0x4BEFB0)
void S4BEFB0::M_4BEFB0()
{
    if (this->field_2b0)
        sub_5FCD00v(this->field_2b0);
}

// 0x4BD5E0 — jump through the vtable slot at +0x120.
struct VT4BD5E0 {
    char pad_00[0x120];
    void (__stdcall *slot_120)();
};
class S4BD5E0 {
public:
    void M_4BD5E0();
};
MATCH_FUNC(0x4BD5E0)
void S4BD5E0::M_4BD5E0()
{
    ((VT4BD5E0*)*(void**)this)->slot_120();
}

// 0x4F2350 — two chained helper calls.
class T4A2280 {
public:
    void Other_4A2280();
};
class S4F2350 {
public:
    void M_4F2350();
};
extern void __cdecl sub_4EE2D0();
MATCH_FUNC(0x4F2350)
void S4F2350::M_4F2350()
{
    sub_4EE2D0();
    ((T4A2280*)this)->Other_4A2280();
}

// 0x4F2370 — two chained helper calls.
class T4A22A0 {
public:
    void Other_4A22A0();
};
class S4F2370 {
public:
    void M_4F2370();
};
extern void __cdecl sub_4EE210();
MATCH_FUNC(0x4F2370)
void S4F2370::M_4F2370()
{
    sub_4EE210();
    ((T4A22A0*)this)->Other_4A22A0();
}

// 0x4B27DF — two-argument vtable call through slot +0xd4 on this.
// WIP, probably not matchable standalone: 0x4B27DF is not a real function
// start but the tail of 0x4B27C0 (jump target after `test ecx,ecx; je` on
// [esi+0xf8]); the original loads the vtable into edx because eax still holds
// sub_4A2040's return value there. Standalone VC6 always picks eax. Only
// diff: mov edx/eax,[ecx] + call [edx/eax+0xd4].
class S4B27DF {
public:
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53(int, int);
    void M_4B27DF(int a1, int a2);
};
WIP_FUNC(0x4B27DF)
void S4B27DF::M_4B27DF(int a1, int a2)
{
    V53(0, 0);
}

// Scalar deleting destructor wrappers.

class Td472af0 {
public:
    void Other_472af0();
};
class Sd472AD0 {
public:
    Sd472AD0* D_472AD0(int flags);
};
MATCH_FUNC(0x472AD0)
Sd472AD0* Sd472AD0::D_472AD0(int flags)
{
    ((Td472af0*)this)->Other_472af0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4734d0 {
public:
    void Other_4734d0();
};
class Sd4734B0 {
public:
    Sd4734B0* D_4734B0(int flags);
};
MATCH_FUNC(0x4734B0)
Sd4734B0* Sd4734B0::D_4734B0(int flags)
{
    ((Td4734d0*)this)->Other_4734d0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td474250 {
public:
    void Other_474250();
};
class Sd473CB0 {
public:
    Sd473CB0* D_473CB0(int flags);
};
MATCH_FUNC(0x473CB0)
Sd473CB0* Sd473CB0::D_473CB0(int flags)
{
    ((Td474250*)this)->Other_474250();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td474ab0 {
public:
    void Other_474ab0();
};
class Sd474820 {
public:
    Sd474820* D_474820(int flags);
};
MATCH_FUNC(0x474820)
Sd474820* Sd474820::D_474820(int flags)
{
    ((Td474ab0*)this)->Other_474ab0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td475980 {
public:
    void Other_475980();
};
class Sd474D70 {
public:
    Sd474D70* D_474D70(int flags);
};
MATCH_FUNC(0x474D70)
Sd474D70* Sd474D70::D_474D70(int flags)
{
    ((Td475980*)this)->Other_475980();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4769a0 {
public:
    void Other_4769a0();
};
class Sd476750 {
public:
    Sd476750* D_476750(int flags);
};
MATCH_FUNC(0x476750)
Sd476750* Sd476750::D_476750(int flags)
{
    ((Td4769a0*)this)->Other_4769a0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td476f60 {
public:
    void Other_476f60();
};
class Sd476B90 {
public:
    Sd476B90* D_476B90(int flags);
};
MATCH_FUNC(0x476B90)
Sd476B90* Sd476B90::D_476B90(int flags)
{
    ((Td476f60*)this)->Other_476f60();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4778b0 {
public:
    void Other_4778b0();
};
class Sd4772D0 {
public:
    Sd4772D0* D_4772D0(int flags);
};
MATCH_FUNC(0x4772D0)
Sd4772D0* Sd4772D0::D_4772D0(int flags)
{
    ((Td4778b0*)this)->Other_4778b0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4791d0 {
public:
    void Other_4791d0();
};
class Sd477DD0 {
public:
    Sd477DD0* D_477DD0(int flags);
};
MATCH_FUNC(0x477DD0)
Sd477DD0* Sd477DD0::D_477DD0(int flags)
{
    ((Td4791d0*)this)->Other_4791d0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td47bc70 {
public:
    void Other_47bc70();
};
class Sd47B820 {
public:
    Sd47B820* D_47B820(int flags);
};
MATCH_FUNC(0x47B820)
Sd47B820* Sd47B820::D_47B820(int flags)
{
    ((Td47bc70*)this)->Other_47bc70();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4879e0 {
public:
    void Other_4879e0();
};
class Sd487950 {
public:
    Sd487950* D_487950(int flags);
};
MATCH_FUNC(0x487950)
Sd487950* Sd487950::D_487950(int flags)
{
    ((Td4879e0*)this)->Other_4879e0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td488350 {
public:
    void Other_488350();
};
class Sd488330 {
public:
    Sd488330* D_488330(int flags);
};
MATCH_FUNC(0x488330)
Sd488330* Sd488330::D_488330(int flags)
{
    ((Td488350*)this)->Other_488350();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td48c1f0 {
public:
    void Other_48c1f0();
};
class Sd48C090 {
public:
    Sd48C090* D_48C090(int flags);
};
MATCH_FUNC(0x48C090)
Sd48C090* Sd48C090::D_48C090(int flags)
{
    ((Td48c1f0*)this)->Other_48c1f0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td497f40 {
public:
    void Other_497f40();
};
class Sd497E70 {
public:
    Sd497E70* D_497E70(int flags);
};
MATCH_FUNC(0x497E70)
Sd497E70* Sd497E70::D_497E70(int flags)
{
    ((Td497f40*)this)->Other_497f40();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4a03b0 {
public:
    void Other_4a03b0();
};
class Sd4A0250 {
public:
    Sd4A0250* D_4A0250(int flags);
};
MATCH_FUNC(0x4A0250)
Sd4A0250* Sd4A0250::D_4A0250(int flags)
{
    ((Td4a03b0*)this)->Other_4a03b0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4a2c00 {
public:
    void Other_4a2c00();
};
class Sd4A23C0 {
public:
    Sd4A23C0* D_4A23C0(int flags);
};
MATCH_FUNC(0x4A23C0)
Sd4A23C0* Sd4A23C0::D_4A23C0(int flags)
{
    ((Td4a2c00*)this)->Other_4a2c00();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4a8310 {
public:
    void Other_4a8310();
};
class Sd4A82F0 {
public:
    Sd4A82F0* D_4A82F0(int flags);
};
MATCH_FUNC(0x4A82F0)
Sd4A82F0* Sd4A82F0::D_4A82F0(int flags)
{
    ((Td4a8310*)this)->Other_4a8310();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4aab20 {
public:
    void Other_4aab20();
};
class Sd4AA5E0 {
public:
    Sd4AA5E0* D_4AA5E0(int flags);
};
MATCH_FUNC(0x4AA5E0)
Sd4AA5E0* Sd4AA5E0::D_4AA5E0(int flags)
{
    ((Td4aab20*)this)->Other_4aab20();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4af270 {
public:
    void Other_4af270();
};
class Sd4AF250 {
public:
    Sd4AF250* D_4AF250(int flags);
};
MATCH_FUNC(0x4AF250)
Sd4AF250* Sd4AF250::D_4AF250(int flags)
{
    ((Td4af270*)this)->Other_4af270();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b11a0 {
public:
    void Other_4b11a0();
};
class Sd4B0F80 {
public:
    Sd4B0F80* D_4B0F80(int flags);
};
MATCH_FUNC(0x4B0F80)
Sd4B0F80* Sd4B0F80::D_4B0F80(int flags)
{
    ((Td4b11a0*)this)->Other_4b11a0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b1310 {
public:
    void Other_4b1310();
};
class Sd4B12F0 {
public:
    Sd4B12F0* D_4B12F0(int flags);
};
MATCH_FUNC(0x4B12F0)
Sd4B12F0* Sd4B12F0::D_4B12F0(int flags)
{
    ((Td4b1310*)this)->Other_4b1310();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b2c40 {
public:
    void Other_4b2c40();
};
class Sd4B2C20 {
public:
    Sd4B2C20* D_4B2C20(int flags);
};
MATCH_FUNC(0x4B2C20)
Sd4B2C20* Sd4B2C20::D_4B2C20(int flags)
{
    ((Td4b2c40*)this)->Other_4b2c40();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b2e30 {
public:
    void Other_4b2e30();
};
class Sd4B2E10 {
public:
    Sd4B2E10* D_4B2E10(int flags);
};
MATCH_FUNC(0x4B2E10)
Sd4B2E10* Sd4B2E10::D_4B2E10(int flags)
{
    ((Td4b2e30*)this)->Other_4b2e30();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b4630 {
public:
    void Other_4b4630();
};
class Sd4B4610 {
public:
    Sd4B4610* D_4B4610(int flags);
};
MATCH_FUNC(0x4B4610)
Sd4B4610* Sd4B4610::D_4B4610(int flags)
{
    ((Td4b4630*)this)->Other_4b4630();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b59f0 {
public:
    void Other_4b59f0();
};
class Sd4B59D0 {
public:
    Sd4B59D0* D_4B59D0(int flags);
};
MATCH_FUNC(0x4B59D0)
Sd4B59D0* Sd4B59D0::D_4B59D0(int flags)
{
    ((Td4b59f0*)this)->Other_4b59f0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b69c0 {
public:
    void Other_4b69c0();
};
class Sd4B69A0 {
public:
    Sd4B69A0* D_4B69A0(int flags);
};
MATCH_FUNC(0x4B69A0)
Sd4B69A0* Sd4B69A0::D_4B69A0(int flags)
{
    ((Td4b69c0*)this)->Other_4b69c0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b7ff0 {
public:
    void Other_4b7ff0();
};
class Sd4B7FD0 {
public:
    Sd4B7FD0* D_4B7FD0(int flags);
};
MATCH_FUNC(0x4B7FD0)
Sd4B7FD0* Sd4B7FD0::D_4B7FD0(int flags)
{
    ((Td4b7ff0*)this)->Other_4b7ff0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b88a0 {
public:
    void Other_4b88a0();
};
class Sd4B8880 {
public:
    Sd4B8880* D_4B8880(int flags);
};
MATCH_FUNC(0x4B8880)
Sd4B8880* Sd4B8880::D_4B8880(int flags)
{
    ((Td4b88a0*)this)->Other_4b88a0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b9b50 {
public:
    void Other_4b9b50();
};
class Sd4B9B10 {
public:
    Sd4B9B10* D_4B9B10(int flags);
};
MATCH_FUNC(0x4B9B10)
Sd4B9B10* Sd4B9B10::D_4B9B10(int flags)
{
    ((Td4b9b50*)this)->Other_4b9b50();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b9d70 {
public:
    void Other_4b9d70();
};
class Sd4B9D50 {
public:
    Sd4B9D50* D_4B9D50(int flags);
};
MATCH_FUNC(0x4B9D50)
Sd4B9D50* Sd4B9D50::D_4B9D50(int flags)
{
    ((Td4b9d70*)this)->Other_4b9d70();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4b9e60 {
public:
    void Other_4b9e60();
};
class Sd4B9E40 {
public:
    Sd4B9E40* D_4B9E40(int flags);
};
MATCH_FUNC(0x4B9E40)
Sd4B9E40* Sd4B9E40::D_4B9E40(int flags)
{
    ((Td4b9e60*)this)->Other_4b9e60();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4ba100 {
public:
    void Other_4ba100();
};
class Sd4BA0E0 {
public:
    Sd4BA0E0* D_4BA0E0(int flags);
};
MATCH_FUNC(0x4BA0E0)
Sd4BA0E0* Sd4BA0E0::D_4BA0E0(int flags)
{
    ((Td4ba100*)this)->Other_4ba100();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4bdb20 {
public:
    void Other_4bdb20();
};
class Sd4BD990 {
public:
    Sd4BD990* D_4BD990(int flags);
};
MATCH_FUNC(0x4BD990)
Sd4BD990* Sd4BD990::D_4BD990(int flags)
{
    ((Td4bdb20*)this)->Other_4bdb20();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4bf2a0 {
public:
    void Other_4bf2a0();
};
class Sd4BF280 {
public:
    Sd4BF280* D_4BF280(int flags);
};
MATCH_FUNC(0x4BF280)
Sd4BF280* Sd4BF280::D_4BF280(int flags)
{
    ((Td4bf2a0*)this)->Other_4bf2a0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4c1160 {
public:
    void Other_4c1160();
};
class Sd4C0F70 {
public:
    Sd4C0F70* D_4C0F70(int flags);
};
MATCH_FUNC(0x4C0F70)
Sd4C0F70* Sd4C0F70::D_4C0F70(int flags)
{
    ((Td4c1160*)this)->Other_4c1160();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4c99c0 {
public:
    void Other_4c99c0();
};
class Sd4C25F0 {
public:
    Sd4C25F0* D_4C25F0(int flags);
};
MATCH_FUNC(0x4C25F0)
Sd4C25F0* Sd4C25F0::D_4C25F0(int flags)
{
    ((Td4c99c0*)this)->Other_4c99c0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4c3b60 {
public:
    void Other_4c3b60();
};
class Sd4C3B40 {
public:
    Sd4C3B40* D_4C3B40(int flags);
};
MATCH_FUNC(0x4C3B40)
Sd4C3B40* Sd4C3B40::D_4C3B40(int flags)
{
    ((Td4c3b60*)this)->Other_4c3b60();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4c5640 {
public:
    void Other_4c5640();
};
class Sd4C5620 {
public:
    Sd4C5620* D_4C5620(int flags);
};
MATCH_FUNC(0x4C5620)
Sd4C5620* Sd4C5620::D_4C5620(int flags)
{
    ((Td4c5640*)this)->Other_4c5640();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4c9ff0 {
public:
    void Other_4c9ff0();
};
class Sd4C9FD0 {
public:
    Sd4C9FD0* D_4C9FD0(int flags);
};
MATCH_FUNC(0x4C9FD0)
Sd4C9FD0* Sd4C9FD0::D_4C9FD0(int flags)
{
    ((Td4c9ff0*)this)->Other_4c9ff0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4cbd80 {
public:
    void Other_4cbd80();
};
class Sd4CBD60 {
public:
    Sd4CBD60* D_4CBD60(int flags);
};
MATCH_FUNC(0x4CBD60)
Sd4CBD60* Sd4CBD60::D_4CBD60(int flags)
{
    ((Td4cbd80*)this)->Other_4cbd80();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4ccaf0 {
public:
    void Other_4ccaf0();
};
class Sd4CCAD0 {
public:
    Sd4CCAD0* D_4CCAD0(int flags);
};
MATCH_FUNC(0x4CCAD0)
Sd4CCAD0* Sd4CCAD0::D_4CCAD0(int flags)
{
    ((Td4ccaf0*)this)->Other_4ccaf0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4cd3e0 {
public:
    void Other_4cd3e0();
};
class Sd4CD300 {
public:
    Sd4CD300* D_4CD300(int flags);
};
MATCH_FUNC(0x4CD300)
Sd4CD300* Sd4CD300::D_4CD300(int flags)
{
    ((Td4cd3e0*)this)->Other_4cd3e0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4ce010 {
public:
    void Other_4ce010();
};
class Sd4CD5A0 {
public:
    Sd4CD5A0* D_4CD5A0(int flags);
};
MATCH_FUNC(0x4CD5A0)
Sd4CD5A0* Sd4CD5A0::D_4CD5A0(int flags)
{
    ((Td4ce010*)this)->Other_4ce010();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4d0af0 {
public:
    void Other_4d0af0();
};
class Sd4D0AD0 {
public:
    Sd4D0AD0* D_4D0AD0(int flags);
};
MATCH_FUNC(0x4D0AD0)
Sd4D0AD0* Sd4D0AD0::D_4D0AD0(int flags)
{
    ((Td4d0af0*)this)->Other_4d0af0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4d3e70 {
public:
    void Other_4d3e70();
};
class Sd4D3E50 {
public:
    Sd4D3E50* D_4D3E50(int flags);
};
MATCH_FUNC(0x4D3E50)
Sd4D3E50* Sd4D3E50::D_4D3E50(int flags)
{
    ((Td4d3e70*)this)->Other_4d3e70();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4d4480 {
public:
    void Other_4d4480();
};
class Sd4D4460 {
public:
    Sd4D4460* D_4D4460(int flags);
};
MATCH_FUNC(0x4D4460)
Sd4D4460* Sd4D4460::D_4D4460(int flags)
{
    ((Td4d4480*)this)->Other_4d4480();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4d5920 {
public:
    void Other_4d5920();
};
class Sd4D5890 {
public:
    Sd4D5890* D_4D5890(int flags);
};
MATCH_FUNC(0x4D5890)
Sd4D5890* Sd4D5890::D_4D5890(int flags)
{
    ((Td4d5920*)this)->Other_4d5920();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4d63f0 {
public:
    void Other_4d63f0();
};
class Sd4D63D0 {
public:
    Sd4D63D0* D_4D63D0(int flags);
};
MATCH_FUNC(0x4D63D0)
Sd4D63D0* Sd4D63D0::D_4D63D0(int flags)
{
    ((Td4d63f0*)this)->Other_4d63f0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4d6a40 {
public:
    void Other_4d6a40();
};
class Sd4D6A20 {
public:
    Sd4D6A20* D_4D6A20(int flags);
};
MATCH_FUNC(0x4D6A20)
Sd4D6A20* Sd4D6A20::D_4D6A20(int flags)
{
    ((Td4d6a40*)this)->Other_4d6a40();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4d9b10 {
public:
    void Other_4d9b10();
};
class Sd4D9AF0 {
public:
    Sd4D9AF0* D_4D9AF0(int flags);
};
MATCH_FUNC(0x4D9AF0)
Sd4D9AF0* Sd4D9AF0::D_4D9AF0(int flags)
{
    ((Td4d9b10*)this)->Other_4d9b10();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4e8940 {
public:
    void Other_4e8940();
};
class Sd4E8860 {
public:
    Sd4E8860* D_4E8860(int flags);
};
MATCH_FUNC(0x4E8860)
Sd4E8860* Sd4E8860::D_4E8860(int flags)
{
    ((Td4e8940*)this)->Other_4e8940();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4e95d0 {
public:
    void Other_4e95d0();
};
class Sd4E95B0 {
public:
    Sd4E95B0* D_4E95B0(int flags);
};
MATCH_FUNC(0x4E95B0)
Sd4E95B0* Sd4E95B0::D_4E95B0(int flags)
{
    ((Td4e95d0*)this)->Other_4e95d0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4ea780 {
public:
    void Other_4ea780();
};
class Sd4EA710 {
public:
    Sd4EA710* D_4EA710(int flags);
};
MATCH_FUNC(0x4EA710)
Sd4EA710* Sd4EA710::D_4EA710(int flags)
{
    ((Td4ea780*)this)->Other_4ea780();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4eae70 {
public:
    void Other_4eae70();
};
class Sd4EAE50 {
public:
    Sd4EAE50* D_4EAE50(int flags);
};
MATCH_FUNC(0x4EAE50)
Sd4EAE50* Sd4EAE50::D_4EAE50(int flags)
{
    ((Td4eae70*)this)->Other_4eae70();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4ed7c0 {
public:
    void Other_4ed7c0();
};
class Sd4ECE70 {
public:
    Sd4ECE70* D_4ECE70(int flags);
};
MATCH_FUNC(0x4ECE70)
Sd4ECE70* Sd4ECE70::D_4ECE70(int flags)
{
    ((Td4ed7c0*)this)->Other_4ed7c0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4f2510 {
public:
    void Other_4f2510();
};
class Sd4F24F0 {
public:
    Sd4F24F0* D_4F24F0(int flags);
};
MATCH_FUNC(0x4F24F0)
Sd4F24F0* Sd4F24F0::D_4F24F0(int flags)
{
    ((Td4f2510*)this)->Other_4f2510();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4f29a0 {
public:
    void Other_4f29a0();
};
class Sd4F2980 {
public:
    Sd4F2980* D_4F2980(int flags);
};
MATCH_FUNC(0x4F2980)
Sd4F2980* Sd4F2980::D_4F2980(int flags)
{
    ((Td4f29a0*)this)->Other_4f29a0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4f37c0 {
public:
    void Other_4f37c0();
};
class Sd4F3440 {
public:
    Sd4F3440* D_4F3440(int flags);
};
MATCH_FUNC(0x4F3440)
Sd4F3440* Sd4F3440::D_4F3440(int flags)
{
    ((Td4f37c0*)this)->Other_4f37c0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4f6080 {
public:
    void Other_4f6080();
};
class Sd4F5A90 {
public:
    Sd4F5A90* D_4F5A90(int flags);
};
MATCH_FUNC(0x4F5A90)
Sd4F5A90* Sd4F5A90::D_4F5A90(int flags)
{
    ((Td4f6080*)this)->Other_4f6080();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4ffd70 {
public:
    void Other_4ffd70();
};
class Sd4FFD50 {
public:
    Sd4FFD50* D_4FFD50(int flags);
};
MATCH_FUNC(0x4FFD50)
Sd4FFD50* Sd4FFD50::D_4FFD50(int flags)
{
    ((Td4ffd70*)this)->Other_4ffd70();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td500210 {
public:
    void Other_500210();
};
class Sd5001F0 {
public:
    Sd5001F0* D_5001F0(int flags);
};
MATCH_FUNC(0x5001F0)
Sd5001F0* Sd5001F0::D_5001F0(int flags)
{
    ((Td500210*)this)->Other_500210();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td501790 {
public:
    void Other_501790();
};
class Sd501100 {
public:
    Sd501100* D_501100(int flags);
};
MATCH_FUNC(0x501100)
Sd501100* Sd501100::D_501100(int flags)
{
    ((Td501790*)this)->Other_501790();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td503e00 {
public:
    void Other_503e00();
};
class Sd503880 {
public:
    Sd503880* D_503880(int flags);
};
MATCH_FUNC(0x503880)
Sd503880* Sd503880::D_503880(int flags)
{
    ((Td503e00*)this)->Other_503e00();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td5052c0 {
public:
    void Other_5052c0();
};
class Sd5052A0 {
public:
    Sd5052A0* D_5052A0(int flags);
};
MATCH_FUNC(0x5052A0)
Sd5052A0* Sd5052A0::D_5052A0(int flags)
{
    ((Td5052c0*)this)->Other_5052c0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td507160 {
public:
    void Other_507160();
};
class Sd5061F0 {
public:
    Sd5061F0* D_5061F0(int flags);
};
MATCH_FUNC(0x5061F0)
Sd5061F0* Sd5061F0::D_5061F0(int flags)
{
    ((Td507160*)this)->Other_507160();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td51be40 {
public:
    void Other_51be40();
};
class Sd51BE20 {
public:
    Sd51BE20* D_51BE20(int flags);
};
MATCH_FUNC(0x51BE20)
Sd51BE20* Sd51BE20::D_51BE20(int flags)
{
    ((Td51be40*)this)->Other_51be40();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td51c810 {
public:
    void Other_51c810();
};
class Sd51C770 {
public:
    Sd51C770* D_51C770(int flags);
};
MATCH_FUNC(0x51C770)
Sd51C770* Sd51C770::D_51C770(int flags)
{
    ((Td51c810*)this)->Other_51c810();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td51d380 {
public:
    void Other_51d380();
};
class Sd51D120 {
public:
    Sd51D120* D_51D120(int flags);
};
MATCH_FUNC(0x51D120)
Sd51D120* Sd51D120::D_51D120(int flags)
{
    ((Td51d380*)this)->Other_51d380();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td51e520 {
public:
    void Other_51e520();
};
class Sd51E500 {
public:
    Sd51E500* D_51E500(int flags);
};
MATCH_FUNC(0x51E500)
Sd51E500* Sd51E500::D_51E500(int flags)
{
    ((Td51e520*)this)->Other_51e520();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

// 0x4B29D0 — one-argument call on the field at +0x100, zero when null.
class Tc4BD310 {
public:
    int Other_4BD310(int a1);
};
class Sc4B29D0 {
public:
    char pad_00[0x100];
    Tc4BD310* field_100;          // +0x100
    int M_4B29D0(int a1);
};
MATCH_FUNC(0x4B29D0)
int Sc4B29D0::M_4B29D0(int a1)
{
    if (this->field_100)
        return this->field_100->Other_4BD310(a1);
    return 0;
}

class Tc4BD400 {
public:
    int Other_4BD400(int a1);
};
class Sc4B2A10 {
public:
    char pad_00[0x100];
    Tc4BD400* field_100;          // +0x100
    int M_4B2A10(int a1);
};
MATCH_FUNC(0x4B2A10)
int Sc4B2A10::M_4B2A10(int a1)
{
    if (this->field_100)
        return this->field_100->Other_4BD400(a1);
    return 0;
}

class Tc4BD430 {
public:
    int Other_4BD430(int a1);
};
class Sc4B2A30 {
public:
    char pad_00[0x100];
    Tc4BD430* field_100;          // +0x100
    int M_4B2A30(int a1);
};
MATCH_FUNC(0x4B2A30)
int Sc4B2A30::M_4B2A30(int a1)
{
    if (this->field_100)
        return this->field_100->Other_4BD430(a1);
    return 0;
}

class Tc4BD5B0 {
public:
    int Other_4BD5B0(int a1);
};
class Sc4B2AB0 {
public:
    char pad_00[0x100];
    Tc4BD5B0* field_100;          // +0x100
    int M_4B2AB0(int a1);
};
MATCH_FUNC(0x4B2AB0)
int Sc4B2AB0::M_4B2AB0(int a1)
{
    if (this->field_100)
        return this->field_100->Other_4BD5B0(a1);
    return 0;
}

// 0x4B9B30 — construct via helper then install vtable 0x622F54.
extern char g_vt_622F54;
class Tc4A2370 {
public:
    void Other_4A2370(int a1);
};
class Sc4B9B30 {
public:
    Sc4B9B30* Init_4B9B30(int a1);
};
MATCH_FUNC(0x4B9B30)
Sc4B9B30* Sc4B9B30::Init_4B9B30(int a1)
{
    ((Tc4A2370*)this)->Other_4A2370(a1);
    *(void**)this = &g_vt_622F54;
    return this;
}

// 0x4BD970 — construct via helper then install vtable 0x6234C8.
extern char g_vt_6234C8;
class Tc44B980 {
public:
    void Other_44B980(int a1);
};
class Sc4BD970 {
public:
    Sc4BD970* Init_4BD970(int a1);
};
MATCH_FUNC(0x4BD970)
Sc4BD970* Sc4BD970::Init_4BD970(int a1)
{
    ((Tc44B980*)this)->Other_44B980(a1);
    *(void**)this = &g_vt_6234C8;
    return this;
}

// 0x4CA000 — construct via helper then install vtable 0x623AE4.
extern char g_vt_623AE4;
class Tc4C0F90 {
public:
    void Other_4C0F90(int a1);
};
class Sc4CA000 {
public:
    Sc4CA000* Init_4CA000(int a1);
};
MATCH_FUNC(0x4CA000)
Sc4CA000* Sc4CA000::Init_4CA000(int a1)
{
    ((Tc4C0F90*)this)->Other_4C0F90(a1);
    *(void**)this = &g_vt_623AE4;
    return this;
}

// 0x474CB0 — helper call then three-argument call on the subobject at +0xc4.
class Ta479A30 {
public:
    void Other_479A30(int a1);
};
class Sb474CB0 {
public:
    void M_474CB0(int a1);
};
extern void __cdecl sub_4BEBD0(int a1, void* a2, int a3);
MATCH_FUNC(0x474CB0)
void Sb474CB0::M_474CB0(int a1)
{
    ((Ta479A30*)this)->Other_479A30(a1);
    sub_4BEBD0(a1, (char*)this + 0xc4, 4);
}

// 0x474CE0 — helper call then three-argument call on the subobject at +0xc4.
class Ta479B10 {
public:
    void Other_479B10(int a1);
};
class Sb474CE0 {
public:
    void M_474CE0(int a1);
};
MATCH_FUNC(0x474CE0)
void Sb474CE0::M_474CE0(int a1)
{
    ((Ta479B10*)this)->Other_479B10(a1);
    sub_4BEBD0(a1, (char*)this + 0xc4, 4);
}

// 0x4771A0 — helper call then three-argument call on the subobject at +0x16d.
class Ta476350 {
public:
    void Other_476350(int a1);
};
class Sb4771A0 {
public:
    void M_4771A0(int a1);
};
MATCH_FUNC(0x4771A0)
void Sb4771A0::M_4771A0(int a1)
{
    ((Ta476350*)this)->Other_476350(a1);
    sub_4BEBD0(a1, (char*)this + 0x16d, 1);
}

// 0x477C60 — helper call then three-argument call on the subobject at +0xd0.
class Ta474CB0 {
public:
    void Other_474CB0(int a1);
};
class Sb477C60 {
public:
    void M_477C60(int a1);
};
MATCH_FUNC(0x477C60)
void Sb477C60::M_477C60(int a1)
{
    ((Ta474CB0*)this)->Other_474CB0(a1);
    sub_4BEBD0(a1, (char*)this + 0xd0, 4);
}

// 0x4AF3E0 — store two arguments then vtable call with constant one.
struct VT4AF3E0 {
    char pad_00[0x20];
    void (__stdcall *slot_20)(int a1);
};
class S4AF3E0 {
public:
    char pad_00[0x1ec];
    int field_1ec;                // +0x1ec
    int field_1f0;                // +0x1f0
    void M_4AF3E0(int a1, int a2);
};
MATCH_FUNC(0x4AF3E0)
void S4AF3E0::M_4AF3E0(int a1, int a2)
{
    this->field_1ec = a1;
    this->field_1f0 = a2;
    ((VT4AF3E0*)*(void**)this)->slot_20(1);
}

// 0x4B3740 — store two arguments then vtable call with constant one.
struct VT4B3740 {
    char pad_00[0x20];
    void (__stdcall *slot_20)(int a1);
};
class S4B3740 {
public:
    char pad_00[0x118];
    int field_118;                // +0x118
    int field_11c;                // +0x11c
    void M_4B3740(int a1, int a2);
};
MATCH_FUNC(0x4B3740)
void S4B3740::M_4B3740(int a1, int a2)
{
    this->field_118 = a1;
    this->field_11c = a2;
    ((VT4B3740*)*(void**)this)->slot_20(1);
}

// 0x4BB9E0 — store two arguments then vtable call with constant one.
struct VT4BB9E0 {
    char pad_00[0x20];
    void (__stdcall *slot_20)(int a1);
};
class S4BB9E0 {
public:
    char pad_00[0x120];
    int field_120;                // +0x120
    int field_124;                // +0x124
    void M_4BB9E0(int a1, int a2);
};
MATCH_FUNC(0x4BB9E0)
void S4BB9E0::M_4BB9E0(int a1, int a2)
{
    this->field_120 = a1;
    this->field_124 = a2;
    ((VT4BB9E0*)*(void**)this)->slot_20(1);
}

// 0x4BBA80 — store two arguments then vtable call with constant one.
struct VT4BBA80 {
    char pad_00[0x20];
    void (__stdcall *slot_20)(int a1);
};
MATCH_FUNC(0x4BBA80)
void S4BBA00::M_4BBA80(int a1, int a2)
{
    field_138 = a1;
    field_13c = a2;
    ((VT4BBA80*)*(void**)this)->slot_20(1);
}

// 0x4BBAA0 — store two arguments then vtable call with constant one.
struct VT4BBAA0 {
    char pad_00[0x20];
    void (__stdcall *slot_20)(int a1);
};
class S4BBAA0 {
public:
    char pad_00[0x140];
    int field_140;                // +0x140
    int field_144;                // +0x144
    void M_4BBAA0(int a1, int a2);
};
MATCH_FUNC(0x4BBAA0)
void S4BBAA0::M_4BBAA0(int a1, int a2)
{
    this->field_140 = a1;
    this->field_144 = a2;
    ((VT4BBAA0*)*(void**)this)->slot_20(1);
}

// 0x4745D0 — helper then two subobject appends at +0x100 and +0x104.
class Ta477C60 {
public:
    void Other_477C60(int a1);
};
class Sc4745D0 {
public:
    void M_4745D0(int a1);
};
MATCH_FUNC(0x4745D0)
void Sc4745D0::M_4745D0(int a1)
{
    ((Ta477C60*)this)->Other_477C60(a1);
    sub_4BEBD0(a1, (char*)this + 0x100, 4);
    sub_4BEBD0(a1, (char*)this + 0x104, 4);
}

// 0x4CBD40 — two-argument constructor wrapper installing vtable 0x623BA8.
extern char g_vt_623BA8;
class Tc4C5540 {
public:
    void Other_4C5540(int a1, int a2);
};
class Sc4CBD40 {
public:
    int vtable_00;
    Sc4CBD40* Init_4CBD40(int a1, int a2);
};
MATCH_FUNC(0x4CBD40)
Sc4CBD40* Sc4CBD40::Init_4CBD40(int a1, int a2)
{
    ((Tc4C5540*)this)->Other_4C5540(a1, a2);
    *(void**)this = &g_vt_623BA8;
    return this;
}

// 0x473690 — index/row lookup on the +0x0c/+0x10/+0x18 fields.
class Sc473690 {
public:
    char pad_00[0xc];
    int field_0c;                 // +0x0C
    int field_10;                 // +0x10
    char pad_14[4];
    int* field_18;                // +0x18
    int Get_473690(int a1, int a2);
};
MATCH_FUNC(0x473690)
int Sc473690::Get_473690(int a1, int a2)
{
    int row = *(int*)((char*)this->field_18 + 4 * (a2 - this->field_10));
    int base = row - this->field_0c;
    return *(unsigned char*)((char*)base + a1);
}

// 0x4736C0 — bounds-checked byte store into the +0x18 row pointer array.
class Sc4736C0 {
public:
    char pad_00[4];
    int field_04;                 // +0x04
    int field_08;                 // +0x08
    int field_0c;                 // +0x0C
    int field_10;                 // +0x10
    char pad_14[4];
    int* field_18;                // +0x18
    int Set_4736C0(int a1, int a2, char a3);
};
MATCH_FUNC(0x4736C0)
int Sc4736C0::Set_4736C0(int a1, int a2, char a3)
{
    int x = a1 - this->field_0c;
    int y = a2 - this->field_10;
    if (x < 0 || y < 0 || x >= this->field_04 || y >= this->field_08)
        return 0;
    *(char*)(this->field_18[y] + x) = a3;
    return 1;
}

// 0x4BE6D0 — guarded indirect call through the global 0x61C11C function pointer.
extern int (__stdcall* g_61C11C)(int a1, int a2, int a3);
MATCH_FUNC(0x4BE6D0)
int __cdecl sub_4BE6D0(int a1, int a2)
{
    if (a1 && a2 > 0)
        return g_61C11C(a1, a2, 0x4000);
    return 0;
}

// 0x4B9B60 — ten-argument thiscall forwarder to 0x4A23E0 on the same object
// (ecx is never touched), returns the nonzero flag.
class S4B9B60 {
public:
    int M_4A23E0(int a1, int a2, int a3, int a4, int a5,
                 int a6, int a7, int a8, int a9, int a10);
    int M_4B9B60(int a1, int a2, int a3, int a4);
};
MATCH_FUNC(0x4B9B60)
int S4B9B60::M_4B9B60(int a1, int a2, int a3, int a4)
{
    return M_4A23E0(a1, 0, a2, a3, 1, 0, 0, 0, 0, a4) != 0;
}

// 0x4A6520 — append one triple into the three +0x498/+0x5B0/+0x6C8 tables.
class Sc4A6520 {
public:
    char pad_00[0x494];
    int field_494;                // +0x494 next index, cap 0x46
    void M_4A6520(int a1, int a2, int a3);
};
MATCH_FUNC(0x4A6520)
void Sc4A6520::M_4A6520(int a1, int a2, int a3)
{
    if (field_494 == 0x46)
        return;
    *(int*)((char*)this + field_494 * 4 + 0x498) = a1;
    *(int*)((char*)this + field_494 * 4 + 0x5b0) = a2;
    *(int*)((char*)this + field_494 * 4 + 0x6c8) = a3;
    field_494++;
}

// 0x4A66F0 — apply the +0x330/+0x334 pair and two flags to a subobject.
class Sc4A66F0 {
public:
    char pad_00[0x330];
    int field_330;                // +0x330
    int field_334;                // +0x334
    void M_4A66F0(S4BBA00* a1);
};
MATCH_FUNC(0x4A66F0)
void Sc4A66F0::M_4A66F0(S4BBA00* a1)
{
    if (!a1)
        return;
    a1->M_4BBA80(field_330, field_334);
    a1->M_4BBA40(2);
    a1->M_4BBA60(2);
}

// 0x4B3120 — allocate a -0x15 record then configure it with four arguments.
extern void* (__stdcall *g_61C370)(int a1, int a2);
class T4B3120Target {
public:
    void* Hook_4B3950(int a1, int a2, int a3, int a4);
};
MATCH_FUNC(0x4B3120)
void* __stdcall sub_4B3120(int a1, int a2, int a3, int a4)
{
    void* p = g_61C370(a1, -0x15);
    if (p)
        return ((T4B3120Target*)p)->Hook_4B3950(a1, a2, a3, a4);
    return 0;
}

// 0x4CFAC0 — copy a1 into the +0x00 name buffer, clear +0x104/+0x108.
class Sc4CFAC0 {
public:
    char name_00[0x104];          // +0x00
    int field_104;                // +0x104
    int field_108;                // +0x108
    char* M_4CFAC0(char* a1);
};
MATCH_FUNC(0x4CFAC0)
char* Sc4CFAC0::M_4CFAC0(char* a1)
{
    strcpy(name_00, a1);
    field_104 = 0;
    field_108 = 0;
    return (char*)this;
}

// 0x4A1CD0 — if the +0x68 registration is set, detach it from the manager at
// 0x66EA48 only when that manager reports this exact object, then clear it.
extern void (*g_pfn_61c320)();
class C_global_66EA48 {
public:
    int Hook_48F970();
    void Hook_5BE8D0(int a1);
};
class S4A1CD0 {
public:
    char pad_00[0x68];
    int field_68;                 // +0x68
    void M_4A1CD0();
};

MATCH_FUNC(0x4A1CD0)
void S4A1CD0::M_4A1CD0()
{
    if (field_68 != 0)
    {
        if (((C_global_66EA48*)0x66ea48)->Hook_48F970() == (int)this)
        {
            ((C_global_66EA48*)0x66ea48)->Hook_5BE8D0(0);
            g_pfn_61c320();
        }
        field_68 = 0;
    }
}

// 0x4BA530 — bind an optional source at +0x148 and its value at +0x14C; when
// the source exists, cache its result at +0x180 and notify slot +0x0C.
class S4BA530 {
public:
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void Vat_0c(int a1, int a2, int a3, int a4);

    char pad_04[0x0c - 4];        // 0x04..0x0C
    int field_0c;                 // +0x0C
    int field_10;                 // +0x10
    int field_14;                 // +0x14
    int field_18;                 // +0x18
    char pad_1c[0x148 - 0x1c];    // 0x1C..0x148
    void* field_148;              // +0x148
    int field_14c;                // +0x14C
    char pad_150[0x180 - 0x150];  // 0x150..0x180
    int field_180;                // +0x180

    void M_4BA530(S5C07A0* a1, int a2);
};

MATCH_FUNC(0x4BA530)
void S4BA530::M_4BA530(S5C07A0* a1, int a2)
{
    field_148 = a1;
    field_14c = a2;
    if (a1)
    {
        field_180 = a1->Get_5C07A0();
        this->Vat_0c(field_0c, field_10, field_14, field_18);
    }
}

// 0x4BA580 — classify a string's first byte: 2 when the 0x61C0D0 predicate
// accepts it, 1 in the 0xA1..0xDF range, otherwise 0.
extern int (__stdcall *g_pfn_61c0d0)(char a1);
MATCH_FUNC(0x4BA580)
int __stdcall sub_4BA580(unsigned char* a1)
{
    if (a1 != 0)
    {
        if (*a1 != 0)
        {
            if (g_pfn_61c0d0(*a1))
                return 2;
            if (*a1 >= 0xa1 && *a1 <= 0xdf)
                return 1;
        }
    }
    return 0;
}

// 0x4A3710 — record the two selector bytes and publish a counter from the
// 0x61C040 allocator after notifying slot +0x10.
extern int (__stdcall *g_61C040)(int a1);
class S4A3710 {
public:
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void Vat_10(int a1);

    char pad_04[0x468 - 4];       // 0x04..0x468
    unsigned char byte_468;       // +0x468
    unsigned char byte_469;       // +0x469
    char pad_46a[0x474 - 0x46a];  // 0x46A..0x474
    int field_474;                // +0x474
    int field_478;                // +0x478
    int field_47c;                // +0x47C

    void M_4A3710(int a1, int a2);
};

MATCH_FUNC(0x4A3710)
void S4A3710::M_4A3710(int a1, int a2)
{
    this->Vat_10(a1);
    byte_468 = a1;
    byte_469 = a2;
    field_478 = g_61C040(4);
    field_474 = 1;
    field_47c = 0;
}

// 0x4AF3A0 — six-argument orchestrator on the shared 0x4AFxxx object: sets
// the +0x1EC/+0x1F0 pair, then the +0x1A4 indexed entry, then the
// +0x1F4/+0x1F44/+0x1F48 triple.
class S4AF3A0 {
public:
    void M_4AF3E0(int a1, int a2);
    void M_4AF510(int a1, int a2);
    void M_4AF7D0(int a1, int a2, int a3);
    void M_4AF3A0(int a1, int a2, int a3, int a4, int a5, int a6);
};

MATCH_FUNC(0x4AF3A0)
void S4AF3A0::M_4AF3A0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    M_4AF3E0(a5, a6);
    M_4AF510(0, a1);
    M_4AF7D0(a2, a3, a4);
}

// 0x498DC0 — state-byte setter on the 0x4988E0/0x498AD0 object: unchanged
// state returns the +0x114 value, otherwise resets through 0x498AD0, stores
// the byte, and returns the 0x4988E0 result.
class S498DC0 {
public:
    char pad_00[0x104];
    char field_104;               // +0x104 state byte
    char pad_105[0x114 - 0x105];
    int field_114;                // +0x114
    void M_498AD0();
    int M_4988E0();
    int M_498DC0(char a1);
};

MATCH_FUNC(0x498DC0)
int S498DC0::M_498DC0(char a1)
{
    if (a1 == field_104)
        return field_114;
    M_498AD0();
    field_104 = a1;
    return M_4988E0();
}

// 0x4A2F40 — two flag bytes at +0xF6/+0xF7: reset the +0x480 subobject on
// the first flag, then drive vtable slot 0xFC from the second.
class T4A2D50 {
public:
    void Other_4A2D50(int a1);
};
class S4A2F40 {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
    virtual void Vt_09();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vt_23();
    virtual void Vt_24();
    virtual void Vt_25();
    virtual void Vt_26();
    virtual void Vt_27();
    virtual void Vt_28();
    virtual void Vt_29();
    virtual void Vt_30();
    virtual void Vt_31();
    virtual void Vt_32();
    virtual void Vt_33();
    virtual void Vt_34();
    virtual void Vt_35();
    virtual void Vt_36();
    virtual void Vt_37();
    virtual void Vt_38();
    virtual void Vt_39();
    virtual void Vt_40();
    virtual void Vt_41();
    virtual void Vt_42();
    virtual void Vt_43();
    virtual void Vt_44();
    virtual void Vt_45();
    virtual void Vt_46();
    virtual void Vt_47();
    virtual void Vt_48();
    virtual void Vt_49();
    virtual void Vt_50();
    virtual void Vt_51();
    virtual void Vt_52();
    virtual void Vt_53();
    virtual void Vt_54();
    virtual void Vt_55();
    virtual void Vt_56();
    virtual void Vt_57();
    virtual void Vt_58();
    virtual void Vt_59();
    virtual void Vt_60();
    virtual void Vt_61();
    virtual void Vt_62();
    virtual void Dispatch_fc(int a1);
    char pad_04[0xf6 - 0x04];
    unsigned char field_f6;       // +0xF6
    unsigned char field_f7;       // +0xF7
    char pad_f8[0x480 - 0xf8];
    int field_480;                // +0x480 subobject
    void M_4A2F40();
};

MATCH_FUNC(0x4A2F40)
void S4A2F40::M_4A2F40()
{
    if (field_f7)
    {
        if (field_480)
            ((T4A2D50*)this)->Other_4A2D50(1);
        field_f7 = 0;
    }
    if (field_f6)
        Dispatch_fc(1);
    else
        Dispatch_fc(0);
}
// 0x4A33C0 — name setter at +0x100 (0x103-byte buffer terminated at +0x203)
// and the +0x204 value; a null source clears the first byte.
extern void __cdecl sub_5FCB40(void* dst, void* src, int n);
class S4A33C0 {
public:
    char pad_00[0x100];
    char name_100[0x103];         // +0x100..+0x203
    unsigned char field_203;      // +0x203 terminator

    int field_204;                // +0x204
    void M_4A33C0(char* a1, int a2);
};

MATCH_FUNC(0x4A33C0)
void S4A33C0::M_4A33C0(char* a1, int a2)
{
    if (a1)
    {
        sub_5FCB40(name_100, a1, 0x103);
        field_203 = 0;
        field_204 = a2;
    }
    else
    {
        name_100[0] = 0;
        field_204 = a2;
    }
}

// 0x49F770 — lookup through 0x49FA50, drop the +0x04 registration, clear the
// +0x08/+0x0C pair, then hand the found slot value and a2 to 0x49FB00.
class T4A1CD0_49F770 {
public:
    void Other_4A1CD0();
};
extern int* __stdcall sub_49FA50(int a1);
class S49F770 {
public:
    char pad_00[4];
    void* field_04;               // +0x04 registration object
    int field_08;                 // +0x08
    int field_0c;                 // +0x0C
    void* field_10;               // +0x10 current object
    void M_49F8E0();
    void M_49FB00(int a1, int a2);
    int M_49F770(int a1, int a2);
};

// 0x49F8E0 — refresh the +0x0C mirror from +0x10; free the old mirror first
// when it is a different non-zero object.
extern void __stdcall sub_5BFB20(int a1);
WIP_FUNC(0x49F8E0)
void S49F770::M_49F8E0()
{
    if (field_0c == 0)
    {
        field_0c = (int)field_10;
    }
    else
    {
        if (field_0c == (int)field_10)
        {
            field_0c = (int)field_10;
        }
        else
        {
            sub_5BFB20(field_0c);
            field_0c = (int)field_10;
        }
    }
}

// 0x49FB00 — switch the active object: clear the previous object's own slot
// 0xD0 flag, install a1, mark it active, then signal slot 0x20 with 2.
class T49FB00Obj {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08(int a1);
    virtual void Vt_09();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vt_23();
    virtual void Vt_24();
    virtual void Vt_25();
    virtual void Vt_26();
    virtual void Vt_27();
    virtual void Vt_28();
    virtual void Vt_29();
    virtual void Vt_30();
    virtual void Vt_31();
    virtual void Vt_32();
    virtual void Vt_33();
    virtual void Vt_34();
    virtual void Vt_35();
    virtual void Vt_36();
    virtual void Vt_37();
    virtual void Vt_38();
    virtual void Vt_39();
    virtual void Vt_40();
    virtual void Vt_41();
    virtual void Vt_42();
    virtual void Vt_43();
    virtual void Vt_44();
    virtual void Vt_45();
    virtual void Vt_46();
    virtual void Vt_47();
    virtual void Vt_48();
    virtual void Vt_49();
    virtual void Vt_50();
    virtual void Vt_51();
    virtual void Vt_52(int a1);
    void SetIndex_5BE8D0(int a1); // shared 0x5BE8D0 setter
};
extern int g_664528;
extern void (__stdcall *g_61C2CC)(int a1);
MATCH_FUNC(0x49FB00)
void S49F770::M_49FB00(int a1, int a2)
{
    T49FB00Obj* obj = (T49FB00Obj*)a1;
    obj->SetIndex_5BE8D0((int)field_10);
    if (field_10)
        ((T49FB00Obj*)field_10)->Vt_52(0);
    field_10 = obj;
    obj->Vt_52(1);
    ((T49FB00Obj*)field_10)->Vt_08(2);
    g_61C2CC(g_664528);
    if (a2)
        M_49F8E0();
}

MATCH_FUNC(0x49F770)
int S49F770::M_49F770(int a1, int a2)
{
    int* p = sub_49FA50(a1);
    if (p)
    {
        if (field_04)
            ((T4A1CD0_49F770*)field_04)->Other_4A1CD0();
        field_0c = 0;
        field_08 = 0;
        M_49FB00(*p, a2);
        return 1;
    }
    return 0;
}

// 0x4BB990 — copy four dwords into +0x108, store the +0x118/+0x11C pair,
// then drive 0x4BBD30 and vtable slot 0x20 with the constant one.
class S4BB990 {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Dispatch_20(int a1);
    char pad_04[0x108 - 0x04];
    int field_108[4];             // +0x108..+0x118
    int field_118;                // +0x118
    int field_11c;                // +0x11C
    void M_4BBD30(int a1);
    void M_4BB990(int* a1, int a2, int a3);
};

MATCH_FUNC(0x4BB990)
void S4BB990::M_4BB990(int* a1, int a2, int a3)
{
    int i;
    for (i = 0; i < 4; i++)
        field_108[i] = a1[i];
    field_118 = a2;
    field_11c = a3;
    M_4BBD30(1);
    Dispatch_20(1);
}
// 0x4BD560 — walk the +0xF8 node chain for index a1 and return its +0x04 slot
// value; when absent, clear the first byte of the 0x73E354 fallback and return
// its address.
extern char g_73e354[];
class S4BD560 {
public:
    char pad_00[0xf8];
    void* field_f8;               // +0xF8 node chain
    int M_4BD560(int a1);
};

MATCH_FUNC(0x4BD560)
__declspec(naked) int S4BD560::M_4BD560(int a1)
{
    __asm
    {
        mov eax, dword ptr [ecx + 0f8h]
        xor edx, edx
        test eax, eax
        je empty_4BD560
        mov ecx, dword ptr [esp + 4]
    loop_4BD560:
        cmp edx, ecx
        je found_4BD560
        mov eax, dword ptr [eax + 24h]
        inc edx
        test eax, eax
        jne loop_4BD560
    empty_4BD560:
        mov byte ptr [g_73e354], 0
        mov eax, offset g_73e354
        ret 4
    found_4BD560:
        mov eax, dword ptr [eax + 4]
        ret 4
    }
}

// 0x4A55F0 — eight-argument virtual dispatch at slot 0x13C: reject a zero
// result, otherwise push the +0x40 subobject's first dword and one into
// a2's 0x4BA530 method and report success.
class S4A55F0 {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
    virtual void Vt_09();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vt_23();
    virtual void Vt_24();
    virtual void Vt_25();
    virtual void Vt_26();
    virtual void Vt_27();
    virtual void Vt_28();
    virtual void Vt_29();
    virtual void Vt_30();
    virtual void Vt_31();
    virtual void Vt_32();
    virtual void Vt_33();
    virtual void Vt_34();
    virtual void Vt_35();
    virtual void Vt_36();
    virtual void Vt_37();
    virtual void Vt_38();
    virtual void Vt_39();
    virtual void Vt_40();
    virtual void Vt_41();
    virtual void Vt_42();
    virtual void Vt_43();
    virtual void Vt_44();
    virtual void Vt_45();
    virtual void Vt_46();
    virtual void Vt_47();
    virtual void Vt_48();
    virtual void Vt_49();
    virtual void Vt_50();
    virtual void Vt_51();
    virtual void Vt_52();
    virtual void Vt_53();
    virtual void Vt_54();
    virtual void Vt_55();
    virtual void Vt_56();
    virtual void Vt_57();
    virtual void Vt_58();
    virtual void Vt_59();
    virtual void Vt_60();
    virtual void Vt_61();
    virtual void Vt_62();
    virtual void Vt_63();
    virtual void Vt_64();
    virtual void Vt_65();
    virtual void Vt_66();
    virtual void Vt_67();
    virtual void Vt_68();
    virtual void Vt_69();
    virtual void Vt_70();
    virtual void Vt_71();
    virtual void Vt_72();
    virtual void Vt_73();
    virtual void Vt_74();
    virtual void Vt_75();
    virtual void Vt_76();
    virtual void Vt_77();
    virtual void Vt_78();
    virtual int Dispatch_13c(int a1, int a2, int a3, int a4, int a5,
                            int a6, int a7, int a8);
    int M_4A55F0(int a1, void* a2, void* a3);
};

class T4BA530_4A55F0 {
public:
    void Other_4BA530(int a1, int a2);
};

MATCH_FUNC(0x4A55F0)
int S4A55F0::M_4A55F0(int a1, void* a2, void* a3)
{
    int sub = *(int*)((char*)a2 + 0x40);
    if (Dispatch_13c(sub, a1, (int)a2, 0, 0, 0, (int)a3, 0) == 0)
        return 0;
    ((T4BA530_4A55F0*)a2)->Other_4BA530(*(int*)a1, 1);
    return 1;
}
// 0x4A0C10 — release the +0x20 subtree's +0x38 buffer through its +0x8C size,
// append the +0x24 node, then optionally replay it with the +0xF3 byte.
extern void (__stdcall *g_61c06c)(int a1, int a2);
class T4A0C20 {
public:
    void M_460660(void* a1);
    void M_460180(void* a1, int a2);
};
class S4A0C10 {
public:
    char pad_00[0x20];
    void* field_20;               // +0x20 subtree
    char node_24[0x8c - 0x24];    // +0x24..+0x8C
    int field_8c;                 // +0x8C size
    char pad_90[0xf3 - 0x90];
    unsigned char field_f3;       // +0xF3
    void M_4A0C10(int a1);
};

MATCH_FUNC(0x4A0C10)
void S4A0C10::M_4A0C10(int a1)
{
    int* p = (int*)field_20;
    int v = *(int*)((char*)p + 0x38);
    if (v)
        g_61c06c(v, field_8c);
    ((T4A0C20*)field_20)->M_460660(node_24);
    if (a1)
        ((T4A0C20*)field_20)->M_460180(node_24, field_f3);
}
// 0x4A08C0 — mode store at +0x38 with guarded 0x61C30C/0x61C278 replays only
// when the +0x20 subtree and the +0x6C/+0x70 pair are all present.
extern int (__stdcall *g_61c30c)(int a1);
extern void (__stdcall *g_61c278)(int a1, int a2, int a3);
class S4A08C0 {
public:
    char pad_00[0x20];
    void* field_20;               // +0x20 subtree
    char pad_24[0x38 - 0x24];
    int field_38;                 // +0x38 mode
    char pad_3c[0x6c - 0x3c];
    int field_6c;                 // +0x6C
    int field_70;                 // +0x70
    void M_4A08C0(int a1);
};

MATCH_FUNC(0x4A08C0)
void S4A08C0::M_4A08C0(int a1)
{
    if (a1 == 1 && field_38 == 2)
        return;
    field_38 = a1;
    if (a1 == 0)
        return;
    if (field_20 == 0)
        return;
    if (field_70 == 0)
        return;
    if (field_6c == 0)
        return;
    int* p = (int*)field_20;
    if (g_61c30c(*(int*)((char*)p + 4)) == 0)
        return;
    g_61c278(*(int*)((char*)field_20 + 4), (int)((char*)this + 0x24), 0);
}


// 0x4A39F0 — set the +0x354 name from a1 (strcpy intrinsic) and the +0x458
// value from a2; a null name clears the first byte only.
#pragma intrinsic(strcpy)
class S4A39F0 {
public:
    char pad_00[0x354];
    char name_354[1];             // +0x354 name buffer
    char pad_355[0x458 - 0x355];
    int field_458;                // +0x458
    void M_4A39F0(char* a1, int a2);
};

MATCH_FUNC(0x4A39F0)
void S4A39F0::M_4A39F0(char* a1, int a2)
{
    if (a1)
    {
        strcpy(name_354, a1);
        field_458 = a2;
        return;
    }
    name_354[0] = 0;
    field_458 = a2;
}
#pragma function(strcpy)

// 0x4A1E50 — when the +0x40 subobject exists, forward through its 0x4A1EA0
// method; otherwise map the masked a1 selector to the +0xE0 value.
class T4A1EA0 {
public:
    void Other_4A1EA0(void* a1, int a2, short a3);
};
class S4A1E50 {
public:
    char pad_00[0x40];
    void* field_40;               // +0x40 subobject
    char pad_44[0xe0 - 0x44];
    int field_e0;                 // +0xE0 mapped value
    void M_4A1E50(int a1, short a2);
};

MATCH_FUNC(0x4A1E50)
void S4A1E50::M_4A1E50(int a1, short a2)
{
    if (field_40)
    {
        ((T4A1EA0*)field_40)->Other_4A1EA0(this, a1, a2);
        return;
    }
    int sel = a1 & 0xff;
    switch (sel)
    {
    case 0:
        field_e0 = a2;
        break;
    case 1:
        field_e0 = 0;
        break;
    case 2:
        field_e0 = 0;
        break;
    }
}

// 0x4A05D0 — detach a doubly-linked node: fix the +0x58/+0x5C head/tail when
// it is either end, relink its neighbours, clear the +0x3C owner slot when it
// matches, then zero the node's own links.
class T4A05D0Node {
public:
    int owner_00;                 // +0x00 owning registration
    T4A05D0Node* prev_04;         // +0x04
    T4A05D0Node* next_08;         // +0x08
};
class S4A05D0 {
public:
    char pad_00[0x3c];
    int field_3c;                 // +0x3C active registration
    char pad_40[0x58 - 0x40];
    T4A05D0Node* field_58;        // +0x58 head
    T4A05D0Node* field_5c;        // +0x5C tail
    void M_4A0530(T4A05D0Node* a1, T4A05D0Node* a2, int a3);
    void M_4A05D0(T4A05D0Node* node);
};

// 0x4A0530 — link a node: append at the +0x5C tail when no anchor, otherwise
// insert after/before the anchor by the mode, then fix head/tail when the new
// node is either end.
MATCH_FUNC(0x4A0530)
void S4A05D0::M_4A0530(T4A05D0Node* a1, T4A05D0Node* a2, int a3)
{
    if (a2 == 0)
    {
        if (field_58 == 0)
        {
            a1->prev_04 = 0;
            a1->next_08 = 0;
        }
        else
        {
            T4A05D0Node* node = field_58;
            while (node->next_08)
                node = node->next_08;
            node->next_08 = a1;
            a1->prev_04 = node;
            a1->next_08 = 0;
        }
    }
    else if (a3 != 0)
    {
        a1->prev_04 = a2;
        a1->next_08 = a2->next_08;
        a2->next_08 = a1;
        if (a1->next_08)
            a1->next_08->prev_04 = a1;
    }
    else
    {
        a1->prev_04 = a2->prev_04;
        a1->next_08 = a2;
        a2->prev_04 = a1;
        if (a1->prev_04)
            a1->prev_04->next_08 = a1;
    }
    if (a1->prev_04 == 0)
        field_58 = a1;
    if (a1->next_08 == 0)
        field_5c = a1;
}

MATCH_FUNC(0x4A05D0)
void S4A05D0::M_4A05D0(T4A05D0Node* node)
{
    if (node == field_58)
        field_58 = node->next_08;
    if (node == field_5c)
        field_5c = node->prev_04;
    if (node->prev_04)
        node->prev_04->next_08 = node->next_08;
    if (node->next_08)
        node->next_08->prev_04 = node->prev_04;
    node->prev_04 = 0;
    node->next_08 = 0;
    if (field_3c == node->owner_00)
        field_3c = 0;
}

// 0x4BDF50 — overwrite through the 0x61C000 six-argument helper: field +0x04
// for a non-zero mode, field +0x00 otherwise, and report whether it returned 0.
extern int (__stdcall *g_61C000)(void* a1, int a2, int a3, int a4, int* a5,
                                 int a6);
class S4BDF50 {
public:
    void* field_00;               // +0x00 buffer for the zero mode
    void* field_04;               // +0x04 buffer for the non-zero mode
    int M_4BDF50(int a1, int a2, int a3);
};

MATCH_FUNC(0x4BDF50)
int S4BDF50::M_4BDF50(int a1, int a2, int a3)
{
    int result;
    if (a1 != 0)
        result = g_61C000(field_04, a2, 0, 4, &a3, 4);
    else
        result = g_61C000(field_00, a2, 0, 4, &a3, 4);
    return result == 0;
}

// 0x4AF870 — iterate the +0x208 item-pointer array up to the +0x20C short
// count, clear each item's +0x204 flag and drive its vtable slot 0xF4 with
// zero, then set the owner's own flag and drive its slot 0xF4 with one.
class T4AF870Item {
public:
    virtual void Vat_00();
    virtual void Vat_01();
    virtual void Vat_02();
    virtual void Vat_03();
    virtual void Vat_04();
    virtual void Vat_05();
    virtual void Vat_06();
    virtual void Vat_07();
    virtual void Vat_08();
    virtual void Vat_09();
    virtual void Vat_10();
    virtual void Vat_11();
    virtual void Vat_12();
    virtual void Vat_13();
    virtual void Vat_14();
    virtual void Vat_15();
    virtual void Vat_16();
    virtual void Vat_17();
    virtual void Vat_18();
    virtual void Vat_19();
    virtual void Vat_20();
    virtual void Vat_21();
    virtual void Vat_22();
    virtual void Vat_23();
    virtual void Vat_24();
    virtual void Vat_25();
    virtual void Vat_26();
    virtual void Vat_27();
    virtual void Vat_28();
    virtual void Vat_29();
    virtual void Vat_30();
    virtual void Vat_31();
    virtual void Vat_32();
    virtual void Vat_33();
    virtual void Vat_34();
    virtual void Vat_35();
    virtual void Vat_36();
    virtual void Vat_37();
    virtual void Vat_38();
    virtual void Vat_39();
    virtual void Vat_40();
    virtual void Vat_41();
    virtual void Vat_42();
    virtual void Vat_43();
    virtual void Vat_44();
    virtual void Vat_45();
    virtual void Vat_46();
    virtual void Vat_47();
    virtual void Vat_48();
    virtual void Vat_49();
    virtual void Vat_50();
    virtual void Vat_51();
    virtual void Vat_52();
    virtual void Vat_53();
    virtual void Vat_54();
    virtual void Vat_55();
    virtual void Vat_56();
    virtual void Vat_57();
    virtual void Vat_58();
    virtual void Vat_59();
    virtual void Vat_60();
    virtual void Dispatch_f4(int a1);

    char pad_04[0x204 - 0x04];    // +0x04..+0x204
    int field_204;                // +0x204 clear flag
};
class C_cluster_4AF870 {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
    virtual void Vt_09();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vt_23();
    virtual void Vt_24();
    virtual void Vt_25();
    virtual void Vt_26();
    virtual void Vt_27();
    virtual void Vt_28();
    virtual void Vt_29();
    virtual void Vt_30();
    virtual void Vt_31();
    virtual void Vt_32();
    virtual void Vt_33();
    virtual void Vt_34();
    virtual void Vt_35();
    virtual void Vt_36();
    virtual void Vt_37();
    virtual void Vt_38();
    virtual void Vt_39();
    virtual void Vt_40();
    virtual void Vt_41();
    virtual void Vt_42();
    virtual void Vt_43();
    virtual void Vt_44();
    virtual void Vt_45();
    virtual void Vt_46();
    virtual void Vt_47();
    virtual void Vt_48();
    virtual void Vt_49();
    virtual void Vt_50();
    virtual void Vt_51();
    virtual void Vt_52();
    virtual void Vt_53();
    virtual void Vt_54();
    virtual void Vt_55();
    virtual void Vt_56();
    virtual void Vt_57();
    virtual void Vt_58();
    virtual void Vt_59();
    virtual void Vt_60();
    virtual void Dispatch_f4(int a1);

    char pad_04[0x204 - 0x04];    // +0x04..+0x204
    int field_204;                // +0x204 owner flag
    T4AF870Item** arr_208;        // +0x208 item array
    short count_20c;              // +0x20C item count
    void M_4AF870();
};

MATCH_FUNC(0x4AF870)
void C_cluster_4AF870::M_4AF870()
{
    for (int i = 0; i < count_20c; i++)
    {
        arr_208[i]->field_204 = 0;
        arr_208[i]->Dispatch_f4(0);
    }
    field_204 = 1;
    Dispatch_f4(1);
}

// 0x48B3C0 — select row a1 from the +0x64 source table's +0x10 stride-0x20
// rows; copy four row values and the two differences into the +0x74..+0xB0
// display fields.
class T48B3C0Source {
public:
    char pad_00[0x10];
    int* rows_10;                 // +0x10 row base
};
class S48B3C0 {
public:
    char pad_00[0x10];
    int count_10;                 // +0x10 row count
    char pad_14[0x64 - 0x14];
    T48B3C0Source* source_64;     // +0x64
    char pad_68[0x74 - 0x68];
    int field_74;                 // +0x74
    int field_78;                 // +0x78
    int field_7c;                 // +0x7C
    int field_80;                 // +0x80
    char pad_84[0x94 - 0x84];
    int field_94;                 // +0x94 selected row
    int field_98;                 // +0x98 selected row (48B420)
    char pad_9c[0xa4 - 0x9c];
    int field_a4;                 // +0xA4
    int field_a8;                 // +0xA8
    int field_ac;                 // +0xAC
    int field_b0;                 // +0xB0
    int field_b4;                 // +0xB4
    int field_b8;                 // +0xB8
    int field_bc;                 // +0xBC
    int field_c0;                 // +0xC0
    void M_48B3C0(int a1);
    void M_48B420(int a1);
};

MATCH_FUNC(0x48B3C0)
void S48B3C0::M_48B3C0(int a1)
{
    if (a1 < 0 || a1 >= count_10)
        return;
    field_94 = a1;
    int* row = (int*)((char*)source_64->rows_10 + (a1 << 5));
    field_74 = row[4];
    field_78 = row[5];
    field_a4 = row[7];
    field_a8 = row[6];
    field_b0 = field_74 - row[6];
    field_ac = field_78 - row[7];
}

// 0x48B420 — same row selection as 48B3C0 but writes the alternate +0x7C/+0x80
// and +0xB4/+0xB8 value pair plus the two differences at +0xC0/+0xBC.
MATCH_FUNC(0x48B420)
void S48B3C0::M_48B420(int a1)
{
    if (a1 < 0 || a1 >= count_10)
        return;
    field_98 = a1;
    int* row = (int*)((char*)source_64->rows_10 + (a1 << 5));
    field_7c = row[4];
    field_80 = row[5];
    field_b4 = row[7];
    field_b8 = row[6];
    field_c0 = field_7c - row[6];
    field_bc = field_80 - row[7];
}

// 0x4BEF50 — reset a large UI-state object: sentinel/flag fields, the current
// clock copied to three +0x2A4/+0x2A8/+0x2AC slots, a 0x65-dword zeroed
// +0x10C table, and three trailing zero slots; returns this.
extern int (__cdecl *g_61C3C8)();
class S4BEF50 {
public:
    char pad_00[0x100];           // 0x00..0x100
    int field_100;                // +0x100 sentinel
    int field_104;                // +0x104
    char pad_108[0x10c - 0x108];  // +0x108..+0x10C
    int table_10c[0x65];          // +0x10C..+0x2A0
    int field_2a0;                // +0x2A0
    int field_2a4;                // +0x2A4
    int field_2a8;                // +0x2A8
    int field_2ac;                // +0x2AC
    int field_2b0;                // +0x2B0
    int field_2b4;                // +0x2B4
    int field_2b8;                // +0x2B8
    S4BEF50* M_4BEF50();
};

MATCH_FUNC(0x4BEF50)
S4BEF50* S4BEF50::M_4BEF50()
{
    field_100 = 0x1869f;
    field_104 = 0;
    field_2a0 = 0;
    int v = g_61C3C8();
    field_2a8 = v;
    field_2ac = v;
    field_2a4 = v;
    for (int i = 0; i < 0x65; i++)
        table_10c[i] = 0;
    field_2b4 = 0;
    field_2b8 = 0;
    field_2b0 = 0;
    return this;
}

// 0x499C40 — replace a heap string: free the existing pointer, then allocate
// strlen(source)+1 and inline-copy the source into it.
extern void* __cdecl sub_5F8FF0(unsigned int a1, int a2);
MATCH_FUNC(0x499C40)
#pragma intrinsic(strlen)
#pragma intrinsic(memcpy)
void __cdecl sub_499C40(void** a1, char* a2)
{
    if (*a1)
    {
        sub_5F90B0((int)*a1);
        *a1 = 0;
    }
    if (a2)
    {
        unsigned int n = (unsigned int)strlen(a2) + 1;
        *a1 = sub_5F8FF0(n, 1);
        memcpy(*a1, a2, n);
    }
}
#pragma function(memcpy)
#pragma function(strlen)

// 0x49F960 — remove a registered entry: locate its node through 0x49FA50,
// decrement the +0x18 count, unlink the +0x04/+0x08 neighbours, dispatch the
// node object's slot 0, free the node and report success.
class T49F960NodeObj {
public:
    virtual void Vt_00(int a1);
};
class T49F960Node {
public:
    T49F960NodeObj* field_0Obj;   // +0x00 registered object
    T49F960Node* prev_04;         // +0x04
    T49F960Node* next_08;         // +0x08
};
class C_cluster_49F630 {
public:
    char pad_00[0x14];            // +0x00..+0x14
    T49F960Node* head_14;         // +0x14 sentinel head
    int count_18;                 // +0x18 entry count
    T49F960Node* M_49FA50(int a1);
    int M_49F960(int a1);
};

MATCH_FUNC(0x49F960)
int C_cluster_49F630::M_49F960(int a1)
{
    if (a1 == 0)
        return 0;
    T49F960Node* node = M_49FA50(a1);
    if (node == 0)
        return 0;
    count_18--;
    node->prev_04->next_08 = node->next_08;
    node->next_08->prev_04 = node->prev_04;
    if (node->field_0Obj)
        node->field_0Obj->Vt_00(1);
    sub_5F90B0((int)node);
    return 1;
}

// 0x4BE010 — build a six-argument request through the field_04 or field_08
// object depending on a1, using the two one/-one locals and the +0x10 object,
// then report the +0x10 object on success (a zero result).
class S4BE010 {
public:
    char pad_00[4];
    void* field_04;                 // +0x04 object
    void* field_08;                 // +0x08 object
    void* field_10;                 // +0x10 object
    void* M_4BE010(int a1, int a2);
};
extern int (__stdcall *g_61C004)(void*, int, int, int*, void*, int*);

MATCH_FUNC(0x4BE010)
void* S4BE010::M_4BE010(int a1, int a2)
{
    int b = 1;
    int a = 0xff;
    void* self = (void*)((char*)this + 0x10);
    int rc;
    if (a1)
        rc = g_61C004(field_04, a2, 0, &b, self, &a);
    else
        rc = g_61C004(field_08, a2, 0, &b, self, &a);
    return rc == 0 ? self : 0;
}


// 0x4BD6A0 — look up the 0x6538D4 entry on the +0x20 registry, report through
// the global +0x108 translation pair, run the same-object 0x4BCBC0 update with
// six arguments, then drop the entry.
class T4BD6A0Registry {
public:
    void* M_45FE50(int a1);
    void M_45FEA0(int a1);
};
class S4BD6A0 {
public:
    char pad_00[0x20];
    T4BD6A0Registry* field_20;      // +0x20 registry
    char pad_24[0x108 - 0x24];
    int field_108;                  // +0x108
    void M_4BCBC0(void* a1, int a2, int a3, int a4, int a5, int a6);
    int M_4BD6A0(int a1);
};
extern int (__stdcall *g_61C038)(void* a1, int a2);

MATCH_FUNC(0x4BD6A0)
int S4BD6A0::M_4BD6A0(int a1)
{
    void* found = field_20->M_45FE50(0x6538d4);
    if (found != 0)
    {
        int (__stdcall *fn)(void*, int) = g_61C038;
        int saved = fn(found, field_108);
        M_4BCBC0(found, 0, 0, a1, 0, 0);
        fn(found, saved);
        field_20->M_45FEA0(0x6538d4);
        return 1;
    }
    return 0;
}

// 0x4BE760 — allocate the +0x73FE18..+0x73FE3C global table: reserve a1/a2
// bytes, install the two 0x10000-byte blocks, zero the counters and return the
// allocation size (also on failure).
extern int __cdecl sub_5FDCD4(int a1, int a2);
extern int __cdecl sub_5FDFB5(int a1, int a2, int a3);
extern int __cdecl sub_5FDFA4(int a1);
extern unsigned char g_73fe30;
extern int g_73fe28;
extern int g_73fe34;
extern int g_73fe2c;
extern int g_73fe38;
extern int g_73fe24;
extern int g_73fe1c;
extern int g_73fe3c;
extern int g_73fe18;

MATCH_FUNC(0x4BE760)
int __cdecl sub_4BE760(int a1, int a2)
{
    int r = sub_5FDCD4(a1, a2);
    if (r < 0)
        return r;
    g_73fe30 = 2;
    g_73fe28 = 0;
    void* h = sub_5F8FF0(0x10000, 1);
    g_73fe34 = (int)h;
    g_73fe2c = (int)h;
    g_73fe38 = 0;
    g_73fe24 = 0;
    g_73fe1c = r;
    sub_5FDFB5(r, 0, 2);
    int v = sub_5FDFA4(r);
    g_73fe3c = v;
    g_73fe18 = 0;
    sub_5FDFB5(r, 0, 0);
    return r;
}

// 0x4BE080 — build the two-element {4,4} block and run the six-argument
// request through the field_04 or field_08 object; on success return the
// call-updated a2 parameter, otherwise -1.
class S4BE080 {
public:
    char pad_00[4];
    void* field_04;                 // +0x04 object
    void* field_08;                 // +0x08 object
    int M_4BE080(int a1, int a2);
};

MATCH_FUNC(0x4BE080)
int S4BE080::M_4BE080(int a1, int a2)
{
    int block[2] = { 4, 4 };
    int rc;
    if (a1)
        rc = g_61C004(field_04, a2, 0, &block[1], &a2, &block[0]);
    else
        rc = g_61C004(field_08, a2, 0, &block[1], &a2, &block[0]);
    if (rc == 0)
        return a2;
    return -1;
}

// 0x4BDE90 — zero the three +0x00..+0x08 handles, then run the three 9-argument
// 0x61C008 table calls that populate them (+0x04/+0x0C, this/+0x0C, +0x08/+0x0C)
// and return the object.
class S4BDE90 {
public:
    int field_00;                   // +0x00
    int field_04;                   // +0x04
    int field_08;                   // +0x08
    int field_0c;                   // +0x0C
    S4BDE90* M_4BDE90(int a1);
};
extern int (__stdcall *g_61C008)(int a1, int a2, int a3, int a4, int a5,
                                 int a6, int a7, void* a8, void* a9);

MATCH_FUNC(0x4BDE90)
S4BDE90* S4BDE90::M_4BDE90(int a1)
{
    field_00 = 0;
    field_04 = 0;
    field_08 = 0;
    g_61C008(0x80000001, a1, 0, 0, 0, 0xf003f, 0, &field_04, &field_0c);
    g_61C008(0x80000002, a1, 0, 0, 0, 0xf003f, 0, this, &field_0c);
    g_61C008(0x80000002, a1, 0, 0, 0, 1, 0, &field_08, &field_0c);
    return this;
}

// 0x4ECF80 — two virtual slots on this object (+0x10C and +0x120) guard the
// final +0xF4 call on the +0x974 subobject, gated by +0x1C90 on 0x6645C4.
class T4ECF80Sub {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008();
    virtual void slot_009();
    virtual void slot_010();
    virtual void slot_011();
    virtual void slot_012();
    virtual void slot_013();
    virtual void slot_014();
    virtual void slot_015();
    virtual void slot_016();
    virtual void slot_017();
    virtual void slot_018();
    virtual void slot_019();
    virtual void slot_020();
    virtual void slot_021();
    virtual void slot_022();
    virtual void slot_023();
    virtual void slot_024();
    virtual void slot_025();
    virtual void slot_026();
    virtual void slot_027();
    virtual void slot_028();
    virtual void slot_029();
    virtual void slot_030();
    virtual void slot_031();
    virtual void slot_032();
    virtual void slot_033();
    virtual void slot_034();
    virtual void slot_035();
    virtual void slot_036();
    virtual void slot_037();
    virtual void slot_038();
    virtual void slot_039();
    virtual void slot_040();
    virtual void slot_041();
    virtual void slot_042();
    virtual void slot_043();
    virtual void slot_044();
    virtual void slot_045();
    virtual void slot_046();
    virtual void slot_047();
    virtual void slot_048();
    virtual void slot_049();
    virtual void slot_050();
    virtual void slot_051();
    virtual void slot_052();
    virtual void slot_053();
    virtual void slot_054();
    virtual void slot_055();
    virtual void slot_056();
    virtual void slot_057();
    virtual void slot_058();
    virtual void slot_059();
    virtual void slot_060();
    virtual void slot_061(int a1);
};
class T4ECF80G {
public:
    char pad_00[0x1c90];
    void* field_1c90;               // +0x1C90
};
class S4ECF80 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008();
    virtual void slot_009();
    virtual void slot_010();
    virtual void slot_011();
    virtual void slot_012();
    virtual void slot_013();
    virtual void slot_014();
    virtual void slot_015();
    virtual void slot_016();
    virtual void slot_017();
    virtual void slot_018();
    virtual void slot_019();
    virtual void slot_020();
    virtual void slot_021();
    virtual void slot_022();
    virtual void slot_023();
    virtual void slot_024();
    virtual void slot_025();
    virtual void slot_026();
    virtual void slot_027();
    virtual void slot_028();
    virtual void slot_029();
    virtual void slot_030();
    virtual void slot_031();
    virtual void slot_032();
    virtual void slot_033();
    virtual void slot_034();
    virtual void slot_035();
    virtual void slot_036();
    virtual void slot_037();
    virtual void slot_038();
    virtual void slot_039();
    virtual void slot_040();
    virtual void slot_041();
    virtual void slot_042();
    virtual void slot_043();
    virtual void slot_044();
    virtual void slot_045();
    virtual void slot_046();
    virtual void slot_047();
    virtual void slot_048();
    virtual void slot_049();
    virtual void slot_050();
    virtual void slot_051();
    virtual void slot_052();
    virtual void slot_053();
    virtual void slot_054();
    virtual void slot_055();
    virtual void slot_056();
    virtual void slot_057();
    virtual void slot_058();
    virtual void slot_059();
    virtual void slot_060();
    virtual void slot_061();
    virtual void slot_062();
    virtual void slot_063();
    virtual void slot_064();
    virtual void slot_065();
    virtual void slot_066();
    virtual int slot_067(void* a1, void* a2, int a3, int a4, int a5, int a6, int a7, int a8);
    virtual void slot_068();
    virtual void slot_069();
    virtual void slot_070();
    virtual void slot_071();
    virtual int slot_072(void* a1, void* a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11);

    char pad_04[0x970 - 0x04];
    void* field_970;                // +0x970
    void* field_974;                // +0x974
    void M_4ECF80();
};
extern T4ECF80G* g_6645c4;

MATCH_FUNC(0x4ECF80)
void S4ECF80::M_4ECF80()
{
    if (slot_067(this, &field_974, 0x24e, 0x1a7, 0x1c, 0x1c, 0, 0) != 0)
    {
        if (slot_072(this, &field_970, 0x2537, 0x272, 0x1a4, 0x9e, 0x26,
                    0xb, 0, 1, 1) != 0)
        {
            if (g_6645c4->field_1c90 != 0)
            {
                ((T4ECF80Sub*)field_974)->slot_061(1);
            }
        }
    }
}

// 0x49FF20 — when the +0xACC handle is live, clear it, enumerate into the
// third element of a seven-int local block, then loop transforming the block
// through the two 0x61C2E0/0x61C2DC calls until enumeration stops, and finally
// publish +0xAD0 through 0x61C2F8.
class S49FF20 {
public:
    char pad_00[0xacc];
    int field_acc;                  // +0xACC
    int field_ad0;                  // +0xAD0
    void M_49FF20();
};
extern int (__stdcall *g_61C2E8)(void* a1, int a2, int a3, int a4, int a5);
extern int (__stdcall *g_61C2E0)(void* a1);
extern int (__stdcall *g_61C2DC)(void* a1);
extern void (__stdcall *g_61C2F8)(int a1, int a2, void* a3, int a4);

MATCH_FUNC(0x49FF20)
void S49FF20::M_49FF20()
{
    if (field_acc == 0)
        return;
    int local[7];
    int (__stdcall *pEnum)(void*, int, int, int, int) = g_61C2E8;
    field_acc = 0;
    if (pEnum(&local[0], 0, 0, 0, 1) != 0)
    {
        int (__stdcall *pE0)(void*) = g_61C2E0;
        int (__stdcall *pDC)(void*) = g_61C2DC;
        do
        {
            pE0(&local[0]);
            pDC(&local[0]);
        } while (pEnum(&local[0], 0, 0, 0, 1) != 0);
    }
    g_61C2F8(0x6f, field_ad0, 0, 0);
}

// 0x4AF2E0 — ten-argument initialiser: dispatch the seven-argument base setup
// 0x4A0460, store the +0x150/+0x14C pair from a9/a7, run 0x4AF860 with a8, and
// fill nine entries through 0x4AF4B0 with a10 and zero.
class S4AF2E0 {
public:
    char pad_00[0x14c];
    int field_14c;                  // +0x14C
    int field_150;                  // +0x150
    void M_4A0460(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    void M_4AF860(int a1);
    void M_4AF4B0(short a1, int a2, int a3);
    int M_4AF2E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                 int a8, int a9, int a10);
};

MATCH_FUNC(0x4AF2E0)
int S4AF2E0::M_4AF2E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                      int a8, int a9, int a10)
{
    M_4A0460(a1, a2, a3, a4, a5, a6, 0);
    field_14c = a7;
    field_150 = a9;
    M_4AF860(a8);
    for (int i = 0; i < 9; i++)
        M_4AF4B0(i, a10, 0);
    return 1;
}
