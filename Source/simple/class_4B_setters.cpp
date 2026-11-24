#include "Function.hpp"

class S4BSetBulk {
public:
    void SetInt_4B4600(int v);
    void SetInt_4B5A00(int v);
    void SetInt_4B67D0(int v);
    void SetInt_4B6880(int v);
    void SetInt_4B7840(int v);
};

MATCH_FUNC(0x4B4600)
void S4BSetBulk::SetInt_4B4600(int v)
{
    *(int*)((char*)this + 0x188) = v;
}

MATCH_FUNC(0x4B5A00)
void S4BSetBulk::SetInt_4B5A00(int v)
{
    *(int*)((char*)this + 0x1a8) = v;
}

MATCH_FUNC(0x4B67D0)
void S4BSetBulk::SetInt_4B67D0(int v)
{
    *(int*)((char*)this + 0x1bc) = v;
}

MATCH_FUNC(0x4B6880)
void S4BSetBulk::SetInt_4B6880(int v)
{
    *(int*)((char*)this + 0x1c8) = v;
}

MATCH_FUNC(0x4B7840)
void S4BSetBulk::SetInt_4B7840(int v)
{
    *(int*)((char*)this + 0x300) = v;
}
