#include "C_vt61D324.hpp"
#include "C_vt61D320.hpp"

MATCH_FUNC(0x40A2F0)
void C_vt61D324::Init_40A2F0()
{
    *(int*)((char*)this) = 0x61d324;
    *(void**)((char*)this + 0x6c) = 0;
    *(void**)((char*)this + 0x70) = 0;
    ((C_vt61D320*)this)->SetVt_40A0C0();
}
