#include "Function.hpp"

// sub_422DD0 (VA 0x422DD0, 0xB bytes) - member: tail-calls the object at +0x128
// when present, otherwise returns void.
class T58A9A0 {
public:
    void Other_58A9A0();
};
class S422DD0 {
public:
    void M_422DD0();
};

MATCH_FUNC(0x422DD0)
void S422DD0::M_422DD0()
{
    char* a = *(char**)((char*)this + 0x128);
    if (a != 0)
        ((T58A9A0*)a)->Other_58A9A0();
}
