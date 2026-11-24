#include "Function.hpp"

// sub_4BD680 (VA 0x4BD680, 20 bytes) - member: store the arg at +0x178, then
// notify through vtable +0x20 with (this, 1). The base supplies eight leading
// virtual slots so slot 0x20 is fn_20.
class S4BD680;
class B4BD680 {
public:
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0C();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1C();
    virtual int fn_20(int on);
};
class S4BD680 : public B4BD680 {
public:
    char pad_04[0x178 - 0x04];
    int field_178;
    void M_4BD680(int v);
};

MATCH_FUNC(0x4BD680)
void S4BD680::M_4BD680(int v)
{
    field_178 = v;
    fn_20(1);
}
