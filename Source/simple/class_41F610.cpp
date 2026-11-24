#include "Function.hpp"

class S41F610 {
public:
    char pad_00[0x1dc];
    int field_1dc;
    int field_1e0;
    void Set_41F610(int a, int b);
};

MATCH_FUNC(0x41F610)
void S41F610::Set_41F610(int a, int b)
{
    field_1dc = a;
    field_1e0 = b;
}
