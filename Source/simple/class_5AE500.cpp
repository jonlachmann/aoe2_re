#include "Function.hpp"

class S5AE500 {
public:
    char pad_00[0x16c];
    int field_16c;
    unsigned char field_170;
    void Set_5AE500(int a, unsigned char b);
};

MATCH_FUNC(0x5AE500)
void S5AE500::Set_5AE500(int a, unsigned char b)
{
    field_16c = a;
    field_170 = b;
}
