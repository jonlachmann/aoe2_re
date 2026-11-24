#include "C_vt61DDB0.hpp"

MATCH_FUNC(0x41AAC0)
void C_vt61DDB0::M_41AAC0(int arg, int unused1, int unused2)
{
    (void)unused1; (void)unused2;
    for (N41AAC0* n = list_4; n; n = n->next_8)
        n->obj_0->Vat_28(arg, field_8);
}
