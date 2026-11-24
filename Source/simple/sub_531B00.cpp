#include "Function.hpp"

class S531B00Node {
public:
    char pad_00[4];
    int field_4;
};

class S531B00 {
public:
    char pad_00[0x24];
    S531B00Node* field_24;
    char pad_28[0x1f8 - 0x28];
    int field_1f8;
    int Diff_531B00();
};

MATCH_FUNC(0x531B00)
int S531B00::Diff_531B00()
{
    if (field_24 == 0)
        return 0;
    return field_24->field_4 - field_1f8;
}
