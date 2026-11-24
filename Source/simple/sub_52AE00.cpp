#include "Function.hpp"

// sub_52AE00 (VA 0x52AE00) - member: when both +0x10 and +0x18 are set, calls
// virtual slot 4 of the +0x18 object with field_10 and returns its short; else 0.
class T52AE00 {
public:
    virtual void Vt_0();
    virtual short Vat_4(int v);
};
class S52AE00 {
public:
    char pad_00[0x10];
    int field_10;
    char pad_14[0x18 - 0x14];
    T52AE00* field_18;
    short M_52AE00();
};

MATCH_FUNC(0x52AE00)
short S52AE00::M_52AE00()
{
    if (field_10 != 0 && field_18 != 0)
        return field_18->Vat_4(field_10);
    return 0;
}
