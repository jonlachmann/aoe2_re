#include "Function.hpp"

class S539870Node {
public:
    unsigned char key_0;
    char pad_01[0x18 - 0x01];
    S539870Node* field_18;
};

class S539870 {
public:
    char pad_00[4];
    S539870Node* field_4;
    S539870Node* Find_539870(unsigned char key);
};

MATCH_FUNC(0x539870)
S539870Node* S539870::Find_539870(unsigned char key)
{
    S539870Node* p = field_4;
    for (;;) {
        if (p == 0)
            return 0;
        if (p->key_0 == key)
            return p;
        p = p->field_18;
    }
}
