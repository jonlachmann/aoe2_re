#include "Function.hpp"

// sub_472B00 (VA 0x472B00) - member: clears dwords +4..+0x18.
class S472B00 {
public:
    char pad_00[4];
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    void M_472B00();
};

MATCH_FUNC(0x472B00)
void S472B00::M_472B00()
{
    field_8 = 0;
    field_c = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_4 = 0;
}
