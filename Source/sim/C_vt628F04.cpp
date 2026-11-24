#include "C_vt628F04.hpp"

MATCH_FUNC(0x548840)
void C_vt628F04::M_548840(unsigned char v)
{
    if (v != 0 && field_10 != 0)
        Vat_5C(4);
    else
        Vat_5C(3);
}
