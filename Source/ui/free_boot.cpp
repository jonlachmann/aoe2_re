// free_boot — boot-path free functions recovered from the WinMain init chain.
// 0x47B620 is called from WinMain 0x47AE20 with the language-DLL path at
// 0x64D58C: it loads a module, resolves a function, loads the language DLL,
// reads two string resources into two stack arrays, probes a string with
// sub_5FDCD4 and calls the resolved export with the language resouce pair, then
// releases both modules and returns the export result.
#include "Function.hpp"
#include "matched_mem.h"

typedef int (__cdecl *TExport)(int, char*, char*, int);
typedef int (__stdcall *TLoadLibrary)(char* name);
typedef TExport (__stdcall *TGetProcAddress)(int module, char* name);
typedef void (__stdcall *TFreeLibrary)(int module);

extern TLoadLibrary g_61c110;
extern TGetProcAddress g_61c0d8;
// FreeLibrary is a real dllimport in the original: VC6 caches the IAT slot in
// ebx for the two closing calls (a plain pointer variable is reloaded). The
// native matched build keeps calling through the patched IAT slot g_61c1a0.
#if defined(MATCHED_NATIVE)
extern TFreeLibrary g_61c1a0;
#define FreeLibrary_61C1A0 g_61c1a0
#else
extern "C" __declspec(dllimport) void __stdcall FreeLibrary(int module);
#define FreeLibrary_61C1A0 FreeLibrary
#endif

extern int __stdcall Hook_473AE0(int a1, int a2, char* a3, int a4);
extern int __cdecl sub_5FDCD4(char* a1, int a2, int a3);
extern int __cdecl sub_5FDA2B(int a1);

MATCH_FUNC(0x47B620)
int __cdecl sub_47B620(char* a1)
{
    char block[0x104];
    char lang[0x104];

    TLoadLibrary loadlib = g_61c110;

    int module = loadlib((char*)ADDR(0x6530B4));
    if (module == 0)
        return 0;

    TExport fn = g_61c0d8(module, (char*)ADDR(0x6530AC));
    if (fn == 0)
    {
        FreeLibrary_61C1A0(module);
        return 0;
    }

    int lang_module = loadlib(a1);
    if (lang_module == 0)
    {
        FreeLibrary_61C1A0(module);
        return 0;
    }

    Hook_473AE0(lang_module, 0x3ef, lang, 0x104);
    Hook_473AE0(lang_module, 0x3f0, block, 0x104);

    int result;
    int r = sub_5FDCD4(block, 0, 0x100);
    if (r == -1)
    {
        result = fn((int)ADDR(0x653070), lang, 0, 1);
    }
    else
    {
        sub_5FDA2B(r);
        result = fn((int)ADDR(0x653070), lang, block, 1);
    }

    FreeLibrary_61C1A0(module);
    FreeLibrary_61C1A0(lang_module);
    return result;
}

typedef void (__stdcall *TTimeEndPeriod)(int p);
extern TTimeEndPeriod g_61c3c4;
extern int g_621310;
extern int g_621314;
extern int g_621318;
extern int g_62131c;
extern int g_621320;
extern int g_621324;
extern int g_621328;
extern int g_62132c;
extern int g_621330;
extern int g_621334;
extern int g_621338;
extern int g_62133c;
// 0x47AE20 — WinMain.
// Frame 0x1B88 = result (+0), the rand()-sized buffer (+4), the 0x1980-byte
// game-info block (+8) passed to the 0x5B0EC0 constructor, and two 0x100
// message buffers (caption +0x1988, text +0x1A88). The return value is the
// Vt_04 result, left uninitialised on the other paths in the original too
// (its slot doubles as the strcpy-destination spill). Matching notes: the
// three floats must be float stores (int 0x3f800000 gets CSE'd into a
// register); the 12 g_621310.. copies go last; the 0x320/0x258 dwords are
// written in (w,h) pair order 8e4/8e8, 8f4/8fc, 8ec/8f0; hInstance before
// hPrevInstance; 0/1/3 first. VC6's scheduler then reproduces the original
// interleaving.
typedef void* (__cdecl *TMalloc)(int n);
typedef int (__stdcall *TTimePeriod)(int p);
typedef unsigned int (__stdcall *TTimeGet)(void);
typedef int (__stdcall *TMessageBoxA)(int hwnd, char* text, char* cap, int type);
extern TTimePeriod g_61c3d8;
extern TTimeGet g_61c3c8;
extern TMessageBoxA g_61c37c;

extern int __cdecl sub_5FCA3B(unsigned int a1);
extern int __cdecl sub_5FCA45();
extern void* __cdecl sub_5F8F60(int a1);
extern void __cdecl Free_5F90B0(void* p);
#include "sim/C_vt62C1E0.hpp"

extern int __cdecl sub_5FCE14(char* dst, char* fmt, ...);

// The object returned by 0x5B0EC0 is dispatched through vtable slots
// +0x00/+0x04/+0x18/+0x24/+0x28.
class TWinMainObj {
public:
    virtual int Vt_00(int a1);
    virtual int Vt_04();
    virtual int Vt_08();
    virtual int Vt_0C();
    virtual int Vt_10();
    virtual int Vt_14();
    virtual int Vt_18();
    virtual int Vt_1C();
    virtual int Vt_20();
    virtual int Vt_24(int a1, char* a2, int a3);
    virtual int Vt_28(int a1, int a2, int a3, char* a4, int a5);

    TWinMainObj* Init_5B0EC0(char* info, int a2);   // thiscall ctor at 0x5B0EC0
};
extern void __cdecl sub_473BF0();

MATCH_FUNC(0x47AE20)
#pragma intrinsic(strcpy)
extern "C" void* cv_boot_info = 0;
int __stdcall sub_47AE20(int hInstance, int hPrevInstance, char* lpCmdLine, int nCmdShow)
{
    int result;
    char* buf;
    char info[0x1980];
    char caption[0x100];
    char text[0x100];
#ifdef MATCHED_NATIVE
    cv_boot_info = info;
#endif

    g_61c3d8(1);
    sub_5FCA3B(g_61c3c8());
    buf = (char*)sub_5F8F60(sub_5FCA45() % 0x1000);

    if (!sub_47B620((char*)ADDR(0x64d58c)))
    {
        if (buf != 0)
            Free_5F90B0(buf);
        return 0;
    }

    strcpy(info, (char*)ADDR(0x65305c));  // Age of Empires II
    strcpy(info + 0x65, (char*)ADDR(0x65304c));  // version
    sub_5FCE14(info + 0x7a, (char*)ADDR(0x64d2b8), info);  // %s

    strcpy(info + 0xf3, (char*)ADDR(0x653040));   // tr_wrld.txt
    strcpy(info + 0x1f8, (char*)ADDR(0x65302c));  // dataempires2.dat
    strcpy(info + 0x418, (char*)ADDR(0x652ff4));  // registry root
    strcpy(info + 0x518, lpCmdLine);              // command line
    strcpy(info + 0x61c, (char*)ADDR(0x652fec));  // AppIcon
    strcpy(info + 0x645, (char*)ADDR(0x662be0));  // ""
    strcpy(info + 0x66e, (char*)ADDR(0x652fe4));  // palette
    strcpy(info + 0x773, (char*)ADDR(0x652fd8));  // mcursors
    strcpy(info + 0x2fd, (char*)ADDR(0x652fd0));  // AOE2

    *(int*)(info + 0x404) = 0;
    *(int*)(info + 0x408) = 1;
    *(int*)(info + 0x40c) = 3;
    *(int*)(info + 0x410) = hInstance;
    *(int*)(info + 0x414) = hPrevInstance;
    *(int*)(info + 0x618) = nCmdShow;
    *(int*)(info + 0x8cc) = 0x54;
    *(int*)(info + 0x8d4) = 0x54;
    *(int*)(info + 0x8e4) = 0x320;
    *(int*)(info + 0x8e8) = 0x258;
    *(int*)(info + 0x8f4) = 0x320;
    *(int*)(info + 0x8fc) = 0x258;
    *(int*)(info + 0x8ec) = 0x320;
    *(int*)(info + 0x8f0) = 0x258;
    *(int*)(info + 0x878) = 8;
    *(int*)(info + 0x87c) = 0;
    *(short*)(info + 0x880) = 9;
    *(short*)(info + 0x882) = 0xf;
    *(short*)(info + 0x884) = 0x63;
    *(int*)(info + 0x888) = 1;
    *(int*)(info + 0x88c) = 1;
    *(int*)(info + 0x890) = 0;
    *(int*)(info + 0x894) = 1;
    *(int*)(info + 0x898) = 1;
    *(int*)(info + 0x89c) = 1;
    *(int*)(info + 0x8a0) = 0;
    *(int*)(info + 0x8a4) = 1;
    *(int*)(info + 0x8a8) = 1;
    *(int*)(info + 0x8bc) = 1;
    *(int*)(info + 0x8c0) = 1;
    *(int*)(info + 0x8c8) = 3;
    *(float*)(info + 0x8d0) = 1.0f;
    *(float*)(info + 0x8d8) = 1.0f;
    *(float*)(info + 0x8dc) = 0.05f;
    *(short*)(info + 0x8e0) = 2;
    *(int*)(info + 0x8ac) = 0;
    *(int*)(info + 0x8b0) = 0;
    *(int*)(info + 0x8b4) = 0;
    *(int*)(info + 0x8b8) = 0;
    *(short*)(info + 0x8f8) = 3;
    *(int*)(info + 0x900) = g_621310;
    *(int*)(info + 0x904) = g_621314;
    *(int*)(info + 0x908) = g_621318;
    *(int*)(info + 0x90c) = g_62131c;
    *(int*)(info + 0x910) = g_621320;
    *(int*)(info + 0x914) = g_621324;
    *(int*)(info + 0x918) = g_621328;
    *(int*)(info + 0x91c) = g_62132c;
    *(int*)(info + 0x920) = g_621330;
    *(int*)(info + 0x924) = g_621334;
    *(int*)(info + 0x928) = g_621338;
    *(int*)(info + 0x92c) = g_62133c;

    strcpy(info + 0x930, (char*)ADDR(0x652fc8));  // data
    strcpy(info + 0xf4e, (char*)ADDR(0x652fc0));  // sound
    strcpy(info + 0x1053, (char*)ADDR(0x652fb0)); // soundterrain
    strcpy(info + 0x1158, (char*)ADDR(0x652fa0)); // soundcampaign
    strcpy(info + 0x1362, (char*)ADDR(0x652f90)); // soundstream
    strcpy(info + 0x125d, (char*)ADDR(0x652f80)); // soundscenario
    strcpy(info + 0xa35, (char*)ADDR(0x662be0));  // ""
    strcpy(info + 0xb3a, (char*)ADDR(0x652f74));  // savegame
    strcpy(info + 0xc3f, (char*)ADDR(0x652f64));  // savegamemulti
    strcpy(info + 0xd44, (char*)ADDR(0x652f58));  // scenario
    strcpy(info + 0xe49, (char*)ADDR(0x652f4c));  // campaign
    strcpy(info + 0x1467, (char*)ADDR(0x652fc8)); // data
    strcpy(info + 0x156c, (char*)ADDR(0x652f48)); // ai
    strcpy(info + 0x1671, (char*)ADDR(0x652f40)); // avi
    strcpy(info + 0x1776, (char*)ADDR(0x652f38)); // taunt
    strcpy(info + 0x187b, (char*)ADDR(0x652f30)); // random

    result = 0;

    TWinMainObj* obj;
    void* mem = sub_5F8F60(0x1c94);
    if (mem != 0)
        obj = ((TWinMainObj*)mem)->Init_5B0EC0(info, 1);
    else
        obj = 0;
    if (obj != 0)
    {
        int r18 = obj->Vt_18();
        if (r18 == 0)
        {
            result = obj->Vt_04();
            obj->Vt_18();
            obj->Vt_00(1);
        }
        else if (r18 != 4)
        {
            obj->Vt_24(0x7d1, caption, 0x100);
            obj->Vt_28(1, r18, 0, text, 0x100);
            obj->Vt_00(1);
            g_61c37c(0, text, caption, 0x10);
        }
    }

    sub_473BF0();
    if (buf != 0)
        Free_5F90B0(buf);
    g_61c3c4(1);
    return result;
}
#pragma function(strcpy)

// The WinMain-matched body declares the 0x5B0EC0 thiscall as
// TWinMainObj::Init_5B0EC0; forward it to the constructor modelled on its real
// owner class C_vt62C1E0 (vtable 0x62C1E0), keeping the call site's direct symbol.
TWinMainObj* TWinMainObj::Init_5B0EC0(char* info, int a2)
{
    return (TWinMainObj*)((C_vt62C1E0*)this)->M_5B0EC0(info, a2);
}
