#include "Function.hpp"

class S58SetBulk {
public:
    void SetInt_58A7F0(int v);
};

MATCH_FUNC(0x58A7F0)
void S58SetBulk::SetInt_58A7F0(int v)
{
    *(int*)((char*)this + 0x194) = v;
}
