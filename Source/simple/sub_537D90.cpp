#include "Function.hpp"

// sub_537D90 (VA 0x537D90) - member: positive field_1a0 returns the global
// float 0x61C584, otherwise tail-calls Sub_48E2D0 on this.
extern float g_61C584;
class S537D90 {
public:
    char pad_00[0x1a0];
    int field_1a0;
    float M_537D90();
    float Sub_48E2D0();
};

MATCH_FUNC(0x537D90)
float S537D90::M_537D90()
{
    if (field_1a0 > 0)
        return g_61C584;
    return Sub_48E2D0();
}
