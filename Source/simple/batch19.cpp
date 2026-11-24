// Batch 19: verified leaf helpers written manually as class methods.
// Each body is a direct translation of Source/autopilot/auto_*.c, keeping the
// decompiler's arithmetic, operand order and control flow, with `self[N]`
// replaced by declared fields at the same byte offsets.
#include "Function.hpp"

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
    int count;                    // self[144]
    int values[0x100];            // self[145...]

    unsigned Append_438840(int a2, int a3);
};

WIP_FUNC(0x438840)
unsigned S438840::Append_438840(int a2, int a3)
{
    this->values[20 * a2 + this->count] = a3;
    this->count = this->count + 1;
    unsigned result = this->count;
    if (result >= 0x14)
        this->count = 0;
    return result;
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

// 0x446050 — free helper: round a size, report a signed value and direction.
int __cdecl sub_446050(int a1, unsigned int* a2, int* a3, int* a4);

MATCH_FUNC(0x446050)
int __cdecl sub_446050(int a1, unsigned int* a2, int* a3, int* a4)
{
    int result;
    *a2 = (*(int*)(a1 + 4) + 3) & 0xFFFFFFFC;
    result = *(int*)(a1 + 8);
    *a3 = result;
    if (result < 0) {
        *a3 = -result;
        result = (int)a4;
        *a4 = 1;
    } else {
        *a4 = -1;
    }
    return result;
}

// 0x4567F0 — scan a positive-dword array, append at the first non-positive.
class S4567F0 {
public:
    char pad_00[528*4];
    int values[0x100];            // self[528...]

    int Add_4567F0(int a2);
};

WIP_FUNC(0x4567F0)
int S4567F0::Add_4567F0(int a2)
{
    int result = 0;
    int* i = (int*)this + 528;
    while (*i > 0) {
        ++result;
        ++i;
        if (result >= 50)
            break;
    }
    if (result >= 50)
        return result;
    this->values[result] = a2;
    return result;
}

// 0x45AB10 — two derived dimensions computed from the same base field.
class S45AB10 {
public:
    char pad_00[102*4];
    int field_198;                // self[102]

    int* Compute_45AB10(int a2, int a3, int a4, int* a5, int* a6);
};

MATCH_FUNC(0x45AB10)
int* S45AB10::Compute_45AB10(int a2, int a3, int a4, int* a5, int* a6)
{
    *a5 = a4 * (a2 + 30) + 2 * this->field_198 + 30;
    int* result = a6;
    *a6 = a3 + 2 * this->field_198 + 8;
    return result;
}

// 0x465920 — bounded pointer-table lookup, -1 for invalid/missing.
class S465920 {
public:
    int count;                    // self[0]
    int field_04;
    int* table;                   // self[2]

    int Get_465920(int a2);
};

MATCH_FUNC(0x465920)
int S465920::Get_465920(int a2)
{
    int v2;
    if (a2 >= 0 && a2 < this->count && (v2 = (int)this->table) != 0)
        return *(int*)(v2 + 4 * a2);
    else
        return -1;
}

// 0x4659A0 — bounded pointer-table store.
class S4659A0 {
public:
    int count;                    // self[0]
    int field_04;
    int* table;                   // self[2]

    int Set_4659A0(int a2, int a3);
};

MATCH_FUNC(0x4659A0)
int S4659A0::Set_4659A0(int a2, int a3)
{
    if (a2 >= 0 && this->count > a2) {
        int v3 = (int)this->table;
        if (v3) {
            *(int*)(v3 + 4 * a2) = a3;
            return 1;
        }
    }
    return 0;
}

// 0x46A500 — search a circular sentinel list for the node at key offset 8.
class S46A500 {
public:
    char pad_00[4];
    int* head;                    // self[1], sentinel node pointer
    int sentinel_next;            // self+1's first dword (same address as head)

    int* Find_46A500(int a2);
};

MATCH_FUNC(0x46A500)
int* S46A500::Find_46A500(int a2)
{
    int* result = this->head;
    int* v3 = (int*)this + 1;
    for (; result != v3; result = (int*)*result) {
        if (result[2] == a2)
            return result;
    }
    return 0;
}

// 0x46C730 — clear the record flag at index 0..n, stride 48.
class S46C730 {
public:
    char pad_00[55*4];
    int* records;                 // self[55]

    int Clear_46C730(int a2);
};

MATCH_FUNC(0x46C730)
int S46C730::Clear_46C730(int a2)
{
    int result = a2;
    if (a2 != -1) {
        result = 48 * a2;
        *(int*)((char*)this->records + 48 * a2 + 28) = 0;
    }
    return result;
}

// 0x46C750 — increment the record counter at index, stride 48.
class S46C750 {
public:
    char pad_00[55*4];
    int* records;                 // self[55]

    int* Count_46C750(int a2);
};

MATCH_FUNC(0x46C750)
int* S46C750::Count_46C750(int a2)
{
    int* result = (int*)a2;
    if (a2 != -1) {
        result = (int*)((char*)this->records + 48 * a2 + 28);
        ++*result;
    }
    return result;
}

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

WIP_FUNC(0x48BF10)
int __cdecl sub_48BF10(int a1)
{
    if (a1) {
        if (*(unsigned char*)(a1 + 78) == 80) {
            int v = *(int*)(a1 + 452);
            if (v)
                return v;
        }
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
