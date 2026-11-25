#include "C_vt6230B0.hpp"

MATCH_FUNC(0x4B9D20)
C_vt6230B0* C_vt6230B0::Init_4B9D20()
{
    this->Hook_4B8730();
    field_1c8 = 1;
    field_1cc = 0;
    *(void**)this = (void*)0x6230b0;
    return this;
}

MATCH_FUNC(0x4B9E00)
void C_vt6230B0::slot03_4B9E00(int a1, int a2, int a3, int a4)
{
    this->Hook_4B8910(a1, a2, a3, a4);
}
