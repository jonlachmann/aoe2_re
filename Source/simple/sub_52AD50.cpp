#include "Function.hpp"

// sub_52AD50 (VA 0x52AD50, 0x13 bytes) - member: true unless the +0x48 byte is
// below 3 or equal to 6.
class S52AD50 {
public:
    bool M_52AD50();
};

MATCH_FUNC(0x52AD50)
bool S52AD50::M_52AD50()
{
    unsigned char c = *(unsigned char*)((char*)this + 0x48);
    if (c < 3 || c == 6)
        return false;
    return true;
}
