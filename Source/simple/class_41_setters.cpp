#include "Function.hpp"

class S41SetBulk {
public:
    void SetInt_41BC00(int v);
};

MATCH_FUNC(0x41BC00)
void S41SetBulk::SetInt_41BC00(int v)
{
    *(int*)((char*)this + 0x1d8) = v;
}
