#include "Function.hpp"

class S433E50 {
public:
    char pad_00[0x14];
    char* field_14;
    unsigned char field_18;
    unsigned char GetBit_433E50();
};

WIP_FUNC(0x433E50)
unsigned char S433E50::GetBit_433E50()
{
    if (field_18 == 0)
        return 0;
    return (unsigned char)((*(int*)(field_14 + 4) >> 1) & 1);
}
