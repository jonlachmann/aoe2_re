#include "Function.hpp"

class S535EC0Sub {
public:
    char pad_00[0x16];
    short field_16;
};

class S535EC0 {
public:
    char pad_00[8];
    S535EC0Sub* field_8;
    unsigned char IsOther_535EC0();
};

