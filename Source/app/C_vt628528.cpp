#include "C_vt628528.hpp"

MATCH_FUNC(0x540DD0)
void C_vt628528::M_540DD0(unsigned char v)
{
    if (v != 0)
        Vat_5c(6);
}

MATCH_FUNC(0x540DF0)
void C_vt628528::M_540DF0(unsigned char v)
{
    field_0C = v;
    if (v == 10)
        field_2C = 3.0f;
}
