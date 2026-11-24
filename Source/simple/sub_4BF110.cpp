#include "Function.hpp"

// sub_4BF110 (VA 0x4BF110, 0x15 bytes) - member: field_2a4 <- global function
// pointer 0x61C3C8's result.
extern int (__cdecl *g_61C3C8)();
class S4BF110 {
public:
    void M_4BF110();
};

MATCH_FUNC(0x4BF110)
void S4BF110::M_4BF110()
{
    *(int*)((char*)this + 0x2a4) = g_61C3C8();
}
