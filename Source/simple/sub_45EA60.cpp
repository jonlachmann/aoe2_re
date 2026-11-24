#include "Function.hpp"

class S45EA60Inner {
public:
    char pad_00[0xf4];
    int field_f4;
};

class S45EA60Node {
public:
    S45EA60Inner* field_0;
    char pad_04[0x8 - 0x4];
    S45EA60Node* field_8;
};

class S45EA60 {
public:
    char pad_00[0x14];
    S45EA60Node* field_14;
    char pad_18[0x4c - 0x18];
    int field_4c;
    void Clear_45EA60();
};

MATCH_FUNC(0x45EA60)
void S45EA60::Clear_45EA60()
{
    S45EA60Node* n = field_14;
    field_4c = 0;
    while (n != 0) {
        n->field_0->field_f4 = 0;
        n = n->field_8;
    }
}
