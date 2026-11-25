// free_app — app-region free functions migrated from Source/simple.
// Sections keep their per-file order so shared class declarations stay ahead
// of every body in the same file. Preambles are carried only when the file's
// first marker lives in another module.
#include "Function.hpp"


extern int g_66d4b0;
extern int g_66d4b4;
extern int g_66d4b8;

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
MATCH_FUNC(0x409E90)
void S409E90::Set_409E90(unsigned char a, int b, unsigned char c,
                         unsigned char d, unsigned char e, unsigned char f)
{
    *(unsigned char*)((char*)this) = a;
    *(int*)((char*)this + 4) = b;
    *(unsigned char*)((char*)this + 8) = c;
    *(unsigned char*)((char*)this + 9) = d;
    *(unsigned char*)((char*)this + 0xa) = e;
    *(unsigned char*)((char*)this + 0xb) = f;
}

class S410530 {
public:
    char pad_00[0x3fc];
    int* field_3fc;
    void Init_410530();
};
MATCH_FUNC(0x410530)
void S410530::Init_410530()
{
    int* p1 = *(int**)((char*)this + 0x3fc);
    *(unsigned char*)p1 = 0;
    int* p2 = *(int**)((char*)this + 0x3fc);
    *(int*)((char*)p2 + 0x104) = -1;
    int* p3 = *(int**)((char*)this + 0x3fc);
    *(unsigned char*)((char*)p3 + 0x108) = 0;
    int* p4 = *(int**)((char*)this + 0x3fc);
    *(int*)((char*)p4 + 0x188) = 0x19;
}

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
MATCH_FUNC(0x416DA0)
void S416DA0::Set_416DA0(int a, int b, int c, int d, int e)
{
    int old34 = field_34;
    int old38 = field_38;
    *(int*)((char*)this + 0x58) = old34;
    *(int*)((char*)this + 0x5c) = old38;
    *(int*)((char*)this + 0x34) = a;
    *(int*)((char*)this + 0x38) = b;
    *(int*)((char*)this + 0x3c) = c;
    *(int*)((char*)this + 0x40) = d;
    *(int*)((char*)this + 0x44) = e;
}

class S40A0D0 {
public:
    S40A0D0* Ref_40A0D0();
};
MATCH_FUNC(0x40A0D0)
S40A0D0* S40A0D0::Ref_40A0D0()
{
    return (S40A0D0*)((char*)this + 0x10);
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

MATCH_FUNC(0x409DE0)
float S409DE0::Get_409DE0()
{
    return *(float*)((char*)this + 0x20);
}
class S409DF0 {
public:
    char pad_00[0x24];
    float Get_409DF0();
};

MATCH_FUNC(0x409DF0)
float S409DF0::Get_409DF0()
{
    return *(float*)((char*)this + 0x24);
}
class S409E00 {
public:
    char pad_00[0x28];
    float Get_409E00();
};

MATCH_FUNC(0x409E00)
float S409E00::Get_409E00()
{
    return *(float*)((char*)this + 0x28);
}
class S40A0E0 {
public:
    char pad_00[0x50];
    float Get_40A0E0();
};

MATCH_FUNC(0x40A0E0)
float S40A0E0::Get_40A0E0()
{
    return *(float*)((char*)this + 0x50);
}
class S40A0F0 {
public:
    char pad_00[0x54];
    float Get_40A0F0();
};

MATCH_FUNC(0x40A0F0)
float S40A0F0::Get_40A0F0()
{
    return *(float*)((char*)this + 0x54);
}
class S40A100 {
public:
    char pad_00[0x58];
    float Get_40A100();
};

MATCH_FUNC(0x40A100)
float S40A100::Get_40A100()
{
    return *(float*)((char*)this + 0x58);
}
class S40A110 {
public:
    char pad_00[0x5c];
    float Get_40A110();
};

MATCH_FUNC(0x40A110)
float S40A110::Get_40A110()
{
    return *(float*)((char*)this + 0x5c);
}
class S40A120 {
public:
    char pad_00[0x60];
    float Get_40A120();
};

MATCH_FUNC(0x40A120)
float S40A120::Get_40A120()
{
    return *(float*)((char*)this + 0x60);
}
class S40A130 {
public:
    char pad_00[0x64];
    float Get_40A130();
};

MATCH_FUNC(0x40A130)
float S40A130::Get_40A130()
{
    return *(float*)((char*)this + 0x64);
}

class S40F4C0 {
public:
    char pad_00[0xea4];
    int Get_40F4C0();
};
MATCH_FUNC(0x40F4C0)
int S40F4C0::Get_40F4C0()
{
    int index = *(int*)((char*)this + 0xea4);
    return *(int*)((char*)this + 0xea4 + index * 4);
}

MATCH_FUNC(0x414300)
void M_414300()
{
}




class S4060A0 {
public:
    char pad_00[8];
    int field_8;
    bool Check_4060A0();
};
// `? true : false` keeps the value in eax (mov/test/setne, no xor eax);
// `!= 0` gives the xor-first form of 0x419810.
MATCH_FUNC(0x4060A0)
bool S4060A0::Check_4060A0()
{
    return this->field_8 ? true : false;
}

class S40F4A0 {
public:
    char pad_00[0xea4];
    int field_ea4;
    bool Check_40F4A0();
};
MATCH_FUNC(0x40F4A0)
bool S40F4A0::Check_40F4A0()
{
    return field_ea4 == 0;
}

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
MATCH_FUNC(0x419810)
bool S419810::Check_419810()
{
    return field_180 != 0;
}
// Batch 18: verified leaf helpers promoted into readable classes.
// Each body starts from Source/autopilot/auto_*.c and is checked byte-for-byte
// against the reference executable with Scripts/match.py.

// 0x40CFB0 — indexed byte field guarded by a related table's entry count.
class S40CFB0Indexed {
public:
    char pad_00[0xf0];
    int field_f0;                // 0xf0 pointer to the owning table
    char pad_f4[0x144 - 0xf4];
    unsigned char entries[0x100]; // 0x144 indexed byte table

    int Set_40CFB0(int index, unsigned char value);
};

MATCH_FUNC(0x40CFB0)
int S40CFB0Indexed::Set_40CFB0(int index, unsigned char value)
{
    int result = index;
    if (index > 0 &&
        index < *(short*)(*(int*)(*(int*)(this->field_f0 + 0xf0) + 0x8c) + 0x48))
        this->entries[index] = value;
    return result;
}

// 0x411940 — clears a 16-entry, 24-byte record table and returns its end.
struct S411940Entry {
    short tag;                   // +0
    int field_04;                // +4
    int field_08;                // +8
    int field_0c;                // +0c
    int field_10;                // +10
};

class S411940Table {
public:
    int field_00;                // 0x00
    int field_04;                // 0x04
    short field_08;              // 0x08
    short field_0a;              // 0x0a
    unsigned char field_0c;      // 0x0c
    unsigned char field_0d;      // 0x0d
    char pad_0e[0x10 - 0x0e];
    int lead_zero;              // 0x10, also the prior record's last field
    S411940Entry entries[16];   // 0x14, stride 0x18

    char* Init_411940();
};

MATCH_FUNC(0x411940)
char* S411940Table::Init_411940()
{
    this->field_08 = -1;
    this->field_00 = 0;
    this->field_04 = 0;
    this->field_0a = -1;
    this->field_0c = 0;
    this->field_0d = 0;
    char* result = (char*)this + 0x14;
    int count = 16;
    do {
        *(int*)(result - 4) = 0;
        *(short*)result = -1;
        *(int*)(result + 4) = 0;
        *(int*)(result + 8) = 0;
        *(int*)(result + 0xc) = 0;
        *(int*)(result + 0x10) = 0;
        result += 0x18;
        --count;
    } while (count);
    return result;
}

// 0x4175B0 — single-state predicate over three fields.
class S4175B0 {
public:
    char pad_00[0x30];
    int field_30;                // 0x30
    char pad_34[0xa0 - 0x34];
    int field_a0;                // 0xa0
    char pad_a4[0x178 - 0xa4];
    unsigned char field_178;     // 0x178

    int Check_4175B0();
};

MATCH_FUNC(0x4175B0)
int S4175B0::Check_4175B0()
{
    if (this->field_178 != 1 || this->field_a0 != 0 || this->field_30 != -1)
        return 0;
    return 1;
}

// 0x41A0D0 / 0x41A110 — stack-built zero triples, returned through an out
// parameter. WIP: the original keeps an explicit 12-byte stack temporary
// (zero stores interleaved with the copy); VC6 /O2 folds every equivalent.
// 41F880 likewise differs: the original is a 31-byte loop with the next
// compare repeated at the top; VC6 emits a duplicated bottom compare.
struct S41A0D0Triple {
    int field_00;
    int field_04;
    int field_08;
};

// 0x41AC00 — find a node by key in a singly linked list and set its byte flag.
struct S41AC00Node {
    char pad_00[4];
    int key;                     // +4
    S41AC00Node* next;           // +8
    unsigned char flag;          // +5? overlaps pad in the original layout
};

class S41AC00List {
public:
    char pad_00[4];
    S41AC00Node* head;           // +4, actually [this+4]

    S41AC00Node* Set_41AC00(int key, unsigned char value);
};

MATCH_FUNC(0x41AC00)
S41AC00Node* S41AC00List::Set_41AC00(int key, unsigned char value)
{
    S41AC00Node* result = this->head;
    while (result) {
        if (*(int*)(*(int*)result + 4) == key) {
            *(unsigned char*)((char*)result + 5) = value;
            break;
        }
        result = *(S41AC00Node**)((char*)result + 8);
    }
    return result;
}

// 0x41B610 — list head present, local flag set, and head->field70 bit 0.
class S41B610 {
public:
    char pad_00[4];
    int field_04;                // 0x04
    char pad_08[0x24 - 0x08];
    unsigned char field_24;      // 0x24

    bool Check_41B610();
};

// 0x41C800 — per-slot 32-byte stats block, accumulate and update high-water.
struct S41C800Stats {
    char pad_00[0x554];
    unsigned accumulated;        // 0x554
    char pad_558[0x568 - 0x558];
    unsigned last;               // 0x568
    unsigned high_water;         // 0x56c
};

class S41C800Table {
public:
    S41C800Stats* Add_41C800(int index, unsigned value);
};

MATCH_FUNC(0x41C800)
S41C800Stats* S41C800Table::Add_41C800(int index, unsigned value)
{
    S41C800Stats* result = (S41C800Stats*)((char*)this + 32 * index);
    result->accumulated += value;
    *(volatile unsigned*)&result->last = value;
    if (value > result->high_water)
        result->high_water = value;
    return result;
}

// 0x41F6A0 — 12-byte record table lookup.
class S41F6A0Table {
public:
    char pad_00[0x20c];
    int records;                 // 0x20c

    void* Entry_41F6A0(int index);
};

MATCH_FUNC(0x41F6A0)
void* S41F6A0Table::Entry_41F6A0(int index)
{
    int v2 = *(int*)((char*)this + 0x20c);
    if (!v2)
        return 0;
    return (void*)(v2 + 12 * index);
}

// 0x41F840 — validated short index into a record's pointer array.
class S41F840Lookup {
public:
    char pad_00[0x41c];
    int records;                 // 0x41c

    int Entry_41F840();
};

MATCH_FUNC(0x41F840)
int S41F840Lookup::Entry_41F840()
{
    int v1 = *(int*)((char*)this + 0x41c);
    if (v1) {
        short count = *(short*)(v1 + 0x48);
        if (count >= 1) {
            short index = *(short*)(v1 + 0x94);
            if (index < count && index >= 0)
                return *(int*)(*(int*)(v1 + 0x4c) + 4 * index);
        }
    }
    return 0;
}

// 0x41F880 — search a fixed nine-entry integer slot set.
class S41F880Slots {
public:
    char pad_00[0x9e4];
    int slots[9];                // 0x9e4

    int Find_41F880(int value);
};

MATCH_FUNC(0x41F880)
int S41F880Slots::Find_41F880(int value)
{
    for (int i = 0; i < 9; ++i) {
        if (value == this->slots[i])
            return i;
    }
    return -1;
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

MATCH_FUNC(0x406170)
int S406170::Get_406170()
{
    int* v1 = this->field_08;
    if (v1)
        return *v1;
    else
        return 0;
}

// 0x410700 — when the first field is 2, clear the second.
class S410700 {
public:
    int field_00;                 // 0x00
    int field_04;                 // 0x04

    void Clear_410700();
};

MATCH_FUNC(0x410700)
void S410700::Clear_410700()
{
    if (this->field_00 == 2)
        this->field_04 = 0;
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
MATCH_FUNC(0x410410)
void S410410::Pop_410410()
{
    int i = field_ea4 - 1;
    field_ea4 = i;
    *(int*)((char*)this + 0x1e0) = array_ea8[i];
}

class S410680 {
public:
    S410680* Init_410680();
};
MATCH_FUNC(0x410680)
S410680* S410680::Init_410680()
{
    int zero = 0;
    *(int*)((char*)this) = zero;
    *(int*)((char*)this + 4) = zero;
    *(int*)((char*)this + 8) = zero;
    *(unsigned char*)((char*)this + 0xc) = zero;
    *(int*)((char*)this + 0x10) = zero;
    *(unsigned char*)((char*)this + 0x14) = zero;
    *(unsigned char*)((char*)this + 0x15) = zero;
    *(unsigned char*)((char*)this + 0x16) = zero;
    *(unsigned char*)((char*)this + 0x17) = zero;
    return this;
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
MATCH_FUNC(0x411900)
S411900* S411900::Init_411900()
{
    field_0 = 0;
    field_4 = 0;
    field_8 = 0xffff;
    field_a = 0xffff;
    field_c = 0;
    field_d = 0;
    for (int i = 0; i < 16; i++) {
        entries_10[i].field_0 = 0;
        entries_10[i].field_4 = 0xffff;
        entries_10[i].field_8 = 0;
        entries_10[i].field_c = 0;
        entries_10[i].field_10 = 0;
        entries_10[i].field_14 = 0;
    }
    return this;
}

class S409E60 {
public:
    unsigned char field_0;
    char pad_01[3];
    void* field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_a;
    unsigned char field_b;
    S409E60* Init_409E60();
};

MATCH_FUNC(0x409E60)
S409E60* S409E60::Init_409E60()
{
    field_0 = 0;
    field_4 = 0;
    field_8 = 0;
    field_9 = 0;
    field_a = 0;
    field_b = 0;
    return this;
}

class S40GetBulk {
public:
    float Get_407C70();
    float Get_407C80();
    int Get_407CA0();
    int Get_407CE0();
    int Get_407CF0();
    int Get_40A320();
    int Get_40A330();
    int Get_40A340();
    int Get_40A350();
    int Get_40A360();
    int Get_40A390();
    int Get_40A400();
    int Get_40A430();
    unsigned char Get_40A460();
    char* Get_40C520();
};

MATCH_FUNC(0x40A320)
int S40GetBulk::Get_40A320()
{
    return *(int*)((char*)this + 0x80);
}

MATCH_FUNC(0x40A330)
int S40GetBulk::Get_40A330()
{
    return *(int*)((char*)this + 0x84);
}

MATCH_FUNC(0x40A340)
int S40GetBulk::Get_40A340()
{
    return *(int*)((char*)this + 0x88);
}

MATCH_FUNC(0x40A350)
int S40GetBulk::Get_40A350()
{
    return *(int*)((char*)this + 0x8c);
}

MATCH_FUNC(0x40A360)
int S40GetBulk::Get_40A360()
{
    return *(int*)((char*)this + 0x90);
}

MATCH_FUNC(0x40A400)
int S40GetBulk::Get_40A400()
{
    return *(int*)((char*)this + 0xa0);
}

MATCH_FUNC(0x40A430)
int S40GetBulk::Get_40A430()
{
    return *(int*)((char*)this + 0xa4);
}

MATCH_FUNC(0x40A460)
unsigned char S40GetBulk::Get_40A460()
{
    return *(unsigned char*)((char*)this + 0xac);
}

MATCH_FUNC(0x40C520)
char* S40GetBulk::Get_40C520()
{
    return (char*)this + 0x1f8;
}

class S40SetImmBulk {
public:
    void Set_407C90();
    void Set_409E80();
    void Set_40A0C0();
};

MATCH_FUNC(0x409E80)
void S40SetImmBulk::Set_409E80()
{
    *(int*)((char*)this + 0x4) = 0x0;
}

class S40SetBulk {
public:
    void SetByte_409E10(unsigned char v);
    void SetInt_40A150(int v);
    void SetInt_40A160(int v);
    void SetInt_40A170(int v);
    void SetInt_40A180(int v);
    void SetInt_40A3A0(int v);
    void SetInt_40A3B0(int v);
    void SetInt_40A3C0(int v);
    void SetInt_40A420(int v);
    void SetInt_40A440(int v);
    void SetInt_40A450(int v);
    void SetByte_40A470(unsigned char v);
    void SetInt_40B650(int v);
    void SetInt_40B660(int v);
    void SetInt_40B6A0(int v);
    void SetInt_40CBC0(int v);
};

MATCH_FUNC(0x409E10)
void S40SetBulk::SetByte_409E10(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x3c) = v;
}

MATCH_FUNC(0x40A150)
void S40SetBulk::SetInt_40A150(int v)
{
    *(int*)((char*)this + 0x50) = v;
}

MATCH_FUNC(0x40A160)
void S40SetBulk::SetInt_40A160(int v)
{
    *(int*)((char*)this + 0x54) = v;
}

MATCH_FUNC(0x40A170)
void S40SetBulk::SetInt_40A170(int v)
{
    *(int*)((char*)this + 0x58) = v;
}

MATCH_FUNC(0x40A180)
void S40SetBulk::SetInt_40A180(int v)
{
    *(int*)((char*)this + 0x68) = v;
}

MATCH_FUNC(0x40A3A0)
void S40SetBulk::SetInt_40A3A0(int v)
{
    *(int*)((char*)this + 0x80) = v;
}

MATCH_FUNC(0x40A3B0)
void S40SetBulk::SetInt_40A3B0(int v)
{
    *(int*)((char*)this + 0x84) = v;
}

MATCH_FUNC(0x40A3C0)
void S40SetBulk::SetInt_40A3C0(int v)
{
    *(int*)((char*)this + 0x88) = v;
}

MATCH_FUNC(0x40A420)
void S40SetBulk::SetInt_40A420(int v)
{
    *(int*)((char*)this + 0xa0) = v;
}

MATCH_FUNC(0x40A440)
void S40SetBulk::SetInt_40A440(int v)
{
    *(int*)((char*)this + 0xa4) = v;
}

MATCH_FUNC(0x40A450)
void S40SetBulk::SetInt_40A450(int v)
{
    *(int*)((char*)this + 0xa8) = v;
}

MATCH_FUNC(0x40A470)
void S40SetBulk::SetByte_40A470(unsigned char v)
{
    *(unsigned char*)((char*)this + 0xac) = v;
}

MATCH_FUNC(0x40B650)
void S40SetBulk::SetInt_40B650(int v)
{
    *(int*)((char*)this + 0x74) = v;
}

MATCH_FUNC(0x40B660)
void S40SetBulk::SetInt_40B660(int v)
{
    *(int*)((char*)this + 0x78) = v;
}

MATCH_FUNC(0x40B6A0)
void S40SetBulk::SetInt_40B6A0(int v)
{
    *(int*)((char*)this + 0x7c) = v;
}

MATCH_FUNC(0x40CBC0)
void S40SetBulk::SetInt_40CBC0(int v)
{
    *(int*)((char*)this + 0xf0) = v;
}

class S4118C0 {
public:
    char pad_00[0xc];
    int array_c[(0x6c - 0xc) / 4];
    int count_6c;
    int Get_4118C0(int index);
};

MATCH_FUNC(0x4118C0)
int S4118C0::Get_4118C0(int index)
{
    if (index < 0 || index >= count_6c)
        return -1;
    return array_c[index];
}

// Family at 0x412BE0: a pair of "active" fields at +0x28/+0x30 with a saved
// copy at +0x50/+0x54. Each setter first snapshots the active value into the
// saved slot, then stores the new value.
class S412BE0 {
public:
    char pad_00[0x28 - 0x00];
    int field_28;             // +0x28
    int field_2c;             // +0x2c (unused here)
    int field_30;             // +0x30
    char pad_34[0x50 - 0x34];
    int field_50;             // +0x50 saved copy of field_28
    int field_54;             // +0x54 saved copy of field_30

    void M_412BE0(int v);
    void M_412BF0(int v);
};

MATCH_FUNC(0x412BE0)
void S412BE0::M_412BE0(int v)
{
    field_50 = field_28;
    field_28 = v;
}

MATCH_FUNC(0x412BF0)
void S412BE0::M_412BF0(int v)
{
    field_54 = field_30;
    field_30 = v;
}

class S41A420 {
public:
    void* vtbl_0;
    int field_4;
    int field_8;
    S41A420* Init_41A420(int v);
};

MATCH_FUNC(0x41A420)
S41A420* S41A420::Init_41A420(int v)
{
    vtbl_0 = (void*)0x61ddb0;
    field_4 = 0;
    field_8 = v;
    return this;
}

// Family at 0x41C860: a table of 32-byte entries starting at +0x554. The
// three dword getters and the setter all index the same entry array:
//   entry+0x00 -> this+0x554 (M_41C8C0)
//   entry+0x04 -> this+0x558 (M_41C880)
//   entry+0x14 -> this+0x568 (M_41C8A0, written by M_41C860)
struct Entry32_554 {
    int field_0;              // +0x00
    int field_4;              // +0x04
    char pad_08[0x14 - 0x08];
    int field_14;             // +0x14
    char pad_18[0x20 - 0x18];
};

class S41C860 {
public:
    char pad_00[0x554];
    Entry32_554 entries[1];   // +0x554

    int M_41C8C0(int index);
    int M_41C880(int index);
    int M_41C8A0(int index);
    void M_41C860(int index, int value);
};

MATCH_FUNC(0x41C8C0)
int S41C860::M_41C8C0(int index)
{
    return entries[index].field_0;
}

MATCH_FUNC(0x41C880)
int S41C860::M_41C880(int index)
{
    return entries[index].field_4;
}

MATCH_FUNC(0x41C8A0)
int S41C860::M_41C8A0(int index)
{
    return entries[index].field_14;
}

MATCH_FUNC(0x41C860)
void S41C860::M_41C860(int index, int value)
{
    entries[index].field_14 = value;
}

// Family at 0x41CE50: three forwards on the pointer field at +0x1c. Null gives
// -1 (M_41CE50) or 0 (M_41CE60); the arg-taking variant just forwards.
class T5BFBF0 {
public:
    int Other_5BFBF0();
};
class T464FD0 {
public:
    int Other_464FD0();
};
class T464D90 {
public:
    void Other_464D90(int v);
};

class S41CE50 {
public:
    char pad_00[0x1c - 0x00];
    char* field_1c;           // +0x1c

    int M_41CE50();
    int M_41CE60();
    void M_41CE70(int v);
};

MATCH_FUNC(0x41CE50)
int S41CE50::M_41CE50()
{
    if (field_1c == 0)
        return -1;
    return ((T5BFBF0*)field_1c)->Other_5BFBF0();
}

MATCH_FUNC(0x41CE60)
int S41CE50::M_41CE60()
{
    if (field_1c == 0)
        return 0;
    return ((T464FD0*)field_1c)->Other_464FD0();
}

MATCH_FUNC(0x41CE70)
void S41CE50::M_41CE70(int v)
{
    if (field_1c != 0)
        ((T464D90*)field_1c)->Other_464D90(v);
}

class S41GetBulk {
public:
    int Get_411590();
    int Get_41A060(int a,int b,int c,int d);
    int Get_41C8E0();
};

MATCH_FUNC(0x41C8E0)
int S41GetBulk::Get_41C8E0()
{
    return *(int*)((char*)this + 0x540);
}

class S41SetImmBulk {
public:
    void Set_4106A0();
    void Set_411420();
};

MATCH_FUNC(0x4106A0)
void S41SetImmBulk::Set_4106A0()
{
    *(int*)((char*)this + 0x10) = 0x0;
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
MATCH_FUNC(0x40A140)
int S40A140::Get_40A140()
{
    return *(int*)((char*)this + 0x68);
}
MATCH_FUNC(0x40A310)
int S40A310::Get_40A310()
{
    return *(int*)((char*)this + 0x74);
}
MATCH_FUNC(0x40B630)
int S40B630::Get_40B630()
{
    return *(int*)((char*)this + 0x78);
}
MATCH_FUNC(0x40B640)
int S40B640::Get_40B640()
{
    return *(int*)((char*)this + 0x7c);
}
MATCH_FUNC(0x412BD0)
int S412BD0::Get_412BD0()
{
    return *(int*)((char*)this + 0x28);
}
MATCH_FUNC(0x412C00)
int S412C00::Get_412C00()
{
    return *(int*)((char*)this + 0x34);
}
MATCH_FUNC(0x412C10)
int S412C10::Get_412C10()
{
    return *(int*)((char*)this + 0x38);
}
MATCH_FUNC(0x412C20)
int S412C20::Get_412C20()
{
    return *(int*)((char*)this + 0x5c);
}
MATCH_FUNC(0x409F40)
int S409F40::Get_409F40()
{
    return *(unsigned char*)((char*)this + 0x0);
}
MATCH_FUNC(0x4107E0)
int S4107E0::Get_4107E0()
{
    return *(unsigned char*)((char*)this + 0xc);
}

// sub_405860 (VA 0x405860) - member: walks the list at +8 and calls virtual
// slot 0x10 on each node's object at +0.
struct N405860 {
    char* obj_0;
    N405860* next_4;
};
class T405860 {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vat_10();
};
class S405860 {
public:
    char pad_00[8];
    N405860* field_8;
    void M_405860();
};

MATCH_FUNC(0x405860)
void S405860::M_405860()
{
    N405860* n = field_8;
    while (n != 0) {
        ((T405860*)n->obj_0)->Vat_10();
        n = n->next_4;
    }
}

// sub_4061B0 (VA 0x4061B0, 0xB bytes) - member getter: reads the pointer at
// +8, then the pointer in its first dword, then its +0x30 dword; 0 if null.
class S4061B0 {
public:
    int M_4061B0();
};

MATCH_FUNC(0x4061B0)
int S4061B0::M_4061B0()
{
    char* obj = *(char**)((char*)this + 8);
    if (obj != 0)
        return *(int*)(*(char**)obj + 0x30);
    return 0;
}

// sub_40B680 (VA 0x40B680, 0xF bytes) - member: decrements field_7c, clamped
// at 0.
class S40B680 {
public:
    void M_40B680();
};

MATCH_FUNC(0x40B680)
void S40B680::M_40B680()
{
    int* f = (int*)this;
    if (--f[0x7c / 4] < 0)
        f[0x7c / 4] = 0;
}

// sub_40E270 (VA 0x40E270) - member: element index of the pointer array at
// +8, bounded by the signed word count at +6; out of range returns the global
// object 0x662BE4.
extern char g_662BE4;
class S40E270 {
public:
    char pad_00[6];
    short count_6;
    char** items_8;
    char* M_40E270(int index);
};

MATCH_FUNC(0x40E270)
char* S40E270::M_40E270(int index)
{
    if (index < 0 || index >= count_6)
        return (char*)&g_662BE4;
    return items_8[index];
}

// sub_40E2A0 (VA 0x40E2A0, 0xB bytes) - member getter: signed word at
// [+0x28]->+8, or -1 when the +0x28 pointer is null.
class S40E2A0 {
public:
    int M_40E2A0();
};

MATCH_FUNC(0x40E2A0)
int S40E2A0::M_40E2A0()
{
    char* p = *(char**)((char*)this + 0x28);
    if (p == 0)
        return -1;
    return (int)*(short*)(p + 8);
}

// sub_40E600 (VA 0x40E600, 0x15 bytes) - member: when the +0x28 object
// exists, clears its +4 dword and returns 1 (0 otherwise).
class S40E600 {
public:
    int M_40E600();
};

MATCH_FUNC(0x40E600)
int S40E600::M_40E600()
{
    char* p = *(char**)((char*)this + 0x28);
    if (p == 0)
        return 0;
    *(int*)(p + 4) = 0;
    return 1;
}

// sub_410500 (VA 0x410500) - member: appends field_1e0 to the array at +0xea8
// using the count at +0xea4, then bumps the count.
class S410500 {
public:
    char pad_00[0x1e0];
    int field_1e0;
    char pad_1e4[0xea4 - 0x1e4];
    int count_ea4;
    int arr_ea8[1];

    void M_410500();
};

MATCH_FUNC(0x410500)
void S410500::M_410500()
{
    arr_ea8[count_ea4] = field_1e0;
    count_ea4++;
}

// sub_4106F0 (VA 0x4106F0, 0xF bytes) - member: when state at +0 is 3, calls
// the member-function pointer at +0x10 and stores its result at +8.
class S4106F0 {
public:
    int state_0;              // +0x00
    char pad_04[0x08 - 0x04];
    int field_8;              // +0x08
    char pad_0C[0x10 - 0x0C];
    int (S4106F0::*fn_10)();  // +0x10

    void M_4106F0();
};

MATCH_FUNC(0x4106F0)
void S4106F0::M_4106F0()
{
    if (state_0 == 3)
        field_8 = (this->*fn_10)();
}

// sub_411AF0 (VA 0x411AF0) - member: writes -1 into entry (b + 10*a) of an
// int table that starts one entry before +0x00 (-0x28 bytes).
class S411AF0 {
public:
    void M_411AF0(int a, int b);
};

MATCH_FUNC(0x411AF0)
void S411AF0::M_411AF0(int a, int b)
{
    int idx = b + a * 10;
    *(int*)((char*)this + idx * 4 - 0x28) = -1;
}

// sub_41F5F0 (VA 0x41F5F0, 0x11 bytes) - member: calls the global function
// pointer 0x61C2F4 with (field_28, 0x10, 0, 0).
extern void (__stdcall *g_61C2F4)(int, int, int, int);
class S41F5F0 {
public:
    void M_41F5F0();
};

MATCH_FUNC(0x41F5F0)
void S41F5F0::M_41F5F0()
{
    g_61C2F4(*(int*)((char*)this + 0x28), 0x10, 0, 0);
}

class S41F6C0 {
public:
    int M_41F6C0(int index);
};

MATCH_FUNC(0x41F6C0)
int S41F6C0::M_41F6C0(int index)
{    int* p = *(int**)((char*)this + 0x7c);
    if (p == 0) { return 0; }
    return p[index];
}

// sub_41F6E0 (VA 0x41F6E0) - member getter over the int array at +0x8c, bounded
// by the signed word count at +0x88; 0 when null/out of range.
class S41F6E0 {
public:
    char pad_00[0x88];
    short count_88;
    int* arr_8c;
    int M_41F6E0(int i);
};

MATCH_FUNC(0x41F6E0)
int S41F6E0::M_41F6E0(int i)
{
    if (arr_8c == 0 || i < 0 || i >= count_88)
        return 0;
    return arr_8c[i];
}

// Small app-region increment members.
class S40A3D0 {
public:
    char pad_00[0x88];
    int count_88;

    void Inc_40A3D0();
};
MATCH_FUNC(0x40A3D0)
void S40A3D0::Inc_40A3D0()
{
    ++count_88;
}

class S40A410 {
public:
    char pad_00[0xa0];
    int count_a0;

    void Inc_40A410();
};
MATCH_FUNC(0x40A410)
void S40A410::Inc_40A410()
{
    ++count_a0;
}

class S40B670 {
public:
    char pad_00[0x7c];
    int count_7c;

    void Inc_40B670();
};
MATCH_FUNC(0x40B670)
void S40B670::Inc_40B670()
{
    ++count_7c;
}

class S41C840 {
public:
    char pad_00[0x534];
    int count_534;

    void Inc_41C840();
};
MATCH_FUNC(0x41C840)
void S41C840::Inc_41C840()
{
    ++count_534;
}

class S41C850 {
public:
    char pad_00[0x538];
    int count_538;

    void Inc_41C850();
};
MATCH_FUNC(0x41C850)
void S41C850::Inc_41C850()
{
    ++count_538;
}

// 0x41CF60 — tail-forward through the pointer at +0x1c.
class T465010 {
public:
    void Other_465010();
};

class S41CF60 {
public:
    char pad_00[0x1c];
    T465010* field_1c;

    void M_41CF60();
};
MATCH_FUNC(0x41CF60)
void S41CF60::M_41CF60()
{
    field_1c->Other_465010();
}

// 0x40EB90 — free __cdecl forwarding call with one argument.
class T40DE50 {
public:
    int Other_40DE50(int a2);
};
class S40EB90 {
public:
    int M_40EB90(int a2);
};
MATCH_FUNC(0x40EB90)
int S40EB90::M_40EB90(int a2)
{
    return ((T40DE50*)this)->Other_40DE50(a2);
}

// 0x41F8A0 — pass the window handle at +0x28 to the global API slot.
extern int (__stdcall *g_61C2CC)(void* hwnd);
class S41F8A0 {
public:
    char pad_00[0x28];
    void* hwnd_28;

    int M_41F8A0();
};
MATCH_FUNC(0x41F8A0)
int S41F8A0::M_41F8A0()
{
    return g_61C2CC(*(void**)((char*)this + 0x28));
}

// 0x41FAA0 — forward an int through the object at +0x1e8.
class T48B3C0 {
public:
    int Other_48B3C0(int a1);
};
class S41FAA0 {
public:
    char pad_00[0x1e8];
    T48B3C0* field_1e8;

    int M_41FAA0(int a1);
};
MATCH_FUNC(0x41FAA0)
int S41FAA0::M_41FAA0(int a1)
{
    return field_1e8->Other_48B3C0(a1);
}

// 0x41B000 — char accessor on the pointer at +4, 20 when absent.
class T526430 {
public:
    char Other_526430();
};
class S41B000 {
public:
    char pad_00[4];
    T526430* field_4;

    char M_41B000();
};
MATCH_FUNC(0x41B000)
char S41B000::M_41B000()
{
    if (field_4)
        return field_4->Other_526430();
    return 20;
}

// 0x41B010 — int accessor on the pointer at +4, 0 when absent.
class T5267D0 {
public:
    int Other_5267D0();
};
class S41B010 {
public:
    char pad_00[4];
    T5267D0* field_4;

    int M_41B010();
};
MATCH_FUNC(0x41B010)
int S41B010::M_41B010()
{
    if (field_4)
        return field_4->Other_5267D0();
    return 0;
}

// 0x4013E0 — install the vtable at 0x61C524 and forward to 0x409630.
extern void sub_409630();
class S4013E0 {
public:
    void M_4013E0();
};
MATCH_FUNC(0x4013E0)
void S4013E0::M_4013E0()
{
    *(void**)this = (void*)0x61C524;
    sub_409630();
}

// 0x402EB0 — install the vtable at 0x61C71C and forward to 0x409630.
class S402EB0 {
public:
    void M_402EB0();
};
MATCH_FUNC(0x402EB0)
void S402EB0::M_402EB0()
{
    *(void**)this = (void*)0x61C71C;
    sub_409630();
}

// 0x410840 — install the vtable at 0x61D4E8 and forward to 0x4114F0.
extern void sub_4114F0();
class S410840 {
public:
    void M_410840();
};
MATCH_FUNC(0x410840)
void S410840::M_410840()
{
    *(void**)this = (void*)0x61D4E8;
    sub_4114F0();
}

// 0x410890 — install the vtable at 0x61D524 and forward to 0x440B30.
extern void sub_440B30();
class S410890 {
public:
    void M_410890();
};
MATCH_FUNC(0x410890)
void S410890::M_410890()
{
    *(void**)this = (void*)0x61D524;
    sub_440B30();
}

// 0x4119D0 — install the vtable at 0x61D6C8 and forward to 0x4114F0.
class S4119D0 {
public:
    void M_4119D0();
};
MATCH_FUNC(0x4119D0)
void S4119D0::M_4119D0()
{
    *(void**)this = (void*)0x61D6C8;
    sub_4114F0();
}

// 0x411A30 — install the vtable at 0x61D704 and forward to 0x4114F0.
class S411A30 {
public:
    void M_411A30();
};
MATCH_FUNC(0x411A30)
void S411A30::M_411A30()
{
    *(void**)this = (void*)0x61D704;
    sub_4114F0();
}

// 0x41A3E0 — thiscall forwarder to 0x52A7A0 with one stacked argument.
class T52A7A0 {
public:
    void Other_52A7A0(int a1);
};
class S41A3E0 {
public:
    void M_41A3E0(int a1);
};
MATCH_FUNC(0x41A3E0)
void S41A3E0::M_41A3E0(int a1)
{
    ((T52A7A0*)this)->Other_52A7A0(a1);
}

// 0x416ED0 — stdcall call with a constant zero argument.
extern void __stdcall sub_419700(int a1);
MATCH_FUNC(0x416ED0)
void __cdecl sub_416ED0()
{
    sub_419700(0);
}

// 0x41A740 — call the thiscall helper then store the argument at +4.
class T41A690 {
public:
    void Other_41A690();
};
class S41A740 {
public:
    char pad_00[4];
    int field_04;                 // +4
    void M_41A740(int a1);
};
MATCH_FUNC(0x41A740)
void S41A740::M_41A740(int a1)
{
    ((T41A690*)this)->Other_41A690();
    this->field_04 = a1;
}

// 0x4089C0 — boolean test on the helper result through the pointer at +0x130.
class T4060A0 {
public:
    unsigned char Other_4060A0();
};
class S4089C0 {
public:
    char pad_00[0x130];
    T4060A0* field_130;           // +0x130
    bool M_4089C0();
};
MATCH_FUNC(0x4089C0)
bool S4089C0::M_4089C0()
{
    return this->field_130->Other_4060A0() ? true : false;
}

// Scalar deleting destructor wrappers.
extern int __cdecl sub_5F90B0(int a1);

class Td4013e0 {
public:
    void Other_4013e0();
};
class Sd401150 {
public:
    Sd401150* D_401150(int flags);
};
MATCH_FUNC(0x401150)
Sd401150* Sd401150::D_401150(int flags)
{
    ((Td4013e0*)this)->Other_4013e0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td402eb0 {
public:
    void Other_402eb0();
};
class Sd402DF0 {
public:
    Sd402DF0* D_402DF0(int flags);
};
MATCH_FUNC(0x402DF0)
Sd402DF0* Sd402DF0::D_402DF0(int flags)
{
    ((Td402eb0*)this)->Other_402eb0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td540780 {
public:
    void Other_540780();
};
class Sd403DC0 {
public:
    Sd403DC0* D_403DC0(int flags);
};
MATCH_FUNC(0x403DC0)
Sd403DC0* Sd403DC0::D_403DC0(int flags)
{
    ((Td540780*)this)->Other_540780();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4057d0 {
public:
    void Other_4057d0();
};
class Sd4057B0 {
public:
    Sd4057B0* D_4057B0(int flags);
};
MATCH_FUNC(0x4057B0)
Sd4057B0* Sd4057B0::D_4057B0(int flags)
{
    ((Td4057d0*)this)->Other_4057d0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td406600 {
public:
    void Other_406600();
};
class Sd406530 {
public:
    Sd406530* D_406530(int flags);
};
MATCH_FUNC(0x406530)
Sd406530* Sd406530::D_406530(int flags)
{
    ((Td406600*)this)->Other_406600();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td407510 {
public:
    void Other_407510();
};
class Sd4073D0 {
public:
    Sd4073D0* D_4073D0(int flags);
};
MATCH_FUNC(0x4073D0)
Sd4073D0* Sd4073D0::D_4073D0(int flags)
{
    ((Td407510*)this)->Other_407510();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td407dc0 {
public:
    void Other_407dc0();
};
class Sd407D30 {
public:
    Sd407D30* D_407D30(int flags);
};
MATCH_FUNC(0x407D30)
Sd407D30* Sd407D30::D_407D30(int flags)
{
    ((Td407dc0*)this)->Other_407dc0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td409630 {
public:
    void Other_409630();
};
class Sd4095E0 {
public:
    Sd4095E0* D_4095E0(int flags);
};
MATCH_FUNC(0x4095E0)
Sd4095E0* Sd4095E0::D_4095E0(int flags)
{
    ((Td409630*)this)->Other_409630();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td40a0c0 {
public:
    void Other_40a0c0();
};
class Sd409FB0 {
public:
    Sd409FB0* D_409FB0(int flags);
};
MATCH_FUNC(0x409FB0)
Sd409FB0* Sd409FB0::D_409FB0(int flags)
{
    ((Td40a0c0*)this)->Other_40a0c0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td40a2f0 {
public:
    void Other_40a2f0();
};
class Sd40A200 {
public:
    Sd40A200* D_40A200(int flags);
};
MATCH_FUNC(0x40A200)
Sd40A200* Sd40A200::D_40A200(int flags)
{
    ((Td40a2f0*)this)->Other_40a2f0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td40aaa0 {
public:
    void Other_40aaa0();
};
class Sd40A5C0 {
public:
    Sd40A5C0* D_40A5C0(int flags);
};
MATCH_FUNC(0x40A5C0)
Sd40A5C0* Sd40A5C0::D_40A5C0(int flags)
{
    ((Td40aaa0*)this)->Other_40aaa0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td40b5e0 {
public:
    void Other_40b5e0();
};
class Sd40B520 {
public:
    Sd40B520* D_40B520(int flags);
};
MATCH_FUNC(0x40B520)
Sd40B520* Sd40B520::D_40B520(int flags)
{
    ((Td40b5e0*)this)->Other_40b5e0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td40bce0 {
public:
    void Other_40bce0();
};
class Sd40B7B0 {
public:
    Sd40B7B0* D_40B7B0(int flags);
};
MATCH_FUNC(0x40B7B0)
Sd40B7B0* Sd40B7B0::D_40B7B0(int flags)
{
    ((Td40bce0*)this)->Other_40bce0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td40cba0 {
public:
    void Other_40cba0();
};
class Sd40CAD0 {
public:
    Sd40CAD0* D_40CAD0(int flags);
};
MATCH_FUNC(0x40CAD0)
Sd40CAD0* Sd40CAD0::D_40CAD0(int flags)
{
    ((Td40cba0*)this)->Other_40cba0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td40d640 {
public:
    void Other_40d640();
};
class Sd40D4B0 {
public:
    Sd40D4B0* D_40D4B0(int flags);
};
MATCH_FUNC(0x40D4B0)
Sd40D4B0* Sd40D4B0::D_40D4B0(int flags)
{
    ((Td40d640*)this)->Other_40d640();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td40dd20 {
public:
    void Other_40dd20();
};
class Sd40D9E0 {
public:
    Sd40D9E0* D_40D9E0(int flags);
};
MATCH_FUNC(0x40D9E0)
Sd40D9E0* Sd40D9E0::D_40D9E0(int flags)
{
    ((Td40dd20*)this)->Other_40dd20();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td40eac0 {
public:
    void Other_40eac0();
};
class Sd40EA00 {
public:
    Sd40EA00* D_40EA00(int flags);
};
MATCH_FUNC(0x40EA00)
Sd40EA00* Sd40EA00::D_40EA00(int flags)
{
    ((Td40eac0*)this)->Other_40eac0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td410840 {
public:
    void Other_410840();
};
class Sd410820 {
public:
    Sd410820* D_410820(int flags);
};
MATCH_FUNC(0x410820)
Sd410820* Sd410820::D_410820(int flags)
{
    ((Td410840*)this)->Other_410840();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td410890 {
public:
    void Other_410890();
};
class Sd410870 {
public:
    Sd410870* D_410870(int flags);
};
MATCH_FUNC(0x410870)
Sd410870* Sd410870::D_410870(int flags)
{
    ((Td410890*)this)->Other_410890();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td410b20 {
public:
    void Other_410b20();
};
class Sd410950 {
public:
    Sd410950* D_410950(int flags);
};
MATCH_FUNC(0x410950)
Sd410950* Sd410950::D_410950(int flags)
{
    ((Td410b20*)this)->Other_410b20();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td411420 {
public:
    void Other_411420();
};
class Sd411400 {
public:
    Sd411400* D_411400(int flags);
};
MATCH_FUNC(0x411400)
Sd411400* Sd411400::D_411400(int flags)
{
    ((Td411420*)this)->Other_411420();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4114f0 {
public:
    void Other_4114f0();
};
class Sd411430 {
public:
    Sd411430* D_411430(int flags);
};
MATCH_FUNC(0x411430)
Sd411430* Sd411430::D_411430(int flags)
{
    ((Td4114f0*)this)->Other_4114f0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4118b0 {
public:
    void Other_4118b0();
};
class Sd411820 {
public:
    Sd411820* D_411820(int flags);
};
MATCH_FUNC(0x411820)
Sd411820* Sd411820::D_411820(int flags)
{
    ((Td4118b0*)this)->Other_4118b0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4119d0 {
public:
    void Other_4119d0();
};
class Sd4119B0 {
public:
    Sd4119B0* D_4119B0(int flags);
};
MATCH_FUNC(0x4119B0)
Sd4119B0* Sd4119B0::D_4119B0(int flags)
{
    ((Td4119d0*)this)->Other_4119d0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td411a30 {
public:
    void Other_411a30();
};
class Sd411A10 {
public:
    Sd411A10* D_411A10(int flags);
};
MATCH_FUNC(0x411A10)
Sd411A10* Sd411A10::D_411A10(int flags)
{
    ((Td411a30*)this)->Other_411a30();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td411c00 {
public:
    void Other_411c00();
};
class Sd411BB0 {
public:
    Sd411BB0* D_411BB0(int flags);
};
MATCH_FUNC(0x411BB0)
Sd411BB0* Sd411BB0::D_411BB0(int flags)
{
    ((Td411c00*)this)->Other_411c00();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td411f80 {
public:
    void Other_411f80();
};
class Sd411F60 {
public:
    Sd411F60* D_411F60(int flags);
};
MATCH_FUNC(0x411F60)
Sd411F60* Sd411F60::D_411F60(int flags)
{
    ((Td411f80*)this)->Other_411f80();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td41a460 {
public:
    void Other_41a460();
};
class Sd41A440 {
public:
    Sd41A440* D_41A440(int flags);
};
MATCH_FUNC(0x41A440)
Sd41A440* Sd41A440::D_41A440(int flags)
{
    ((Td41a460*)this)->Other_41a460();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td41ada0 {
public:
    void Other_41ada0();
};
class Sd41AD00 {
public:
    Sd41AD00* D_41AD00(int flags);
};
MATCH_FUNC(0x41AD00)
Sd41AD00* Sd41AD00::D_41AD00(int flags)
{
    ((Td41ada0*)this)->Other_41ada0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td41b240 {
public:
    void Other_41b240();
};
class Sd41B170 {
public:
    Sd41B170* D_41B170(int flags);
};
MATCH_FUNC(0x41B170)
Sd41B170* Sd41B170::D_41B170(int flags)
{
    ((Td41b240*)this)->Other_41b240();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td41c330 {
public:
    void Other_41c330();
};
class Sd41BC60 {
public:
    Sd41BC60* D_41BC60(int flags);
};
MATCH_FUNC(0x41BC60)
Sd41BC60* Sd41BC60::D_41BC60(int flags)
{
    ((Td41c330*)this)->Other_41c330();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

// 0x408C20 — one-argument call on the field at +0x130, zero when null.
class Tc4060B0 {
public:
    int Other_4060B0(int a1);
};
class Sc408C20 {
public:
    char pad_00[0x130];
    Tc4060B0* field_130;          // +0x130
    int M_408C20(int a1);
};
MATCH_FUNC(0x408C20)
int Sc408C20::M_408C20(int a1)
{
    if (this->field_130)
        return this->field_130->Other_4060B0(a1);
    return 0;
}

// 0x41A3B0 — helper call then three-argument call on the subobject at +0xa4.
class Ta529B90 {
public:
    void Other_529B90(int a1);
};
class Sb41A3B0 {
public:
    void M_41A3B0(int a1);
};
extern void __cdecl sub_4BEBD0(int a1, void* a2, int a3);
MATCH_FUNC(0x41A3B0)
void Sb41A3B0::M_41A3B0(int a1)
{
    ((Ta529B90*)this)->Other_529B90(a1);
    sub_4BEBD0(a1, (char*)this + 0xa4, 4);
}

// 0x402990 — three-argument constructor wrapper with type word 0xa.
extern char g_vt_61C62C;
class Tc4095A0 {
public:
    void Other_4095A0(int a1, int a2, int a3);
};
class Sc402990 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    Sc402990* Init_402990(int a1, int a2);
};
MATCH_FUNC(0x402990)
Sc402990* Sc402990::Init_402990(int a1, int a2)
{
    ((Tc4095A0*)this)->Other_4095A0(a1, a2, 1);
    *(void**)this = &g_vt_61C62C;
    this->type_04 = 0xa;
    return this;
}

// 0x405680 — three-argument constructor wrapper with type word 0xd.
extern char g_vt_61C9D4;
class Sc405680 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    Sc405680* Init_405680(int a1, int a2);
};
MATCH_FUNC(0x405680)
Sc405680* Sc405680::Init_405680(int a1, int a2)
{
    ((Tc4095A0*)this)->Other_4095A0(a1, a2, 1);
    *(void**)this = &g_vt_61C9D4;
    this->type_04 = 0xd;
    return this;
}

// 0x408ED0 — three-argument constructor wrapper with type word 0xc.
extern char g_vt_61D1D8;
class Sc408ED0 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    Sc408ED0* Init_408ED0(int a1, int a2);
};
MATCH_FUNC(0x408ED0)
Sc408ED0* Sc408ED0::Init_408ED0(int a1, int a2)
{
    ((Tc4095A0*)this)->Other_4095A0(a1, a2, 1);
    *(void**)this = &g_vt_61D1D8;
    this->type_04 = 0xc;
    return this;
}

// 0x4039B0 — two-argument constructor wrapper with type word 4.
extern char g_vt_61C800f;
class Sc4039B0 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    Sc4039B0* Init_4039B0(int a1, int a2);
};
MATCH_FUNC(0x4039B0)
Sc4039B0* Sc4039B0::Init_4039B0(int a1, int a2)
{
    ((Tc4095A0*)this)->Other_4095A0(a1, a2, 1);
    *(void**)this = &g_vt_61C800f;
    this->type_04 = 4;
    return this;
}

// 0x409600 — base constructor: default fields, vtable, optional hook.
extern char g_vt_61D2C0f;
class S409600 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    char pad_06[0x12];
    int field_18;                 // +0x18
    int field_1c;                 // +0x1c
    char pad_20[0x1d];
    char byte_3d;                 // +0x3d
    void Hook_4097C0(int a1);     // unresolved callee at 0x4097C0
    S409600* Init_409600(int a1, int a2);
};
MATCH_FUNC(0x409600)
S409600* S409600::Init_409600(int a1, int a2)
{
    this->field_18 = -1;
    this->field_1c = -1;
    this->byte_3d = 0;
    *(void**)this = &g_vt_61D2C0f;
    if (a2 != 0)
        this->Hook_4097C0(a1);
    return this;
}

// 0x406670 — gate on a bool and two -1.0f bit patterns, dispatch slot +0x5C.
class Sc406670 {
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
    virtual void Vat_5C(int v);

    char pad_04[0xc];             // +0x04..+0x10
    int field_10;                 // +0x10
    char pad_14[0xc];             // +0x14..+0x20
    int field_20;                 // +0x20
    int field_24;                 // +0x24
    void M_406670(bool a1);
};
MATCH_FUNC(0x406670)
void Sc406670::M_406670(bool a1)
{
    if (a1)
    {
        if (this->field_10 == 0)
        {
            if (this->field_20 == (int)0xbf800000 || this->field_24 == (int)0xbf800000)
            {
                Vat_5C(1);
                return;
            }
        }
        Vat_5C(3);
    }
    else
        Vat_5C(4);
}

extern void __stdcall sub_4098D0(void* a1);
// 0x407300 — clear six 4-byte sub-fields through sub_4BEBD0.
class Sc407300 {
public:
    char pad_00[0x40];
    int field_40;                 // +0x40
    int field_44;                 // +0x44
    int field_48;                 // +0x48
    int field_4c;                 // +0x4C
    int field_50;                 // +0x50
    int field_54;                 // +0x54
    void M_407300(void* a1);
};
MATCH_FUNC(0x407300)
void Sc407300::M_407300(void* a1)
{
    sub_4098D0(a1);
    sub_4BEBD0((int)a1, &this->field_40, 4);
    sub_4BEBD0((int)a1, &this->field_44, 4);
    sub_4BEBD0((int)a1, &this->field_48, 4);
    sub_4BEBD0((int)a1, &this->field_4c, 4);
    sub_4BEBD0((int)a1, &this->field_50, 4);
    sub_4BEBD0((int)a1, &this->field_54, 4);
}

// 0x403F50 — clear six sub-fields then the +0x51 byte.
class Sc403F50 {
public:
    char pad_00[0x40];
    int field_40;                 // +0x40
    char field_44;                // +0x44
    char field_45;                // +0x45
    char pad_46[2];
    int field_48;                 // +0x48
    int field_4c;                 // +0x4C
    char field_50;                // +0x50
    char field_51;                // +0x51
    void M_403F50(void* a1);
};
MATCH_FUNC(0x403F50)
void Sc403F50::M_403F50(void* a1)
{
    sub_4098D0(a1);
    sub_4BEBD0((int)a1, &this->field_40, 4);
    sub_4BEBD0((int)a1, &this->field_44, 1);
    sub_4BEBD0((int)a1, &this->field_45, 1);
    sub_4BEBD0((int)a1, &this->field_48, 4);
    sub_4BEBD0((int)a1, &this->field_4c, 4);
    sub_4BEBD0((int)a1, &this->field_50, 1);
    sub_4BEBD0((int)a1, &this->field_51, 1);
}

// --- 0x406330: mode write + node/data derived value pair.
class T406330Node {
public:
    char pad_00[0x14];
    unsigned short field_14;      // +0x14
};
class T406330Data {
public:
    char pad_00[0xc];
    void* field_0c;               // +0x0C
};
class T406330Value {
public:
    char pad_00[0x90];
    int field_90;                 // +0x90
    char pad_94[0x160 - 0x94];
    int field_160;                // +0x160
};
class Sc406330 {
public:
    char pad_00[8];
    T406330Data* field_08;        // +0x08
    char field_0c;                // +0x0C
    char pad_0d[0x2c - 0x0d];
    int field_2c;                 // +0x2C
    T406330Node* field_30;        // +0x30
    char pad_34[0x40 - 0x34];
    int field_40;                 // +0x40
    void M_406330(char a1);
};
MATCH_FUNC(0x406330)
void Sc406330::M_406330(char a1)
{
    this->field_0c = a1;
    if (a1 == 6)
    {
        // Both branches store field_2c directly; field_40 then copies it
        // (VC6 forwards the store through edx).
        if (this->field_30->field_14 == 0x10)
            this->field_2c = *(int*)(*(char**)((char*)this->field_08->field_0c + 0xa8) + 0x90);
        else
            this->field_2c = *(int*)(*(char**)((char*)this->field_08->field_0c + 0xa8) + 0x160);
        this->field_40 = this->field_2c;
    }
}

extern float g_61c584;
// Node at [this+0x30] used by the 0x4053A0/0x4053F0 guards.
class T4053A0Node {
public:
    char pad_00[0x14];
    unsigned short field_14;      // +0x14
    char pad_16[0x1e];
    int field_34;                 // +0x34
    char pad_38[8];
    int field_40;                 // +0x40
};
// Data at [this+0x08] used by the same guards.
class T4053A0Data {
public:
    char pad_00[0x44];
    float field_44;               // +0x44
    char pad_48[4];
    unsigned short field_4c;      // +0x4C
};

// 0x4053A0 — guard on the +0x30 node id, then float threshold lookup.
class Sc4053A0 {
public:
    char pad_00[8];
    T4053A0Data* field_08;        // +0x08
    char pad_0c[0x24];
    T4053A0Node* field_30;        // +0x30
    int field_34;                 // +0x34
    char pad_38[8];
    int field_40;                 // +0x40
    int M_4053A0();
};
MATCH_FUNC(0x4053A0)
int Sc4053A0::M_4053A0()
{
    T4053A0Node* node = this->field_30;
    unsigned short id = node->field_14;
    if (id != 0xffff)
    {
        T4053A0Data* data = this->field_08;
        if (data->field_4c == id)
        {
            int value = (int)data->field_44;
            if (value > g_61c584)
            {
                if (node->field_40 != 0)
                    return node->field_40;
            }
        }
    }
    return node->field_34;
}

// 0x4053F0 — same id/threshold guard, default value from the nested pointers.
class T4053F0Inner {
public:
    char pad_00[0x18];
    int field_18;                 // +0x18
};
class Sc4053F0 {
public:
    char pad_00[8];
    void* field_08;               // +0x08
    char pad_0c[0x24];
    T4053A0Node* field_30;        // +0x30
    int M_4053F0();
};
MATCH_FUNC(0x4053F0)
int Sc4053F0::M_4053F0()
{
    T4053A0Node* node = this->field_30;
    unsigned short id = node->field_14;
    if (id != 0xffff)
    {
        void* data = this->field_08;
        if (id == *(unsigned short*)((char*)data + 0x4c))
        {
            int value = (int)*(float*)((char*)data + 0x44);
            if (value > g_61c584)
            {
                if (node->field_40 != 0)
                    return node->field_40;
            }
        }
    }
    return ((T4053F0Inner*)*(int*)((char*)this->field_08 + 8))->field_18;
}

// 0x40A370 — bounded index lookup into the +0x90 slot array.
class Sc40A370 {
public:
    char pad_00[0x90];
    int field_90[2];              // +0x90, indices 1..2 used
    int Get_40A370(int a1);
};
MATCH_FUNC(0x40A370)
int Sc40A370::Get_40A370(int a1)
{
    if (a1 < 1 || a1 > 2)
        return -1;
    return this->field_90[a1];
}

// 0x408830 — conditional call on the object referenced at +0x130.
class T405F00 {
public:
    void Hook_405F00(int a1);     // unresolved callee at 0x405F00
};
class Sc408830 {
public:
    char pad_00[0x130];
    void* field_130;              // +0x130
    void M_408830(int a1);
};
MATCH_FUNC(0x408830)
void Sc408830::M_408830(int a1)
{
    if (a1 != 0)
        ((T405F00*)this->field_130)->Hook_405F00(a1);
}

// 0x408880 — conditional call on the object referenced at +0x130.
class T405F50 {
public:
    void Hook_405F50(int a1);     // unresolved callee at 0x405F50
};
class Sc408880 {
public:
    char pad_00[0x130];
    void* field_130;              // +0x130
    void M_408880(int a1);
};
MATCH_FUNC(0x408880)
void Sc408880::M_408880(int a1)
{
    if (a1 != 0)
        ((T405F50*)this->field_130)->Hook_405F50(a1);
}

// 0x4029C0 — five-argument constructor wrapper with fields at +0x20..+0x30.
extern char g_vt_61C62Cf;
extern void __stdcall sub_409600(int a1, int a2);
class Sc4029C0 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    char pad_06[0x1a];
    int field_20;                 // +0x20
    int field_24;                 // +0x24
    int field_28;                 // +0x28
    char pad_2c[4];
    int field_30;                 // +0x30
    Sc4029C0* Init_4029C0(int a1, int a2, int a3, int a4, int a5);
};
MATCH_FUNC(0x4029C0)
Sc4029C0* Sc4029C0::Init_4029C0(int a1, int a2, int a3, int a4, int a5)
{
    sub_409600(a1, 1);
    this->field_30 = a2;
    *(void**)this = &g_vt_61C62Cf;
    this->type_04 = 0xa;
    this->field_20 = a3;
    this->field_24 = a4;
    this->field_28 = a5;
    return this;
}

// 0x4073F0 — six-argument constructor wrapper with a field-default branch.
extern char g_vt_61CD2Cf;
class Sc4073F0 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    char pad_06[2];
    void* field_08;               // +8
    char pad_0c[0x14];
    int field_20;                 // +0x20
    int field_24;                 // +0x24
    int field_28;                 // +0x28
    char pad_2c[0xc];
    int field_38;                 // +0x38
    char pad_3c[4];
    int field_40;                 // +0x40
    Sc4073F0* Init_4073F0(int a1, int a2, int a3, int a4, int a5, int a6);
};
MATCH_FUNC(0x4073F0)
Sc4073F0* Sc4073F0::Init_4073F0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    sub_409600(a1, 1);
    this->field_20 = a2;
    *(void**)this = &g_vt_61CD2Cf;
    this->type_04 = 1;
    this->field_24 = a3;
    this->field_28 = a4;
    this->field_40 = a5;
    this->field_38 = a6;
    if (a6 == 0)
    {
        int p = *(int*)((char*)this->field_08 + 8);
        int c = *(int*)((char*)p + 0xc8);
        if (c == 0)
            this->field_38 = *(int*)((char*)p + 0x18);
        else
            this->field_38 = c;
    }
    return this;
}

// 0x4062D0 — two-argument constructor wrapper, fields +0x30 and +0x40.
extern char g_vt_61CB58f;
class Sc4062D0 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    char pad_06[0x2a];
    int field_30;                 // +0x30
    char pad_34[0xc];
    float field_40;               // +0x40
    Sc4062D0* Init_4062D0(int a1, int a2);
};
MATCH_FUNC(0x4062D0)
Sc4062D0* Sc4062D0::Init_4062D0(int a1, int a2)
{
    sub_409600(a1, 1);
    *(void**)this = &g_vt_61CB58f;
    this->type_04 = 0x15;
    this->field_30 = a2;
    this->field_40 = 120.0f;
    return this;
}

// 0x403EF0 — five-argument constructor wrapper with fields at +0x20..+0x30.
extern char g_vt_61C8E4f;
class Sc403EF0 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    char pad_06[0x1a];
    int field_20;                 // +0x20
    int field_24;                 // +0x24
    int field_28;                 // +0x28
    char pad_2c[4];
    int field_30;                 // +0x30
    char pad_34[0xc];
    int field_40;                 // +0x40
    char byte_44;                 // +0x44
    char byte_45;                 // +0x45
    char pad_46[2];
    int field_48;                 // +0x48
    int field_4c;                 // +0x4c
    char byte_50;                 // +0x50
    char byte_51;                 // +0x51
    Sc403EF0* Init_403EF0(int a1, int a2, int a3, int a4, int a5);
};
MATCH_FUNC(0x403EF0)
Sc403EF0* Sc403EF0::Init_403EF0(int a1, int a2, int a3, int a4, int a5)
{
    sub_409600(a1, 1);
    this->field_30 = a2;
    *(void**)this = &g_vt_61C8E4f;
    this->type_04 = 5;
    this->field_20 = a3;
    this->field_24 = a4;
    this->byte_45 = 0;
    this->field_48 = 0;
    this->field_4c = 0;
    this->byte_50 = 0;
    this->byte_51 = 0;
    this->field_28 = a5;
    this->field_40 = -1;
    this->byte_44 = 1;
    return this;
}

// 0x4039E0 — five-argument constructor wrapper with fields at +0x20..+0x30.
extern char g_vt_61C800f;
class Sc4039E0 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    char pad_06[0x1a];
    int field_20;                 // +0x20
    int field_24;                 // +0x24
    int field_28;                 // +0x28
    char pad_2c[4];
    int field_30;                 // +0x30
    Sc4039E0* Init_4039E0(int a1, int a2, int a3, int a4, int a5);
};
MATCH_FUNC(0x4039E0)
Sc4039E0* Sc4039E0::Init_4039E0(int a1, int a2, int a3, int a4, int a5)
{
    sub_409600(a1, 1);
    this->field_30 = a2;
    *(void**)this = &g_vt_61C800f;
    this->type_04 = 4;
    this->field_20 = a3;
    this->field_24 = a4;
    this->field_28 = a5;
    return this;
}

// 0x408F00 — five-argument constructor wrapper with fields at +0x20..+0x30.
extern char g_vt_61D1D8f;
class Sc408F00 {
public:
    int vtable_00;                // +0
    short type_04;                // +4
    char pad_06[0x1a];
    int field_20;                 // +0x20
    int field_24;                 // +0x24
    int field_28;                 // +0x28
    char pad_2c[4];
    int field_30;                 // +0x30
    Sc408F00* Init_408F00(int a1, int a2, int a3, int a4, int a5);
};
MATCH_FUNC(0x408F00)
Sc408F00* Sc408F00::Init_408F00(int a1, int a2, int a3, int a4, int a5)
{
    sub_409600(a1, 1);
    this->field_30 = a2;
    *(void**)this = &g_vt_61D1D8f;
    this->type_04 = 0xc;
    this->field_20 = a3;
    this->field_24 = a4;
    this->field_28 = a5;
    return this;
}

// 0x41D670 — dispatch four args plus the global object through the +0x8 slot.
extern void* g_6645c4;
typedef int (__stdcall* T41D670Fn)(void* obj, int a1, int a2, int a3, int a4);
class T41D670Target {
public:
    char pad_00[8];
    T41D670Fn slot_08;            // +0x08 dispatch slot
};
class T41D670Obj {
public:
    T41D670Target* field_0;       // +0x00 slot table
};
MATCH_FUNC(0x41D670)
int __stdcall sub_41D670(int a1, int a2, int a3, int a4)
{
    T41D670Obj* p = (T41D670Obj*)g_6645c4;
    if (p != 0)
        return p->field_0->slot_08(p, a1, a2, a3, a4);
    return 0;
}

// 0x41B700 — copy a string while expanding each 0x41..0x5F byte through the
// 0x64D3F4 word table until the destination count reaches the limit.
extern int g_64d3f4[];
MATCH_FUNC(0x41B700)
int __cdecl sub_41B700(char* a1, char* a2, int a3)
{
    char* sp = a1;
    char* dp = a2;
    char c = *sp;
    sp++;
    int n = 0;
    while (c != 0 && n < a3) {
        if (c >= 'A' && c <= '_') {
            int v = g_64d3f4[c];
            *dp++ = (char)(v >> 8);
            *dp++ = (char)v;
            n += 2;
        } else {
            *dp++ = c;
            n++;
        }
        c = *sp++;
    }
    *dp = 0;
    return (int)dp;
}


// 0x41F8B0 — one-shot latch: if +0x1F4 is unset, either run 0x48B4F0 on the
// +0x1E8 object or publish +0x28/-0xC/+0x1FC through the two global calls,
// then mark +0x1F4.
class T41F8B0Obj48B4F0 {
public:
    void M_48B4F0();
};
class S41F8B0 {
public:
    char pad_00[0x28];
    int field_28;                   // +0x28
    char pad_2c[0x74 - 0x2c];
    void* field_74;                 // +0x74
    char pad_78[0x1e8 - 0x78];
    T41F8B0Obj48B4F0* field_1e8;    // +0x1E8
    char pad_1ec[0x1f4 - 0x1ec];    // +0x1EC..+0x1F4
    int field_1f4;                  // +0x1F4 latch
    int field_1f8;                  // +0x1F8
    int field_1fc;                  // +0x1FC
    void M_41F8B0();
};
extern void (__stdcall *g_61C284)(int a1);
extern void (__stdcall *g_61C288)(int a1, int a2, int a3);

MATCH_FUNC(0x41F8B0)
void S41F8B0::M_41F8B0()
{
    if (field_1f4 != 0)
        return;
    if (field_74 != 0 && field_1f8 == 0)
        field_1e8->M_48B4F0();
    else
    {
        g_61C284(field_1fc);
        g_61C288(field_28, -0xc, field_1fc);
    }
    field_1f4 = 1;
}
