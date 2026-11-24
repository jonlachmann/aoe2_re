#include "Function.hpp"

// The four "int" args are one 16-byte struct passed by value; the body is a
// struct assignment (`add ecx, 0x12dc` then [ecx], [ecx+4], ...).
struct S42F0B0Rect {
    int a, b, c, d;
};

class S42F0B0 {
public:
    char pad_00[0x12dc];
    S42F0B0Rect rect_12dc;
    void Set_42F0B0(S42F0B0Rect r);
};

MATCH_FUNC(0x42F0B0)
void S42F0B0::Set_42F0B0(S42F0B0Rect r)
{
    rect_12dc = r;
}
