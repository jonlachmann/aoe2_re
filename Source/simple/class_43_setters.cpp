#include "Function.hpp"

class S43SetBulk {
public:
    void SetInt_438620(int v);
    void SetInt_43A070(int v);
    void SetInt_43A090(int v);
    void SetInt_43A0A0(int v);
    void SetInt_43A0B0(int v);
    void SetInt_43A410(int v);
};

MATCH_FUNC(0x438620)
void S43SetBulk::SetInt_438620(int v)
{
    *(int*)((char*)this + 0x118) = v;
}

MATCH_FUNC(0x43A070)
void S43SetBulk::SetInt_43A070(int v)
{
    *(int*)((char*)this + 0x28) = v;
}

MATCH_FUNC(0x43A090)
void S43SetBulk::SetInt_43A090(int v)
{
    *(int*)((char*)this + 0xc) = v;
}

MATCH_FUNC(0x43A0B0)
void S43SetBulk::SetInt_43A0B0(int v)
{
    *(int*)((char*)this + 0x14) = v;
}

MATCH_FUNC(0x43A410)
void S43SetBulk::SetInt_43A410(int v)
{
    *(int*)((char*)this + 0x25c0) = v;
}
