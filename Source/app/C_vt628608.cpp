#include "C_vt628608.hpp"

MATCH_FUNC(0x5410B0)
void C_vt628608::M_5410B0(unsigned char v)
{
    field_C = v;
    if (v == 0x64) {
        char* a = (char*)field_8;
        char* b = *(char**)(a + 0xc);
        char* c = *(char**)(b + 0xa8);
        field_2C = *(int*)(c + 0x90);
    }
}
