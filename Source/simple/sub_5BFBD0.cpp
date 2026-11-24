#include "Function.hpp"

// sub_5BFBD0 (VA 0x5BFBD0) - member: writes field_c and field_10 into the
// two out pointers.
class S5BFBD0 {
public:
    char pad_00[0xc];
    int field_c;
    int field_10;
    void M_5BFBD0(int* a, int* b);
};

MATCH_FUNC(0x5BFBD0)
void S5BFBD0::M_5BFBD0(int* a, int* b)
{
    *a = field_c;
    *b = field_10;
}
