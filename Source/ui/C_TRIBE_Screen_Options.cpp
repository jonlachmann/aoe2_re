#include "C_TRIBE_Screen_Options.hpp"

MATCH_FUNC(0x407C00)
int C_TRIBE_Screen_Options::M_407C00(int a, int b)
{
    (void)a; (void)b;
    return 0;
}

MATCH_FUNC(0x407C10)
int C_TRIBE_Screen_Options::M_407C10(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    return 0;
}

MATCH_FUNC(0x4237A0)
void C_TRIBE_Screen_Options::M_4237A0()
{
}

MATCH_FUNC(0x4364F0)
int C_TRIBE_Screen_Options::M_4364F0(int a, int b)
{
    (void)a; (void)b;
    return 0;
}

MATCH_FUNC(0x4474F0)
int C_TRIBE_Screen_Options::Get_4474F0()
{
    return *(int*)((char*)this + 0xfc);
}

MATCH_FUNC(0x447500)
int C_TRIBE_Screen_Options::Get_447500()
{
    return *(int*)((char*)this + 0xf8);
}

MATCH_FUNC(0x4A0BB0)
void C_TRIBE_Screen_Options::M_4A0BB0(int v)
{
    field_F6 = 1;
    Vat_34(v);
    field_F6 = 0;
}

MATCH_FUNC(0x4A2040)
void C_TRIBE_Screen_Options::M_4A2040(int a, int b)
{
    field_60 = a;
    field_64 = b;
    field_74 = 1;
}

MATCH_FUNC(0x4A22F0)
void C_TRIBE_Screen_Options::Get_4A22F0(int* out)
{
    out[0] = *(int*)((char*)this + 0x90);
    out[1] = *(int*)((char*)this + 0x94);
    out[2] = *(int*)((char*)this + 0x98);
    out[3] = *(int*)((char*)this + 0x9c);
}

MATCH_FUNC(0x4A3410)
void C_TRIBE_Screen_Options::SetF8_4A3410(int a, int b)
{
    field_F8 = a;
    field_FC = b;
}

MATCH_FUNC(0x5C6890)
int C_TRIBE_Screen_Options::M_5C6890(int a, int b, int c, int d, int e)
{
    (void)a; (void)b; (void)c; (void)d; (void)e;
    return 0;
}
