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

