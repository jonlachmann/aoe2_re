#include "C_vt62C1E0.hpp"
#include "app/C_vt61DF78.hpp"
#include "game/C_cluster_421430.hpp"
#include <new>
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

// Menu-idle tick 0x5BB2D0 (vtable slot +0xD0) dependencies.
extern int g_664520;                         // host config pointer slot (0x664520)
extern unsigned int (__stdcall *cv_61c3c8)(); // timeGetTime trampoline

class S50GetBulk { public: int Get_501950(); };
class S49F620 { public: int Get_49F620(); };
class S4FFDE0 { public: void M_4FFDE0(int v); };
class S42D490 { public: int M_42D490(); };
class C_cluster_42A9F0 { public: int Get_42D470(); };
class C_vt61CE24 { public: int Get_48F970(); };

extern "C" void __stdcall Hook_5F8F60(int size);
extern "C" void __stdcall Hook_433ED0(void* obj);
extern "C" void __stdcall Hook_4A5D40(int obj, char* text, int a3, int a4, int a5);
extern "C" int __stdcall Hook_42F640(void* obj);
extern "C" void __stdcall Hook_5B9DF0(void* obj);
extern "C" int __stdcall Hook_42D610(void* obj, int index);
extern "C" char* __stdcall Hook_425530(void* obj, int index);
extern "C" void* __stdcall Hook_49F630(int id);
extern "C" int __stdcall Hook_520C40(void* obj);
extern "C" void __stdcall Hook_520BA0(void* obj);
extern "C" void __stdcall Hook_5200A0();
extern "C" void __stdcall Hook_5C9A50(void* obj);
extern "C" void __stdcall Hook_5C9DC0();
extern "C" void __stdcall Hook_4DB890();
extern "C" void __stdcall Hook_Vt16(void* obj);
extern "C" int __stdcall Hook_SendMessageA(void* hwnd, unsigned msg, int wp, int lp);

#ifdef MATCHED_NATIVE
extern "C" int g_cvt_idle_hits = 0;
#endif

static void* GuestPtr(unsigned va)
{
    unsigned v = *(unsigned int*)ADDR(va);
    return v == 0 ? 0 : ADDR((void*)(unsigned long)v);
}

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
// Native vtable replica for the slots the matched bodies dispatch: +0x00
// (0x5B1170 dtor), +0x04 (0x41CF70 pump), +0x08 (0x5BB240 message dispatch),
// +0x18 (+0x60 status getter), +0x24 (0x41C920 string fill), +0x28 (0x5BB240
// wrapper) and +0xD0 (0x5BB2D0 idle tick). Unmatched slots go to a benign
// zero-returning trap.
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
static int vt62_slot50(void* obj, int a1, int a2, int a3, int a4, int a5)
{
    return sub_5BB240((C_vt62C1E0*)obj, a1, (unsigned int)a2, a3, a4 + a5);
}
static int vt62_slot52(void* obj)
{
    // 0x5BB2D0 is the menu/game idle tick (slot +0xD0).
    return ((C_vt62C1E0*)obj)->M_5BB2D0();
}
extern "C" int Native_MenuIdleTicks(void* obj, int count)
{
    int n = 0;
    if (obj != 0)
    {
        while (n < count)
        {
            ((C_vt62C1E0*)obj)->M_5BB2D0();
            ++n;
        }
    }
    return n;
}
#endif


// Raw 32-bit-layout field access: the guest object is described by its
// 32-bit offsets, so these bodies address it by offset (the class's typed
// void* fields would shift on the 64-bit host build).
#define CV_I32(o) (*(int*)((char*)this + (o)))
#define CV_U16(o) (*(unsigned short*)((char*)this + (o)))
#define CV_U8(o) (*(unsigned char*)((char*)this + (o)))
#define CV_PTR(o) (*(char**)((char*)this + (o)))
#ifdef MATCHED_NATIVE
extern "C" void* cv_regctx;            // native registry context (+0x1D4), C_vt61DF78.cpp
#define CV_CFG() ((char*)cv_config_ptr)
#define CV_REGCTX() ((S4BE080*)cv_regctx)
#else
#define CV_CFG() (*(char**)((char*)this + 0x24))
#define CV_REGCTX() (*(S4BE080**)((char*)this + 0x1d4))
#endif

// Callees of 0x41B760/0x5B0EC0/0x5B17D0 that are byte-verified members of
// local classes in other TUs (same class names, so the symbols resolve).
class S421AD0 { public: void M_421AF0(int v); };                 // free_game
class S421Accessors {                                              // free_game
public:
    void Set9BF_421710(unsigned char v);
    void Set9B0_421B50(unsigned char v);
    void Set9B2_421B80(unsigned char v);
    void Set9B3_421B90(unsigned char v);
    void Clear9B4_421BA0(unsigned char unused);
    void SetBit_421BB0(int index, unsigned char v);
    void Set1094_421C50(unsigned char v);
};
class S421CF0 { public: void Set9CC_421CD0(int v); void Set108C_421CE0(int v); };   // free_game
class S421C00 {                                                    // free_game
public:
    void Set_421C00(int index, unsigned char v);
    void Set_421C30(int index, unsigned char v);
    void Set_421C60(unsigned char v);
};
class S421BD0 { public: void M_421BD0(int index, unsigned char v); };   // free_game
class S5BC460 { public: void Clear_5BC460(); };                   // free_sim
class S4BE080 { public: int M_4BE080(int a1, int a2); };          // free_ui
class Sc422180 { public: bool M_422180(int a1); };                // free_game
class S49F770 { public: int M_49F770(int a1, int a2); };          // free_ui
class S41F5F0 { public: void M_41F5F0(); };                       // free_app
class S4320E0 { public: void M_4320E0(unsigned char v); };        // free_game
class S4FFE00 { public: void M_4FFE00(int v); };                  // free_ui
class S_5B1CD0 { public: void M_5B1CD0(); };                      // free_sim
// Unresolved callees (lifted only).
class T4A5CE0 { public: void M_4A5CE0(int a1, int a2, int a3, int a4, int a5); };
class C_cluster_49F630 { public: T4A5CE0* M_49F630(int name); int M_49F960(int a1); };
class T42DBC0 { public: int M_42DBC0(); };                        // [this+0x1B0] screen manager
class T51D140 { public: char pad_00[0x840]; T51D140(int a1, int a2, int a3, int a4, int a5); };
class T4F2390 { public: char pad_00[0xdc]; int field_dc; char pad_e0[0x7f0 - 0xe0]; T4F2390(); };
class T4A5D40 { public: void M_4A5D40(char* text, int a2, int a3, int a4, int a5); };
class T4F4920 : public T4A5D40 { public: char pad_00[0xdbc]; T4F4920(); };
class T4F3460 : public T4A5D40 { public: char pad_00[0x1c24]; T4F3460(int a1); };
class T15F0 { public: char pad_00[0x17c]; int field_17c; };
class T1B0 { public: char pad_00[0x15f0]; T15F0* field_15f0; T15F0* Get15F0() { return field_15f0; } };
class S5B1Session {                                                // 0x62C1E0 methods, unresolved
public:
    int M_5B8260(char* name, int a2);
    int M_5BA080(char* name, int a2);
    int M_5B84F0(char* name, int a2);
    int M_5B50D0(int a1);
    void M_5B4590(int a1, char* a2);
    void M_5B5740();
};
// Virtual dispatch through the 0x62C1E0 vtable (+0x20 string getter, +0x158).
class CvVt62C1E0 {
public:
    virtual void vs_000();
    virtual void vs_004();
    virtual void vs_008();
    virtual void vs_00C();
    virtual void vs_010();
    virtual void vs_014();
    virtual void vs_018();
    virtual void vs_01C();
    virtual char* GetString_20(int id);   // +0x020 (0x41C900)
    virtual void vs_024();
    virtual void vs_028();
    virtual void vs_02C();
    virtual void vs_030();
    virtual void vs_034();
    virtual void vs_038();
    virtual void vs_03C();
    virtual void vs_040();
    virtual void vs_044();
    virtual void vs_048();
    virtual void vs_04C();
    virtual void vs_050();
    virtual void vs_054();
    virtual void vs_058();
    virtual void vs_05C();
    virtual void vs_060();
    virtual void vs_064();
    virtual void vs_068();
    virtual void vs_06C();
    virtual void vs_070();
    virtual void vs_074();
    virtual void vs_078();
    virtual void vs_07C();
    virtual void vs_080();
    virtual void vs_084();
    virtual void vs_088();
    virtual void vs_08C();
    virtual void vs_090();
    virtual void vs_094();
    virtual void vs_098();
    virtual void vs_09C();
    virtual void vs_0A0();
    virtual void vs_0A4();
    virtual void vs_0A8();
    virtual void vs_0AC();
    virtual void vs_0B0();
    virtual void vs_0B4();
    virtual void vs_0B8();
    virtual void vs_0BC();
    virtual void vs_0C0();
    virtual void vs_0C4();
    virtual void vs_0C8();
    virtual void vs_0CC();
    virtual void vs_0D0();
    virtual void vs_0D4();
    virtual void vs_0D8();
    virtual void vs_0DC();
    virtual void vs_0E0();
    virtual void vs_0E4();
    virtual void vs_0E8();
    virtual void vs_0EC();
    virtual void vs_0F0();
    virtual void vs_0F4();
    virtual void vs_0F8();
    virtual void vs_0FC();
    virtual void vs_100();
    virtual void vs_104();
    virtual void vs_108();
    virtual void vs_10C();
    virtual void vs_110();
    virtual void vs_114();
    virtual void vs_118();
    virtual void vs_11C();
    virtual void vs_120();
    virtual void vs_124();
    virtual void vs_128();
    virtual void vs_12C();
    virtual void vs_130();
    virtual void vs_134();
    virtual void vs_138();
    virtual void vs_13C();
    virtual void vs_140();
    virtual void vs_144();
    virtual void vs_148();
    virtual void vs_14C();
    virtual void vs_150();
    virtual void vs_154();
    virtual void Slot_158();              // +0x158 (0x5BC500)
};

extern int g_664514, g_664518, g_664520, g_664524, g_664528, g_66452c, g_66450c;
extern int g_64d4c0, g_75ff18, g_6645b0, g_6645b4, g_75fddc, g_75fdd8, g_75fdd4, g_75fdd0;
extern unsigned char g_75ff35;
extern int g_75fe04[9];
extern unsigned char g_75fdf8[9], g_75fdec[9], g_75fde0[9];
extern int g_75ff44, g_65d3e4, g_664538;
extern int (__stdcall *g_61c308)(int a1, int a2);                         // LoadCursorA
extern unsigned long (__stdcall *g_61c1b4)(unsigned long n, char* buf);  // GetCurrentDirectoryA
extern int (__stdcall *g_61c398)(int ex, char* cls, char* name, int style, int x, int y,
                                  int w, int h, int parent, int menu, int inst, void* param); // CreateWindowExA
extern unsigned int (__stdcall *g_61c3c8)();                              // timeGetTime
extern "C" void __cdecl sub_4BE0F0(char* a1, char* a2, char* a3, int a4);    // registry write
extern "C" int __stdcall ICInfo_5ECE38(int fccType, int fccHandler, void* info); // MSVFW32 thunk
extern char* __cdecl sub_5FCC80(char* a1, char* a2);                      // strstr

#ifdef _MSC_VER
#pragma intrinsic(memset, strcpy)     // these bodies inline memset/strcpy
#endif

// 0x41B760 — base (application, vtable 0x61DF78) constructor body, entered as
// a thiscall member by the 0x5B0EC0 constructor. Owner is really C_vt61DF78
// (it installs vtable 0x61DF78); parked here with its only caller. Matched
// once the 0x9DC store preceded the vtable store, the 0x530.. block was nine
// plain stores (a loop turns into rep stosd), the 0xFFFF words were signed
// short -1 (so VC6 shares one -1 register with the +8..+18 dwords) and those
// five dwords were a loop. memset/strcpy are the inline intrinsics here.
MATCH_FUNC(0x41B760)
C_vt62C1E0* C_vt62C1E0::M_41B760(void* parent, int flag)
{
    int i;
#ifdef MATCHED_NATIVE
    ++g_cvt_ctor41_hits;
#endif

    CV_I32(0x1c) = 0;
    CV_I32(0x44) = -1;
    CV_I32(0x48) = -1;
    CV_I32(0x4c) = -1;
    CV_I32(0x50) = -1;
    CV_I32(0x58) = 0;
    CV_I32(0x9dc) = 0;
    *(unsigned int*)this = 0x61df78;
    memset((char*)this + 0xa10, 0, 0x24);
    memset((char*)this + 0x924, 0, 0xb0);
    memset((char*)this + 0x1078, 0, 0x14);
    CV_I32(0x5c) = 0;
    ((C_cluster_421430*)this)->Set924Raw_421A70(0x40000000);
    Set928_421A60(0);
    Set9D4_421AB0(0);
    Set9D8_421AC0(0);
    M_421AD0(1);
    ((S421AD0*)this)->M_421AF0(0);
    M_421B10(0x60, 0x60, 8);
    Set9AE_421B40(0);
    ((S421Accessors*)this)->Set9B0_421B50(1);
    Set9B1_421B70(1);
    ((S421Accessors*)this)->Set9B2_421B80(1);
    ((S421CF0*)this)->Set108C_421CE0(0x3fc00000);
    ((S421CF0*)this)->Set9CC_421CD0(0x3fc00000);
    ClearC9_421D30();
    ClearCA_421D40();
    ((S421Accessors*)this)->Clear9B4_421BA0(0);
    Set9BE_421C20(2);
    for (i = 0; i < 9; i++)
    {
        ((S421C00*)this)->Set_421C00(i, 0);
        ((S421Accessors*)this)->SetBit_421BB0(i, 0);
        ((S421BD0*)this)->M_421BD0(i, 0);
        ((S421C00*)this)->Set_421C30(i, 1);
    }
    ((S421Accessors*)this)->Set1094_421C50(2);
    ((S421C00*)this)->Set_421C60(2);
    ((S421Accessors*)this)->Set9B3_421B90(4);
    M_421A80((char*)ADDR(0x662be0));

    g_6645c4 = this;
    *(void**)((char*)this + 0x24) = parent;
#ifdef MATCHED_NATIVE
    cv_config_ptr = parent;
#endif
    CV_I32(0x28) = 0;
    CV_I32(0x2c) = 0;
    CV_I32(0x30) = 1;
    CV_I32(0x34) = 0;
    CV_I32(0x3c) = 0;
    g_664510 = 0;
    CV_I32(0x54) = 0;
    CV_I32(0x60) = 0;
    CV_I32(0x64) = 0;
    CV_I32(0x68) = 0;
    CV_I32(0x6c) = 0;
    CV_U8(0x70) = 2;
    CV_I32(0x74) = 0;
    CV_I32(0x7c) = 0;
    CV_I32(0x80) = 0;
    CV_I32(0x84) = 0;
    CV_U16(0x88) = 0;
    CV_I32(0x8c) = 0;
    CV_I32(0x90) = 0;
    for (i = 0; i < 5; i++)
    {
        CV_I32(0x1064 + i * 4) = 0;
        CV_U8(0xb50 + i * 0x104) = 0;
    }
    CV_U8(0x94) = 0;
    CV_I32(0x98) = 0;
    CV_I32(0x9c) = 0;
    CV_I32(0xa0) = 0;
    CV_U8(0xa4) = 0;
    CV_I32(0x1a8) = 0;
    CV_I32(0x1ac) = 0;
    CV_I32(0x1b0) = 0;
    g_66450c = 0;
    CV_I32(0x1c8) = 0;
    CV_I32(0x1cc) = 0;
    CV_I32(0x1d0) = 0;
    CV_I32(0x1b4) = 0;
    CV_I32(0x1bc) = 0;
    CV_I32(0x1c0) = 0;
    CV_I32(0x1c4) = 1;
    CV_I32(0x1b8) = 0;
    CV_I32(0xb44) = 0;
    CV_I32(0x1d4) = 0;
    CV_I32(0x1d8) = 0;
    CV_I32(0x1dc) = 0;
    CV_I32(0x1e0) = 0;
    CV_I32(0x1e4) = 0;
    CV_I32(0x1e8) = 0;
    CV_I32(0x1ec) = 0;
    CV_I32(0x1f0) = 0;
    CV_I32(0x1f4) = 1;
    CV_I32(0x1f8) = 1;
    CV_I32(0x1fc) = g_61c308(0, 0x7f00);
    CV_U16(0x208) = 0;
    CV_I32(0x20c) = 0;
    g_61c1b4(0x105, (char*)this + 0x210);
    strcpy((char*)this + 0x315, (char*)ADDR(0x64d58c));
    CV_I32(0x41c) = 0;
    CV_I32(0x420) = 1;
    *(short*)((char*)this + 0x424) = -1;
    CV_U16(0x426) = 0;
    CV_U8(0x428) = 0;
    *(short*)((char*)this + 0x42a) = -1;
    *(short*)((char*)this + 0x42c) = -1;
    CV_U16(0x42e) = 1;
    CV_U8(0x430) = 0;
    CV_I32(0x530) = 0;
    CV_I32(0x534) = 0;
    CV_I32(0x538) = 0;
    CV_I32(0x53c) = 0;
    CV_I32(0x540) = 0;
    CV_I32(0x544) = 0;
    CV_I32(0x548) = 0;
    CV_I32(0x54c) = 0;
    CV_I32(0x550) = 0;
    CV_I32(0x920) = 0;
    for (i = 0; i < 0x1e; i++)
    {
        CV_I32(0x554 + i * 0x20) = 0;
        CV_I32(0x558 + i * 0x20) = 0;
        CV_I32(0x55c + i * 0x20) = 0;
        CV_I32(0x568 + i * 0x20) = 0;
        CV_I32(0x56c + i * 0x20) = 0;
        CV_I32(0x570 + i * 0x20) = 0;
        CV_I32(0x560 + i * 0x20) = 0;
        CV_I32(0x564 + i * 0x20) = 0;
    }
    CV_I32(0x914) = 0;
    CV_I32(0x918) = 0;
    CV_I32(0x91c) = 0;
    CV_I32(0x9e0) = 1;
    CV_I32(0x40) = 0;
    *(int*)g_669558 = 0;
    g_66452c = *(int*)(CV_CFG() + 0x410);
    g_664528 = 0;
    g_664524 = 0;
    g_664520 = 0;
    *(int*)g_66451c = 0;
    g_664518 = 0;
    g_664514 = 0;
    CV_I32(0x20) = 0;
    for (i = 0; i < 9; i++)
    {
        CV_I32(0x9e4 + i * 4) = 0;
        CV_U8(0x1095 + i) = 0;
    }
    for (i = 0; i < 5; i++)
        CV_I32(8 + i * 4) = -1;
    CV_I32(0xb38) = 0;
    CV_I32(0xb48) = 1;
    CV_I32(0x10a0) = 0;
    CV_I32(0x108c) = 0x3fc00000;
    CV_I32(0x1090) = 3;
#ifdef MATCHED_NATIVE
    // 64-bit host: rewrite the full parent pointer (the +0x28 store above
    // clobbered its upper half); native callers read it via cv_config_ptr.
    *(void**)((char*)this + 0x24) = parent;
#endif
    if (!((C_vt61DF78*)(void*)this)->C_vt61DF78::slot36_41DC10())
    {
        CV_I32(0x60) = 0xe;
        return this;
    }
    *(int*)g_66451c = CV_I32(0x1d4);
    if (!((C_vt61DF78*)(void*)this)->C_vt61DF78::slot37_41DC80())
    {
        CV_I32(0x60) = 0xf;
#ifdef MATCHED_NATIVE
        g_cvt_dc10_status = 0xf;
#endif
        return this;
    }
    *(int*)g_669558 = CV_I32(0x1c8);
    if (flag != 0 && !((C_vt61DF78*)(void*)this)->C_vt61DF78::slot29_41BC80() && CV_I32(0x60) == 0)
        CV_I32(0x60) = 1;
    CV_I32(0xa08) = 0;
    CV_I32(0xa0c) = 0;
    CV_U8(0x4) = 0xff;
#ifdef MATCHED_NATIVE
    g_cvt_dc10_status = CV_I32(0x60);
#endif
    return this;
}

// 0x5B17D0 — vtable 0x62C1E0 slot +0x74 (override of 0x41BC80): game-session
// bring-up. Five 0x4BE0F0 registry writes, the base 0x41BC80, a hidden
// CreateWindowExA child at +0x204, ICInfo('vidc','iv50'), two registry flags
// into +0x1C8C/+0x1C90, the 0x63 string check, the command-line strstr bail
// (status 4), then either the 0x422180 multiplayer path (0x51D140 / 0x42DBC0
// result: -1 -> 0x4F2390 dialog, 1 -> 0x4F4920/0x4F3460 screens) or the
// scenario/campaign/saved-game launch through 0x5B8260/0x5BA080/0x5B84F0.
// The catalog's 862 bytes stop mid-function; the whole 0x4F9-byte body matches.
// The [+0x1B0]->+0x15F0 load needs the inline getter (raw casts pick ecx).
MATCH_FUNC(0x5B17D0)
int C_vt62C1E0::M_5B17D0()
{
    char info[0x238];                   // ICINFO filled by ICInfo('vidc','iv50')
    int i;
    int r;
#ifdef MATCHED_NATIVE
    ++g_cvt_5b17d0_hits;
    // ponytail: native boot keeps the pre-match path (0x41BC80 only); the full
    // body below faults on virtual calls through 32-bit guest vtables
    // (0x62C220). Drop this when those slots are native.
    if (CV_I32(0x60) != 0)
        return 0;
    return ((C_vt61DF78*)(void*)this)->C_vt61DF78::slot29_41BC80() ? 1 : 0;
#endif
    if (CV_I32(0x60) != 0)
        return 0;
    sub_4BE0F0((char*)ADDR(0x65d43c), (char*)ADDR(0x65d5d8), CV_CFG() + 0x1467, 1);
    sub_4BE0F0((char*)ADDR(0x65d42c), (char*)ADDR(0x65d5d8), CV_CFG() + 0x1467, 0);
    sub_4BE0F0((char*)ADDR(0x65d420), (char*)ADDR(0x65d5d8), CV_CFG() + 0x1467, 0);
    sub_4BE0F0((char*)ADDR(0x65d410), (char*)ADDR(0x65d5d8), CV_CFG() + 0x1467, 0);
    sub_4BE0F0((char*)ADDR(0x65d400), (char*)ADDR(0x65d5d8), CV_CFG() + 0x1467, 0);
    if (!((C_vt61DF78*)(void*)this)->C_vt61DF78::slot29_41BC80())
        return 0;
    for (i = 0; i < 7; i++)
    {
        CV_U8(0x1c68 + i) = 0;
        CV_I32(0x1c70 + i * 4) = 0;
    }
    CV_I32(0x204) = g_61c398(0, (char*)ADDR(0x65d5bc), (char*)ADDR(0x65d5c4), 0x40000000,
                             0, 0, 1, 1, CV_I32(0x28), 0, *(int*)(CV_CFG() + 0x410), 0);
    g_75ff44 = ICInfo_5ECE38(0x63646976, 0x30357669, info);
    if (CV_REGCTX()->M_4BE080(1, (int)(size_t)ADDR(0x65d570)) == 1)
        CV_I32(0x1c8c) = 1;
    else
        CV_I32(0x1c8c) = 0;
    if (CV_REGCTX()->M_4BE080(1, (int)(size_t)ADDR(0x65d558)) == 1)
        CV_I32(0x1c90) = 1;
    else
        CV_I32(0x1c90) = 0;
    char* s = ((CvVt62C1E0*)this)->GetString_20(0x63);
    if (s != 0 && *s == '0')
        g_65d3e4 = 0;
    if (sub_5FCC80(CV_CFG() + 0x518, (char*)ADDR(0x65d5b4)) != 0
        || sub_5FCC80(CV_CFG() + 0x518, (char*)ADDR(0x65d5ac)) != 0)
    {
        ((S5B1Session*)this)->M_5B5740();
        CV_I32(0x60) = 4;
        return 0;
    }
    if (((Sc422180*)this)->M_422180((int)(size_t)ADDR(0x64d8e8)))
    {
        new T51D140((int)(size_t)ADDR(0x64d90c), 0x4bf, (int)(size_t)ADDR(0x6547ac), 0xc383, 0);
        ((S49F770*)ADDR(0x66ea48))->M_49F770((int)(size_t)ADDR(0x64d90c), 0);
        r = ((T42DBC0*)CV_PTR(0x1b0))->M_42DBC0();
        if (r == -1)
        {
            T4F2390* p = new T4F2390();
            if (p == 0 || p->field_dc != 0)
                return 0;
            ((S4FFE00*)p)->M_4FFE00(0x96a);
            ((S49F770*)ADDR(0x66ea48))->M_49F770((int)(size_t)ADDR(0x6547b4), 0);
            ((C_cluster_49F630*)ADDR(0x66ea48))->M_49F960((int)(size_t)ADDR(0x64d90c));
        }
        else if (r != 1)
        {
            ((S41F5F0*)this)->M_41F5F0();
            return 1;
        }
        else
        {
            CV_I32(0x1c58) = 1;
            CV_I32(0x1c5c) = g_61c3c8();
            if (((T1B0*)CV_PTR(0x1b0))->Get15F0()->field_17c == 1)
            {
                ((S4320E0*)(size_t)g_664520)->M_4320E0(0);
                ((S421Accessors*)this)->Set9BF_421710(0);
                ((S421AD0*)this)->M_421AF0(1);
                T4F4920* scr = new T4F4920();
                if (g_664538 != 0)
                {
                    if (scr != 0)
                        scr->M_4A5D40(((CvVt62C1E0*)this)->GetString_20(0x7df), 0, 400, 0xbe, 1);
                    g_664538 = 0;
                }
            }
            else
            {
                ((S4320E0*)(size_t)g_664520)->M_4320E0(1);
                ((S421Accessors*)this)->Set9BF_421710(1);
                ((S421AD0*)this)->M_421AF0(1);
                T4F3460* scr = new T4F3460(0);
                if (g_664538 != 0)
                {
                    if (scr != 0)
                        scr->M_4A5D40(((CvVt62C1E0*)this)->GetString_20(0x7df), 0, 400, 0xbe, 1);
                    g_664538 = 0;
                }
            }
        }
    }
    else
    {
        if (CV_U8(0x14a0) != 0)
        {
            if (!((S5B1Session*)this)->M_5B8260((char*)this + 0x14a0, 1))
            {
                if (!((S5B1Session*)this)->M_5B50D0(0))
                    return 0;
                T4A5CE0* w = ((C_cluster_49F630*)ADDR(0x66ea48))->M_49F630((int)(size_t)ADDR(0x652338));
                if (w != 0)
                    w->M_4A5CE0(0x961, 0, 0x1c2, 0x64, 1);
            }
        }
        else if (CV_U8(0x15a4) != 0)
        {
            if (!((S5B1Session*)this)->M_5BA080((char*)this + 0x15a4, 0))
            {
                if (!((S5B1Session*)this)->M_5B50D0(0))
                    return 0;
                T4A5CE0* w = ((C_cluster_49F630*)ADDR(0x66ea48))->M_49F630((int)(size_t)ADDR(0x652338));
                if (w != 0)
                    w->M_4A5CE0(0x961, 0, 0x1c2, 0x64, 1);
            }
        }
        else if (CV_U8(0x16a8) != 0)
        {
            if (!((S5B1Session*)this)->M_5B84F0((char*)this + 0x16a8, 0))
            {
                if (!((S5B1Session*)this)->M_5B50D0(0))
                    return 0;
                T4A5CE0* w = ((C_cluster_49F630*)ADDR(0x66ea48))->M_49F630((int)(size_t)ADDR(0x652338));
                if (w != 0)
                    w->M_4A5CE0(0x961, 0, 0x1c2, 0x64, 1);
            }
        }
        else if (*(int*)(CV_CFG() + 0x890) == 0)
            ((S5B1Session*)this)->M_5B4590(0, (char*)ADDR(0x65d5a4));
        else if (!((S5B1Session*)this)->M_5B50D0(0))
            return 0;
    }
    ((CvVt62C1E0*)this)->Slot_158();
    ((S_5B1CD0*)this)->M_5B1CD0();
    return 1;
}

// 0x5BB2D0 (vtable slot +0xD0) — the menu/game idle tick. WIP semantic body:
// the original carries a four-byte SEH frame and a 0x968-byte stack frame
// (2304-byte resource string + 100-byte SendMessage poll buffer) that VC6 C++
// source cannot reproduce byte-for-byte, so this body is reconstructed for
// behaviour and class layout. It (1) probes the 0x75FF3C bulk object and
// re-adds this through 0x5B4B10 when live; (2) watches the +0x1C58 lobby gate,
// refreshing the +0x15F0 config block when elapsed <= 0x7530, otherwise clearing
// the gate, freeing 2032 bytes, refreshing the 0x66EA48 accessor and posting the
// 400x190 message when +0x664538 and the accessor agree; (3) runs the matched
// periodic tick 0x420450, gates on +0x1C54, reads +0x1D8, handles mode 3's
// 0x75FF50 half-second UI string rebuild and modes 4/5/6's 0x75FF35 one-shot
// scene scan, then the mode-1 SendMessageA poll at +0x1470/+0x146C/+0x1460;
// finally it clears +0x1C54 and returns the tick result.
WIP_FUNC(0x5BB2D0)
int C_vt62C1E0::M_5BB2D0()
{
#ifdef MATCHED_NATIVE
    ++g_cvt_idle_hits;
#endif
    char* self = (char*)this;
    int v2 = 1;
    void* bulk = GuestPtr(0x75ff3c);
    if (bulk != 0 && ((S50GetBulk*)bulk)->Get_501950() != 0)
        Hook_5B4B10(1);

    if (*(int*)(self + 0x1c58) != 0)
    {
        if ((int)cv_61c3c8() - *(int*)(self + 0x1c5c) <= 0x7530)
        {
            int cfg = g_664520 != 0 ? *(int*)(g_664520 + 1404 * 4) : 0;
            if (cfg != 0)
                Hook_433ED0((void*)(size_t)cfg);
        }
        else
        {
            *(int*)(self + 0x1c58) = 0;
            int cfg = g_664520 != 0 ? *(int*)(g_664520 + 1404 * 4) : 0;
            if (cfg != 0 && *(int*)(cfg + 380) == 0)
                Hook_5F8F60(2032);
            ((S49F770*)ADDR(0x66ea48))->M_49F770(*(int*)ADDR(0x6504e8), 0);
            ((C_cluster_49F630*)ADDR(0x66ea48))->M_49F960(*(int*)ADDR(0x64d90c));
            if (*(int*)ADDR(0x664538) != 0)
            {
                if (((S49F620*)ADDR(0x66ea48))->Get_49F620() != 0)
                {
                    char* v3 = ((C_vt61DF78*)(void*)this)->C_vt61DF78::M_41C900((char*)(void*)this);
                    Hook_4A5D40((int)(size_t)v3, (char*)ADDR(0x7df), 0, 400, 190);
                }
                *(int*)ADDR(0x664538) = 0;
            }
        }
    }

    int result = ((C_vt61DF78*)(void*)this)->C_vt61DF78::M_420450();
    int v15 = result;
    if (result != 0)
    {
        if (*(int*)(self + 0x1c54) != 0)
            return 0;
        int v6 = *(int*)(self + 0x1d8);
        *(int*)(self + 0x1c54) = 1;
        if (v6 != 1 || *(int*)(self + 0x1460) == 0)
        {
            if (v6 == 3)
            {
                if (Hook_42F640(*(void**)(self + 0x1b0)) != 0)
                {
                    Hook_5B9DF0((void*)this);
                }
                else if ((int)cv_61c3c8() - *(int*)ADDR(0x75ff50) >= 0x1f4)
                {
                    char v17[2304];
                    ((C_vt61DF78*)(void*)this)->C_vt61DF78::slot09_41C920(
                        (char*)(size_t)1108, v17, 2304);
                    strcat(v17, (char*)ADDR(0x652d84));
                    do
                    {
                        void* sub = *(void**)(self + 0x1b0);
                        if (v2 != ((C_cluster_42A9F0*)sub)->Get_42D470()
                            && Hook_42D610(sub, v2) != 0)
                        {
                            strcat(v17, (char*)ADDR(0x652d84));
                            strcat(v17, Hook_425530(sub, v2));
                        }
                        ++v2;
                    } while (v2 < 9);
                    void* v7 = Hook_49F630(*(int*)ADDR(0x655084));
                    if (v7 != 0)
                        ((S4FFDE0*)v7)->M_4FFDE0((int)(size_t)v17);
                    *(int*)ADDR(0x75ff50) = (int)cv_61c3c8();
                }
            }
            else if ((v6 == 4 || v6 == 6 || v6 == 5)
                     && *(int*)ADDR(0x6645b4) == 0)
            {
                if (*(unsigned char*)ADDR(0x75ff35) != 0)
                {
                    *(unsigned char*)ADDR(0x75ff35) = 0;
                    int base = g_664520;
                    if (base != 0 && ((S42D490*)base)->M_42D490() != 0)
                    {
                        int v8 = *(int*)(self + 0x41c);
                        if (v8 != 0 && *(int*)(v8 + 504) == 0)
                        {
                            Hook_421E60();
                            int v9 = *(int*)(self + 0x41c);
                            if (*(short*)(v9 + 72) > 1)
                            {
                                do
                                {
                                    void* v10 = *(void**)(*(int*)(v9 + 76) + 4 * v2);
                                    if (((C_vt61CE24*)v10)->Get_48F970() != 0
                                        && *(int*)((char*)v10 + 1050 * 4) == 0)
                                    {
                                        if (*(int*)(*(int*)(self + 0x41c) + 504) == 0)
                                        {
                                            int i;
                                            for (i = 0; i < *(short*)(self + 0x88); ++i)
                                            {
                                                void* v12 = *(void**)(*(int*)(self + 0x8c) + 4 * i);
                                                if (v12 != 0 && Hook_520C40(v12) != 0)
                                                    Hook_520BA0(v12);
                                            }
                                            int v13 = *(int*)(self + 0x41c);
                                            int j;
                                            for (j = 0; j < *(short*)(v13 + 56); ++j)
                                            {
                                                if (*(void**)(*(int*)(v13 + 60) + 4 * j) != 0)
                                                    Hook_5200A0();
                                                v13 = *(int*)(self + 0x41c);
                                            }
                                            Hook_5C9A50((void*)(size_t)*(int*)(self + 0x41c));
                                        }
                                        Hook_Vt16(v10);
                                    }
                                    v9 = *(int*)(self + 0x41c);
                                    ++v2;
                                } while (v2 < *(short*)(v9 + 72));
                            }
                            if (*(int*)(*(int*)(self + 0x41c) + 504) != 0)
                                Hook_5C9DC0();
                        }
                    }
                }
                if (*(int*)(self + 0x149c) != 0)
                    Hook_4DB890();
            }
        }
        else
        {
            if ((int)cv_61c3c8() - *(int*)(self + 0x1470) >= 0x3e8)
            {
                char lParam[100];
                void* hwnd = *(void**)(self + 0x1460);
                Hook_SendMessageA(hwnd, 0x46a, 0x64, (int)(size_t)lParam);
                char* expect = (char*)GuestPtr(0x65d8bc);
                if (lParam[0] == 0 || strcmp(lParam, expect) == 0)
                {
                    Hook_5B4B10(1);
                }
                else if (*(int*)(self + 0x146c) == 0
                         && strcmp(lParam, (char*)GuestPtr(0x65dbc8)) == 0)
                {
                    Hook_SendMessageA(hwnd, 0x855, 0, 0);
                    *(int*)(self + 0x1470) = (int)cv_61c3c8();
                    goto idle_done;
                }
                *(int*)(self + 0x1470) = (int)cv_61c3c8();
            }
        }
    idle_done:
        result = v15;
        *(int*)(self + 0x1c54) = 0;
    }
    return result;
}

// 0x5B0EC0 — derived (vtable 0x62C1E0) constructor. Written as a real C++
// constructor so VC6 emits the EH frame: the base subobject (inline ctor ->
// 0x41B760, out-of-line non-trivial dtor) is "constructed" state 0. Member
// stores, the literal vtable store, the 0x5BAxxx/0x5BBxxx setters, the nine
// 0x75FExx globals, the +0x1AB8 loop (rep stosd), 0x421B90(4), 0x5BC460 and
// 0x5B17D0 when the flag is set. The base dtor here is an empty stand-in for
// the unwind path only (the original's ~TApp is not reconstructed).
class CvAppBase {
public:
    CvAppBase(void* parent, int flag) { ((C_vt62C1E0*)this)->M_41B760(parent, flag); }
    ~CvAppBase();
};
class CvApp_5B0EC0 : public CvAppBase {
public:
    CvApp_5B0EC0(void* parent, int flag);
};
CvAppBase::~CvAppBase() {}

MATCH_FUNC(0x5B0EC0)
CvApp_5B0EC0::CvApp_5B0EC0(void* parent, int flag) : CvAppBase(parent, 0)
{
    C_vt62C1E0* self = (C_vt62C1E0*)this;
    int i;
#ifdef MATCHED_NATIVE
    ++g_cvt_ctor5b_hits;
#endif
    CV_I32(0x1460) = 0;
    CV_I32(0x1464) = -1;
    CV_I32(0x1468) = 0;
    CV_I32(0x146c) = 0;
    CV_I32(0x1470) = 0;
    CV_I32(0x1474) = 0;
    CV_I32(0x1478) = 0;
    CV_I32(0x147c) = 0;
    CV_I32(0x1480) = 0;
    CV_I32(0x1484) = 0;
    CV_I32(0x1488) = 0;
    CV_I32(0x148c) = 0;
    CV_I32(0x1494) = 0;
    CV_I32(0x1498) = 0;
    CV_I32(0x149c) = 0;
    CV_I32(0x1c54) = 0;
    CV_I32(0x1c8c) = 0;
    CV_I32(0x1c90) = 0;
    *(unsigned int*)this = 0x62c1e0;
    g_64d4c0 = 1;
    CV_I32(0x200) = 1;
    CV_I32(0x204) = 0;
    CV_U8(0x1254) = 0;
    CV_I32(0x10a4) = 0;
    CV_U8(0x14a0) = 0;
    CV_U8(0x15a4) = 0;
    CV_U8(0x16a8) = 0;
    CV_U8(0x17b0) = 0;
    CV_U8(0x18b4) = 0;
    CV_I32(0x17ac) = 0;
    CV_U8(0x19b8) = 0;
    CV_U8(0x1358) = 0;
    g_75ff18 = 0;
    g_6645b0 = 0;
    g_6645b4 = 0;
    g_75ff35 = 0;
    g_75fddc = 0;
    g_75fdd8 = 0;
    g_75fdd4 = 0;
    g_75fdd0 = 0;
    CV_I32(0x1c58) = 0;
    CV_I32(0x11c0) = 0;
    CV_I32(0x11c4) = 0;
    CV_I32(0x11c8) = 0;
    CV_I32(0x11cc) = 0;
    CV_I32(0x11d4) = 2;
    self->M_5BAD80(1);
    self->M_5BAEC0(2);
    self->SetInt_5BAD60(0);
    self->M_5BAEE0((char*)ADDR(0x662be0));
    self->SetInt_5BAF20(1);
    self->SetInt_5BAF40(1);
    self->Set_5BAF70(1, 1);
    self->SetByte_5BB170(1);
    self->SetByte_5BB180(0);
    self->SetByte_5BB190(0);
    self->SetByte_5BB1A0(0);
    self->SetInt_5BB1B0(0);
    self->SetInt_5BB1C0(0);
    self->SetByte_5BB1D0(0);
    self->SetByte_5BB1E0(0);
    self->SetByte_5BB1F0(0);
    self->SetByte_5BB200(0x4b);
    self->SetByte_5BB210(0);
    self->SetInt_5BB220(-1);
    CV_I32(0x1458) = 0;
    CV_U8(0x145c) = 0;
    CV_U8(0x145d) = 0;
    for (i = 0; i < 9; i++)
    {
        self->SetByte_5BAFA0(i, 1);
        self->SetInt_5BAFD0(i, i);
        self->Set_5BB000(i, 1);
        self->SetByte2_5BB040(i, 0);
        self->M_5BB080(i, 0);
        g_75fe04[i] = 0;
        g_75fdf8[i] = 0;
        g_75fdec[i] = 0;
        g_75fde0[i] = 0;
    }
    for (i = 0; i < 9; i++)
        CV_I32(0x1ab8 + i * 4) = 0;
    ((S421Accessors*)this)->Set9B3_421B90(4);
    ((S5BC460*)this)->Clear_5BC460();
    if (flag != 0 && !self->M_5B17D0() && CV_I32(0x60) == 0)
        CV_I32(0x60) = 1;
#ifdef MATCHED_NATIVE
    // Host replica of the five vtable slots WinMain dispatches (see above).
    static void* s_vt62[87];
    static int s_vt62_ready;
    if (!s_vt62_ready)
    {
        int k;
        for (k = 0; k < 87; ++k)
            s_vt62[k] = (void*)vt62_trap;
        s_vt62[0] = (void*)vt62_slot00;
        s_vt62[1] = (void*)vt62_slot04;
        s_vt62[2] = (void*)vt62_slot50;
        s_vt62[6] = (void*)vt62_slot18;
        s_vt62[9] = (void*)vt62_slot24;
        s_vt62[10] = (void*)vt62_slot28;
        s_vt62[52] = (void*)vt62_slot52;
        s_vt62_ready = 1;
    }
    *(void**)this = s_vt62;
#endif
}

// Entry used by C_vt62C1E0::M_5B0EC0 (inline in the header; WinMain's
// TWinMainObj::Init_5B0EC0 forwards there): construct in place.
C_vt62C1E0* C_vt62C1E0::NewApp(void* parent, int flag)
{
    return (C_vt62C1E0*)(void*)new (this) CvApp_5B0EC0(parent, flag);
}

#ifdef _MSC_VER
#pragma function(memset, strcpy)
#endif

// 0x5B1EB0 (slot +0xA8) — the derived override of 0x41E5D0 (C_vt61DF78):
// seed +0x88 to 0x31, allocate the 0x31*4 sound table through 0x5F8FF0 at
// +0x8C, zero it, `new` the 49 0x20-byte sound entries (0x520720 init with
// the +0x80 sound system, the .wav name and the string id), then run 0x5207B0
// (0,-1,0) on the first three entries. The cached `arr` local in the last
// loop is what gives the original's [edi+eax] operand order. Natively
// unreachable: slot 42 of the host vtable replica (s_vt62 above) stays
// vt62_trap, and the 32-bit +0x8C table would truncate host pointers.
extern void* __cdecl sub_5F8FF0(unsigned int a1, int a2);
class C_cluster_520720 { public: C_cluster_520720* M_520720(int a1, int a2, int a3); };
class C_cluster_5207B0 { public: void M_5207B0(int a1, int a2, int a3); };
class T5B1EB0Sound {
public:
    char pad_00[0x20];             // 0x20 entry, initialized by 0x520720
    T5B1EB0Sound(int a1, const char* a2, int a3);
};
T5B1EB0Sound::T5B1EB0Sound(int a1, const char* a2, int a3)
{
    ((C_cluster_520720*)this)->M_520720(a1, (int)(size_t)a2, a3);
}

#define SND_5B1EB0(slot, name, id) \
    { T5B1EB0Sound* p = new T5B1EB0Sound(*(int*)((char*)this + 0x80), name, id); \
      ((int*)(size_t)field_8c)[slot] = (int)(size_t)p; }

MATCH_FUNC(0x5B1EB0)
int C_vt62C1E0::LoadSounds_5B1EB0()
{
    field_88 = 0x31;
    field_8c = (int)(size_t)sub_5F8FF0(0x31, 4);
    if (field_8c == 0)
        return 0;
    {
        int i = 0;
        for (; i < field_88; i++)
            ((int*)(size_t)field_8c)[i] = 0;
    }
    SND_5B1EB0(0, "button1.wav", 0xc47c);
    SND_5B1EB0(1, "button2.wav", 0xc47d);
    SND_5B1EB0(28, "button3.wav", 0xc49b);
    SND_5B1EB0(29, "button4.wav", 0xc49c);
    SND_5B1EB0(30, "button5.wav", 0xc49d);
    SND_5B1EB0(31, "button6.wav", 0xc49e);
    SND_5B1EB0(32, "button7.wav", 0xc49f);
    SND_5B1EB0(33, "button8.wav", 0xc4a0);
    SND_5B1EB0(34, "button9.wav", 0xc4a1);
    SND_5B1EB0(35, "rollover.wav", 0xc4a2);
    SND_5B1EB0(2, "chatrcvd.wav", 0xc47e);
    SND_5B1EB0(3, "cantdo.wav", 0xc47f);
    SND_5B1EB0(4, "tribute.wav", 0xc480);
    SND_5B1EB0(5, "resdone.wav", 0xc481);
    SND_5B1EB0(6, "pkilled.wav", 0xc482);
    SND_5B1EB0(7, "pdropped.wav", 0xc483);
    SND_5B1EB0(8, "mstart.wav", 0xc484);
    SND_5B1EB0(9, "mdone.wav", 0xc485);
    SND_5B1EB0(10, "mkilled.wav", 0xc486);
    SND_5B1EB0(11, "artheld.wav", 0xc487);
    SND_5B1EB0(12, "artlost.wav", 0xc488);
    SND_5B1EB0(13, "convwarn.wav", 0xc489);
    SND_5B1EB0(14, "convdone.wav", 0xc48a);
    SND_5B1EB0(15, "atakwarn.wav", 0xc48b);
    SND_5B1EB0(16, "enemwarn.wav", 0xc48c);
    SND_5B1EB0(17, "flare.wav", 0xc48d);
    SND_5B1EB0(18, "needres.wav", 0xc48e);
    SND_5B1EB0(19, "housing.wav", 0xc492);
    SND_5B1EB0(20, "loosebld.wav", 0xc493);
    SND_5B1EB0(21, "takebld.wav", 0xc494);
    SND_5B1EB0(22, "archupg.wav", 0xc495);
    SND_5B1EB0(23, "fortupg.wav", 0xc496);
    SND_5B1EB0(24, "flaresnd.wav", 0xc497);
    SND_5B1EB0(25, "farmdied.wav", 0xc498);
    SND_5B1EB0(26, "gather.wav", 0xc499);
    SND_5B1EB0(27, "resdone2.wav", 0xc49a);
    SND_5B1EB0(36, "needhous.wav", 0xc4b2);
    SND_5B1EB0(37, "capsheep.wav", 0xc4b3);
    SND_5B1EB0(38, "capgaia.wav", 0xc4b4);
    SND_5B1EB0(39, "townbell.wav", 0xc4b5);
    SND_5B1EB0(40, "townrcal.wav", 0xc4b6);
    SND_5B1EB0(41, "buy.wav", 0xc4b8);
    SND_5B1EB0(42, "sell.wav", 0xc4b9);
    SND_5B1EB0(43, "gatel.wav", 0xc4ba);
    SND_5B1EB0(44, "gateu.wav", 0xc4bb);
    SND_5B1EB0(45, "objctive.wav", 0xc4bc);
    SND_5B1EB0(46, "puprelic.wav", 0xc4bd);
    SND_5B1EB0(47, "wolfwarn.wav", 0xc4be);
    SND_5B1EB0(48, "spies.wav", 0xc4bf);
    for (int i = 0; i < 3; i++)
    {
        C_cluster_5207B0** arr = (C_cluster_5207B0**)(size_t)field_8c;
        if (arr[i] != 0)
            arr[i]->M_5207B0(0, -1, 0);
    }
    return 1;
}
#undef SND_5B1EB0

// 0x5B4B10 — end-of-video / next-screen dispatcher. Closes the MCI window at
// +0x1460 (MCIWNDM_GETMODE 0x46A; MCI_STOP 0x808 unless "stopped"; WM_CLOSE),
// repaints, then either (game-start pending, 0x5B4540) tears down the 0x75FF3C
// object and picks the next screen, or switches on the finished video id taken
// from +0x1464 (reset to -1): 0 eslogo -> 1, 1 age2 -> 10, 3/4/6/8/9 open the
// mission / achievements / aftermath / game-mission / campaign screens.
// SendMessageA/InvalidateRect are real dllimports (VC6 caches the SendMessageA
// IAT slot in ebp). Case 3's failure path must `break` (not return) so VC6
// keeps the early 0x5B9430 copy; case 6 duplicates the panel call per branch
// so the two `new` sites share the test+ctor tail.
// Guest-only (Win32 IAT, guest globals/screens): the native build keeps the
// weak no-op stub for Hook_5B4B10 from Scripts/matched_stubs.cpp.
#ifndef MATCHED_NATIVE
extern "C" __declspec(dllimport) int __stdcall SendMessageA(void* hwnd, unsigned msg, int wp, int lp);
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void* hwnd, const void* rc, int erase);
class T5B4B10View { public: void M_45E8F0(); void M_45F5C0(int a1); };   // [this+0x68]
class T5B4B10Obj { public: virtual ~T5B4B10Obj(); };                     // *0x75FF3C
extern T5B4B10Obj* g_75ff3c;
extern int g_75ff40;
class T5B4B10Player { public: char pad_00[0xa2]; unsigned char field_a2; };
class T5B4B10Scen {                                                       // [+0x41C]+0x6C
public:
    char pad_00[0x19f0];
    int field_19f0;                // +0x19F0
    char* M_4CE690();
    char* M_4CFA00(int a1);
};
class T5B4B10World { public: char pad_00[0x6c]; T5B4B10Scen* field_6c; };
class T4CFC10 { public: char pad_00[0xc9c]; T4CFC10(int a1); void M_4D3970(); };
class T51E060 { public: char pad_00[0x808]; T51E060(char* a1, int a2, int a3); };
class T4D3C60 { public: char pad_00[0x7f4]; T4D3C60(); };
class T4E91A0 { public: char pad_00[0x978]; T4E91A0(int a1, int a2, int a3, int a4); };
class S5B4B10Self {                                                       // 0x62C1E0 methods
public:
    void M_422420();
    int Get_5B4540();
    unsigned char Get_5B4560();
    unsigned char Get_5B4580();
    unsigned char Get_5BCA00();
    void M_5B4590(int a1, char* a2);
    void M_5B9430();
    void M_421F40();
    void M_5B1560(int a1);
    int M_5BC350(int a1);
    void M_5B5360();
    void M_5BC7C0();
    int M_5B50D0(int a1);
    T5B4B10Player* M_41F840();
};
#define SELF_5B4B10 ((S5B4B10Self*)this)
#define PANELS_5B4B10 ((S49F770*)ADDR(0x66ea48))

MATCH_FUNC(0x5B4B10)
void C_vt62C1E0::Hook_5B4B10(int a1)
{
    char buf[100];
    int prev = CV_I32(0x1464);
    CV_I32(0x1464) = -1;
    if (field_1460 != 0)
    {
        SendMessageA(field_1460, 0x46a, 100, (int)buf);
        if (buf[0] != 0 && strcmp(buf, "stopped") != 0)
            SendMessageA(field_1460, 0x808, 0, 0);
        SendMessageA(field_1460, 0x10, 0, 0);
        field_1460 = 0;
        (*(T5B4B10View**)((char*)this + 0x68))->M_45E8F0();
        (*(T5B4B10View**)((char*)this + 0x68))->M_45F5C0(CV_I32(0x34));
        SELF_5B4B10->M_422420();
        InvalidateRect(field_28, 0, 1);
        SendMessageA(field_28, 0xf, 0, 0);
        (*(T5B4B10View**)((char*)this + 0x68))->M_45E8F0();
    }
    if (SELF_5B4B10->Get_5B4540() != 0)
    {
        if (g_75ff3c != 0)
        {
            PANELS_5B4B10->M_49F770((int)"Blank Screen", 0);
            delete g_75ff3c;
            g_75ff3c = 0;
        }
        if (SELF_5B4B10->Get_5B4560() == 8 && SELF_5B4B10->Get_5B4580() == 1 && g_75ff40 == 0)
        {
            g_75ff40 = 1;
            SELF_5B4B10->M_5B4590(3, (char*)ADDR(0x662be0));
            return;
        }
        if (SELF_5B4B10->Get_5BCA00() == 4)
        {
            if (field_41c != 0 && SELF_5B4B10->Get_5B4560() != 8)
            {
                PANELS_5B4B10->M_49F770((int)"Blank Screen", 0);
                SELF_5B4B10->M_421F40();
                SELF_5B4B10->M_5B1560(0);
                if (new T4CFC10(SELF_5B4B10->M_5BC350(2)) == 0)
                {
                    SELF_5B4B10->M_5B5360();
                    return;
                }
                PANELS_5B4B10->M_49F770((int)"Achievements Screen", 0);
                return;
            }
            SELF_5B4B10->M_5B5360();
            return;
        }
        SELF_5B4B10->M_5B9430();
        return;
    }
    switch (prev)
    {
    case 0:
        if ((char)a1)
        {
            SELF_5B4B10->M_5B4590(1, "eslogo");
            return;
        }
        if (SELF_5B4B10->M_5B50D0(0) == 0)
        {
            ((S41F5F0*)this)->M_41F5F0();
            return;
        }
        break;
    case 1:
        if ((char)a1)
        {
            SELF_5B4B10->M_5B4590(10, "age2");
            return;
        }
        if (SELF_5B4B10->M_5B50D0(0) == 0)
        {
            ((S41F5F0*)this)->M_41F5F0();
            return;
        }
        break;
    case 10:
        if (CV_I32(0x1474) != 0)
            SELF_5B4B10->M_5BC7C0();
    case 2:
    case 5:
        if (SELF_5B4B10->M_5B50D0(0) == 0)
        {
            ((S41F5F0*)this)->M_41F5F0();
            return;
        }
        break;
    case 3:
    {
        if (CV_I32(0x1474) != 0)
            SELF_5B4B10->M_5BC7C0();
        T5B4B10Scen* scen = ((T5B4B10World*)field_41c)->field_6c;
        char* name = scen->M_4CE690();
        if (name == 0 || *name == 0 || Get9AA_4217C0() != 0 || Get928_421760() == 0)
        {
            SELF_5B4B10->M_5B9430();
            break;
        }
        new T51E060(name, 0, ((T5B4B10World*)field_41c)->field_6c->field_19f0);
        PANELS_5B4B10->M_49F770((int)"Mission Dialog", 0);
        break;
    }
    case 4:
    {
        if (CV_I32(0x1474) != 0)
            SELF_5B4B10->M_5BC7C0();
        if (field_41c == 0)
            break;
        PANELS_5B4B10->M_49F770((int)"Blank Screen", 0);
        SELF_5B4B10->M_421F40();
        SELF_5B4B10->M_5B1560(0);
        T4CFC10* scr = new T4CFC10(SELF_5B4B10->M_5BC350(2));
        if (scr == 0)
        {
            SELF_5B4B10->M_5B5360();
            return;
        }
        if (SELF_5B4B10->Get_5B4540() == 0 && Get928_421760() != 0)
        {
            char* n;
            if (SELF_5B4B10->M_41F840()->field_a2 == 1)
                n = ((T5B4B10World*)field_41c)->field_6c->M_4CFA00(2);
            else
                n = ((T5B4B10World*)field_41c)->field_6c->M_4CFA00(3);
            if (n != 0 && *n != 0 && new T4D3C60() != 0)
            {
                PANELS_5B4B10->M_49F770((int)"Aftermath Screen", 0);
                scr->M_4D3970();
                return;
            }
        }
        PANELS_5B4B10->M_49F770((int)"Achievements Screen", 0);
        break;
    }
    case 6:
        if (CV_I32(0x1474) != 0)
            SELF_5B4B10->M_5BC7C0();
        if (field_41c != 0)
        {
            new T4E91A0(0, 0, 0, 0);
            PANELS_5B4B10->M_49F770((int)"Game Mission Dialog", 0);
        }
        else
        {
            new T4E91A0(0, 0, 0, 0);
            PANELS_5B4B10->M_49F770((int)"Game Mission Dialog", 0);
        }
        break;
    case 8:
    case 9:
        if (CV_I32(0x1474) != 0)
            SELF_5B4B10->M_5BC7C0();
        PANELS_5B4B10->M_49F770((int)"Campaign Game Screen", 0);
        break;
    }
}
#undef SELF_5B4B10
#undef PANELS_5B4B10
#endif // !MATCHED_NATIVE
