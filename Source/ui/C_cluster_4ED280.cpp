#include "C_cluster_4ED280.hpp"

extern int g_664524;

// 0x4ED280 — dispatch the object's +0x10C slot (this, &field_97c, 0x24E,
// 0x181, 0x1C, 0x1C, 0, 0); when nonzero dispatch +0x120 (this, &field_978,
// 0x2536, 0x272, 0x17E, 0x9E, 0x26, 0xB, 0, 1, 1); when nonzero require the
// 0x664524 global, run its 0x422A70 entry, then the 0x58A800 entry on the
// result; only when that entry returns zero call the +0x97C object's +0xF4
// slot with 1.
MATCH_FUNC(0x4ED280)
void T4ED280Self::M_4ED280()
{
    if (Vt_67((int)this, (int*)&field_97c, 0x24E, 0x181, 0x1C, 0x1C, 0, 0) == 0)
        return;
    if (Vt_72((int)this, field_978, 0x2536, 0x272, 0x17E, 0x9E, 0x26, 0xB,
              0, 1, 1) == 0)
        return;
    T4ED280Global* g = (T4ED280Global*)g_664524;
    if (g == 0)
        return;
    int r = g->M_422A70();
    if (r == 0)
        return;
    if (((T4ED280Bulk*)r)->M_58A800() != 0)
        return;
    ((T4ED280Obj*)field_97c)->Vt_61(1);
}
