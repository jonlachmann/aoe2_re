#include "Function.hpp"

extern int g_741f80;
extern int g_741f84;

MATCH_FUNC(0x554E50)
bool IsFirst_554E50(int value)
{
    return value == g_741f80;
}

MATCH_FUNC(0x554E70)
bool IsSecond_554E70(int value)
{
    return value == g_741f84;
}
