#include "C_global_66451C.hpp"

MATCH_FUNC(0x42FBC0)
int C_global_66451C::Get_42FBC0()
{
    return *(int*)((char*)this + 0x2008);
}

MATCH_FUNC(0x4308C0)
void C_global_66451C::Clear_4308C0()
{
    for (int i = 0; i < 8; ++i)
        ((unsigned char*)this)[0x3860 + i * 0x20c] = 0;
}

MATCH_FUNC(0x432B30)
void C_global_66451C::Set_432B30(int index, int v)
{
    array_267C[index] = v;
}
