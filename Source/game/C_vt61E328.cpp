#include "C_vt61E328.hpp"

extern float g_61c598;
extern float g_61C584;

MATCH_FUNC(0x434BE0)
float C_vt61E328::Get_434BE0(int unused)
{
    (void)unused;
    return g_61c598;
}

MATCH_FUNC(0x435810)
unsigned char C_vt61E328::M_435810()
{
    if (field_168 > g_61C584)
        return 0;
    else
        return 1;
}

MATCH_FUNC(0x4359B0)
void C_vt61E328::M_4359B0(int* a, int* b)
{
    *a = *(int*)((char*)field_08 + 0x134);
    *b = *(int*)((char*)field_08 + 0x160);
}

MATCH_FUNC(0x4359E0)
void C_vt61E328::M_4359E0(int* a, int* b)
{
    *a = *(int*)((char*)field_08 + 0x140);
    *b = *(int*)((char*)field_08 + 0x164);
}

MATCH_FUNC(0x436B20)
int C_vt61E328::M_436B20()
{
    Vat_40(((S436B20Sub*)field_08)->field_18);
    return 1;
}

MATCH_FUNC(0x436B40)
float C_vt61E328::Get_436B40()
{
    return *(float*)((char*)field_08 + 0x140);
}

MATCH_FUNC(0x436C50)
float C_vt61E328::Get_436C50()
{
    return *(float*)((char*)field_08 + 0x134);
}

MATCH_FUNC(0x436C60)
float C_vt61E328::Get_436C60()
{
    return *(float*)((char*)field_08 + 0x158);
}
