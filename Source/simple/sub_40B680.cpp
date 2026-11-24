#include "Function.hpp"

// sub_40B680 (VA 0x40B680, 0xF bytes) - member: decrements field_7c, clamped
// at 0.
class S40B680 {
public:
    void M_40B680();
};

MATCH_FUNC(0x40B680)
void S40B680::M_40B680()
{
    int* f = (int*)this;
    if (--f[0x7c / 4] < 0)
        f[0x7c / 4] = 0;
}
