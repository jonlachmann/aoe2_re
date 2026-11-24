#include "Function.hpp"

// sub_562550 (VA 0x562550) - member: dword +8 of entry i in the 44-byte table
// at +0xf20, when entry+0 is nonzero and entry+4 >= 1.
struct E562550 {
    int field_0;
    int field_4;
    int field_8;
    char pad_c[0x2c - 0xc];
};
class S562550 {
public:
    char pad_00[0xf20];
    E562550 entries[1];
    int M_562550(int i);
};

MATCH_FUNC(0x562550)
int S562550::M_562550(int i)
{
    E562550* e = &entries[i];
    if (e->field_0 == 0 || e->field_4 < 1)
        return 0;
    return e->field_8;
}
