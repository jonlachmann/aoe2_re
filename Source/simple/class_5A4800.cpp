#include "Function.hpp"

class S5A4800 {
public:
    char pad_00[0x16cf];
    unsigned char array_16cf[0x40];
    unsigned char array_16d8[0x40];
    void SetA_5A4800(short index, unsigned char v);
    void SetB_5A4820(short index, unsigned char v);
};

MATCH_FUNC(0x5A4800)
void S5A4800::SetA_5A4800(short index, unsigned char v)
{
    ((unsigned char*)this)[0x16cf + index] = v;
}

MATCH_FUNC(0x5A4820)
void S5A4800::SetB_5A4820(short index, unsigned char v)
{
    ((unsigned char*)this)[0x16d8 + index] = v;
}
