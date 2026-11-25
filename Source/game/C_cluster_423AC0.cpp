#include "C_cluster_423AC0.hpp"

extern "C" void sub_5FDFB5(int a1, int a2, int a3);
extern "C" void sub_5FE04F(int a1, void* a2, int a3);
extern "C" void sub_5FDA2B(int a1);

MATCH_FUNC(0x423AC0)
void C_cluster_423AC0::M_423AC0()
{
    this->M_4241B0();
    this->M_4242F0();
    field_14 = 0;
    field_524 = 0;
}

MATCH_FUNC(0x4241B0)
void C_cluster_423AC0::M_4241B0()
{
    if (field_8 >= 0) {
        sub_5FDFB5(field_8, 0, 0);
        sub_5FE04F(field_8, &field_544, 4);
        sub_5FDA2B(field_8);
    }
    field_8 = -1;
    field_0 = 0;
}

MATCH_FUNC(0x4242F0)
void C_cluster_423AC0::M_4242F0()
{
    if (field_8 >= 0)
        sub_5FDA2B(field_8);
    field_8 = -1;
    field_4 = 0;
}
