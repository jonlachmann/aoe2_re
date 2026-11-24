#include "Function.hpp"

class S422320 {
public:
    char pad_00[0x1090];
    int field_1090;
    int Get_422320();
    void Set_422330(int v);
};

MATCH_FUNC(0x422320)
int S422320::Get_422320() { return field_1090; }

MATCH_FUNC(0x422330)
void S422320::Set_422330(int v) { field_1090 = v; }
