#include "Function.hpp"

class S5D17B0Node {
public:
    char pad_00[0x30];
    S5D17B0Node* field_30;
};

class S5D17B0 {
public:
    char pad_00[4];
    S5D17B0Node* field_4;
    S5D17B0Node* Index_5D17B0(int index);
};

MATCH_FUNC(0x5D17B0)
S5D17B0Node* S5D17B0::Index_5D17B0(int index)
{
    int i = 0;
    S5D17B0Node* p = field_4;
    while (p != 0) {
        if (i == index)
            return p;
        p = p->field_30;
        ++i;
    }
    return 0;
}
