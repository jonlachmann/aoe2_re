#include "C_cluster_4AC3E0.hpp"

// 0x4AC3E0 — bounded signed-word index; report dword i and success flag.
MATCH_FUNC(0x4AC3E0)
int C_cluster_4AC3E0::GetRecord_4AC3E0(__int16 index, int* out)
{
    if (index < 0 || index >= this->count)
        return 0;
    *out = *(int*)((char*)this->records + 4 * index);
    return 1;
}
