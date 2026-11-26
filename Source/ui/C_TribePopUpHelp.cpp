#include "C_TribePopUpHelp.hpp"
#include "matched_mem.h"

extern void* g_6645c4;
extern int (__stdcall *g_61C2A0)(int a1);

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

// 0x4A1440 — reject when any of the +0x20/+0x70/+0x6C gates, the 0x6645C4 +0x30
// gate or the +0x20 object's +0x04 word is missing; then when +0x38 is set,
// walk the +0x58 chain dispatching slot +0x20, invoke the +0x40 object's
// +0x24 three-argument slot when its +0x7C gate is set, call own slot +0x30,
// clear +0x38 and mark +0x84 = 1; finally walk the chain again dispatching
// slot +0x54 and clear +0x84. Returns 0.
MATCH_FUNC(0x4A1440)
int C_TribePopUpHelp::M_4A1440()
{
    if (field_20 == 0 || field_70 == 0 || field_6c == 0)
        return 0;
    if (*(int*)(((char*)ADDR(g_6645c4)) + 0x30) == 0)
        return 0;
    if (g_61C2A0(((T4A1440Field20*)field_20)->field_4) != 0)
        return 0;
    if (field_38 != 0)
    {
        for (T4A1440Node* n = field_58; n; n = n->field_8)
            ((T4A1440Obj*)n->obj_0)->Vt_08(field_38);
        if (field_40 != 0 && ((T4A1440Field40*)field_40)->field_7c != 0)
            ((T4A1440Field40*)field_40)->Vt_09((int)this, (int)this, field_38);
        this->slot_12();
        field_38 = 0;
        field_84 = 1;
    }
    for (T4A1440Node* n = field_58; n; n = n->field_8)
        ((T4A1440Obj*)n->obj_0)->Vt_21();
    field_84 = 0;
    return 0;
}
