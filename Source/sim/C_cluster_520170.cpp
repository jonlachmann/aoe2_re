#include "C_cluster_520170.hpp"

MATCH_FUNC(0x5203C0)
void C_cluster_520170::M_5203C0(char* src)
{
    if (src)
        strcpy(&field_20, src);
    else
        field_20 = 0;
}
