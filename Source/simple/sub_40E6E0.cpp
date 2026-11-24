#include "Function.hpp"

// sub_40E6E0 (VA 0x40E6E0) - member: whether entry i (16-byte stride) of the
// table at +0x20 has a nonzero first dword; 0 when index is out of range.
class S40E6E0 {
public:
    char pad_00[0x1c];
    short count_1c;
    char pad_1e[0x20 - 0x1e];
    int* arr_20;
    int M_40E6E0(int i);
};

