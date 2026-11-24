#include "Function.hpp"

class S409E60 {
public:
    unsigned char field_0;
    char pad_01[3];
    void* field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_a;
    unsigned char field_b;
    S409E60* Init_409E60();
};

MATCH_FUNC(0x409E60)
S409E60* S409E60::Init_409E60()
{
    field_0 = 0;
    field_4 = 0;
    field_8 = 0;
    field_9 = 0;
    field_a = 0;
    field_b = 0;
    return this;
}
