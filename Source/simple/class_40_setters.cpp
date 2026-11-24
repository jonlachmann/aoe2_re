#include "Function.hpp"

class S40SetBulk {
public:
    void SetByte_409E10(unsigned char v);
    void SetInt_40A150(int v);
    void SetInt_40A160(int v);
    void SetInt_40A170(int v);
    void SetInt_40A180(int v);
    void SetInt_40A3A0(int v);
    void SetInt_40A3B0(int v);
    void SetInt_40A3C0(int v);
    void SetInt_40A420(int v);
    void SetInt_40A440(int v);
    void SetInt_40A450(int v);
    void SetByte_40A470(unsigned char v);
    void SetInt_40B650(int v);
    void SetInt_40B660(int v);
    void SetInt_40B6A0(int v);
    void SetInt_40CBC0(int v);
};

MATCH_FUNC(0x409E10)
void S40SetBulk::SetByte_409E10(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x3c) = v;
}

MATCH_FUNC(0x40A150)
void S40SetBulk::SetInt_40A150(int v)
{
    *(int*)((char*)this + 0x50) = v;
}

MATCH_FUNC(0x40A160)
void S40SetBulk::SetInt_40A160(int v)
{
    *(int*)((char*)this + 0x54) = v;
}

MATCH_FUNC(0x40A170)
void S40SetBulk::SetInt_40A170(int v)
{
    *(int*)((char*)this + 0x58) = v;
}

MATCH_FUNC(0x40A180)
void S40SetBulk::SetInt_40A180(int v)
{
    *(int*)((char*)this + 0x68) = v;
}

MATCH_FUNC(0x40A3A0)
void S40SetBulk::SetInt_40A3A0(int v)
{
    *(int*)((char*)this + 0x80) = v;
}

MATCH_FUNC(0x40A3B0)
void S40SetBulk::SetInt_40A3B0(int v)
{
    *(int*)((char*)this + 0x84) = v;
}

MATCH_FUNC(0x40A3C0)
void S40SetBulk::SetInt_40A3C0(int v)
{
    *(int*)((char*)this + 0x88) = v;
}

MATCH_FUNC(0x40A420)
void S40SetBulk::SetInt_40A420(int v)
{
    *(int*)((char*)this + 0xa0) = v;
}

MATCH_FUNC(0x40A440)
void S40SetBulk::SetInt_40A440(int v)
{
    *(int*)((char*)this + 0xa4) = v;
}

MATCH_FUNC(0x40A450)
void S40SetBulk::SetInt_40A450(int v)
{
    *(int*)((char*)this + 0xa8) = v;
}

MATCH_FUNC(0x40A470)
void S40SetBulk::SetByte_40A470(unsigned char v)
{
    *(unsigned char*)((char*)this + 0xac) = v;
}

MATCH_FUNC(0x40B650)
void S40SetBulk::SetInt_40B650(int v)
{
    *(int*)((char*)this + 0x74) = v;
}

MATCH_FUNC(0x40B660)
void S40SetBulk::SetInt_40B660(int v)
{
    *(int*)((char*)this + 0x78) = v;
}

MATCH_FUNC(0x40B6A0)
void S40SetBulk::SetInt_40B6A0(int v)
{
    *(int*)((char*)this + 0x7c) = v;
}

MATCH_FUNC(0x40CBC0)
void S40SetBulk::SetInt_40CBC0(int v)
{
    *(int*)((char*)this + 0xf0) = v;
}
