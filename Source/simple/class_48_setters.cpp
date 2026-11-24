#include "Function.hpp"

class S48SetBulk {
public:
    void SetInt_48A840(int v);
    void SetInt_48A850(int v);
    void SetByte_48E330(unsigned char v);
};

MATCH_FUNC(0x48A840)
void S48SetBulk::SetInt_48A840(int v)
{
    *(int*)((char*)this + 0x144) = v;
}

MATCH_FUNC(0x48A850)
void S48SetBulk::SetInt_48A850(int v)
{
    *(int*)((char*)this + 0x148) = v;
}

