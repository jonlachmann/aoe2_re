#include "Function.hpp"

// sub_422960 (VA 0x422960) - member: pointer to entry index of a 520-byte
// table based at the pointer in +0x108.
class S422960 {
public:
    char pad_00[0x108];
    char* field_108;
    char* M_422960(int index);
};

MATCH_FUNC(0x422960)
char* S422960::M_422960(int index)
{
    return field_108 + (index * 65) * 8 + 8;
}
