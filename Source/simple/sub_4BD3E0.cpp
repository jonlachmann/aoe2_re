#include "Function.hpp"

// sub_4BD3E0 (VA 0x4BD3E0) - member: -1 when the word at +0xfc is 0, else
// the signed word at +0x104.
class S4BD3E0 {
public:
    char pad_00[0xfc];
    short field_fc;
    char pad_0fe[0x104 - 0xfe];
    short field_104;
    int M_4BD3E0();
};

MATCH_FUNC(0x4BD3E0)
int S4BD3E0::M_4BD3E0()
{
    if (field_fc == 0)
        return -1;
    return field_104;
}
