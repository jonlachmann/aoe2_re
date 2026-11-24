#include "Function.hpp"

// sub_40E600 (VA 0x40E600, 0x15 bytes) - member: when the +0x28 object
// exists, clears its +4 dword and returns 1 (0 otherwise).
class S40E600 {
public:
    int M_40E600();
};

MATCH_FUNC(0x40E600)
int S40E600::M_40E600()
{
    char* p = *(char**)((char*)this + 0x28);
    if (p == 0)
        return 0;
    *(int*)(p + 4) = 0;
    return 1;
}
