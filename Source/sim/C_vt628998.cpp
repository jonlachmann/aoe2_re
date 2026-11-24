#include "C_vt628998.hpp"

extern float g_6289F8;

MATCH_FUNC(0x544E70)
void C_vt628998::M_544E70(unsigned char v)
{
    field_0C = v;
    if (v == 6) {
        char* a = (char*)field_08;
        char* b = *(char**)(a + 0xc);
        char* c = *(char**)(b + 0xa8);
        field_2C = *(int*)(c + 0xf8);
    }
}

MATCH_FUNC(0x544FD0)
int C_vt628998::M_544FD0()
{
    Vat_5c(1);
    C544FD0* c = ((A544FD0*)field_08)->field_c->field_a8;
    float t = c->field_4;
    t += g_6289F8;
    c->field_4 = t;
    return 1;
}
