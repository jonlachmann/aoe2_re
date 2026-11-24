#include "C_cluster_4ACA10.hpp"

MATCH_FUNC(0x4ACA10)
void C_cluster_4ACA10::Set_4ACA10(unsigned short a, unsigned short b)
{
    *(unsigned short*)((char*)this + 0x170) = a;
    *(unsigned short*)((char*)this + 0x172) = b;
}
