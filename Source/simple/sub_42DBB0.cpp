#include "Function.hpp"

// sub_42DBB0 (VA 0x42DBB0, 0xC bytes) - member: tail-calls the object at +0x15f0.
class T4337C0 {
public:
    void Other_4337C0();
};
class S42DBB0 {
public:
    void M_42DBB0();
};

MATCH_FUNC(0x42DBB0)
void S42DBB0::M_42DBB0()
{
    ((T4337C0*)*(char**)((char*)this + 0x15f0))->Other_4337C0();
}
