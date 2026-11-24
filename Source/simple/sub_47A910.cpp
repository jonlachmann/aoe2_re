#include "Function.hpp"

// sub_47A910 (VA 0x47A910, 0x11 bytes) - member: stores the arg byte at +0x5a
// only when the +0x5b flag byte is 0.
class S47A910 {
public:
    void M_47A910(unsigned char v);
};

MATCH_FUNC(0x47A910)
void S47A910::M_47A910(unsigned char v)
{
    if (*(unsigned char*)((char*)this + 0x5b) == 0)
        *(unsigned char*)((char*)this + 0x5a) = v;
}
