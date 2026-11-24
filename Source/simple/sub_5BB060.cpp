#include "Function.hpp"

// sub_5BB060 (VA 0x5BB060) - member: pointer to entry index of a 31-byte
// table starting at +0x10a8.
class S5BB060 {
public:
    char* M_5BB060(int index);
};

MATCH_FUNC(0x5BB060)
char* S5BB060::M_5BB060(int index)
{
    return (char*)this + 0x10a8 + index * 31;
}
