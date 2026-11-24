#include "Function.hpp"

// sub_520F60 (VA 0x520F60, 0xF bytes) - member: post-increments the dword at
// +0x59c and returns the old value.
class S520F60 {
public:
    int M_520F60();
};

MATCH_FUNC(0x520F60)
int S520F60::M_520F60()
{
    int* f = (int*)this;
    return f[0x59c / 4]++;
}
