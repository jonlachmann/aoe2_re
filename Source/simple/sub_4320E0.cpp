#include "Function.hpp"

// sub_4320E0 (VA 0x4320E0, 0x15 bytes) - member: stores the arg byte at +0x1e31
// when field_1c is set.
class S4320E0 {
public:
    void M_4320E0(unsigned char v);
};

MATCH_FUNC(0x4320E0)
void S4320E0::M_4320E0(unsigned char v)
{
    if (*(int*)((char*)this + 0x1c) != 0)
        *(unsigned char*)((char*)this + 0x1e31) = v;
}
