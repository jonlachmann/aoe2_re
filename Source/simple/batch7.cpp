#include "Function.hpp"

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
