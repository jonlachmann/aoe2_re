#include "Function.hpp"

class S44SetBulk {
public:
    void SetInt_44CFC0(int v);
};

MATCH_FUNC(0x44CFC0)
void S44SetBulk::SetInt_44CFC0(int v)
{
    *(int*)((char*)this + 0x804) = v;
}
