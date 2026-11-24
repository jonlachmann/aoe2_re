#include "Function.hpp"

class S43EB90 {
public:
    int field_0;
    int field_4;
    char pad_08[0xa8 - 0x08];
    int field_a8;
    char pad_ac[0x1a4c - 0xac];
    int field_1a4c;
    void Init_43EB90();
};

MATCH_FUNC(0x43EB90)
void S43EB90::Init_43EB90()
{
    field_0 = -1;
    field_4 = 0;
    field_a8 = 0;
    field_1a4c = 0;
}
