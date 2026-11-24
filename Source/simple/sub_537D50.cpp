#include "Function.hpp"

class S537D50 {
public:
    char pad_00[0x1a0];
    int field_1a0;
    int Tick_537D50();
};

MATCH_FUNC(0x537D50)
int S537D50::Tick_537D50()
{
    ++field_1a0;
    return 1;
}
