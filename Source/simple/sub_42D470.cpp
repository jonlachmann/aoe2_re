#include "Function.hpp"

class S42D470 {
public:
    char pad_00[0x10e0];
    int field_10e0;
    int field_10e4;
    int Get_42D470();
};

MATCH_FUNC(0x42D470)
int S42D470::Get_42D470()
{
    if (field_10e4 != 0)
        return field_10e0;
    return 1;
}
