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

// 0x45DDB0 — initialize the dense display object: zero every scalar field
// in the binary's store order (the +0x3C/+0x3D mode bytes as bytes), set +0x34
// to 8, then publish the default colors through sub_619780(0xFF00FF, 0,
// 0xFF00FF00, 0); the left-to-right pushes put 0xFF00FF in the a1 slots.
void __cdecl sub_619780(int a1, int a2, int a3, int a4);

MATCH_FUNC(0x45DDB0)
C_cluster_45F8A0* C_cluster_45F8A0::Init_45DDB0()
{
    field_00 = 0;
    field_04 = 0;
    field_08 = 0;
    field_0c = 0;
    field_10 = 0;
    field_18 = 0;
    field_1c = 0;
    field_20 = 0;
    field_24 = 0;
    field_40 = 0;
    field_3c = 0;
    field_3d = 0;
    field_2c = 0;
    field_30 = 0;
    field_34 = 8;
    field_28 = 0;
    field_44 = 0;
    field_48 = 0;
    field_14 = 0;
    field_4c = 0;
    field_54 = 0;
    field_58 = 0;
    field_5c = 0;
    field_60 = 0;
    field_64 = 0;
    field_68 = 0;
    field_6c = 0;
    field_70 = 0;
    field_74 = 0;
    field_78 = 0;
    field_7c = 0;
    field_80 = 0;
    field_84 = 0;
    field_88 = 0;
    field_8c = 0;
    field_90 = 0;
    field_94 = 0;
    field_98 = 0;
    field_9c = 0;
    field_a0 = 0;
    field_a4 = 0;
    field_a8 = 0;
    field_ac = 0;
    field_b0 = 0;
    field_b4 = 0;
    field_38 = 0;
    field_50 = 0;
    sub_619780(0xFF00FF, 0, 0xFF00FF00, 0);
    return this;
}
