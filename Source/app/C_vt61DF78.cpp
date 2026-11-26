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
// host-installed trampoline arrays. WIP: ours 240 vs 243 bytes; all operands
// now match, and the only miss is block placement — VC6 emits the peek block
// (PeekMessage) before the GetMessage block and shifts every jump target, while
// the original keeps GetMessage first and the peek/idle blocks after it.
WIP_FUNC(0x41CF70)
int C_vt61DF78::slot01_41CF70()
{
#ifdef MATCHED_NATIVE
    ++g_cvt_slot04_hits;
    int (__stdcall *translate)(void*) =
        *(int (__stdcall**)(void*))g_61c2e0;
    int (__stdcall *dispatch)(void*) =
        *(int (__stdcall**)(void*))g_61c2dc;
#else
    int (__stdcall *translate)(void*) =
        *(int (__stdcall**)(void*))ADDR(0x61c2e0);
    int (__stdcall *dispatch)(void*) =
        *(int (__stdcall**)(void*))ADDR(0x61c2dc);
#endif
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
#ifdef MATCHED_NATIVE
        if (!(*(int (__stdcall**)(void*, int, int, int))g_61c2e4)(
                msg, 0, 0, 0))
            return msg[2];
#else
        if (!(*(int (__stdcall**)(void*, int, int, int))
                ADDR(0x61c2e4))(msg, 0, 0, 0))
            return msg[2];
#endif
        translate(msg);
        dispatch(msg);
        continue;

    peek:
#ifdef MATCHED_NATIVE
        if ((*(int (__stdcall**)(void*, int, int, int, int))g_61c2e8)(
                msg, 0, 0, 0, 1) == 0)
            goto idle;
#else
        if ((*(int (__stdcall**)(void*, int, int, int, int))
                ADDR(0x61c2e8))(msg, 0, 0, 0, 1) == 0)
            goto idle;
#endif
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
// WIP: ours 320 vs 330 bytes. Every byte of both style branches (0x0000-0x007A)
// is identical, including the literal 0x2CA0000/0x82080000 pushes and the shared
// tail; the residual is register allocation: the original keeps `this` in esi,
// the slot pointer in edi and the new rect height in ebx (no frame pointer),
// while VC6 here assigns this to edi, gm to esi, and the rect height to ebp, so
// it pushes ebp mid-function and shifts the second rect pair from [esp+0x1C] to
// [esp+0x20]. Source variants (single shared-tail call, ternary arg selection,
// inline vs cached cfg pointer) only worsened the shape. The native branch keeps
// the Native_CreateWindow flow and skips the raw guest slots.
extern void __cdecl Hook_49FE60Noop();
class C_cluster_49FE60 {
public:
    void M_49FE60();
};
WIP_FUNC(0x41D6A0)
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
    int (__stdcall *gm)(int) = (*(int (__stdcall**)(int))ADDR(0x61c390));
    int width = gm(0);
    int height = gm(1);
    int hwnd;
    if (*(int*)(*(int*)((char*)this + 0x24) + 0x894) == 0
        && (width != *(int*)(*(int*)((char*)this + 0x24) + 0x8e4)
            || height != *(int*)(*(int*)((char*)this + 0x24) + 0x8e8)))
    {
        hwnd = (*(int (__stdcall**)(int, int, void*, int, int, int, int,
                                     int, int, int, int, int))
                ADDR(0x61c398))(0, *(int*)((char*)this + 0x24),
                                (void*)(*(int*)((char*)this + 0x24) + 0x7a),
                                0x2ca0000, 0, 0,
                                *(int*)(*(int*)((char*)this + 0x24) + 0x8e4),
                                *(int*)(*(int*)((char*)this + 0x24) + 0x8e8),
                                0, 0,
                                *(int*)(*(int*)((char*)this + 0x24) + 0x410), 0);
    }
    else
    {
        hwnd = (*(int (__stdcall**)(int, int, void*, int, int, int, int,
                                     int, int, int, int, int))
                ADDR(0x61c398))(0, *(int*)((char*)this + 0x24),
                                (void*)(*(int*)((char*)this + 0x24) + 0x7a),
                                0x82080000, 0, 0, width, height, 0, 0,
                                *(int*)(*(int*)((char*)this + 0x24) + 0x410), 0);
    }
    *(int*)((char*)this + 0x28) = hwnd;
    if (hwnd == 0)
        return 0;
    int rc[8];
    (*(int (__stdcall**)(int, void*))ADDR(0x61c38c))(hwnd, (void*)&rc[0]);
    (*(int (__stdcall**)(int, void*))ADDR(0x61c2c4))(hwnd, (void*)&rc[4]);
    if (rc[6] != *(int*)(*(int*)((char*)this + 0x24) + 0x8e4)
        || rc[7] != *(int*)(*(int*)((char*)this + 0x24) + 0x8e8))
    {
        int newh = *(int*)(*(int*)((char*)this + 0x24) + 0x8e8)
                   - rc[1] - rc[7] + rc[3];
        int neww = *(int*)(*(int*)((char*)this + 0x24) + 0x8e4)
                   - rc[1] - rc[6] + rc[3];
        (*(int (__stdcall**)(int, int, int, int, int, int, int))
                ADDR(0x61c2c8))(hwnd, 0, rc[1], rc[1], neww, newh, 0);
    }
    if (*(int*)(*(int*)((char*)this + 0x24) + 0x894) != 0)
    {
        (*(int (__stdcall**)(int, int))ADDR(0x61c2fc))(
            hwnd, *(int*)(*(int*)((char*)this + 0x24) + 0x618));
        (*(int (__stdcall**)(int))ADDR(0x61c2cc))(hwnd);
        (*(int (__stdcall**)(int))ADDR(0x61c300))(hwnd);
    }
    *(int*)&g_664528 = *(int*)((char*)this + 0x28);
    ((C_cluster_49FE60*)ADDR(0x66ea48))->M_49FE60();
    return 1;
#endif
}

// 0x41D7F0 — device/screen setup after window creation. WIP success contract;
// original builds the 0x49FED0/0x49FE00/0x45DDB0..0x45EF10 gfx chain.
WIP_FUNC(0x41D7F0)
int C_vt61DF78::slot33_41D7F0()
{
    return 1;
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

// 0x41DAA0 WIP layout note: ours 256 vs 251 bytes; the only structural miss is
// VC6 block placement. The original keeps the -1 registration block first,
// then the allocation block, then the result==1/2 dispatch after it with
// backward jumps into the allocation; our compiler keeps the dispatch before
// the allocation and jumps forward. Logic is equivalent; register scheduling
// and the EH handler push (`push 0` vs `push <reloc>`) follow from it. 0x41DAA0
// itself: registry resolution plus the 0x268 edit object. It
// reads the registry key 0x64D818; -1 triggers the 0x4BDF50 registration with
// (0,key,0); 1 keeps the argument as the +0x74 selection; 2 clears +0x74.
// Then `new` constructs the 0x268 object with 0, stores it at +0x1E8, runs the
// 0x48A6F0 five-argument setup from +0x74/+0x6C/config +0x773/(0xC738,0x13),
// and on success calls the base 0x41F920 teardown. Both failures return 0;
// success returns 1.
WIP_FUNC(0x41DAA0)
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
    if (result != -1)
    {
        if (result == 1)
            arg0 = result;
        if (result == 2)
            *(int*)((char*)this + 0x74) = 0;
    }
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

// 0x41DE50 — build the 0x47C4 main-menu screen. The reconstructed
// S47C4Screen::M_425750 constructor now runs inside this slot: it allocates and
// seeds the 0x47C4 screen, constructs the 0x1168/+0x15F8, 0x7F4/+0x15FC and the
// other 0x7D0//0x8//0x54C subobjects, then the byte-exact 0x425650/425680/426A0
// setters populate the +0x1B4/+0x1BC/+0x1C0/+0x1C4/+0x1B8 UI fields. The
// nonzero-field count and the setter entries are recorded for the boot proof.
WIP_FUNC(0x41DE50)
int C_vt61DF78::slot39_41DE50()
{
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
}

// 0x41E070 — build the 0x7B0 game/options screen at +0x80 and the 0x5C0
// auxiliary screen at +0x90. When config +0x8A8 is set the byte-exact
// 0x5200F0 constructor runs on the 0x7B0 allocation (the WIP 0x520170 helper
// sets the +0x04 ready flag), the 0x520400 gate, registry probe, 0x520410, then
// the 520CC0/520DD0/520E10/520E50/520E90/520F50/520ED0/521090 panel setters
// populate the 0x5C0 object. Preset bytes at +0xB50 are empty in the boot
// config, so the lifted 0x520F70/0x5215F0 pair is not entered here.
WIP_FUNC(0x41E070)
int C_vt61DF78::slot40_41E070()
{
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
            *(int*)((char*)this + 0x80) = (int)(size_t)s1;
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
                *(int*)((char*)this + 0x80) = 0;
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
            *(int*)((char*)this + 0x90) = (int)(size_t)s2;
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
void C_cluster_5207B0::M_5207B0(int a1, int a2, int a3)
{
    (void)a1; (void)a2; (void)a3;
}

// 0x41E5D0 (slot +0xA8) — the sibling of 0x41E4A0: seed +0x88 to 3, allocate
// the 3*4 table through 0x5F8FF0 at +0x8C, zero it, `new` three 0x20 entries
// from the 0x64D8B4/0x64D8A8/0x64D898 names with codes 0xC47C/0xC47D/0xC47E
// and the +0x80 object, then walk the table and run each entry's 0x5207B0
// cleanup with (0,-1,0).
WIP_FUNC(0x41E5D0)
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

// setup_fonts at +0xA4. WIP success contract.
WIP_FUNC(0x41E760)
int C_vt61DF78::slot41_41E760()
{
    return 1;
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

// 0x41F200 / 0x41F3A0 / 0x41F0C0 / 0x465270 — device/gfx bootstrap chain.
// WIP success contracts; their real bodies drive the DirectDraw/DirectSound
// setup and are still lifted.
WIP_FUNC(0x41F200)
int C_vt61DF78::M_41F200()
{
    return 1;
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
WIP_FUNC(0x41F0C0)
int C_vt61DF78::M_41F0C0(int a1)
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
}
