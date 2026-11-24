#include "C_cluster_4ACB80.hpp"

MATCH_FUNC(0x4ACB80)
void C_cluster_4ACB80::SetOne_4ACB80()
{
    if (field_A2 == 0)
        V1(1);
}

MATCH_FUNC(0x4AD440)
char C_cluster_4ACB80::M_4AD440(int index)
{
    char* base = (char*)field_D4;
    return base[index];
}
