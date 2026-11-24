#include "C_vt620A64.hpp"

MATCH_FUNC(0x46A900)
C_vt620A64* C_vt620A64::Ref_46A900()
{
    return (C_vt620A64*)((char*)this + 4);
}

MATCH_FUNC(0x46A940)
C_vt620A64* C_vt620A64::Ref_46A940()
{
    return (C_vt620A64*)((char*)this + 0x10);
}

MATCH_FUNC(0x46A950)
C_vt620A64* C_vt620A64::Ref_46A950()
{
    return (C_vt620A64*)((char*)this + 0x1c);
}

MATCH_FUNC(0x46A960)
C_vt620A64* C_vt620A64::Ref_46A960()
{
    return (C_vt620A64*)((char*)this + 0x28);
}

MATCH_FUNC(0x46A970)
C_vt620A64* C_vt620A64::Ref_46A970()
{
    return (C_vt620A64*)((char*)this + 0x64);
}

MATCH_FUNC(0x46A980)
void C_vt620A64::Copy_46A980(Three46* src)
{
    field_64 = *src;
}

MATCH_FUNC(0x46A9A0)
float C_vt620A64::Get_46A9A0()
{
    return *(float*)((char*)this + 0x6c);
}

MATCH_FUNC(0x46A9B0)
void C_vt620A64::SetInt_46A9B0(int v)
{
    *(int*)((char*)this + 0x6c) = v;
}

MATCH_FUNC(0x46A9C0)
void C_vt620A64::SetInt_46A9C0(int v)
{
    *(int*)((char*)this + 0xb0) = v;
}

MATCH_FUNC(0x46A9D0)
float C_vt620A64::Get_46A9D0()
{
    return *(float*)((char*)this + 0x68);
}

MATCH_FUNC(0x46A9E0)
void C_vt620A64::SetInt_46A9E0(int v)
{
    *(int*)((char*)this + 0x68) = v;
}

MATCH_FUNC(0x46A9F0)
float C_vt620A64::Get_46A9F0()
{
    return *(float*)((char*)this + 0x64);
}

MATCH_FUNC(0x46AA00)
void C_vt620A64::SetInt_46AA00(int v)
{
    *(int*)((char*)this + 0x64) = v;
}

MATCH_FUNC(0x46AA10)
C_vt620A64* C_vt620A64::Ref_46AA10()
{
    return (C_vt620A64*)((char*)this + 0x70);
}

MATCH_FUNC(0x46AA20)
void C_vt620A64::Copy_46AA20(Three46* src)
{
    field_70 = *src;
}

MATCH_FUNC(0x46AA40)
float C_vt620A64::Get_46AA40()
{
    return *(float*)((char*)this + 0x78);
}

MATCH_FUNC(0x46AA50)
void C_vt620A64::SetInt_46AA50(int v)
{
    *(int*)((char*)this + 0x78) = v;
}

MATCH_FUNC(0x46AA60)
float C_vt620A64::Get_46AA60()
{
    return *(float*)((char*)this + 0x74);
}

MATCH_FUNC(0x46AA70)
void C_vt620A64::SetInt_46AA70(int v)
{
    *(int*)((char*)this + 0x74) = v;
}

MATCH_FUNC(0x46AA80)
float C_vt620A64::Get_46AA80()
{
    return *(float*)((char*)this + 0x70);
}

MATCH_FUNC(0x46AA90)
void C_vt620A64::SetInt_46AA90(int v)
{
    *(int*)((char*)this + 0x70) = v;
}

MATCH_FUNC(0x46AAA0)
float C_vt620A64::Get_46AAA0()
{
    return *(float*)((char*)this + 0x94);
}

MATCH_FUNC(0x46AAB0)
float C_vt620A64::Get_46AAB0()
{
    return *(float*)((char*)this + 0x98);
}

MATCH_FUNC(0x46AAC0)
float C_vt620A64::Get_46AAC0()
{
    return *(float*)((char*)this + 0x9c);
}

MATCH_FUNC(0x46AB60)
void C_vt620A64::SetInt_46AB60(int v)
{
    *(int*)((char*)this + 0xac) = v;
}

MATCH_FUNC(0x4886F0)
void C_vt620A64::M_4886F0()
{
    Vat_28(0);
    Vat_4c(0);
}
