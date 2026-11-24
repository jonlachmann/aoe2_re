#include "C_cluster_5B4530.hpp"

MATCH_FUNC(0x5B4530)
void C_cluster_5B4530::SetInt_5B4530(int v)
{
    *(int*)((char*)this + 0x1458) = v;
}

MATCH_FUNC(0x5B4550)
void C_cluster_5B4530::SetByte_5B4550(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x145c) = v;
}
