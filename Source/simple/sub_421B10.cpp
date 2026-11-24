#include "Function.hpp"

// sub_421B10 (VA 0x421B10) - member: stores three byte args at +0x9ab/+0x9ac/
// +0x9ad.
class S421B10 {
public:
    char pad_00[0x9ab];
    unsigned char field_9ab;
    unsigned char field_9ac;
    unsigned char field_9ad;
    void M_421B10(unsigned char a, unsigned char b, unsigned char c);
};

