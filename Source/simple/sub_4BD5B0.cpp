#include "Function.hpp"

// sub_4BD5B0 (VA 0x4BD5B0) - member: +8 dword of the list node at index idx
// (following +0x24), or -1.
struct N4BD5B0 {
    char pad_00[8];
    int value_8;
    char pad_0c[0x24 - 0x0c];
    N4BD5B0* next_24;
};
class S4BD5B0 {
public:
    char pad_00[0xf8];
    N4BD5B0* list_f8;
    int M_4BD5B0(int idx);
};

