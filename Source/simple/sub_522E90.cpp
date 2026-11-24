#include "Function.hpp"

// sub_522E90 (VA 0x522E90) - member: clears three fields, copies field_1c into
// field_20 and increments field_38.
class S522E90 {
public:
    char pad_00[0x10];
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    char pad_24[0x38 - 0x24];
    int field_38;
    void M_522E90();
};

