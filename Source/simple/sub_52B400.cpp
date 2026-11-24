#include "Function.hpp"

// sub_52B400 (VA 0x52B400) - member: increments the +0x4f byte below 0xfa then
// calls Other_52C190(0); three args are accepted but unused (ret 0xc).
class S52B400 {
public:
    char pad_00[0x4f];
    unsigned char field_4f;
    int Other_52C190(int v);
    void M_52B400(int a, int b, int c);
};

MATCH_FUNC(0x52B400)
void S52B400::M_52B400(int a, int b, int c)
{
    if (field_4f < 0xfa)
        field_4f++;
    Other_52C190(0);
}
