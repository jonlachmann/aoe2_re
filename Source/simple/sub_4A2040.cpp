#include "Function.hpp"

// sub_4A2040 (VA 0x4A2040) - member: stores two args at +0x60/+0x64 and sets
// the +0x74 flag to 1.
class S4A2040 {
public:
    char pad_00[0x60];
    int field_60;
    int field_64;
    char pad_68[0x74 - 0x68];
    int field_74;
    void M_4A2040(int a, int b);
};

MATCH_FUNC(0x4A2040)
void S4A2040::M_4A2040(int a, int b)
{
    field_60 = a;
    field_64 = b;
    field_74 = 1;
}
