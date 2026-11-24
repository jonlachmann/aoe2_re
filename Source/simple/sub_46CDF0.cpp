#include "Function.hpp"

// sub_46CDF0 (VA 0x46CDF0, 0x11 bytes) - member getter: first dword of the
// +0xf0 object, or -1 when null.
class S46CDF0 {
public:
    int M_46CDF0();
};

MATCH_FUNC(0x46CDF0)
int S46CDF0::M_46CDF0()
{
    char* p = *(char**)((char*)this + 0xf0);
    if (p != 0)
        return *(int*)p;
    return -1;
}
