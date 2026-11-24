#include "C_global_6645C4.hpp"

MATCH_FUNC(0x473110)
bool C_global_6645C4::M_473110(int i, int v)
{
    if (i >= 0 && i < field_4) {
        arr_18[i] = v;
        return true;
    }
    return false;
}
