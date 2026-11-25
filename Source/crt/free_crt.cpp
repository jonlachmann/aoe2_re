// free_crt — CRT-region free functions migrated from Source/simple.
// Standard /O2 bodies (the size-optimized pair lives in free_crt_s.cpp).
#include "Function.hpp"


class S407B80 {
public:
    int M_407B80(int);
};
class S407BC0 {
public:
    bool M_407BC0(int);
};
class S407C00 {
public:
    int M_407C00(int, int);
};
class S407C10 {
public:
    int M_407C10(int, int, int, int);
};
class S407C20 {
public:
    int M_407C20(int, int, int);
};
class S407C30 {
public:
    int M_407C30(int, int, int, int, int, int);
};
class S407C40 {
public:
    int M_407C40(int, int, int, int, int);
};
class S407C60 {
public:
    int M_407C60(int);
};
class S409A20 {
public:
    bool M_409A20(int);
};
class S409A30 {
public:
    bool M_409A30(int, int);
};
class S41A050 {
public:
    bool M_41A050(int, int, int, int);
};
class S41A070 {
public:
    int M_41A070(int, int, int, int, int, int, int, int, int);
};
class S41A080 {
public:
    int M_41A080(int, int, int, int, int, int, int, int, int, int, int, int);
};
class S41A0C0 {
public:
    int M_41A0C0(int, int, int);
};
class S4364F0 {
public:
    int M_4364F0(int, int);
};
class S47EED0 {
public:
    bool M_47EED0(int, int, int, int);
};
class S5A4790 {
public:
    int M_5A4790(int);
};
class S5C6880 {
public:
    int M_5C6880(int, int, int, int);
};
class S5C6890 {
public:
    int M_5C6890(int, int, int, int, int);
};
class S5EA410 {
public:
    int M_5EA410(int);
};
MATCH_FUNC(0x5F0BE0)
int M_5F0BE0()
{
    return 0;
}

MATCH_FUNC(0x5F0CB0)
bool Check_5F0CB0(int* p)
{
    return *(int*)((char*)p + 8) == 0;
}

class S5F0CC0Node {
public:
    char pad_00[4];
    int field_4;
};



class S5F0CC0 {
public:
    char pad_00[8];
    void* field_8;
    S5F0CC0Node* field_c;
};

MATCH_FUNC(0x5F0CC0)
int Get_5F0CC0(S5F0CC0* obj)
{
    if (obj->field_8 != 0)
        return 0;
    return obj->field_c->field_4;
}

class S5F3200 {
public:
    char pad_00[0xc];
    int field_c;
    int field_10;
    int field_14;
    int field_18;
};

MATCH_FUNC(0x5F3200)
void Set_5F3200(S5F3200* obj)
{
    int v = obj->field_c;
    obj->field_18 = 0;
    obj->field_10 = v;
    obj->field_14 = v;
}

struct Three46 {
    int a;
    int b;
    int c;
};

class S46A980 {
public:
    char pad_00[0x64];
    Three46 field_64;
    void Copy_46A980(Three46* src);
};

class S46AA20 {
public:
    char pad_00[0x70];
    Three46 field_70;
    void Copy_46AA20(Three46* src);
};

MATCH_FUNC(0x5F3FB0)
void Build_5F3FB0(int* out, int a, int b)
{
    out[0] = a;
    out[1] = a + b;
    out[3] = a;
    out[2] = a;
}

WIP_FUNC(0x5F9100)
int M_5F9100()
{
    int result = -1;
    return result;
}

class S407BD0 {
public:
    bool M_407BD0(int unused);
};

MATCH_FUNC(0x5FB450)
int M_5FB450()
{
    return 1;
}

MATCH_FUNC(0x5FB460)
void M_5FB460()
{
}

MATCH_FUNC(0x5FBDE7)
int M_5FBDE7()
{
    return 1;
}

MATCH_FUNC(0x5FC8EB)
void M_5FC8EB()
{
}

MATCH_FUNC(0x5FC8EC)
void Init_5FC8EC()
{
    *(int*)0x661cac = 0x600f6b;
    *(int*)0x661ca8 = 0x6012d6;
    *(int*)0x661cb0 = 0x600fd1;
    *(int*)0x661cb4 = 0x600f11;
    *(int*)0x661cb8 = 0x600fb9;
    *(int*)0x661cbc = 0x6012d6;
}

extern int g_661c14;
MATCH_FUNC(0x5FCA3B)
void Set_5FCA3B(int v)
{
    g_661c14 = v;
}

extern int g_77279c;
MATCH_FUNC(0x6004B7)
int Get_6004B7()
{
    return g_77279c;
}

extern int g_772a1c;
MATCH_FUNC(0x6004BD)
int Get_6004BD()
{
    return g_772a1c;
}
MATCH_FUNC(0x60700F)
int M_60700F()
{
    return 0;
}

// Tail-jump forwarders (CRT region).
void sub_5F9200();
void sub_6005A4();
void sub_600DEC();

MATCH_FUNC(0x5F9230)
void sub_5F9230()
{
    sub_5F9200();
}

MATCH_FUNC(0x600E3D)
void sub_600E3D()
{
    sub_6005A4();
}

MATCH_FUNC(0x600E93)
void sub_600E93()
{
    sub_600DEC();
}

// 0x5F38C0 — cdecl forwarder to 0x5F46A0 with one argument.
extern int __cdecl sub_5F46A0(int a1);
MATCH_FUNC(0x5F38C0)
int __cdecl sub_5F38C0(int a1)
{
    return sub_5F46A0(a1);
}

// 0x5F91F0 — mask the helper result to a multiple of four.
extern int __stdcall sub_5FA940(int a1);
WIP_FUNC(0x5F91F0)
int __cdecl sub_5F91F0(int a1)
{
    return sub_5FA940(a1) & 0xFFFFFFFC;
}

// 0x5FD518 — cdecl helper call with constant one.
extern void __cdecl sub_5FD521(int a1);
MATCH_FUNC(0x5FD518)
void __cdecl sub_5FD518()
{
    sub_5FD521(1);
}

// 0x6198E0 — low byte of the global dword.
extern int g_774040;
MATCH_FUNC(0x6198E0)
int M_6198E0()
{
    return g_774040 & 0xFF;
}

// 0x6199C0 — store the argument in the global dword (frame pointer kept).
extern int g_77401C;
#pragma optimize("y", off)
MATCH_FUNC(0x6199C0)
void __cdecl sub_6199C0(int a1)
{
    g_77401C = a1;
}
#pragma optimize("y", on)
