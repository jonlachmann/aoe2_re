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
#pragma optimize("s", on)
WIP_FUNC(0x4060A0)
bool S4060A0::Check_4060A0()
{
    return this->field_8;
}
#pragma optimize("", on)

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
