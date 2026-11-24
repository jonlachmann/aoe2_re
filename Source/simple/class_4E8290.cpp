#include "Function.hpp"

class S4E8290 {
public:
    char pad_00[0x17f9];
    unsigned char field_17f9;
    unsigned char field_17fa;
    void Set_4E8290(unsigned char a, unsigned char b);
};

MATCH_FUNC(0x4E8290)
void S4E8290::Set_4E8290(unsigned char a, unsigned char b)
{
    field_17fa = a;
    field_17f9 = b;
}
