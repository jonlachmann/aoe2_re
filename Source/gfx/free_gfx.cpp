// free_gfx — gfx-region free functions migrated from Source/simple.
// Sections keep per-file order; preambles are carried only when the file's
// first marker lives in another module.
#include "Function.hpp"
#include "matched_mem.h"


extern int g_66d4b0;
extern int g_66d4b4;
extern int g_66d4b8;

// 0x4654A0 — clear 0x28 records of three dwords (stride 12) at 0x66d7e8.
struct S4654A0 {
public:
    int field_00;                 // +0
    int field_04;                 // +4
    int field_08;                 // +8
};
extern S4654A0 g_66d7e8[0x28];

void sub_4654A0();
void sub_4654D0();

// 0x465490 — tail-call forwarder to the array clear.
MATCH_FUNC(0x465490)
void sub_465490()
{
    sub_4654A0();
}

MATCH_FUNC(0x4654A0)
void sub_4654A0()
{
    int n = 0x28;
    S4654A0* p = &g_66d7e8[0];
    do {
        p->field_00 = 0;
        p->field_04 = 0;
        p->field_08 = 0;
        ++p;
    } while (--n);
}

// 0x4654C0 — tail-call forwarder to the three-global init.
MATCH_FUNC(0x4654C0)
void sub_4654C0()
{
    sub_4654D0();
}

MATCH_FUNC(0x4654D0)
void Init_4654D0()
{
    *(volatile float*)&g_66d4b0 = 0.0f;
    *(volatile float*)&g_66d4b4 = 1.0f;
    *(volatile float*)&g_66d4b8 = 0.0f;
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
MATCH_FUNC(0x45AE80)
void S45AE80::Set_45AE80(int a, int b, int c, int d, int unused1, int unused2)
{
    *(int*)((char*)this + 0x150) = a;
    *(int*)((char*)this + 0x154) = c;
    *(int*)((char*)this + 0x158) = b;
    *(int*)((char*)this + 0x160) = 0x40;
    *(int*)((char*)this + 0x164) = 0x40;
    *(int*)((char*)this + 0x15c) = d;
    *(int*)((char*)this + 0x168) = 0x24;
    *(int*)((char*)this + 0x16c) = 0x24;
    *(int*)((char*)this + 0x170) = 0xe;
    *(int*)((char*)this + 0x174) = 3;
}


MATCH_FUNC(0x440740)
void M_440740()
{
}

MATCH_FUNC(0x440750)
void M_440750()
{
}

MATCH_FUNC(0x446D10)
void M_446D10()
{
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

MATCH_FUNC(0x4567F0)
int S4567F0::Add_4567F0(int a2)
{
    int i;
    for (i = 0; i < 50; i++) {
        if (this->values[i] <= 0) {
            this->values[i] = a2;
            break;
        }
    }
    return i;
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

class S464D90 {
public:
    int field_0;
    int field_4;
    bool Set_464D90(int value);
};
MATCH_FUNC(0x464D90)
bool S464D90::Set_464D90(int value)
{
    if (value < field_4) {
        field_0 = value;
        return true;
    }
    field_0 = -1;
    return false;
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
MATCH_FUNC(0x465B10)
S465B10* S465B10::Init_465B10()
{
    int zero = 0;
    *(int*)((char*)this) = zero;
    *(int*)((char*)this + 4) = zero;
    *(int*)((char*)this + 8) = zero;
    *(int*)((char*)this + 0xc) = zero;
    *(int*)((char*)this + 0x10) = zero;
    *(int*)((char*)this + 0x14) = zero;
    *(int*)((char*)this + 0x18) = zero;
    *(int*)((char*)this + 0x1c) = zero;
    *(int*)((char*)this + 0x20) = zero;
    *(int*)((char*)this + 0x24) = zero;
    *(int*)((char*)this + 0x28) = zero;
    *(int*)((char*)this + 0x2c) = zero;
    *(int*)((char*)this + 0x30) = 0x3f800000;
    *(int*)((char*)this + 0x34) = zero;
    *(int*)((char*)this + 0x38) = zero;
    return this;
}

class S469570 {
public:
    S469570* Init_469570();
};
MATCH_FUNC(0x469570)
S469570* S469570::Init_469570()
{
    int zero = 0;
    *(int*)((char*)this) = zero;
    char* p = (char*)this + 4;
    *(int*)p = zero;
    *(int*)(p + 4) = zero;
    *(int*)(p + 8) = zero;
    *(int*)(p + 0xc) = zero;
    *(int*)(p + 0x10) = zero;
    *(int*)(p + 0x14) = zero;
    *(int*)(p + 0x18) = zero;
    *(int*)(p + 0x1c) = zero;
    *(int*)(p + 0x20) = zero;
    *(int*)(p + 0x24) = zero;
    *(int*)(p + 0x28) = zero;
    *(int*)(p + 0x2c) = zero;
    *(void**)(p + 0x30) = p;
    *(void**)(p + 0x34) = p;
    *(int*)((char*)this + 0x3c) = zero;
    *(int*)((char*)this + 0x40) = zero;
    *(void**)((char*)this + 0x34) = p;
    *(void**)((char*)this + 0x38) = p;
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

MATCH_FUNC(0x443960)
int M_443960()
{
    return 0x3817c;
}

class S44GetBulk {
public:
    int Get_440730();
    int Get_4474F0();
    int Get_447500();
    int Get_44B9E0();
};

MATCH_FUNC(0x440730)
int S44GetBulk::Get_440730()
{
    return *(int*)((char*)this + 0xf0);
}

class S44SetBulk {
public:
    void SetInt_44CFC0(int v);
};

MATCH_FUNC(0x44CFC0)
void S44SetBulk::SetInt_44CFC0(int v)
{
    *(int*)((char*)this + 0x804) = v;
}

// Family 0x456790/0x4567C0: two arrays of 96 dwords at +0x908 and +0xb60. Each
// method finds the first slot that is <= 0 and writes the arg there.
class S456790 {
public:
    char pad_00[0x908];
    int arr_908[96];          // +0x908
    char pad_a88[0xb60 - 0xa88];
    int arr_b60[96];          // +0xb60

    void M_456790(int v);
    void M_4567C0(int v);
};

MATCH_FUNC(0x456790)
void S456790::M_456790(int v)
{
    for (int i = 0; i < 0x96; i++)
        if (arr_b60[i] <= 0) {
            arr_b60[i] = v;
            return;
        }
}

MATCH_FUNC(0x4567C0)
void S456790::M_4567C0(int v)
{
    for (int i = 0; i < 0x96; i++)
        if (arr_908[i] <= 0) {
            arr_908[i] = v;
            return;
        }
}

class S45SetBulk {
public:
    void SetByte_45AF60(unsigned char v);
};

MATCH_FUNC(0x45AF60)
void S45SetBulk::SetByte_45AF60(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x196) = v;
}

// Family at 0x464FD0/0x464FF0: one accessor class over an object array. field_0
// is the index, +8 is the array of object pointers; the two methods differ only
// in the null (negative-index) result and the tail-called virtual.
class T43FAB0 {
public:
    char* Other_43FAB0();
};
class T464290 {
public:
    int Other_464290();
};

class T464FD0 {
public:
    int index_0;              // +0x00
    char pad_04[0x08 - 0x04];
    char** items_8;           // +0x08

    char* Other_464FD0();
    int M_464FF0();
};

MATCH_FUNC(0x464FD0)
char* T464FD0::Other_464FD0()
{
    if (index_0 < 0)
        return 0;
    return ((T43FAB0*)items_8[index_0])->Other_43FAB0();
}

MATCH_FUNC(0x464FF0)
int T464FD0::M_464FF0()
{
    if (index_0 < 0)
        return -1;
    return ((T464290*)items_8[index_0])->Other_464290();
}

class S46GetBulk {
public:
    int Get_463260();
    int Get_464290();
    float Get_46AAA0();
    float Get_46AAB0();
    float Get_46AAC0();
};

MATCH_FUNC(0x463260)
int S46GetBulk::Get_463260()
{
    return *(int*)((char*)this + 0x100);
}

MATCH_FUNC(0x464290)
int S46GetBulk::Get_464290()
{
    return *(int*)((char*)this + 0x118);
}

class S46SetBulk {
public:
    void SetInt_464480(int v);
    void SetInt_46A9B0(int v);
    void SetInt_46A9C0(int v);
    void SetInt_46A9E0(int v);
    void SetInt_46AA00(int v);
    void SetInt_46AA50(int v);
    void SetInt_46AA70(int v);
    void SetInt_46AA90(int v);
    void SetInt_46AB60(int v);
    void SetInt_46AE40(int v);
};

MATCH_FUNC(0x464480)
void S46SetBulk::SetInt_464480(int v)
{
    *(int*)((char*)this + 0x104) = v;
}

MATCH_FUNC(0x46AE40)
void S46SetBulk::SetInt_46AE40(int v)
{
    *(int*)((char*)this + 0xc4) = v;
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
MATCH_FUNC(0x440720)
int S440720::Get_440720()
{
    return *(int*)((char*)this + 0x1c);
}

// sub_440F70 (VA 0x440F70) - stdcall: returns one of two globals by flag.
extern int g_6514FC;
extern int g_6514E4;
MATCH_FUNC(0x440F70)
extern "C" int* __stdcall sub_440F70(int flag)
{
    return flag ? &g_6514FC : &g_6514E4;
}

// 0x440B40..0x440CC0 — five toggle setters on the same object: when the +0x2C
// logger is absent, report the new state through the empty 0x4378C0 stub.
extern void __cdecl Hook_4378C0(void* a1, int a2, void* a3);
class S440B40 {
public:
    int vtbl_00;                  // +0x00 vtable 0x61E948
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    int field_14;                 // +0x14 state flag
    int field_18;
    char pad_1c[0x08];            // 0x1c..0x24
    int field_24;
    int field_28;                 // +0x28 reset by M_440D00
    int field_2c;
    int* M_440F70(int a1);        // __thiscall sibling helper at 0x440F70
    void M_440B40(int a1);
    void M_440B80(int a1);
    void M_440BC0(int a1);
    void M_440C00(int a1);
    void M_440CC0(int a1);
    void M_440D00(int a1);
};

MATCH_FUNC(0x440B40)
void S440B40::M_440B40(int a1)
{
    if (field_2c == 0)
        Hook_4378C0(this, 0x65137c, sub_440F70(a1));
    if (a1)
        field_0c = 1;
    else
        field_0c = 0;
}

MATCH_FUNC(0x440B80)
void S440B40::M_440B80(int a1)
{
    if (field_2c == 0)
        Hook_4378C0(this, 0x651390, sub_440F70(a1));
    if (a1)
        field_10 = 1;
    else
        field_10 = 0;
}

MATCH_FUNC(0x440BC0)
void S440B40::M_440BC0(int a1)
{
    if (field_2c == 0)
        Hook_4378C0(this, 0x6513a8, sub_440F70(a1));
    if (a1)
        field_04 = 1;
    else
        field_04 = 0;
}

MATCH_FUNC(0x440D00)
void S440B40::M_440D00(int a1)
{
    if (a1 != 0)
    {
        field_14 = 1;
        field_28 = 0;
    }
    else
        field_14 = 0;
    if (field_2c == 0)
        Hook_4378C0(this, 0x651420, M_440F70(a1));
}

MATCH_FUNC(0x440C00)
void S440B40::M_440C00(int a1)
{
    if (field_2c == 0)
        Hook_4378C0(this, 0x6513c4, sub_440F70(a1));
    if (a1)
        field_08 = 1;
    else
        field_08 = 0;
}

MATCH_FUNC(0x440CC0)
void S440B40::M_440CC0(int a1)
{
    if (field_2c == 0)
        Hook_4378C0(this, 0x651404, sub_440F70(a1));
    if (a1)
        field_18 = 1;
    else
        field_18 = 0;
}

// sub_4437F0 (VA 0x4437F0, 20 bytes) - cdecl: publish the arg as the global
// pointer at 0x66A478 and stamp 0xABCD1234 at object offset +0x38178.
int global_66A478;

MATCH_FUNC(0x4437F0)
void sub_4437F0(int v)
{
    global_66A478 = v;
    *(int*)(v + 0x38178) = 0xABCD1234;
}

// sub_4441C0 (VA 0x4441C0) - member: stores the arg at +0xfc then calls the virtual
// slot 0x20 with the constant 2.
class S4441C0 {
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

    char pad_04[0xfc - 4];
    int field_0xfc;

    void M_4441C0(int v);
};

MATCH_FUNC(0x4441C0)
void S4441C0::M_4441C0(int v)
{
    field_0xfc = v;
    Vat_20(2);
}

// sub_45AEF0 (VA 0x45AEF0) - member: forwards three args through virtual slot
// 0x108 of the object at +0x188.
class T45AEF0 {
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
    virtual void Vat_108(int a, int b, int c);
};
class S45AEF0 {
public:
    char pad_00[0x188];
    T45AEF0* field_188;
    void M_45AEF0(int a, int b, int c);
};

MATCH_FUNC(0x45AEF0)
void S45AEF0::M_45AEF0(int a, int b, int c)
{
    if (field_188 != 0)
        field_188->Vat_108(a, b, c);
}

class S45EA60Inner {
public:
    char pad_00[0xf4];
    int field_f4;
};

class S45EA60Node {
public:
    S45EA60Inner* field_0;
    char pad_04[0x8 - 0x4];
    S45EA60Node* field_8;
};

class S45EA60 {
public:
    char pad_00[0x14];
    S45EA60Node* field_14;
    char pad_18[0x4c - 0x18];
    int field_4c;
    void Clear_45EA60();
};

MATCH_FUNC(0x45EA60)
void S45EA60::Clear_45EA60()
{
    S45EA60Node* n = field_14;
    field_4c = 0;
    while (n != 0) {
        n->field_0->field_f4 = 0;
        n = n->field_8;
    }
}

// sub_464490 (VA 0x464490) - member: tail-calls the entry at field_100 in the
// two tables 0x10c/0x114, -1 when the index is invalid or the flag slot is 0.
class T463260 {
public:
    int Other_463260();
};
class S464490 {
public:
    char pad_00[0x100];
    int index_100;
    char pad_104[0x10c - 0x104];
    T463260** arr_10c;
    char pad_110[0x114 - 0x110];
    int* flags_114;
    int M_464490();
};

MATCH_FUNC(0x464490)
int S464490::M_464490()
{
    int i = index_100;
    if (i <= -1)
        return -1;
    if (flags_114[i] == 0)
        return -1;
    return arr_10c[i]->Other_463260();
}

// sub_465900 (VA 0x465900, 16 bytes) - member: zero four dwords at +0..+0xC
// (a small object's clear/ctor). No calls.
class S465900 {
public:
    int a_0;
    int b_4;
    int c_8;
    int d_C;
    S465900* M_465900();
};

MATCH_FUNC(0x465900)
S465900* S465900::M_465900()
{
    S465900* p = this;
    int z = 0;
    p->a_0 = z;
    p->b_4 = z;
    p->c_8 = z;
    p->d_C = z;
    return p;
}

// sub_465BB0 (VA 0x465BB0) - member: index of the first 0x48-stride entry at
// +0xc whose +0 dword equals the arg; -1 when the count at +4 is <= 0 or none.
struct E465BB0 {
    int field_0;
    char pad_04[0x48 - 0x04];
};
class S465BB0 {
public:
    char pad_00[4];
    int count_4;
    char pad_08[0xc - 0x08];
    E465BB0* arr_c;
    int M_465BB0(int v);
};

MATCH_FUNC(0x465BB0)
int S465BB0::M_465BB0(int v)
{
    for (int i = 0; i < count_4; i++)
        if (arr_c[i].field_0 == v)
            return i;
    return -1;
}

// sub_46CDF0 (VA 0x46CDF0, 0x11 bytes) - member getter: first dword of the
// +0xf0 object, or -1 when null.
class S46CDF0 {
public:
    int M_46CDF0();
};

MATCH_FUNC(0x46CDF0)
int S46CDF0::M_46CDF0()
{
    char* p = *(char**)((char*)this + 0xf0);
    if (p != 0)
        return *(int*)p;
    return -1;
}

// Tail-jump forwarder (gfx region).
void sub_469AB0();

MATCH_FUNC(0x4695B0)
void sub_4695B0()
{
    sub_469AB0();
}

// 0x440B30 — install the vtable at 0x61E948 and forward to 0x440F00.
extern void sub_440F00();
class T440B30 {
public:
    void Other_440B30();
};
MATCH_FUNC(0x440B30)
void T440B30::Other_440B30()
{
    *(void**)this = (void*)0x61E948;
    sub_440F00();
}

// 0x465910 — tail-call forwarder to 0x465AE0.
extern void sub_465AE0();
MATCH_FUNC(0x465910)
void __cdecl sub_465910()
{
    sub_465AE0();
}

// 0x465100 — dispatch through the array at +8 using the index at +0.
class T4645A0 {
public:
    void Other_4645A0();
};
class S465100 {
public:
    int index_00;                 // +0
    char pad_04[4];
    T4645A0** array_08;           // +8
    void M_465100();
};
MATCH_FUNC(0x465100)
void S465100::M_465100()
{
    this->array_08[this->index_00]->Other_4645A0();
}

// 0x465110 — dispatch through the array at +8 using the index at +0.
class T464610 {
public:
    void Other_464610();
};
class S465110 {
public:
    int index_00;                 // +0
    char pad_04[4];
    T464610** array_08;           // +8
    void M_465110();
};
MATCH_FUNC(0x465110)
void S465110::M_465110()
{
    this->array_08[this->index_00]->Other_464610();
}

// 0x465120 — dispatch unless the index is -1.
class T4646D0 {
public:
    void Other_4646D0();
};
class S465120 {
public:
    int index_00;                 // +0
    char pad_04[4];
    T4646D0** array_08;           // +8
    void M_465120();
};
MATCH_FUNC(0x465120)
void S465120::M_465120()
{
    if (this->index_00 == -1)
        return;
    this->array_08[this->index_00]->Other_4646D0();
}

// 0x4457F0 — clear the field at +0x158 then forward.
class S4457F0 {
public:
    char pad_00[0x158];
    int field_158;                // +0x158
    void M_4457F0();
};
class T4A1CD0 {
public:
    void Other_4A1CD0();
};
MATCH_FUNC(0x4457F0)
void S4457F0::M_4457F0()
{
    this->field_158 = 0;
    ((T4A1CD0*)this)->Other_4A1CD0();
}

// 0x4436B0 — set a global field to 0xffff then forward.
extern char* g_66A478;
class T4436B0 {
public:
    char pad_00[0x38128];
    int field_38128;              // +0x38128
};
extern void __cdecl sub_4429B0();
MATCH_FUNC(0x4436B0)
void __cdecl sub_4436B0()
{
    (((T4436B0*)ADDR(g_66A478)))->field_38128 = 0xffff;
    sub_4429B0();
}

// Scalar deleting destructor wrappers.
extern int __cdecl sub_5F90B0(int a1);

class Td440b30 {
public:
    void Other_440b30();
};
class Sd440B10 {
public:
    Sd440B10* D_440B10(int flags);
};
MATCH_FUNC(0x440B10)
Sd440B10* Sd440B10::D_440B10(int flags)
{
    ((Td440b30*)this)->Other_440b30();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td443a70 {
public:
    void Other_443a70();
};
class Sd443A50 {
public:
    Sd443A50* D_443A50(int flags);
};
MATCH_FUNC(0x443A50)
Sd443A50* Sd443A50::D_443A50(int flags)
{
    ((Td443a70*)this)->Other_443a70();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td447530 {
public:
    void Other_447530();
};
class Sd447510 {
public:
    Sd447510* D_447510(int flags);
};
MATCH_FUNC(0x447510)
Sd447510* Sd447510::D_447510(int flags)
{
    ((Td447530*)this)->Other_447530();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td447c10 {
public:
    void Other_447c10();
};
class Sd447BE0 {
public:
    Sd447BE0* D_447BE0(int flags);
};
MATCH_FUNC(0x447BE0)
Sd447BE0* Sd447BE0::D_447BE0(int flags)
{
    ((Td447c10*)this)->Other_447c10();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td448960 {
public:
    void Other_448960();
};
class Sd448940 {
public:
    Sd448940* D_448940(int flags);
};
MATCH_FUNC(0x448940)
Sd448940* Sd448940::D_448940(int flags)
{
    ((Td448960*)this)->Other_448960();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td44a260 {
public:
    void Other_44a260();
};
class Sd44A240 {
public:
    Sd44A240* D_44A240(int flags);
};
MATCH_FUNC(0x44A240)
Sd44A240* Sd44A240::D_44A240(int flags)
{
    ((Td44a260*)this)->Other_44a260();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td44b470 {
public:
    void Other_44b470();
};
class Sd44B3E0 {
public:
    Sd44B3E0* D_44B3E0(int flags);
};
MATCH_FUNC(0x44B3E0)
Sd44B3E0* Sd44B3E0::D_44B3E0(int flags)
{
    ((Td44b470*)this)->Other_44b470();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td44ba10 {
public:
    void Other_44ba10();
};
class Sd44B9F0 {
public:
    Sd44B9F0* D_44B9F0(int flags);
};
MATCH_FUNC(0x44B9F0)
Sd44B9F0* Sd44B9F0::D_44B9F0(int flags)
{
    ((Td44ba10*)this)->Other_44ba10();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td44c170 {
public:
    void Other_44c170();
};
class Sd44C150 {
public:
    Sd44C150* D_44C150(int flags);
};
MATCH_FUNC(0x44C150)
Sd44C150* Sd44C150::D_44C150(int flags)
{
    ((Td44c170*)this)->Other_44c170();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td44c7f0 {
public:
    void Other_44c7f0();
};
class Sd44C7D0 {
public:
    Sd44C7D0* D_44C7D0(int flags);
};
MATCH_FUNC(0x44C7D0)
Sd44C7D0* Sd44C7D0::D_44C7D0(int flags)
{
    ((Td44c7f0*)this)->Other_44c7f0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td44cf00 {
public:
    void Other_44cf00();
};
class Sd44CEE0 {
public:
    Sd44CEE0* D_44CEE0(int flags);
};
MATCH_FUNC(0x44CEE0)
Sd44CEE0* Sd44CEE0::D_44CEE0(int flags)
{
    ((Td44cf00*)this)->Other_44cf00();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td44d3c0 {
public:
    void Other_44d3c0();
};
class Sd44D3A0 {
public:
    Sd44D3A0* D_44D3A0(int flags);
};
MATCH_FUNC(0x44D3A0)
Sd44D3A0* Sd44D3A0::D_44D3A0(int flags)
{
    ((Td44d3c0*)this)->Other_44d3c0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td44e2f0 {
public:
    void Other_44e2f0();
};
class Sd44E2D0 {
public:
    Sd44E2D0* D_44E2D0(int flags);
};
MATCH_FUNC(0x44E2D0)
Sd44E2D0* Sd44E2D0::D_44E2D0(int flags)
{
    ((Td44e2f0*)this)->Other_44e2f0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td44ef20 {
public:
    void Other_44ef20();
};
class Sd44EF00 {
public:
    Sd44EF00* D_44EF00(int flags);
};
MATCH_FUNC(0x44EF00)
Sd44EF00* Sd44EF00::D_44EF00(int flags)
{
    ((Td44ef20*)this)->Other_44ef20();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td4511a0 {
public:
    void Other_4511a0();
};
class Sd451180 {
public:
    Sd451180* D_451180(int flags);
};
MATCH_FUNC(0x451180)
Sd451180* Sd451180::D_451180(int flags)
{
    ((Td4511a0*)this)->Other_4511a0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td45a5e0 {
public:
    void Other_45a5e0();
};
class Sd45A5C0 {
public:
    Sd45A5C0* D_45A5C0(int flags);
};
MATCH_FUNC(0x45A5C0)
Sd45A5C0* Sd45A5C0::D_45A5C0(int flags)
{
    ((Td45a5e0*)this)->Other_45a5e0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td45c8b0 {
public:
    void Other_45c8b0();
};
class Sd45BDA0 {
public:
    Sd45BDA0* D_45BDA0(int flags);
};
MATCH_FUNC(0x45BDA0)
Sd45BDA0* Sd45BDA0::D_45BDA0(int flags)
{
    ((Td45c8b0*)this)->Other_45c8b0();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td41a150 {
public:
    void Other_41a150();
};
class Sd45D0F0 {
public:
    Sd45D0F0* D_45D0F0(int flags);
};
MATCH_FUNC(0x45D0F0)
Sd45D0F0* Sd45D0F0::D_45D0F0(int flags)
{
    ((Td41a150*)this)->Other_41a150();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td462850 {
public:
    void Other_462850();
};
class Sd462650 {
public:
    Sd462650* D_462650(int flags);
};
MATCH_FUNC(0x462650)
Sd462650* Sd462650::D_462650(int flags)
{
    ((Td462850*)this)->Other_462850();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

class Td46ab90 {
public:
    void Other_46ab90();
};
class Sd46AB70 {
public:
    Sd46AB70* D_46AB70(int flags);
};
MATCH_FUNC(0x46AB70)
Sd46AB70* Sd46AB70::D_46AB70(int flags)
{
    ((Td46ab90*)this)->Other_46ab90();
    if (flags & 1)
        sub_5F90B0((int)this);
    return this;
}

// 0x4424D0 — four-byte element copy loop.
MATCH_FUNC(0x4424D0)
void sub_4424D0(int* dest, int* src, int count)
{
    while (count != 0)
    {
        *dest++ = *src++;
        count--;
    }
}

// 0x45B520 — conditional one-argument thiscall on the field at +0x188.
class Tc4BD7A0 {
public:
    void Other_4BD7A0(int a1);
};
class Sc45B520 {
public:
    char pad_00[0x188];
    Tc4BD7A0* field_188;          // +0x188
    void M_45B520(int a1);
};
MATCH_FUNC(0x45B520)
void Sc45B520::M_45B520(int a1)
{
    if (this->field_188)
        this->field_188->Other_4BD7A0(a1);
}

// 0x462B50 — initialize the two +0x00/+0x104 name pointers from the shared
// allocator, then copy the embedded name at +0x108 into the +0x04 buffer.
// strcpy becomes VC6's scan/copy intrinsic under the scoped pragma.
extern char* __cdecl Hook_5FF0A3();
class T462BA0 {
public:
    void Other_462BA0();
};
class S462B50 {
public:
    char* field_00;               // +0x00 name pointer
    char name_04[0x104 - 0x04];   // +0x04 inlined name buffer
    char* field_104;              // +0x104 same pointer
    char src_108[1];              // +0x108 embedded source name
    S462B50* M_462B50();
};

#pragma intrinsic(strcpy)
MATCH_FUNC(0x462B50)
S462B50* S462B50::M_462B50()
{
    char* p = Hook_5FF0A3();
    field_00 = p;
    field_104 = p;
    ((T462BA0*)this)->Other_462BA0();
    strcpy(name_04, src_108);
    return this;
}
#pragma function(strcpy)

// 0x461CA0 — reset the 0x100-byte buffer head/tail bytes, then forward it to
// the 0x45F6F0 screen helper through the object stored at this->+0x00.
class T45F6F0_461CA0 {
public:
    void Other_45F6F0(int a1, int a2, char* a3);
};
class S461CA0 {
public:
    void* field_00;               // +0x00 object workspace
    void M_461CA0(char* a1);
};

MATCH_FUNC(0x461CA0)
void S461CA0::M_461CA0(char* a1)
{
    a1[0] = 0;
    a1[1] = 0;
    a1[2] = 0;
    a1[3] = 0;
    a1[0x3fc] = 0xff;
    a1[0x3fd] = 0xff;
    a1[0x3fe] = 0xff;
    a1[0x3ff] = 0;
    ((T45F6F0_461CA0*)field_00)->Other_45F6F0(0, 0x100, a1);
}


// 0x45EDE0 — read the +0x04 pair into +0x2C/+0x30 when the +0x3C/+0x3D mode is
// one, then send that pair to the +0x10 object (when present) and the +0x0C
// object.
class T45EDE0Sub {
public:
    char pad_00[0x04];
    void M_45FED0(int a1, int a2, int a3);
};
class S45EDE0 {
public:
    char pad_00[4];
    void* field_04;                 // +0x04 pair source
    char pad_08[0x0c - 0x08];
    T45EDE0Sub* field_0c;           // +0x0C receiver
    T45EDE0Sub* field_10;           // +0x10 optional receiver
    char pad_14[0x2c - 0x14];
    int field_2c;                   // +0x2C pair A
    int field_30;                   // +0x30 pair B
    char pad_34[0x3c - 0x34];       // +0x34..+0x3C
    unsigned char field_3c;         // +0x3C mode
    unsigned char field_3d;         // +0x3D mode
    void M_45EDE0(int a1, int a2, int a3, int a4);
};
extern void (__stdcall *g_61C2C4)(void* a1, int* a2);

MATCH_FUNC(0x45EDE0)
void S45EDE0::M_45EDE0(int a1, int a2, int a3, int a4)
{
    if (field_0c == 0)
        return;
    if (field_3c == 1 || field_3d == 1)
    {
        int data[4];
        g_61C2C4(field_04, data);
        field_2c = data[2];
        field_30 = data[3];
    }
    if (field_10 != 0)
        field_10->M_45FED0(field_2c, field_30, 0);
    field_0c->M_45FED0(field_2c, field_30, 0);
}
