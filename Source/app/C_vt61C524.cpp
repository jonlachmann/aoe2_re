#include "C_vt61C524.hpp"

MATCH_FUNC(0x409A00)
unsigned short C_vt61C524::Get_409A00()
{
    return *(unsigned short*)((char*)this + 0x4);
}

MATCH_FUNC(0x409A20)
bool C_vt61C524::M_409A20(int unused)
{
    (void)unused;
    return false;
}

MATCH_FUNC(0x409A30)
bool C_vt61C524::M_409A30(int a, int b)
{
    (void)a; (void)b;
    return false;
}
