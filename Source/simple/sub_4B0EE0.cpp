#include "Function.hpp"

// sub_4B0EE0 (VA 0x4B0EE0) - member: clears field_154 when set.
class S4B0EE0 {
public:
    char pad_00[0x154];
    int field_154;
    void M_4B0EE0();
};

MATCH_FUNC(0x4B0EE0)
void S4B0EE0::M_4B0EE0()
{
    if (field_154 != 0)
        field_154 = 0;
}
