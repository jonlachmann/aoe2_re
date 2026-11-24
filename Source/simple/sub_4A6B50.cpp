#include "Function.hpp"

// sub_4A6B50 (VA 0x4A6B50, 0x11 bytes) - member: stores two args at +4/+8.
class S4A6B50 {
public:
    void M_4A6B50(int a, int b);
};

MATCH_FUNC(0x4A6B50)
void S4A6B50::M_4A6B50(int a, int b)
{
    int* f = (int*)this;
    f[4 / 4] = a;
    f[8 / 4] = b;
}
