#include "C_cluster_5200F0.hpp"

extern C_cluster_5200F0* g_7407E0;    // global current object at 0x7407E0

MATCH_FUNC(0x5200F0)
C_cluster_5200F0* C_cluster_5200F0::M_5200F0(int a1, int a2)
{
    g_7407E0 = this;
    this->Reset_520130();
    this->Hook_520170(a1, a2);
    return this;
}

// 0x520130 — reset the scattered counters and flags; +24 is set to one.
MATCH_FUNC(0x520130)
int C_cluster_5200F0::Reset_520130()
{
    int result = 0;
    this->field_18 = 1;
    this->flag_04 = 0;
    this->field_08 = 0;
    this->field_0C = 0;
    this->field_10 = 0;
    this->field_14 = 0;
    this->flag_05 = 0;
    this->field_79C = 0;
    this->field_1C = 0;
    this->field_124 = 0;
    this->field_128 = 0;
    this->flag_20 = 0;
    return result;
}
