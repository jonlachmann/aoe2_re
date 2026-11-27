#include "C_cluster_4A3BB0.hpp"

extern int (__stdcall *cv_61C05C)(void* a1, int a2, int a3, void* a4);

// 0x4A3BB0 — rebuild the +0x460 owned object. Store a1 at +0x464 (0 when a1 is
// -1); release an existing +0x460 object through its slot 0 with 1 and clear
// it. Then, when +0x210 is present and the +0x464 count is positive, format
// through the 0x61C05C import into a local buffer; on success allocate a 0x38
// object, construct it with (+0x20, +0x464, 0, buffer) and store the result at
// +0x460. Finally, when +0x78 is set, dispatch slot 8 with 2.
MATCH_FUNC(0x4A3BB0)
void C_cluster_4A3BB0::M_4A3BB0(int a1)
{
    char buf[0x400];
    if (a1 == -1)
        field_464 = 0;
    else
        field_464 = a1;
    T460Obj* old = (T460Obj*)field_460;
    if (old != 0)
    {
        old->slot_000(1);
        field_460 = 0;
    }
    if (field_210 != 0 && field_464 > 0)
    {
        if (cv_61C05C(field_210, 0, 0x100, buf) != 0)
        {
            T4233E0_4233E0* obj = new T4233E0_4233E0(field_20, field_464, 0, buf);
            field_460 = obj;
        }
    }
    if (field_78 != 0)
        slot_008(2);
}
