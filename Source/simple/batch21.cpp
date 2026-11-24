// Batch 21: verified leaf helpers written manually as class methods.
// Direct translations of Source/autopilot/auto_*.c with declared fields at the
// same byte offsets. A catalog size that disagrees with the decompiled body is
// called out in the comment for that function.
#include "Function.hpp"

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

// 0x587440 — small tag-to-slot mapping; -1 when unknown.
int __stdcall sub_587440(int a1);

MATCH_FUNC(0x587440)
int __stdcall sub_587440(int a1)
{
    if (a1 == 31 || a1 == 5 || a1 == 33)
        return 2;
    else
        return -1;
}

// 0x594E70 — cluster C_cluster_594060. Set a member flag and report success.
int __stdcall sub_594E70(int a1);

MATCH_FUNC(0x594E70)
int __stdcall sub_594E70(int a1)
{
    int result = a1;
    if (!a1)
        return result;
    *(int*)(a1 + 8) = 1;
    return 1;
}

// 0x5955C0 — first element of an optional array behind byte flag +32.
int __stdcall sub_5955C0(char* a1);

WIP_FUNC(0x5955C0)
int __stdcall sub_5955C0(char* a1)
{
    int result = -1;
    if (!a1)
        return -1;
    if (*(unsigned char*)(a1 + 32))
        return **(int**)(a1 + 36);
    return result;
}

// 0x5955E0 — same pattern with byte flag +24 and array +28.
int __stdcall sub_5955E0(char* a1);

WIP_FUNC(0x5955E0)
int __stdcall sub_5955E0(char* a1)
{
    int result = -1;
    if (!a1)
        return -1;
    if (*(unsigned char*)(a1 + 24))
        return **(int**)(a1 + 28);
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

// 0x5A46C0 — member of vtable class C_vt62B750. The catalog split this
// function at 0x5A46C6; the binary continues through the 5-iteration clear
// loop and returns self + 1830, so the whole body is reconstructed here.
class S5A46C0 {
public:
    char pad_00[0x1c48];

    int* End_5A46C0();
};

MATCH_FUNC(0x5A46C0)
int* S5A46C0::End_5A46C0()
{
    int* result = (int*)this + 1810;
    int v2 = 5;
    do {
        *(result - 2) = 0;
        *result = 0;
        result += 4;
        --v2;
    } while (v2);
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

WIP_FUNC(0x5BB000)
int S5BB000::Set_5BB000(int a2, int a3)
{
    int result = a2;
    char v4;
    int idx = a2 + 4636;
    if (a2 == 1) {
        v4 = (char)a3;
        if (a3 == a2) {
            ((char*)this)[idx] = (char)a2;
            return result;
        }
    } else {
        v4 = (char)a3;
    }
    ((char*)this)[idx] = v4;
    return result;
}

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

// 0x5C1A00 — cluster C_cluster_4CED80: 20-byte record array at 0x1BAC,
// indexed by a2 + 12 * count (count at 0x4CD4).
class S5C1A00 {
public:
    char pad_00[1771 * 4];
    int records[0x3128 / 4];      // 0x1BAC .. 0x4CD4
    int count;                    // 0x4CD4

    int Get_5C1A00(int a2);
};

MATCH_FUNC(0x5C1A00)
int S5C1A00::Get_5C1A00(int a2)
{
    return this->records[180 * this->count + 15 * a2];
}

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

// ---------------------------------------------------------------------------
// WIP group notes (byte-exact matching against VC6 /O2):
//
// loop pipelining / callee-saved register: the original advances the record
// pointer and re-tests at the loop head, but VC6 /O2 caches the next pointer in
// ESI and folds the head test into the loop bottom (580AF0). Same code shape
// problem as earlier bounded-scan WIPs.
//
// argument-register inversion: the original keeps the incoming pointer in ECX
// and the -1 fallback in EAX; here VC6 loads the pointer into EAX and only
// materializes -1 on the return edges (5955C0, 5955E0). The branch layout of
// the valid path differs only in register choice.
//
// constant-propagation / branch order: inside `if (a2 == 1)`, the original
// still compares a3 against the live a2 in EAX and stores through the generic
// index expression; VC6 folds a2 to 1, uses an immediate compare, and reorders
// the return edges (5BB000).
//
// Catalog correction: 0x5A46C0 was split into 0x5A46C0 (6 bytes) +
// 0x5A46C6 (19 bytes) by the start finder; the binary body is continuous
// through the 5-iteration clear loop, so data/disasm32_catalog.json merged the
// fragment back into a single 25-byte function to match it.
// ---------------------------------------------------------------------------
