#include "C_vt6234C8.hpp"

extern int g_6645c4;

// 0x4BDE70 — decrement the +0x81C counter; on zero read the short at +0x424
// of the object stored in the 0x6645C4 global, otherwise return -1.
WIP_FUNC(0x4BDE70)
short C_vt6234C8::M_4BDE70()
{
    int v = *(int*)((char*)this + 0x81c);
    if (--v != 0)
        return -1;
    int obj = g_6645c4;
    return *(short*)((char*)obj + 0x424);
}
