#include "Function.hpp"

class S4ASetBulk {
public:
    void SetInt_4A38F0(int v);
    void SetInt_4A3900(int v);
    void SetInt_4A3910(int v);
    void SetInt_4A39E0(int v);
    void SetInt_4A6500(int v);
    void SetInt_4A6510(int v);
    void SetByte_4AD420(unsigned char v);
    void SetInt_4AF350(int v);
    void SetInt_4AF860(int v);
};

MATCH_FUNC(0x4A38F0)
void S4ASetBulk::SetInt_4A38F0(int v)
{
    *(int*)((char*)this + 0x320) = v;
}

MATCH_FUNC(0x4A3900)
void S4ASetBulk::SetInt_4A3900(int v)
{
    *(int*)((char*)this + 0x324) = v;
}

MATCH_FUNC(0x4A3910)
void S4ASetBulk::SetInt_4A3910(int v)
{
    *(int*)((char*)this + 0x31c) = v;
}

MATCH_FUNC(0x4A39E0)
void S4ASetBulk::SetInt_4A39E0(int v)
{
    *(int*)((char*)this + 0x350) = v;
}

MATCH_FUNC(0x4A6500)
void S4ASetBulk::SetInt_4A6500(int v)
{
    *(int*)((char*)this + 0x490) = v;
}

MATCH_FUNC(0x4A6510)
void S4ASetBulk::SetInt_4A6510(int v)
{
    *(int*)((char*)this + 0x48c) = v;
}

MATCH_FUNC(0x4AD420)
void S4ASetBulk::SetByte_4AD420(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x154) = v;
}

MATCH_FUNC(0x4AF350)
void S4ASetBulk::SetInt_4AF350(int v)
{
    *(int*)((char*)this + 0x2b8) = v;
}

MATCH_FUNC(0x4AF860)
void S4ASetBulk::SetInt_4AF860(int v)
{
    *(int*)((char*)this + 0x154) = v;
}
