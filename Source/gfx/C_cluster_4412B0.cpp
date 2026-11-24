#include "C_cluster_4412B0.hpp"

extern "C" int F_441330(int a, int b);
extern int g_6696f0;

MATCH_FUNC(0x441300)
int C_cluster_4412B0::Init_441300()
{
    if (F_441330(0, 7) != 0)
        return 1;
    g_6696f0 = 0;
    return 0;
}

MATCH_FUNC(0x441DE0)
bool C_cluster_4412B0::Check_441DE0()
{
    return F_441330(1, 2) != 0;
}
