#include "Function.hpp"

// sub_421BD0 (VA 0x421BD0) - member: sets bit 1 of the byte field at
// 0x9b5 + index to arg<<1, preserving bit 0.
class S421BD0 {
public:
    void M_421BD0(int index, unsigned char v);
};

MATCH_FUNC(0x421BD0)
void S421BD0::M_421BD0(int index, unsigned char v)
{
    unsigned char* p = (unsigned char*)this + 0x9b5 + index;
    *p = (*p & 1) | (v << 1);
}
