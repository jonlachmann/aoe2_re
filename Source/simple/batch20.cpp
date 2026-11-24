// Batch 20: verified leaf helpers written manually as class methods.
// Direct translations of Source/autopilot/auto_*.c with `self[N]` replaced by
// declared fields at the same byte offsets; arithmetic order preserved.
#include "Function.hpp"

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

WIP_FUNC(0x494DA0)
int S494DA0Body::Compute_494DA0(float a2)
{
    this->field_c8 = a2;
    int result = (int)this->field_00;
    double v3 = (double)*(int*)(result + 8);
    this->field_cc = a2;
    this->field_d0 = (float)(v3 - a2);
    this->field_d4 = (float)((double)*(int*)(result + 12) - a2);
    return result;
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
    char field_14;                // +20

    char Round_4A9F20();
};

WIP_FUNC(0x4A9F20)
char S4A9F20::Round_4A9F20()
{
    char result = this->field_14;
    result = (char)((result + 3) & 0xFC);
    return result;
}

// 0x4AC3E0 — cluster C_cluster_4AC3E0. Bounded record lookup through a table.
class S4AC3E0 {
public:
    char pad_00[41*4];
    int count;                    // self[41]
    int* records;                 // self[42]

    int Get_4AC3E0(__int16 a2, int* a3);
};

MATCH_FUNC(0x4AC3E0)
int S4AC3E0::Get_4AC3E0(__int16 a2, int* a3)
{
    if (a2 < 0 || a2 >= this->count)
        return 0;
    *a3 = *(int*)((char*)this->records + 4 * a2);
    return 1;
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

WIP_FUNC(0x4E8230)
char S4E8230::Check_4E8230(int a2)
{
    int* v2 = this->field_1200;
    int* v3 = *(int**)((char*)v2 + 76);
    int* v4 = *(int**)((char*)v3 + 4 * a2);
    int* v5 = *(int**)((char*)v4 + 168);
    return *(unsigned char*)((char*)v2 + 650) &&
           *(float*)((char*)v5 + 28) > 0.0f;
}

// 0x501980 — member of vtable class C_vt625DA4: set a flag for two values.
class S501980 {
public:
    char pad_00[703*4];
    int field_afc;                // self[703]

    int Set_501980(int a2, int a3, int a4, int a5, int a6);
};

MATCH_FUNC(0x501980)
int S501980::Set_501980(int a2, int a3, int a4, int a5, int a6)
{
    (void)a3; (void)a4; (void)a5; (void)a6;
    if (a2 == 27 || a2 == 32)
        this->field_afc = 1;
    return 0;
}

// 0x520130 — cluster C_cluster_5200F0. Reset scattered counters and flags.
class S520130 {
public:
    char pad_00[4];
    unsigned char flag_04;        // +4
    unsigned char flag_05;        // +5
    char pad_06[8 - 6];
    int field_08;                 // +8
    int field_0c;                 // +12
    int field_10;                 // +16
    int field_14;                 // +20
    int field_18;                 // +24
    int field_1c;                 // +28
    unsigned char flag_20;        // +32
    char pad_21[292 - 33];
    int field_124;                // +292
    int field_128;                // +296
    char pad_12c[1948 - 300];
    int field_79c;                // +1948

    int Reset_520130();
};

MATCH_FUNC(0x520130)
int S520130::Reset_520130()
{
    int result = 0;
    this->field_18 = 1;
    this->flag_04 = 0;
    this->field_08 = 0;
    this->field_0c = 0;
    this->field_10 = 0;
    this->field_14 = 0;
    this->flag_05 = 0;
    this->field_79c = 0;
    this->field_1c = 0;
    this->field_124 = 0;
    this->field_128 = 0;
    this->flag_20 = 0;
    return result;
}

// 0x5219B0 — cluster C_cluster_520CE0. Search a singly linked node list.
class S5219B0 {
public:
    char pad_00[32*4];
    int* head;                    // self[32]

    int Find_5219B0(int a2);
};

WIP_FUNC(0x5219B0)
int S5219B0::Find_5219B0(int a2)
{
    int* v2 = this->head;
    if (!v2)
        return 0;
    while (*(int*)(*(int*)((char*)v2 + 8)) != a2) {
        v2 = *(int**)((char*)v2 + 4);
        if (!v2)
            return 0;
    }
    return *(int*)((char*)v2 + 8);
}

// 0x5219E0 — same node search on the previous list head field.
class S5219E0 {
public:
    char pad_00[31*4];
    int* head;                    // self[31]

    int Find_5219E0(int a2);
};

WIP_FUNC(0x5219E0)
int S5219E0::Find_5219E0(int a2)
{
    int* v2 = this->head;
    if (!v2)
        return 0;
    while (*(int*)(*(int*)((char*)v2 + 8)) != a2) {
        v2 = *(int**)((char*)v2 + 4);
        if (!v2)
            return 0;
    }
    return *(int*)((char*)v2 + 8);
}

// 0x524320 — first matching word pair in a small tag list.
class S524320 {
public:
    char pad_00[602*4];
    int* field_968;               // self[602]

    int Lookup_524320();
};

WIP_FUNC(0x524320)
int S524320::Lookup_524320()
{
    int* v1 = this->field_968;
    if (!v1)
        return 0;
    if (*(unsigned char*)((char*)v1 + 4) != 70)
        return 0;
    __int16 v3 = *(__int16*)((char*)v1 + 290);
    int result = 0;
    if (v3 > 0) {
        __int16* v4 = *(__int16**)((char*)v1 + 292);
        do {
            if (*v4 == 3)
                result = v4[1];
            v4 += 2;
            --v3;
        } while (v3);
    }
    return result;
}

// 0x5247E0 — set or clear bit 4 of a member's byte flag.
int __stdcall sub_5247E0(int a1, int a2);

WIP_FUNC(0x5247E0)
int __stdcall sub_5247E0(int a1, int a2)
{
    int result = a1;
    if (a1) {
        unsigned char v3 = *(unsigned char*)(a1 + 64);
        if (a2)
            *(unsigned char*)(a1 + 64) = v3 & 0xEF;
        else
            *(unsigned char*)(a1 + 64) = v3 | 0x10;
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

WIP_FUNC(0x52C430)
float* S52C430::Copy_52C430(float* a2)
{
    float* result = a2;
    float v3 = this->field_40;
    float v4 = this->field_3c;
    *a2 = this->field_38;
    a2[1] = v3;
    a2[2] = v4;
    return result;
}

// 0x52C6A0 — member of vtable class C_vt61CE24: dereference a member pointer.
class S52C6A0 {
public:
    char pad_00[9*4];
    int* field_24;                // self[9]

    int Get_52C6A0();
};

MATCH_FUNC(0x52C6A0)
int S52C6A0::Get_52C6A0()
{
    int* result = this->field_24;
    if (!result)
        return (int)result;
    return *(int*)((char*)result + 4);
}

// 0x531F00 — member of vtable class C_vt627428: bounded table read.
class S531F00 {
public:
    char pad_00[114*4];
    int* table[4];                // self[114...]

    int Get_531F00(int a2);
};

MATCH_FUNC(0x531F00)
int S531F00::Get_531F00(int a2)
{
    int* v2;
    if (a2 >= 0 && a2 < 4 && (v2 = this->table[a2]) != 0)
        return *(int*)((char*)v2 + 4);
    else
        return -1;
}

// 0x535E90 — member of vtable class C_vt627428: type predicate.
class S535E90 {
public:
    char pad_00[8];
    int* field_08;                // self[2]

    char Check_535E90(int a2);
};

MATCH_FUNC(0x535E90)
char S535E90::Check_535E90(int a2)
{
    int* v2 = this->field_08;
    int v3 = *(__int16*)((char*)v2 + 22);
    char result;
    if (v3 != 9 && v3 != 10 && v3 != 58 || a2 == 4 ||
        *(unsigned char*)((char*)v2 + 4) == 60)
        result = 1;
    else
        result = 0;
    return result;
}

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

// ---------------------------------------------------------------------------
// WIP group notes (byte-exact matching against VC6 /O2):
//
// register-allocation inversion: the original keeps a counter/pointer in a
// different register than VC6 /O2 chooses here even with identical source
// order (438840, 524320, 5247E0). Needs an explicit temporary or a different
// operand shape, not a semantic change.
//
// branch/return layout inversion: original falls through to a return at the
// end while VC6 places the failure path inline (5219B0, 5219E0, 539890,
// 5398D0, 54BDB0). The generated bodies are semantically equivalent.
//
// FPU/stack temporaries: original keeps interleaved float temporaries on its
// own stack slots, while /O2 folds the two float copies into registers
// (494DA0, 52C430). Same code shape problem as batch18's stack-triple WIPs.
//
// narrow-code emission: VC6 refuses to emit a byte load/add here and widens
// the expression to dword (4A9F20).
//
// pointer-chain widening: original dereferences one extra pointer level
// (4E8230) and keeps the cached member in ECX; generated code differs by
// three bytes around the FPU compare.
//
// cached-value selector: original keeps the argument in EAX and the cached
// value in ECX; VC6 swaps them (48BF10).
//
// bounded-50 scan: original emits `jl` back to the loop and falls through to
// `ret`; VC6 hoists the 50-check and pushes ESI to keep the pointer (4567F0).
//
// float-array fill: original emits the +inf constant as a store immediate and
// reloads the count each iteration; VC6 caches the constant and pointer in
// ESI (472A70).
// ---------------------------------------------------------------------------
