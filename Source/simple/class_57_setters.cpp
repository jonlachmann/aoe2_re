#include "Function.hpp"

class S57SetBulk {
public:
    void SetInt_573F50(int v);
};

MATCH_FUNC(0x573F50)
void S57SetBulk::SetInt_573F50(int v)
{
    *(int*)((char*)this + 0xf4) = v;
}
