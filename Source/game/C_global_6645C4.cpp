#include "C_global_6645C4.hpp"

extern C_global_6645C4* g_p6645c4;             // global object pointer at 0x6645C4
extern "C" void* sub_5F8FF0(int a1, int a2);   // unresolved callee at 0x5F8FF0

MATCH_FUNC(0x4732B0)
void C_global_6645C4::M_4732B0(int a1)
{
    if (field_4 == 0) {
        field_4 = a1;
        arr_18 = (int*)sub_5F8FF0(a1 + 1, 4);
    }
}

MATCH_FUNC(0x4B0EA0)
void C_global_6645C4::M_4B0EA0(int a1)
{
    field_2cc = a1;
    if (a1 == -1) {
        field_154 = 0;
    } else {
        field_154 = g_p6645c4->Hook_41F6E0(a1);
    }
}

MATCH_FUNC(0x473110)
bool C_global_6645C4::M_473110(int i, int v)
{
    if (i >= 0 && i < field_4) {
        arr_18[i] = v;
        return true;
    }
    return false;
}
