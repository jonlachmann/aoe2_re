#include "C_cluster_4AF360.hpp"

MATCH_FUNC(0x4AF4D0)
void C_cluster_4AF360::M_4AF4D0(short index, int value, short flag)
{
    if (array_158[index] != value || array_17c[index] != flag) {
        array_158[index] = value;
        array_17c[index] = flag;
        Vt_20(1);
    }
}
