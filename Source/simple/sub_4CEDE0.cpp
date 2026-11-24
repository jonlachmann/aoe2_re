#include "Function.hpp"

// sub_4CEDE0 (VA 0x4CEDE0, 0xD bytes) - member: tail-calls the object at +4
// when present.
class T595FC0 {
public:
    void Other_595FC0();
};
class S4CEDE0 {
public:
    void M_4CEDE0();
};

MATCH_FUNC(0x4CEDE0)
void S4CEDE0::M_4CEDE0()
{
    char* a = *(char**)((char*)this + 4);
    if (a != 0)
        ((T595FC0*)a)->Other_595FC0();
}
