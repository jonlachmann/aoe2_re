#include "C_vt62C1E0.hpp"

extern unsigned char g_75fdc4;
extern "C" void sub_5FCB40(char* dst, char* src, int size);   // unresolved callee at 0x5FCB40

extern int g_66459C;
extern void (__stdcall *g_61C284)(int a1);
extern void (__stdcall *g_61C288)(void* a1, int a2, int a3);
extern void __stdcall Hook_421FC0(int a1, int a2);

MATCH_FUNC(0x41FA40)
void C_vt62C1E0::M_41FA40(int a1)
{
    field_1fc = a1;
    if (a1 != 0)
        g_66459C = a1;
    if (field_1f4 != 0) {
        if (field_74 == 0 || field_1f8 != 0) {
            g_61C284(field_1fc);
            g_61C288(field_28, -0xc, field_1fc);
        }
    }
}

MATCH_FUNC(0x421A80)
void C_vt62C1E0::M_421A80(char* src)
{
    sub_5FCB40((char*)this + 0x929, src, 0x80);
    ((unsigned char*)this)[0x9a8] = 0;
}

MATCH_FUNC(0x5BAEC0)
void C_vt62C1E0::M_5BAEC0(int a1)
{
    int old = field_11D0;
    field_11D4 = a1;
    this->Hook_5BAD80(old);
}

MATCH_FUNC(0x5BAEE0)
void C_vt62C1E0::M_5BAEE0(char* src)
{
    strcpy((char*)this + 0x1240, src);
}

MATCH_FUNC(0x421750)
float C_vt62C1E0::Get924_421750() { return field_924; }

MATCH_FUNC(0x421760)
int C_vt62C1E0::Get928_421760() { return field_928; }

MATCH_FUNC(0x421780)
int C_vt62C1E0::Get9D4_421780() { return field_9D4; }

MATCH_FUNC(0x4217A0)
char* C_vt62C1E0::Ptr9A9_4217A0() { return (char*)this + 0x929; }

MATCH_FUNC(0x4217B0)
int C_vt62C1E0::Get9A9_4217B0() { return field_9A9; }

MATCH_FUNC(0x4217C0)
int C_vt62C1E0::Get9AA_4217C0() { return field_9AA; }

MATCH_FUNC(0x421A60)
void C_vt62C1E0::Set928_421A60(unsigned char v) { field_928 = v; }

MATCH_FUNC(0x421AB0)
void C_vt62C1E0::Set9D4_421AB0(int v) { field_9D4 = v; }

MATCH_FUNC(0x421AC0)
void C_vt62C1E0::Set9D8_421AC0(int v) { field_9D8 = v; }

MATCH_FUNC(0x421AD0)
void C_vt62C1E0::M_421AD0(int v)
{
    field_9A9 = (unsigned char)v;
    field_9AA = (v == 0);
}

MATCH_FUNC(0x421B10)
void C_vt62C1E0::M_421B10(unsigned char a, unsigned char b, unsigned char c)
{
    field_9AB = a;
    field_9AC = b;
    field_9AD = c;
}

MATCH_FUNC(0x421B40)
void C_vt62C1E0::Set9AE_421B40(unsigned char v) { field_9AE = v; }

MATCH_FUNC(0x421B70)
void C_vt62C1E0::Set9B1_421B70(unsigned char v) { field_9B1 = v; }

MATCH_FUNC(0x421C20)
void C_vt62C1E0::Set9BE_421C20(unsigned char v) { field_9BE = v; }

MATCH_FUNC(0x421CF0)
void C_vt62C1E0::SetC9_421CF0() { field_9C9 = 1; }

MATCH_FUNC(0x421D00)
void C_vt62C1E0::SetCA_421D00() { field_9CA = 1; }

MATCH_FUNC(0x421D30)
void C_vt62C1E0::ClearC9_421D30() { field_9C9 = 0; }

MATCH_FUNC(0x421D40)
void C_vt62C1E0::ClearCA_421D40() { field_9CA = 0; }

MATCH_FUNC(0x421D70)
void C_vt62C1E0::ConditionC9_421D70(unsigned char v)
{
    if (v != 0)
        SetC9_421CF0();
    else
        ClearC9_421D30();
}

MATCH_FUNC(0x421D90)
void C_vt62C1E0::ConditionCA_421D90(unsigned char v)
{
    if (v != 0)
        SetCA_421D00();
    else
        ClearCA_421D40();
}

MATCH_FUNC(0x422320)
int C_vt62C1E0::Get_422320() { return field_1090; }

MATCH_FUNC(0x5B5C50)
void C_vt62C1E0::Wrap_5B5C50()
{
    if (*(void**)((char*)this + 0x149c))
        (*(T4DF8F0**)((char*)this + 0x149c))->M_4DF8F0(
            (char*)this + 0x430, (char*)this + 0x19b8);
}

MATCH_FUNC(0x5BAD50)
int C_vt62C1E0::Get_5BAD50()
{
    return *(int*)((char*)this + 0x11d8);
}

MATCH_FUNC(0x5BAD60)
void C_vt62C1E0::SetInt_5BAD60(int v)
{
    *(int*)((char*)this + 0x11d8) = v;
}

MATCH_FUNC(0x5BAD70)
int C_vt62C1E0::Get_5BAD70()
{
    return *(int*)((char*)this + 0x11d0);
}

MATCH_FUNC(0x5BAEA0)
int C_vt62C1E0::Get_5BAEA0()
{
    return *(int*)((char*)this + 0x11d4);
}

MATCH_FUNC(0x5BAEB0)
char* C_vt62C1E0::Get_5BAEB0()
{
    return (char*)this + 0x1240;
}

MATCH_FUNC(0x5BAF20)
void C_vt62C1E0::SetInt_5BAF20(int v)
{
    *(int*)((char*)this + 0x11dc) = v;
}

MATCH_FUNC(0x5BAF40)
void C_vt62C1E0::SetInt_5BAF40(int v)
{
    *(int*)((char*)this + 0x11e0) = v;
}

MATCH_FUNC(0x5BAF70)
void C_vt62C1E0::Set_5BAF70(int a, int b)
{
    field_11E4 = a;
    field_11E8 = b;
}

MATCH_FUNC(0x5BAFA0)
void C_vt62C1E0::SetByte_5BAFA0(int index, unsigned char v)
{
    array_11EC[index] = v;
}

MATCH_FUNC(0x5BAFD0)
void C_vt62C1E0::SetInt_5BAFD0(int index, int v)
{
    array_11F8[index] = v;
}

// 0x5BB000: one-instruction diff left. Original copies the a2 path as a full
// register (`mov edx, eax`); a char temp gives `mov dl, al`, and an int temp
// (or ternary / early-return / constant-1 forms) lets VC6 fold a3==a2 and
// collapse the whole branch to one store. Tried char/uchar/short/int temps,
// casts on each arm, nested vs && vs ternary, a3==1 vs a3==a2. Possibly a
// VC6 SP3 (8447) vs SP5 (8804) byte-copy difference.
WIP_FUNC(0x5BB000)
int C_vt62C1E0::Set_5BB000(int a2, int a3)
{
    int result = a2;
    char v4;
    if (a2 == 1) {
        if (a3 == a2)
            v4 = result;
        else
            v4 = a3;
    } else {
        v4 = a3;
    }
    ((char*)this)[a2 + 4636] = v4;
    return result;
}

MATCH_FUNC(0x5BB040)
void C_vt62C1E0::SetByte2_5BB040(int index, unsigned char v)
{
    *((unsigned char*)this + 0x1225 + index) = v;
}

MATCH_FUNC(0x5BB170)
void C_vt62C1E0::SetByte_5BB170(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x122e) = v;
}

MATCH_FUNC(0x5BB180)
void C_vt62C1E0::SetByte_5BB180(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x122f) = v;
}

MATCH_FUNC(0x5BB190)
void C_vt62C1E0::SetByte_5BB190(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1230) = v;
}

MATCH_FUNC(0x5BB1A0)
void C_vt62C1E0::SetByte_5BB1A0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1231) = v;
}

MATCH_FUNC(0x5BB1B0)
void C_vt62C1E0::SetInt_5BB1B0(int v)
{
    *(int*)((char*)this + 0x1234) = v;
}

MATCH_FUNC(0x5BB1C0)
void C_vt62C1E0::SetInt_5BB1C0(int v)
{
    *(int*)((char*)this + 0x1238) = v;
}

MATCH_FUNC(0x5BB1D0)
void C_vt62C1E0::SetByte_5BB1D0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123c) = v;
}

MATCH_FUNC(0x5BB1E0)
void C_vt62C1E0::SetByte_5BB1E0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123d) = v;
}

MATCH_FUNC(0x5BB1F0)
void C_vt62C1E0::SetByte_5BB1F0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123e) = v;
}

MATCH_FUNC(0x5BB200)
void C_vt62C1E0::SetByte_5BB200(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123f) = v;
}

MATCH_FUNC(0x5BB210)
void C_vt62C1E0::SetByte_5BB210(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1adc) = v;
}

MATCH_FUNC(0x5BB220)
void C_vt62C1E0::SetInt_5BB220(int v)
{
    *(int*)((char*)this + 0x1ae0) = v;
}

MATCH_FUNC(0x5BB230)
unsigned char* C_vt62C1E0::Clear_5BB230()
{
    g_75fdc4 = 0;
    return &g_75fdc4;
}

MATCH_FUNC(0x5BC4D0)
void C_vt62C1E0::Set_5BC4D0(int a, int b, int c, int d)
{
    *(int*)((char*)this + 0x11c0) = a;
    *(int*)((char*)this + 0x11c4) = b;
    *(int*)((char*)this + 0x11c8) = c;
    *(int*)((char*)this + 0x11cc) = d;
}

extern int g_65C928;
extern int g_65C92C;
extern int g_65B480;
extern int g_65B484;
extern char g_65B488;
extern char g_65BED8;
extern char g_659FE0;
extern char g_65AA30;
extern void __cdecl sub_5FCB40(char* dst, char* src, int n);

// 0x5BB080 — clear or copy the 0x1F-stride record at +0x10A8.
MATCH_FUNC(0x5BB080)
void C_vt62C1E0::M_5BB080(int a1, char* a2)
{
    if (a2 == 0) {
        *(char*)((char*)this + a1 * 0x1f + 0x10a8) = 0;
    } else {
        char* rec = (char*)this + a1 * 0x1f;
        sub_5FCB40(rec + 0x10a8, a2, 0x1e);
        *(char*)(rec + 0x10c6) = 0;
    }
}

// 0x5BC500 — branch on the basegame +0x8E0 flag and load one 4-dword set.
MATCH_FUNC(0x5BC500)
void C_vt62C1E0::M_5BC500()
{
    if (*(short*)((char*)this->field_24 + 0x8e0) == 1)
        this->Set_5BC4D0((int)&g_65B488, g_65C928, (int)&g_65BED8, g_65C92C);
    else
        this->Set_5BC4D0((int)&g_659FE0, g_65B480, (int)&g_65AA30, g_65B484);
}

// A short vtable subobject reaching slot +0x50 (index 20) through [object].
class T5BCA10Sub {
public:
    virtual void s_000();
    virtual void s_001();
    virtual void s_002();
    virtual void s_003();
    virtual void s_004();
    virtual void s_005();
    virtual void s_006();
    virtual void s_007();
    virtual void s_008();
    virtual void s_009();
    virtual void s_010();
    virtual void s_011();
    virtual void s_012();
    virtual void s_013();
    virtual void s_014();
    virtual void s_015();
    virtual void s_016();
    virtual void s_017();
    virtual void s_018();
    virtual void s_019();
    virtual void slot_020(int a1, int a2);
};

// 0x5BCA10 — position change: refresh the +0x6C object's +0x18/+0x1C pair,
// run the base handler with the two arguments, and when either value moved,
// notify the +0x149C subobject through slot +0x50.
MATCH_FUNC(0x5BCA10)
void C_vt62C1E0::M_5BCA10(int a1, int a2)
{
    int e = *(int*)((char*)this + 0x6c);
    int b = *(int*)(e + 0x18);
    int c = *(int*)(e + 0x1c);
    Hook_421FC0(a1, a2);
    if (a1 != b || a2 != c)
    {
        int o = *(int*)((char*)this + 0x149c);
        if (o != 0)
            ((T5BCA10Sub*)o)->slot_020(a1, a2);
    }
}
