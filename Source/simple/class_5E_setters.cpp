#include "Function.hpp"

class S5ESetBulk {
public:
    void SetInt_5E5160(int v);
};

MATCH_FUNC(0x5E5160)
void S5ESetBulk::SetInt_5E5160(int v)
{
    *(int*)((char*)this + 0x24) = v;
}
