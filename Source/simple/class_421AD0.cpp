#include "Function.hpp"

// Family 0x421AD0/0x421AF0: two setters over the byte pair +0x9a9/+0x9aa;
// the first writes +0x9a9 then stores the (arg == 0) result at +0x9aa, the
// second swaps which byte gets what.
class S421AD0 {
public:
    char pad_00[0x9a9];
    unsigned char field_9a9;
    unsigned char field_9aa;

    void M_421AD0(int v);
    void M_421AF0(int v);
};

MATCH_FUNC(0x421AF0)
void S421AD0::M_421AF0(int v)
{
    field_9aa = (unsigned char)v;
    field_9a9 = (v == 0);
}
