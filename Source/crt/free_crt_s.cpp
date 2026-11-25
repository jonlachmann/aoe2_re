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

// 0x5FF22D — forward two arguments plus a zero default.
extern void __cdecl sub_5FF240(int a1, int a2, int a3);
MATCH_FUNC(0x5FF22D)
void __cdecl sub_5FF22D(int a1, int a2)
{
    sub_5FF240(0, a1, a2);
}

// 0x5FCE01 — forward two arguments plus the 0x40 constant.
extern void __cdecl sub_5FCDE1(int a1, int a2, int a3);
MATCH_FUNC(0x5FCE01)
void __cdecl sub_5FCE01(int a1, int a2)
{
    sub_5FCDE1(a1, a2, 0x40);
}

// 0x6032E5 — pop four bytes from an advancing stack cursor.
MATCH_FUNC(0x6032E5)
int __cdecl sub_6032E5(int* p)
{
    *p += 4;
    return *(int*)(*p - 4);
}

// 0x5FD62D — -1 when 0x5FD5C0 returns zero, else 0.
extern int __cdecl sub_5FD5C0(int a1);
MATCH_FUNC(0x5FD62D)
int __cdecl sub_5FD62D(int a1)
{
    if (sub_5FD5C0(a1) == 0)
        return -1;
    return 0;
}

// 0x6033C4 — one-time lazy initializer: run 0x6033D9 on first use and bump
// the global gate.
extern int g_772878;
extern void __cdecl sub_6033D9();
MATCH_FUNC(0x6033C4)
void __cdecl sub_6033C4()
{
    if (g_772878 == 0)
    {
        sub_6033D9();
        g_772878++;
    }
}

// 0x5FE2FA — call every non-null function pointer over [a1, a2).
MATCH_FUNC(0x5FE2FA)
void __cdecl sub_5FE2FA(void** a1, void** a2)
{
    while (a1 < a2)
    {
        void (*fn)() = (void (*)())*a1;
        if (fn != 0)
            fn();
        ++a1;
    }
}

// 0x6026DB — one-byte cursor: decrement +4, consume *+0 when available, else
// refresh through 0x602730.
extern int __cdecl sub_602730(int a1);
MATCH_FUNC(0x6026DB)
__declspec(naked) int __cdecl sub_6026DB(int a1)
{
    __asm
    {
        mov edx, dword ptr [esp + 4]
        dec dword ptr [edx + 4]
        js slow_6026DB
        mov ecx, dword ptr [edx]
        movzx eax, byte ptr [ecx]
        inc ecx
        mov dword ptr [edx], ecx
        ret
    slow_6026DB:
        push edx
        call sub_602730
        pop ecx
        ret
    }
}

// 0x6026F5 — skip when the first argument is -1, else forward both.
extern void __cdecl sub_6070DA(int a1, int a2);
MATCH_FUNC(0x6026F5)
void __cdecl sub_6026F5(int a1, int a2)
{
    if (a1 != -1)
        sub_6070DA(a1, a2);
}

// 0x604208 — one-time lazy -3 invocation gate.
extern void __cdecl sub_603E44(int a1);
extern int g_773e0c;
MATCH_FUNC(0x604208)
void __cdecl sub_604208()
{
    if (g_773e0c == 0)
    {
        sub_603E44(-3);
        g_773e0c = 1;
    }
}

// 0x606958 — mask bit 0x80000 out of the second argument before forwarding
// to the FPU-control helper 0x606923.
extern int __cdecl sub_606923(int a1, int a2);
MATCH_FUNC(0x606958)
void __cdecl sub_606958(int a1, int a2)
{
    sub_606923(a1, a2 & 0xfff7ffff);
}

// 0x5FCDE1 — four-argument forwarder gated by a 0x602979 result.
extern int __cdecl sub_602979();
extern void __cdecl sub_602809(int a1, int a2, int a3, int a4);
// 0x5FDCD4 — four-argument forwarder with the 0x40 option constant in slot 3.
extern void __cdecl sub_5FDCEB(int a1, int a2, int a3, int a4);
MATCH_FUNC(0x5FDCD4)
void __cdecl sub_5FDCD4(int a1, int a2, int a3, int a4)
{
    sub_5FDCEB(a1, a2, 0x40, a3);
}

// 0x5FD7A5 — zero for a null pointer, else the 0x6043AA total plus the
// pointer value itself.
extern int __cdecl sub_6043AA(int a1, int a2);
MATCH_FUNC(0x5FD7A5)
int __cdecl sub_5FD7A5(int a1, int a2)
{
    if (a1 == 0)
        return 0;
    return sub_6043AA(a1, a2) + a1;
}

// 0x5FD0C8 — table lookup fallback for the 0x662160 gate; otherwise probe
// the 0x661F54 pair table and mask bit 8.
extern int g_662160;
extern int g_661f54;
extern int __cdecl sub_603310(int a1, int a2);
MATCH_FUNC(0x5FD0C8)
int __cdecl sub_5FD0C8(int a1)
{
    if (g_662160 > 1)
        return sub_603310(a1, 8);
    unsigned char v = *(unsigned char*)(g_661f54 + a1 * 2);
    return v & 8;
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
// 0x5F9750 — pop one node from the +0x14 free-list head; the first-use
// branch refreshes it through 0x5F94D0 and returns null on failure.
extern int __cdecl sub_5F94D0();
class S5F9750 {
public:
    char pad_00[0x14];
    void* field_14;               // +0x14 free-list head
    void* M_5F9750();
};

MATCH_FUNC(0x5F9750)
__declspec(naked) void* S5F9750::M_5F9750()
{
    __asm
    {
        push esi
        mov esi, ecx
        cmp dword ptr [ecx + 0x14], 0
        jne pop_5F9750
        mov ecx, esi
        call sub_5F94D0
        test eax, eax
        jne pop_5F9750
        xor eax, eax
        pop esi
        ret
    pop_5F9750:
        mov eax, dword ptr [esi + 0x14]
        mov ecx, dword ptr [eax + 8]
        mov dword ptr [esi + 0x14], ecx
        pop esi
        mov dword ptr [eax + 4], -1
        ret
    }
}

