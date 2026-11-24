#include "C_vt61DE70.hpp"

MATCH_FUNC(0x41ADA0)
void C_vt61DE70::Init_41ADA0()
{
    *(int*)((char*)this) = 0x61de70;
    *(int*)((char*)this + 4) = 0;
}

MATCH_FUNC(0x41ADB0)
void C_vt61DE70::M_41ADB0(int a, int b)
{
    int* f = (int*)this;
    f[0x0c / 4] = a;
    f[0x10 / 4] = b;
}

MATCH_FUNC(0x41AF50)
void C_vt61DE70::Set_41AF50(unsigned short v)
{
    *(unsigned short*)((char*)this + 0x14) = v;
}

MATCH_FUNC(0x41AF90)
bool C_vt61DE70::M_41AF90(int unused)
{
    (void)unused;
    return true;
}

MATCH_FUNC(0x41B5F0)
unsigned short C_vt61DE70::Get_41B5F0()
{
    return *(unsigned short*)((char*)this + 0x14);
}
