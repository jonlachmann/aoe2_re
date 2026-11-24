#include "Function.hpp"

// sub_473110 (VA 0x473110) - member: stores the arg at entry index of the
// pointer array +0x18 when index is in [0, field_4), reporting success.
class S473110 {
public:
    char pad_00[4];
    int field_4;
    char pad_08[0x18 - 0x08];
    int* arr_18;
    bool M_473110(int i, int v);
};

MATCH_FUNC(0x473110)
bool S473110::M_473110(int i, int v)
{
    if (i >= 0 && i < field_4) {
        arr_18[i] = v;
        return true;
    }
    return false;
}
