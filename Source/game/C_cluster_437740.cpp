#include "C_cluster_437740.hpp"

// 0x437740 — when the index is below count, mark dword +28 in the 36-byte
// record and return the byte index times nine; invalid indices pass through.
MATCH_FUNC(0x437740)
int C_cluster_437740::MarkRecord_437740(unsigned index)
{
    int result = index;
    if (index < this->count) {
        result = 9 * index;
        *(int*)((char*)this->records + 4 * result + 28) = 1;
    }
    return result;
}
