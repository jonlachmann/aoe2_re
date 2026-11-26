#include "C_cluster_43EB70.hpp"

MATCH_FUNC(0x43EB80)
void T43EB70::Other_43EB80()
{
    Other_43EB90();
}

MATCH_FUNC(0x43EB90)
void T43EB70::Other_43EB90()
{
    field_00 = -1;
    field_04 = 0;
    field_A8 = 0;
    field_1A4C = 0;
}

MATCH_FUNC(0x43EB60)
void sub_43EB60()
{
    ((T43EB70*)0x665660)->Other_43EB80();
}
