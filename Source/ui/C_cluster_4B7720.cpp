#include "C_cluster_4B7720.hpp"

MATCH_FUNC(0x4B7720)
int C_cluster_4B7720::M_4B7720()
{
    char* p = *(char**)((char*)this + 0x38c);
    if (p != 0)
        return *(int*)p;
    return 0;
}
