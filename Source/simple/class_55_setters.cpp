#include "Function.hpp"

class S55SetBulk {
public:
    void SetInt_550990(int v);
    void SetInt_55D910(int v);
};

MATCH_FUNC(0x550990)
void S55SetBulk::SetInt_550990(int v)
{
    *(int*)((char*)this + 0x314) = v;
}

MATCH_FUNC(0x55D910)
void S55SetBulk::SetInt_55D910(int v)
{
    *(int*)((char*)this + 0x100) = v;
}
