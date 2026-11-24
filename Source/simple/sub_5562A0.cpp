#include "Function.hpp"

// sub_5562A0 (VA 0x5562A0) - cdecl: whether global table 0x740B54[id]
// equals the second arg, for id in [1,0x100].
extern int g_740B54[];
MATCH_FUNC(0x5562A0)
extern "C" int __cdecl sub_5562A0(int id, int v)
{
    if (id < 1 || id > 0x100)
        return 0;
    return g_740B54[id] == v;
}
