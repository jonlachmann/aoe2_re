#include "Function.hpp"

class S52AE20A {
public:
    char pad_00[4];
    int field_4;
};

class S52AE20B {
public:
    char pad_00[0x30];
    unsigned char field_30;
};

// The original duplicates the compare into both arms of an inlined getter.
class S52AE20 {
public:
    char pad_00[8];
    S52AE20B* field_8;
    char pad_c[0x24 - 0xc];
    S52AE20A* field_24;
    int Value()
    {
        if (!field_24)
            return 0;
        return field_24->field_4;
    }
    bool Less_52AE20();
};

