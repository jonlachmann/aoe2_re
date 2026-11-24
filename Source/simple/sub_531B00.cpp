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

