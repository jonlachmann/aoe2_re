#include "C_cluster_522E90.hpp"

#pragma intrinsic(memset)

MATCH_FUNC(0x522E90)
void C_cluster_522E90::M_522E90()
{
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_20 = field_1C;
    field_38++;
}

// 0x523060 — clear the five +0x3C..+0x4C pools through the base reset first.
MATCH_FUNC(0x523060)
void C_cluster_522E90::M_523060()
{
    this->M_522E90();
    memset(field_3C, 0, field_50 * 4);
    memset(field_40, 0, field_50 * 4);
    memset(field_44, 0, field_50 * 4);
    memset(field_48, 0, field_50 * 4);
    memset(field_4C, 0, field_50 * 4);
}
