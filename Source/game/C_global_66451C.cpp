#include "C_global_66451C.hpp"

MATCH_FUNC(0x42FD20)
void C_global_66451C::Init_42FD20()
{
    field_17e4 = -1;
    field_1b7c = 0;
    this->Hook_4308C0();
    field_17f8 = 0;
    field_1bb4 = 1;
}

MATCH_FUNC(0x42FD60)
void C_global_66451C::Init_42FD60()
{
    field_1a50 = -1;
    for (int i = 0; i < 10; ++i) {
        array_1a64[i] = 0;
        array_1adc[i] = 0xc800;
        array_1b04[i] = 0xc800;
        array_1b80[i] = 0;
    }
    field_1bac = 0;
    field_1bb8 = 0x100;
}

MATCH_FUNC(0x42FBC0)
int C_global_66451C::Get_42FBC0()
{
    return *(int*)((char*)this + 0x2008);
}

MATCH_FUNC(0x4308C0)
void C_global_66451C::Hook_4308C0()
{
    for (int i = 0; i < 8; ++i)
        ((unsigned char*)this)[0x3860 + i * 0x20c] = 0;
}

MATCH_FUNC(0x432B30)
void C_global_66451C::Set_432B30(int index, int v)
{
    array_267C[index] = v;
}
