#include "Function.hpp"

// sub_469DE0 (VA 0x469DE0) - member: index of the first dword entry at +0x14
// equal to the arg, bounded by the count at +0xc; -1 otherwise.
class S469DE0 {
public:
    char pad_00[0xc];
    int count_c;
    char pad_10[0x14 - 0x10];
    int* arr_14;
    int M_469DE0(int v);
};

MATCH_FUNC(0x469DE0)
int S469DE0::M_469DE0(int v)
{
    int n = count_c;
    int i = 0;
    while (i < n) {
        if (arr_14[i] == v)
            return i;
        i++;
    }
    return -1;
}
