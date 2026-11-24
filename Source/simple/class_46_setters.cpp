#include "Function.hpp"

class S46SetBulk {
public:
    void SetInt_464480(int v);
    void SetInt_46A9B0(int v);
    void SetInt_46A9C0(int v);
    void SetInt_46A9E0(int v);
    void SetInt_46AA00(int v);
    void SetInt_46AA50(int v);
    void SetInt_46AA70(int v);
    void SetInt_46AA90(int v);
    void SetInt_46AB60(int v);
    void SetInt_46AE40(int v);
};

MATCH_FUNC(0x464480)
void S46SetBulk::SetInt_464480(int v)
{
    *(int*)((char*)this + 0x104) = v;
}

MATCH_FUNC(0x46AE40)
void S46SetBulk::SetInt_46AE40(int v)
{
    *(int*)((char*)this + 0xc4) = v;
}
