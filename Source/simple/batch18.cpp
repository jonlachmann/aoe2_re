// Batch 18: verified leaf helpers promoted into readable classes.
// Each body starts from Source/autopilot/auto_*.c and is checked byte-for-byte
// against the reference executable with Scripts/match.py.
#include "Function.hpp"

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

// 0x433500 — write a value into a slot only when the slot currently holds 5.
class S433500Slots {
public:
    char pad_00[0x46bc];
    int slots[1];                // 0x46bc

    int Set_433500(int index, int value);
};

