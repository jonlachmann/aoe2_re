#include "Function.hpp"

// sub_42D490 (VA 0x42D490, 0x14 bytes) - member: field_1c when field_10e4 is
// set, otherwise 1.
class S42D490 {
public:
    int M_42D490();
};

MATCH_FUNC(0x42D490)
int S42D490::M_42D490()
{
    if (*(int*)((char*)this + 0x10e4) != 0)
        return *(int*)((char*)this + 0x1c);
    return 1;
}
