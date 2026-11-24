#include "C_scr_ach.hpp"

MATCH_FUNC(0x4D3C10)
void C_scr_ach::M_4D3C10()
{
    if (field_C7C != 0)
        field_C7C = 0;
    Sub_4A2280();
}
