#include "Function.hpp"

// sub_548840 (VA 0x548840) - member: calls virtual slot 0x5c with 4 when both
// the byte arg and field_10 are set, else with 3.
class S548840 {
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
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vat_5c(int v);
    char pad_04[0x10 - 0x04];
    int field_10;
    void M_548840(unsigned char v);
    void M_540DD0(unsigned char v);
    void M_54C1F0(unsigned char v);
    void M_54CF90(unsigned char v);
    void M_540800(unsigned char unused);
};

MATCH_FUNC(0x548840)
void S548840::M_548840(unsigned char v)
{
    if (v != 0 && field_10 != 0)
        Vat_5c(4);
    else
        Vat_5c(3);
}

MATCH_FUNC(0x540DD0)
void S548840::M_540DD0(unsigned char v)
{
    if (v != 0)
        Vat_5c(6);
}

MATCH_FUNC(0x54C1F0)
void S548840::M_54C1F0(unsigned char v)
{
    if (v != 0)
        Vat_5c(0xb);
}

MATCH_FUNC(0x54CF90)
void S548840::M_54CF90(unsigned char v)
{
    if (v != 0)
        Vat_5c(2);
}

MATCH_FUNC(0x540800)
void S548840::M_540800(unsigned char unused)
{
    (void)unused;
    if (field_10 != 0)
        Vat_5c(4);
    else
        Vat_5c(0xd);
}
