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
extern TFreeLibrary g_61c1a0;

extern int __stdcall Hook_473AE0(int a1, int a2, char* a3, int a4);
extern int __cdecl sub_5FDCD4(char* a1, int a2, int a3);
extern int __cdecl sub_5FDA2B(int a1);

WIP_FUNC(0x47B620)
int __cdecl sub_47B620(char* a1)
{
    char block[0x104];
    char lang[0x104];
    TFreeLibrary freefn;

    TLoadLibrary loadlib = g_61c110;

    int module = loadlib((char*)ADDR(0x6530B4));
    if (module == 0)
        return 0;

    TExport fn = g_61c0d8(module, (char*)ADDR(0x6530AC));
    if (fn == 0)
    {
        g_61c1a0(module);
        return 0;
    }

    int lang_module = loadlib(a1);
    if (lang_module == 0)
    {
        g_61c1a0(module);
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

    freefn = g_61c1a0;
    freefn(module);
    freefn(lang_module);
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
// Frame 0x1B88: a stack config block whose strings were filled by 27 inline
// strcpy expansions, plus the rand()-sized buffer pointer at +0x04. The body
// asks the language DLL (0x47B620) for a language, fills the config, builds the
// 0x1C94 sim/config object via 0x5B0EC0, drives its vtable slots, shows the
// resource-based message box, tears down 0x473BF0 and the timer.
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
extern int __cdecl sub_5FCE14(char* dst, char* fmt, char* a3);

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
};

extern TWinMainObj* __cdecl sub_5B0EC0(void* a1, char* a2, int a3);
extern void __cdecl sub_473BF0();

WIP_FUNC(0x47AE20)
#pragma intrinsic(strcpy)
int __stdcall sub_47AE20(int hInstance, int hPrevInstance, char* lpCmdLine, int nCmdShow)
{
    char cfg[0x1b84];

    g_61c3d8(1);
    sub_5FCA3B(g_61c3c8());
    *(char**)(cfg + 4) = (char*)sub_5F8F60(sub_5FCA45() % 0x1000);

    if (!sub_47B620((char*)ADDR(0x64d58c)))
    {
        if (*(char**)(cfg + 4) != 0)
            Free_5F90B0(*(char**)(cfg + 4));
        return 0;
    }

    strcpy(cfg + 0x08, (char*)ADDR(0x65305c));  // Age of Empires II
    strcpy(cfg + 0x6d, (char*)ADDR(0x65304c));  // version
    sub_5FCE14(cfg + 0x82, (char*)ADDR(0x64d2b8), cfg + 0x08);  // %s

    strcpy(cfg + 0xfb, (char*)ADDR(0x653040));   // tr_wrld.txt
    strcpy(cfg + 0x200, (char*)ADDR(0x65302c));  // dataempires2.dat
    strcpy(cfg + 0x420, (char*)ADDR(0x652ff4));  // registry root
    strcpy(cfg + 0x520, lpCmdLine);              // command line
    strcpy(cfg + 0x624, (char*)ADDR(0x652fec));  // AppIcon
    strcpy(cfg + 0x64d, (char*)ADDR(0x662be0));  // ""
    strcpy(cfg + 0x676, (char*)ADDR(0x652fe4));  // palette
    strcpy(cfg + 0x77b, (char*)ADDR(0x652fd8));  // mcursors
    strcpy(cfg + 0x305, (char*)ADDR(0x652fd0));  // AOE2

    *(int*)(cfg + 0x41c) = hPrevInstance;
    *(int*)(cfg + 0x418) = hInstance;
    *(int*)(cfg + 0x620) = nCmdShow;
    *(int*)(cfg + 0x8d4) = 0x54;
    *(int*)(cfg + 0x8dc) = 0x54;
    *(int*)(cfg + 0x8f0) = 0x258;
    *(int*)(cfg + 0x8f8) = 0x258;
    *(int*)(cfg + 0x904) = 0x258;
    *(int*)(cfg + 0x8ec) = 0x320;
    *(int*)(cfg + 0x8fc) = 0x320;
    *(int*)(cfg + 0x8f4) = 0x320;
    *(int*)(cfg + 0x908) = g_621310;
    *(int*)(cfg + 0x90c) = g_621314;
    *(int*)(cfg + 0x910) = g_621318;
    *(int*)(cfg + 0x914) = g_62131c;
    *(int*)(cfg + 0x918) = g_621320;
    *(int*)(cfg + 0x91c) = g_621324;
    *(int*)(cfg + 0x920) = g_621328;
    *(int*)(cfg + 0x924) = g_62132c;
    *(int*)(cfg + 0x928) = g_621330;
    *(int*)(cfg + 0x92c) = g_621334;
    *(int*)(cfg + 0x930) = g_621338;
    *(int*)(cfg + 0x934) = g_62133c;
    *(int*)(cfg + 0x40c) = 0;
    *(int*)(cfg + 0x410) = 1;
    *(int*)(cfg + 0x414) = 3;
    *(int*)(cfg + 0x880) = 8;
    *(int*)(cfg + 0x884) = 0;
    *(short*)(cfg + 0x888) = 9;
    *(short*)(cfg + 0x88a) = 0xf;
    *(short*)(cfg + 0x88c) = 0x63;
    *(int*)(cfg + 0x890) = 1;
    *(int*)(cfg + 0x894) = 1;
    *(int*)(cfg + 0x898) = 0;
    *(int*)(cfg + 0x89c) = 1;
    *(int*)(cfg + 0x8a0) = 1;
    *(int*)(cfg + 0x8a4) = 1;
    *(int*)(cfg + 0x8a8) = 0;
    *(int*)(cfg + 0x8ac) = 1;
    *(int*)(cfg + 0x8b0) = 1;
    *(int*)(cfg + 0x8c4) = 1;
    *(int*)(cfg + 0x8c8) = 1;
    *(int*)(cfg + 0x8d0) = 3;
    *(int*)(cfg + 0x8d8) = 0x3f800000;
    *(int*)(cfg + 0x8e0) = 0x3f800000;
    *(int*)(cfg + 0x8e4) = 0x3d4ccccd;
    *(short*)(cfg + 0x8e8) = 2;
    *(int*)(cfg + 0x8b4) = 0;
    *(int*)(cfg + 0x8b8) = 0;
    *(int*)(cfg + 0x8bc) = 0;
    *(int*)(cfg + 0x8c0) = 0;
    *(short*)(cfg + 0x900) = 3;

    strcpy(cfg + 0x938, (char*)ADDR(0x652fc8));  // data
    strcpy(cfg + 0xf56, (char*)ADDR(0x652fc0));  // sound
    strcpy(cfg + 0x105b, (char*)ADDR(0x652fb0)); // soundterrain
    strcpy(cfg + 0x1160, (char*)ADDR(0x652fa0)); // soundcampaign
    strcpy(cfg + 0x136a, (char*)ADDR(0x652f90)); // soundstream
    strcpy(cfg + 0x1265, (char*)ADDR(0x652f80)); // soundscenario
    strcpy(cfg + 0xa3d, (char*)ADDR(0x662be0));  // ""
    strcpy(cfg + 0xb42, (char*)ADDR(0x652f74));  // savegame
    strcpy(cfg + 0xc47, (char*)ADDR(0x652f64));  // savegamemulti
    strcpy(cfg + 0xd4c, (char*)ADDR(0x652f58));  // scenario
    strcpy(cfg + 0xe51, (char*)ADDR(0x652f4c));  // campaign
    strcpy(cfg + 0x146f, (char*)ADDR(0x652fc8)); // data
    strcpy(cfg + 0x1574, (char*)ADDR(0x652f48)); // ai
    strcpy(cfg + 0x1679, (char*)ADDR(0x652f40)); // avi
    strcpy(cfg + 0x177e, (char*)ADDR(0x652f38)); // taunt
    strcpy(cfg + 0x1883, (char*)ADDR(0x652f30)); // random

    if (*(char**)(cfg + 4) != 0)
        strcpy(*(char**)(cfg + 4), (char*)ADDR(0x652f30));
    *(char**)(cfg + 4) = 0;

    void* simbuf = sub_5F8F60(0x1c94);
    if (simbuf != 0)
    {
        TWinMainObj* obj = sub_5B0EC0(simbuf, cfg + 0x08, 1);
        if (obj != 0)
        {
            int r18 = obj->Vt_18();
            if (r18 == 0)
            {
                int r4 = obj->Vt_04();
                obj->Vt_18();
                obj->Vt_00(1);
                (void)r4;
            }
            else if (r18 != 4)
            {
                obj->Vt_24(0x7d1, cfg + 0x1988, 0x100);
                obj->Vt_28(1, 0, r18, cfg + 0x1a88, 0x100);
                obj->Vt_00(1);
                g_61c37c(0, cfg + 0x1988, cfg + 0x1a8c, 0x10);
            }
        }
    }

    sub_473BF0();
    if (*(char**)(cfg + 4) != 0)
        Free_5F90B0(*(char**)(cfg + 4));
    g_61c3c4(1);
    return 0;
}
#pragma function(strcpy)
