#include "Function.hpp"

// sub_41B600 (VA 0x41B600, 0xD bytes) - member: word fields +0x14 and +0x20
// both <- arg.
class S41B600 {
public:
    void M_41B600(short v);
};

MATCH_FUNC(0x41B600)
void S41B600::M_41B600(short v)
{
    *(short*)((char*)this + 0x14) = v;
    *(short*)((char*)this + 0x20) = v;
}
