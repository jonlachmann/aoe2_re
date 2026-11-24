#include "Function.hpp"

// sub_48F950 (VA 0x48F950, 0x15 bytes) - member: stores the arg at
// [+0x108]->+0x28 when that object exists.
class S48F950 {
public:
    void M_48F950(int v);
};

MATCH_FUNC(0x48F950)
void S48F950::M_48F950(int v)
{
    char* p = *(char**)((char*)this + 0x108);
    if (p != 0)
        *(int*)(p + 0x28) = v;
}
