#include "C_pnl_inp.hpp"

extern void __cdecl Free_5F90B0(void* p);

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

MATCH_FUNC(0x4BD4B0)
char* C_pnl_inp::M_4BD4B0(int index)
{
    int i = 0;
    for (T4BD4B0Node* node = field_f8; node; node = node->next_24)
    {
        if (i == index)
            return (char*)node->field_0;
        i++;
    }
    g_73e355 = 0;
    return (char*)&g_73e355;
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

// 0x4BADD0 — build a 0x1000-byte stack buffer, pass it through the 0x4A2140
// capture helper, then hand it to vtable slot 0xFC with the zero mode.
MATCH_FUNC(0x4BADD0)
void C_pnl_inp::M_4BADD0(int a1)
{
    char buffer[0x1000];
    Other_4A2140(a1, buffer, 0x1000);
    Vat_fc(buffer, 0);
}

// 0x4BD4E0 — walk the +0xF8 indexed node chain to the matching index and copy
// the +0x00/+0x0C results; when the +0x10 flag is set and both optional output
// pointers exist, copy one of the two +0x14/+0x18 or +0x1C/+0x20 pairs.
MATCH_FUNC(0x4BD4E0)
void C_pnl_inp::M_4BD4E0(int index, void* a2, void* a3, int* a4, int* a5,
                         unsigned char flag)
{
    *(void**)a2 = 0;
    *(void**)a3 = 0;
    int i = 0;
    for (T4BD4B0Node* node = field_f8; node; node = node->next_24)
    {
        if (i == index)
        {
            *(void**)a2 = node->field_0;
            *(void**)a3 = node->field_c;
            if (node->field_10 != 0 && a4 != 0 && a5 != 0)
            {
                if (flag != 0)
                {
                    *a4 = node->field_1c;
                    *a5 = node->field_20;
                }
                else
                {
                    *a4 = node->field_14;
                    *a5 = node->field_18;
                }
            }
        }
        i++;
    }
}

// 0x4BD5F0 — tear down the +0xF8 indexed node chain: free each node's +0x00
// and +0x04 pointers, unlink and free the +0x0C chain through +0x08, then
// release the node itself and continue through +0x24; finally clear +0xF8 and
// the +0xFC word, reset the +0x00 list through 0x4BBD30 and notify slot +0x20.
WIP_FUNC(0x4BD5F0)
void C_pnl_inp::M_4BD5F0()
{
    C_pnl_inp* self = this;
    T4BD4B0Node* n = self->field_f8;
    if (n != 0)
    {
        while (n != 0)
        {
            if (n->field_0 != 0)
                Free_5F90B0(n->field_0);
            if (n->field_4 != 0)
                Free_5F90B0(n->field_4);
            while (n->field_c != 0)
            {
                T4BD5F0Chain* c = (T4BD5F0Chain*)n->field_c;
                void* next = c->next_8;
                Free_5F90B0(n->field_c);
                n->field_c = next;
            }
            T4BD4B0Node* old = n;
            n = n->next_24;
            Free_5F90B0(old);
        }
        self->field_f8 = n;
    }
    self->field_fc = 0;
    self->Hook_4BBD30(1);
    slot_008(1);
}
