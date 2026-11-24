#include "Function.hpp"

class S4A00B0Inner {
public:
    char pad_00[0xf7];
    unsigned char field_f7;
};

class S4A00B0Node {
public:
    S4A00B0Inner* field_0;
    char pad_04[0x8 - 0x4];
    S4A00B0Node* field_8;
};

class S4A00B0 {
public:
    char pad_00[0x14];
    S4A00B0Node* field_14;
    void Mark_4A00B0();
};

MATCH_FUNC(0x4A00B0)
void S4A00B0::Mark_4A00B0()
{
    S4A00B0Node* n = field_14->field_8;
    while (n != field_14) {
        S4A00B0Inner* q = n->field_0;
        if (q != 0)
            q->field_f7 = 1;
        n = n->field_8;
    }
}
