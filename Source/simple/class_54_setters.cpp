#include "Function.hpp"

class S54SetBulk {
public:
    void SetInt_548110(int v);
    void SetByte_54ADD0(unsigned char v);
    void SetInt_54FE60(int v);
};

MATCH_FUNC(0x548110)
void S54SetBulk::SetInt_548110(int v)
{
    *(int*)((char*)this + 0x40) = v;
}

MATCH_FUNC(0x54FE60)
void S54SetBulk::SetInt_54FE60(int v)
{
    *(int*)((char*)this + 0x5c0) = v;
}
