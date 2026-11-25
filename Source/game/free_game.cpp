// free_game — game-region free functions migrated from Source/simple.
// Sections keep per-file order; preambles are carried only when the file's
// first marker lives in another module.
#include "Function.hpp"


extern int g_66d4b0;
extern int g_66d4b4;
extern int g_66d4b8;

extern int g_66e3e8;
extern int g_66e3ec;
extern int g_66e3f0;

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
MATCH_FUNC(0x437710)
void S437710::Get_437710(int* a, int* b, int* c)
{
    *a = *(int*)((char*)this + 0x980);
    *b = *(int*)((char*)this + 0x984);
    *c = *(int*)((char*)this + 0x988);
}

class S40A0D0 {
public:
    S40A0D0* Ref_40A0D0();
};

// 0x426070 — ten-dword clear constructor, returns this.
class S426070 {
public:
    int field_0;                  // +0x00
    int field_4;                  // +0x04
    int field_8;                  // +0x08
    int field_c;                  // +0x0C
    int array_10[10];             // +0x10
    S426070* Init_426070();
};
MATCH_FUNC(0x426070)
S426070* S426070::Init_426070()
{
    field_0 = 0;
    field_8 = 0;
    field_4 = 0;
    field_c = 0;
    for (int i = 0; i < 10; ++i)
        array_10[i] = 0;
    return this;
}

class S4228E0 {
public:
    S4228E0* Ref_4228E0();
};
MATCH_FUNC(0x4228E0)
S4228E0* S4228E0::Ref_4228E0()
{
    return (S4228E0*)((char*)this + 4);
}

class S46A900 {
public:
    S46A900* Ref_46A900();
};

class S46A940 {
public:
    S46A940* Ref_46A940();
};

class S46A950 {
public:
    S46A950* Ref_46A950();
};

class S46A960 {
public:
    S46A960* Ref_46A960();
};

class S46A970 {
public:
    S46A970* Ref_46A970();
};

class S46AA10 {
public:
    S46AA10* Ref_46AA10();
};

extern int* g_6645c4;
MATCH_FUNC(0x439610)
int* Ref_439610()
{
    return (int*)((char*)*(int**)((char*)g_6645c4 + 0x24) + 0xc3f);
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

MATCH_FUNC(0x43A080)
void S43A080::M_43A080(int, int, int, int, int, int, int, int, int)
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
MATCH_FUNC(0x42D210)
bool S42D210::Check_42D210()
{
    return field_1e38 == 4;
}

class S431740 {
public:
    char pad_00[0x17e4];
    int field_17e4;
    bool Check_431740();
};
MATCH_FUNC(0x431740)
bool S431740::Check_431740()
{
    return field_17e4 != -1;
}

class S431750 {
public:
    char pad_00[0x1a50];
    int field_1a50;
    bool Check_431750();
};
MATCH_FUNC(0x431750)
bool S431750::Check_431750()
{
    return field_1a50 != -1;
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


// 0x41F6A0 — 12-byte record table lookup.
class S41F6A0Table {
public:
    char pad_00[0x20c];
    int records;                 // 0x20c

    void* Entry_41F6A0(int index);
};


// 0x41F840 — validated short index into a record's pointer array.
class S41F840Lookup {
public:
    char pad_00[0x41c];
    int records;                 // 0x41c

    int Entry_41F840();
};


// 0x41F880 — search a fixed nine-entry integer slot set.
class S41F880Slots {
public:
    char pad_00[0x9e4];
    int slots[9];                // 0x9e4

    int Find_41F880(int value);
};


// 0x42AF40 — count occupied 56-byte records under a base pointer.
class S42AF40 {
public:
    char pad_00[0x1dd8];
    int table;                   // 0x1dd8

    int Count_42AF40();
};

MATCH_FUNC(0x42AF40)
int S42AF40::Count_42AF40()
{
    int result = 0;
    int* v2 = (int*)(*(int*)((char*)this + 0x1dd8) + 4);
    int v3 = 502;
    do {
        if (*v2)
            ++result;
        v2 += 14;
        --v3;
    } while (v3);
    return result;
}

// 0x42DB70 — select an indexed record, with a special zero-length case.
class S42DB70Table {
public:
    char pad_00[0x10e0];
    int special_index;           // 0x10e0
    char pad_10e4[0x10f8 - 0x10e4];
    void* special_record;        // 0x10f8
    char pad_10fc[0x12c8 - 0x10fc];
    int records;                 // 0x12c8, stride 0x80
    char pad_12cc[0x12d8 - 0x12cc];
    unsigned short count;        // 0x12d8

    int Record_42DB70(unsigned index);
};

MATCH_FUNC(0x42DB70)
int S42DB70Table::Record_42DB70(unsigned index)
{
    if (index > *(unsigned short*)((char*)this + 0x12d8))
        return 0;
    if (index == *(int*)((char*)this + 0x10e0))
        return (int)((char*)this + 0x10f8);
    return (int)(*(int*)((char*)this + 0x12c8) + (index << 7));
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

MATCH_FUNC(0x433E70)
char S433E70::Get_433E70(int* a2, int* a3)
{
    if (!this->field_18)
        return 0;
    *a2 = *(int*)((char*)*(int*)((char*)this->field_14 + 0xc) + 8);
    *a3 = *(int*)((char*)*(int*)((char*)this->field_14 + 0xc) + 0xc);
    return 1;
}

// 0x437970 — record array indexed by dword stride 24.
class S437970 {
public:
    char pad_00[0x2580];
    int field_2580;                // count, self[2400]
    char pad_2584[0x2588 - 0x2584];

    int* Get_437970(int a2);
};

MATCH_FUNC(0x437970)
int* S437970::Get_437970(int a2)
{
    if (a2 < 0 || a2 > this->field_2580)
        return 0;
    else
        return (int*)((char*)this + 4 * 24 * a2);
}

// 0x4385F0 — lazy three-field initialisation guarded by the fourth.
class S4385F0 {
public:
    char pad_00[72*4];
    int field_120;                // self[72]
    char pad_124[80*4 - 72*4 - 4];
    int field_140;                // self[80]

    int Init_4385F0(int a2, int a3, int a4);
};

MATCH_FUNC(0x4385F0)
int S4385F0::Init_4385F0(int a2, int a3, int a4)
{
    int result = this->field_140;
    if (!result) {
        this->field_120 = a2;
        result = a4;
        *(int*)((char*)this + 76 * 4) = a3;
        this->field_140 = a4;
    }
    return result;
}

// 0x438840 — append into a 20-stride ring, wrapping the count at 20.
class S438840 {
public:
    char pad_00[144*4];
    unsigned count;               // self[144]
    int values[20][20];           // self[145...]

    void Append_438840(int a2, int a3);
};

MATCH_FUNC(0x438840)
void S438840::Append_438840(int a2, int a3)
{
    values[a2][count] = a3;
    if (++count >= 20)
        count = 0;
}

// 0x4388F0 — 1-based table read for indices 1..9.
class S4388F0 {
public:
    char pad_00[81*4];
    int values[10];               // self[81...]

    int Get_4388F0(unsigned a2);
};

MATCH_FUNC(0x4388F0)
int S4388F0::Get_4388F0(unsigned a2)
{
    if (a2 >= 1 && a2 <= 9)
        return this->values[a2];
    else
        return 0;
}

// 0x439D40 — clear 55 records of nine dwords, return the end pointer.
class S439D40 {
public:
    char pad_00[16*4];
    int records[55 * 9];          // self[16...]

    int* Clear_439D40();
};

MATCH_FUNC(0x439D40)
int* S439D40::Clear_439D40()
{
    int* result = ((int*)this) + 16;
    int v2 = 55;
    do {
        *(result - 1) = 0;
        *result = 0;
        result[1] = 0;
        result[2] = 0;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0;
        result[6] = 0;
        *(result - 2) = 0;
        result += 9;
        --v2;
    } while (v2);
    return result;
}

// 0x43E7D0 — clear 0x200 records of three dwords (stride 12) at 0x667958.
struct S43E7D0 {
public:
    int field_00;                 // +0
    int field_04;                 // +4
    int field_08;                 // +8
};
extern S43E7D0 g_667958[0x200];

void sub_43E7D0();

// 0x43E7C0 — tail-call forwarder to the array clear.
MATCH_FUNC(0x43E7C0)
void sub_43E7C0()
{
    sub_43E7D0();
}

MATCH_FUNC(0x43E7D0)
void sub_43E7D0()
{
    int n = 0x200;
    S43E7D0* p = &g_667958[0];
    do {
        p->field_00 = 0;
        p->field_04 = 0;
        p->field_08 = 0;
        ++p;
    } while (--n);
}

// 0x43EBB0 — bounded 1-based dword table, -1 for invalid.
class S43EBB0 {
public:
    int field_00;
    int field_04;                 // self[1], count
    int values[0x100];            // self[2...]

    int Get_43EBB0(int a2);
};

MATCH_FUNC(0x43EBB0)
int S43EBB0::Get_43EBB0(int a2)
{
    if (a2 < 0 || a2 >= this->field_04)
        return -1;
    else
        return this->values[a2];
}

// 0x43EC00 — bounded table returning a dword value.
class S43EC00 {
public:
    char pad_00[42*4];
    int count;                    // self[42]
    int values[0x100];            // self[43...]

    int Get_43EC00(int a2);
};

MATCH_FUNC(0x43EC00)
int S43EC00::Get_43EC00(int a2)
{
    if (a2 < 0 || a2 >= this->count)
        return 0;
    else
        return this->values[a2];
}

// 0x43EC20 — bounded record address, dword stride 40.
class S43EC20 {
public:
    char pad_00[42*4];
    int count;                    // self[42]
    char pad_ac[83*4 - 42*4 - 4];
    int records[0x100];           // self[83...]

    int Get_43EC20(int a2);
};

MATCH_FUNC(0x43EC20)
int S43EC20::Get_43EC20(int a2)
{
    if (a2 < 0 || a2 >= this->count)
        return 0;
    else
        return (int)&this->records[40 * a2];
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
MATCH_FUNC(0x437960)
int S437960::Inc_437960()
{
    int value = field_2580;
    ++value;
    field_2580 = value;
    return value;
}

class S438690 {
public:
    char pad_00[0x210];
    int field_210;
    int Inc_438690();
};
MATCH_FUNC(0x438690)
int S438690::Inc_438690()
{
    int value = field_210;
    ++value;
    field_210 = value;
    return value;
}

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
MATCH_FUNC(0x43F8B0)
S43F8B0* S43F8B0::Reset_43F8B0()
{
    *(int*)((char*)this) = 0;
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    return this;
}

class S410680 {
public:
    S410680* Init_410680();
};

class S4373F0 {
public:
    S4373F0* Init_4373F0();
};
MATCH_FUNC(0x4373F0)
S4373F0* S4373F0::Init_4373F0()
{
    int zero = 0;
    *(int*)((char*)this) = zero;
    *(int*)((char*)this + 4) = zero;
    *(unsigned char*)((char*)this + 8) = zero;
    *(int*)((char*)this + 0x10) = zero;
    *(int*)((char*)this + 0x14) = zero;
    *(int*)((char*)this + 0x18) = zero;
    *(int*)((char*)this + 0x1c) = -1;
    *(int*)((char*)this + 0xc) = zero;
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
MATCH_FUNC(0x423A70)
S423A70* S423A70::Init_423A70()
{
    field_4 = 0;
    field_0 = 0;
    field_8 = -1;
    field_14 = 0;
    field_1c = -1;
    field_524 = 0;
    field_420 = 0;
    field_540 = 0;
    field_52c = 1;
    field_53c = 1;
    field_528 = 1;
    field_530 = 0;
    field_548 = 0;
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

MATCH_FUNC(0x422E00)
int M_422E00()
{
    return 0x32;
}




class S43FAB0 {
public:
    S43FAB0* Self_43FAB0();
};
MATCH_FUNC(0x43FAB0)
S43FAB0* S43FAB0::Self_43FAB0()
{
    return this;
}

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
MATCH_FUNC(0x421FB0)
int S421FB0::Get_421FB0()
{
    return *(short*)((char*)field_24 + 0x8f8);
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
MATCH_FUNC(0x42F0A0)
int Get_42F0A0()
{
    return g_665340;
}

// Family 0x421AD0/0x421AF0: two setters over the byte pair +0x9a9/+0x9aa;
// the first writes +0x9a9 then stores the (arg == 0) result at +0x9aa, the
// second swaps which byte gets what.
class S421AD0 {
public:
    char pad_00[0x9a9];
    unsigned char field_9a9;
    unsigned char field_9aa;

    void M_421AD0(int v);
    void M_421AF0(int v);
};

MATCH_FUNC(0x421AF0)
void S421AD0::M_421AF0(int v)
{
    field_9aa = (unsigned char)v;
    field_9a9 = (v == 0);
}

class S421Accessors {
public:
    char pad_00[0x924];
    float field_924;
    unsigned char field_928;
    char gap_929[0x9a9 - 0x929];
    unsigned char field_9a9;
    unsigned char field_9aa;
    unsigned char field_9ab;
    unsigned char field_9ac;
    unsigned char field_9ad;
    unsigned char field_9ae;
    unsigned char field_9af;
    unsigned char field_9b0;
    unsigned char field_9b1;
    unsigned char field_9b2;
    unsigned char field_9b3;
    unsigned char field_9b4;
    unsigned char array_9b5[0x9be - 0x9b5];
    unsigned char field_9be;
    unsigned char field_9bf;
    unsigned char array_9c0[0x9d0 - 0x9c0];
    unsigned char field_9d0;
    char gap_9d1[0x9d4 - 0x9d1];
    int field_9d4;
    int field_9d8;
    char pad_dc[0xb44 - 0x9dc];
    int field_b44;
    char pad_b48[0x1094 - 0xb48];
    unsigned char field_1094;

    void Set9BF_421710(unsigned char v);
    void Set9AE_421B40(unsigned char v);
    void Set9B0_421B50(unsigned char v);
    void Set9D0_421B60(unsigned char v);
    void Set9B1_421B70(unsigned char v);
    void Set9B2_421B80(unsigned char v);
    void Set9B3_421B90(unsigned char v);
    void Clear9B4_421BA0(unsigned char unused);
    void SetBit_421BB0(int index, unsigned char v);
    void Set9BE_421C20(unsigned char v);
    void Set1094_421C50(unsigned char v);
    void SetB44_421720(int v);
    int GetB44_421730();
    unsigned char Get9BF_421740();
    float Get924_421750();
    int Get928_421760();
    bool IsZero928_421770();
    int Get9D4_421780();
    int Get9D8_421790();
    char* Ptr9A9_4217A0();
    int Get9A9_4217B0();
    int Get9AA_4217C0();
    int Get9AB_4217D0();
    int Get9AC_4217E0();
    int Get9AD_4217F0();
    int Get9AE_421800();
    int Get9B0_421810();
    int Get9D0_421820();
    int Get9B1_421830();
    int Get9B2_421840();
    int Get9B4_421850();
    unsigned char GetIndexed9B5_4219D0(int index);
    int Get9BE_4219E0();
    int Get9B3_4219F0();
    int GetIndexed9C0_421A00(int index);
    unsigned char Get1094_421A20();
    unsigned char Get9AF_421A30();
    void Set928_421A60(unsigned char v);
    void Set924Raw_421A70(int v);
    void Set9D4_421AB0(int v);
    void Set9D8_421AC0(int v);
};

MATCH_FUNC(0x421710)
void S421Accessors::Set9BF_421710(unsigned char v) { field_9bf = v; }

MATCH_FUNC(0x421720)
void S421Accessors::SetB44_421720(int v) { field_b44 = v; }

MATCH_FUNC(0x421730)
int S421Accessors::GetB44_421730() { return field_b44; }

MATCH_FUNC(0x421740)
unsigned char S421Accessors::Get9BF_421740() { return field_9bf; }

MATCH_FUNC(0x421770)
bool S421Accessors::IsZero928_421770() { return field_928 == 0; }

MATCH_FUNC(0x421790)
int S421Accessors::Get9D8_421790() { return field_9d8; }

MATCH_FUNC(0x4217D0)
int S421Accessors::Get9AB_4217D0() { return field_9ab; }

MATCH_FUNC(0x4217E0)
int S421Accessors::Get9AC_4217E0() { return field_9ac; }

MATCH_FUNC(0x4217F0)
int S421Accessors::Get9AD_4217F0() { return field_9ad; }

MATCH_FUNC(0x421800)
int S421Accessors::Get9AE_421800() { return field_9ae; }

MATCH_FUNC(0x421810)
int S421Accessors::Get9B0_421810() { return field_9b0; }

MATCH_FUNC(0x421830)
int S421Accessors::Get9B1_421830() { return field_9b1; }

MATCH_FUNC(0x421840)
int S421Accessors::Get9B2_421840() { return field_9b2; }

MATCH_FUNC(0x421850)
int S421Accessors::Get9B4_421850() { return field_9b4; }

MATCH_FUNC(0x4219D0)
unsigned char S421Accessors::GetIndexed9B5_4219D0(int index) { return array_9b5[index]; }

MATCH_FUNC(0x4219E0)
int S421Accessors::Get9BE_4219E0() { return field_9be; }

MATCH_FUNC(0x4219F0)
int S421Accessors::Get9B3_4219F0() { return field_9b3; }

MATCH_FUNC(0x421A00)
int S421Accessors::GetIndexed9C0_421A00(int index)
{
    if (index >= 9)
        return 1;
    return array_9c0[index];
}

MATCH_FUNC(0x421A20)
unsigned char S421Accessors::Get1094_421A20() { return field_1094; }

MATCH_FUNC(0x421A30)
unsigned char S421Accessors::Get9AF_421A30() { return field_9af; }

extern unsigned char g_6642f0;

MATCH_FUNC(0x421B50)
void S421Accessors::Set9B0_421B50(unsigned char v) { field_9b0 = v; }

MATCH_FUNC(0x421B60)
void S421Accessors::Set9D0_421B60(unsigned char v) { field_9d0 = v; }

MATCH_FUNC(0x421B80)
void S421Accessors::Set9B2_421B80(unsigned char v) { field_9b2 = v; }

MATCH_FUNC(0x421B90)
void S421Accessors::Set9B3_421B90(unsigned char v) { field_9b3 = v; }

MATCH_FUNC(0x421BA0)
void S421Accessors::Clear9B4_421BA0(unsigned char unused) { (void)unused; field_9b4 = 0; }

MATCH_FUNC(0x421BB0)
void S421Accessors::SetBit_421BB0(int index, unsigned char v)
{
    unsigned char* p = (unsigned char*)this + 0x9b5 + index;
    *p = (*p & 0xfe) | v;
}

MATCH_FUNC(0x421C50)
void S421Accessors::Set1094_421C50(unsigned char v) { field_1094 = v; }

class S421C00 {
public:
    char pad_00[0x9af];
    unsigned char field_9af;
    char pad_9b0[0x9b5 - 0x9b0];
    unsigned char array_9b5[0xb];
    unsigned char array_9c0[0x9e4 - 0x9c0];
    int array_9e4[(0xa10 - 0x9e4) / 4];
    int array_a10[0x40];

    int Get_421880(int index);
    void Set_421C00(int index, unsigned char v);
    void Set_421C30(int index, unsigned char v);
    void Set_421C60(unsigned char v);
    void Set_422220(int index, int v);
    void Clear_422240(int index);
    int Get_422210(int index);
    void GetBounds_422290(int index, int* out);
};

MATCH_FUNC(0x421C00)
void S421C00::Set_421C00(int index, unsigned char v)
{
    array_9b5[index] = v;
}

MATCH_FUNC(0x421C30)
void S421C00::Set_421C30(int index, unsigned char v)
{
    array_9c0[index] = v;
}

MATCH_FUNC(0x421C60)
void S421C00::Set_421C60(unsigned char v)
{
    field_9af = v;
}

MATCH_FUNC(0x422220)
void S421C00::Set_422220(int index, int v)
{
    array_9e4[index] = v;
}

MATCH_FUNC(0x422240)
void S421C00::Clear_422240(int index)
{
    array_a10[index] = -1;
}

MATCH_FUNC(0x422210)
int S421C00::Get_422210(int index)
{
    return array_9e4[index];
}

MATCH_FUNC(0x422290)
void S421C00::GetBounds_422290(int index, int* out)
{
    if (index < 0 || index >= 9)
        *out = 0;
    else
        *out = array_a10[index];
}

class S421CF0 {
public:
    char pad_00[0x9c9];
    unsigned char field_9c9;
    unsigned char field_9ca;
    char gap_9cb[0x9cc - 0x9cb];
    int field_9cc;
    char pad_9d0[0x108c - 0x9d0];
    int field_108c;

    void SetC9_421CF0();
    void SetCA_421D00();
    float Get108C_421D10();
    float Get9CC_421D20();
    void ClearC9_421D30();
    void ClearCA_421D40();
    unsigned char GetC9_421D50();
    unsigned char GetCA_421D60();
    void Set9CC_421CD0(int v);
    void Set108C_421CE0(int v);
    void ConditionC9_421D70(unsigned char v);
    void ConditionCA_421D90(unsigned char v);
};

MATCH_FUNC(0x421CD0)
void S421CF0::Set9CC_421CD0(int v) { field_9cc = v; }

MATCH_FUNC(0x421CE0)
void S421CF0::Set108C_421CE0(int v) { field_108c = v; }

MATCH_FUNC(0x421D10)
float S421CF0::Get108C_421D10() { return *(float*)&field_108c; }

MATCH_FUNC(0x421D20)
float S421CF0::Get9CC_421D20() { return *(float*)&field_9cc; }

MATCH_FUNC(0x421D50)
unsigned char S421CF0::GetC9_421D50() { return field_9c9; }

MATCH_FUNC(0x421D60)
unsigned char S421CF0::GetCA_421D60() { return field_9ca; }

class S421FSub {
public:
    char pad_00[0x8ec];
    int field_8ec;
    int field_8f0;
    int field_8f4;
    int unused_8f8;
    int field_8fc;
};

class S421F20 {
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
    virtual void Vat_58(int a, int b);
    char pad_04[0x24 - 4];
    S421FSub* field_24;
    char pad_28[0x5c - 0x28];
    int field_5c;
    void M_421F20();
    void M_421F40();
    void M_421F60(int a, int b);
};

MATCH_FUNC(0x421F20)
void S421F20::M_421F20()
{
    S421FSub* s = field_24;
    field_5c = 1;
    Vat_58(s->field_8f4, s->field_8fc);
}

MATCH_FUNC(0x421F40)
void S421F20::M_421F40()
{
    S421FSub* s = field_24;
    field_5c = 0;
    Vat_58(s->field_8ec, s->field_8f0);
}

MATCH_FUNC(0x421F60)
void S421F20::M_421F60(int a, int b)
{
    field_24->field_8f4 = a;
    field_24->field_8fc = b;
    if (field_5c != 0)
        Vat_58(a, b);
}

class S422320 {
public:
    char pad_00[0x1090];
    int field_1090;
    int Get_422320();
    void Set_422330(int v);
};

MATCH_FUNC(0x422330)
void S422320::Set_422330(int v) { field_1090 = v; }

// Family 0x422D*: three int arrays in one object:
//   +0x04 : 10 entries (indices 1..9 used by the setters/getters)
//   +0x2C : 10 entries (indices 1..9)
//   +0x54 : 51 entries (indices 0..0x32)
// Setters check i in [1,9]; getters check [0,9] / [0,0x32] and return 0 out of
// range.
class S422D50 {
public:
    char pad_00[4];
    int arr_04[10];           // +0x04
    int arr_2c[10];           // +0x2C
    int arr_54[51];           // +0x54

    void M_422D50(int i, int v);
    void M_422D90(int i, int v);
    int M_422D70(int i);
    int M_422DB0(int i);
    int M_422CE0(int i);
};

MATCH_FUNC(0x422D50)
void S422D50::M_422D50(int i, int v)
{
    if (i > 0 && i <= 9)
        arr_04[i] = v;
}

MATCH_FUNC(0x422D90)
void S422D50::M_422D90(int i, int v)
{
    if (i > 0 && i <= 9)
        arr_2c[i] = v;
}

MATCH_FUNC(0x422D70)
int S422D50::M_422D70(int i)
{
    if (i >= 0 && i <= 9)
        return arr_04[i];
    return 0;
}

MATCH_FUNC(0x422DB0)
int S422D50::M_422DB0(int i)
{
    if (i >= 0 && i <= 9)
        return arr_2c[i];
    return 0;
}

MATCH_FUNC(0x422CE0)
int S422D50::M_422CE0(int i)
{
    if (i >= 0 && i <= 0x32)
        return arr_54[i];
    return 0;
}

class S424BC0 {
public:
    int field_0;
    int field_4;
    S424BC0* Init_424BC0(int v);
};

MATCH_FUNC(0x424BC0)
S424BC0* S424BC0::Init_424BC0(int v)
{
    field_0 = v;
    field_4 = 0;
    return this;
}

class S4260C0 {
public:
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    S4260C0* Clear_4260C0();
};

MATCH_FUNC(0x4260C0)
S4260C0* S4260C0::Clear_4260C0()
{
    field_0 = 0;
    field_4 = 0;
    field_8 = 0;
    field_c = 0;
    field_10 = 0;
    return this;
}

class S42C270 {
public:
    char pad_00[0x13c0];
    void Clear_42C270();
};

MATCH_FUNC(0x42C270)
void S42C270::Clear_42C270()
{
    for (int i = 0; i < 9; ++i)
        ((int*)this)[(0x13c0 / 4) + i] = 0;
}

class S42GetBulk {
public:
    int Get_422A70();
    int Get_422E10();
    int Get_42FBC0();
};

MATCH_FUNC(0x422A70)
int S42GetBulk::Get_422A70()
{
    return *(int*)((char*)this + 0x128);
}

MATCH_FUNC(0x422E10)
int S42GetBulk::Get_422E10()
{
    return *(int*)((char*)this + 0x120);
}

class S42SetImmBulk {
public:
    void Set_428C10();
};

MATCH_FUNC(0x428C10)
void S42SetImmBulk::Set_428C10()
{
    *(unsigned char*)((char*)this + 0x1e30) = 0x0;
}

class S42SetBulk {
public:
    void SetInt_422D40(int v);
    void SetInt_42E3D0(int v);
};

MATCH_FUNC(0x422D40)
void S42SetBulk::SetInt_422D40(int v)
{
    *(int*)((char*)this + 0x0) = v;
}

MATCH_FUNC(0x42E3D0)
void S42SetBulk::SetInt_42E3D0(int v)
{
    *(int*)((char*)this + 0x130c) = v;
}

class S430000 {
public:
    char pad_00[4];
    int field_4;
    char pad_08[0x10c8 - 0x08];
    unsigned int field_10c8;
    char pad_10cc[0x2010 - 0x10cc];
    int field_2010;
    char pad_2014[0x267c - 0x2014];
    int array_267c[0x40];

    int Cmp_42F620();
    int Get_42FB70(int* out);
    void Set_432B30(int index, int v);
};

MATCH_FUNC(0x42F620)
int S430000::Cmp_42F620()
{
    return field_10c8 > 6;
}

MATCH_FUNC(0x42FB70)
int S430000::Get_42FB70(int* out)
{
    *out = field_2010;
    return field_4;
}

class S432Accessors {
public:
    char pad_00[0x1c68];
    int field_1c68;
    char pad_1c6c[0x1e31 - 0x1c6c];
    unsigned char field_1e31;
    char pad_1e32[0x26a4 - 0x1e32];
    int field_26a4;
    char pad_26a8[0x2c44 - 0x26a8];
    int field_2c44;
    char pad_2c48[0x352c - 0x2c48];
    int field_352c;

    void Set1C68_4329B0(int v);
    int Get1E31_432100();
    int Get26A4_432B50();
    void Set26A4_432B60(int v);
    int Get2C44_432060();
    int Get352C_432CB0();
};

MATCH_FUNC(0x432060)
int S432Accessors::Get2C44_432060() { return field_2c44; }

MATCH_FUNC(0x432100)
int S432Accessors::Get1E31_432100() { return field_1e31; }

MATCH_FUNC(0x4329B0)
void S432Accessors::Set1C68_4329B0(int v) { field_1c68 = v; }

MATCH_FUNC(0x432B50)
int S432Accessors::Get26A4_432B50() { return field_26a4; }

MATCH_FUNC(0x432CB0)
int S432Accessors::Get352C_432CB0() { return field_352c; }

// Family 0x437A40/0x437AA0: a table of 96-byte entries from +0x50 with two dword
// fields (entry+0 -> +0x50, entry+0xC -> +0x5C). Bounded by field_2580.
struct E437A40 {
    int field_0;
    char pad_04[0xc - 0x04];
    int field_c;
    char pad_10[0x60 - 0x10];
};
class S437A40 {
public:
    char pad_00[0x50];
    E437A40 entries[1];
    char pad_b0[0x2580 - 0xb0];
    int field_2580;

    void M_437A40(int i, int v);
    void M_437AA0(int i, int v);
};

MATCH_FUNC(0x437A40)
void S437A40::M_437A40(int i, int v)
{
    if (i >= 0 && i <= field_2580)
        entries[i].field_0 = v;
}

MATCH_FUNC(0x437AA0)
void S437A40::M_437AA0(int i, int v)
{
    if (i >= 0 && i <= field_2580)
        entries[i].field_c = v;
}

class S437CA0 {
public:
    char pad_00[0x204];
    int Get_437CA0(int index);
    int Get_437CC0(int index);
    char* Get_437CE0(int index);
};

MATCH_FUNC(0x437CA0)
int S437CA0::Get_437CA0(int index)
{
    return *(int*)((char*)this + 0x204 + index * 616);
}

MATCH_FUNC(0x437CC0)
int S437CA0::Get_437CC0(int index)
{
    return *(int*)((char*)this + 0x208 + index * 616);
}

MATCH_FUNC(0x437CE0)
char* S437CA0::Get_437CE0(int index)
{
    return (char*)this + 0x22c + index * 616;
}

class S43A420Tail {
public:
    int field_0;
    int field_4;
    unsigned char field_8;
};

class S43A420 {
public:
    char pad_00[0x28];
    unsigned short field_28;
    int field_2c;
    char pad_30[0xd0 - 0x30];
    S43A420Tail tail_d0;
    int Init_43A420();
};

// The tail clear is an inlined memset intrinsic (own zero register, not CSE'd
// with the field_28/2c zero); the TU otherwise forces the memset call.
#pragma intrinsic(memset)
MATCH_FUNC(0x43A420)
int S43A420::Init_43A420()
{
    field_28 = 0;
    field_2c = 0;
    S43A420Tail* t = &tail_d0;
    return (int)memset(t, 0, 9);
}
#pragma function(memset)

class S43GetBulk {
public:
    int Get_437950();
    int Get_438630();
    int Get_438680();
};

MATCH_FUNC(0x437950)
int S43GetBulk::Get_437950()
{
    return *(int*)((char*)this + 0x2580);
}

MATCH_FUNC(0x438630)
int S43GetBulk::Get_438630()
{
    return *(int*)((char*)this + 0x238);
}

MATCH_FUNC(0x438680)
int S43GetBulk::Get_438680()
{
    return *(int*)((char*)this + 0x124);
}

class S43SetImmBulk {
public:
    void Set_431D90();
    void Set_43A440();
    void Set_43F9B0();
};

MATCH_FUNC(0x431D90)
void S43SetImmBulk::Set_431D90()
{
    *(int*)((char*)this + 0x206c) = 0x0;
}

MATCH_FUNC(0x43A440)
void S43SetImmBulk::Set_43A440()
{
    *(int*)((char*)this + 0x25bc) = 0x0;
}

MATCH_FUNC(0x43F9B0)
void S43SetImmBulk::Set_43F9B0()
{
    *(int*)((char*)this + 0x0) = 0x0;
}

class S43SetBulk {
public:
    void SetInt_438620(int v);
    void SetInt_43A070(int v);
    void SetInt_43A090(int v);
    void SetInt_43A0A0(int v);
    void SetInt_43A0B0(int v);
    void SetInt_43A410(int v);
};

MATCH_FUNC(0x438620)
void S43SetBulk::SetInt_438620(int v)
{
    *(int*)((char*)this + 0x118) = v;
}

MATCH_FUNC(0x43A070)
void S43SetBulk::SetInt_43A070(int v)
{
    *(int*)((char*)this + 0x28) = v;
}

MATCH_FUNC(0x43A090)
void S43SetBulk::SetInt_43A090(int v)
{
    *(int*)((char*)this + 0xc) = v;
}

MATCH_FUNC(0x43A0B0)
void S43SetBulk::SetInt_43A0B0(int v)
{
    *(int*)((char*)this + 0x14) = v;
}

MATCH_FUNC(0x43A410)
void S43SetBulk::SetInt_43A410(int v)
{
    *(int*)((char*)this + 0x25c0) = v;
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
MATCH_FUNC(0x428AE0)
int S428AE0::Get_428AE0(int index)
{
    return *(int*)((char*)this + 0x13bc + index * 4);
}
MATCH_FUNC(0x431CD0)
int S431CD0::Get_431CD0(int index)
{
    return *(int*)((char*)this + 0x1bf0 + index * 4);
}
MATCH_FUNC(0x4334F0)
int S4334F0::Get_4334F0(int index)
{
    return *(int*)((char*)this + 0x46bc + index * 4);
}

// sub_421860 (VA 0x421860, 0x11 bytes) - member: low bit of the byte at
// 0x9b5 + index.
class S421860 {
public:
    int M_421860(int index);
};

MATCH_FUNC(0x421860)
int S421860::M_421860(int index)
{
    return ((unsigned char*)this)[0x9b5 + index] & 1;
}

// sub_421BD0 (VA 0x421BD0) - member: sets bit 1 of the byte field at
// 0x9b5 + index to arg<<1, preserving bit 0.
class S421BD0 {
public:
    void M_421BD0(int index, unsigned char v);
};

MATCH_FUNC(0x421BD0)
void S421BD0::M_421BD0(int index, unsigned char v)
{
    unsigned char* p = (unsigned char*)this + 0x9b5 + index;
    *p = (*p & 1) | (v << 1);
}

// sub_421CC0 (VA 0x421CC0, 0xC bytes) - member: tail-calls the object at +0x1c.
class T465070 {
public:
    void Other_465070();
};
class S421CC0 {
public:
    void M_421CC0();
};

MATCH_FUNC(0x421CC0)
void S421CC0::M_421CC0()
{
    ((T465070*)*(char**)((char*)this + 0x1c))->Other_465070();
}

// sub_421F90 (VA 0x421F90) - member: stores the arg in global 0x65E3C0 and
// as a word at [field_24 + 0x8f8].
extern int g_65E3C0;
class S421F90 {
public:
    char pad_00[0x24];
    char* field_24;
    void M_421F90(int v);
};

MATCH_FUNC(0x421F90)
void S421F90::M_421F90(int v)
{
    g_65E3C0 = v;
    *(short*)(field_24 + 0x8f8) = v;
}

class S422420Global {
public:
    void Mark_4A00B0();
};

class S422420 {
public:
    char pad_00[0x420];
    int field_420;
    void Mark_422420();
};

MATCH_FUNC(0x422420)
void S422420::Mark_422420()
{
    field_420 = 1;
    ((S422420Global*)0x66ea48)->Mark_4A00B0();
}

// sub_422440 (VA 0x422440, 0x15 bytes) - member getter: dword at
// [+0x1b0]->+0x10e0, or -1 when null.
class S422440 {
public:
    int M_422440();
};

MATCH_FUNC(0x422440)
int S422440::M_422440()
{
    char* p = *(char**)((char*)this + 0x1b0);
    if (p == 0)
        return -1;
    return *(int*)(p + 0x10e0);
}

// sub_422960 (VA 0x422960) - member: pointer to entry index of a 520-byte
// table based at the pointer in +0x108.
class S422960 {
public:
    char pad_00[0x108];
    char* field_108;
    char* M_422960(int index);
};

MATCH_FUNC(0x422960)
char* S422960::M_422960(int index)
{
    return field_108 + (index * 65) * 8 + 8;
}

// sub_422DD0 (VA 0x422DD0, 0xB bytes) - member: tail-calls the object at +0x128
// when present, otherwise returns void.
class T58A9A0 {
public:
    void Other_58A9A0();
};
class S422DD0 {
public:
    void M_422DD0();
};

MATCH_FUNC(0x422DD0)
void S422DD0::M_422DD0()
{
    char* a = *(char**)((char*)this + 0x128);
    if (a != 0)
        ((T58A9A0*)a)->Other_58A9A0();
}

// sub_423810 (VA 0x423810) - member: fills 0x80 bytes at +0x194 (stdcall
// helper 0x6087EC) and returns that buffer pointer.
extern "C" void __stdcall sub_6087EC(char* buf, int len);
class S423810 {
public:
    char* M_423810();
};

MATCH_FUNC(0x423810)
char* S423810::M_423810()
{
    char* p = (char*)this + 0x194;
    sub_6087EC(p, 0x80);
    return p;
}

// sub_4238D0 (VA 0x4238D0) - member: pointer to entry index (160-byte stride)
// of the table based at +0x220; out of range/null returns global 0x64DB20.
extern char g_64DB20;
class S4238D0 {
public:
    char pad_00[0x218];
    unsigned int count_218;
    char pad_21c[0x220 - 0x21c];
    char* base_220;               // 160-byte entries
    char* Entry(unsigned i) { return base_220 + 160 * i; }
    char* M_4238D0(unsigned a2);
};

// The original recomputes the entry address for the return (inline getter
// called twice); a single local folds the null test into the add's flags.
MATCH_FUNC(0x4238D0)
char* S4238D0::M_4238D0(unsigned a2)
{
    if (Entry(a2) == 0 || a2 > count_218)
        return &g_64DB20;
    return Entry(a2);
}

// sub_4254D0 (VA 0x4254D0, 0x15 bytes) - member: field_1528 defaults to 1.
class S4254D0 {
public:
    void M_4254D0();
};

MATCH_FUNC(0x4254D0)
void S4254D0::M_4254D0()
{
    if (*(int*)((char*)this + 0x1528) == 0)
        *(int*)((char*)this + 0x1528) = 1;
}

// sub_42C290 (VA 0x42C290, 0x10 bytes) - member: field_12d4 <- result of the
// method at 0x42D0D0 (called on this).
class S42C290 {
public:
    int Method_42D0D0();
    char pad_00[0x12d4];
    int field_12d4;           // +0x12d4

    void M_42C290();
};

MATCH_FUNC(0x42C290)
void S42C290::M_42C290()
{
    field_12d4 = Method_42D0D0();
}

// sub_42D490 (VA 0x42D490, 0x14 bytes) - member: field_1c when field_10e4 is
// set, otherwise 1.
class S42D490 {
public:
    int M_42D490();
};

MATCH_FUNC(0x42D490)
int S42D490::M_42D490()
{
    if (*(int*)((char*)this + 0x10e4) != 0)
        return *(int*)((char*)this + 0x1c);
    return 1;
}

// sub_42DBB0 (VA 0x42DBB0, 0xC bytes) - member: tail-calls the object at +0x15f0.
class T4337C0 {
public:
    void Other_4337C0();
};
class S42DBB0 {
public:
    void M_42DBB0();
};

MATCH_FUNC(0x42DBB0)
void S42DBB0::M_42DBB0()
{
    ((T4337C0*)*(char**)((char*)this + 0x15f0))->Other_4337C0();
}

// The four "int" args are one 16-byte struct passed by value; the body is a
// struct assignment (`add ecx, 0x12dc` then [ecx], [ecx+4], ...).
struct S42F0B0Rect {
    int a, b, c, d;
};

class S42F0B0 {
public:
    char pad_00[0x12dc];
    S42F0B0Rect rect_12dc;
    void Set_42F0B0(S42F0B0Rect r);
};

MATCH_FUNC(0x42F0B0)
void S42F0B0::Set_42F0B0(S42F0B0Rect r)
{
    rect_12dc = r;
}

// sub_432040 (VA 0x432040, 0x14 bytes) - member: 0 when field_10e8 is set,
// otherwise field_10e4.
class S432040 {
public:
    int M_432040();
};

MATCH_FUNC(0x432040)
int S432040::M_432040()
{
    if (*(int*)((char*)this + 0x10e8) != 0)
        return 0;
    return *(int*)((char*)this + 0x10e4);
}

// sub_4320E0 (VA 0x4320E0, 0x15 bytes) - member: stores the arg byte at +0x1e31
// when field_1c is set.
class S4320E0 {
public:
    void M_4320E0(unsigned char v);
};

MATCH_FUNC(0x4320E0)
void S4320E0::M_4320E0(unsigned char v)
{
    if (*(int*)((char*)this + 0x1c) != 0)
        *(unsigned char*)((char*)this + 0x1e31) = v;
}

class S433E50 {
public:
    char pad_00[0x14];
    char* field_14;
    unsigned char field_18;
    unsigned char GetBit_433E50();
};

MATCH_FUNC(0x433E50)
unsigned char S433E50::GetBit_433E50()
{
    if (field_18 == 0)
        return 0;
    int w = *(int*)(field_14 + 4);
    unsigned char v = (unsigned char)w;
    v = v >> 1;
    v = v & 1;
    return v;
}

// sub_435830 (VA 0x435830, 0xF bytes) - member: copies the float at
// [+8]->+0x140 into this +0x168.
class S435830 {
public:
    void M_435830();
};

MATCH_FUNC(0x435830)
void S435830::M_435830()
{
    float* src = *(float**)((char*)this + 8);
    float t = *(float*)((char*)src + 0x140);
    *(float*)((char*)this + 0x168) = t;
}

// sub_438FA0 (VA 0x438FA0) - stdcall: copies a 16-byte (four dword) struct.
struct P438FA0 {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
};
MATCH_FUNC(0x438FA0)
extern "C" void __stdcall sub_438FA0(P438FA0* dst, P438FA0* src)
{
    *dst = *src;
}

// sub_43EBD0 (VA 0x43EBD0) - member: appends the arg to the array at +8 while
// the count at +4 is below 0x28; returns 1 on success, 0 when full.
class S43EBD0 {
public:
    char pad_00[4];
    int count_4;
    int arr_8[1];
    int M_43EBD0(int v);
};

MATCH_FUNC(0x43EBD0)
int S43EBD0::M_43EBD0(int v)
{
    if (count_4 >= 0x28)
        return 0;
    arr_8[count_4] = v;
    count_4++;
    return 1;
}

// Game-region wrapper members that forward an int arg to a field-owned object.
class S425680 {
public:
    char pad_00[0x15fc];
    S43SetBulk* field_15fc;

    void M_425680(int a1);
};
MATCH_FUNC(0x425680)
void S425680::M_425680(int a1)
{
    field_15fc->SetInt_43A0B0(a1);
}

class S4256A0 {
public:
    char pad_00[0x15f8];
    S43SetBulk* field_15f8;

    void M_4256A0(int a1);
};
MATCH_FUNC(0x4256A0)
void S4256A0::M_4256A0(int a1)
{
    field_15f8->SetInt_438620(a1);
}

class S4266B0 {
public:
    char pad_00[0x15fc];
    S43SetBulk* field_15fc;

    void M_4266B0(int a1);
};
MATCH_FUNC(0x4266B0)
void S4266B0::M_4266B0(int a1)
{
    field_15fc->SetInt_43A0B0(a1);
}

// 0x438EB0 takes its arg through a member-call ABI at the field-owned object.
class T438EB0 {
public:
    void Other_438EB0(int a1);
};

class S42FD00 {
public:
    char pad_00[0x15f8];
    T438EB0* field_15f8;

    void M_42FD00(int a1);
};
MATCH_FUNC(0x42FD00)
void S42FD00::M_42FD00(int a1)
{
    field_15f8->Other_438EB0(a1);
}

// 0x421A50 — tail-forward through the pointer at +0x1c.
class T464AF0 {
public:
    int Other_464AF0();
};

class S421A50 {
public:
    char pad_00[0x1c];
    T464AF0* field_1c;

    int M_421A50();
};
MATCH_FUNC(0x421A50)
int S421A50::M_421A50()
{
    return field_1c->Other_464AF0();
}

// 0x437BF0 — call a two-argument app helper with the global and a constant.
extern int g_669558;
extern void __cdecl sub_4378C0(int a1, int a2);

class S437BF0 {
public:
    void M_437BF0();
};
MATCH_FUNC(0x437BF0)
void S437BF0::M_437BF0()
{
    sub_4378C0(g_669558, 0x650EE0);
}

// 0x436E60 — free __cdecl call with a zero argument.
extern int __stdcall sub_436E70(int a1);
MATCH_FUNC(0x436E60)
int __cdecl sub_436E60()
{
    return sub_436E70(0);
}

// 0x437410 — free __cdecl call with two zero arguments.
extern int __stdcall sub_437420(int a1, int a2);
MATCH_FUNC(0x437410)
int __cdecl sub_437410()
{
    return sub_437420(0, 0);
}

// 0x438C00 — forward 50 through the object at +0x104.
class T4BEFD0 {
public:
    int Other_4BEFD0(int a1);
};
class S438C00 {
public:
    char pad_00[0x104];
    T4BEFD0* field_104;

    int M_438C00();
};
MATCH_FUNC(0x438C00)
int S438C00::M_438C00()
{
    return field_104->Other_4BEFD0(50);
}

// 0x439C90 — free __cdecl forwarding call with two arguments.
class T439840 {
public:
    int Other_439840(void* dst, char* str);
};
class S439C90 {
public:
    int M_439C90(void* dst, char* str);
};
MATCH_FUNC(0x439C90)
int S439C90::M_439C90(void* dst, char* str)
{
    return ((T439840*)this)->Other_439840(dst, str);
}

// 0x43E7B0 — install the vtable pointer and forward through the same object.
class T440B30 {
public:
    void Other_440B30();
};
class S43E7B0 {
public:
    void M_43E7B0();
};
MATCH_FUNC(0x43E7B0)
void S43E7B0::M_43E7B0()
{
    *(void**)this = (void*)0x61E8C0;
    ((T440B30*)this)->Other_440B30();
}

// 0x43EB40 — forward through the global object at 0x665660.
extern char g_665660;
class T43EB70 {
public:
    int Other_43EB70();
    void Other_43EB90();
};
MATCH_FUNC(0x43EB40)
int __cdecl sub_43EB40()
{
    return ((T43EB70*)&g_665660)->Other_43EB70();
}

// 0x43EB50 — register the thunk at 0x43EB60 with the CRT callback helper.
extern void sub_43EB60();
extern void __cdecl sub_5FD62D(void* fn);
MATCH_FUNC(0x43EB50)
void __cdecl sub_43EB50()
{
    sub_5FD62D((void*)&sub_43EB60);
}

// 0x43EB70 — clear the object through its init helper and return itself.
class S43EB70 {
public:
    int M_43EB70();
};
MATCH_FUNC(0x43EB70)
int S43EB70::M_43EB70()
{
    ((T43EB70*)this)->Other_43EB90();
    return (int)this;
}

// 0x438F00 — tail-call forwarder to 0x438F10.
extern void sub_438F10();
MATCH_FUNC(0x438F00)
void __cdecl sub_438F00()
{
    sub_438F10();
}

// 0x43EB30 — call 0x43EB40 and tail-jump to 0x43EB50.
MATCH_FUNC(0x43EB30)
void __cdecl sub_43EB30()
{
    sub_43EB40();
    sub_43EB50();
}

// 0x428460 — one-argument wrapper with a leading zero argument.
extern void __stdcall sub_428470(int a1, int a2);
MATCH_FUNC(0x428460)
void __stdcall sub_428460(int a1)
{
    sub_428470(a1, 0);
}

// 0x431680 — two chained helper calls.
class T431710 {
public:
    void Other_431710();
};
class S431680 {
public:
    void M_431680();
};
extern void __cdecl sub_4316A0();
MATCH_FUNC(0x431680)
void S431680::M_431680()
{
    sub_4316A0();
    ((T431710*)this)->Other_431710();
}

// 0x421CB0 — tail-call through the vtable slot at +0xc8 of the field at +0x41c.
// Slot 0xc8/4 = 50 is the method tail-called by 0x421CB0.
class T421CB0 {
public:
    virtual void Slot_00();
    virtual void Slot_04();
    virtual void Slot_08();
    virtual void Slot_0c();
    virtual void Slot_10();
    virtual void Slot_14();
    virtual void Slot_18();
    virtual void Slot_1c();
    virtual void Slot_20();
    virtual void Slot_24();
    virtual void Slot_28();
    virtual void Slot_2c();
    virtual void Slot_30();
    virtual void Slot_34();
    virtual void Slot_38();
    virtual void Slot_3c();
    virtual void Slot_40();
    virtual void Slot_44();
    virtual void Slot_48();
    virtual void Slot_4c();
    virtual void Slot_50();
    virtual void Slot_54();
    virtual void Slot_58();
    virtual void Slot_5c();
    virtual void Slot_60();
    virtual void Slot_64();
    virtual void Slot_68();
    virtual void Slot_6c();
    virtual void Slot_70();
    virtual void Slot_74();
    virtual void Slot_78();
    virtual void Slot_7c();
    virtual void Slot_80();
    virtual void Slot_84();
    virtual void Slot_88();
    virtual void Slot_8c();
    virtual void Slot_90();
    virtual void Slot_94();
    virtual void Slot_98();
    virtual void Slot_9c();
    virtual void Slot_a0();
    virtual void Slot_a4();
    virtual void Slot_a8();
    virtual void Slot_ac();
    virtual void Slot_b0();
    virtual void Slot_b4();
    virtual void Slot_b8();
    virtual void Slot_bc();
    virtual void Slot_c0();
    virtual void Slot_c4();
    virtual void Slot_c8();
};
class S421CB0 {
public:
    char pad_00[0x41c];
    T421CB0* field_41c;           // +0x41c
    void M_421CB0();
};
MATCH_FUNC(0x421CB0)
void S421CB0::M_421CB0()
{
    field_41c->Slot_c8();
}

// Scalar deleting destructor wrappers.
extern int __cdecl sub_5F90B0(int a1);

class Td4235c0 {
public:
    void Other_4235c0();
};
class Sd423360 {
public:
    Sd423360* D_423360(int flags);
};
MATCH_FUNC(0x423360)
Sd423360* Sd423360::D_423360(int flags)
{
    ((Td4235c0*)this)->Other_4235c0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td434860 {
public:
    void Other_434860();
};
class Sd4347D0 {
public:
    Sd4347D0* D_4347D0(int flags);
};
MATCH_FUNC(0x4347D0)
Sd4347D0* Sd4347D0::D_4347D0(int flags)
{
    ((Td434860*)this)->Other_434860();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td43a3f0 {
public:
    void Other_43a3f0();
};
class Sd43A3D0 {
public:
    Sd43A3D0* D_43A3D0(int flags);
};
MATCH_FUNC(0x43A3D0)
Sd43A3D0* Sd43A3D0::D_43A3D0(int flags)
{
    ((Td43a3f0*)this)->Other_43a3f0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td43e7b0 {
public:
    void Other_43e7b0();
};
class Sd43E790 {
public:
    Sd43E790* D_43E790(int flags);
};
MATCH_FUNC(0x43E790)
Sd43E790* Sd43E790::D_43E790(int flags)
{
    ((Td43e7b0*)this)->Other_43e7b0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

// 0x422A40 — helper call then release the pointer field at +0x128.
class Tr422D00 {
public:
    void Other_422D00();
};
class Tr58A7E0 {
public:
    void Other_58A7E0();
};
class Sr422A40 {
public:
    char pad_00[0x128];
    Tr58A7E0* field_128;          // +0x128
    void M_422A40();
};
extern int __cdecl sub_5F90B0(int a1);
MATCH_FUNC(0x422A40)
void Sr422A40::M_422A40()
{
    ((Tr422D00*)this)->Other_422D00();
    Tr58A7E0* p = this->field_128;
    if (p) {
        p->Other_58A7E0();
        sub_5F90B0((int)p);
    }
}

// 0x433750 — helper call then release the pointer field at +0x1c.
class Tr433780 {
public:
    void Other_433780();
};
class Tr4378C0 {
public:
    void Other_4378C0();
};
class Sr433750 {
public:
    char pad_00[0x1c];
    Tr4378C0* field_1c;           // +0x1c
    void M_433750();
};
MATCH_FUNC(0x433750)
void Sr433750::M_433750()
{
    ((Tr433780*)this)->Other_433780();
    Tr4378C0* p = this->field_1c;
    if (p) {
        p->Other_4378C0();
        sub_5F90B0((int)p);
    }
}

// 0x421C70 — conditional one-argument thiscall on the field at +0x41c.
class Tc5E3100 {
public:
    void Other_5E3100(int a1);
};
class Sc421C70 {
public:
    char pad_00[0x41c];
    Tc5E3100* field_41c;          // +0x41c
    void M_421C70(int a1);
};
MATCH_FUNC(0x421C70)
void Sc421C70::M_421C70(int a1)
{
    if (this->field_41c)
        this->field_41c->Other_5E3100(a1);
}

// 0x421C90 — conditional one-argument thiscall on the field at +0x41c.
class Tc5E3120 {
public:
    void Other_5E3120(int a1);
};
class Sc421C90 {
public:
    char pad_00[0x41c];
    Tc5E3120* field_41c;          // +0x41c
    void M_421C90(int a1);
};
MATCH_FUNC(0x421C90)
void Sc421C90::M_421C90(int a1)
{
    if (this->field_41c)
        this->field_41c->Other_5E3120(a1);
}

// 0x423900 — 160-byte record index with a fallback object.
extern char g_64db20;
class Sc423900 {
public:
    char pad_00[0x21c];
    unsigned int field_21c;       // +0x21C
    int field_220;                // +0x220
    void* Get_423900(unsigned int a1);
};
MATCH_FUNC(0x423900)
void* Sc423900::Get_423900(unsigned int a1)
{
    if (a1 > this->field_21c)
        return (void*)&g_64db20;
    int base = this->field_220;
    void* p = (void*)(base + (int)(a1 * 160 + 0x20));
    if (p != 0)
        return p;
    return (void*)&g_64db20;
}

// 0x425650 — two one-argument stores through the +0x15fc subobject.
class T425650Sub {
public:
    void Hook_43A0A0(int a1);
    void Hook_43A090(int a1);
};
class Sc425650 {
public:
    char pad_00[0x15fc];
    T425650Sub* field_15fc;       // +0x15FC
    void M_425650(int a1);
};
MATCH_FUNC(0x425650)
void Sc425650::M_425650(int a1)
{
    this->field_15fc->Hook_43A0A0(a1);
    this->field_15fc->Hook_43A090(a1);
}

// 0x422180 — compare a trimmed +0x518 string of the basegame object with a1.
extern int (__stdcall *g_61C2D8)(char* a1);
extern void __cdecl sub_5FCB40(char* dst, char* src, int n);
extern int __cdecl sub_5FCC80(char* a1, int a2);
class Sc422180 {
public:
    char pad_00[0x24];
    void* field_24;               // +0x24 basegame object
    bool M_422180(int a1);
};
MATCH_FUNC(0x422180)
bool Sc422180::M_422180(int a1)
{
    char buf[0x100];
    sub_5FCB40(buf, (char*)this->field_24 + 0x518, 0xff);
    buf[0xff] = 0;
    g_61C2D8(buf);
    if (sub_5FCC80(buf, a1))
        return 1;
    return 0;
}

// 0x439410 — clear the ten 0xA0-stride records and the four head fields.
// The four head fields are cleared by an inlined memset intrinsic: its own
// zero register (ecx after the call) instead of a zero kept in edi across it.
extern void __cdecl Hook_5FCE14_439410(void* a1, int a2);
struct R439410 {
    int field_0;
    char pad_04[0xa0 - 4];
};
class T439410 {
public:
    int field_0;                  // +0x00
    int field_4;                  // +0x04
    int field_8;                  // +0x08
    int field_c;                  // +0x0C
    int field_10;                 // +0x10
    int field_14;                 // +0x14
    int field_18;                 // +0x18
    char name_1c[0x5c4 - 0x1c];   // +0x1C
    R439410 recs[10];             // +0x5C4
};
#pragma intrinsic(memset)
MATCH_FUNC(0x439410)
void __stdcall sub_439410(T439410* a1)
{
    a1->field_10 = 0x11;
    a1->field_14 = 0;
    a1->field_18 = 0;
    for (int i = 0; i < 10; i++)
        a1->recs[i].field_0 = 0;
    Hook_5FCE14_439410(a1->name_1c, 0x662be0);
    memset(a1, 0, 16);
}
#pragma function(memset)

// 0x439CB0 — constructor seeding the 0x37 0x24-stride records.
extern void __cdecl Hook_439CB0_log(int a1, int a2, int a3);
class Sc439CB0 {
public:
    int field_0;                  // +0x00
    int field_4;                  // +0x04
    int field_8;                  // +0x08
    int field_c;                  // +0x0C
    int field_10;                 // +0x10
    int field_14;                 // +0x14
    int field_18;                 // +0x18
    int field_1c;                 // +0x1C
    int field_20;                 // +0x20
    int field_24;                 // +0x24
    int field_28;                 // +0x28
    int field_2c;                 // +0x2C
    int field_30;                 // +0x30
    int field_34;                 // +0x34
    Sc439CB0* Init_439CB0(int a1);
};
MATCH_FUNC(0x439CB0)
Sc439CB0* Sc439CB0::Init_439CB0(int a1)
{
    field_0 = a1;
    field_4 = 0x3e8;
    field_8 = 0xa;
    Hook_439CB0_log(g_669558, 0x651134, 0xa);
    int v = 1;
    field_c = v;
    field_24 = v;
    field_1c = v;
    field_18 = 0;
    field_20 = 0;
    field_28 = 0;
    field_2c = 0;
    field_14 = 0;
    field_10 = 0;
    int* rec = (int*)((char*)this + 0x40);
    for (int i = 0; i < 0x37; i++) {
        rec[-1] = 0;
        rec[0] = 0;
        rec[1] = 0;
        rec[2] = 0;
        rec[3] = 0;
        rec[4] = 0;
        rec[5] = 0;
        rec[6] = 0;
        rec[-2] = 0;
        rec += 0x24 / 4;
    }
    field_34 = 0x28;
    return this;
}

// 0x42D1D0 — broadcast one clock value into two 0x50-byte parallel arrays at
// +0x1348/+0x1398 for indices 1..the word count at +0x12D8.
extern int (__cdecl *g_61C3C8)();
class S42D1D0 {
public:
    char pad_00[0x12d8];          // 0x00..0x12D8
    unsigned short count_12d8;    // +0x12D8
    char pad_12da[0x1348 - 0x12da]; // 0x12DA..0x1348
    int arr_1348[20];             // +0x1348..0x1398
    int arr_1398[20];             // +0x1398..0x13E8
    void M_42D1D0();
    void M_42AE00();
};

MATCH_FUNC(0x42D1D0)
void S42D1D0::M_42D1D0()
{
    int v = g_61C3C8();
    for (int i = 1; i <= count_12d8; i++)
    {
        ((int*)((char*)this + 0x1348))[i - 1] = v;
        ((int*)((char*)this + 0x1398))[i - 1] = v;
    }
}

// 0x42AE00 — reset the five +0x13E4 record fields for every count slot, after
// the two-argument 0x4378C0 screen helper.
WIP_FUNC(0x42AE00)
void S42D1D0::M_42AE00()
{
    sub_4378C0(g_669558, 0x64f114);
    int* p = (int*)((char*)this + 0x13e4);
    for (int i = 0; i <= count_12d8; i++)
    {
        *(int*)((char*)p + 0x9fc) = 0;
        *p = 0;
        *(int*)((char*)p + 0x28) = 0;
        *(int*)((char*)p + 0x50) = 0;
        *(int*)((char*)p + 0xcc) = 0;
        p++;
    }
}

// 0x43E740 — base-constructor call, own 0x61E8C0 vtable, then zero the nine
// +0x10D4..+0x10F8 state slots.
class T440A90 {
public:
    void Other_440A90();
};
class S43E740 {
public:
    void* vtbl_00;                // +0x00 vtable 0x61E8C0
    char pad_04[0x10d4 - 0x04];
    int field_10d4;               // +0x10D4
    int field_10d8;               // +0x10D8
    int field_10dc;               // +0x10DC
    int field_10e0;               // +0x10E0
    int field_10e4;               // +0x10E4
    int field_10e8;               // +0x10E8
    int field_10ec;               // +0x10EC
    char pad_10f0[4];             // 0x10F0..0x10F4
    int field_10f4;               // +0x10F4
    int field_10f8;               // +0x10F8
    S43E740* M_43E740();
};

MATCH_FUNC(0x43E740)
S43E740* S43E740::M_43E740()
{
    ((T440A90*)this)->Other_440A90();
    *(void**)this = (void*)0x61E8C0;
    field_10d4 = 0;
    field_10d8 = 0;
    field_10dc = 0;
    field_10e0 = 0;
    field_10e4 = 0;
    field_10e8 = 0;
    field_10ec = 0;
    field_10f4 = 0;
    field_10f8 = 0;
    return this;
}
