#include "Function.hpp"

// sub_5E3120 (VA 0x5E3120, 20 bytes) - member: forwards the arg to the pointer
// at +0x34 (the companion of sub_5E3100, a different store slot).
class S5E3120;
class T47C200 {
public:
    char pad_00[0x8ecd];
    void Other_47C200(int v);
};

class S5E3120 {
public:
    char pad_00[0x34];
    void* field_34;
    void M_5E3120(int v);
};

MATCH_FUNC(0x5E3120)
void S5E3120::M_5E3120(int v)
{
    if (field_34 != 0)
        ((T47C200*)field_34)->Other_47C200(v);
}
