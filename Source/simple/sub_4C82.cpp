#include "Function.hpp"

class S4C8204 {
public:
    void Init_4C8204(int unused);
};

MATCH_FUNC(0x4C8204)
void S4C8204::Init_4C8204(int unused)
{
    *(int*)((char*)this + 0x2f44c) = -1;
    *(unsigned char*)((char*)this + 0x2884e) = 1;
}

class S4C8222 {
public:
    void Init_4C8222(int unused);
};

MATCH_FUNC(0x4C8222)
void S4C8222::Init_4C8222(int unused)
{
    *(int*)((char*)this + 0x2f64c) = -1;
    *(unsigned char*)((char*)this + 0x2884d) = 1;
}
