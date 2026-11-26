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
