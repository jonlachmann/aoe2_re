#include "Function.hpp"

class S49F480Node {
public:
    char pad_00[0xc];
    int field_c;
};

class S49F480 {
public:
    char pad_00[0x10];
    S49F480Node* field_10;
    char pad_14[0x20 - 0x14];
    int count_20;
    void Insert_49F480(S49F480Node* p);
};

MATCH_FUNC(0x49F480)
void S49F480::Insert_49F480(S49F480Node* p)
{
    p->field_c = reinterpret_cast<int>(field_10);
    field_10 = p;
    ++count_20;
}
