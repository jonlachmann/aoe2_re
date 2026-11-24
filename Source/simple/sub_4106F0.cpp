#include "Function.hpp"

// sub_4106F0 (VA 0x4106F0, 0xF bytes) - member: when state at +0 is 3, calls
// the member-function pointer at +0x10 and stores its result at +8.
class S4106F0 {
public:
    int state_0;              // +0x00
    char pad_04[0x08 - 0x04];
    int field_8;              // +0x08
    char pad_0C[0x10 - 0x0C];
    int (S4106F0::*fn_10)();  // +0x10

    void M_4106F0();
};

MATCH_FUNC(0x4106F0)
void S4106F0::M_4106F0()
{
    if (state_0 == 3)
        field_8 = (this->*fn_10)();
}
