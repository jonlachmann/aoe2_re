#include "Function.hpp"

// sub_4061B0 (VA 0x4061B0, 0xB bytes) - member getter: reads the pointer at
// +8, then the pointer in its first dword, then its +0x30 dword; 0 if null.
class S4061B0 {
public:
    int M_4061B0();
};

MATCH_FUNC(0x4061B0)
int S4061B0::M_4061B0()
{
    char* obj = *(char**)((char*)this + 8);
    if (obj != 0)
        return *(int*)(*(char**)obj + 0x30);
    return 0;
}
