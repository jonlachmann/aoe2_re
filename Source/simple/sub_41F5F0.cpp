#include "Function.hpp"

// sub_41F5F0 (VA 0x41F5F0, 0x11 bytes) - member: calls the global function
// pointer 0x61C2F4 with (field_28, 0x10, 0, 0).
extern void (__stdcall *g_61C2F4)(int, int, int, int);
class S41F5F0 {
public:
    void M_41F5F0();
};

MATCH_FUNC(0x41F5F0)
void S41F5F0::M_41F5F0()
{
    g_61C2F4(*(int*)((char*)this + 0x28), 0x10, 0, 0);
}
