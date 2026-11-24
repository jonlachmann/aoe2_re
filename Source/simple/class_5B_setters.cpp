#include "Function.hpp"

class S5BSetBulk {
public:
    void SetInt_5B4530(int v);
    void SetByte_5B4550(unsigned char v);
    void SetByte_5B4570(unsigned char v);
    void SetInt_5BAD60(int v);
    void SetInt_5BAF20(int v);
    void SetInt_5BAF40(int v);
    void SetByte_5BB170(unsigned char v);
    void SetByte_5BB180(unsigned char v);
    void SetByte_5BB190(unsigned char v);
    void SetByte_5BB1A0(unsigned char v);
    void SetInt_5BB1B0(int v);
    void SetInt_5BB1C0(int v);
    void SetByte_5BB1D0(unsigned char v);
    void SetByte_5BB1E0(unsigned char v);
    void SetByte_5BB1F0(unsigned char v);
    void SetByte_5BB200(unsigned char v);
    void SetByte_5BB210(unsigned char v);
    void SetInt_5BB220(int v);
    void SetByte_5BC9F0(unsigned char v);
    void SetByte_5BFB10(unsigned char v);
    void SetInt_5BFB20(int v);
    void SetByte_5BFBA0(unsigned char v);
};

MATCH_FUNC(0x5B4530)
void S5BSetBulk::SetInt_5B4530(int v)
{
    *(int*)((char*)this + 0x1458) = v;
}

MATCH_FUNC(0x5B4550)
void S5BSetBulk::SetByte_5B4550(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x145c) = v;
}

MATCH_FUNC(0x5B4570)
void S5BSetBulk::SetByte_5B4570(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x145d) = v;
}

MATCH_FUNC(0x5BAD60)
void S5BSetBulk::SetInt_5BAD60(int v)
{
    *(int*)((char*)this + 0x11d8) = v;
}

MATCH_FUNC(0x5BAF20)
void S5BSetBulk::SetInt_5BAF20(int v)
{
    *(int*)((char*)this + 0x11dc) = v;
}

MATCH_FUNC(0x5BAF40)
void S5BSetBulk::SetInt_5BAF40(int v)
{
    *(int*)((char*)this + 0x11e0) = v;
}

MATCH_FUNC(0x5BB170)
void S5BSetBulk::SetByte_5BB170(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x122e) = v;
}

MATCH_FUNC(0x5BB180)
void S5BSetBulk::SetByte_5BB180(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x122f) = v;
}

MATCH_FUNC(0x5BB190)
void S5BSetBulk::SetByte_5BB190(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1230) = v;
}

MATCH_FUNC(0x5BB1A0)
void S5BSetBulk::SetByte_5BB1A0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1231) = v;
}

MATCH_FUNC(0x5BB1B0)
void S5BSetBulk::SetInt_5BB1B0(int v)
{
    *(int*)((char*)this + 0x1234) = v;
}

MATCH_FUNC(0x5BB1C0)
void S5BSetBulk::SetInt_5BB1C0(int v)
{
    *(int*)((char*)this + 0x1238) = v;
}

MATCH_FUNC(0x5BB1D0)
void S5BSetBulk::SetByte_5BB1D0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123c) = v;
}

MATCH_FUNC(0x5BB1E0)
void S5BSetBulk::SetByte_5BB1E0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123d) = v;
}

MATCH_FUNC(0x5BB1F0)
void S5BSetBulk::SetByte_5BB1F0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123e) = v;
}

MATCH_FUNC(0x5BB200)
void S5BSetBulk::SetByte_5BB200(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x123f) = v;
}

MATCH_FUNC(0x5BB210)
void S5BSetBulk::SetByte_5BB210(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1adc) = v;
}

MATCH_FUNC(0x5BB220)
void S5BSetBulk::SetInt_5BB220(int v)
{
    *(int*)((char*)this + 0x1ae0) = v;
}

MATCH_FUNC(0x5BC9F0)
void S5BSetBulk::SetByte_5BC9F0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x1ae4) = v;
}

MATCH_FUNC(0x5BFB10)
void S5BSetBulk::SetByte_5BFB10(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x5) = v;
}

MATCH_FUNC(0x5BFB20)
void S5BSetBulk::SetInt_5BFB20(int v)
{
    *(int*)((char*)this + 0x8) = v;
}

MATCH_FUNC(0x5BFBA0)
void S5BSetBulk::SetByte_5BFBA0(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x4) = v;
}
