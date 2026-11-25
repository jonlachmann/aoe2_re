#include "C_cluster_438F10.hpp"

extern void __cdecl Free_5F90B0(void* p);

// 0x438F10 — free the 0x20-stride records at +0xE54 and then the array
// itself, clearing the +0xE58 count; a null array only clears the count.
MATCH_FUNC(0x438F10)
void C_cluster_438F10::M_438F10()
{
    if (field_E54 != 0)
    {
        for (int i = 0; i < field_E58; i++)
        {
            int p = ((R438F10*)field_E54)[i].field_0;
            if (p != 0)
                Free_5F90B0((void*)p);
            ((R438F10*)field_E54)[i].field_0 = 0;
        }
        Free_5F90B0((void*)field_E54);
        field_E54 = 0;
        field_E58 = 0;
    }
    else
    {
        field_E58 = 0;
    }
}
