#include "Function.hpp"

class S4886C0 {
public:
    char pad_00[0xa8];
    char* field_a8;
    int M_4886C0();
};

MATCH_FUNC(0x4886C0)
int S4886C0::M_4886C0()
{    char* p = field_a8;
    if (!p)
        return 0;
    int v = *(int*)(p + 0x1c);
    if (v != 1 && v != 2)
        return 0;
    return 1;
}
