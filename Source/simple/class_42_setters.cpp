#include "Function.hpp"

class S42SetBulk {
public:
    void SetInt_422D40(int v);
    void SetInt_42E3D0(int v);
};

MATCH_FUNC(0x422D40)
void S42SetBulk::SetInt_422D40(int v)
{
    *(int*)((char*)this + 0x0) = v;
}

MATCH_FUNC(0x42E3D0)
void S42SetBulk::SetInt_42E3D0(int v)
{
    *(int*)((char*)this + 0x130c) = v;
}
