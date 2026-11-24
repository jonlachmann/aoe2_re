#include "Function.hpp"

class S5549A0Global {
public:
    char pad_00[0x2064];
    int field_2064;
};

extern S5549A0Global* g_741f60;

MATCH_FUNC(0x5549A0)
bool Has_5549A0()
{
    return g_741f60->field_2064 > 0;
}
