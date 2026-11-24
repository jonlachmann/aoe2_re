#include "Function.hpp"

class S4B27F0Node {
public:
    char pad_00[0x174];
    int field_174;
};

class S4B27F0 {
public:
    char pad_00[0x100];
    S4B27F0Node* field_100;
    void Set_4B27F0(int v);
};

MATCH_FUNC(0x4B27F0)
void S4B27F0::Set_4B27F0(int v)
{
    if (field_100 != 0)
        field_100->field_174 = v;
}
