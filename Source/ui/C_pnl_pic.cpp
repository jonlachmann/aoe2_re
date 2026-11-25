#include "C_pnl_pic.hpp"

extern int (__cdecl *g_61C3C8)();

class T4A1160NodeObj {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08();
    virtual void Vt_09();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual int Vt_19();
};
class T4A1160Node {
public:
    T4A1160NodeObj* field_0;
    T4A1160Node* field_4;
};

// 0x4A1160 — advance the +0xF0 state machine when the +0x6C subobject and
// one-shot state are present, dispatching by the +0xF1 mode, then scan the
// +0x5C chain for the first object whose slot +0x4C reports success.
MATCH_FUNC(0x4A1160)
int C_pnl_pic::M_4A1160()
{
    if (field_6c != 0 && field_f0 == 1)
    {
        int t = g_61C3C8();
        if ((t - field_d8) >= field_c0)
        {
            field_f0 = 2;
            if (field_f1 == 1)
                slot_038(field_c8, field_cc, field_d0, field_d4);
            else
                slot_043(field_c8, field_cc, field_d0, field_d4);
        }
    }
    for (T4A1160Node* n = (T4A1160Node*)field_5c; n; n = n->field_4)
    {
        int r = n->field_0->Vt_19();
        if (r != 0)
            return r;
    }
    return 0;
}

// 0x4B8510 — tick a picture panel: when the +0x21C gate is set and the elapsed
// time since +0x22C reaches the +0x228 threshold, advance the +0x218 phase
// counter (wrapping at +0x224), drive slot +0x20 with one and stamp the clock
// into +0x22C; then forward the same-object 0x4A1160 update.
MATCH_FUNC(0x4B8510)
void C_pnl_pic::M_4B8510()
{
    if (field_21c != 0)
    {
        int t = g_61C3C8();
        unsigned int diff = (unsigned int)(t - field_22c);
        if (diff >= (unsigned int)field_228)
        {
            int phase = field_218;
            if (phase == field_224)
                field_218 = 0;
            else
                field_218 = phase + 1;
            slot_008(1);
            field_22c = t;
        }
    }
    M_4A1160();
}
