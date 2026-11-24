#include "Function.hpp"

// sub_55A0D0 (VA 0x55A0D0, 0xB bytes) - cdecl: sets global table entry [arg] to 1.
extern int gTab_741758[];

MATCH_FUNC(0x55A0D0)
extern "C" void __cdecl sub_55A0D0(int index)
{
    gTab_741758[index] = 1;
}
