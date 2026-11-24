#include "Function.hpp"

class S41F6C0 {
public:
    int M_41F6C0(int index);
};

MATCH_FUNC(0x41F6C0)
int S41F6C0::M_41F6C0(int index)
{    int* p = *(int**)((char*)this + 0x7c);
    if (p == 0) { return 0; }
    return p[index];
}
