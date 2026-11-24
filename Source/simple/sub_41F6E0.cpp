#include "Function.hpp"

// sub_41F6E0 (VA 0x41F6E0) - member getter over the int array at +0x8c, bounded
// by the signed word count at +0x88; 0 when null/out of range.
class S41F6E0 {
public:
    char pad_00[0x88];
    short count_88;
    int* arr_8c;
    int M_41F6E0(int i);
};

MATCH_FUNC(0x41F6E0)
int S41F6E0::M_41F6E0(int i)
{
    if (arr_8c == 0 || i < 0 || i >= count_88)
        return 0;
    return arr_8c[i];
}
