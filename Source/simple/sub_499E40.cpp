#include "Function.hpp"

class S499E40Value {
public:
    char pad_00[4];
    int field_4;
};

class S499E40Node {
public:
    S499E40Value* field_0;
    S499E40Node* field_4;
};

class S499E40 {
public:
    char pad_00[4];
    S499E40Node* field_4;
    S499E40Value* Find_499E40(int key);
};

MATCH_FUNC(0x499E40)
S499E40Value* S499E40::Find_499E40(int key)
{
    S499E40Node* n = field_4;
    while (n != 0) {
        if (n->field_0 != 0 && n->field_0->field_4 == key)
            return n->field_0;
        n = n->field_4;
    }
    return 0;
}
