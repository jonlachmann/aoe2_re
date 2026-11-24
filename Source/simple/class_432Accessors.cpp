#include "Function.hpp"

class S432Accessors {
public:
    char pad_00[0x1c68];
    int field_1c68;
    char pad_1c6c[0x1e31 - 0x1c6c];
    unsigned char field_1e31;
    char pad_1e32[0x26a4 - 0x1e32];
    int field_26a4;
    char pad_26a8[0x2c44 - 0x26a8];
    int field_2c44;
    char pad_2c48[0x352c - 0x2c48];
    int field_352c;

    void Set1C68_4329B0(int v);
    int Get1E31_432100();
    int Get26A4_432B50();
    void Set26A4_432B60(int v);
    int Get2C44_432060();
    int Get352C_432CB0();
};

MATCH_FUNC(0x432060)
int S432Accessors::Get2C44_432060() { return field_2c44; }

MATCH_FUNC(0x432100)
int S432Accessors::Get1E31_432100() { return field_1e31; }

MATCH_FUNC(0x4329B0)
void S432Accessors::Set1C68_4329B0(int v) { field_1c68 = v; }

MATCH_FUNC(0x432B50)
int S432Accessors::Get26A4_432B50() { return field_26a4; }

MATCH_FUNC(0x432CB0)
int S432Accessors::Get352C_432CB0() { return field_352c; }
