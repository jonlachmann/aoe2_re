#include "C_vt61D380.hpp"
#include "C_vt61D320.hpp"

MATCH_FUNC(0x40B5E0)
void C_vt61D380::Init_40B5E0()
{
    *(int*)((char*)this) = 0x61d380;
    *(void**)((char*)this + 0x6c) = 0;
    *(void**)((char*)this + 0x70) = 0;
    ((C_vt61D320*)this)->SetVt_40A0C0();
}
