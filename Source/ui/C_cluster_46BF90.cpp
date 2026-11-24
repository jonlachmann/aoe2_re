#include "C_cluster_46BF90.hpp"

// 0x472A70 — fill `count` consecutive float slots from values with +inf.
MATCH_FUNC(0x472A70)
int C_cluster_46BF90::FillPositiveInf_472A70()
{
    int result = 0;
    while (result < this->count)
        this->values[result++] = 3.402823466e+38F;
    return result;
}
