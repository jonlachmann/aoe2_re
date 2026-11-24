#include "C_vt625DA4.hpp"

MATCH_FUNC(0x501980)
int C_vt625DA4::Set_501980(int a2, int a3, int a4, int a5, int a6)
{
    (void)a3; (void)a4; (void)a5; (void)a6;
    if (a2 == 27 || a2 == 32)
        this->field_AFC = 1;
    return 0;
}

MATCH_FUNC(0x503310)
int C_vt625DA4::Set_503310(int a, int b, int c, int d, int e)
{
    (void)a; (void)b; (void)c; (void)d; (void)e;
    *(int*)((char*)this + 0xafc) = 1;
    return 1;
}
