// Native probe for the portable guest-VA access layer. A matched body stores a
// 32-bit guest VA in a global; ADDR() offsets that VA by a host-side guest
// image base, so the dereference lands in mapped host memory on a 64-bit host.
#include <cstdio>
#include <cstdlib>

#include "matched_mem.h"
#include "ui/C_vt6234C8.hpp"

extern "C" long g_matched_base = 0;
int g_6645c4 = 0;

int main()
{
    int failures = 0;

    // Host-side guest image: a small block addressed through guest VA 0x1000.
    const unsigned int VA = 0x1000;
    char* img = (char*)calloc(1, 0x2000);
    g_matched_base = (long)img - (long)VA;
    g_6645c4 = (int)VA;
    *(short*)(img + 0x424) = 0x1234;

    C_vt6234C8* a = (C_vt6234C8*)calloc(1, sizeof(C_vt6234C8));

    a->field_81C = 1;
    short hit = a->M_4BDE70();
    if (hit != 0x1234) { printf("M_4BDE70 VA deref: %d != 0x1234\n", hit); failures++; }

    a->field_81C = 2;
    short miss = a->M_4BDE70();
    if (miss != -1) { printf("M_4BDE70 gate: %d != -1\n", miss); failures++; }

    printf("va probe: %d failures (base=%p va=0x%x)\n", failures, (void*)img, VA);
    return failures != 0;
}
