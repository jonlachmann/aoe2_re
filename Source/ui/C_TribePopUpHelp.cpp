#include "C_TribePopUpHelp.hpp"

MATCH_FUNC(0x4A1E20)
void C_TribePopUpHelp::M_4A1E20(int v)
{
    if (v == field_78)
        return;
    field_78 = v;
    slot_08(1);
    if (field_3c) {
        T4A1E20Sub* sub = field_3c;
        sub->Vat_d0(field_78);
    }
}
