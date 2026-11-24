#include "C_cluster_42A9F0.hpp"

MATCH_FUNC(0x42D470)
int C_cluster_42A9F0::Get_42D470()
{
    if (field_10E4 != 0)
        return field_10E0;
    return 1;
}

MATCH_FUNC(0x433500)
int C_cluster_42A9F0::Set_433500(int index, int value)
{
    int result = index;
    int* slot = (int*)((char*)this + 0x46bc + index * 4);
    if (*slot == 5)
        *slot = value;
    return result;
}
