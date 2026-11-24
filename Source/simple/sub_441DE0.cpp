#include "Function.hpp"

extern "C" int F_441330(int a, int b);
extern int g_6696f0;

MATCH_FUNC(0x441DE0)
bool Check_441DE0()
{
    return F_441330(1, 2) != 0;
}

MATCH_FUNC(0x441300)
int Init_441300()
{
    if (F_441330(0, 7) != 0)
        return 1;
    g_6696f0 = 0;
    return 0;
}
