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

