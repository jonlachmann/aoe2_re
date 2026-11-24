#include "Function.hpp"

class S503310 {
public:
    char pad_00[0xafc];
    int Set_503310(int a, int b, int c, int d, int e);
};

MATCH_FUNC(0x503310)
int S503310::Set_503310(int a, int b, int c, int d, int e)
{
    *(int*)((char*)this + 0xafc) = 1;
    return 1;
}
