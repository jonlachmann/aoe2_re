#include "Function.hpp"

// Family 0x4359B0/0x4359E0: writes two dwords of the object at +8 into the two
// out pointers (first variant offsets 0x134/0x160, second 0x140/0x164).
class S4359B0 {
public:
    char pad_00[8];
    char* field_8;
    void M_4359B0(int* a, int* b);
    void M_4359E0(int* a, int* b);
};

MATCH_FUNC(0x4359B0)
void S4359B0::M_4359B0(int* a, int* b)
{
    *a = *(int*)(field_8 + 0x134);
    *b = *(int*)(field_8 + 0x160);
}

MATCH_FUNC(0x4359E0)
void S4359B0::M_4359E0(int* a, int* b)
{
    *a = *(int*)(field_8 + 0x140);
    *b = *(int*)(field_8 + 0x164);
}
