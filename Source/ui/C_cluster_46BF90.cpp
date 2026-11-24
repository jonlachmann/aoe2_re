#include "C_cluster_46BF90.hpp"

// 0x472A70 — fill `count` consecutive float slots from values with +inf.
WIP_FUNC(0x472A70)
int C_cluster_46BF90::FillPositiveInf_472A70()
{
    int result;
    for (result = 0; result < this->count;
         *(int*)((char*)this->values + 4 * result - 4) = 2139095039)
        ++result;
    return result;
}
