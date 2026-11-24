#include "Function.hpp"

class S5BC460 {
public:
    void Clear_5BC460();
};

MATCH_FUNC(0x5BC460)
void S5BC460::Clear_5BC460()
{
    int* p = (int*)((char*)this + 0x1ae5);
    for (int i = 0; i < 0x5a; ++i)
        p[i] = 0;
}
