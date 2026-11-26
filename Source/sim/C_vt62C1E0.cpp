#include "C_vt62C1E0.hpp"
#include "app/C_vt61DF78.hpp"
#include <string.h>
#include "Function.hpp"
#include "matched_mem.h"

extern unsigned char g_75fdc4;
extern "C" void sub_5FCB40(char* dst, char* src, int size);   // unresolved callee at 0x5FCB40

extern int g_66459C;
extern void (__stdcall *g_61C284)(int a1);
extern void (__stdcall *g_61C288)(void* a1, int a2, int a3);
extern void __stdcall Hook_421FC0(int a1, int a2);
extern void (__stdcall *g_61C2F4)(void* a1, int a2, int a3, int a4);
extern int __stdcall sub_41FAC0(C_vt62C1E0* a1, int a2, int a3, int a4, int a5);

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

// 0x5BB8A0 — 4-argument reset handler: forward the arguments to the base
// 0x420BE0 init, then when the +0x1D8 state is 1 and the +0x1460 handle is
// present, toggle the +0x146C flag through the 0x61C2F4 printer with code
// 0x855 when the third argument is 1 (clearing the flag) or 0x809 otherwise
// (setting it); every path returns 1.
MATCH_FUNC(0x5BB8A0)
int C_vt62C1E0::M_5BB8A0(int a1, int a2, int a3, int a4)
{
    this->Hook_420BE0(a1, a2, a3, a4);
    if (field_1d8 != 1)
        return 1;
    if (field_1460 == 0)
        return 1;
    if (a3 == 1)
    {
        if (field_146c == 0)
            return 1;
        g_61C2F4(field_1460, 0x855, 0, 0);
        field_146c = 0;
    }
    else
    {
        if (field_146c != 0)
            return 1;
        g_61C2F4(field_1460, 0x809, 0, 0);
        field_146c = 1;
    }
    return 1;
}

// 0x5BB240 — message-id dispatch on the object passed as the first argument:
// ids 0x201/0x204 call 0x5B4B10(1) and return 0 when the +0x1D8 state is 1;
// id 7 runs one of 0x421E60/0x421EC0 based on the +0x200 flag; id 0x200
// prints code 0 through 0x61C284 when the state is 1; every other path falls
// through to 0x41FAC0 with the same five arguments and returns its result.
MATCH_FUNC(0x5BB240)
int __stdcall sub_5BB240(C_vt62C1E0* a1, int a2, unsigned int a3, int a4, int a5)
{
    switch (a3)
    {
    case 0x201:
    case 0x204:
        if (a1->field_1d8 == 1)
        {
            a1->Hook_5B4B10(1);
            return 0;
        }
        break;
    case 7:
        if (a1->field_200 == 0)
            a1->Hook_421E60();
        else
            a1->Hook_421EC0();
        break;
    case 0x200:
        if (a1->field_1d8 == 1)
            g_61C284(0);
        break;
    }
    return sub_41FAC0(a1, a2, a3, a4, a5);
}

// 0x5BAD80 — grouped nested switch: the +0x11D4 value offset by 0xA selects
// one of two inner dimension switches on the argument; cases map a1 0..5 to
// byte-written dimension triples through +0x11D0.
// Byte-exact already: all 288 COMDAT bytes (213 code + padding + the 14-byte
// switch index table + both jump tables) equal the original at 0x5BAD80, and
// every jump-table / $L relocation resolves to the original target (checked
// 2026-11 against the obj's relocs). It stays WIP only because match.py's tail
// check accepts masked relocs or nop/cc padding after the catalog size, and
// the index table bytes (00 01 01 ...) are neither. Promote once match.py
// compares the tail against the original bytes.
MATCH_FUNC(0x5BAD80)
void C_vt62C1E0::M_5BAD80(int a1)
{
    int v = field_11D4 - 0xa;
    field_11D0 = a1;
    switch (v)
    {
    case 0:
    case 6:
    case 9:
    case 11:
    case 13:
        switch (a1)
        {
        case 0: M_421B10(0x90, 0x90, 8); return;
        case 1: M_421B10(0xa8, 0xa8, 8); return;
        case 2: M_421B10(0xc8, 0xc8, 8); return;
        case 3: M_421B10(0xdc, 0xdc, 8); return;
        case 4: M_421B10(0xf0, 0xf0, 8); return;
        case 5: M_421B10(0xff, 0xff, 8); return;
        default: return;
        }
    default:
        switch (a1)
        {
        case 0: M_421B10(0x78, 0x78, 8); return;
        case 1: M_421B10(0x90, 0x90, 8); return;
        case 2: M_421B10(0xa8, 0xa8, 8); return;
        case 3: M_421B10(0xc8, 0xc8, 8); return;
        case 4: M_421B10(0xdc, 0xdc, 8); return;
        case 5: M_421B10(0xf0, 0xf0, 8); return;
        default: return;
        }
    }
}

#ifdef MATCHED_NATIVE
extern "C" int g_cvt_ctor41_hits = 0;   // proof counters for the native boot
extern "C" int g_cvt_ctor5b_hits = 0;
extern "C" int g_cvt_5b17d0_hits = 0;
extern "C" void* cv_config_ptr = 0;
extern "C" int g_cvt_dc10_status = 0;
extern "C" int g_cvt_slot18_hits = 0;
extern "C" int g_cvt_slot24_hits = 0;
extern "C" int g_cvt_slot00_hits = 0;
#endif
extern void* g_6645c4;                 // global object slot at 0x6645C4
extern void* g_664510;                 // global slot at 0x664510
extern char g_66451c[0x1000];          // 0x66451C receives the 0x41DC10 result
extern char g_669558[0x1000];          // 0x669558 receives the 0x41DC80 object
extern int __stdcall Hook_473AE0(int a1, int a2, char* a3, int a4);

#ifdef MATCHED_NATIVE
// Native vtable replica for the five slots WinMain dispatches (+0x00/+0x04/
// +0x18/+0x24/+0x28). Unmatched slots go to a benign zero-returning trap. Slot
// 0x00 is the deleting destructor 0x5B1170, 0x18 is the matched +0x60 status
// getter, 0x24 is the matched 0x41C920 resource-string fill; 0x04 and 0x28
// remain lifted and are trapped.
static int vt62_trap(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6)
{
    (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6;
    return 0;
}
// 0x5B1170 is modelled in free_sim.cpp as Sd5B1170::D_5B1170(int flags).
class Sd5B1170 {
public:
    Sd5B1170* D_5B1170(int flags);
};
static void* vt62_slot00(void* obj, int flags)
{
    ++g_cvt_slot00_hits;
    return (void*)((Sd5B1170*)obj)->D_5B1170(flags);
}
static int vt62_slot04(void* obj)
{
    // 0x41CF70 is the window/menu message pump (slot +0x04); run its body.
    return ((C_vt61DF78*)(void*)obj)->C_vt61DF78::slot01_41CF70();
}
static int vt62_slot18(void* obj)
{
    ++g_cvt_slot18_hits;
    return *(int*)((char*)obj + 0x60);
}
static char* vt62_slot24(void* obj, int a1, char* buf, int len)
{
    ++g_cvt_slot24_hits;
    (void)obj;
    if (!Hook_473AE0((int)(size_t)g_664510, a1, buf, len))
        buf[0] = 0;
    buf[len - 1] = 0;
    return buf;
}
static int vt62_slot28(void* obj, int a1, int a2, int a3, char* a4, int a5)
{
    (void)obj; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    return 0;
}
#endif


// Host helpers for the 32-bit guest layout: the object is still described with
// 32-bit offsets, so the constructor writes scalar fields through raw offsets
// and keeps pointer-sized fields for last (a 64-bit pointer would otherwise
// clobber the next field on the host build).
static void SCvtI32(void* p, int off, int v) { *(int*)((char*)p + off) = v; }
static void SCvtU8(void* p, int off, int v) { *(unsigned char*)((char*)p + off) = (unsigned char)v; }


// 0x41B760 — base constructor. The original sets the base vtable 0x61DF78 and
// zeroes/initialises the whole pregame block, runs the 0x421Axx 0x421Bxx setter
// families (byte/float/array state), stores the parent config pointer at
// +0x24, then tries the 0x41DC10/0x41DC80/0x41BC80 window/device chain. Those
// three are still lifted stubs here, so this WIP body takes the same "failed"
// branch the original takes when 0x41DC10 returns 0 (status +0x60 = 0xE) and
// initialises the observable state the derived constructor and methods need.
WIP_FUNC(0x41B760)
C_vt62C1E0* C_vt62C1E0::M_41B760(void* parent, int flag)
{
#ifdef MATCHED_NATIVE
    ++g_cvt_ctor41_hits;
#endif
    memset(this, 0, 0x1c94);

    // pregame scalars from the original prologue
    SCvtI32(this, 0x08, -1); SCvtI32(this, 0x0c, -1);
    SCvtI32(this, 0x10, -1); SCvtI32(this, 0x14, -1);
    SCvtI32(this, 0x18, -1); SCvtI32(this, 0x1c, 0);
    SCvtI32(this, 0x20, 0);
    SCvtI32(this, 0x2c, 0); SCvtI32(this, 0x30, 1);
    SCvtI32(this, 0x34, 0); SCvtI32(this, 0x3c, 0);
    SCvtI32(this, 0x40, 0);
    SCvtI32(this, 0x44, -1); SCvtI32(this, 0x48, -1);
    SCvtI32(this, 0x4c, -1); SCvtI32(this, 0x50, -1);
    SCvtI32(this, 0x54, 0); SCvtI32(this, 0x58, 0); SCvtI32(this, 0x5c, 0);
    SCvtI32(this, 0x60, 0);              // success path leaves status 0
    SCvtI32(this, 0x64, 0); SCvtI32(this, 0x68, 0); SCvtI32(this, 0x6c, 0);
    SCvtU8(this, 0x70, 2);
    SCvtI32(this, 0x74, 0);
    SCvtI32(this, 0x7c, 0); SCvtI32(this, 0x80, 0); SCvtI32(this, 0x84, 0);
    *(unsigned short*)((char*)this + 0x88) = 0;
    SCvtI32(this, 0x8c, 0); SCvtI32(this, 0x90, 0);
    SCvtU8(this, 0x94, 0);
    SCvtI32(this, 0x98, 0); SCvtI32(this, 0x9c, 0); SCvtI32(this, 0xa0, 0);
    SCvtU8(this, 0xa4, 0);

    SCvtI32(this, 0x1a8, 0); SCvtI32(this, 0x1ac, 0); SCvtI32(this, 0x1b0, 0);
    SCvtI32(this, 0x1b4, 0); SCvtI32(this, 0x1b8, 0); SCvtI32(this, 0x1bc, 0);
    SCvtI32(this, 0x1c0, 0); SCvtI32(this, 0x1c4, 1);
    SCvtI32(this, 0x1c8, 0); SCvtI32(this, 0x1cc, 0); SCvtI32(this, 0x1d0, 0);
    SCvtI32(this, 0x1d4, 0); SCvtI32(this, 0x1d8, 0); SCvtI32(this, 0x1dc, 0);
    SCvtI32(this, 0x1e0, 0); SCvtI32(this, 0x1e4, 0); SCvtI32(this, 0x1e8, 0);
    SCvtI32(this, 0x1ec, 0); SCvtI32(this, 0x1f0, 0);
    SCvtI32(this, 0x1f4, 1); SCvtI32(this, 0x1f8, 1); SCvtI32(this, 0x1fc, 0);
    *(unsigned short*)((char*)this + 0x208) = 0;
    SCvtI32(this, 0x20c, 0);

    // getter/setter families folded inline (their bodies are byte-verified
    // members but live in TUs modelled with separate local classes):
    SCvtI32(this, 0x924, 0);             // 0x421A70 Set924Raw(0)
    SCvtU8(this, 0x928, 0);              // 0x421A60
    SCvtI32(this, 0x9d4, 0);             // 0x421AB0
    SCvtI32(this, 0x9d8, 0);             // 0x421AC0
    SCvtU8(this, 0x9a9, 1); SCvtU8(this, 0x9aa, 0);   // 0x421AD0(1)
    SCvtU8(this, 0x9aa, 0); SCvtU8(this, 0x9a9, 1);   // 0x421AF0(0)
    SCvtU8(this, 0x9ab, 0x60); SCvtU8(this, 0x9ac, 0x60); SCvtU8(this, 0x9ad, 8);
    SCvtU8(this, 0x9ae, 0);              // 0x421B40
    SCvtU8(this, 0x9b0, 1);              // 0x421B50
    SCvtU8(this, 0x9b1, 1);              // 0x421B70
    SCvtU8(this, 0x9b2, 1);              // 0x421B80
    SCvtI32(this, 0x9cc, 0x3fc00000);    // 0x421CD0
    SCvtI32(this, 0x108c, 0x3fc00000);   // 0x421CE0
    SCvtU8(this, 0x9c9, 0); SCvtU8(this, 0x9ca, 0);   // 0x421D30/40
    SCvtU8(this, 0x9b4, 0);              // 0x421BA0
    SCvtU8(this, 0x9be, 2);              // 0x421C20(2)
    int i;
    for (i = 0; i < 9; ++i) {            // 0x421C00/BB0/BD0/C30 loop
        SCvtU8(this, 0x9b5 + i, 0);
        SCvtU8(this, 0x9b5 + i, (*(unsigned char*)((char*)this + 0x9b5 + i)) & 0xfe);
        SCvtU8(this, 0x9b5 + i, (*(unsigned char*)((char*)this + 0x9b5 + i)) & 1);
        SCvtI32(this, 0x9c0 + i * 4, 1);
    }
    SCvtU8(this, 0x1094, 2);             // 0x421C50(2)
    SCvtU8(this, 0x9af, 2);              // 0x421C60(2)
    SCvtU8(this, 0x9b3, 4);              // 0x421B90(4)
    // 0x421A80("") copies the empty language path into +0x929; memset already
    // holds that block, and the terminator at +0x9A8 stays zero.

    // fixed scene defaults (words/bytes at +0x41C..+0x430)
    SCvtI32(this, 0x41c, 0); SCvtI32(this, 0x420, 1);
    *(unsigned short*)((char*)this + 0x424) = 0xffff;
    *(unsigned short*)((char*)this + 0x426) = 0;
    SCvtU8(this, 0x428, 0);
    *(unsigned short*)((char*)this + 0x42a) = 0xffff;
    *(unsigned short*)((char*)this + 0x42c) = 0xffff;
    *(unsigned short*)((char*)this + 0x42e) = 1;
    SCvtU8(this, 0x430, 0);

    SCvtI32(this, 0x530, 0); SCvtI32(this, 0x534, 0); SCvtI32(this, 0x538, 0);
    SCvtI32(this, 0x53c, 0); SCvtI32(this, 0x540, 0); SCvtI32(this, 0x544, 0);
    SCvtI32(this, 0x548, 0); SCvtI32(this, 0x54c, 0); SCvtI32(this, 0x550, 0);
    SCvtI32(this, 0x914, 0); SCvtI32(this, 0x918, 0); SCvtI32(this, 0x91c, 0);
    SCvtI32(this, 0x920, 0);
    SCvtI32(this, 0xb38, 0); SCvtI32(this, 0xb44, 0); SCvtI32(this, 0xb48, 1);
    SCvtI32(this, 0x9e0, 1);
    SCvtI32(this, 0x108c, 0x3fc00000);   // 0x421CE0 wins over 0x421CD0 later
    SCvtI32(this, 0x1090, 3);
    SCvtI32(this, 0x10a0, 0);
    SCvtI32(this, 0xa08, 0); SCvtI32(this, 0xa0c, 0);

    g_6645c4 = this;
    g_664510 = 0;

    // pointer-sized parent config block: write last so +0x2C stays zero.
    *(void**)((char*)this + 0x24) = parent;
#ifdef MATCHED_NATIVE
    cv_config_ptr = parent;
#endif

    // device chain: 0x41DC10 is now a byte-verified native body (allocates the
    // 0x110 registry/context object and stores it at +0x1D4). 0x41DC80 is still
    // WIP without native helper wiring, so this body takes the original's
    // 0x41DC80-failure branch (+0x60 = 0xF) after the 0x41DC10 success contract
    // (g_66451C = +0x1D4) has run.
#ifdef MATCHED_NATIVE
    if (!((C_vt61DF78*)(void*)this)->C_vt61DF78::slot36_41DC10())
    {
        SCvtI32(this, 0x60, 0x0e);
        return this;
    }
    *(int*)g_66451c = *(int*)((char*)this + 0x1d4);
    if (!((C_vt61DF78*)(void*)this)->C_vt61DF78::slot37_41DC80())
    {
        SCvtI32(this, 0x60, 0x0f);
        g_cvt_dc10_status = 0x0f;
        return this;
    }
    *(int*)g_669558 = *(int*)((char*)this + 0x1c8);
    // device/window bring-up: the original calls 0x41BC80 only when the caller
    // passed a non-zero flag; a zero result while status is still zero raises
    // the status to 1.
    if (flag != 0)
    {
        if (!((C_vt61DF78*)(void*)this)->C_vt61DF78::slot29_41BC80()
            && *(int*)((char*)this + 0x60) == 0)
            SCvtI32(this, 0x60, 1);
    }
    g_cvt_dc10_status = *(int*)((char*)this + 0x60);
#endif
    return this;
}

// 0x5B17D0 — game-session bring-up called by the derived constructor when the
// caller flag is set. WIP: the original runs the five 0x4BE0F0 registry writes,
// calls 0x41BC80, creates the DirectPlay/session objects (0x5ECE38, 0x51D140,
// 0x49F770, 0x42DBC0, 0x4F2390, 0x4FFE00, 0x4F4920), builds the session screen
// via 0x4320E0/0x421710/0x421AF0 and drives its +0x20/+0x158 slots before
// returning 1. Only the status contract and the 0x41BC80 call are modelled:
// status must be 0 to enter, 0x41BC80's failure returns 0, success returns 1
// and leaves status 0.
WIP_FUNC(0x5B17D0)
int C_vt62C1E0::M_5B17D0()
{
#ifdef MATCHED_NATIVE
    ++g_cvt_5b17d0_hits;
#endif
    if (*(int*)((char*)this + 0x60) != 0)
        return 0;
    if (!((C_vt61DF78*)(void*)this)->C_vt61DF78::slot29_41BC80())
        return 0;
    return 1;
}

// 0x5B0EC0 — derived constructor for the 0x1C94 sim/config object. The original
// calls the 0x41B760 base with the config pointer and a zero flag, clears the
// +0x1460.. scene block, installs the 0x62C1E0 vtable, drives the 0x5BAxxx /
// 0x5BBxxx state setter family, walks nine globals 0x75FE04..0x75FE28 setting
// their +0/+bytes, clears nine dwords at +0x1AB8, runs 0x421B90(4) and
// 0x5BC460, and finally calls 0x5B17D0 when the caller flag is set.
WIP_FUNC(0x5B0EC0)
C_vt62C1E0* C_vt62C1E0::M_5B0EC0(void* parent, int flag)
{
#ifdef MATCHED_NATIVE
    ++g_cvt_ctor5b_hits;
#endif
    M_41B760(parent, 0);

    SCvtI32(this, 0x1464, -1);
    SCvtI32(this, 0x200, 1);
    SCvtI32(this, 0x11d4, 2);

    M_5BAD80(0);
    M_5BAEC0(2);
    SetInt_5BAD60(0);
    M_5BAEE0((char*)ADDR(0x662be0));
    SetInt_5BAF20(1);
    SetInt_5BAF40(1);
    Set_5BAF70(1, 1);
    SetByte_5BB170(1);
    SetByte_5BB180(0);
    SetByte_5BB190(0);
    SetByte_5BB1A0(0);
    SetInt_5BB1B0(0);
    SetInt_5BB1C0(0);
    SetByte_5BB1D0(0);
    SetByte_5BB1E0(0);
    SetByte_5BB1F0(0);
    SetByte_5BB200(0x4b);
    SetByte_5BB210(0);
    SetInt_5BB220(-1);
    SCvtI32(this, 0x1458, 0);
    SCvtU8(this, 0x145c, 0);
    SCvtU8(this, 0x145d, 0);

    int i;
    for (i = 0; i < 9; ++i)
    {
        SetByte_5BAFA0(i, 1);
        SetInt_5BAFD0(i, i);
        Set_5BB000(1, i);
        SetByte2_5BB040(i, 0);
        M_5BB080(i, 0);
        // global tables 0x75FE04..0x75FE28 and the three 0x75FDF8 byte arrays
        ADDR(0x75fe04);  // the native build cannot address the guest image here
    }

    // 0x421B90(4): +0x9B3 = 4 (folded; the setter lives in free_game)
    SCvtU8(this, 0x9b3, 4);
    // 0x5BC460: clear 0x5A dwords starting at the unaligned +0x1AE5
    for (i = 0; i < 0x5a; ++i)
        *(int*)((char*)this + 0x1ae5 + i * 4) = 0;

    if (flag != 0)
    {
        // 0x5B17D0 is now modelled natively (WIP) and calls the WIP 0x41BC80
        // bring-up; its success contract leaves status 0 and returns 1.
        if (!M_5B17D0() && *(int*)((char*)this + 0x60) == 0)
            SCvtI32(this, 0x60, 1);
    }

#ifdef MATCHED_NATIVE
    static void* s_vt62[87];
    static int s_vt62_ready;
    if (!s_vt62_ready)
    {
        int k;
        for (k = 0; k < 87; ++k)
            s_vt62[k] = (void*)vt62_trap;
        s_vt62[0] = (void*)vt62_slot00;
        s_vt62[1] = (void*)vt62_slot04;
        s_vt62[6] = (void*)vt62_slot18;
        s_vt62[9] = (void*)vt62_slot24;
        s_vt62[10] = (void*)vt62_slot28;
        s_vt62_ready = 1;
    }
    *(void**)this = s_vt62;
#else
    *(unsigned int*)this = 0x62c1e0;
#endif
    return this;
}
