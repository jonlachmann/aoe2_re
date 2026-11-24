/* [aoe2_re] Bring-up shims for the lifted game: the CRT-era kernel32/user32
 * imports win32hle does not answer yet. Each runs as guest-called C via the
 * shim ABI (A32/APTR/ASTR read args, RET/RETP return). */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "win32hle.h"

/* ---- kernel32 gaps the CRT hits ---- */

/* CloseProfileUserMapping: the CRT's _setenvp probes it to decide where the
 * environment comes from. Measured against the lifted CRT at 0x60639E: a
 * nonzero return is taken as a usable handle and the CRT then dereferences it
 * as a string pointer (guest fault at 0x1). Returning 0 sends the CRT down the
 * GetEnvironmentStrings path, which is what a Win32 box with no profile does. */
static void s_CloseProfileUserMapping(void) { RET(0, 0); }

/* IsDBCSLeadByte: CP_ACP lead-byte probe. The CRT uses it to walk the
 * environment; 0 (not a lead byte) is the behavior on a US code page. */
static void s_IsDBCSLeadByte(void) { RET(0, 1); }

/* GetPriorityClass: the game checks its scheduling class; NORMAL is 0x20. */
static void s_GetPriorityClass(void) { RET(0x20, 1); }

/* WinExec: the game would relaunch helper tools; report success but do
 * nothing (the CD check path uses it). */
static void s_WinExec(void) { RET(32, 2); }  /* 32 = success */

/* AddAtomW / the atom family the CRT's profile code uses. */
static void s_AddAtomW(void) { RET(0xC000, 1); }

/* IsBadHugeReadPtr / IsBadHugeWritePtr: 0 = readable/writable. The CRT's
 * heap probes use them; with the guest heap mapped, 0 is right. */
static void s_IsBadHugeReadPtr(void)  { RET(0, 2); }
static void s_IsBadHugeWritePtr(void) { RET(0, 2); }

/* BackupSeek: CRT io helpers probe streams; seek fails cleanly. */
static void s_BackupSeek(void) { RET(0, 7); }

/* CreateEventW: the CRT + game use named events; return a scratch handle. */
static uint32_t g_event_next = 0x7F000000u;
static void s_CreateEventW(void) {
    /* (attrs, manual, initial, name) -> handle; the game only closes/sets it */
    RET(g_event_next++, 4);
}

/* VirtualLock: the game pins its draw buffers; succeed without pinning. */
static void s_VirtualLock(void) { RET(1, 2); }

/* ---- user32 gaps ---- */

static void s_GetWindowThreadProcessId(void) {
    /* (hwnd, &pid) -> tid; the game checks its own window. */
    if (A32(1)) MEM32(A32(1)) = 0x1234u;
    RET(0x5678u, 1);
}
static void s_SetClassLongA(void)   { RET(0, 3); }
static void s_IsIconic(void)        { RET(0, 1); }
static void s_GetLastActivePopup(void) { RET(A32(0), 1); }  /* same hwnd */
static void s_SystemParametersInfoA(void) { RET(1, 4); }

/* ---- msvfw32 / mci (video + MCI) — the game probes codecs at boot ---- */

static void s_ICInfo(void) { RET(0, 3); }          /* no codec matches */
static void s_MCIWndCreateA(void)  { RET(0, 4); }  /* no MCI window */

/* ---- winmm MCI: the game's media-audio/MIDI music driver (0x4988E0) ----
 * mciSendCommandA is stdcall (the caller does no `add esp` after `call edi`),
 * so pop all 4 args. Answer the way a Windows box with no MCI devices would:
 * MCI_OPEN fails with MCIERR_DEVICE_NOT_INSTALLED (306); commands against a
 * device ID that was never opened fail with MCIERR_INVALID_DEVICE_ID (257).
 * The driver's error paths return cleanly (e.g. 0x498AAD), so the game boots
 * without media audio / MIDI music. */
#define MCI_OPEN                        0x0803u
#define MCIERR_INVALID_DEVICE_ID        257u
#define MCIERR_DEVICE_NOT_INSTALLED     306u
static void s_mciSendCommandA(void) {
    uint32_t dev = A32(0), msg = A32(1);
    if (win32hle_trace) fprintf(stderr, "[mci] dev=0x%x msg=0x%04x flags=0x%x\n",
                                dev, msg, A32(2));
    RET(dev || msg == MCI_OPEN ? MCIERR_DEVICE_NOT_INSTALLED
                               : MCIERR_INVALID_DEVICE_ID, 4);
}


/* ---- EBUEula.dll answer ----
 * The game probes EBUEula.dll!GetProcAddress("EBUEula") and calls it with
 * (int flag, 0, char* registryKey) to display/check the EULA. The real DLL
 * shows a dialog and writes the acceptance to the registry. For the bring-up
 * we answer with "accepted" (return 1); the game then reads the registry key
 * itself. */
static void s_EBUEula(void) {
    /* cdecl(4): (flag, 0, keyptr, ?) — the caller cleans up (add esp,0x10
     * at 0x47B708), so pop nothing. return 1 = accepted */
    RET(1, 0);
}

/* ---- dplayx.dll / VERSION.dll: retired 2026-11-23 ----
 * The boot-time DirectX check (sub_465270) is overridden in
 * Source/host/overrides.c (answers "DirectX 6.1a present"), so the
 * GetFileVersionInfo* family is never called. But the boot's network-provider
 * init (0x437932) still calls DirectPlayEnumerateA (IAT 0x61C020, dplayx
 * ordinal 2) with a callback, and an unbound ordinal is a permissive-bind
 * FATAL. Answer the way a Windows box with no DirectPlay providers would:
 * enumeration completes successfully and invokes nothing; the create/lobby
 * ordinals fail with E_FAIL. DirectPlay comes back for real with the net
 * module (step 3-4 of docs/agent_plan.md). */
#define E_FAIL 0x80004005u
static void s_DirectPlayEnumerateA(void) { RET(0, 2); }
static void s_DirectPlayCreate(void)     { RET(E_FAIL, 3); }
static void s_DirectPlayLobbyCreateA(void) { RET(E_FAIL, 5); }

const win32hle_shim win32hle_aoe[] = {
    { "CloseProfileUserMapping",    s_CloseProfileUserMapping },
    { "IsDBCSLeadByte",             s_IsDBCSLeadByte },
    { "GetPriorityClass",           s_GetPriorityClass },
    { "WinExec",                    s_WinExec },
    { "AddAtomW",                   s_AddAtomW },
    { "IsBadHugeReadPtr",           s_IsBadHugeReadPtr },
    { "IsBadHugeWritePtr",          s_IsBadHugeWritePtr },
    { "BackupSeek",                 s_BackupSeek },
    { "CreateEventW",               s_CreateEventW },
    { "VirtualLock",                s_VirtualLock },
    { "GetWindowThreadProcessId",   s_GetWindowThreadProcessId },
    { "SetClassLongA",              s_SetClassLongA },
    { "IsIconic",                   s_IsIconic },
    { "GetLastActivePopup",         s_GetLastActivePopup },
    { "SystemParametersInfoA",      s_SystemParametersInfoA },
    { "EBUEula",                    s_EBUEula },
    { "ICInfo",                     s_ICInfo },
    { "MCIWndCreateA",              s_MCIWndCreateA },
    { "mciSendCommandA",            s_mciSendCommandA },
    { "dplayx.dll#1",               s_DirectPlayCreate },
    { "dplayx.dll#2",               s_DirectPlayEnumerateA },
    { "dplayx.dll#4",               s_DirectPlayLobbyCreateA },
    { "DirectPlayCreate",           s_DirectPlayCreate },
    { "DirectPlayEnumerateA",       s_DirectPlayEnumerateA },
    { "DirectPlayLobbyCreateA",     s_DirectPlayLobbyCreateA },
    { 0, 0 },
};
