#include "Function.hpp"

class S5ASetBulk {
public:
    void SetInt_5AED50(int v);
    void SetInt_5AED60(int v);
};

MATCH_FUNC(0x5AED50)
void S5ASetBulk::SetInt_5AED50(int v)
{
    *(int*)((char*)this + 0x14c) = v;
}

MATCH_FUNC(0x5AED60)
void S5ASetBulk::SetInt_5AED60(int v)
{
    *(int*)((char*)this + 0x150) = v;
}
