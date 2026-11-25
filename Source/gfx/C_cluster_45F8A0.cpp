#include "C_cluster_45F8A0.hpp"

// 0x45F8A0 — when both +0x3C/+0x3D mode bytes are 2 and the +0x1C/+0x24
// pointers are present, call slot +0x18 of the vtable at [field_24] with
// (field_24, 0, 0, 0x100, this+0xB8).
MATCH_FUNC(0x45F8A0)
void C_cluster_45F8A0::M_45F8A0()
{
    if (field_3c == 2 && field_3d == 2 && field_1c != 0 && field_24 != 0)
    {
        T45F8Slot18* vt = *(T45F8Slot18**)field_24;
        vt[6](field_24, 0, 0, 0x100, (void*)((char*)this + 0xb8));
    }
}
