#include "Function.hpp"

// sub_5EA3F0 (VA 0x5EA3F0, 0x11 bytes) - member: byte at [+0x34]->+0x8ece, or false when
// the +0x34 pointer is null.
class S5EA3F0 {
public:
    bool M_5EA3F0();
};

MATCH_FUNC(0x5EA3F0)
bool S5EA3F0::M_5EA3F0()
{
    char* p = *(char**)((char*)this + 0x34);
    if (p == 0)
        return false;
    return *(bool*)(p + 0x8ece);
}
