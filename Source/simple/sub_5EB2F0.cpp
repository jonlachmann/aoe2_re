#include "Function.hpp"

extern void* g_664534;
extern float g_64d4bc;

class S5EB2F0 {
public:
    char pad_00[0xa8];
    float field_a8;
    float Get_5EB2F0();
};

MATCH_FUNC(0x5EB2F0)
float S5EB2F0::Get_5EB2F0()
{
    if (g_664534 == 0)
        return field_a8;
    return g_64d4bc;
}
