#include "Function.hpp"

// sub_522E90 (VA 0x522E90) - member: clears three fields, copies field_1c into
// field_20 and increments field_38.
class S522E90 {
public:
    char pad_00[0x10];
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    char pad_24[0x38 - 0x24];
    int field_38;
    void M_522E90();
};

MATCH_FUNC(0x522E90)
void S522E90::M_522E90()
{
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_20 = field_1c;
    field_38++;
}
