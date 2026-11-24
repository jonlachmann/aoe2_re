#include "C_cluster_594060.hpp"

// 0x594E70 — set [object+8] and report success; null passes through.
MATCH_FUNC(0x594E70)
int C_cluster_594060::SetFlag_594E70(int object)
{
    int result = object;
    if (!object)
        return result;
    *(int*)(object + 8) = 1;
    return 1;
}
