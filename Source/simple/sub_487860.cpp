#include "Function.hpp"

// sub_487860 (VA 0x487860) - member: appends the arg to the pointer array at
// +0x14 using the count at +0xc.
class S487860 {
public:
    char pad_00[0xc];
    int count_c;
    char pad_10[0x14 - 0x10];
    int* arr_14;
    void M_487860(int v);
};

MATCH_FUNC(0x487860)
void S487860::M_487860(int v)
{
    arr_14[count_c] = v;
    count_c++;
}
