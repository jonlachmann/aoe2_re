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
extern char g_61C3C8[0x1000];   /* same slot under the uppercase alias many bodies use */
extern char g_61c168[0x1000];   /* GlobalFree */
extern char g_61c37c[0x1000];   /* MessageBoxA */
extern char g_61c3c4[0x1000];   /* timeEndPeriod */
extern char g_61C008[0x1000];   /* RegCreateKeyExA (9-arg slot 0x61C008) */
extern char g_61C004[0x1000];   /* RegQueryValueExA (6-arg slot 0x61C004) */
extern char g_61C000[0x1000];   /* RegSetValueExA (6-arg slot 0x61C000) */
/* Win32 window/user slots reached by the native 0x41BC80 bring-up. */
extern char g_61C2D8[0x1000];   /* CharUpperA (slot 0x61C2D8) */
/* Lowercase image-slot arrays used by the C_vt61DF78 message pump. */
extern char g_61c2dc[0x1000];
extern char g_61c2e0[0x1000];
extern char g_61c2e4[0x1000];
extern char g_61c2e8[0x1000];

/* cv_* IAT-pointer bodies such as 0x440C40 call through a data pointer symbol,
   not through a code stub. Bind that symbol to the same trampoline value the
   generated guest slot carries; a weak code stub with this name would otherwise
   make the first instruction bytes look like a function address. */
unsigned int (__stdcall *cv_61c3c8)() = 0;


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
    /* The matched WinMain passes native stack buffers, not guest VAs; the HLE
     * shim resolves guest pointers through the image base and would fault.
     * Headless boot only needs the box's text and an IDOK result. */
    (void)hwnd; (void)type;
    fprintf(stderr, "[MessageBox] %s: %s\n",
            cap != 0 ? cap : "", text != 0 ? text : "");
    return 1;
}

static int __stdcall dispatch_message_a(void *msg)
{
    (void)msg;
    return 0;
}

static int __stdcall translate_message(void *msg)
{
    (void)msg;
    return 1;
}

/* Headless boot has no real window queue; return zero (WM_QUIT) so the menu
 * loop's GetMessage gate exits after one iteration instead of blocking. */
static int __stdcall get_message_a(void *msg, int hwnd, int lo, int hi)
{
    (void)msg; (void)hwnd; (void)lo; (void)hi;
    if (msg != 0)
    {
        int *m = (int*)msg;
        m[0] = 0;
        m[1] = 0x12;    /* WM_QUIT */
        m[2] = 0;
        m[3] = 0;
    }
    return 0;
}

static int __stdcall peek_message_a(void *msg, int hwnd, int lo, int hi, int remove)
{
    (void)msg; (void)hwnd; (void)lo; (void)hi; (void)remove;
    return 0;
}

static int __stdcall reg_create_key_ex_a(int root, char *subkey, int reserved,
                                         char *cls, int options, int access,
                                         void *sec, void *outkey, void *disposition)
{
    /* The matched 0x4BDE90 passes native stack/config pointers here; the HLE
     * shim resolves guest VAs and would fault on them. Headless boot does not
     * need registry handles: succeed and hand back empty handles/dispositions. */
    (void)root; (void)subkey; (void)reserved; (void)cls; (void)options;
    (void)access; (void)sec;
    if (outkey != 0)
        *(uint32_t*)outkey = 0;
    if (disposition != 0)
        *(uint32_t*)disposition = 0;
    return 0;
}

static int __stdcall reg_query_value_ex_a(void *key, char *name, int reserved,
                                          int *type, void *data, unsigned int *size)
{
    /* Headless boot has no registry hive to read. Report a miss so the matched
     * 0x4BE080 reader returns -1 and the bring-up takes its documented default
     * branches instead of faulting on an unbound slot. */
    (void)key; (void)name; (void)reserved; (void)data;
    if (type != 0) *type = 4;
    if (size != 0) *size = 0;
    return 1;
}

static int __stdcall reg_set_value_ex_a(void *key, char *name, int reserved,
                                        int type, void *data, unsigned int size)
{
    (void)key; (void)name; (void)reserved; (void)type; (void)data; (void)size;
    return 0;
}

static int __stdcall get_system_metrics(int index)
{
    /* Headless menu boot: a 800x600 desktop. index 0 width, 1 height. */
    return index == 0 ? 800 : 600;
}

static int __stdcall create_window_ex_a(int exstyle, char *cls, char *title,
                                        int style, int x, int y, int w, int h,
                                        int parent, int menu, int inst, int param)
{
    (void)exstyle; (void)cls; (void)title; (void)style; (void)x; (void)y;
    (void)w; (void)h; (void)parent; (void)menu; (void)inst; (void)param;
    /* A stable fake 32-bit HWND the guest layout can carry in a dword field. */
    return 0x1a2b3c4d;
}

static int __stdcall get_window_rect(void *hwnd, int *rect)
{
    (void)hwnd;
    if (rect != 0)
    {
        rect[0] = 0; rect[1] = 0; rect[2] = 800; rect[3] = 600;
    }
    return 1;
}

static int __stdcall get_client_rect(void *hwnd, int *rect)
{
    (void)hwnd;
    if (rect != 0)
    {
        rect[0] = 0; rect[1] = 0; rect[2] = 800; rect[3] = 600;
    }
    return 1;
}

static int __stdcall set_window_pos(void *hwnd, void *after, int x, int y, int cx, int cy, int flags)
{
    (void)hwnd; (void)after; (void)x; (void)y; (void)cx; (void)cy; (void)flags;
    return 1;
}

static int __stdcall update_window(void *hwnd)
{
    (void)hwnd;
    return 1;
}

static int __stdcall show_window(void *hwnd, int cmd)
{
    (void)hwnd; (void)cmd;
    return 1;
}

static int __stdcall set_focus(void *hwnd)
{
    (void)hwnd;
    return 1;
}

static int __stdcall set_timer(void *hwnd, int id, int ms, void *proc)
{
    (void)hwnd; (void)id; (void)ms; (void)proc;
    return 1;
}

static int __stdcall system_parameters_info_a(int action, int p0, void *p1, int p2)
{
    (void)p0; (void)p2;
    if (action == 0x10 && p1 != 0)
        *(int*)p1 = 0x20;      /* SPI_GETMOUSESPEED style probe */
    return 1;
}

static int __stdcall register_class_a(void *wc)
{
    (void)wc;
    return 1;
}

static int __stdcall load_icon_a(int inst, char *name)
{
    (void)inst; (void)name;
    return 1;
}

static int __stdcall global_memory_status(void *mem)
{
    /* dwLength, dwMemoryLoad, dwTotalPhys, dwAvailPhys, dwTotalPageFile,
     * dwAvailPageFile, dwTotalVirtual, dwAvailVirtual (8 dwords). */
    if (mem != 0)
    {
        unsigned int *m = (unsigned int*)mem;
        m[0] = 32;
        m[1] = 10;
        m[2] = 0x3f00000;
        m[3] = 0x2000000;
        m[4] = 0;
        m[5] = 0;
        m[6] = 0;
        m[7] = 0;
    }
    return 1;
}

/* Direct native entry points for the WIP bring-up bodies. They bypass the
 * guest IAT slot arrays (which are only meaningful when a caller pushes
 * guest-VA arguments) and let the 0x41BC80 window/screen chain run in-process. */
extern "C" int Native_GetSystemMetrics(int index) { return get_system_metrics(index); }
extern "C" int Native_CreateWindow(int clsId) { (void)clsId; return create_window_ex_a(0, (char*)"AOE matched menu", (char*)"Age of Empires", 0x82080000, 0, 0, 800, 600, 0, 0, 0, 0); }
extern "C" int Native_RegisterClass(void* wc) { return register_class_a(wc); }
extern "C" int Native_LoadIcon(int inst, char* name) { return load_icon_a(inst, name); }
extern "C" int Native_SystemParameters(int action, int p0, void* p1, int p2) { return system_parameters_info_a(action, p0, p1, p2); }
extern "C" int Native_ShowWindow(int hwnd, int cmd) { return show_window((void*)(size_t)hwnd, cmd); }
extern "C" int Native_UpdateWindow(int hwnd) { return update_window((void*)(size_t)hwnd); }
extern "C" int Native_SetFocus(int hwnd) { return set_focus((void*)(size_t)hwnd); }
extern "C" int Native_SetTimer(int hwnd, int id, int ms, void* proc) { return set_timer((void*)(size_t)hwnd, id, ms, proc); }
extern "C" int Native_GlobalMemoryStatus(void* mem) { return global_memory_status(mem); }
extern "C" int Native_GetClientRect(int hwnd, int* rect) { return get_client_rect((void*)(size_t)hwnd, rect); }

static int __stdcall char_upper_a(char *s)
{
    /* The seeded slot holds the RVA 0x38284A of the name "CharUpperA"; its
     * callers pass native stack buffers, so upper-case them in place. */
    if (s != 0)
    {
        char *p = s;
        while (*p != 0)
        {
            if (*p >= 'a' && *p <= 'z')
                *p = (char)(*p - 'a' + 'A');
            ++p;
        }
    }
    return (int)(uintptr_t)s;
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
    *(void**)g_61C3C8 = (void*)time_get_time;
    cv_61c3c8 = time_get_time;
    *(void**)g_61c168 = (void*)global_free;
    *(void**)g_61c37c = (void*)message_box_a;
    *(void**)g_61c3c4 = (void*)time_end_period;
    *(void**)g_61C008 = (void*)reg_create_key_ex_a;
    *(void**)g_61C004 = (void*)reg_query_value_ex_a;
    *(void**)g_61C000 = (void*)reg_set_value_ex_a;
    *(void**)g_61C2D8 = (void*)char_upper_a;
    *(void**)g_61c2dc = (void*)dispatch_message_a;
    *(void**)g_61c2e0 = (void*)translate_message;
    *(void**)g_61c2e4 = (void*)get_message_a;
    *(void**)g_61c2e8 = (void*)peek_message_a;

}

/* Diagnostic path: run the WIP language init 0x47B620 natively now that the
 * slots it calls are dispatchable. Used by the boot harness to prove the
 * import layer before WinMain has a body. */
extern int __cdecl sub_47B620(char *a1);

extern int __stdcall sub_47AE20(int hInstance, int hPrevInstance, char *lpCmdLine, int nCmdShow);
extern "C" int g_cvt_ctor41_hits;
extern "C" int g_cvt_ctor5b_hits;
extern "C" int g_cvt_slot18_hits;
extern "C" int g_cvt_slot24_hits;
extern "C" int g_cvt_slot00_hits;
extern "C" int g_cvt_slot36_hits;
extern "C" int g_cvt_dc10_status;
extern "C" int g_cvt_slot37_hits;
extern "C" int g_cvt_slot04_hits;
extern "C" int g_cvt_41bc80_hits;
extern "C" int g_cvt_5b17d0_hits;
extern "C" int cv_win_class;
extern "C" int cv_win_handle;
extern "C" int cv_de50_hits;
extern "C" int cv_e070_hits;
extern "C" int cv_screen47_pop;
extern "C" int cv_screen7b0_pop;
extern "C" int cv_screen5c0_pop;
extern "C" int cv_e070_preset_entries;
extern "C" int cv_cfg_sound;
extern "C" void* cv_config_ptr;
extern "C" void* cv_boot_info;
extern "C" void* cv_s47_15e8;
extern "C" void* cv_s47_15f8;
extern "C" void* cv_s47_15fc;
extern "C" void* cv_s47_1604;
extern "C" void* cv_s47_1610;
extern "C" void* cv_s47_80;
extern "C" void* cv_s47_90;
extern "C" int cv_ui_425650;
extern "C" int cv_ui_425680;
extern "C" int cv_ui_4256a0;
extern "C" int cv_ui_5200f0;
extern "C" int cv_ui_520410;
extern "C" int cv_ui_520cc0;
extern "C" int cv_ui_520dd0;
extern "C" int cv_ui_520e10;
extern "C" int cv_ui_520e50;
extern "C" int cv_ui_520e90;
extern "C" int cv_ui_520f50;
extern "C" int cv_ui_520ed0;
extern "C" int cv_ui_521090;
extern "C" int matched_winmain(void)
{
    int r = sub_47AE20(0x400000, 0, (char *)(g_matched_base + 0x662be0), 1);
    fprintf(stderr, "[matched-imports] WinMain body 0x47AE20 returned %d\n", r);
    fprintf(stderr, "[matched-imports] sim ctor hits: 41B760=%d 5B0EC0=%d; vtable slots 00=%d 18=%d 24=%d; DC10=%d status=%X\n",
            g_cvt_ctor41_hits, g_cvt_ctor5b_hits, g_cvt_slot00_hits,
            g_cvt_slot18_hits, g_cvt_slot24_hits, g_cvt_slot36_hits,
            g_cvt_dc10_status);
    fprintf(stderr, "[matched-imports] DC80=%d\n", g_cvt_slot37_hits);
    fprintf(stderr, "[matched-imports] BC80=%d 5B17D0=%d menu-loop=%d\n",
            g_cvt_41bc80_hits, g_cvt_5b17d0_hits, g_cvt_slot04_hits);
    fprintf(stderr, "[matched-imports] window class/create=%d hwnd=%X menu-screen DE50=%d E070=%d\n",
            cv_win_class, cv_win_handle,
            cv_de50_hits, cv_e070_hits);
    fprintf(stderr, "[matched-imports] menu populated: 47C4=%d subobjects 15e8=%d 15f8=%d 15fc=%d 1604=%d 1610=%d; 7B0=%d 5C0=%d preset-entries=%d cfg-sound=%d\n",
            cv_screen47_pop,
            cv_s47_15e8 != 0, cv_s47_15f8 != 0, cv_s47_15fc != 0,
            cv_s47_1604 != 0, cv_s47_1610 != 0,
            cv_screen7b0_pop, cv_screen5c0_pop,
            cv_e070_preset_entries, cv_cfg_sound);
    if (cv_config_ptr != 0)
    {
        char* c = (char*)cv_config_ptr;
        fprintf(stderr, "[matched-imports] cfg probe: base=%p info=%p +0xF4E=\"%s\" +0x930=\"%s\" +0x878=%d +0x8A8=%d\n",
                c, cv_boot_info, c + 0xf4e, c + 0x930,
                *(int*)(c + 0x878), *(int*)(c + 0x8a8));
        fprintf(stderr, "[matched-imports] info probe: +0xF4E=\"%s\" +0x930=\"%s\"\n",
                (char*)cv_boot_info + 0xf4e, (char*)cv_boot_info + 0x930);
    }
    fprintf(stderr, "[matched-imports] matched UI entries: 425650=%d 425680=%d 4256a0=%d 5200F0=%d 520410=%d 520CC0=%d 520DD0=%d 520E10=%d 520E50=%d 520E90=%d 520F50=%d 520ED0=%d 521090=%d\n",
            cv_ui_425650, cv_ui_425680, cv_ui_4256a0,
            cv_ui_5200f0, cv_ui_520410, cv_ui_520cc0,
            cv_ui_520dd0, cv_ui_520e10, cv_ui_520e50,
            cv_ui_520e90, cv_ui_520f50, cv_ui_520ed0,
            cv_ui_521090);
    return r;
}

extern "C" int matched_langtest(void)
{
    int r = sub_47B620((char *)(g_matched_base + 0x64d58c));
    fprintf(stderr, "[matched-imports] language init 0x47B620 returned %d\n", r);
    return r;
}
