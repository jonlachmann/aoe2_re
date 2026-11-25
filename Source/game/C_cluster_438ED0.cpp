#include "C_cluster_438ED0.hpp"

MATCH_FUNC(0x438ED0)
C_cluster_438ED0* C_cluster_438ED0::M_438ED0(T438ED0Obj* owner)
{
    field_0 = owner;
    field_e54 = 0;
    field_e58 = 0;
    this->M_439950();
    return this;
}

MATCH_FUNC(0x439950)
void C_cluster_438ED0::M_439950()
{
    field_4 = field_0->field_160c;
    this->Hook_439030();
    this->Hook_439410(&field_0c);
}
