#include "Function.hpp"

// sub_435830 (VA 0x435830, 0xF bytes) - member: copies the float at
// [+8]->+0x140 into this +0x168.
class S435830 {
public:
    void M_435830();
};

MATCH_FUNC(0x435830)
void S435830::M_435830()
{
    float* src = *(float**)((char*)this + 8);
    float t = *(float*)((char*)src + 0x140);
    *(float*)((char*)this + 0x168) = t;
}
