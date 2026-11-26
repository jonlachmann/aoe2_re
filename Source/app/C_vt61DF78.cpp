#include "C_vt61DF78.hpp"
#include "matched_mem.h"
#ifdef MATCHED_NATIVE
extern "C" int g_cvt_slot36_hits = 0;
extern "C" int g_cvt_slot37_hits = 0;
extern "C" int g_cvt_slot04_hits = 0;
extern "C" int g_cvt_41bc80_hits = 0;
#endif

extern void* __cdecl sub_5F8F60(int a1);
extern void __cdecl sub_5F90B0(void* p);
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
    T41DC10Obj* p = new T41DC10Obj(*(int*)((char*)this + 0x24) + 0x418);
    *(int*)((char*)this + 0x1d4) = (int)(size_t)p;
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
    sub_5FCB40(buf, (char*)(*(int*)((char*)this + 0x24) + 0x518), 0xff);
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

// 0x41BC80 (slot +0x74) — basegame device/window/menu bring-up. WIP: only the
// registry-free control state is modelled here. The original first time-seeds
// 0x5FCA3B, reads the resolution/option registry values through the matched
// 0x4BE080 reader on +0x1D4, selects +0x8F4/+0x8FC, drives its +0x78/+0x158/
// +0x7C virtual init slots and the 0x41F200/0x41F3A0/0x41F0C0/0x465270
// subsystem builders, allocates the 0x274 object at +0x1B0/0x664514 and the
// 0x11C/0x10C objects at +0x1C/+0x20, creates the +0x28 window, then leaves
// status 0 and returns 1. Those slots/builders are still lifted, so this body
// takes only the success contract: status 0, non-zero result, no MessageBox.
WIP_FUNC(0x41BC80)
int C_vt61DF78::slot29_41BC80()
{
#ifdef MATCHED_NATIVE
    ++g_cvt_41bc80_hits;
#endif
    field_60 = 0;
    return 1;
}
