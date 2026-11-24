#include "Function.hpp"

// sub_43EBD0 (VA 0x43EBD0) - member: appends the arg to the array at +8 while
// the count at +4 is below 0x28; returns 1 on success, 0 when full.
class S43EBD0 {
public:
    char pad_00[4];
    int count_4;
    int arr_8[1];
    int M_43EBD0(int v);
};

MATCH_FUNC(0x43EBD0)
int S43EBD0::M_43EBD0(int v)
{
    if (count_4 >= 0x28)
        return 0;
    arr_8[count_4] = v;
    count_4++;
    return 1;
}
