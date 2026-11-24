#include "Function.hpp"

// sub_4437F0 (VA 0x4437F0, 20 bytes) - cdecl: publish the arg as the global
// pointer at 0x66A478 and stamp 0xABCD1234 at object offset +0x38178.
int global_66A478;

MATCH_FUNC(0x4437F0)
void sub_4437F0(int v)
{
    global_66A478 = v;
    *(int*)(v + 0x38178) = 0xABCD1234;
}
