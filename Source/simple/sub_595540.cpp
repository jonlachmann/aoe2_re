#include "Function.hpp"

class S595540Node {
public:
    char pad_00[0xc];
    int field_c;
    int field_10;
};

class S595540 {
public:
    int Count_595540(S595540Node* p);
    int Count_595560(S595540Node* p);
};

