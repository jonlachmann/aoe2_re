#include "C_cluster_520720.hpp"

MATCH_FUNC(0x520720)
C_cluster_520720* C_cluster_520720::M_520720(int a1, int a2, int a3)
{
    (void)a1; (void)a2;
    this->Init_520750();
    field_8 = a3;
    return this;
}

MATCH_FUNC(0x520750)
void C_cluster_520720::Init_520750()
{
    field_0 = 0;
    field_4 = 0;
    field_5 = 0;
    field_1C = 0;
    field_C = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
}
