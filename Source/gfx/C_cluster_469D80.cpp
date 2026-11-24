#include "C_cluster_469D80.hpp"

MATCH_FUNC(0x469DE0)
int C_cluster_469D80::M_469DE0(int v)
{
    int n = count_C;
    int i = 0;
    while (i < n) {
        if (arr_14[i] == v)
            return i;
        i++;
    }
    return -1;
}
