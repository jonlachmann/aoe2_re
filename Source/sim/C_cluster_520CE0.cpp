#include "C_cluster_520CE0.hpp"

WIP_FUNC(0x5219B0)
int C_cluster_520CE0::Find_5219B0(int a2)
{
    int* v2 = *(int**)((char*)this + 0x80);
    if (!v2)
        return 0;
    while (*(int*)(*(int*)((char*)v2 + 8)) != a2) {
        v2 = *(int**)((char*)v2 + 4);
        if (!v2)
            return 0;
    }
    return *(int*)((char*)v2 + 8);
}

WIP_FUNC(0x5219E0)
int C_cluster_520CE0::Find_5219E0(int a2)
{
    int* v2 = *(int**)((char*)this + 0x7c);
    if (!v2)
        return 0;
    while (*(int*)(*(int*)((char*)v2 + 8)) != a2) {
        v2 = *(int**)((char*)v2 + 4);
        if (!v2)
            return 0;
    }
    return *(int*)((char*)v2 + 8);
}
