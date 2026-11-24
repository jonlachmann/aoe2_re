#include "C_vt62C9CC.hpp"

MATCH_FUNC(0x5E68D0)
char C_vt62C9CC::Get_5E68D0()
{
    return *(char*)((char*)this + 0x29);
}

MATCH_FUNC(0x5E4380)
void C_vt62C9CC::M_5E4380(int arg)
{
    Vat_34(arg);
}

MATCH_FUNC(0x5E3BE0)
void C_vt62C9CC::M_5E3BE0(int a, int b, int c, int d)
{
    field_34->Vt_2(a, b, c, d);
}
