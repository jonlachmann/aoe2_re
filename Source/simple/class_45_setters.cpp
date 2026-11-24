#include "Function.hpp"

class S45SetBulk {
public:
    void SetByte_45AF60(unsigned char v);
};

MATCH_FUNC(0x45AF60)
void S45SetBulk::SetByte_45AF60(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x196) = v;
}
