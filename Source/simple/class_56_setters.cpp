#include "Function.hpp"

class S56SetBulk {
public:
    void SetInt_565B70(int v);
};

MATCH_FUNC(0x565B70)
void S56SetBulk::SetInt_565B70(int v)
{
    *(int*)((char*)this + 0xf80) = v;
}
