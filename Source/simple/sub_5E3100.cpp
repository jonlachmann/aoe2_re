#include "Function.hpp"

// sub_5E3100 (VA 0x5E3100, 20 bytes) - member: forwards the byte arg to the
// pointer at +0x34 (a settings store). Null does nothing.
class S5E3100;
class T47C1F0 {
public:
    char pad_00[0x8ecd];
    unsigned char field_8ecd;
    void Other_47C1F0(int v);
};

class S5E3100 {
public:
    char pad_00[0x34];
    void* field_34;
    void M_5E3100(int v);
};

MATCH_FUNC(0x5E3100)
void S5E3100::M_5E3100(int v)
{
    if (field_34 != 0)
        ((T47C1F0*)field_34)->Other_47C1F0(v);
}
