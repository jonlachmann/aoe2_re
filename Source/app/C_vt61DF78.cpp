#include "C_vt61DF78.hpp"
#include "matched_mem.h"
#ifdef MATCHED_NATIVE
extern "C" int g_cvt_slot36_hits = 0;
extern "C" int g_cvt_slot37_hits = 0;
extern "C" int g_cvt_slot04_hits = 0;
extern "C" int g_cvt_41bc80_hits = 0;
#endif

// Side globals are compiled in both the VC6 match TU and the native host TU so
// the WIP bodies can use the full host pointers the 32-bit guest fields cannot
// carry. They are read-only declarations for the VC6 object; the native link
// resolves them to this file's definition.
extern "C" { extern void* cv_config_ptr; }   // native config object from +0x24
extern "C" void* cv_regctx = 0;        // native registry context from +0x1d4
extern "C" int* cv_e4a0_arr = 0;       // native full array pointer for +0x7C
extern "C" int* cv_e5d0_arr = 0;       // native full array pointer for +0x8C
extern "C" int cv_win_class = 0;     // 0x41D5D0/0x41D6A0 proof counters
extern "C" int cv_win_handle = 0;
extern "C" int cv_de50_hits = 0;
extern "C" int cv_e070_hits = 0;
// Menu-screen population proof: full host pointers kept aside because the guest
// dword fields at +0x15F8/+0x15FC/+0x15E8/+0x1604/+0x1610/+0x80/+0x90 are not all
// 8-aligned and cannot carry a 64-bit host pointer.
extern "C" void* cv_s47_screen = 0;    // the populated 0x47C4 main-menu screen
extern "C" void* cv_s47_15e8 = 0;      // 0x7D0 C_cluster_437740 subobject
extern "C" void* cv_s47_15f8 = 0;      // 0x1168 S438120 subobject
extern "C" void* cv_s47_15fc = 0;      // 0x7F4 Sc439CB0 subobject
extern "C" void* cv_s47_1604 = 0;      // 0x8 S424BC0 subobject
extern "C" void* cv_s47_1610 = 0;      // 0x54C S423A70 subobject
extern "C" void* cv_s47_80 = 0;        // 0x7B0 game/options screen
extern "C" void* cv_s47_90 = 0;        // 0x5C0 options sub-screen
// Matched-UI entry counters (incremented inside the byte-exact bodies under
// MATCHED_NATIVE only, so the VC6 gate never sees them).
extern "C" int cv_ui_425650 = 0;
extern "C" int cv_ui_425680 = 0;
extern "C" int cv_ui_4256a0 = 0;
extern "C" int cv_ui_5200f0 = 0;
extern "C" int cv_ui_520410 = 0;
extern "C" int cv_ui_520cc0 = 0;
extern "C" int cv_ui_520dd0 = 0;
extern "C" int cv_ui_520e10 = 0;
extern "C" int cv_ui_520e50 = 0;
extern "C" int cv_ui_520e90 = 0;
extern "C" int cv_ui_520f50 = 0;
extern "C" int cv_ui_520ed0 = 0;
extern "C" int cv_ui_521090 = 0;
// Nonzero-field population counts computed after construction.
extern "C" int cv_screen47_pop = 0;
extern "C" int cv_screen7b0_pop = 0;
extern "C" int cv_screen5c0_pop = 0;
extern "C" int cv_e070_preset_entries = 0;
extern "C" int cv_cfg_sound = 0;

// Constructors/methods the menu-screen bodies call (mangled owner symbols).
class S47C4Screen {
public:
    int M_425750(int hwnd, int cfg, int obj664524,
                 int b0, int b1, int b2, int b3);
};
class C_cluster_437740 {
public:
    C_cluster_437740* Init_437100(int a1);
};
class S438120 {
public:
    S438120* Init_438120(int a1);
};
class Sc439CB0 {
public:
    Sc439CB0* Init_439CB0(int a1);
};
class S423A70 {
public:
    S423A70* Init_423A70();
};
class S424BC0 {
public:
    S424BC0* Init_424BC0(int v);
};
class S42D1D0 {
public:
    void M_42AE00();
    void M_42D1D0();
};
class C_cluster_42AEE0 {
public:
    void M_42AE50();
};
class C_global_66451C {
public:
    void Init_42FD60();
    void Init_42FD20();
    void Hook_4308C0();
    void M_427120();              // lifted callee at 0x427120
};
class Sc425650 {
public:
    void M_425650(int a1);
};
class S425680 {
public:
    void M_425680(int a1);
};
class S4256A0 {
public:
    void M_4256A0(int a1);
};
class C_vt61CE24 {
public:
    void M_408650(int unused);
};
class C_cluster_5200F0 {
public:
    C_cluster_5200F0* M_5200F0(int a1, int a2);
};
class S520400 {
public:
    int Get_520400();
};
class S520410 {
public:
    void M_520410(int a1, int a2);
};
class S520CC0 {
public:
    S520CC0* Init_520CC0(int a1, int a2);
};
class S52SetBulk {
public:
    void CopyName_520DD0(char* a1);
    void CopyName_520E10(char* a1);
    void CopyName_520E50(char* a1);
    void CopyName_520E90(char* a1);
    void CopyName_520ED0(char* a1);
    void SetInt_520F50(int v);
};
class T4EE210Obj {
public:
    int M_521090(int a1, int a2, int a3, int a4);
};
class S4BE010 {
public:
    void* M_4BE010(int a1, int a2);
};
extern void __cdecl sub_520120();
extern int __cdecl sub_5E4610(int a1);
extern int __cdecl sub_42FD00(int a1);

extern void* __cdecl sub_5F8F60(int a1);
extern void __cdecl sub_5F90B0(void* p);
extern "C" int Native_GetSystemMetrics(int index);
extern "C" int Native_CreateWindow(int clsId);
extern "C" int Native_RegisterClass(void* wc);
extern "C" int Native_LoadIcon(int inst, char* name);
extern "C" int Native_SystemParameters(int action, int p0, void* p1, int p2);
extern "C" int Native_ShowWindow(int hwnd, int cmd);
extern "C" int Native_UpdateWindow(int hwnd);
extern "C" int Native_SetFocus(int hwnd);
extern "C" int Native_SetTimer(int hwnd, int id, int ms, void* proc);
extern "C" int Native_GlobalMemoryStatus(void* mem);
int __cdecl sub_41F8B0();        // matched display helper


class S4BE080 {
public:
    int M_4BE080(int a1, int a2);
};
class S4BDF50 {
public:
    int M_4BDF50(int a1, int a2, int a3);
};
extern int __cdecl sub_465270();
extern int __cdecl sub_5FCA3B(unsigned int a1);
extern char g_61c3c8[0x1000];    // timeGetTime
extern int g_664510;
extern int g_664514;
extern int g_664518;
extern int g_664520;
extern int g_664528;
extern int g_65E3C0;

class S462B50 {
public:
    S462B50* M_462B50();
};

extern void __cdecl sub_5FCB40(char* dst, char* src, int n);
extern int (__stdcall *g_61C2D8)(char* a1);
extern char g_61c2dc[0x1000];   // DispatchMessageA
extern char g_61c2e0[0x1000];   // TranslateMessage
extern char g_61c2e4[0x1000];   // GetMessageA
extern char g_61c2e8[0x1000];   // PeekMessageA
extern unsigned char g_664544;
extern int g_6645c8;
extern char* __cdecl sub_5FD7C3(char* a1, char* a2);
extern char* __cdecl sub_5FD7A5(char* a1, int a2);
extern int __cdecl sub_5FD716(unsigned int a1);   // _ismbcspace-like: 0x41DC80 zero-extends the byte (xor/mov cl)
extern char* __cdecl sub_5FD66E(char* a1, char* a2, int a3);

// Subobject at 0x110 built by 0x4BDE90 (handles +0x00/+0x04/+0x08/+0x0C).
class S4BDE90 {
public:
    S4BDE90* M_4BDE90(int a1);
};

extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void* hwnd, char* text);
extern unsigned char g_6642f0;
extern int g_664510;
extern "C" int __stdcall Hook_473AE0(int a1, int a2, char* a3, int a4);   // unresolved callee at 0x473AE0

// Global object at 0x66EA48 is constructed by 0x49FB60 (664 bytes).
class T49FB60 {
public:
    int Hook_49FB60(void* a1, int a2, int a3);   // unresolved callee at 0x49FB60
};

MATCH_FUNC(0x41C920)
char* C_vt61DF78::slot09_41C920(char* a1, char* buf, int len)
{
    if (!Hook_473AE0(g_664510, (int)a1, buf, len))
        buf[0] = 0;
    buf[len - 1] = 0;
    return buf;
}

MATCH_FUNC(0x41DA70)
int C_vt61DF78::slot34_41DA70()
{
    T49FB60* build = (T49FB60*)0x66ea48;
    int r = build->Hook_49FB60((void*)(field_24 + 0x66e), 0xc544, 1);
    field_34 = r;
    return r != 0;
}

MATCH_FUNC(0x41BC00)
void C_vt61DF78::SetInt_41BC00(int v)
{
    *(int*)((char*)this + 0x1d8) = v;
}

MATCH_FUNC(0x41BC10)
void C_vt61DF78::M_41BC10(int a, int b, int c, int d, int e)
{
    (void)a; (void)b; (void)c; (void)d; (void)e;
}

MATCH_FUNC(0x41BC20)
int C_vt61DF78::M_41BC20()
{
    return 1;
}

MATCH_FUNC(0x41BC30)
int C_vt61DF78::M_41BC30(int a, int b, int c, int d, int e, int f)
{
    (void)a; (void)b; (void)c; (void)d; (void)e; (void)f;
    return 1;
}

MATCH_FUNC(0x41BC40)
int C_vt61DF78::M_41BC40(int a, int b, int c, int d, int e)
{
    (void)a; (void)b; (void)c; (void)d; (void)e;
    return 1;
}

MATCH_FUNC(0x41BC50)
int C_vt61DF78::M_41BC50(int a, int b)
{
    (void)a; (void)b;
    return 1;
}


class T49F620Result {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
    virtual void Vt_09();
    virtual void Vt_0A();
    virtual void Vt_0B();
    virtual void Vt_0C();
    virtual void Vt_0D();
    virtual void Vt_0E();
    virtual void Vt_0F();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14(int a, int b);
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_1A();
    virtual void Vt_1B();
    virtual void Vt_1C();
    virtual void Vt_1D();
    virtual void Vt_1E();
    virtual void Vt_1F();
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
    virtual void Vt_2A();
    virtual void Vt_2B();
    virtual void Vt_2C();
    virtual void Vt_2D();
    virtual void Vt_2E();
    virtual void Vt_2F();
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
    virtual void Vt_3A();
    virtual void Vt_EC();
};

class S49F620Global {
public:
    char pad_00[0x10];
    T49F620Result* Get_49F620();
};

MATCH_FUNC(0x420BE0)
int C_vt61DF78::M_420BE0(int a1, int a2, int a3, int a4)
{
    (void)a1; (void)a2; (void)a4;
    if (a3)
        field_30 = 1;
    else
        field_30 = 0;
    if (field_30 != 0)
    {
        int cur = *(int*)((char*)this + 0x1d8);
        if ((cur == 4 || cur == 6 || cur == 7)
            && *(int*)((char*)this + 0xb38) == 1)
        {
            *(int*)((char*)this + 0xb38) = 0;
            Hook_41F730(0, 0);
        }
        if (((S49F620Global*)ADDR(0x66ea48))->Get_49F620() != 0)
        {
            ((T49F620Result*)((S49F620Global*)ADDR(0x66ea48))->Get_49F620())->Vt_EC();
        }
        slot_074();
        return 1;
    }
    else
    {
        int cur = *(int*)((char*)this + 0x1d8);
        if (cur == 4 || cur == 6 || cur == 7)
        {
            if (Hook_4217B0() == 1 && *(unsigned char*)ADDR(0x664544) == 0)
            {
                int r = Hook_41F660(1);
                if (r == 0)
                {
                    *(int*)((char*)this + 0xb38) = 1;
                    Hook_41F730(1, r);
                }
            }
        }
        slot_075();
        return 1;
    }
}

MATCH_FUNC(0x41C8F0)
int C_vt61DF78::Get_41C8F0()
{
    return *(int*)((char*)this + 0x60);
}

MATCH_FUNC(0x41EB30)
void C_vt61DF78::Init_41EB30()
{
    int one = 1;
    *(int*)((char*)this + 0x580) = one;
    *(int*)((char*)this + 0x5a0) = one;
    *(int*)((char*)this + 0x5c0) = one;
    *(int*)((char*)this + 0x6a0) = one;
    *(int*)((char*)this + 0x700) = one;
    *(int*)((char*)this + 0x564) = one;
    *(int*)((char*)this + 0x5e4) = one;
}

MATCH_FUNC(0x41F610)
void C_vt61DF78::Set_41F610(int a, int b)
{
    field_1DC = a;
    field_1E0 = b;
}

MATCH_FUNC(0x4208D0)
bool C_vt61DF78::M_4208D0(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    return Vat_124();
}

MATCH_FUNC(0x420CD0)
bool C_vt61DF78::M_420CD0(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    return Vat_130();
}

MATCH_FUNC(0x420CF0)
bool C_vt61DF78::M_420CF0(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    return Vat_134();
}

MATCH_FUNC(0x4213B0)
void C_vt61DF78::SetText_4213B0()
{
    SetWindowTextA(field_28, text_430);
}

MATCH_FUNC(0x4213D0)
void C_vt61DF78::Wrap_4213D0()
{
    if (field_1B0)
        ((T42FAE0*)field_1B0)->M_42FAE0(buf_924, 0xb0);
}

MATCH_FUNC(0x421A40)
char* C_vt61DF78::ClearGlobal_421A40()
{
    g_6642f0 = 0;
    return (char*)&g_6642f0;
}

MATCH_FUNC(0x5E2CC0)
void C_vt61DF78::M_5E2CC0(int a, int b)
{
    (void)a; (void)b;
}

MATCH_FUNC(0x4208B0)
bool C_vt61DF78::M_4208B0(int a, int b, int c, int d)
{
    (void)a; (void)b;
    return slot_072(c, d) != 0;
}

MATCH_FUNC(0x41C900)
char* C_vt61DF78::M_41C900(char* a)
{
    slot09_41C920(a, (char*)0x664308, 0x200);
    return (char*)0x664308;
}

MATCH_FUNC(0x41C950)
void C_vt61DF78::M_41C950(int a, int b, int c, int d)
{
    slot_010(a, b, 0, c, d);
}

// 0x41DC10 — allocate the 0x110 context object with `new` (the CRT operator
// new at 0x5F8F60, operator delete at 0x5F90B0) and construct it from the
// config's +0x418 path; VC6 emits the EH frame because the constructor can
// throw and the unwind funclet frees the allocation. The built pointer goes to
// +0x1D4 and the function returns whether construction produced one.
class T41DC10Obj {
public:
    char pad_00[0x110];
    T41DC10Obj(int a1);
};

#ifdef MATCHED_NATIVE
void* __cdecl operator new(size_t n)
#else
void* __cdecl operator new(unsigned int n)
#endif
{
    return sub_5F8F60((int)n);
}
void __cdecl operator delete(void* p)
{
    sub_5F90B0(p);
}
T41DC10Obj::T41DC10Obj(int a1)
{
    ((S4BDE90*)this)->M_4BDE90(a1);
}

MATCH_FUNC(0x41DC10)
int C_vt61DF78::slot36_41DC10()
{
#ifdef MATCHED_NATIVE
    ++g_cvt_slot36_hits;
#endif
#ifdef MATCHED_NATIVE
    T41DC10Obj* p = new T41DC10Obj((int)(size_t)cv_config_ptr + 0x418);
#else
    T41DC10Obj* p = new T41DC10Obj(*(int*)((char*)this + 0x24) + 0x418);
#endif
    *(int*)((char*)this + 0x1d4) = (int)(size_t)p;
#ifdef MATCHED_NATIVE
    cv_regctx = p;
#endif
    return p != 0;
}
// 0x41DC80 — parse LOGDIR:/LOGNAME: out of the module path and build the
// 0xCEC logging/device object from the config's +0x518 path. The body keeps a
// 0x100 path buffer, uses 0x5FCB40 (bounded copy), 0x5FD7C3 (substring search)
// and the 0x5FD7A5/0x5FD716/0x5FD66E character walk into 0x651164/0x66955C, and
// finally constructs the 0x440A90 object at +0x1C8 (with +0x1D0 and 0x664540
// passed to its setters).
// Shared with Source/gfx/free_gfx.cpp: the 0xCEC object's constructor body is
// modelled there as M_440A90 (0x440A90) and its setters M_440B40/M_440B80/
// M_440BC0 are byte-verified members of the same class.
class S440B40 {
public:
    char pad_00[0xcec];
    S440B40();
    S440B40* M_440A90();
    void M_440B40(int a1);
    void M_440B80(int a1);
    void M_440BC0(int a1);
};
S440B40::S440B40()
{
    M_440A90();
}
extern int g_664540;

// MATCH: the loops are plain `while (!sub_5FD716((unsigned char)*s) && *s)`
// with 0x5FD716 taking an unsigned int (the byte is zero-extended with
// xor/mov cl), CharUpperA is a real dllimport, the source path is field_24 and
// the S440B40 ctor stays defined in this TU (inlined `new`; with an
// out-of-TU ctor VC6 duplicates the epilogue into the `return 0` path).
#ifndef MATCHED_NATIVE
extern "C" __declspec(dllimport) char* __stdcall CharUpperA(char* s);
#endif
MATCH_FUNC(0x41DC80)
int C_vt61DF78::slot37_41DC80()
{
#ifdef MATCHED_NATIVE
    ++g_cvt_slot37_hits;
#endif
    char buf[0x100];
    char* p;
    char* s;
#ifdef MATCHED_NATIVE
    sub_5FCB40(buf, (char*)(cv_config_ptr != 0 ? cv_config_ptr : 0) + 0x518, 0xff);
    buf[0xff] = 0;
    g_61C2D8(buf);
#else
    sub_5FCB40(buf, (char*)field_24 + 0x518, 0xff);
    buf[0xff] = 0;
    CharUpperA(buf);
#endif

    p = sub_5FD7C3(buf, (char*)ADDR(0x64d834));
    if (p != 0)
    {
        while (*p != ':')
            p = sub_5FD7A5(p, 1);
        s = sub_5FD7A5(p, 1);
        *(char*)ADDR(0x651164) = 0;
        while (!sub_5FD716((unsigned char)*s) && *s != 0)
        {
            sub_5FD66E((char*)ADDR(0x651164), s, 1);
            s = sub_5FD7A5(s, 1);
        }
    }

    p = sub_5FD7C3(buf, (char*)ADDR(0x64d828));
    if (p != 0)
    {
        while (*p != ':')
            p = sub_5FD7A5(p, 1);
        s = sub_5FD7A5(p, 1);
        *(char*)ADDR(0x66955c) = 0;
        while (!sub_5FD716((unsigned char)*s) && *s != 0)
        {
            sub_5FD66E((char*)ADDR(0x66955c), s, 1);
            s = sub_5FD7A5(s, 1);
        }
    }

    S440B40* obj = new S440B40();
    *(int*)((char*)this + 0x1c8) = (int)(size_t)obj;
    if (obj == 0)
        return 0;
#ifdef MATCHED_NATIVE
    obj->M_440B40(*(int*)((char*)this + 0x1d0));
    obj->M_440B80(g_664540);
    obj->M_440BC0(1);
#else
    obj->M_440B40(*(int*)((char*)this + 0x1d0));
    (*(S440B40**)((char*)this + 0x1c8))->M_440B80(g_664540);
    (*(S440B40**)((char*)this + 0x1c8))->M_440BC0(1);
#endif
    return 1;
}

// 0x41CF70 (slot +0x04) — the window/menu message pump. The original keeps a
// 7-dword MSG block, loops while the 0x664544 quit byte is clear, calls
// GetMessageA(hwnd 0) for the game screens when the +0x30/+0x1d8/+0x1b0 gate
// is active, and otherwise PeekMessageA(...,PM_REMOVE). Each message goes to
// TranslateMessageA + DispatchMessageA; idle path drives the +0xD0 slot, the
// message path the +0xCC slot, and WM_QUIT clears the 0x6645C8 latch. It
// returns the MSG wParam left in the block.
// Native/guest behaviour for the +0x1B0 subobject's aliveness probe.
int T41B0::M_42D210()
{
    return 1;
}

// 0x41CF70 (slot +0x04) — the menu message pump. The original reads the
// 0x61C2DC/0x61C2E0 dispatch/translate slots into ebp/edi, keeps a seven-dword
// message block in the local frame, handles the 0x664544 hold byte and the
// +0x1D8 mode 4/2 special path, then alternates GetMessage / PeekMessage. The
// guest-exact VC6 branch uses the absolute guest IAT addresses so the
// compiler emits the same absolute memory operands; the native branch reads the
// host-installed trampoline arrays.
// 0x41CF70 (slot +0x04) — the menu message pump. The original reads the
// 0x61C2DC/0x61C2E0 dispatch/translate slots into ebp/edi, keeps a seven-dword
// message block in the local frame, handles the 0x664544 hold byte and the
// +0x1D8 mode 4/2 special path, then alternates GetMessage / PeekMessage. The
// guest-exact VC6 branch uses the absolute guest IAT addresses so the compiler
// emits the same absolute memory operands; the native branch reads the
// host-installed trampoline arrays.
// MATCH (VC6 branch): real user32 dllimports (VC6 caches Translate/Dispatch in
// edi/ebp), a typed 7-field MSG, and one natural if / else-if / else loop.
// NOTE: in a standalone one-function scratch TU this exact body cross-jumps the
// two Translate/Dispatch tails (240 vs 243 bytes); it only matches in this TU
// (presumably the in-TU T41B0::M_42D210 body / TU context), so keep it here.
#ifndef MATCHED_NATIVE
struct TMsg41CF70 {
    void* hwnd;
    unsigned message;
    int wParam;
    int lParam;
    unsigned time;
    int ptx;
    int pty;
};
extern "C" __declspec(dllimport) int __stdcall GetMessageA(TMsg41CF70* msg, void* hwnd, unsigned lo, unsigned hi);
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(TMsg41CF70* msg, void* hwnd, unsigned lo, unsigned hi, unsigned remove);
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(TMsg41CF70* msg);
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(TMsg41CF70* msg);
#endif
MATCH_FUNC(0x41CF70)
int C_vt61DF78::slot01_41CF70()
{
#ifndef MATCHED_NATIVE
    TMsg41CF70 msg;
    msg.hwnd = 0; msg.message = 0; msg.wParam = 0; msg.lParam = 0;
    msg.time = 0; msg.ptx = 0; msg.pty = 0;
    while (1)
    {
        if (g_664544 == 0
            && (field_30 == 0
                || (field_1D8 != 4 && field_1D8 != 2)
                || (field_1B0 != 0 && ((T41B0*)field_1B0)->M_42D210() != 0)))
        {
            if (!GetMessageA(&msg, 0, 0, 0))
                return msg.wParam;
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        else if (PeekMessageA(&msg, 0, 0, 0, 1))
        {
            if (msg.message == 0x12)
            {
                if (g_6645c8 == 0)
                    return msg.wParam;
                g_6645c8 = 0;
            }
            if (slot_051(&msg))
            {
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            }
        }
        else
            slot_052();
    }
#else
    ++g_cvt_slot04_hits;
    int (__stdcall *translate)(void*) =
        *(int (__stdcall**)(void*))g_61c2e0;
    int (__stdcall *dispatch)(void*) =
        *(int (__stdcall**)(void*))g_61c2dc;
    int zero = 0;
    int msg[7];
    msg[0] = zero; msg[1] = zero; msg[2] = zero; msg[3] = zero;
    msg[4] = zero; msg[5] = zero; msg[6] = zero;

    while (1)
    {
        if (*(unsigned char*)ADDR(0x664544) != zero)
            goto peek;
        if (*(int*)((char*)this + 0x30) != zero)
        {
            int mode = *(int*)((char*)this + 0x1d8);
            if (mode == 4 || mode == 2)
            {
                void* obj = *(void**)((char*)this + 0x1b0);
                if (obj == 0)
                    goto peek;
                if (((T41B0*)obj)->M_42D210() == zero)
                    goto peek;
            }
        }
        if (!(*(int (__stdcall**)(void*, int, int, int))g_61c2e4)(
                msg, 0, 0, 0))
            return msg[2];
        translate(msg);
        dispatch(msg);
        continue;

    peek:
        if ((*(int (__stdcall**)(void*, int, int, int, int))g_61c2e8)(
                msg, 0, 0, 0, 1) == 0)
            goto idle;
        if (*(int*)((char*)msg + 4) == 0x12)
        {
            if (*(int*)ADDR(0x6645c8) == zero)
                return msg[2];
            *(int*)ADDR(0x6645c8) = zero;
        }
        if (slot_051(msg) == 0)
            continue;
        translate(msg);
        dispatch(msg);
        continue;

    idle:
        slot_052();
        continue;
    }
#endif
}

// Host-side pointer helpers used by the WIP bring-up bodies. The native build
// keeps the 32-bit guest field offsets, so scalar store/gather helpers are
// explicit; the config and registry contexts themselves live in native side
// globals because the truncated guest dwords cannot hold host pointers.
static char* Cfg() { return (char*)(cv_config_ptr != 0 ? cv_config_ptr : 0); }
static int CfgI(int off) { char* c = Cfg(); return c != 0 ? *(int*)(c + off) : 0; }
static short CfgS(int off) { char* c = Cfg(); return c != 0 ? *(short*)(c + off) : 0; }
static float CfgF(int off) { char* c = Cfg(); return c != 0 ? *(float*)(c + off) : 0.0f; }
static S4BE080* Regctx() { return (S4BE080*)cv_regctx; }
static int RegGet(int which, int name)
{
    S4BE080* r = Regctx();
    if (r == 0)
        return -1;
    return r->M_4BE080(which, name);
}
static int RegSet(int which, int name, int v)
{
    S4BDF50* r = (S4BDF50*)cv_regctx;
    if (r == 0)
        return 0;
    return r->M_4BDF50(which, name, v);
}

// The 0x47C4 / 0x7B0 / 0x5C0 screen shells. Constructed now through the
// reconstructed 0x425750 / 0x5200F0 entry bodies plus the byte-exact setters.
struct TScreen47C4 { char pad[0x47c4]; };
struct TScreen7B0  { char pad[0x7b0]; };
struct TScreen5C0  { char pad[0x5c0]; };

// 0x41D070 (slot +0x78) — command-line option parse. Copies config +0x518
// (the command line) into a 0x100 buffer, upper-cases it (CharUpperA via
// 0x61C2D8), keeps a second bounded copy, then strstr (0x5FCC80)-tests the
// option spellings: AUTOSAVE -> +0xB4C, NOSTARTUP -> cfg +0x890,
// SYSTEMMEMORY -> cfg +0x8A0, MIDIMUSIC -> cfg +0x8A4..+0x8B8, MSYNC -> +0x1F0,
// MFILL -> 0x65299C (0 when present), NOSOUND -> cfg +0x8A8 = 0, -G0..-G3 ->
// 0x65E3C0, 800/1024/1280 -> cfg +0x8F4/+0x8FC, RESEND1=/RESEND2= (0x5FD7C3
// _mbsstr + 0x5FD7A5/0x5FD716/0x5FD66E walk + 0x5FCFDC atoi) -> 0x66534C /
// 0x665350, LOGFPS -> 0x66457C, sound off or NOMUSIC -> cfg +0x8A4 = 0,
// cfg +0x89C == 1 && +0x894 == 1 -> +0x74 = 1, NORMALMOUSE -> +0x74 = 0.
// Returns 1. The native build keeps the old contract (+0x74 = 0, return 1):
// the guest +0x24 pointer and the guest globals are not dereferenceable there.
extern char* __cdecl sub_5FCC80(char* s, char* sub);   // strstr
extern int __cdecl sub_5FCFDC(char* s);               // atoi
MATCH_FUNC(0x41D070)
int C_vt61DF78::slot30_41D070()
{
#ifdef MATCHED_NATIVE
    *(int*)((char*)this + 0x74) = 0;
    return 1;
#else
    char buf[0x100];
    char num[0x100];
    char copy[0x100];
    char* p;
    sub_5FCB40(buf, (char*)(*(int*)((char*)this + 0x24) + 0x518), 0xff);
    buf[0xff] = 0;
    g_61C2D8(buf);
    sub_5FCB40(copy, buf, 0xff);
    *(int*)((char*)this + 0xb4c) = 0;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d80c)) || sub_5FCC80(buf, (char*)ADDR(0x64d800))
        || sub_5FCC80(buf, (char*)ADDR(0x64d7f4)))
        *(int*)((char*)this + 0xb4c) = 1;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d7e8)) || sub_5FCC80(buf, (char*)ADDR(0x64d7dc))
        || sub_5FCC80(buf, (char*)ADDR(0x64d7d0)))
        *(int*)(*(int*)((char*)this + 0x24) + 0x890) = 1;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d7c0)) || sub_5FCC80(buf, (char*)ADDR(0x64d7b0))
        || sub_5FCC80(buf, (char*)ADDR(0x64d7a0)))
        *(int*)(*(int*)((char*)this + 0x24) + 0x8a0) = 1;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d794)) || sub_5FCC80(buf, (char*)ADDR(0x64d788))
        || sub_5FCC80(buf, (char*)ADDR(0x64d77c)))
    {
        *(int*)(*(int*)((char*)this + 0x24) + 0x8a4) = 1;
        *(int*)(*(int*)((char*)this + 0x24) + 0x8ac) = 0;
        *(int*)(*(int*)((char*)this + 0x24) + 0x8b0) = 1;
        *(int*)(*(int*)((char*)this + 0x24) + 0x8b4) = 0;
        *(int*)(*(int*)((char*)this + 0x24) + 0x8b8) = 0;
    }
    if (sub_5FCC80(buf, (char*)ADDR(0x64d774)))
        *(int*)((char*)this + 0x1f0) = 1;
    *(int*)ADDR(0x65299c) = sub_5FCC80(buf, (char*)ADDR(0x64d76c)) == 0;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d764)) || sub_5FCC80(buf, (char*)ADDR(0x64d758))
        || sub_5FCC80(buf, (char*)ADDR(0x64d74c)))
        *(int*)(*(int*)((char*)this + 0x24) + 0x8a8) = 0;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d748)))
        g_65E3C0 = 0;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d744)))
        g_65E3C0 = 1;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d740)))
        g_65E3C0 = 2;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d73c)))
        g_65E3C0 = 3;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d738)))
    {
        *(int*)(*(int*)((char*)this + 0x24) + 0x8f4) = 0x320;
        *(int*)(*(int*)((char*)this + 0x24) + 0x8fc) = 0x258;
    }
    if (sub_5FCC80(buf, (char*)ADDR(0x64d730)))
    {
        *(int*)(*(int*)((char*)this + 0x24) + 0x8f4) = 0x400;
        *(int*)(*(int*)((char*)this + 0x24) + 0x8fc) = 0x300;
    }
    if (sub_5FCC80(buf, (char*)ADDR(0x64d728)))
    {
        *(int*)(*(int*)((char*)this + 0x24) + 0x8f4) = 0x500;
        *(int*)(*(int*)((char*)this + 0x24) + 0x8fc) = 0x400;
    }
    p = sub_5FD7C3(buf, (char*)ADDR(0x64d71c));
    if (p != 0)
    {
        while (*p != '=')
            p = sub_5FD7A5(p, 1);
        p = sub_5FD7A5(p, 1);
        num[0] = 0;
        while (!sub_5FD716((unsigned char)*p) && *p != 0)
        {
            sub_5FD66E(num, p, 1);
            p = sub_5FD7A5(p, 1);
        }
        *(int*)ADDR(0x66534c) = sub_5FCFDC(num);
    }
    p = sub_5FD7C3(buf, (char*)ADDR(0x64d710));
    if (p != 0)
    {
        while (*p != '=')
            p = sub_5FD7A5(p, 1);
        p = sub_5FD7A5(p, 1);
        num[0] = 0;
        while (!sub_5FD716((unsigned char)*p) && *p != 0)
        {
            sub_5FD66E(num, p, 1);
            p = sub_5FD7A5(p, 1);
        }
        *(int*)ADDR(0x665350) = sub_5FCFDC(num);
    }
    if (sub_5FCC80(buf, (char*)ADDR(0x64d708)) || sub_5FCC80(buf, (char*)ADDR(0x64d700))
        || sub_5FCC80(buf, (char*)ADDR(0x64d6f8)))
        *(int*)ADDR(0x66457c) = 1;
    if (*(int*)(*(int*)((char*)this + 0x24) + 0x8a8) == 0
        || sub_5FCC80(buf, (char*)ADDR(0x64d6f0)) || sub_5FCC80(buf, (char*)ADDR(0x64d6e4))
        || sub_5FCC80(buf, (char*)ADDR(0x64d6d8)))
        *(int*)(*(int*)((char*)this + 0x24) + 0x8a4) = 0;
    if (*(int*)(*(int*)((char*)this + 0x24) + 0x89c) == 1
        && *(int*)(*(int*)((char*)this + 0x24) + 0x894) == 1)
        *(int*)((char*)this + 0x74) = 1;
    if (sub_5FCC80(buf, (char*)ADDR(0x64d6cc)) || sub_5FCC80(buf, (char*)ADDR(0x64d6bc))
        || sub_5FCC80(buf, (char*)ADDR(0x64d6ac)))
        *(int*)((char*)this + 0x74) = 0;
    return 1;
#endif
}

// 0x41D5D0 — register the window class. The guest-exact VC6 branch reads the
// +0x24 block through its guest pointer, builds the WNDCLASS-style block, and
// invokes the 0x61C2D0/0x61C2D4 slots as absolute guest IAT memory operands
// (`ADDR` casts), which is what the original `call dword ptr [0x61C2...]`
// bytes require. The native branch uses the host WNDCLASS build plus
// Native_LoadIcon/Native_RegisterClass (headless no-op WndProc) because the
// guest pointer/words are not dereferenceable in the native image. MATCH_FUNC
// (152 bytes): the byte gate is exact.
static int __stdcall HeadlessWndProc(void* hwnd, unsigned msg, int wp, int lp)
{
    (void)hwnd; (void)msg; (void)wp; (void)lp;
    return 0;
}
struct TWndClassA {
    unsigned style;
    void* proc;
    int clsExtra;
    int wndExtra;
    void* hInst;
    void* icon;
    void* cursor;
    void* brush;
    char* menu;
    char* cls;
};
MATCH_FUNC(0x41D5D0)
int C_vt61DF78::slot31_41D5D0()
{
#ifdef MATCHED_NATIVE
    ++cv_win_class;
    if (CfgI(0x414) != 0)
        return 1;
    TWndClassA wc;
    memset(&wc, 0, sizeof wc);
    wc.style = 0xb;
    wc.proc = (void*)HeadlessWndProc;
    wc.hInst = (void*)(size_t)CfgI(0x410);
    wc.cls = (char*)"AOE matched menu";
    wc.icon = (void*)(size_t)Native_LoadIcon(
        (int)(size_t)CfgI(0x410), (char*)(Cfg() != 0 ? Cfg() + 0x61c : 0));
    int ok = Native_RegisterClass(&wc);
    return ok != 0;
#else
    int zero = 0;
    if (*(int*)(*(int*)((char*)this + 0x24) + 0x414) != zero)
        return 1;
    TWndClassA wc;
    char* cfgname = (char*)(*(int*)((char*)this + 0x24) + 0x645);
    wc.cursor = 0;
    char ch = *cfgname;
    wc.menu = (char*)ADDR(0x662be0);
    if (ch != 0)
        wc.menu = cfgname;
    wc.icon = (void*)(size_t)(*(int (__stdcall**)(int, void*))
        ADDR(0x61c2d0))(*(int*)(*(int*)((char*)this + 0x24) + 0x410),
                        (void*)(*(int*)((char*)this + 0x24) + 0x61c));
    wc.cls = (char*)(size_t)*(int*)((char*)this + 0x24);
    wc.brush = 0;
    wc.hInst = (void*)(size_t)*(int*)(*(int*)((char*)this + 0x24) + 0x410);
    wc.style = 0xb;
    wc.proc = (void*)ADDR(0x41d670);
    wc.wndExtra = 0;
    wc.clsExtra = 0;
    return (*(short (__stdcall**)(void*))ADDR(0x61c2d4))(&wc) != 0;
#endif
}

// 0x41D6A0 (slot +0x080) — create the main window. It probes GetSystemMetrics
// (0/1) into width/height, picks the extended style from the +0x24 config block
// (0x2CA0000 sized to the configured 0x8E4/0x8E8 when the sizes differ, else
// 0x82080000 sized to the metrics), calls the 0x61C398 CreateWindowEx slot, then
// runs the two 0x61C38C/0x61C2C4 rect probes with the 0x61C2C8 SetWindowPos
// correction, the 0x61C2FC/0x61C2CC/0x61C300 show/focus path when +0x894 is set,
// publishes +0x28/0x2C and 0x664528, and calls C_cluster_49FE60::M_49FE60.
// Matched once the user32 calls were real dllimports (GetSystemMetrics cached in
// edi), the window/client rects typed TRect41D6A0 and every call re-reading
// field_28 / field_24 (the calls clobber them). The native branch keeps the
// Native_CreateWindow flow and skips the raw guest slots.
extern void __cdecl Hook_49FE60Noop();
class C_cluster_49FE60 {
public:
    void M_49FE60();
};
#ifndef MATCHED_NATIVE
struct TRect41D6A0 { int left, top, right, bottom; };
extern "C" __declspec(dllimport) int __stdcall GetSystemMetrics(int index);
extern "C" __declspec(dllimport) void* __stdcall CreateWindowExA(
    unsigned exstyle, const char* cls, const char* title, unsigned style,
    int x, int y, int w, int h, void* parent, void* menu, void* inst,
    void* param);
extern "C" __declspec(dllimport) int __stdcall GetWindowRect(void* hwnd, TRect41D6A0* r);
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hwnd, TRect41D6A0* r);
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hwnd, void* after,
    int x, int y, int w, int h, unsigned flags);
extern "C" __declspec(dllimport) int __stdcall ShowWindow(void* hwnd, int cmd);
extern "C" __declspec(dllimport) int __stdcall UpdateWindow(void* hwnd);
extern "C" __declspec(dllimport) void* __stdcall SetFocus(void* hwnd);
#define CFG41D6A0 ((char*)field_24)
#define CI41D6A0(o) (*(int*)(CFG41D6A0 + (o)))
#endif
MATCH_FUNC(0x41D6A0)
int C_vt61DF78::slot32_41D6A0()
{
#ifdef MATCHED_NATIVE
    ++cv_win_class;
    int hwnd = Native_CreateWindow((int)(size_t)CfgI(0x410));
    if (hwnd == 0)
        return 0;
    *(int*)((char*)this + 0x28) = hwnd;
    *(int*)((char*)this + 0x2c) = 1;
    cv_win_handle = hwnd;
    *(int*)&g_664528 = hwnd;
    return 1;
#else
    TRect41D6A0 wr;
    TRect41D6A0 cr;
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    if (CI41D6A0(0x894) == 0 && (w != CI41D6A0(0x8e4) || h != CI41D6A0(0x8e8)))
        field_28 = CreateWindowExA(0, CFG41D6A0, CFG41D6A0 + 0x7a, 0x2ca0000,
                                   0, 0, CI41D6A0(0x8e4), CI41D6A0(0x8e8), 0, 0,
                                   (void*)CI41D6A0(0x410), 0);
    else
        field_28 = CreateWindowExA(0, CFG41D6A0, CFG41D6A0 + 0x7a, 0x82080000,
                                   0, 0, w, h, 0, 0,
                                   (void*)CI41D6A0(0x410), 0);
    if (field_28 == 0)
        return 0;
    GetWindowRect(field_28, &wr);
    GetClientRect(field_28, &cr);
    if (cr.right != CI41D6A0(0x8e4) || cr.bottom != CI41D6A0(0x8e8))
        SetWindowPos(field_28, 0, wr.left, wr.top,
                     CI41D6A0(0x8e4) - wr.left - cr.right + wr.right,
                     CI41D6A0(0x8e8) - wr.top - cr.bottom + wr.bottom, 0);
    if (CI41D6A0(0x894) != 0)
    {
        ShowWindow(field_28, CI41D6A0(0x618));
        UpdateWindow(field_28);
        SetFocus(field_28);
    }
    g_664528 = (int)field_28;
    ((C_cluster_49FE60*)0x66ea48)->M_49FE60();
    return 1;
#endif
}

// 0x41D7F0 (slot +0x84) — draw-system setup after window creation. When config
// +0x89C (fullscreen) is set, GetDC(0)/GetDeviceCaps(BITSPIXEL)/ReleaseDC
// rejects < 8 bpp with +0x60 = 0x13. Then 0x66EA48->M_49FED0, `new` the 0x4B8
// draw system (ctor 0x45DDB0, EH frame) at +0x68, M_45DF20(cfg +0x894), and
// probe the configured mode via M_45E2C0(cfg +0x8E4, 0, 8), falling back to
// 800x600, 1024x768, then 1280x1024 (the original probes the last one with a
// width of 0x400 — kept as is). M_45E4C0(hinst, hwnd, +0x34, fullscreen?2:1,
// cfg+0x894?2:1, w, h, cfg+0x8A0 != 0) opens the device; then the 0x66EA48
// palette chain (0x49FE00, 0x49FB60 -> +0x34), +0x6C = draw +0x0C with
// M_460180(0,0), M_45EF10(0) and 0x66EA48->M_49FF20; returns 1. The native
// build keeps the old success contract (the guest draw system is not built).
#ifndef MATCHED_NATIVE
class C_vt621F64 {
public:
    void M_49FED0();
    void M_49FE00(int a1);
};
class S49FF20 { public: void M_49FF20(); };
class C_cluster_45DF20 { public: void M_45DF20(int a1); };
class S45EA60 { public: void M_45EF10(int* a1); void Clear_45EA60(); };
class T4A0C20 { public: void M_460180(void* a1, int a2); };
class S45DDB0 { public: S45DDB0* Init_45DDB0(); };
// The 0x4B8 draw system at +0x68 (ctor 0x45DDB0).
class T41D7F0Draw {
public:
    char pad_00[0xc];
    void* field_0c;                 // +0x0C primary draw area
    char pad_10[0x4b8 - 0x10];
    T41D7F0Draw();
    int M_45E2C0(int w, int a2, int bpp);
    int M_45E4C0(int inst, int hwnd, int pal, char fullscreen, char mode,
                 int w, int h, int flag);
};
T41D7F0Draw::T41D7F0Draw()
{
    ((S45DDB0*)this)->Init_45DDB0();
}
extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hwnd);
extern "C" __declspec(dllimport) int __stdcall GetDeviceCaps(void* dc, int index);
extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hwnd, void* dc);
#endif
MATCH_FUNC(0x41D7F0)
int C_vt61DF78::slot33_41D7F0()
{
#ifdef MATCHED_NATIVE
    return 1;
#else
    if (*(int*)(*(int*)((char*)this + 0x24) + 0x89c) != 0)
    {
        void* dc = GetDC(0);
        int bpp = GetDeviceCaps(dc, 0xc);
        ReleaseDC(0, dc);
        if (bpp < 8)
        {
            field_60 = 0x13;
            return 0;
        }
    }
    ((C_vt621F64*)ADDR(0x66ea48))->M_49FED0();
    int cfg = *(int*)((char*)this + 0x24);
    char m1 = *(int*)(cfg + 0x89c) ? 2 : 1;
    char m2 = *(int*)(cfg + 0x894) ? 2 : 1;
    int f = *(int*)(cfg + 0x8a0) != 0;
    T41D7F0Draw* draw = new T41D7F0Draw();
    *(T41D7F0Draw**)((char*)this + 0x68) = draw;
    if (draw == 0)
        return 0;
    ((C_cluster_45DF20*)draw)->M_45DF20(*(int*)(*(int*)((char*)this + 0x24) + 0x894));
    if (!(*(T41D7F0Draw**)((char*)this + 0x68))->M_45E2C0(
            *(int*)(*(int*)((char*)this + 0x24) + 0x8e4), 0, 8))
    {
        if (*(int*)(*(int*)((char*)this + 0x24) + 0x8e4) != 0x320
            && (*(T41D7F0Draw**)((char*)this + 0x68))->M_45E2C0(0x320, 0, 8))
        {
            *(int*)(*(int*)((char*)this + 0x24) + 0x8e4) = 0x320;
            *(int*)(*(int*)((char*)this + 0x24) + 0x8e8) = 0x258;
        }
        else if (*(int*)(*(int*)((char*)this + 0x24) + 0x8e4) != 0x400
            && (*(T41D7F0Draw**)((char*)this + 0x68))->M_45E2C0(0x400, 0, 8))
        {
            *(int*)(*(int*)((char*)this + 0x24) + 0x8e4) = 0x400;
            *(int*)(*(int*)((char*)this + 0x24) + 0x8e8) = 0x300;
        }
        else if (*(int*)(*(int*)((char*)this + 0x24) + 0x8e4) != 0x500
            && (*(T41D7F0Draw**)((char*)this + 0x68))->M_45E2C0(0x400, 0, 8))
        {
            *(int*)(*(int*)((char*)this + 0x24) + 0x8e4) = 0x500;
            *(int*)(*(int*)((char*)this + 0x24) + 0x8e8) = 0x400;
        }
        else
            return 0;
    }
    cfg = *(int*)((char*)this + 0x24);
    if (!(*(T41D7F0Draw**)((char*)this + 0x68))->M_45E4C0(
            *(int*)(cfg + 0x410), *(int*)((char*)this + 0x28), field_34,
            m1, m2, *(int*)(cfg + 0x8e4), *(int*)(cfg + 0x8e8), f))
        return 0;
    ((C_vt621F64*)ADDR(0x66ea48))->M_49FE00(field_34);
    field_34 = ((T49FB60*)ADDR(0x66ea48))->Hook_49FB60(
        (void*)(*(int*)((char*)this + 0x24) + 0x66e), 0xc544, 1);
    *(void**)((char*)this + 0x6c) = (*(T41D7F0Draw**)((char*)this + 0x68))->field_0c;
    ((T4A0C20*)*(void**)((char*)this + 0x6c))->M_460180(0, 0);
    ((S45EA60*)*(T41D7F0Draw**)((char*)this + 0x68))->M_45EF10(0);
    ((S49FF20*)ADDR(0x66ea48))->M_49FF20();
    return 1;
#endif
}

// 0x41DAA0 — post-window startup chain. WIP success contract.
// 0x48A410's 0x268 registry/edit object; the real ctor is lifted, so the stub
// below keeps a non-trivial hook ctor to preserve the original VC6 EH frame.
// 0x48A6F0 (its five-argument setup) and 0x41F920 (the +0x1E8-based teardown)
// are modelled as success-contract stubs here; 0x41F920 itself is matched in
// Source/app/C_cluster_48B300_member_1E8.cpp but acts on the base object.
extern void __cdecl Hook_41DAA0Ctor(void* p, int a1);
class T48A410 {
public:
    char pad_00[0x268];
    T48A410(int a1);
    int M_48A6F0(int a1, int a2, int a3, int a4, int a5);
};
T48A410::T48A410(int a1)
{
    Hook_41DAA0Ctor(this, a1);
}
void __cdecl Hook_41DAA0Ctor(void* p, int a1)
{
    (void)p; (void)a1;
}
int T48A410::M_48A6F0(int a1, int a2, int a3, int a4, int a5)
{
    (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    return 1;
}
class C_cluster_48B300_member_1E8 {
public:
    void M_41F920();
};

// 0x41DAA0 matched as a plain if / else-if chain with an explicit final
// `else arg0 = 0;` (that store is the shared `xor edi,edi` the -1 arm and the
// default arm both land on). 0x41DAA0
// itself: registry resolution plus the 0x268 edit object. It
// reads the registry key 0x64D818; -1 triggers the 0x4BDF50 registration with
// (0,key,0); 1 keeps the argument as the +0x74 selection; 2 clears +0x74.
// Then `new` constructs the 0x268 object with 0, stores it at +0x1E8, runs the
// 0x48A6F0 five-argument setup from +0x74/+0x6C/config +0x773/(0xC738,0x13),
// and on success calls the base 0x41F920 teardown. Both failures return 0;
// success returns 1.
MATCH_FUNC(0x41DAA0)
int C_vt61DF78::slot35_41DAA0()
{
    int arg0 = 0;
    int result;
#ifdef MATCHED_NATIVE
    result = RegGet(arg0, (int)(size_t)ADDR(0x64d818));
#else
    result = (*(S4BE080**)((char*)this + 0x1d4))
                 ->M_4BE080(arg0, (int)(size_t)ADDR(0x64d818));
#endif
    if (result == -1)
    {
#ifdef MATCHED_NATIVE
        RegSet(arg0, (int)(size_t)ADDR(0x64d818), 0);
#else
        (*(S4BDF50**)((char*)this + 0x1d4))
            ->M_4BDF50(arg0, (int)(size_t)ADDR(0x64d818), 0);
#endif
        arg0 = 0;
    }
    else if (result == 1)
        arg0 = result;
    else if (result == 2)
        *(int*)((char*)this + 0x74) = 0;
    else
        arg0 = 0;
    T48A410* p = new T48A410(arg0);
    *(int*)((char*)this + 0x1e8) = (int)(size_t)p;
    if (p == 0)
        return 0;
#ifdef MATCHED_NATIVE
    if (!p->M_48A6F0(*(int*)((char*)this + 0x74), *(int*)((char*)this + 0x6c),
                     (int)(size_t)(cv_config_ptr ? (char*)cv_config_ptr + 0x773 : 0),
                     0xc738, 0x13))
        return 0;
    (void)(C_cluster_48B300_member_1E8*)this;
#else
    if (!p->M_48A6F0(*(int*)((char*)this + 0x74), *(int*)((char*)this + 0x6c),
                     *(int*)((char*)this + 0x24) + 0x773, 0xc738, 0x13))
        return 0;
    ((C_cluster_48B300_member_1E8*)this)->M_41F920();
#endif
    return 1;
}

// 0x41DBA0 — UI theme/text init. WIP success contract.
// 0x422980 — constructor-like method of the 0x12C menu screen object that
// 0x41DBA0 allocates; it zeroes +0x04/+0x2C blocks, builds the 0x198 child at
// +0x128 and seeds the 0x54 block. Still a minimal stub body here (the real
// construction is lifted), but the call shape below is the original ctor call.
class T422980 {
public:
    char pad_00[0x12c];
    T422980(int a1);
    ~T422980();
};
extern void __cdecl Hook_422980Init(void* p, int a1);
T422980::T422980(int a1)
{
    Hook_422980Init(this, a1);
}
void __cdecl Hook_422980Init(void* p, int a1)
{
    (void)p; (void)a1;
}


// 0x41DBA0 (slot +0x098) — allocate the 0x12C object and construct it with the
// window handle at +0x28, store the constructed pointer at 0x664524, and report
// whether construction succeeded. `new` reproduces the original VC6 EH frame
// and the operator-new/ctor/free-unwind sequence.
MATCH_FUNC(0x41DBA0)
int C_vt61DF78::slot38_41DBA0()
{
    T422980* p = new T422980(*(int*)((char*)this + 0x28));
    *(int*)ADDR(0x664524) = (int)(size_t)p;
    return p != 0;
}

#ifndef MATCHED_NATIVE
// ---- 0x41DE50 / 0x41E070 / 0x41BC80 support (VC6 match path only) ---------
// Layout view of C_vt61DF78 for the three bring-up slots: typed fields at the
// original offsets plus the full 87-slot vtable shape (slot 3 takes an int,
// slot 86 = +0x158), so the bodies read this->field directly and call the
// virtual slots by offset without changing the shared class declaration.
struct Rect16_425750 { int a, b, c, d; };
struct CfgApp {
    char pad0[0x410]; int f410;
    char pad1[0x878 - 0x414]; char opt_878; char pad1b[3]; int f87c;
    char pad2[0x88c - 0x880]; int f88c;
    char pad3[0x8a8 - 0x890]; int f8a8;
    char pad4[0x8cc - 0x8ac]; int f8cc; int f8d0; int f8d4;
    char pad5[0x8e0 - 0x8d8]; short w8e0;
    char pad6[0x8f4 - 0x8e2]; int f8f4; short w8f8; short w8fa; int f8fc;
    Rect16_425750 r900;
    char pad7[0xd44 - 0x910]; char path_d44[0xf4e - 0xd44];
    char name_f4e[0x105]; char name_1053[0x105]; char name_1158[0x20a];
    char name_1362[4];
};
class T425750 {                     // 0x47C4 main-menu screen
public:
    char pad[0x47c4];
    T425750(int hwnd, char opt, int obj, Rect16_425750 r);   // 0x425750
    void M_408650(int unused);
    void M_425650(int a1);
    void M_425680(int a1);
    void M_4256A0(int a1);
    void M_42FD00(int a1);
};
class T438ED0 { public: char pad[0xe5c]; T438ED0(T425750* s); };
class T5E4610 { public: void M_5E4610(T425750* s); };
class T5200F0 {                     // 0x7B0 game/options screen
public:
    char pad[0xc]; int fc; char pad2[0x7b0 - 0x10];
    T5200F0(int hwnd, char* name);  // 0x5200F0
    ~T5200F0();                     // 0x520120
    int M_520400();
    void M_520410(int v, int b);
};
class T520CC0 {                     // 0x5C0 options sub-screen
public:
    char pad[0x5c0];
    T520CC0(int a, int hwnd);       // 0x520CC0
    void M_520DD0(char* s);
    void M_520E10(char* s);
    void M_520E50(char* s);
    void M_520E90(char* s);
    void M_520F50(int v);
    void M_520ED0(char* s);
    int M_521090(char* s, int a, int b, int c);
    void M_520F70(int id, int v);
    void M_5215F0(int id);
};
class TRegApp { public: int M_4BE080(int a, const char* s); char* M_4BE010(int a, const char* s); void M_4BDF50(int a, const char* s, int v); };
class T462B50 { public: char pad[0x274]; T462B50(); };
class T4647C0 { public: char pad[0x11c]; T4647C0(char* s); };
class T4CFAC0 { public: char pad[0x10c]; T4CFAC0(char* s); };
struct S664520App { char pad[0x160c]; int f160c; };
struct MemStatApp { unsigned long dwLength, dwMemoryLoad, dwTotalPhys, dwAvailPhys, dwTotalPageFile, dwAvailPageFile, dwTotalVirtual, dwAvailVirtual; };
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* name);
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(void* ms);
extern "C" __declspec(dllimport) int __stdcall SystemParametersInfoA(unsigned int a, unsigned int b, void* c, unsigned int d);
extern "C" __declspec(dllimport) unsigned int __stdcall SetTimer(void* h, unsigned int id, unsigned int ms, void* proc);
extern int __cdecl sub_5FCA14_rand();                              // 0x5FCA14
extern void __cdecl sub_4BD830();                                  // 0x4BD830
extern int __cdecl sub_5FCE14_sprintf(char* buf, const char* fmt, ...);  // 0x5FCE14
extern void* __cdecl sub_5FCE01_fopen(const char* name, const char* mode); // 0x5FCE01
extern void __cdecl sub_4378C0(int a, int b, const char* c);       // 0x4378C0
class AppView {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(int a1);
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual int v30(); virtual int v31();
    virtual int v32(); virtual int v33(); virtual int v34(); virtual int v35();
    virtual void v36(); virtual void v37(); virtual int v38(); virtual int v39();
    virtual int v40(); virtual int v41(); virtual int v42(); virtual int v43();
    virtual int v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62();
    virtual int v63(int a1, int a2, int a3, int a4);
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual int v85(); virtual void v86();
    char pad04[0x1c - 4];
    T4647C0* f1c;                   // +0x1C
    T4CFAC0* f20;                   // +0x20
    CfgApp* cfg_24;                 // +0x24
    void* hwnd_28;                  // +0x28
    int f2c;                        // +0x2C
    char pad30[0x54 - 0x30];
    int f54;                        // +0x54 SPI mouse 0x10
    int f58;                        // +0x58 SPI 0x53
    char pad5c[0x60 - 0x5c];
    int field_60;                   // +0x60 bring-up error code
    int f64;                        // +0x64 timer id
    char pad68[0x80 - 0x68];
    T5200F0* f80;                   // +0x80
    char pad84[0x90 - 0x84];
    T520CC0* f90;                   // +0x90
    char pad94[0x1b0 - 0x94];
    T425750* screen_1b0;            // +0x1B0
    int f1b4, f1b8, f1bc, f1c0, f1c4;
    char pad1c8[0x1d4 - 0x1c8];
    TRegApp* reg_1d4;               // +0x1D4
    char pad1d8[0x315 - 0x1d8];
    char dll_315[0x41c - 0x315];    // +0x315
    T5E4610* f41c;                  // +0x41C
    char pad420[0x9cc - 0x420];
    float f9cc;                     // +0x9CC
    char pad9d0[0x9e0 - 0x9d0];
    int f9e0;                       // +0x9E0
    char pad9e4[0xb48 - 0x9e4];
    int fb48;                       // +0xB48
    char padb4c[0xb50 - 0xb4c];
    char preset_b50[5][0x104];      // +0xB50
    int f1064[5];                   // +0x1064
    char blk_1078[0x108c - 0x1078]; // +0x1078
    float f108c;                    // +0x108C
    int f1090;                      // +0x1090
    // Members not yet declared on C_vt61DF78 (0x421F90/0x422180/0x41F8B0/0x409A10).
    void M_421F90(int v);
    bool M_422180(const char* s);
    void M_41F8B0();
    int M_409A10();
};
#define APPV ((AppView*)this)
// ---------------------------------------------------------------------------
#endif

// 0x41DE50 (slot +0x9C) — build the 0x47C4 main-menu screen: `new` it with
// (hwnd, config byte +0x878, 0x664524 object, 16-byte config rect +0x900 by
// value), store it at +0x1B0, then `new` the 0xE5C 0x438ED0 object into
// 0x66450C, run the 0x425650/425680/408650/4256A0 setters from +0x1B4..+0x1C4,
// publish it at 0x664520 and hand it to +0x41C (0x5E4610) and the 0x6645A0/A4
// objects (0x42FD00 on the screen). The VC6 path is the byte-exact original;
// MATCHED_NATIVE keeps the previous host bring-up body (64-bit host pointers
// cannot live in the 32-bit guest fields the original uses).
MATCH_FUNC(0x41DE50)
int C_vt61DF78::slot39_41DE50()
{
#ifndef MATCHED_NATIVE
    APPV->screen_1b0 = new T425750((int)APPV->hwnd_28, APPV->cfg_24->opt_878,
        *(int*)ADDR(0x664524), APPV->cfg_24->r900);
    APPV->screen_1b0->M_408650((int)APPV->blk_1078);
    if (APPV->screen_1b0 == 0)
        return 0;
    *(T438ED0**)ADDR(0x66450c) = new T438ED0(APPV->screen_1b0);
    APPV->screen_1b0->M_425650(APPV->f1b4);
    APPV->screen_1b0->M_425680(APPV->f1bc);
    APPV->screen_1b0->M_408650(APPV->f1c0);
    APPV->screen_1b0->M_4256A0(APPV->f1c4);
    APPV->screen_1b0->M_408650(APPV->f1b8);
    *(T425750**)ADDR(0x664520) = APPV->screen_1b0;
    if (APPV->f41c)
        APPV->f41c->M_5E4610(APPV->screen_1b0);
    if (*(int*)ADDR(0x6645a0))
        APPV->screen_1b0->M_42FD00(*(int*)ADDR(0x6645a0));
    if (*(int*)ADDR(0x6645a4))
        APPV->screen_1b0->M_42FD00(*(int*)ADDR(0x6645a4));
    return 1;
#else
#ifdef MATCHED_NATIVE
    ++cv_de50_hits;
    char* cfg = (char*)cv_config_ptr;
    int hwnd = *(int*)((char*)this + 0x28);
#else
    char* cfg = (char*)(size_t)*(int*)((char*)this + 0x24);
    int hwnd = (int)(size_t)*(int*)((char*)this + 0x28);
#endif
    TScreen47C4* p = (TScreen47C4*)(size_t)sub_5F8F60(0x47c4);
    if (p == 0)
        return 0;
    memset(p, 0, 0x47c4);
#ifdef MATCHED_NATIVE
    cv_s47_screen = p;
#endif
    int b0 = 0, b1 = 0, b2 = 0, b3 = 0;
    if (cfg != 0)
    {
        b0 = *(int*)(cfg + 0x900);
        b1 = *(int*)(cfg + 0x904);
        b2 = *(int*)(cfg + 0x908);
        b3 = *(int*)(cfg + 0x90c);
    }
    ((S47C4Screen*)p)->M_425750(hwnd, (int)(size_t)cfg,
        *(int*)ADDR(0x664524), b0, b1, b2, b3);
    *(void**)((char*)this + 0x1b0) = p;
    ((C_vt61CE24*)p)->M_408650(
        (int)(size_t)((char*)this + 0x1078));
    ((Sc425650*)p)->M_425650(*(int*)((char*)this + 0x1b4));
    ((S425680*)p)->M_425680(*(int*)((char*)this + 0x1bc));
    ((C_vt61CE24*)p)->M_408650(*(int*)((char*)this + 0x1c0));
    ((S4256A0*)p)->M_4256A0(*(int*)((char*)this + 0x1c4));
    ((C_vt61CE24*)p)->M_408650(*(int*)((char*)this + 0x1b8));
    *(int*)&g_664520 = (int)(size_t)p;
#ifdef MATCHED_NATIVE
    {
        int pop = 0;
        if (*(int*)((char*)p + 0x12d4)) pop++;
        if (*(int*)((char*)p + 0x12d8)) pop++;
        if (*(int*)((char*)p + 0x12ec)) pop++;
        if (*(int*)((char*)p + 0x130c)) pop++;
        if (*(int*)((char*)p + 0x15e8)) pop++;
        if (*(int*)((char*)p + 0x15f8)) pop++;
        if (*(int*)((char*)p + 0x15fc)) pop++;
        if (*(int*)((char*)p + 0x1604)) pop++;
        if (*(int*)((char*)p + 0x1610)) pop++;
        if (*(int*)((char*)p + 0x18)) pop++;
        if (*(int*)((char*)p + 0x3524)) pop++;
        cv_screen47_pop = pop;
    }
#endif
    if (*(int*)((char*)this + 0x41c) != 0)
        sub_5E4610((int)(size_t)p);
    if (*(int*)ADDR(0x6645a0) != 0)
        sub_42FD00((int)(size_t)p);
    if (*(int*)ADDR(0x6645a4) != 0)
        sub_42FD00((int)(size_t)p);
    return 1;
#endif
}

// 0x41E070 (slot +0xA0) — when config +0x8A8 is set, `new` the 0x7B0 screen
// (0x5200F0(hwnd, config+0xF4E)) into +0x80; if its 0x520400 gate fails it is
// deleted (0x520120 dtor + free), +0x80 cleared and the slot returns 1 at once.
// Otherwise publish it at 0x664518 and run 0x520410(-regkey or 0, 1). Then the
// +0x60 virtual, and (again under +0x8A8) `new` the 0x5C0 object
// (0x520CC0(config+0x410, hwnd)) into +0x90, copy the four config names, the
// 0x7B0 screen's +0xC, the 0x4BE010 registry string, register the five preset
// names at +0xB50 (0x521090 -> 0x520F70(id, +0x1064[i]) / 0x5215F0(id)) and
// clear them. VC6 path byte-exact; MATCHED_NATIVE keeps the host body.
MATCH_FUNC(0x41E070)
int C_vt61DF78::slot40_41E070()
{
#ifndef MATCHED_NATIVE
    int i;
    if (APPV->cfg_24->f8a8)
    {
        APPV->f80 = new T5200F0((int)APPV->hwnd_28, APPV->cfg_24->name_f4e);
        if (APPV->f80 && !APPV->f80->M_520400())
        {
            delete APPV->f80;
            APPV->f80 = 0;
            return 1;
        }
        *(T5200F0**)ADDR(0x664518) = APPV->f80;
        int v = 0;
        int r = APPV->reg_1d4->M_4BE080(1, (const char*)ADDR(0x64d844));
        if (r != -1)
            v = -r;
        APPV->f80->M_520410(v, 1);
    }
    APPV->v24();
    if (APPV->cfg_24->f8a8)
    {
        APPV->f90 = new T520CC0(APPV->cfg_24->f410, (int)APPV->hwnd_28);
        if (APPV->f90)
        {
            APPV->f90->M_520DD0(APPV->cfg_24->name_f4e);
            APPV->f90->M_520E10(APPV->cfg_24->name_1053);
            APPV->f90->M_520E50(APPV->cfg_24->name_1158);
            APPV->f90->M_520E90(APPV->cfg_24->name_1362);
            APPV->f90->M_520F50(APPV->f80->fc);
            APPV->f90->M_520ED0(APPV->reg_1d4->M_4BE010(0, (const char*)ADDR(0x64d83c)));
            for (i = 0; i < 5; i++)
            {
                if (APPV->preset_b50[i][0])
                {
                    int id = APPV->f90->M_521090(APPV->preset_b50[i], 1, 0, 6);
                    if (id != -1)
                    {
                        APPV->f90->M_520F70(id, APPV->f1064[i]);
                        APPV->f90->M_5215F0(id);
                    }
                }
            }
            for (i = 0; i < 5; i++)
            {
                APPV->f1064[i] = 0;
                APPV->preset_b50[i][0] = 0;
            }
        }
    }
    return 1;
#else
#ifdef MATCHED_NATIVE
    ++cv_e070_hits;
    char* cfg = (char*)cv_config_ptr;
    int hwnd = *(int*)((char*)this + 0x28);
#else
    char* cfg = (char*)(size_t)*(int*)((char*)this + 0x24);
    int hwnd = (int)(size_t)*(int*)((char*)this + 0x28);
#endif
    TScreen7B0* s1 = 0;
#ifdef MATCHED_NATIVE
    cv_cfg_sound = (cfg != 0 && cfg[0xf4e] != 0) ? 1 : 0;
#endif
    if (cfg != 0 && *(int*)(cfg + 0x8a8) != 0)
    {
        s1 = (TScreen7B0*)(size_t)sub_5F8F60(0x7b0);
        if (s1 != 0)
        {
            ((C_cluster_5200F0*)s1)->M_5200F0(
                hwnd, (int)(size_t)(cfg + 0xf4e));
            *(void**)((char*)this + 0x80) = s1;
#ifdef MATCHED_NATIVE
            cv_s47_80 = s1;
#endif
            if (((S520400*)s1)->Get_520400() != 0)
            {
                *(int*)&g_664518 = (int)(size_t)s1;
                int r = ((S4BE080*)Regctx())->M_4BE080(
                    1, (int)(size_t)ADDR(0x64d844));
                int v = -1;
                if (r != -1)
                    v = -r;
                ((S520410*)s1)->M_520410(v, 1);
#ifdef MATCHED_NATIVE
                {
                    int pop = 0;
                    if (*(int*)((char*)s1 + 0x4)) pop++;
                    if (*(int*)((char*)s1 + 0x8)) pop++;
                    if (*(int*)((char*)s1 + 0x14)) pop++;
                    if (*(int*)((char*)s1 + 0x18)) pop++;
                    if (*(int*)((char*)s1 + 0x20)) pop++;
                    cv_screen7b0_pop = pop;
                }
#endif
            }
            else
            {
                sub_520120();
                sub_5F90B0(s1);
                *(void**)((char*)this + 0x80) = 0;
#ifdef MATCHED_NATIVE
                cv_s47_80 = 0;
#endif
            }
        }
    }
    TScreen5C0* s2 = 0;
    if (cfg != 0 && *(int*)(cfg + 0x8a8) != 0)
    {
        s2 = (TScreen5C0*)(size_t)sub_5F8F60(0x5c0);
        if (s2 != 0)
        {
            ((S520CC0*)s2)->Init_520CC0(
                hwnd, *(int*)(cfg + 0x410));
            *(void**)((char*)this + 0x90) = s2;
#ifdef MATCHED_NATIVE
            cv_s47_90 = s2;
#endif
            char* n1 = cfg + 0xf4e;
            char* n2 = cfg + 0x1053;
            char* n3 = cfg + 0x1158;
            char* n4 = cfg + 0x1362;
#ifdef MATCHED_NATIVE
            // The reduced native boot's stack config block carries the numeric
            // options (+0x878/+0x8A8/...) but its string area is not staged by
            // the host path; fall back to the same guest constants the original
            // 0x47AE20 copies into those slots.
            if (*n1 == 0) n1 = (char*)ADDR(0x652fc0);
            if (*n2 == 0) n2 = (char*)ADDR(0x652fb0);
            if (*n3 == 0) n3 = (char*)ADDR(0x652fa0);
            if (*n4 == 0) n4 = (char*)ADDR(0x652f90);
#endif
            ((S52SetBulk*)s2)->CopyName_520DD0(n1);
            ((S52SetBulk*)s2)->CopyName_520E10(n2);
            ((S52SetBulk*)s2)->CopyName_520E50(n3);
            ((S52SetBulk*)s2)->CopyName_520E90(n4);
            int v = 0;
            if (s1 != 0)
                v = *(int*)((char*)s1 + 0xc);
            ((S52SetBulk*)s2)->SetInt_520F50(v);
            void* pn = ((S4BE010*)Regctx())->M_4BE010(
                0, (int)(size_t)ADDR(0x64d83c));
            ((S52SetBulk*)s2)->CopyName_520ED0((char*)(size_t)pn);
            for (int i = 0; i < 5; i++)
            {
                char* preset = (char*)this + 0xb50 + i * 0x104;
                if (*preset != 0)
                {
                    ++cv_e070_preset_entries;
                    int id = ((T4EE210Obj*)s2)->M_521090(
                        (int)(size_t)preset, 1, 0, 6);
                    if (id != -1)
                    {
                        // 0x520F70/0x5215F0 remain lifted; not entered in the
                        // native boot because the five preset bytes are empty.
                    }
                }
            }
            for (int j = 0; j < 5; j++)
            {
                *(int*)((char*)this + 0x1064 + j * 4) = 0;
                *((char*)this + 0xb50 + j * 0x104) = 0;
            }
#ifdef MATCHED_NATIVE
            {
                int pop = 0;
                if (*(int*)((char*)s2 + 0x4)) pop++;
                if (*(int*)((char*)s2 + 0xc)) pop++;
                if (*(int*)((char*)s2 + 0x70)) pop++;
                if (*(int*)((char*)s2 + 0x84)) pop++;
                if (*(int*)((char*)s2 + 0x188)) pop++;
                if (*(int*)((char*)s2 + 0x28c)) pop++;
                if (*(int*)((char*)s2 + 0x390)) pop++;
                if (*(int*)((char*)s2 + 0x494)) pop++;
                cv_screen5c0_pop = pop;
            }
#endif
        }
    }
    return 1;
#endif
}

// 0x41E4A0 — dialogue/panel bootstrap. WIP success contract.
// 0x51E7F0's 0x1C entry object: three of them are installed into the array at
// +0x7C. The real constructor is lifted, so the shape below uses a non-trivial
// stub ctor to keep the original VC6 EH frame on each `new`.
extern void __cdecl Hook_51E7F0Ctor(void* p, char* a1, int a2);
class T51E7F0 {
public:
    char pad_00[0x1c];
    T51E7F0(char* a1, int a2);
};
T51E7F0::T51E7F0(char* a1, int a2)
{
    Hook_51E7F0Ctor(this, a1, a2);
}
void __cdecl Hook_51E7F0Ctor(void* p, char* a1, int a2)
{
    (void)p; (void)a1; (void)a2;
}
extern void* __cdecl sub_5F8FF0(unsigned int a1, int a2);

// 0x41E4A0 (slot +0xAC) — seed the +0x78 short to 3, allocate the 3*4 integer
// array through 0x5F8FF0, store it at +0x7C, zero each slot, then `new` three
// 0x1C entries from the 0x64D888/0x64D878/0x64D86C names and codes
// 0xC4E3/0xC4E4/0xC4E5 into the array.
MATCH_FUNC(0x41E4A0)
int C_vt61DF78::slot43_41E4A0()
{
#ifdef MATCHED_NATIVE
    // The guest stores the array pointer in the truncated dword at +0x7C; the
    // lateral table only holds a 32-bit word, so the native path keeps the full
    // host pointer in a side variable and mirrors the same zero-fill plus three
    // 0x1C entries.
    *(short*)((char*)this + 0x78) = 3;
    int* arr = (int*)sub_5F8FF0(3, 4);
    cv_e4a0_arr = arr;
    *(int*)((char*)this + 0x7c) = 0;
    if (arr == 0)
        return 0;
    for (int i = 0; i < 3; i++)
        arr[i] = 0;
    {
        T51E7F0* a = new T51E7F0((char*)ADDR(0x64d888), 0xc4e3);
        arr[0] = (int)(size_t)a;
        T51E7F0* b = new T51E7F0((char*)ADDR(0x64d878), 0xc4e4);
        arr[1] = (int)(size_t)b;
        T51E7F0* c = new T51E7F0((char*)ADDR(0x64d86c), 0xc4e5);
        arr[2] = (int)(size_t)c;
    }
    return 1;
#else
    *(short*)((char*)this + 0x78) = 3;
    *(int*)((char*)this + 0x7c) = (int)(size_t)sub_5F8FF0(3, 4);
    if (*(int*)((char*)this + 0x7c) == 0)
        return 0;
    {
        int i = 0;
        for (; i < *(short*)((char*)this + 0x78); i++)
            *(int*)((char*)(size_t)*(int*)((char*)this + 0x7c) + i * 4) = 0;
    }
    {
        T51E7F0* a = new T51E7F0((char*)ADDR(0x64d888), 0xc4e3);
        *(int*)((char*)(size_t)*(int*)((char*)this + 0x7c)) = (int)(size_t)a;
    }
    {
        T51E7F0* b = new T51E7F0((char*)ADDR(0x64d878), 0xc4e4);
        *(int*)((char*)(size_t)*(int*)((char*)this + 0x7c) + 4) = (int)(size_t)b;
    }
    {
        T51E7F0* c = new T51E7F0((char*)ADDR(0x64d86c), 0xc4e5);
        *(int*)((char*)(size_t)*(int*)((char*)this + 0x7c) + 8) = (int)(size_t)c;
    }
    return 1;
#endif
}

// 0x41E5D0 — font/panel construction. WIP success contract.
// 0x520720 is the real matched init method of the 0x20 entry object; the stub
// ctor below forwards to it so the native bring-up builds real entries while
// the original VC6 EH frame is preserved on `new`. 0x5207B0 (the entry cleanup)
// is still lifted and gets a no-op stub.
class C_cluster_520720 {
public:
    C_cluster_520720* M_520720(int a1, int a2, int a3);
};
class C_cluster_5207B0 {
public:
    void M_5207B0(int a1, int a2, int a3);
};
extern void __cdecl Hook_41E5D0Ctor(void* p, int a1, char* a2, int a3);
class T41E5D0Entry {
public:
    char pad_00[0x20];
    T41E5D0Entry(int a1, char* a2, int a3);
};
T41E5D0Entry::T41E5D0Entry(int a1, char* a2, int a3)
{
    Hook_41E5D0Ctor(this, a1, a2, a3);
}
void __cdecl Hook_41E5D0Ctor(void* p, int a1, char* a2, int a3)
{
    ((C_cluster_520720*)p)->M_520720(a1, (int)(size_t)a2, a3);
}
// Native-only: a body visible to VC6 lets it prove the 0x41E5D0 cleanup loop
// cannot throw and drop the original's final EH-state (-1) store.
#ifdef MATCHED_NATIVE
void C_cluster_5207B0::M_5207B0(int a1, int a2, int a3)
{
    (void)a1; (void)a2; (void)a3;
}
#endif

// 0x41E5D0 (slot +0xA8) — the sibling of 0x41E4A0: seed +0x88 to 3, allocate
// the 3*4 table through 0x5F8FF0 at +0x8C, zero it, `new` three 0x20 entries
// from the 0x64D8B4/0x64D8A8/0x64D898 names with codes 0xC47C/0xC47D/0xC47E
// and the +0x80 object, then walk the table and run each entry's 0x5207B0
// cleanup with (0,-1,0).
MATCH_FUNC(0x41E5D0)
int C_vt61DF78::slot42_41E5D0()
{
#ifdef MATCHED_NATIVE
    *(short*)((char*)this + 0x88) = 3;
    int* arr = (int*)sub_5F8FF0(3, 4);
    cv_e5d0_arr = arr;
    *(int*)((char*)this + 0x8c) = 0;
    if (arr == 0)
        return 0;
    for (int i = 0; i < 3; i++)
        arr[i] = 0;
    {
        T41E5D0Entry* a = new T41E5D0Entry(*(int*)((char*)this + 0x80),
                                           (char*)ADDR(0x64d8b4), 0xc47c);
        arr[0] = (int)(size_t)a;
        T41E5D0Entry* b = new T41E5D0Entry(*(int*)((char*)this + 0x80),
                                           (char*)ADDR(0x64d8a8), 0xc47d);
        arr[1] = (int)(size_t)b;
        T41E5D0Entry* c = new T41E5D0Entry(*(int*)((char*)this + 0x80),
                                           (char*)ADDR(0x64d898), 0xc47e);
        arr[2] = (int)(size_t)c;
    }
    for (int i = 0; i < 3; i++)
    {
        C_cluster_5207B0* e = (C_cluster_5207B0*)(size_t)arr[i];
        if (e != 0)
            e->M_5207B0(0, -1, 0);
    }
    return 1;
#else
    *(short*)((char*)this + 0x88) = 3;
    *(int*)((char*)this + 0x8c) = (int)(size_t)sub_5F8FF0(3, 4);
    if (*(int*)((char*)this + 0x8c) == 0)
        return 0;
    {
        int i = 0;
        for (; i < *(short*)((char*)this + 0x88); i++)
            *(int*)((char*)(size_t)*(int*)((char*)this + 0x8c) + i * 4) = 0;
    }
    {
        T41E5D0Entry* a = new T41E5D0Entry(*(int*)((char*)this + 0x80),
                                           (char*)ADDR(0x64d8b4), 0xc47c);
        *(int*)((char*)(size_t)*(int*)((char*)this + 0x8c)) = (int)(size_t)a;
    }
    {
        T41E5D0Entry* b = new T41E5D0Entry(*(int*)((char*)this + 0x80),
                                           (char*)ADDR(0x64d8a8), 0xc47d);
        *(int*)((char*)(size_t)*(int*)((char*)this + 0x8c) + 4) = (int)(size_t)b;
    }
    {
        T41E5D0Entry* c = new T41E5D0Entry(*(int*)((char*)this + 0x80),
                                           (char*)ADDR(0x64d898), 0xc47e);
        *(int*)((char*)(size_t)*(int*)((char*)this + 0x8c) + 8) = (int)(size_t)c;
    }
    {
        int i = 0;
        for (; i < *(short*)((char*)this + 0x88); i++)
        {
            C_cluster_5207B0* e = (C_cluster_5207B0*)(size_t)
                *(int*)((char*)(size_t)*(int*)((char*)this + 0x8c) + i * 4);
            if (e != 0)
                e->M_5207B0(0, -1, 0);
        }
    }
    return 1;
#endif
}


// 0x41EA60 — post-screen init. WIP success contract.
// 0x4B9B30 constructs the 0x7E4 dialog object and installs vtable 0x622F54; its
// real body is matched in Source/ui/free_ui.cpp, so the stub ctor below only
// keeps the VC6 EH frame by calling an external hook (the hook is empty here).
extern void __cdecl Hook_41EA60Ctor(void* p, char* a1);
class T41EA60Dialog {
public:
    char pad_00[0x7e4];
    T41EA60Dialog(char* a1);
    int M_4B9B60(int a1, int a2, int a3, int a4);
};
T41EA60Dialog::T41EA60Dialog(char* a1)
{
    Hook_41EA60Ctor(this, a1);
}
void __cdecl Hook_41EA60Ctor(void* p, char* a1)
{
    (void)p; (void)a1;
}
int T41EA60Dialog::M_4B9B60(int a1, int a2, int a3, int a4)
{
    (void)a1; (void)a2; (void)a3; (void)a4;
    return 1;
}

// Minimal shapes of the shared owner classes whose matched methods are called
// from 0x41EA60: the 0x49F770 registration manager and the 0x422420 +0x420
// marker.
class S49F770 {
public:
    int M_49F770(int a1, int a2);
};
class S422420 {
public:
    char pad_00[0x420];
    int field_420;                 // +0x420
    void Mark_422420();
};
extern void (__stdcall *g_61C2F4)(int a1, int a2, int a3, int a4);

// 0x41EA60 (slot +0xB0) — allocate the 0x7E4 dialog through `new` from the
// 0x64D694 name, run its 0x4B9B60 four-argument setup with the +0x6C pointer,
// register the name through the 0x49F770 manager at 0x66EA48, mark the +0x420
// global state via 0x422420, and send (hwnd, 0xF, 0, 0) through the 0x61C2F4
// callback; the two setup failures return 0 and success returns 1.
MATCH_FUNC(0x41EA60)
int C_vt61DF78::slot44_41EA60()
{
    T41EA60Dialog* p = new T41EA60Dialog((char*)ADDR(0x64d694));
    if (p == 0)
        return 0;
    if (!p->M_4B9B60(*(int*)((char*)this + 0x6c), 0, -1, 0))
        return 0;
#ifdef MATCHED_NATIVE
    // 0x66EA48 and 0x61C2F4 still hold raw guest words in the native image, and
    // the 0x49F770/0x422420 matched bodies dereference guest-owned pointers; the
    // bring-up path only needs the allocated dialog and its setup call.
    (void)ADDR(0x66ea48);
#else
    ((S49F770*)ADDR(0x66ea48))->M_49F770((int)(size_t)ADDR(0x64d694), 0);
    ((S422420*)this)->Mark_422420();
    g_61C2F4(*(int*)((char*)this + 0x28), 0xf, 0, 0);
#endif
    return 1;
}

// 0x41E760 (slot +0xA4) — basegame::setup_fonts. +0x208 = 0x24 fonts,
// +0x20C = calloc(0x24, 0xC) table of {font, aveCharWidth, height}; get the DC
// of the +0x6C draw area (0x45FE50 with the "basegame::setup_fonts" tag), and
// for each index build the font through 0x41EEE0(dc, id, flag) (id table in
// the switch; index 5 has none), select it, GetTextMetricsA, store font /
// tmAveCharWidth / tmHeight + (tmExternalLeading ? : 1), restore the old
// object; release the DC (0x45FEA0) and return 1 (0 when calloc or the DC
// fail). The native build keeps the old success contract.
// WIP: 619/619 bytes, every instruction identical except the three table
// stores, where the original encodes the SIB as [offset + base]
// (`mov [eax+ecx], edi`, `[eax+edx+4]`, `[eax+edx+8]`) and VC6 here emits
// [base + offset]. Tried: typed pointer field via a view struct, int field
// cast per store, i[p], (char*)(i*12) + base, i*12 + base and base + i*12 in
// int/unsigned arithmetic, an `int k = i` / unsigned / unsigned short / long
// index, cached and per-store reloaded table pointers, `lead` temp for the
// height. None changes the operand order.
#ifndef MATCHED_NATIVE
class TDrawArea {
public:
    int GetDC_45FE50(int unused);
    void ReleaseDC_45FEA0(int unused);
};
class T41EEE0 {
public:
    int M_41EEE0(int dc, int id, int flag);
};
struct TTextMetric41E {
    int height, ascent, descent, intLeading, extLeading, aveWidth, maxWidth,
        weight, overhang, aspX, aspY;
    char first, last, def, brk, italic, under, strike, pitch, charset;
};
struct TFontEntry41E { int font; int aveWidth; int height; };
extern "C" __declspec(dllimport) int __stdcall SelectObject(int dc, int obj);
extern "C" __declspec(dllimport) int __stdcall GetTextMetricsA(int dc, TTextMetric41E* tm);
#endif
WIP_FUNC(0x41E760)
int C_vt61DF78::slot41_41E760()
{
#ifdef MATCHED_NATIVE
    return 1;
#else
    short i;
    TTextMetric41E tm;
    *(short*)((char*)this + 0x208) = 0x24;
    *(int*)((char*)this + 0x20c) = (int)(size_t)sub_5F8FF0(0x24, 0xc);
    if (*(int*)((char*)this + 0x20c) == 0)
        return 0;
    int dc = (*(TDrawArea**)((char*)this + 0x6c))->GetDC_45FE50((int)(size_t)ADDR(0x64d8c0));
    if (dc == 0)
        return 0;
    for (i = 0; i < *(short*)((char*)this + 0x208); i++)
    {
        int font;
        switch (i)
        {
            case 0: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x6e, 0); break;
            case 1: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x71, 0); break;
            case 2: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x86, 0); break;
            case 3: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x89, 0); break;
            case 4: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x74, 0); break;
            case 6: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x83, 0); break;
            case 7: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x77, 0); break;
            case 8: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x80, 1); break;
            case 9: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x7a, 0); break;
            case 10: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x7d, 0); break;
            case 11: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x80, 0); break;
            case 12: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x8c, 0); break;
            case 13: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x8f, 0); break;
            case 14: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x92, 0); break;
            case 15: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x95, 0); break;
            case 16: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x98, 0); break;
            case 17: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x9b, 0); break;
            case 18: font = ((T41EEE0*)this)->M_41EEE0(dc, 0x9e, 0); break;
            case 19: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xa1, 0); break;
            case 20: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xa4, 0); break;
            case 21: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xa7, 0); break;
            case 22: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xaa, 0); break;
            case 23: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xad, 0); break;
            case 24: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xb0, 0); break;
            case 25: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xb3, 0); break;
            case 26: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xb6, 0); break;
            case 33: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xcb, 0); break;
            case 34: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xce, 0); break;
            case 35: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xd1, 0); break;
            case 27: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xb9, 0); break;
            case 28: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xbc, 1); break;
            case 29: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xbf, 0); break;
            case 30: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xc2, 0); break;
            case 31: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xc5, 0); break;
            case 32: font = ((T41EEE0*)this)->M_41EEE0(dc, 0xc8, 0); break;
            default:
                continue;
        }
        if (font != 0)
        {
            int old = SelectObject(dc, font);
            GetTextMetricsA(dc, &tm);
            (*(TFontEntry41E**)((char*)this + 0x20c))[i].font = font;
            (*(TFontEntry41E**)((char*)this + 0x20c))[i].aveWidth = tm.aveWidth;
            (*(TFontEntry41E**)((char*)this + 0x20c))[i].height =
                tm.height + (tm.extLeading != 0 ? tm.extLeading : 1);
            SelectObject(dc, old);
        }
    }
    (*(TDrawArea**)((char*)this + 0x6c))->ReleaseDC_45FEA0((int)(size_t)ADDR(0x64d8c0));
    return 1;
#endif
}

// 0x420D10 — window child/scroll init. WIP success contract.
// 0x45EDE0's owner object, shared with Source/gfx/free_gfx.cpp: only the two
// pair fields and the four-argument method are needed by 0x420D10.
class S45EDE0 {
public:
    char pad_00[0x2c];
    int field_2c;                   // +0x2C pair A
    int field_30;                   // +0x30 pair B
    void M_45EDE0(int a1, int a2, int a3, int a4);
};

// 0x420D10 (slot +0x0FC) — the display-object update path: when arg3 is one it
// returns immediately; otherwise it forwards the four arguments to the +0x68
// device object, copies that object's +0x2C/+0x30 pair into config +0x8E4/+0x8E8,
// and when the 0x49F620 global object exists, passes the pair to its +0x50
// virtual slot. The +0x138 base slot is then dispatched and the call returns 1.
MATCH_FUNC(0x420D10)
int C_vt61DF78::slot63_420D10(int a1, int a2, int a3, int a4)
{
    if (a3 == 1)
        return 1;
    S45EDE0* dev = *(S45EDE0**)((char*)this + 0x68);
    if (dev != 0)
    {
        dev->M_45EDE0(a1, a2, a3, a4);
        dev = *(S45EDE0**)((char*)this + 0x68);
        if (dev != 0)
        {
            int a = dev->field_2c;
            if (a != 0)
            {
                *(int*)(*(int*)((char*)this + 0x24) + 0x8e4) = a;
                *(int*)(*(int*)((char*)this + 0x24) + 0x8e8) =
                    (*(S45EDE0**)((char*)this + 0x68))->field_30;
            }
        }
        if (((S49F620Global*)ADDR(0x66ea48))->Get_49F620() != 0)
        {
            T49F620Result* res =
                ((S49F620Global*)ADDR(0x66ea48))->Get_49F620();
            int cfg = *(int*)((char*)this + 0x24);
            res->Vt_14(*(int*)(cfg + 0x8e4), *(int*)(cfg + 0x8e8));
        }
    }
#ifdef MATCHED_NATIVE
    // The +0x138 base slot is beyond the native vtable replica's populated
    // slots (it still holds raw guest words); the bring-up path does not need
    // that dispatch, so only the VC6 body emits it for the byte match.
#else
    slot_078();
#endif
    return 1;
}

// 0x422340's 0x208 screen/state object: the ctor at 0x45F8E0 and the two
// member calls at 0x45FB60/0x45FA20 are still lifted, so this TU models the
// class shape with a non-trivial ctor (to keep the original VC6 EH frame) and
// success-contract stubs. M_45FB60 returns 1 here so the native bring-up takes
// the original success branch.
extern void __cdecl Hook_422340Ctor(void* p, char* a1, int a2);
class T422340Screen {
public:
    char pad_00[0x208];
    T422340Screen(char* a1, int a2);
    int M_45FB60(int a1, int a2, int a3, int a4, int a5);
    void M_45FA20();
};
T422340Screen::T422340Screen(char* a1, int a2)
{
    Hook_422340Ctor(this, a1, a2);
}
void __cdecl Hook_422340Ctor(void* p, char* a1, int a2)
{
    (void)p; (void)a1; (void)a2;
}
int T422340Screen::M_45FB60(int a1, int a2, int a3, int a4, int a5)
{
    (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    return 1;
}
void T422340Screen::M_45FA20()
{
}

// 0x422340 (slot +0x154) — allocate the 0x208 screen/state object with the
// 0x64DAA8 name, store it at +0x10A0, then run the 0x45FB60 five-argument mode
// call with +0x68; a zero result destroys/frees the object, clears +0x10A0 and
// returns 0, otherwise returns 1.
MATCH_FUNC(0x422340)
int C_vt61DF78::slot85_422340()
{
    T422340Screen* p = new T422340Screen((char*)ADDR(0x64daa8), 0);
    *(int*)((char*)this + 0x10a0) = (int)(size_t)p;
    if (p == 0)
        return 0;
    if (!p->M_45FB60(*(int*)((char*)this + 0x68), 0x18a, 0xc6, 0, 0))
    {
        T422340Screen* old = (T422340Screen*)(size_t)*(int*)((char*)this + 0x10a0);
        if (old != 0)
        {
            old->M_45FA20();
            sub_5F90B0(old);
        }
        *(int*)((char*)this + 0x10a0) = 0;
        return 0;
    }
    return 1;
}

// 0x41F200 / 0x41F3A0 / 0x41F0C0 / 0x465270 — startup gates. The native build
// keeps their old success contracts (return 1); the VC6 bodies are the
// original logic.
//
// 0x41F200 — expiry gate (config +0x87C). mktime (0x5FD839) of the config
// date (+0x880 month, +0x882 day, +0x884 year) against time (0x5FD3A5); the
// registry path is the first 9 chars of config +0x418 plus "X", the value
// "DT2". After the date: `new` the 0x110 registry object (0x4BDE90), set DT2
// = 1 unless it already reads 1, destroy (0x4BDF10) + free, return 0. Before
// it: return 0 when DT2 already reads 1 (or the allocation fails: 1), else 1.
#ifndef MATCHED_NATIVE
struct TTm41F200 { int sec, min, hour, mday, mon, year, wday, yday, isdst; };
extern int __cdecl sub_5FD839(TTm41F200* tm);   // mktime
extern int __cdecl sub_5FD3A5(int* t);          // time
class T41F200Reg {
public:
    char pad_00[0x110];
    T41F200Reg(char* key);     // 0x4BDE90
    ~T41F200Reg();             // 0x4BDF10
};
#endif
MATCH_FUNC(0x41F200)
int C_vt61DF78::M_41F200()
{
#ifdef MATCHED_NATIVE
    return 1;
#else
    int now;
    char name[8];
    char path[0x14];
    TTm41F200 tm;
    for (int i = 0; i < 9; i++)
        ((int*)&tm)[i] = 0;
    tm.mon = *(short*)(*(int*)((char*)this + 0x24) + 0x880) - 1;
    tm.mday = *(short*)(*(int*)((char*)this + 0x24) + 0x882);
    tm.year = *(short*)(*(int*)((char*)this + 0x24) + 0x884);
    int expiry = sub_5FD839(&tm);
    sub_5FD3A5(&now);
    sub_5FCB40(path, (char*)(*(int*)((char*)this + 0x24) + 0x418), 9);
    path[9] = 'X';
    path[10] = 0;
    name[0] = 'D';
    name[1] = 'T';
    name[2] = '2';
    name[3] = 0;
    if (now > expiry)
    {
        T41F200Reg* reg = new T41F200Reg(path);
        if (reg == 0)
            return 0;
        if (((S4BE080*)reg)->M_4BE080(0, (int)name) != 1)
            ((S4BDF50*)reg)->M_4BDF50(0, (int)name, 1);
        delete reg;
        return 0;
    }
    T41F200Reg* reg = new T41F200Reg(path);
    if (reg == 0)
        return 1;
    if (((S4BE080*)reg)->M_4BE080(0, (int)name) == 1)
    {
        delete reg;
        return 0;
    }
    delete reg;
    return 1;
#endif
}
// 0x41F3A0 should only be reached when the device path is active; it
// checks the shell: seed +0x38 through the 0x61C190 slot, compare the 0x61C188
// version with 0xB7, then on that version find the window by the className/
// windowName config strings (0x61C2F0) and either run the 0x422180 name check
// plus the 0x61C2F4 message and 0x61C198 destroy path, or the 0x61C2A0 detail
// chain (0x61C2FC/0x61C2A4/0x61C2A8/0x61C2AC), finally clearing +0x38 through
// 0x61C198/0x61C1A8. Success returns 1; the found-window cleanup returns 0.
class Sc422180 {
public:
    char pad_00[0x24];
    bool M_422180(int a1);
};
MATCH_FUNC(0x41F3A0)
int C_vt61DF78::M_41F3A0()
{
#ifdef MATCHED_NATIVE
    return 1;
#else
    int cfg = *(int*)((char*)this + 0x24);
    int version;
    *(int*)((char*)this + 0x38) =
        (*(int (__stdcall**)(int, int, int))ADDR(0x61c190))(0, 1, cfg);
    version = (*(int (__stdcall**)())ADDR(0x61c188))();
    if (version == 0xb7)
    {
        int found;
        cfg = *(int*)((char*)this + 0x24);
        found = (*(int (__stdcall**)(int, char*))ADDR(0x61c2f0))(
            cfg, (char*)(cfg + 0x7a));
        if (found != 0)
        {
            if (((Sc422180*)this)->M_422180((int)(size_t)ADDR(0x64d8e8)))
            {
                (*(int (__stdcall**)(int, int, int, int))ADDR(0x61c2f4))(
                    found, 0x10, 0, 0);
                if (*(int*)((char*)this + 0x38) != 0)
                    (*(int (__stdcall**)(int))ADDR(0x61c198))(
                        *(int*)((char*)this + 0x38));
                return 1;
            }
            if ((*(int (__stdcall**)(int))ADDR(0x61c2a0))(found) != 0)
                (*(int (__stdcall**)(int, int))ADDR(0x61c2fc))(
                    found, 1);
            (*(int (__stdcall**)(int))ADDR(0x61c2a4))(found);
            (*(int (__stdcall**)(int))ADDR(0x61c2ac))(
                (*(int (__stdcall**)(int))ADDR(0x61c2a8))(found));
        }
        if (*(int*)((char*)this + 0x38) != 0)
        {
            (*(int (__stdcall**)(int))ADDR(0x61c198))(
                *(int*)((char*)this + 0x38));
            (*(int (__stdcall**)(int))ADDR(0x61c1a8))(
                *(int*)((char*)this + 0x38));
            *(int*)((char*)this + 0x38) = 0;
        }
        return 0;
    }
    if (*(int*)((char*)this + 0x38) != 0)
        (*(int (__stdcall**)(int))ADDR(0x61c198))(
            *(int*)((char*)this + 0x38));
    return 1;
#endif
}
// 0x41F0C0 — CD check (config +0x408 enables it; else 1). With a1 > 0: count
// the slots 1..9 where the +0x1B0 object's 0x42D580(slot) == 2 and this
// object's 0x421860(slot-1) holds, and return a1 <= count * cfg +0x40C.
// Otherwise 1 when 0x66456C is set; else read the CD root from the registry
// (+0x1D4 -> 0x4BE010 with 0x64D83C), require GetDriveTypeA == DRIVE_CDROM
// and GetVolumeInformationA, and return whether the volume label equals
// config +0x2FD (0x5FF460 _stricmp).
#ifndef MATCHED_NATIVE
class S42D580 { public: int M_42D580(int a1); };
class S421860 { public: int M_421860(int index); };
extern int __cdecl sub_5FF460(char* a1, char* a2);
extern "C" __declspec(dllimport) unsigned int __stdcall GetDriveTypeA(char* root);
extern "C" __declspec(dllimport) int __stdcall GetVolumeInformationA(char* root,
    char* volName, unsigned int volNameSize, unsigned long* serial,
    unsigned long* maxLen, unsigned long* flags, char* fsName, unsigned int fsNameSize);
#endif
MATCH_FUNC(0x41F0C0)
int C_vt61DF78::M_41F0C0(int a1)
{
#ifdef MATCHED_NATIVE
    (void)a1;
    return 1;
#else
    unsigned long serial;
    unsigned long flags;
    unsigned long maxLen;
    char volName[0x100];
    char fsName[0x100];
    if (*(int*)(*(int*)((char*)this + 0x24) + 0x408) == 0)
        return 1;
    if (a1 > 0)
    {
        int n = 0;
        for (int i = 0; i < 9; i++)
        {
            if ((*(S42D580**)((char*)this + 0x1b0))->M_42D580(i + 1) == 2
                && ((S421860*)this)->M_421860(i))
                n++;
        }
        return a1 <= *(int*)(*(int*)((char*)this + 0x24) + 0x40c) * n;
    }
    if (*(int*)ADDR(0x66456c) != 0)
        return 1;
    char* root = (char*)(*(S4BE010**)((char*)this + 0x1d4))
                     ->M_4BE010(0, (int)(size_t)ADDR(0x64d83c));
    if (root == 0)
        return 0;
    if (GetDriveTypeA(root) != 5)
        return 0;
    if (!GetVolumeInformationA(root, volName, 0x100, &serial, &maxLen, &flags,
                               fsName, 0x100))
        return 0;
    return sub_5FF460(volName, (char*)(*(int*)((char*)this + 0x24) + 0x2fd)) == 0;
#endif
}

// 0x465270 — DirectPlay version gate. DirectPlayCreate(GUID_NULL copy) and
// QueryInterface for IID 0x62E378 (either failing returns 0), release the
// first interface, then read dplayx's VS_FIXEDFILEINFO (GetModuleHandleA,
// GetModuleFileNameA, GetFileVersionInfoSizeA, GlobalAlloc/Lock,
// GetFileVersionInfoA, VerQueryValueA "\\"), format it with 0x5FCE14
// ("DPlay Version found: %d.%d.%d.%d") and accept > 5.x, 5.0 >= .2046,
// 4.8+, 4.7 > .0.177, 4.6 >= .3.516, or exactly 1.2.3.12. Releases the
// queried interface and returns the flag.
#ifndef MATCHED_NATIVE
struct TGuid465 { unsigned long d1; unsigned short d2; unsigned short d3; unsigned char d4[8]; };
extern TGuid465 g_642f88;      // GUID_NULL
extern TGuid465 g_62e378;      // DirectPlay interface IID probed
class TDPlay465 {
public:
    virtual long __stdcall QueryInterface(TGuid465* iid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct TFixedFileInfo465 {
    unsigned long sig, strucVer, fileVerMS, fileVerLS;
};
extern int __cdecl sub_5FCE14(char* dst, char* fmt, ...);
// Called through the 0x5ECE26..0x5ECE4A import thunks, so not dllimport.
extern "C" long __stdcall DirectPlayCreate(TGuid465* guid, TDPlay465** dp, void* outer);
extern "C" unsigned long __stdcall GetFileVersionInfoSizeA(char* file, unsigned long* handle);
extern "C" int __stdcall GetFileVersionInfoA(char* file, unsigned long handle,
                                             unsigned long len, void* data);
extern "C" int __stdcall VerQueryValueA(void* block, char* sub, void** buf, unsigned int* len);
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(char* name);
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* mod, char* buf,
                                                                          unsigned long size);
extern "C" __declspec(dllimport) void* __stdcall GlobalAlloc(unsigned int flags, unsigned long size);
extern "C" __declspec(dllimport) void* __stdcall GlobalLock(void* mem);
extern "C" __declspec(dllimport) int __stdcall GlobalUnlock(void* mem);
extern "C" __declspec(dllimport) void* __stdcall GlobalFree(void* mem);
#endif
MATCH_FUNC(0x465270)
int sub_465270()
{
#ifdef MATCHED_NATIVE
    return 1;
#else
    unsigned char ok;
    TDPlay465* dp;
    TFixedFileInfo465* info;
    TDPlay465* dp2;
    unsigned long handle;
    unsigned int len;
    void* mem;
    TGuid465 guid;
    char path[0x100];
    char text[0x100];

    dp2 = 0;
    guid = g_642f88;
    if (DirectPlayCreate(&guid, &dp, 0) != 0)
        return 0;
    if (dp != 0)
    {
        if (dp->QueryInterface(&g_62e378, (void**)&dp2) != 0)
            return 0;
        dp->Release();
    }
    ok = 0;
    len = 0;
    info = 0;
    void* mod = GetModuleHandleA((char*)ADDR(0x652bb0));
    if (mod != 0)
    {
        GetModuleFileNameA(mod, path, 0x100);
        unsigned long size = GetFileVersionInfoSizeA(path, &handle);
        if (size != 0)
        {
            mem = GlobalAlloc(2, size);
            if (mem != 0)
            {
                void* data = GlobalLock(mem);
                if (data != 0)
                {
                    GetFileVersionInfoA(path, handle, size, data);
                    if (VerQueryValueA(data, (char*)ADDR(0x651100), (void**)&info, &len))
                    {
                        unsigned short build = (unsigned short)info->fileVerLS;
                        unsigned short major = (unsigned short)(info->fileVerMS >> 16);
                        unsigned short minor = (unsigned short)info->fileVerMS;
                        unsigned short rel = (unsigned short)(info->fileVerLS >> 16);
                        sub_5FCE14(text, (char*)ADDR(0x652b3c), major, minor, rel, build);
                        if (major > 5)
                            ok = 1;
                        if (major == 5)
                        {
                            if (minor > 0 || rel >= 0x7fe)
                                ok = 1;
                            else
                                ok = 0;
                        }
                        else if (major == 4)
                        {
                            if (minor > 7)
                                ok = 1;
                            if (minor == 7)
                            {
                                if (rel > 0 || build > 0xb1)
                                    ok = 1;
                                else
                                    ok = 0;
                            }
                            else if (minor == 6)
                            {
                                if ((rel == 3 && build >= 0x204) || rel > 3)
                                    ok = 1;
                                else
                                    ok = 0;
                            }
                        }
                        else if (major == 1)
                        {
                            if (minor == 2 && rel == 3 && build == 0xc)
                                ok = 1;
                        }
                    }
                    GlobalUnlock(mem);
                }
                GlobalFree(mem);
            }
        }
    }
    dp2->Release();
    return ok;
#endif
}

// 0x41BC80 (slot +0x74) — real device/window/menu bring-up. This is the full
// original control flow: timeGetTime seed, registry resolution/option reads,
// the +0x158 order/name call, the 0x41F200/0x41F3A0/0x422180/0x465270 gates,
// SystemParametersInfoA mouse-speed probes, 0x41F0C0, the +0x7C/+0x80/+0x84
// window init slots, the +0xAC/+0x154/+0x8C/+0xA0/+0x98/+0x9C/+0xA4/+0xA8
// screen init slots, the 0x274 object at +0x1B0, +0xB0/+0x0C/+0xB4/+0xFC, the
// ShowWindow/SetFocus/SetTimer window show, and the +0x1C/+0x20 path objects.
// Every large init slot is a WIP success contract here; window creation and
// the two menu-screen allocations are real.
//
// VC6 path (#ifndef MATCHED_NATIVE): the complete original logic, recovered
// from the asm. Corrections vs the host body: the slots are virtual calls in
// this order: +0x78, +0x158, +0x7C(5) +0x80(6) +0x84(7 if unset) +0x88(0x11)
// +0xAC(7) +0x154(7) +0x8C(8) +0xA0(0xA) +0x98(0x10) +0x9C(9) +0xA4(0xB)
// +0xA8(0xC), new 0x462B50 -> 0x664514 (not +0x1B0), +0xB0(0xD), +0x0C(0),
// +0xB4, +0xFC(hwnd,0,0,0); speed key absent -> 0x4BD830 + rand() written back
// to the registry, 0x421F90(band 1/2/3) and the +0x8F8 word saved; LoadLibraryA
// fail = code 1; GlobalMemoryStatus < 28MB = code 0x17, < 62MB with
// AvailPhys+AvailPageFile < 64MB sets 0x664538; SPI(0x53)/(0x55) for +0x58;
// the tail sprintf/strcpy's the 0x409A10 name, calls 0x4378C0, news
// 0x4647C0 (+0x1C) and 0x4CFAC0 (+0x20) and fopen()s the 0x66457C log.
// Status (ours 1706 vs 1700 bytes): identical through 0x4E4 and the shared
// epilogue. Remaining diff is the EH-state resets after the 0x462B50 and
// 0x4647C0 news: VC6 caches -1 in esi (`or esi,-1; mov [esp+0x13c],esi`,
// 0x664514 stored before the test) where the original stores the immediate,
// plus the knock-on edx-vs-eax pick for 0x664520->+0x160C and the sprintf
// argument registers. Tried for that: local for the new result, assignment
// inside the if, typed extern global, separate/merged int locals.
// NOTE: in a one-function scratch TU VC6 instead clones the EH epilogue into
// every `return 0` (2096 bytes); in this full TU it shares one epilogue as
// the original does, so always measure this function in the real file.
// The `avail` local (PageFile + Phys) is what gives `add eax,edx`.
WIP_FUNC(0x41BC80)
int C_vt61DF78::slot29_41BC80()
{
#ifndef MATCHED_NATIVE
    MemStatApp ms;
    char buf[0x104];
    sub_5FCA3B(timeGetTime());
    switch (APPV->reg_1d4->M_4BE080(1, (const char*)ADDR(0x64d67c)))
    {
    case 0x280:
    case 0x320:
        APPV->cfg_24->f8f4 = 0x320;
        APPV->cfg_24->f8fc = 0x258;
        break;
    case 0x400:
        APPV->cfg_24->f8f4 = 0x400;
        APPV->cfg_24->f8fc = 0x300;
        break;
    case 0x500:
        APPV->cfg_24->f8f4 = 0x500;
        APPV->cfg_24->f8fc = 0x400;
        break;
    }
    int speed = APPV->reg_1d4->M_4BE080(1, (const char*)ADDR(0x64d664));
    if (speed != -1)
    {
        APPV->M_421F90(speed);
    }
    else
    {
        int cpu = APPV->reg_1d4->M_4BE080(0, (const char*)ADDR(0x64d654));
        if (cpu == -1)
        {
            sub_4BD830();
            cpu = sub_5FCA14_rand();
            APPV->reg_1d4->M_4BDF50(0, (const char*)ADDR(0x64d654), cpu);
        }
        if (cpu < 0xd2)
            APPV->M_421F90(1);
        else if (cpu < 0x136)
            APPV->M_421F90(2);
        else
            APPV->M_421F90(3);
        APPV->reg_1d4->M_4BDF50(1, (const char*)ADDR(0x64d664), APPV->cfg_24->w8f8);
    }
    if (APPV->reg_1d4->M_4BE080(1, (const char*)ADDR(0x64d644)) == 2)
        APPV->fb48 = 0;
    else
        APPV->fb48 = 1;
    int v = APPV->reg_1d4->M_4BE080(1, (const char*)ADDR(0x64d638));
    if (v == 2)
        APPV->cfg_24->w8e0 = 2;
    else if (v == 1)
        APPV->cfg_24->w8e0 = 1;
    v = APPV->reg_1d4->M_4BE080(1, (const char*)ADDR(0x64d62c));
    if (v > 0 && v <= 0xa0)
        APPV->f108c = v * *(float*)ADDR(0x61e0d4);
    v = APPV->reg_1d4->M_4BE080(1, (const char*)ADDR(0x64d61c));
    if (v > 0 && v <= 0x14)
        APPV->f9cc = v * *(float*)ADDR(0x61e0d4);
    v = APPV->reg_1d4->M_4BE080(1, (const char*)ADDR(0x64d610));
    if (v >= 1 && v <= 5)
        APPV->f1090 = v - 1;
    v = APPV->reg_1d4->M_4BE080(1, (const char*)ADDR(0x64d600));
    if (v >= 10 && v <= 200)
    {
        APPV->cfg_24->f8cc = v;
        APPV->cfg_24->f8d4 = v;
    }
    if (!APPV->v30())
    {
        APPV->field_60 = 2;
        return 0;
    }
    *(void**)ADDR(0x664510) = LoadLibraryA(APPV->dll_315);
    if (*(void**)ADDR(0x664510) == 0)
    {
        APPV->field_60 = 1;
        return 0;
    }
    GlobalMemoryStatus(&ms);
    if (ms.dwTotalPhys < 0x1c00000)
    {
        APPV->field_60 = 0x17;
        return 0;
    }
    if (ms.dwTotalPhys < 0x3e00000)
    {
        unsigned long avail = ms.dwAvailPageFile + ms.dwAvailPhys;
        if (avail < 0x4000000)
            *(int*)ADDR(0x664538) = 1;
    }
    APPV->v86();
    if (APPV->cfg_24->f87c && !M_41F200())
    {
        APPV->field_60 = 3;
        return 0;
    }
    if (APPV->cfg_24->f88c && !M_41F3A0())
    {
        APPV->field_60 = 4;
        return 0;
    }
    if (!APPV->M_422180((const char*)ADDR(0x64d5f4)) && !sub_465270())
    {
        APPV->field_60 = 0x14;
        return 0;
    }
    SystemParametersInfoA(0x10, 0, &APPV->f54, 0);
    if (APPV->f54)
        SystemParametersInfoA(0x11, 0, 0, 2);
    SystemParametersInfoA(0x53, 0, &APPV->f58, 0);
    if (APPV->f58)
        SystemParametersInfoA(0x55, 0, 0, 2);
    APPV->f9e0 = M_41F0C0(0);
    if (!APPV->v31()) { APPV->field_60 = 5; return 0; }
    if (!APPV->v32()) { APPV->field_60 = 6; return 0; }
    if (!APPV->v33())
    {
        if (!APPV->field_60)
            APPV->field_60 = 7;
        return 0;
    }
    if (!APPV->v34()) { APPV->field_60 = 0x11; return 0; }
    if (!APPV->v43()) { APPV->field_60 = 7; return 0; }
    if (!APPV->v85()) { APPV->field_60 = 7; return 0; }
    if (!APPV->v35()) { APPV->field_60 = 8; return 0; }
    if (!APPV->v40()) { APPV->field_60 = 0xa; return 0; }
    if (!APPV->v38()) { APPV->field_60 = 0x10; return 0; }
    if (!APPV->v39()) { APPV->field_60 = 9; return 0; }
    if (!APPV->v41()) { APPV->field_60 = 0xb; return 0; }
    if (!APPV->v42()) { APPV->field_60 = 0xc; return 0; }
    *(T462B50**)ADDR(0x664514) = new T462B50();
    if (*(T462B50**)ADDR(0x664514) == 0)
        return 0;
    if (!APPV->v44()) { APPV->field_60 = 0xd; return 0; }
    APPV->v3(0);
    APPV->v45();
    APPV->v63((int)APPV->hwnd_28, 0, 0, 0);
    APPV->f2c = 1;
    ShowWindow(APPV->hwnd_28, 5);
    UpdateWindow(APPV->hwnd_28);
    APPV->M_41F8B0();
    APPV->f64 = SetTimer(APPV->hwnd_28, 1, 0x32, 0);
    v = APPV->M_409A10();
    if (v > 0)
        sub_5FCE14_sprintf(buf, (const char*)ADDR(0x64d5e4), v);
    else
        strcpy(buf, (const char*)ADDR(0x64d5d8));
    sub_4378C0((*(S664520App**)ADDR(0x664520))->f160c, 5, (const char*)ADDR(0x64d5bc));
    APPV->f1c = new T4647C0(buf);
    sub_5FCE14_sprintf(buf, (const char*)ADDR(0x64d5ac), APPV->cfg_24->path_d44);
    APPV->f20 = new T4CFAC0(buf);
    if (*(int*)ADDR(0x66457c))
    {
        *(void**)ADDR(0x664580) = sub_5FCE01_fopen((const char*)ADDR(0x64d59c), (const char*)ADDR(0x64d5a8));
        if (*(void**)ADDR(0x664580) == 0)
            *(int*)ADDR(0x66457c) = 0;
    }
    return 1;
#else
#ifdef MATCHED_NATIVE
    ++g_cvt_41bc80_hits;
#endif
    // timeGetTime -> 0x5FCA3B seed
    sub_5FCA3B((*(unsigned int (__stdcall**)(void))g_61c3c8)());

    // resolution selection from the registry "+0x???" key
    int res = RegGet(1, (int)(size_t)ADDR(0x64d67c));
    if (res == 0x280 || res == 0x320)
    {
        if (Cfg() != 0) { *(int*)(Cfg() + 0x8f4) = 0x320; *(int*)(Cfg() + 0x8fc) = 0x258; }
    }
    else if (res == 0x400)
    {
        if (Cfg() != 0) { *(int*)(Cfg() + 0x8f4) = 0x400; *(int*)(Cfg() + 0x8fc) = 0x300; }
    }
    else if (res == 0x500)
    {
        if (Cfg() != 0) { *(int*)(Cfg() + 0x8f4) = 0x500; *(int*)(Cfg() + 0x8fc) = 0x400; }
    }

    // game speed option: "..." else default 0xD2, selected into three bands
    int speed = RegGet(1, (int)(size_t)ADDR(0x64d664));
    if (speed != -1)
    {
        g_65E3C0 = speed;
        if (Cfg() != 0) *(short*)(Cfg() + 0x8f8) = (short)speed;
    }
    else
    {
        speed = 0xd2;
    }
    int band = (speed < 0xd2) ? 1 : ((speed < 0x136) ? 2 : 3);
    if (Cfg() != 0) *(short*)(Cfg() + 0x8f8) = (short)band;

    // difficulty flag -> config +0x8E0 word
    int diff = RegGet(1, (int)(size_t)ADDR(0x64d638));
    if (Cfg() != 0)
        *(short*)(Cfg() + 0x8e0) = (diff == 2) ? 2 : 1;

    // unit speed / game speed floats (registry reads, 0x61E0D4 scale)
    int us = RegGet(1, (int)(size_t)ADDR(0x64d62c));
    if (us > 0 && us <= 0xa0)
    {
        *(float*)((char*)this + 0x108c) = (float)us * *(float*)ADDR(0x61e0d4);
    }
    int gs = RegGet(1, (int)(size_t)ADDR(0x64d61c));
    if (gs > 0 && gs <= 0x14)
    {
        *(float*)((char*)this + 0x9cc) = (float)gs * *(float*)ADDR(0x61e0d4);
    }

    // difficulty scale index 1..5 -> +0x1090 = value-1
    int dscale = RegGet(1, (int)(size_t)ADDR(0x64d610));
    if (dscale >= 1 && dscale <= 5)
        *(int*)((char*)this + 0x1090) = dscale - 1;

    // scroll speed 10..200 -> config +0x8CC/+0x8D4
    int scroll = RegGet(1, (int)(size_t)ADDR(0x64d600));
    if (scroll >= 0xa && scroll <= 0xc8 && Cfg() != 0)
    {
        *(int*)(Cfg() + 0x8cc) = scroll;
        *(int*)(Cfg() + 0x8d4) = scroll;
    }

    // +0x78: config parse
    if (!this->C_vt61DF78::slot30_41D070())
    {
        field_60 = 2;
        return 0;
    }

    // LoadLibraryA(config path) — headless boot can skip the DLL load gate.
    g_664510 = 1;

    // GlobalMemoryStatus gates 28MB/62MB; headless memory report is large.
    {
        unsigned int mem[0x10];
        memset(mem, 0, sizeof mem);
        mem[0] = sizeof mem;
        mem[1] = 0x10;                 // 64MB-ish load percentage
        mem[2] = 0x3f00000;            // total physical bytes (>= 0x3E00000)
        Native_GlobalMemoryStatus(mem);
    }

    // +0x158: order/name slot (matched 0x4378C0: no-op)

    // 0x41F200 when config +0x87C is set
    if (CfgI(0x87c) != 0)
    {
        if (!this->M_41F200())
        {
            field_60 = 3;
            return 0;
        }
    }
    // 0x41F3A0 when config +0x88C is set
    if (CfgI(0x88c) != 0)
    {
        if (!this->M_41F3A0())
        {
            field_60 = 4;
            return 0;
        }
    }
    // 0x422180(config +0x5F4 string) else the 0x465270 fallback: the matched
    // body reads the basegame object through the guest +0x24 pointer, which the
    // 64-bit native layout cannot share, so the WIP bring-up takes the success
    // branch and skips the fallback probe.
    (void)0;

    // mouse-speed probes: SystemParametersInfoA(0x10), conditional 0x11
    {
        int ms = 0;
        if (Native_SystemParameters(0x10, 0, &ms, 0) != 0)
        {
            *(int*)((char*)this + 0x54) = ms;
            if (ms != 0)
                Native_SystemParameters(0x11, 0, 0, 2);
        }
        if (Native_SystemParameters(0x10, 0, &ms, 0) != 0)
        {
            *(int*)((char*)this + 0x58) = ms;
            if (ms != 0)
                Native_SystemParameters(0x11, 0, 0, 2);
        }
    }

    // 0x41F0C0(0) -> +0x9E0
    *(int*)((char*)this + 0x9e0) = this->M_41F0C0(0);

    // +0x7C register class, +0x80 create window, +0x84 setup
    if (!this->C_vt61DF78::slot31_41D5D0())
    {
        field_60 = 5;
        return 0;
    }
    if (!this->C_vt61DF78::slot32_41D6A0())
    {
        field_60 = 6;
        return 0;
    }
    if (!this->C_vt61DF78::slot33_41D7F0())
    {
        if (field_60 == 0)
            field_60 = 7;
        return 0;
    }

    // +0xAC early panel bootstrap, +0x154 sound/state, +0x8C, then screens
    if (!this->C_vt61DF78::slot43_41E4A0())
    {
        field_60 = 0x11;
        return 0;
    }
    if (!this->C_vt61DF78::slot85_422340())
    {
        field_60 = 7;
        return 0;
    }
    if (!this->C_vt61DF78::slot35_41DAA0())
    {
        field_60 = 7;
        return 0;
    }
    if (!this->C_vt61DF78::slot40_41E070())
    {
        field_60 = 8;
        return 0;
    }
    if (!this->C_vt61DF78::slot38_41DBA0())
    {
        field_60 = 0x10;
        return 0;
    }
    if (!this->C_vt61DF78::slot39_41DE50())
    {
        field_60 = 9;
        return 0;
    }
    if (!this->C_vt61DF78::slot41_41E760())
    {
        field_60 = 0xb;
        return 0;
    }
    if (!this->C_vt61DF78::slot42_41E5D0())
    {
        field_60 = 0xc;
        return 0;
    }

    // 0x274 pregame object at +0x1B0 / g_664514 (matched 0x462B50 ctor)
    {
        S462B50* obj = (S462B50*)(size_t)sub_5F8F60(0x274);
        if (obj != 0)
        {
            obj->M_462B50();
            *(void**)((char*)this + 0x1b0) = obj;
            *(int*)&g_664514 = (int)(size_t)obj;
        }
        else
            return 0;
    }

    // +0xB0 post-object init
    if (!this->C_vt61DF78::slot44_41EA60())
    {
        field_60 = 0xd;
        return 0;
    }

    // +0x0C SetInt(0) and +0xB4 Init_41EB30
    SetInt_41BC00(0);
    Init_41EB30();

    // +0xFC child/scroll init (0,0,0,window)
    if (!this->C_vt61DF78::slot63_420D10(0, 0, 0, *(int*)((char*)this + 0x28)))
        return 0;    // the original does not raise the status here

    // ShowWindow(hwnd,5), UpdateWindow(hwnd), SetFocus(hwnd), SetTimer(...)
    {
        int hwnd = *(int*)((char*)this + 0x28);
        Native_ShowWindow(hwnd, 5);
        Native_UpdateWindow(hwnd);
        Native_SetFocus(hwnd);
        *(int*)((char*)this + 0x64) = Native_SetTimer(hwnd, 1, 0x32, 0);
    }

    // 0x41F8B0 display helper is still field-dependent; skip.

    // +0x1C / +0x20 path objects (0x4647C0 / 0x4CFAC0) are still lifted. The
    // original also calls 0x5FCE01 to format a startup log path; skip both.
    return 1;
#endif
}

// Support for 0x420450: callees already matched in other TUs (duplicated as
// minimal declarations so the mangled symbols resolve), the guest tick stamp,
// the guest stats-table pointer and the 0x66EA48 accessor owner.
extern int g_664550;                  // last accepted tick stamp (0xFA gate)
extern void* g_6645c4;                // global per-slot stats table object
struct S41C800Stats;
class S41C800Table { public: S41C800Stats* Add_41C800(int index, unsigned value); };
class C_cluster_45F8A0 { public: void M_45F8A0(); };
class C_pnl_btn { public: int M_5C6880(int a1, int a2, int a3, int a4); };
class C_cluster_520CE0 { public: void M_5214E0(); };
class C_vt62C1E0 { public: int Get9AA_4217C0(); };

// 0x420450 — periodic tick housekeeping. Return 0 when +0x2C or +0x28 is
// clear. Otherwise, with +0x30 set, +0x1D8 not 1 and a +0x68 child, refresh
// that child (0x45F8A0) when the tick delta since the guest 0x664550 stamp has
// reached 0xFA, then store the new stamp. With a +0x80 child, seed it through
// M_5C6880(+0x28, 0x113, 0, 0), accumulate the 0x0F stats slot with the tick
// delta, refresh the optional +0x90 child through M_5214E0, and accumulate the
// 0x10 stats slot with its own tick delta. When the 0x66EA48 accessor yields an
// object, call its slot +0x4C. With a +0x1B0 child and a nonzero 0x4217C0 probe
// on this object, run M_427120 on the child and accumulate the 0x0E stats slot.
// Finally dispatch slot 83 when +0x918 is set and slot 84 when +0x91C is set,
// returning 1.
MATCH_FUNC(0x420450)
int C_vt61DF78::M_420450()
{
    int (__cdecl *tick)();
    if (*(int*)((char*)this + 0x2c) == 0 || field_28 == 0)
        return 0;
    tick = ((int (__cdecl**)())g_61c3c8)[0];
    if (field_30 != 0)
    {
        if (*(int*)((char*)this + 0x1d8) != 1)
        {
            if (*(void**)((char*)this + 0x68) != 0)
            {
                int t = tick();
                if ((unsigned int)(t - g_664550) >= 0xfa)
                {
                    ((C_cluster_45F8A0*)(*(void**)((char*)this + 0x68)))->M_45F8A0();
                    g_664550 = t;
                }
            }
        }
    }
    if (*(void**)((char*)this + 0x80) != 0)
    {
        int t = tick();
        ((C_pnl_btn*)(*(void**)((char*)this + 0x80)))->M_5C6880(
            (int)field_28, 0x113, 0, 0);
        ((S41C800Table*)g_6645c4)->Add_41C800(0xf, tick() - t);
        int t2 = tick();
        if (*(void**)((char*)this + 0x90) != 0)
            ((C_cluster_520CE0*)(*(void**)((char*)this + 0x90)))->M_5214E0();
        ((S41C800Table*)g_6645c4)->Add_41C800(0x10, tick() - t2);
    }
    T49F620Result* res = ((S49F620Global*)ADDR(0x66ea48))->Get_49F620();
    if (res != 0)
        res->Vt_13();
    if (*(void**)((char*)this + 0x1b0) != 0)
    {
        if (((C_vt62C1E0*)this)->Get9AA_4217C0() != 0)
        {
            int t = tick();
            ((C_global_66451C*)(*(void**)((char*)this + 0x1b0)))->M_427120();
            ((S41C800Table*)g_6645c4)->Add_41C800(0xe, tick() - t);
        }
    }
    if (*(int*)((char*)this + 0x918) != 0)
        slot_083();
    if (*(int*)((char*)this + 0x91c) != 0)
        slot_084();
    return 1;
}


// ---- 0x41FAC0 window/message handler -------------------------------------
// The original receives the owning C_vt62C1E0 object as its first stack
// argument (0x5BB240 pushes the object together with hwnd/msg/wp/lp), so it is
// a free __stdcall handler rather than a thiscall slot. The message payload is
// spread across four ints: hwnd, msg, wParam, lParam.
#ifdef MATCHED_NATIVE
class C_vt621F64 { public: void M_49FED0(); };
class S49FF20 { public: void M_49FF20(); };
class S45EA60 { public: void Clear_45EA60(); };
#endif
class S49F620 { public: int Get_49F620(); };       // 0x66EA48 accessor owner
class C_cluster_498F00 { public: int M_4998B0(int a1, int a2, int a3, int a4); };
class S41F8B0 { public: void M_41F8B0(); };

extern "C" int __stdcall DefWindowProcA(void* hwnd, unsigned msg, int wp, int lp);
extern "C" int __stdcall IsIconic(void* hwnd);
extern "C" int __stdcall IsWindow(void* hwnd);
extern "C" void* __stdcall GetFocus();
extern "C" void* __stdcall GetParent(void* hwnd);
extern "C" int __stdcall GetKeyState(int vk);
extern "C" void* __stdcall SetCursor(void* cursor);
extern "C" int __stdcall SetClassLongA(void* hwnd, int index, int value);
extern "C" int __stdcall InvalidateRect(void* hwnd, void* rect, int erase);
extern "C" int __stdcall GetWindowThreadProcessId(void* hwnd, int* pid);
extern "C" void __stdcall sub_45E930(void* obj);
extern "C" void __stdcall sub_45E8F0(void);
extern "C" void __stdcall sub_45F6F0(int a1, int a2, int a3);
extern "C" void __stdcall sub_48A610(void);
extern "C" void __stdcall sub_461CE0(int a1, int a2);

// vtable target reached through the 0x66EA48 accessor's +0x48 slot and the
// occasional key notification at +0xEC.
class TMsgSink41 {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
    virtual void Vt_09();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual int Vt_18(int hwnd, int msg, int wp, int lp);   // +0x48
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
    virtual void Vt_59();   // +0xEC
};

// The owning 0x61DF78/0x62C1E0 message-target vtable. Only the slots this
// handler reaches are given real signatures; the placeholders preserve the
// +0x00..+0x10C offsets.
class TWinProcObj {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
    virtual void Vt_09();
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
    virtual void Vt_46();   // +0xB8 recenter helper
    virtual void Vt_47();   // +0xBC restore helper
    virtual void Vt_48();
    virtual void Vt_49();
    virtual void Vt_50();
    virtual void Vt_51();
    virtual void Vt_52();   // +0xD0 no-arg refresh
    virtual int Vt_53(int hwnd, int msg, int wp, int lp);  // +0xD4 mouse
    virtual int Vt_54(int hwnd, int msg, int wp, int lp);  // +0xD8
    virtual int Vt_55(int hwnd, int msg, int wp, int lp);  // +0xDC key/char
    virtual int Vt_56(int hwnd, int msg, int wp, int lp);  // +0xE0
    virtual int Vt_57(int hwnd, int msg, int wp, int lp);  // +0xE4
    virtual int Vt_58(int hwnd, int msg, int wp, int lp);  // +0xE8
    virtual int Vt_59(int hwnd, int msg, int wp, int lp);  // +0xEC focus
    virtual int Vt_60(int hwnd, int msg, int wp, int lp);  // +0xF0 activate
    virtual int Vt_61(int hwnd, int msg, int wp, int lp);  // +0xF4
    virtual int Vt_62(int hwnd, int msg, int wp, int lp);  // +0xF8
    virtual int Vt_63(int hwnd, int msg, int wp, int lp);  // +0xFC size
    virtual int Vt_64(int hwnd, int msg, int wp, int lp);  // +0x100
    virtual int Vt_65(int hwnd, int msg, int wp, int lp);  // +0x104
    virtual int Vt_66(int hwnd, int msg, int wp, int lp);  // +0x108 close
    virtual int Vt_67(int hwnd, int msg, int wp, int lp);  // +0x10C destroy
};

extern unsigned int (__stdcall *cv_61c3c8)();
static int WinTime() { return cv_61c3c8 != 0 ? (int)cv_61c3c8() : 0; }

// 0x41FAC0 — window-procedure message dispatcher for the 0x61DF78/0x62C1E0
// object. The 0x66EA48 accessor's +0x48 slot gets first refusal (it consumes
// WM_MOUSEMOVE/WM_SIZE payloads); panes at +0x80/+0x84 also receive every
// message. The handler then classifies hwnd/msg/wParam/lParam through the full
// WM_ switch: key and char messages (+0xDC), mouse messages (+0xD4/+0xD8),
// activate (+0xF0 with the +0xB8/+0xBC helpers and 0x6645A8 cursor latch),
// focus (+0xEC), close (+0x108), destroy (+0x10C), size (+0xFC), set/window
// position (+0xE0..+0x104), and the 0x664508/0x6645C0/0x6645A8/0x66454C/
// 0x664550/0x6645AC globals. Unhandled routes return DefWindowProcA. WIP: the
// original keeps a 4-byte SEH frame and partitions the switch into nested
// ranges; this reconstruction preserves the branch outcomes but does not
// reproduce the 0x748-byte stack/EH layout.
WIP_FUNC(0x41FAC0)
int __stdcall sub_41FAC0(C_vt62C1E0* a1, int a2, int a3, int a4, int a5)
{
    char* o = (char*)a1;
    int hwnd = a2;
    int msg = a3;
    int wp = a4;
    int lp = a5;
    int v17 = 0;

    if (*(void**)(o + 0x80) != 0)
        ((C_pnl_btn*)*(void**)(o + 0x80))->M_5C6880(hwnd, msg, wp, lp);
    if (*(void**)(o + 0x84) != 0)
        ((C_cluster_498F00*)*(void**)(o + 0x84))->M_4998B0(hwnd, msg, wp, lp);

    if (((S49F620*)ADDR(0x66ea48))->Get_49F620() != 0)
    {
        int v8 = ((S49F620*)ADDR(0x66ea48))->Get_49F620();
        v17 = ((TMsgSink41*)v8)->Vt_18(hwnd, msg, wp, lp);
        if (v17 != 0 && msg != 512 && msg != 275)
            return v17;
    }

    unsigned top = (unsigned)msg;
    switch (top)
    {
    case 0x112:  // WM_SYSCOMMAND-ish payload (61696)
        if (wp != 61696)
            return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
        if (*(int*)(*(int*)(o + 0x24) + 2196) == 0)
            return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
        {
            int iconic = IsIconic(*(void**)(o + 0x28));
            if (iconic)
                return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
            return iconic;
        }
    case 0x113:  // WM_TIMER
        ((TWinProcObj*)o)->Vt_52();
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 0x116:  // WM_SYSTIMER/MENUSELECT? 278
        if (((TWinProcObj*)o)->Vt_61(hwnd, msg, wp, lp))
            return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
        return v17;
    case 0x200:  // WM_MOUSEMOVE
        if (!((TWinProcObj*)o)->Vt_53(hwnd, msg, wp, lp))
            return v17;
        if (*(int*)ADDR(0x664508) != 0)
        {
            if (*(void**)(o + 0x1f8) != 0)
                SetCursor(*(void**)(o + 0x1f8));
            else
            {
                SetCursor(0);
                SetClassLongA(*(void**)(o + 0x28), -12, 0);
                ((S41F8B0*)o)->M_41F8B0();
            }
            *(int*)ADDR(0x664508) = 0;
        }
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 0x20a:  // WM_RBUTTONDOWN? 522
        if (((TWinProcObj*)o)->Vt_54(hwnd, msg, wp, lp))
            return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
        return v17;
    case 0x273:  // WM_COMMAND
        if (((TWinProcObj*)o)->Vt_57(hwnd, msg, wp, lp) == 0)
            return v17;
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 530:
        if (((TWinProcObj*)o)->Vt_62(hwnd, msg, wp, lp) == 0)
            return v17;
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 536:
        if (wp == 0)
            return 1112363332;
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 783:
        if (((TWinProcObj*)o)->Vt_65(hwnd, msg, wp, lp) == 0)
            return v17;
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 785:
        if (((TWinProcObj*)o)->Vt_64(hwnd, msg, wp, lp) == 0)
            return v17;
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 953:
        if (((TWinProcObj*)o)->Vt_58(hwnd, msg, wp, lp) == 0)
            return v17;
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 1024:
        if (((TWinProcObj*)o)->Vt_56(hwnd, msg, wp, lp) == 0)
            return v17;
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 0x100:  // WM_KEYDOWN
    case 0x104:  // WM_SYSKEYDOWN
        if (((TWinProcObj*)o)->Vt_55(hwnd, msg, wp, lp))
            return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
        return v17;
    case 0x101:  // WM_KEYUP
        if (wp == 44 || (wp == 123 && GetKeyState(17) < 0))
        {
            if (*(int*)(o + 0x2c) != 0 && *(int*)(o + 0x30) != 0)
            {
                int v13 = *(int*)(o + 0x68);
                if (v13 != 0 && *(int*)((char*)(size_t)v13 + 12) != 0)
                {
                    if (*(void**)(o + 0x80) != 0)
                        sub_5F8F60(32);
                    sub_461CE0(*(int*)ADDR(0x64d8f0),
                               (int)(size_t)ADDR(0x64d4ec));
                }
            }
        }
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 0x105:  // WM_SYSKEYUP/CAPTURE
        if (wp == 18
            && ((S49F620*)ADDR(0x66ea48))->Get_49F620() != 0)
        {
            int v14 = ((S49F620*)ADDR(0x66ea48))->Get_49F620();
            ((TMsgSink41*)v14)->Vt_59();
        }
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 0x10:  // WM_CLOSE
        if (((TWinProcObj*)o)->Vt_66(hwnd, msg, wp, lp))
            return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
        return v17;
    case 0x0f:  // WM_SETFOCUS
        {
            void* focus = GetFocus();
            if ((focus != *(void**)(o + 0x28)
                 && (focus == 0 || GetParent(focus) != *(void**)(o + 0x28)))
                || ((TWinProcObj*)o)->Vt_59(hwnd, msg, wp, lp))
                return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
            return v17;
        }
    case 5:  // WM_SIZE
        {
            int v12 = *(int*)(o + 0x68);
            if ((v12 != 0 && *(int*)((char*)(size_t)v12 + 80) != 0)
                || ((TWinProcObj*)o)->Vt_63(hwnd, msg, wp, lp))
                return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
            return v17;
        }
    case 6:  // WM_ACTIVATE
        if (*(int*)(o + 0x2c) != 0)
        {
            int right_high = (unsigned short)((unsigned)wp >> 16);
            if ((unsigned short)wp == 0)
            {
                if (IsWindow((void*)(size_t)lp))
                {
                    int pid = GetWindowThreadProcessId(*(void**)(o + 0x28), 0);
                    if (GetWindowThreadProcessId((void*)(size_t)lp, 0) == pid)
                        *(int*)ADDR(0x6645c0) = lp;
                }
                hwnd = a2;
            }
            if (hwnd == *(int*)(o + 0x28) && (unsigned short)wp != 0
                && right_high != 0 && *(int*)ADDR(0x6645c0) != 0)
                *(int*)ADDR(0x6645c0) = 0;
        }
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    case 2:  // WM_DESTROY
        if (((TWinProcObj*)o)->Vt_67(hwnd, msg, wp, lp))
            return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
        return v17;
    case 0x1c:  // WM_ACTIVATEAPP
        if (*(int*)(o + 0x2c) != 0)
        {
            if (wp == 1)
            {
                if (*(int*)ADDR(0x6645a8) != 0)
                {
                    SetCursor(0);
                    SetClassLongA(*(void**)(o + 0x28), -12, 0);
                    if (*(int*)(o + 0x1d8) != 1)
                        ((TWinProcObj*)o)->Vt_47();
                    *(int*)ADDR(0x6645a8) = 0;
                    int v15 = *(int*)(o + 0x68);
                    if (v15 != 0)
                    {
                        sub_45E930((void*)(size_t)v15);
                        ((S45EA60*)(size_t)v15)->Clear_45EA60();
                        ((S422420*)o)->Mark_422420();
                    }
                    ((S49FF20*)ADDR(0x66ea48))->M_49FF20();
                    if (*(int*)(o + 0x1d8) != 1)
                    {
                        if (*(int*)(o + 0x68) != 0)
                        {
                            sub_45E8F0();
                            sub_45F6F0(0, 256, *(int*)(o + 0x68) + 184);
                        }
                        ((S422420*)o)->Mark_422420();
                        InvalidateRect(*(void**)(o + 0x28), 0, 1);
                        *(int*)ADDR(0x66454c) = 10;
                        *(int*)ADDR(0x664550) = WinTime();
                        *(int*)ADDR(0x6645ac) = 1;
                    }
                }
            }
            else if (*(int*)ADDR(0x6645a8) == 0)
            {
                SetClassLongA(*(void**)(o + 0x28), -12, 0);
                if (*(int*)(o + 0x1d8) != 1)
                    ((TWinProcObj*)o)->Vt_46();
                *(int*)ADDR(0x6645a8) = 1;
                if (*(int*)(o + 0x1d8) != 1 && *(int*)(o + 0x1e8) != 0)
                    sub_48A610();
            }
        }
        if (((TWinProcObj*)o)->Vt_60(hwnd, msg, wp, lp))
            return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
        return v17;
    case 19:  // WM_ERASEBKGND? 19
        if (*(int*)(o + 0x2c) != 0)
            ((C_vt621F64*)ADDR(0x66ea48))->M_49FED0();
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    default:
        return DefWindowProcA((void*)(size_t)hwnd, top, wp, lp);
    }
}
