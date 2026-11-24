#include "Function.hpp"

// Family 0x5410B0/0x544E70: stores the byte arg at +0xc and, for one specific
// value, pulls a dword through two pointers into field_2c.
class S5410B0 {
public:
    char pad_00[8];
    char* field_8;
    unsigned char field_c;
    char pad_0D[0x2c - 0x0D];
    int field_2c;

    void M_5410B0(unsigned char v);
    void M_544E70(unsigned char v);
};

MATCH_FUNC(0x5410B0)
void S5410B0::M_5410B0(unsigned char v)
{
    field_c = v;
    if (v == 0x64) {
        char* a = field_8;
        char* b = *(char**)(a + 0xc);
        char* c = *(char**)(b + 0xa8);
        field_2c = *(int*)(c + 0x90);
    }
}

MATCH_FUNC(0x544E70)
void S5410B0::M_544E70(unsigned char v)
{
    field_c = v;
    if (v == 6) {
        char* a = field_8;
        char* b = *(char**)(a + 0xc);
        char* c = *(char**)(b + 0xa8);
        field_2c = *(int*)(c + 0xf8);
    }
}
