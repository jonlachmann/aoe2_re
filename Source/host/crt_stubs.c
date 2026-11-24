/* [aoe2_re] CRT entry stubs the catalog missed (guest code that the lift did
 * not emit as a body). Each is hand-lifted from the original bytes.
 *
 * sub_006068B5 (CRT init table entry at 0x64D050):
 *   push 0x0060686F        ; the CRT's unhandled-filter thunk
 *   call [0x0061C14C]      ; SetUnhandledExceptionFilter
 *   mov [0x00772A34], eax
 *   ret
 */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "win32hle.h"
#include "recomp_types.h"

extern const win32hle_shim win32hle_kernel32_crt[];

static const win32hle_shim* find_shim(const char* name) {
    for (const win32hle_shim* s = win32hle_kernel32_crt; s->name; s++)
        if (!strcmp(s->name, name)) return s;
    return 0;
}

void sub_006068B5(void);
void sub_006068B5(void) {
    const win32hle_shim* s = find_shim("SetUnhandledExceptionFilter");
    if (!s) {
        fprintf(stderr, "[crt_stubs] SetUnhandledExceptionFilter shim missing\n");
        g_eax = 0;
        return;
    }
    /* Shim ABI: push the argument, call; the shim runs with the guest stack. */
    g_esp -= 4;
    MEM32(g_esp) = 0x0060686Fu;   /* push 0x60686f */
    s->fn();
    MEM32(0x00772A34u) = g_eax;
}
