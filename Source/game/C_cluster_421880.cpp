#include "C_cluster_421880.hpp"

MATCH_FUNC(0x421880)
int C_cluster_421880::Get_421880(int index)
{
    return array_9B5[index] >> 1;
}

// 0x4218A0 — map a 0x421880 packed-byte index (0..0x15) to one of the fixed
// guest addresses; values above 0x15 fall through to 0x64DA08.
MATCH_FUNC(0x4218A0)
int C_cluster_421880::M_4218A0(int a1)
{
    switch ((unsigned char)Get_421880(a1))
    {
    case 0: return (int)0x662BE0;
    case 1: return (int)0x64DA9C;
    case 2: return (int)0x64DA94;
    case 3: return (int)0x64DA8C;
    case 4: return (int)0x64DA84;
    case 5: return (int)0x64DA7C;
    case 6: return (int)0x64DA78;
    case 7: return (int)0x64DA70;
    case 8: return (int)0x64DA68;
    case 9: return (int)0x64DA60;
    case 10: return (int)0x64DA5C;
    case 11: return (int)0x64DA54;
    case 12: return (int)0x64DA4C;
    case 13: return (int)0x64DA44;
    case 14: return (int)0x64DA40;
    case 15: return (int)0x64DA38;
    case 16: return (int)0x64DA30;
    case 17: return (int)0x64DA28;
    case 18: return (int)0x64DA24;
    case 19: return (int)0x64DA1C;
    case 20: return (int)0x64DA14;
    case 21: return (int)0x64DA0C;
    default: return (int)0x64DA08;
    }
}
