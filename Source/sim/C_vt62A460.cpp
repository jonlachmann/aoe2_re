#include "C_vt62A460.hpp"

// 0x587440 — map a small set of tags to slot 2; -1 when unknown.
MATCH_FUNC(0x587440)
int C_vt62A460::MapTag_587440(int a1)
{
    if (a1 == 31 || a1 == 5 || a1 == 33)
        return 2;
    else
        return -1;
}

MATCH_FUNC(0x587420)
int C_vt62A460::M_587420(int v)
{
    return v == 0x1f || v == 5;
}
