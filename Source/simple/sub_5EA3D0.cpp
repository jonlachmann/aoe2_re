#include "Function.hpp"

// sub_5EA3D0 (VA 0x5EA3D0, 0x11 bytes) - member: byte at [+0x34]->+0x8ecd, or true when
// the +0x34 pointer is null.
class S5EA3D0 {
public:
    bool M_5EA3D0();
};

MATCH_FUNC(0x5EA3D0)
bool S5EA3D0::M_5EA3D0()
{
    char* p = *(char**)((char*)this + 0x34);
    if (p == 0)
        return true;
    return *(bool*)(p + 0x8ecd);
}
