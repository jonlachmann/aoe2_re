#include "C_vt61CAB4.hpp"

MATCH_FUNC(0x4061C0)
void C_vt61CAB4::M_4061C0(int v)
{
    N4061C0* n = field_08;
    while (n != 0) {
        ((T4061C0*)n->obj_0)->Vat_40(v);
        n = n->next_4;
    }
}

MATCH_FUNC(0x406220)
void C_vt61CAB4::Clear_406220(char* p)
{
    *p = 0;
}
