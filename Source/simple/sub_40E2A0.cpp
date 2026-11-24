#include "Function.hpp"

// sub_40E2A0 (VA 0x40E2A0, 0xB bytes) - member getter: signed word at
// [+0x28]->+8, or -1 when the +0x28 pointer is null.
class S40E2A0 {
public:
    int M_40E2A0();
};

MATCH_FUNC(0x40E2A0)
int S40E2A0::M_40E2A0()
{
    char* p = *(char**)((char*)this + 0x28);
    if (p == 0)
        return -1;
    return (int)*(short*)(p + 8);
}
