#include "Function.hpp"

class S52SetBulk {
public:
    void SetInt_520F50(int v);
    void SetByte_52BC90(unsigned char v);
};

MATCH_FUNC(0x520F50)
void S52SetBulk::SetInt_520F50(int v)
{
    *(int*)((char*)this + 0x70) = v;
}

MATCH_FUNC(0x52BC90)
void S52SetBulk::SetByte_52BC90(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x76) = v;
}
