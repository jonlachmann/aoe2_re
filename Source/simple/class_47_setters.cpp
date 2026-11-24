#include "Function.hpp"

class S47SetBulk {
public:
    void SetByte_47C1F0(unsigned char v);
    void SetByte_47C200(unsigned char v);
};

MATCH_FUNC(0x47C1F0)
void S47SetBulk::SetByte_47C1F0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x8ecd) = v;
}

MATCH_FUNC(0x47C200)
void S47SetBulk::SetByte_47C200(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x8ece) = v;
}
