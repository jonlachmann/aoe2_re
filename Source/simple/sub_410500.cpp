#include "Function.hpp"

// sub_410500 (VA 0x410500) - member: appends field_1e0 to the array at +0xea8
// using the count at +0xea4, then bumps the count.
class S410500 {
public:
    char pad_00[0x1e0];
    int field_1e0;
    char pad_1e4[0xea4 - 0x1e4];
    int count_ea4;
    int arr_ea8[1];

    void M_410500();
};

MATCH_FUNC(0x410500)
void S410500::M_410500()
{
    arr_ea8[count_ea4] = field_1e0;
    count_ea4++;
}
