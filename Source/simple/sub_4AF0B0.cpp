#include "Function.hpp"

// sub_4AF0B0 (VA 0x4AF0B0) - member: writes field_10 and field_4 into the
// two out pointers.
class S4AF0B0 {
public:
    char pad_00[4];
    int field_4;
    char pad_08[0x10 - 0x08];
    int field_10;
    void M_4AF0B0(int* a, int* b);
};

MATCH_FUNC(0x4AF0B0)
void S4AF0B0::M_4AF0B0(int* a, int* b)
{
    *a = field_10;
    *b = field_4;
}
