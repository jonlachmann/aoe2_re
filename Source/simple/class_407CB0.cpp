#include "Function.hpp"

// The two getters return a 3-int struct by value. VC6 passes the hidden
// return pointer at [esp+4], keeps it in eax for the return and copies through
// edx/esi, which is the `push esi; mov edx, eax` shape in the original.
struct S407CB0Vec3 {
    int x, y, z;
};

class S407CB0 {
public:
    char pad_00[0xe4];
    S407CB0Vec3 vec_e4;
    S407CB0Vec3 vec_f0;
    S407CB0Vec3 CopyE4_407CB0();
    S407CB0Vec3 CopyF0_407D00();
};

MATCH_FUNC(0x407CB0)
S407CB0Vec3 S407CB0::CopyE4_407CB0()
{
    return vec_e4;
}

MATCH_FUNC(0x407D00)
S407CB0Vec3 S407CB0::CopyF0_407D00()
{
    return vec_f0;
}
