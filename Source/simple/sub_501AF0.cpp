#include "Function.hpp"

// sub_501AF0 (VA 0x501AF0, 0x15 bytes) - member: field_af4 <- global function
// pointer 0x61C3C8's result.
extern int (__cdecl *g_61C3C8)();
class S501AF0 {
public:
    void M_501AF0();
};

MATCH_FUNC(0x501AF0)
void S501AF0::M_501AF0()
{
    *(int*)((char*)this + 0xaf4) = g_61C3C8();
}
