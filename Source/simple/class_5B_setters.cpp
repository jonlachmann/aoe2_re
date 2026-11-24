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

MATCH_FUNC(0x5B4570)
void S5BSetBulk::SetByte_5B4570(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x145d) = v;
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
