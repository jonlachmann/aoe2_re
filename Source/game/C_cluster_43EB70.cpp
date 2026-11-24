#include "C_cluster_43EB70.hpp"

MATCH_FUNC(0x43EB80)
void C_cluster_43EB70::Forward_43EB80()
{
    Init_43EB90();
}

MATCH_FUNC(0x43EB90)
void C_cluster_43EB70::Init_43EB90()
{
    field_00 = -1;
    field_04 = 0;
    field_A8 = 0;
    field_1A4C = 0;
}

MATCH_FUNC(0x43EB60)
void sub_43EB60()
{
    ((C_cluster_43EB70*)0x665660)->Forward_43EB80();
}
