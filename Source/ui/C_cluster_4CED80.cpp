#include "C_cluster_4CED80.hpp"

MATCH_FUNC(0x4CED80)
int C_cluster_4CED80::Get_4CED80(int index)
{
    if (index < 0 || index >= 0x10)
        return 0;
    return *(int*)((char*)this + 0x1930 + index * 4);
}

MATCH_FUNC(0x4CEDC0)
int C_cluster_4CED80::Get_4CEDC0(int index)
{
    if (index < 0 || index >= 0x10)
        return 0;
    return *(int*)((char*)this + 0x19b0 + index * 4);
}

MATCH_FUNC(0x5C1410)
int C_cluster_4CED80::Set_5C1410(int value)
{
    int result = value;
    if (result < 0)
        result = 0;
    else if (result > 0x10)
        result = 0xf;
    return this->field_4CD4 = result;
}

MATCH_FUNC(0x5C1A00)
int C_cluster_4CED80::Get_5C1A00(int a2)
{
    return this->records[180 * this->field_4CD4 + 15 * a2];
}
