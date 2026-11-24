#include "Function.hpp"

// sub_51CE40 (VA 0x51CE40) - member: field_844 <- M_4BD3E0() of the object at
// +0x800.
class C4BD3E0 {
public:
    int M_4BD3E0();
};
class S51CE40 {
public:
    char pad_00[0x800];
    C4BD3E0* field_800;
    char pad_804[0x844 - 0x804];
    int field_844;
    void M_51CE40();
};

MATCH_FUNC(0x51CE40)
void S51CE40::M_51CE40()
{
    field_844 = field_800->M_4BD3E0();
}
