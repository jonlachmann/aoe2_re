#include "C_vt61DEB8.hpp"
#include "C_vt61DE70.hpp"

MATCH_FUNC(0x41B240)
void C_vt61DEB8::Init_41B240()
{
    *(int*)((char*)this) = 0x61deb8;
    ((C_vt61DE70*)this)->Init_41ADA0();
}

MATCH_FUNC(0x41B600)
void C_vt61DEB8::M_41B600(short v)
{
    *(short*)((char*)this + 0x14) = v;
    *(short*)((char*)this + 0x20) = v;
}

MATCH_FUNC(0x41B610)
bool C_vt61DEB8::Check_41B610()
{
    int v1 = this->field_04;
    if (!v1)
        return false;
    return this->field_24 != 0 && (*(unsigned char*)(v1 + 0x70) & 1) != 0;
}

MATCH_FUNC(0x41B660)
char C_vt61DEB8::Get_41B660()
{
    return *(char*)((char*)this + 0x23);
}

MATCH_FUNC(0x41B6E0)
void C_vt61DEB8::Move_41B6E0()
{
    unsigned short v = field_14;
    field_22 = 1;
    field_20 = v;
    field_14 = 0;
}
