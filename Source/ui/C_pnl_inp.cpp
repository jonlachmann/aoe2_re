#include "C_pnl_inp.hpp"

extern unsigned char g_73e355;

MATCH_FUNC(0x4BBCE0)
void C_pnl_inp::M_4BBCE0(int a1)
{
    this->Hook_4A07A0(a1);
    if (field_14c != 0 && field_148 != 0) {
        T4BBCE0Sub* sub = field_148;
        if (field_6c != 0)
            sub->Vat_14(field_184);
        else
            sub->Vat_14(0);
    }
}

WIP_FUNC(0x4BD4B0)
char* C_pnl_inp::M_4BD4B0(int index)
{
    int i = 0;
    T4BD4B0Node* node = field_f8;
    if (node) {
        for (;;) {
            if (i == index)
                return node->field_0;
            node = node->next_24;
            i++;
            if (!node)
                break;
        }
    }
    g_73e355 = 0;
    return (char*)0x73e355;
}

MATCH_FUNC(0x408050)
void C_pnl_inp::M_408050(int a, int b)
{
    (void)a; (void)b;
}

MATCH_FUNC(0x4B4600)
void C_pnl_inp::SetInt_4B4600(int v)
{
    *(int*)((char*)this + 0x188) = v;
}

MATCH_FUNC(0x4BAF60)
void C_pnl_inp::M_4BAF60(int a, int b, int c, int d)
{
    (void)c; (void)d;
    Vat_f4(a, b);
}

MATCH_FUNC(0x4BCE20)
int C_pnl_inp::M_4BCE20(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    T4BCE20Sub* s = field_40;
    if (s)
        s->Vat_C4(this, 1, 0, 0);
    return 0;
}
