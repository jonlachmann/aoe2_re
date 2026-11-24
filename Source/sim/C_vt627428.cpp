#include "C_vt627428.hpp"

extern float g_61C584;

MATCH_FUNC(0x52CB50)
int C_vt627428::Get_52CB50()
{
    return *(int*)((char*)this + 0x1a0);
}

MATCH_FUNC(0x52CB60)
int C_vt627428::Get_52CB60()
{
    return *(int*)((char*)this + 0x23c);
}

MATCH_FUNC(0x531B00)
int C_vt627428::Diff_531B00()
{
    if (field_24 == 0)
        return 0;
    return ((S531B00Node*)field_24)->field_4 - field_1F8;
}

MATCH_FUNC(0x531F00)
int C_vt627428::Get_531F00(int index)
{
    int* v2;
    if (index >= 0 && index < 4 && (v2 = this->table[index]) != 0)
        return *(int*)((char*)v2 + 4);
    else
        return -1;
}

MATCH_FUNC(0x535E70)
bool __stdcall C_vt627428::M_535E70(int id)
{
    if (id == 0x32 || id == 0x2d)
        return true;
    return false;
}

MATCH_FUNC(0x535E90)
char C_vt627428::Check_535E90(int a2)
{
    int* v2 = (int*)this->field_08;
    int v3 = *(__int16*)((char*)v2 + 22);
    char result;
    if (v3 != 9 && v3 != 10 && v3 != 58 || a2 == 4 ||
        *(unsigned char*)((char*)v2 + 4) == 60)
        result = 1;
    else
        result = 0;
    return result;
}

MATCH_FUNC(0x535EC0)
unsigned char C_vt627428::IsOther_535EC0()
{
    int v = ((S535EC0Sub*)field_08)->field_16;
    if (v == 0x15 || v == 2)
        return 0;
    return 1;
}

MATCH_FUNC(0x537D50)
int C_vt627428::Tick_537D50()
{
    ++field_1A0;
    return 1;
}

MATCH_FUNC(0x537D70)
int C_vt627428::Pop_537D70()
{
    if (field_1A0 < 1)
        return 0;
    --field_1A0;
    return 1;
}

MATCH_FUNC(0x537D90)
float C_vt627428::M_537D90()
{
    if (field_1A0 > 0)
        return g_61C584;
    return Sub_48E2D0();
}

MATCH_FUNC(0x530AC0)
void C_vt627428::M_530AC0()
{
    ((T537150*)this)->M_537150();
}
