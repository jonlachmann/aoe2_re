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
extern "C" int cv_win_class = 0;     // 0x41D5D0/0x41D6A0 proof counters
extern "C" int cv_win_handle = 0;
extern "C" int cv_de50_hits = 0;
extern "C" int cv_e070_hits = 0;

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
extern int __cdecl sub_5FD716(unsigned char a1);
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

WIP_FUNC(0x41DC80)
int C_vt61DF78::slot37_41DC80()
{
#ifdef MATCHED_NATIVE
    ++g_cvt_slot37_hits;
#endif
    char buf[0x100];
    char* p;
    char* s;
    int c;
    sub_5FCB40(buf, (char*)(cv_config_ptr != 0 ? cv_config_ptr : 0) + 0x518, 0xff);
    buf[0xff] = 0;
    g_61C2D8(buf);

    p = sub_5FD7C3(buf, (char*)ADDR(0x64d834));
    if (p != 0)
    {
        while (*p != ':')
            p = sub_5FD7A5(p, 1);
        s = sub_5FD7A5(p, 1);
        *(char*)ADDR(0x651164) = 0;
        while (1)
        {
            c = *s;
            if (sub_5FD716((unsigned char)c) != 0)
                break;
            if (*s == 0)
                break;
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
        while (1)
        {
            c = *s;
            if (sub_5FD716((unsigned char)c) != 0)
                break;
            if (*s == 0)
                break;
            sub_5FD66E((char*)ADDR(0x66955c), s, 1);
            s = sub_5FD7A5(s, 1);
        }
    }

    S440B40* obj = new S440B40();
    *(int*)((char*)this + 0x1c8) = (int)(size_t)obj;
    if (obj == 0)
        return 0;
    obj->M_440B40(*(int*)((char*)this + 0x1d0));
    obj->M_440B80(g_664540);
    obj->M_440BC0(1);
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

WIP_FUNC(0x41CF70)
int C_vt61DF78::slot01_41CF70()
{
#ifdef MATCHED_NATIVE
    ++g_cvt_slot04_hits;
#endif
    int (__stdcall *translate)(void*) =
        *(int (__stdcall**)(void*))g_61c2e0;
    int (__stdcall *dispatch)(void*) =
        *(int (__stdcall**)(void*))g_61c2dc;
    int msg[7];
    msg[0] = 0;
    msg[1] = 0;
    msg[2] = 0;
    msg[3] = 0;
    msg[4] = 0;
    msg[5] = 0;
    msg[6] = 0;

    while (1)
    {
        if (g_664544 != 0)
            goto peek;
        if (field_30 != 0)
        {
            int mode = field_1D8;
            if (mode == 4 || mode == 2)
            {
                if (field_1B0 == 0)
                    goto peek;
                if (((T41B0*)field_1B0)->M_42D210() == 0)
                    goto peek;
            }
        }

        if (!(*(int (__stdcall**)(void*, int, int, int))g_61c2e4)(msg, 0, 0, 0))
            return msg[2];
        translate(msg);
        dispatch(msg);
        continue;

    peek:
        if ((*(int (__stdcall**)(void*, int, int, int, int))g_61c2e8)(msg, 0, 0, 0, 1) == 0)
            goto idle;
        if (msg[1] == 0x12)
        {
            if (g_6645c8 == 0)
                return msg[2];
            g_6645c8 = 0;
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

// The 0x47C4 / 0x7B0 / 0x5C0 screen shells. Their full constructors
// (0x425750 / 0x5200F0 family) are still lifted, so the WIP bring-up allocates
// and records the objects and vtable-neutral zeroes the shell.
struct TScreen47C4 { char pad[0x47c4]; };
struct TScreen7B0  { char pad[0x7b0]; };
struct TScreen5C0  { char pad[0x5c0]; };

// 0x41D070 — config/option parse. WIP: the original normalises the config
// string, selects the +0x74 startup mode from the +0x894/+0x89c/+0x8a4
// option block and drives the 0x5FCC80 string compares. Keep the success
// contract: leave +0x74 = 0 and return 1.
WIP_FUNC(0x41D070)
int C_vt61DF78::slot30_41D070()
{
    *(int*)((char*)this + 0x74) = 0;
    return 1;
}

// 0x41D5D0 — register the window class. WIP but real Win32: build the
// WNDCLASS-style block (style 0xB, the 0x41D670 original WndProc is replaced by
// a headless no-op proc) and call RegisterClassA. Under MATCHED_NATIVE the
// native API slots are installed as trampolines in matched_imports.cpp.
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
WIP_FUNC(0x41D5D0)
int C_vt61DF78::slot31_41D5D0()
{
#ifdef MATCHED_NATIVE
    ++cv_win_class;
#endif
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
}

// 0x41D6A0 — create the main window. WIP with real Win32 calls: read the
// screen metrics, CreateWindowExA, store the handle at +0x28, g_664528 and set
// +0x2C = 1. The original also drives GetWindowRect/SetWindowPos/ShowWindow/
// UpdateWindow/SetFocus once config +0x894 is set; those are skipped here.
WIP_FUNC(0x41D6A0)
int C_vt61DF78::slot32_41D6A0()
{
#ifdef MATCHED_NATIVE
    ++cv_win_class;
#endif
    int w = Native_GetSystemMetrics(0);
    int h = Native_GetSystemMetrics(1);
    int hwnd = Native_CreateWindow((int)(size_t)CfgI(0x410));
    if (hwnd == 0)
        return 0;
    *(int*)((char*)this + 0x28) = hwnd;
    *(int*)((char*)this + 0x2c) = 1;
#ifdef MATCHED_NATIVE
    cv_win_handle = hwnd;
#endif
    *(int*)&g_664528 = hwnd;
    return 1;
}

// 0x41D7F0 — device/screen setup after window creation. WIP success contract;
// original builds the 0x49FED0/0x49FE00/0x45DDB0..0x45EF10 gfx chain.
WIP_FUNC(0x41D7F0)
int C_vt61DF78::slot33_41D7F0()
{
    return 1;
}

// 0x41DAA0 — post-window startup chain. WIP success contract.
WIP_FUNC(0x41DAA0)
int C_vt61DF78::slot35_41DAA0()
{
    return 1;
}

// 0x41DBA0 — UI theme/text init. WIP success contract.
WIP_FUNC(0x41DBA0)
int C_vt61DF78::slot38_41DBA0()
{
    return 1;
}

// 0x41DE50 — build the 0x47C4 main-menu screen. WIP but allocates the real
// shell: operator new(0x47C4), zeroes it, stores it at +0x1B0 and g_664520.
// The original then runs the 0x425750 screen constructor with the config
// +0x900 block and the matched 0x425650/680/6A0 setters; 0x425750 is still
// lifted, so this body stores the allocated screen and returns 1.
WIP_FUNC(0x41DE50)
int C_vt61DF78::slot39_41DE50()
{
#ifdef MATCHED_NATIVE
    ++cv_de50_hits;
#endif
    TScreen47C4* p = (TScreen47C4*)(size_t)sub_5F8F60(0x47c4);
    if (p == 0)
        return 0;
    memset(p, 0, 0x47c4);
    if (Cfg() != 0)
    {
        *(int*)((char*)p + 0x130c) = CfgI(0x900);
        *(int*)((char*)p + 0x12ec) = CfgI(0x904);
        *(int*)((char*)p + 0x12d8) = (unsigned short)(CfgI(0x878) & 0xff);
    }
    *(void**)((char*)this + 0x1b0) = p;
    *(int*)&g_664520 = (int)(size_t)p;
    return 1;
}

// 0x41E070 — build the 0x7B0 game/options screen at +0x80 and the 0x5C0
// auxiliary screen at +0x90. WIP: allocate both shells through the same 0x5F8F60
// allocator used by the original and store g_664518 = +0x80. The matched
// 0x5200F0/0x520410/0x520CC0/0x520DD0/0x520E10/0x520E50/0x520E90/0x520F50/
// 0x520ED0/0x521090 panel setters run once those shells have their internal
// 0x15fc-style subobjects; still skipped here.
WIP_FUNC(0x41E070)
int C_vt61DF78::slot40_41E070()
{
#ifdef MATCHED_NATIVE
    ++cv_e070_hits;
#endif
    TScreen7B0* s1 = (TScreen7B0*)(size_t)sub_5F8F60(0x7b0);
    if (s1 == 0)
        return 0;
    memset(s1, 0, 0x7b0);
    *(void**)((char*)this + 0x80) = s1;
    *(int*)&g_664518 = (int)(size_t)s1;

    TScreen5C0* s2 = (TScreen5C0*)(size_t)sub_5F8F60(0x5c0);
    if (s2 == 0)
        return 0;
    memset(s2, 0, 0x5c0);
    *(void**)((char*)this + 0x90) = s2;
    return 1;
}

// 0x41E4A0 — dialogue/panel bootstrap. WIP success contract.
WIP_FUNC(0x41E4A0)
int C_vt61DF78::slot43_41E4A0()
{
    return 1;
}

// 0x41E5D0 — font/panel construction. WIP success contract.
WIP_FUNC(0x41E5D0)
int C_vt61DF78::slot42_41E5D0()
{
    return 1;
}

// 0x41EA60 — post-screen init. WIP success contract.
WIP_FUNC(0x41EA60)
int C_vt61DF78::slot44_41EA60()
{
    return 1;
}

// setup_fonts at +0xA4. WIP success contract.
WIP_FUNC(0x41E760)
int C_vt61DF78::slot41_41E760()
{
    return 1;
}

// 0x420D10 — window child/scroll init. WIP success contract.
WIP_FUNC(0x420D10)
int C_vt61DF78::slot63_420D10()
{
    return 1;
}

// 0x422340 — UI-sound/state init. WIP success contract.
WIP_FUNC(0x422340)
int C_vt61DF78::slot85_422340()
{
    return 1;
}

// 0x41F200 / 0x41F3A0 / 0x41F0C0 / 0x465270 — device/gfx bootstrap chain.
// WIP success contracts; their real bodies drive the DirectDraw/DirectSound
// setup and are still lifted.
WIP_FUNC(0x41F200)
int sub_41F200()
{
    return 1;
}
WIP_FUNC(0x41F3A0)
int sub_41F3A0()
{
    return 1;
}
WIP_FUNC(0x41F0C0)
int sub_41F0C0(int a1)
{
    (void)a1;
    return 1;
}
WIP_FUNC(0x465270)
int sub_465270()
{
    return 1;
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
WIP_FUNC(0x41BC80)
int C_vt61DF78::slot29_41BC80()
{
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
        if (!sub_41F200())
        {
            field_60 = 3;
            return 0;
        }
    }
    // 0x41F3A0 when config +0x88C is set
    if (CfgI(0x88c) != 0)
    {
        if (!sub_41F3A0())
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
    *(int*)((char*)this + 0x9e0) = sub_41F0C0(0);

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
    if (!this->C_vt61DF78::slot63_420D10())
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
}
