#include "Function.hpp"

// sub_5C53B0 (VA 0x5C53B0) - member: zeroes ten dwords in each of the two
// arrays at +0x924 and +0x94c, then clears field_974.
class S5C53B0 {
public:
    char pad_00[0x924];
    int arr_924[10];          // +0x924
    int arr_94c[10];          // +0x94c
    int field_974;            // +0x974
    void M_5C53B0();
};

MATCH_FUNC(0x5C53B0)
void S5C53B0::M_5C53B0()
{
    for (int i = 0; i < 10; i++) {
        arr_924[i] = 0;
        arr_94c[i] = 0;
    }
    field_974 = 0;
}
