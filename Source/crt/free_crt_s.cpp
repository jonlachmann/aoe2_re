// free_crt_s — size-optimized CRT leaves migrated from Source/simple.
// CRT code at 0x5FE000+ is compiled with #pragma optimize("s", on).
#include "Function.hpp"

#pragma optimize("s", on)
#pragma intrinsic(memset)

extern unsigned char g_772bc1[256];   // _mbctype + 1

// _mbsinc: skip a lead byte's trail byte. CRT code is size-optimized (movzx
// instead of xor+mov).

MATCH_FUNC(0x5FF5E6)
char* Skip_5FF5E6(char* p)
{
    if (g_772bc1[(unsigned char)*p++] & 4)
        ++p;
    return p;
}

extern double g_61c690;

// CRT code (0x5FE000+) is size-optimized: sahf/jb and `push 1; pop eax`.

MATCH_FUNC(0x600FB9)
int Cmp_600FB9(double* value)
{
    if (*value >= g_61c690)
        return 1;
    return 0;
}

// Trivial constant-one CRT leaves (size-optimized).
MATCH_FUNC(0x600D09)
int M_600D09() { return 1; }
MATCH_FUNC(0x600E29)
int M_600E29() { return 1; }
MATCH_FUNC(0x600E7F)
int M_600E7F() { return 1; }
MATCH_FUNC(0x60435A)
int M_60435A() { return 1; }
MATCH_FUNC(0x6048F0)
int M_6048F0() { return 1; }
MATCH_FUNC(0x6049A4)
int M_6049A4() { return 1; }
MATCH_FUNC(0x608472)
int M_608472() { return 1; }
MATCH_FUNC(0x6084E1)
int M_6084E1() { return 1; }

// Size-optimized CRT one-argument wrappers.
extern void __cdecl sub_5FCC3E(int a1);
MATCH_FUNC(0x5FCC68)
void __cdecl sub_5FCC68(int a1) { sub_5FCC3E(a1); }

extern void __cdecl sub_5FCFDC(int a1);
MATCH_FUNC(0x5FD067)
void __cdecl sub_5FD067(int a1) { sub_5FCFDC(a1); }

extern void __cdecl sub_5FD847(int a1, int a2);
MATCH_FUNC(0x5FD839)
void __cdecl sub_5FD839(int a1) { sub_5FD847(a1, 1); }

extern void __cdecl sub_5FDFB5(int a1, int a2, int a3);
MATCH_FUNC(0x5FDFA4)
void __cdecl sub_5FDFA4(int a1) { sub_5FDFB5(a1, 0, 1); }

extern void __cdecl sub_5FE261(int a1, int a2, int a3);
MATCH_FUNC(0x5FE23F)
void __cdecl sub_5FE23F(int a1) { sub_5FE261(a1, 0, 0); }

MATCH_FUNC(0x5FE250)
void __cdecl sub_5FE250(int a1) { sub_5FE261(a1, 1, 0); }

extern void __cdecl sub_600377(int a1);
MATCH_FUNC(0x607006)
void __cdecl sub_607006() { sub_600377(2); }

extern void __cdecl sub_607A46(int a1, int a2, int a3);
MATCH_FUNC(0x607A35)
void __cdecl sub_607A35(int a1) { sub_607A46(a1, 0, 4); }

// 0x6068C6 — call the function pointer global with the global argument.
extern int g_772A34;
extern void (__stdcall *g_61C14C)(int a1);
MATCH_FUNC(0x6068C6)
void __cdecl sub_6068C6()
{
    g_61C14C(g_772A34);
}

// 0x606BCF — zero three dwords through a pointer argument.
MATCH_FUNC(0x606BCF)
void __cdecl sub_606BCF(int* p)
{
    memset(p, 0, 12);
}

// 0x6087E0.. — function-pointer global thunks.
extern void (__cdecl *g_61C3F0)();
extern void (__cdecl *g_61C3F8)();
extern void (__cdecl *g_61C3EC)();
extern void (__cdecl *g_61C3F4)();
extern void (__cdecl *g_61C224)();
MATCH_FUNC(0x6087E0)
void __cdecl sub_6087E0() { g_61C3F0(); }
MATCH_FUNC(0x6087E6)
void __cdecl sub_6087E6() { g_61C3F8(); }
MATCH_FUNC(0x6087EC)
void __cdecl sub_6087EC() { g_61C3EC(); }
MATCH_FUNC(0x6087F2)
void __cdecl sub_6087F2() { g_61C3F4(); }
MATCH_FUNC(0x6087F8)
void __cdecl sub_6087F8() { g_61C224(); }

// 0x603B83 — call the helper then forward when the global flag is set.
extern void __cdecl sub_5FD518();
extern unsigned char g_772780;
extern void __cdecl sub_607382();
MATCH_FUNC(0x603B83)
void __cdecl sub_603B83()
{
    sub_5FD518();
    if (g_772780)
        sub_607382();
}

// 0x600E98 — two-argument cdecl wrapper with constant arguments.
extern void __cdecl sub_606958(int a1, int a2);
MATCH_FUNC(0x600E98)
void __cdecl sub_600E98()
{
    sub_606958(0x10000, 0x30000);
}

// 0x61006E — function-pointer global thunk.
extern void (__cdecl *g_774044)();
MATCH_FUNC(0x61006E)
void __cdecl sub_61006E()
{
    g_774044();
}
