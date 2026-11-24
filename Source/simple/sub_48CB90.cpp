#include "Function.hpp"

extern float g_61C584;
class S48CB90 {
public:
    char pad_00[0xa4];
    float field_a4;
    unsigned char M_48CB90();
};

MATCH_FUNC(0x48CB90)
unsigned char S48CB90::M_48CB90()
{
    if (field_a4 > g_61C584)
        return 1;
    return 0;
}
