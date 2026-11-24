#include "Function.hpp"

extern float g_61C584;
class S435810 {
public:
    char pad_00[0x168];
    float field_168;
    unsigned char M_435810();
};

MATCH_FUNC(0x435810)
unsigned char S435810::M_435810()
{    if (field_168 > g_61C584)
        return 0;
    else
        return 1;
}
