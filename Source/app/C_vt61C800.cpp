#include "C_vt61C800.hpp"

MATCH_FUNC(0x403A20)
void C_vt61C800::M_403A20(int unused)
{
    (void)unused;
    if (*(int*)((char*)this + 0x20) == (int)0xbf800000)
        Vat_5C(3);
    else
        Vat_5C(0xb);
}
