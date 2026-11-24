#include "Function.hpp"

// sub_41ADB0 (VA 0x41ADB0, 0x11 bytes) - member: stores two args at +0xc/+0x10.
class S41ADB0 {
public:
    void M_41ADB0(int a, int b);
};

MATCH_FUNC(0x41ADB0)
void S41ADB0::M_41ADB0(int a, int b)
{
    int* f = (int*)this;
    f[0x0c / 4] = a;
    f[0x10 / 4] = b;
}
