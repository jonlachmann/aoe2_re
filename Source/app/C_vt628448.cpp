#include "C_vt628448.hpp"

MATCH_FUNC(0x540800)
void C_vt628448::M_540800(unsigned char unused)
{
    (void)unused;
    if (field_10 != 0)
        Vat_5C(4);
    else
        Vat_5C(0xd);
}
