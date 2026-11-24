#include "Function.hpp"

class S520750 {
public:
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    char pad_06[0xc - 0x06];
    int field_c;
    int field_10;
    int field_14;
    unsigned char field_18;
    char pad_19[0x1c - 0x19];
    int field_1c;
    void Init_520750();
};

MATCH_FUNC(0x520750)
void S520750::Init_520750()
{
    field_0 = 0;
    field_4 = 0;
    field_5 = 0;
    field_1c = 0;
    field_c = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
}
