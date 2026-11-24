#include "C_cluster_4BD5A0.hpp"

MATCH_FUNC(0x4BD5B0)
int C_cluster_4BD5A0::M_4BD5B0(int idx)
{
    int i = 0;
    for (N4BD5B0* n = list_F8; n; n = n->next_24) {
        if (i == idx)
            return n->value_8;
        i++;
    }
    return -1;
}
