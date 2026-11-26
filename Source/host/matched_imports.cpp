/*
 * matched_imports.cpp - the native import-dispatch layer for matched/WIP C++
 * bodies.
 *
 * Matched bodies call the original IAT slots as function pointers
 * (`call dword ptr [0x61C110]`). Under the matched-only build that storage is
 * still the generated `g_*` char array, seeded from the raw PE image, so the
 * value is an unbound image word, not a callable address. This layer installs
 * native trampolines into the first dword of each slot the boot path uses. A
 * trampoline converts image pointers back to guest VAs and calls the win32hle
 * shim through hle_call_guest, so the shim sees the guest ABI it expects.
 *
 * GetProcAddress needs one more step: the shim returns a guest VA for the
 * resolved export, and the caller then calls that pointer natively. Known
 * exports get native wrappers (EBUEula is the boot path's EULA checker).
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
extern "C" {
#include "win32hle.h"
}
#include "matched_guest_image.h"

extern long g_matched_base;

/* Generated guest-slot storage (Scripts/matched_globals.cpp). */
extern char g_61c110[0x1000];   /* LoadLibraryA */
extern char g_61c0d8[0x1000];   /* GetProcAddress */
extern char g_61c1a0[0x1000];   /* FreeLibrary */
extern char g_61c3d8[0x1000];   /* timeBeginPeriod */
extern char g_61c3c8[0x1000];   /* timeGetTime */
extern char g_61c168[0x1000];   /* GlobalFree */

typedef int (__stdcall *TLoadLibraryA)(char *name);
typedef int (__cdecl *TExport)(int, char *, char *, int);
typedef TExport (__stdcall *TGetProcAddress)(int module, char *name);
typedef void (__stdcall *TFreeLibrary)(int module);
typedef int (__stdcall *TTimePeriod)(int p);
typedef unsigned int (__stdcall *TTimeGetTime)(void);
typedef void (__stdcall *TGlobalFree)(void *p);
typedef void (__stdcall *TSetLastError)(int e);
typedef int (__stdcall *TIsDBCSLeadByte)(int c);
typedef void* (__stdcall *TGlobalAlloc)(int flags, int size);
typedef int (__stdcall *TLoadStringA)(int module, int id, char *buf, int n);
typedef int (__stdcall *TMessageBoxA)(int hwnd, char *text, char *cap, int type);
typedef int (__stdcall *TGetLastError)(void);

static uint32_t slot_va(const void *p)
{
    /* ADDR() in a matched body yields an image pointer; the shim registry
     * expects the guest VA the original binary would have pushed. */
    if (p != 0 && g_matched_base != 0)
    {
        long off = (long)((const char *)p - (const char *)g_matched_base);
        if (off >= 0 && off < 0x800000)
            return (uint32_t)off;
    }
    return (uint32_t)(uintptr_t)p;
}

static uint32_t call_shim(const char *name, int nargs, const uint32_t *args)
{
    uint32_t va = hle_resolve(name);
    if (va == 0)
    {
        fprintf(stderr, "[matched-imports] shim %s missing\n", name);
        return 0;
    }
    return hle_call_guest(va, nargs, args);
}

static uint32_t g_eula_va = 0;

static int __cdecl eula_export(int a, char *b, char *c, int d)
{
    uint32_t args[4];
    args[0] = (uint32_t)a;
    args[1] = slot_va(b);
    args[2] = slot_va(c);
    args[3] = (uint32_t)d;
    return (int)hle_call_guest(g_eula_va, 4, args);
}

static TExport __stdcall get_proc_address(int module, char *name)
{
    uint32_t args[2];
    args[0] = (uint32_t)module;
    args[1] = slot_va(name);
    uint32_t va = hle_call_guest(hle_resolve("GetProcAddress"), 2, args);
    if (va != 0)
    {
        const char *n = hle_name(va);
        if (n != 0 && strcmp(n, "EBUEula") == 0)
        {
            g_eula_va = va;
            fprintf(stderr, "[matched-imports] GetProcAddress(\"%s\") -> EBUEula wrapper\n", name);
            return eula_export;
        }
        fprintf(stderr, "[matched-imports] GetProcAddress(\"%s\"): no native wrapper for export VA 0x%08X (%s)\n",
                name, va, n == 0 ? "?" : n);
    }
    return 0;
}

static int __stdcall load_library_a(char *name)
{
    uint32_t args[1];
    args[0] = slot_va(name);
    return (int)call_shim("LoadLibraryA", 1, args);
}

static void __stdcall free_library(int module)
{
    uint32_t args[1];
    args[0] = (uint32_t)module;
    call_shim("FreeLibrary", 1, args);
}

static int __stdcall time_begin_period(int p)
{
    uint32_t args[1];
    args[0] = (uint32_t)p;
    return (int)call_shim("timeBeginPeriod", 1, args);
}

static unsigned int __stdcall time_get_time(void)
{
    return call_shim("timeGetTime", 0, 0);
}

static void __stdcall time_end_period(int p)
{
    uint32_t args[1];
    args[0] = (uint32_t)p;
    call_shim("timeEndPeriod", 1, args);
}

static void __stdcall global_free(void *p)
{
    uint32_t args[1];
    args[0] = slot_va(p);
    call_shim("GlobalFree", 1, args);
}

static void __stdcall set_last_error(int e)
{
    uint32_t args[1];
    args[0] = (uint32_t)e;
    call_shim("SetLastError", 1, args);
}

static int __stdcall is_dbcs_lead_byte(int c)
{
    uint32_t args[1];
    args[0] = (uint32_t)c;
    return (int)call_shim("IsDBCSLeadByte", 1, args);
}

static void* __stdcall global_alloc(int flags, int size)
{
    uint32_t args[2];
    args[0] = (uint32_t)flags;
    args[1] = (uint32_t)size;
    return (void*)(uintptr_t)call_shim("GlobalAlloc", 2, args);
}

static int __stdcall load_string_a(int module, int id, char *buf, int n)
{
    uint32_t args[4];
    args[0] = (uint32_t)module;
    args[1] = (uint32_t)id;
    args[2] = slot_va(buf);
    args[3] = (uint32_t)n;
    return (int)call_shim("LoadStringA", 4, args);
}

static int __stdcall message_box_a(int hwnd, char *text, char *cap, int type)
{
    uint32_t args[4];
    args[0] = (uint32_t)hwnd;
    args[1] = slot_va(text);
    args[2] = slot_va(cap);
    args[3] = (uint32_t)type;
    return (int)call_shim("MessageBoxA", 4, args);
}

static int __stdcall get_last_error(void)
{
    return (int)call_shim("GetLastError", 0, 0);
}

extern "C" void InstallMatchedImports(void)
{
    *(void**)g_61c110 = (void*)load_library_a;
    *(void**)g_61c0d8 = (void*)get_proc_address;
    *(void**)g_61c1a0 = (void*)free_library;
    *(void**)g_61c3d8 = (void*)time_begin_period;
    *(void**)g_61c3c8 = (void*)time_get_time;
    *(void**)g_61c168 = (void*)global_free;
}

/* Diagnostic path: run the WIP language init 0x47B620 natively now that the
 * slots it calls are dispatchable. Used by the boot harness to prove the
 * import layer before WinMain has a body. */
extern int __cdecl sub_47B620(char *a1);

extern "C" int matched_langtest(void)
{
    int r = sub_47B620((char *)(g_matched_base + 0x64d58c));
    fprintf(stderr, "[matched-imports] language init 0x47B620 returned %d\n", r);
    return r;
}
