#include "Function.hpp"

// sub_422440 (VA 0x422440, 0x15 bytes) - member getter: dword at
// [+0x1b0]->+0x10e0, or -1 when null.
class S422440 {
public:
    int M_422440();
};

MATCH_FUNC(0x422440)
int S422440::M_422440()
{
    char* p = *(char**)((char*)this + 0x1b0);
    if (p == 0)
        return -1;
    return *(int*)(p + 0x10e0);
}
