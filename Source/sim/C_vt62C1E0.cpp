#include "C_vt62C1E0.hpp"

extern unsigned char g_75fdc4;

MATCH_FUNC(0x421750)
float C_vt62C1E0::Get924_421750() { return field_924; }

MATCH_FUNC(0x421760)
int C_vt62C1E0::Get928_421760() { return field_928; }

MATCH_FUNC(0x421780)
int C_vt62C1E0::Get9D4_421780() { return field_9D4; }

MATCH_FUNC(0x4217A0)
char* C_vt62C1E0::Ptr9A9_4217A0() { return (char*)this + 0x929; }

MATCH_FUNC(0x4217B0)
int C_vt62C1E0::Get9A9_4217B0() { return field_9A9; }

MATCH_FUNC(0x4217C0)
int C_vt62C1E0::Get9AA_4217C0() { return field_9AA; }

MATCH_FUNC(0x421A60)
void C_vt62C1E0::Set928_421A60(unsigned char v) { field_928 = v; }

MATCH_FUNC(0x421AB0)
void C_vt62C1E0::Set9D4_421AB0(int v) { field_9D4 = v; }

MATCH_FUNC(0x421AC0)
void C_vt62C1E0::Set9D8_421AC0(int v) { field_9D8 = v; }

MATCH_FUNC(0x421AD0)
void C_vt62C1E0::M_421AD0(int v)
{
    field_9A9 = (unsigned char)v;
    field_9AA = (v == 0);
}

MATCH_FUNC(0x421B10)
void C_vt62C1E0::M_421B10(unsigned char a, unsigned char b, unsigned char c)
{
    field_9AB = a;
    field_9AC = b;
    field_9AD = c;
}

MATCH_FUNC(0x421B40)
void C_vt62C1E0::Set9AE_421B40(unsigned char v) { field_9AE = v; }

MATCH_FUNC(0x421B70)
void C_vt62C1E0::Set9B1_421B70(unsigned char v) { field_9B1 = v; }

MATCH_FUNC(0x421C20)
void C_vt62C1E0::Set9BE_421C20(unsigned char v) { field_9BE = v; }

MATCH_FUNC(0x421CF0)
void C_vt62C1E0::SetC9_421CF0() { field_9C9 = 1; }

MATCH_FUNC(0x421D00)
void C_vt62C1E0::SetCA_421D00() { field_9CA = 1; }

MATCH_FUNC(0x421D30)
void C_vt62C1E0::ClearC9_421D30() { field_9C9 = 0; }

MATCH_FUNC(0x421D40)
void C_vt62C1E0::ClearCA_421D40() { field_9CA = 0; }

MATCH_FUNC(0x421D70)
void C_vt62C1E0::ConditionC9_421D70(unsigned char v)
{
    if (v != 0)
        SetC9_421CF0();
    else
        ClearC9_421D30();
}

MATCH_FUNC(0x421D90)
void C_vt62C1E0::ConditionCA_421D90(unsigned char v)
{
    if (v != 0)
        SetCA_421D00();
    else
        ClearCA_421D40();
}

MATCH_FUNC(0x422320)
int C_vt62C1E0::Get_422320() { return field_1090; }

MATCH_FUNC(0x5B5C50)
void C_vt62C1E0::Wrap_5B5C50()
{
    if (*(void**)((char*)this + 0x149c))
        (*(T4DF8F0**)((char*)this + 0x149c))->M_4DF8F0(
            (char*)this + 0x430, (char*)this + 0x19b8);
}

MATCH_FUNC(0x5BAD50)
int C_vt62C1E0::Get_5BAD50()
{
    return *(int*)((char*)this + 0x11d8);
}

MATCH_FUNC(0x5BAD60)
void C_vt62C1E0::SetInt_5BAD60(int v)
{
    *(int*)((char*)this + 0x11d8) = v;
}

MATCH_FUNC(0x5BAD70)
int C_vt62C1E0::Get_5BAD70()
{
    return *(int*)((char*)this + 0x11d0);
}

MATCH_FUNC(0x5BAEA0)
int C_vt62C1E0::Get_5BAEA0()
{
    return *(int*)((char*)this + 0x11d4);
}

MATCH_FUNC(0x5BAEB0)
char* C_vt62C1E0::Get_5BAEB0()
{
    return (char*)this + 0x1240;
}

MATCH_FUNC(0x5BAF20)
void C_vt62C1E0::SetInt_5BAF20(int v)
{
    *(int*)((char*)this + 0x11dc) = v;
}

MATCH_FUNC(0x5BAF40)
void C_vt62C1E0::SetInt_5BAF40(int v)
{
    *(int*)((char*)this + 0x11e0) = v;
}

MATCH_FUNC(0x5BAF70)
void C_vt62C1E0::Set_5BAF70(int a, int b)
{
    field_11E4 = a;
    field_11E8 = b;
}

MATCH_FUNC(0x5BAFA0)
void C_vt62C1E0::SetByte_5BAFA0(int index, unsigned char v)
{
    array_11EC[index] = v;
}

MATCH_FUNC(0x5BAFD0)
void C_vt62C1E0::SetInt_5BAFD0(int index, int v)
{
    array_11F8[index] = v;
}

WIP_FUNC(0x5BB000)
int C_vt62C1E0::Set_5BB000(int a2, int a3)
{
    int result = a2;
    char v4;
    int idx = a2 + 4636;
    if (a2 == 1) {
        v4 = (char)a3;
        if (a3 == a2) {
            ((char*)this)[idx] = (char)a2;
            return result;
        }
    } else {
        v4 = (char)a3;
    }
    ((char*)this)[idx] = v4;
    return result;
}

MATCH_FUNC(0x5BB040)
void C_vt62C1E0::SetByte2_5BB040(int index, unsigned char v)
{
    *((unsigned char*)this + 0x1225 + index) = v;
}

MATCH_FUNC(0x5BB170)
void C_vt62C1E0::SetByte_5BB170(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x122e) = v;
}

MATCH_FUNC(0x5BB180)
void C_vt62C1E0::SetByte_5BB180(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x122f) = v;
}

MATCH_FUNC(0x5BB190)
void C_vt62C1E0::SetByte_5BB190(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1230) = v;
}

MATCH_FUNC(0x5BB1A0)
void C_vt62C1E0::SetByte_5BB1A0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1231) = v;
}

MATCH_FUNC(0x5BB1B0)
void C_vt62C1E0::SetInt_5BB1B0(int v)
{
    *(int*)((char*)this + 0x1234) = v;
}

MATCH_FUNC(0x5BB1C0)
void C_vt62C1E0::SetInt_5BB1C0(int v)
{
    *(int*)((char*)this + 0x1238) = v;
}

MATCH_FUNC(0x5BB1D0)
void C_vt62C1E0::SetByte_5BB1D0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123c) = v;
}

MATCH_FUNC(0x5BB1E0)
void C_vt62C1E0::SetByte_5BB1E0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123d) = v;
}

MATCH_FUNC(0x5BB1F0)
void C_vt62C1E0::SetByte_5BB1F0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123e) = v;
}

MATCH_FUNC(0x5BB200)
void C_vt62C1E0::SetByte_5BB200(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123f) = v;
}

MATCH_FUNC(0x5BB210)
void C_vt62C1E0::SetByte_5BB210(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1adc) = v;
}

MATCH_FUNC(0x5BB220)
void C_vt62C1E0::SetInt_5BB220(int v)
{
    *(int*)((char*)this + 0x1ae0) = v;
}

MATCH_FUNC(0x5BB230)
unsigned char* C_vt62C1E0::Clear_5BB230()
{
    g_75fdc4 = 0;
    return &g_75fdc4;
}

MATCH_FUNC(0x5BC4D0)
void C_vt62C1E0::Set_5BC4D0(int a, int b, int c, int d)
{
    *(int*)((char*)this + 0x11c0) = a;
    *(int*)((char*)this + 0x11c4) = b;
    *(int*)((char*)this + 0x11c8) = c;
    *(int*)((char*)this + 0x11cc) = d;
}
