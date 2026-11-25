#include "C_cluster_472AA0.hpp"

MATCH_FUNC(0x472AA0)
C_cluster_472AA0* C_cluster_472AA0::Init_472AA0(int a1, int a2)
{
    *(void**)this = (void*)0x620b74;
    M_472B00();
    this->Hook_472B20(a1, a2);
    return this;
}

MATCH_FUNC(0x472B00)
void C_cluster_472AA0::M_472B00()
{
    field_8 = 0;
    field_C = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_4 = 0;
}
