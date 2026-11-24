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

MATCH_FUNC(0x4BD5B0)
int S4BD5B0::M_4BD5B0(int idx)
{
    int i = 0;
    for (N4BD5B0* n = list_f8; n; n = n->next_24) {
        if (i == idx)
            return n->value_8;
        i++;
    }
    return -1;
}
