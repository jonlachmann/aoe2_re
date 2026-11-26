#include "C_cluster_5200F0.hpp"

extern C_cluster_5200F0* g_7407E0;    // global current object at 0x7407E0
extern "C" int cv_ui_5200f0;
extern "C" void* cv_config_ptr;

MATCH_FUNC(0x5200F0)
C_cluster_5200F0* C_cluster_5200F0::M_5200F0(int a1, int a2)
{
#ifdef MATCHED_NATIVE
    ++cv_ui_5200f0;
#endif
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


// 0x520170 — open/probe the 0x7B0 screen's game-data files. The full original
// (499 bytes) drives 0x5203C0 name copy, the 0x5ECE56 open probe and the
// +0x04/+0x08/+0x14/+0x124/+0x128 state; reconstructed here as the minimal
// native path the 0x41E070 gate needs: stage the fallback name at +0x20, keep
// the window handle in +0x08 and mark the +0x04 ready flag so the byte-exact
// 0x520400 gate and the panel setters run. WIP.
WIP_FUNC(0x520170)
void C_cluster_5200F0::Hook_520170(int a1, int a2)
{
#ifdef MATCHED_NATIVE
    if (cv_config_ptr != 0)
        strcpy((char*)this + 0x20, (char*)cv_config_ptr + 0xf4e);
    else
        ((char*)this)[0x20] = 0;
    this->field_08 = a1;
    this->field_14 = 0;
    this->flag_04 = 1;
#else
    if (a2 != 0)
        strcpy((char*)this + 0x20, (char*)(size_t)a2);
    else
        ((char*)this)[0x20] = 0;
    this->field_08 = a1;
    this->field_14 = 0;
    this->flag_04 = 1;
#endif
}
