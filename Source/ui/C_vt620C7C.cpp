#include "C_vt620C7C.hpp"

extern float g_61dd2c;
extern float g_621178;

MATCH_FUNC(0x473C70)
float C_vt620C7C::Get_473C70()
{
    return *(float*)((char*)this + 0xe4);
}

MATCH_FUNC(0x473C80)
float C_vt620C7C::Get_473C80()
{
    return *(float*)((char*)this + 0xe8);
}

MATCH_FUNC(0x473C90)
float C_vt620C7C::Get_473C90()
{
    return *(float*)((char*)this + 0xec);
}

MATCH_FUNC(0x473CA0)
float C_vt620C7C::Get_473CA0()
{
    return *(float*)((char*)this + 0xf4);
}

MATCH_FUNC(0x477990)
float C_vt620C7C::Get_477990(int unused)
{
    (void)unused;
    return *(float*)((char*)this + 0xc4);
}

MATCH_FUNC(0x4779A0)
float C_vt620C7C::Get_4779A0(int unused)
{
    (void)unused;
    return g_61dd2c;
}

MATCH_FUNC(0x4779B0)
float C_vt620C7C::Get_4779B0(int unused)
{
    (void)unused;
    return g_621178;
}
