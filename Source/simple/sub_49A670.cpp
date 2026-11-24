#include "Function.hpp"

// sub_49A670 (VA 0x49A670) - member: over the array at +4 (count +8), calls
// virtual slot 0x2c on every element.
class T49A670 {
public:
    virtual void Vt_0();
    virtual void Vt_1();
    virtual void Vt_2();
    virtual void Vt_3();
    virtual void Vt_4();
    virtual void Vt_5();
    virtual void Vt_6();
    virtual void Vt_7();
    virtual void Vt_8();
    virtual void Vt_9();
    virtual void Vt_10();
    virtual void Vat_2c();
};
class S49A670 {
public:
    char pad_00[4];
    T49A670** arr_4;
    int count_8;
    void M_49A670();
};

MATCH_FUNC(0x49A670)
void S49A670::M_49A670()
{
    for (int i = 0; i < count_8; i++)
        arr_4[i]->Vat_2c();
}
