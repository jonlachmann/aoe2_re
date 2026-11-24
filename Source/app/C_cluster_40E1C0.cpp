#include "C_cluster_40E1C0.hpp"

MATCH_FUNC(0x40E6E0)
int C_cluster_40E1C0::M_40E6E0(int i)
{
    if (i < 0 || i >= count_1C)
        return 0;
    int* e = (int*)((char*)arr_20 + (i << 4));
    return *e != 0;
}
