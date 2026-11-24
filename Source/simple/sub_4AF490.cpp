#include "Function.hpp"

// sub_4AF490 (VA 0x4AF490) - member: field_148 = 3, then the word arg at +0x200.
class S4AF490 {
public:
    char pad_00[0x148];
    int field_148;
    char pad_14c[0x200 - 0x14c];
    short field_200;
    void M_4AF490(short v);
};

MATCH_FUNC(0x4AF490)
void S4AF490::M_4AF490(short v)
{
    field_148 = 3;
    field_200 = v;
}
