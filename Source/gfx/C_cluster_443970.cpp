#include "C_cluster_443970.hpp"

MATCH_FUNC(0x5C53B0)
void C_cluster_443970::M_5C53B0()
{
    for (int i = 0; i < 10; i++) {
        arr_924[i] = 0;
        arr_94C[i] = 0;
    }
    field_974 = 0;
}

// 0x4B5950 — cluster reset: run the base 0x4B9F70 init, zero the +0xC4 and
// +0x1A8..+0x1C8 fields, write the 0x622B50 vtable pointer, set the +0xF2
// mode byte to 4, the +0x1B0 value to 0x32 and the +0x80/+0x188/+0x198/+0x19C/
// +0x1BC flags to 1, then return this.
WIP_FUNC(0x4B5950)
C_cluster_443970* C_cluster_443970::M_4B5950()
{
    this->Hook_4B9F70();
    field_c4 = 0;
    field_1ac = 0;
    field_1b4 = 0;
    field_1b8 = 0;
    field_1a8 = 0;
    field_1c0 = 0;
    field_1c4 = 0;
    field_1c8 = 0;
    field_1bc = 1;
    field_188 = 1;
    field_80 = 1;
    field_19c = 1;
    field_198 = 1;
    field_0 = 0x622B50;
    field_f2 = 4;
    field_1b0 = 0x32;
    return this;
}
