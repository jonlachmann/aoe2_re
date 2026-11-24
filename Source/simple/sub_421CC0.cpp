#include "Function.hpp"

// sub_421CC0 (VA 0x421CC0, 0xC bytes) - member: tail-calls the object at +0x1c.
class T465070 {
public:
    void Other_465070();
};
class S421CC0 {
public:
    void M_421CC0();
};

MATCH_FUNC(0x421CC0)
void S421CC0::M_421CC0()
{
    ((T465070*)*(char**)((char*)this + 0x1c))->Other_465070();
}
