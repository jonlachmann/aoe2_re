#include "Function.hpp"

class S5CSetBulk {
public:
    void SetInt_5C13D0(int v);
    void SetInt_5C13F0(int v);
    void SetInt_5C15C0(int v);
    void SetInt_5C15D0(int v);
    void SetInt_5C15E0(int v);
    void SetInt_5C15F0(int v);
    void SetInt_5C1600(int v);
    void SetInt_5C47C0(int v);
};

MATCH_FUNC(0x5C13D0)
void S5CSetBulk::SetInt_5C13D0(int v)
{
    *(int*)((char*)this + 0x5228) = v;
}

MATCH_FUNC(0x5C13F0)
void S5CSetBulk::SetInt_5C13F0(int v)
{
    *(int*)((char*)this + 0x522c) = v;
}

MATCH_FUNC(0x5C15C0)
void S5CSetBulk::SetInt_5C15C0(int v)
{
    *(int*)((char*)this + 0x1b78) = v;
}

MATCH_FUNC(0x5C15D0)
void S5CSetBulk::SetInt_5C15D0(int v)
{
    *(int*)((char*)this + 0x1b7c) = v;
}

MATCH_FUNC(0x5C15E0)
void S5CSetBulk::SetInt_5C15E0(int v)
{
    *(int*)((char*)this + 0x1b80) = v;
}

MATCH_FUNC(0x5C15F0)
void S5CSetBulk::SetInt_5C15F0(int v)
{
    *(int*)((char*)this + 0x1b84) = v;
}

MATCH_FUNC(0x5C1600)
void S5CSetBulk::SetInt_5C1600(int v)
{
    *(int*)((char*)this + 0x1b88) = v;
}

MATCH_FUNC(0x5C47C0)
void S5CSetBulk::SetInt_5C47C0(int v)
{
    *(int*)((char*)this + 0x170) = v;
}
