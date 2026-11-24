#include "Function.hpp"

class S564E80 {
public:
    int Scale_564E80(int n);
};

MATCH_FUNC(0x564E80)
int S564E80::Scale_564E80(int n)
{
    if (n <= 1)
        return 2;
    return n * n;
}
