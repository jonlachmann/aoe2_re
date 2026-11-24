#include "Function.hpp"

// sub_5C0840 (VA 0x5C0840, 0xF bytes) - member: field_2c = 999999,
// field_24 = field_28 = 0.
class S5C0840 {
public:
    void M_5C0840();
};

MATCH_FUNC(0x5C0840)
void S5C0840::M_5C0840()
{
    int* f = (int*)this;
    f[0x2c / 4] = 999999;
    f[0x24 / 4] = 0;
    f[0x28 / 4] = 0;
}
