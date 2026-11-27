#include "C_vt622368.hpp"

MATCH_FUNC(0x4AA5D0)
void C_vt622368::M_4AA5D0(int a, int b, int c)
{
    (void)a; (void)b; (void)c;
}

MATCH_FUNC(0x4AAFC0)
void C_vt622368::M_4AAFC0(int a, int b, int c, int d, int e)
{
    (void)a; (void)b; (void)c; (void)d; (void)e;
}

MATCH_FUNC(0x4AC9F0)
void C_vt622368::Call_4AC9F0(int v)
{
    ((S4AC9Sub*)field_84)->V3(v);
}

MATCH_FUNC(0x4ADF90)
int __stdcall C_vt622368::M_4ADF90(int a1, int a2, int a3, int a4, int a5,
                                   int* p6, int* p7)
{
    (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    *p6 = 0;
    *p7 = 0;
    return 0;
}

MATCH_FUNC(0x4AE900)
void C_vt622368::M_4AE900(int a, int b, int c, int d, int e, int f)
{
    (void)a; (void)b; (void)c; (void)d; (void)e; (void)f;
}

// 0x4AD530 — clear the +0x194..+0x1A0 short pair set to -1, zero +0x24C and
// +0x1A4, memset +0x1A8 (0xA0 bytes) and the +0x250..+0x2CE span (0x7F bytes,
// which expands to 0x1F stosd plus a stosw/stosb tail).
WIP_FUNC(0x4AD530)
#pragma intrinsic(memset)
void C_vt622368::M_4AD530()
{
    int result;
    *(short*)((char*)this + 0x194) = -1;
    *(short*)((char*)this + 0x196) = -1;
    *(short*)((char*)this + 0x198) = -1;
    *(short*)((char*)this + 0x19a) = -1;
    *(short*)((char*)this + 0x19c) = -1;
    *(short*)((char*)this + 0x19e) = -1;
    *(short*)((char*)this + 0x1a0) = -1;
    result = 0;
    *(int*)((char*)this + 0x24c) = result;
    *(int*)((char*)this + 0x1a4) = result;
    memset((char*)this + 0x1a8, result, 0xa0);
    memset((char*)this + 0x250, result, 0x7f);
}
