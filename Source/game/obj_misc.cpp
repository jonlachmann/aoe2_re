// Small game-object leaves, owner class not yet identified (fields provisional).
#include "Function.hpp"
struct Obj {
    char pad_00[0x50];
    float x;          // 0x50
    float y;          // 0x54
    char pad_58[0x88 - 0x58];
    int countdown;    // 0x88

    int Countdown_40A3E0();
};
// Returns the decremented value, which can be negative while the stored field clamps to 0.
MATCH_FUNC(0x40A3E0)
int Obj::Countdown_40A3E0()
{
    int v = --countdown;
    if (countdown < 0) countdown = 0;
    return v;
}
// x87 equality: an unordered compare (NaN) counts as equal, as in the original.
MATCH_FUNC(0x40B600)
int SamePos_40B600(const Obj* a, const Obj* b)
{
    return a->x == b->x && a->y == b->y;
}
