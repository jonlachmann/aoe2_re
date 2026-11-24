#include "C_vt6291AC.hpp"

MATCH_FUNC(0x54B1F0)
void C_vt6291AC::Init_54B1F0()
{
    int* p = *(int**)((char*)this + 8);
    *(int*)((char*)this) = 0x6291ac;
    *(int*)((char*)p + 0x44) = 0;
    *(short*)((char*)(*(void**)((char*)this + 8)) + 0x4c) = -1;
    ((T409630*)this)->Init_409630();
}
