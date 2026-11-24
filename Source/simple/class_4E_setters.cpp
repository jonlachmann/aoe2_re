#include "Function.hpp"

class S4ESetBulk {
public:
    void SetInt_4E8610(int v);
};

MATCH_FUNC(0x4E8610)
void S4ESetBulk::SetInt_4E8610(int v)
{
    *(int*)((char*)this + 0x1818) = v;
}
