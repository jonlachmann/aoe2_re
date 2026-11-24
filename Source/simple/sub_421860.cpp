#include "Function.hpp"

// sub_421860 (VA 0x421860, 0x11 bytes) - member: low bit of the byte at
// 0x9b5 + index.
class S421860 {
public:
    int M_421860(int index);
};

MATCH_FUNC(0x421860)
int S421860::M_421860(int index)
{
    return ((unsigned char*)this)[0x9b5 + index] & 1;
}
