#include "Function.hpp"

class S5A02C0Row {
public:
    char pad_00[0x5a];
    unsigned char field_5a;
};

class S5A02C0 {
public:
    char pad_00[0x74];
    S5A02C0Row** array_74;
    int Check_5A02C0(int index);
};

MATCH_FUNC(0x5A02C0)
int S5A02C0::Check_5A02C0(int index)
{
    S5A02C0Row* row = array_74[index];
    if ((row != 0 && row->field_5a != 0) || index == 0x6d)
        return 1;
    return 0;
}
