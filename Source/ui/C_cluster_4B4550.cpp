#include "C_cluster_4B4550.hpp"

extern "C" int __stdcall ImmGetOpenStatus(void*);

MATCH_FUNC(0x4B4550)
int C_cluster_4B4550::M_4B4550()
{
    void* h = handle_164;
    if (h != 0)
        return ImmGetOpenStatus(h);
    return 0;
}
