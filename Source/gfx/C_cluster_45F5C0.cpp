#include "C_cluster_45F5C0.hpp"

#pragma intrinsic(memset)

extern void (__stdcall *g_61C05C)(int a1, int a2, int a3, char* a4);

// 0x45F5C0 — store the argument at +0x08; with a nonzero argument fill the
// first 0x100 bytes of a 0x400-byte stack buffer through 61C05C, otherwise zero
// the whole buffer; then clear its first four bytes, set the last three bytes
// to 0xFF and the final byte to 0, and run 45F6F0(0, 0x100, buffer).
WIP_FUNC(0x45F5C0)
void C_cluster_45F5C0::M_45F5C0(int a1)
{
    field_8 = a1;
    char buf[0x400];
    if (a1 != 0)
        g_61C05C(a1, 0, 0x100, buf);
    else
    {
        char* p = buf;
        for (int i = 0x100; i != 0; i--)
        {
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
        }
    }
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[0x3fc] = 0xff;
    buf[0x3fd] = 0xff;
    buf[0x3fe] = 0xff;
    buf[0x3ff] = 0;
    Hook_45F6F0(0, 0x100, buf);
}

#pragma function(memset)
