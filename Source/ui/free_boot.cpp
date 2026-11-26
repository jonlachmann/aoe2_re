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

// 0x47AE20 — WinMain. Reconstruction of the prologue: raise the timer period,
// seed the CRT random generator from timeGetTime, allocate a rand()%0x1000
// buffer, store it in the stack config block at +0x04, and run the language
// init at 0x47B620 with the path at 0x64D58C. The remaining body copies the
// config strings and dispatches further work; this WIP stops at that point.
typedef void* (__cdecl *TMalloc)(int n);
typedef int (__stdcall *TTimePeriod)(int p);
typedef unsigned int (__stdcall *TTimeGet)(void);
extern TTimePeriod g_61c3d8;
extern TTimeGet g_61c3c8;

extern int __cdecl sub_5FCA3B(unsigned int a1);
extern int __cdecl sub_5FCA45();
extern void* __cdecl sub_5F8F60(int a1);
extern void __cdecl Free_5F90B0(void* p);

WIP_FUNC(0x47AE20)
int __stdcall sub_47AE20(int hInstance, int hPrevInstance, char* lpCmdLine, int nCmdShow)
{
    volatile char cfg[0x1b88];
    int one = 1;

    g_61c3d8(one);
    unsigned int t = g_61c3c8();
    sub_5FCA3B(t);
    int r = sub_5FCA45();
    int n = r % 0x1000;
    char* buf = (char*)sub_5F8F60(n);
    *(char* volatile*)(cfg + 4) = buf;

    int ok = sub_47B620((char*)ADDR(0x64d58c));
    if (ok == 0)
    {
        if (buf != 0)
            Free_5F90B0(buf);
        return 0;
    }
    cfg[0] = (char)ok;
    cfg[0x42c] = (char)one;
    if (cfg[0] != 0)
        return 1;
    if (cfg[0x42c] != 0)
        return 2;
    return 0;
}
