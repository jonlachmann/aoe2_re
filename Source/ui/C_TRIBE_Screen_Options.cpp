#include "C_TRIBE_Screen_Options.hpp"

extern void (__stdcall *g_61C06C)(void* a1, int a2);

MATCH_FUNC(0x4A0890)
void C_TRIBE_Screen_Options::M_4A0890(int a1, int a2, int a3, int a4)
{
    slot_06(0, a1, a2, 0, 0, a3, a3, a4, a4, 0, 0, 0, 0);
}

MATCH_FUNC(0x4A07A0)
void C_TRIBE_Screen_Options::M_4A07A0(int v)
{
    if (field_6C == v)
        return;
    field_6C = v;
    if (v != 0) {
        slot_08(1);
        return;
    }
    this->Hook_4A1CD0();
    if (field_40)
        field_40->Vt_08(1);
}

MATCH_FUNC(0x4A0C60)
void C_TRIBE_Screen_Options::M_4A0C60()
{
    TField20Obj* sub = field_20;
    field_38 = 0;
    if (sub->field_38)
        g_61C06C(sub->field_38, 0);
    field_20->Hook_460660(0);
    field_F7 = 0;
}

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

MATCH_FUNC(0x4A0780)
void C_TRIBE_Screen_Options::M_4A0780(unsigned char v)
{
    field_F3 = v;
    if (field_6C)
        slot_08(2);
}

MATCH_FUNC(0x4A2280)
void C_TRIBE_Screen_Options::M_4A2280()
{
    T4A2280Node* n = field_58;
    while (n)
    {
        n->field_0->Vt_56();
        n = n->field_8;
    }
}

MATCH_FUNC(0x4A22D0)
void C_TRIBE_Screen_Options::M_4A22D0()
{
    T4A2280Node* n = field_58;
    while (n)
    {
        n->field_0->Vt_59();
        n = n->field_8;
    }
}
