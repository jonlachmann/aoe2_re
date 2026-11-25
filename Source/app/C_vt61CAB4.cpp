#include "C_vt61CAB4.hpp"

extern char g_vt_61CAB4f;
MATCH_FUNC(0x4057D0)
void C_vt61CAB4::Init_4057D0()
{
    *(void**)this = &g_vt_61CAB4f;
    this->Clear_4058C0();
    this->field_04 = 0;
    this->field_08 = 0;
}

MATCH_FUNC(0x4058C0)
void C_vt61CAB4::Clear_4058C0()
{
    while (this->field_08 != 0)
        this->Hook_405FD0();
}

MATCH_FUNC(0x4060F0)
int C_vt61CAB4::Get_4060F0()
{
    N4061C0* n = this->field_08;
    if (n != 0)
        return ((T4061C0*)n->obj_0)->Vt_11();
    return 0;
}

MATCH_FUNC(0x406110)
int C_vt61CAB4::M_406110(int a1, int a2, int a3, int a4)
{
    N4061C0* n = this->field_08;
    if (n != 0)
        return ((T4061C0*)n->obj_0)->Vt_12(a1, a2, a3, a4);
    return 0;
}

MATCH_FUNC(0x406140)
int C_vt61CAB4::M_406140(int a1, int a2, int a3, int a4)
{
    N4061C0* n = this->field_08;
    if (n != 0)
        return ((T4061C0*)n->obj_0)->Vt_13(a1, a2, a3, a4);
    return 0;
}

MATCH_FUNC(0x4060B0)
int C_vt61CAB4::Find_4060B0(int a1)
{
    N4061C0* n = this->field_08;
    while (n != 0)
    {
        short id = ((T4061C0*)n->obj_0)->Vt_6();
        if ((int)id == a1)
            return 1;
        n = n->next_4;
    }
    return 0;
}

MATCH_FUNC(0x406180)
void* C_vt61CAB4::Get_406180(int a1)
{
    N4061C0* n = this->field_08;
    while (n != 0)
    {
        short id = ((T4061C0*)n->obj_0)->Vt_6();
        if ((int)id == a1)
            return n->obj_0;
        n = n->next_4;
    }
    return 0;
}

extern void* __cdecl sub_5F8FF0(int a1, int a2);
extern void __cdecl sub_5F90B0(void* p);

MATCH_FUNC(0x405F00)
void C_vt61CAB4::M_405F00(int a1)
{
    if (*(unsigned char*)((char*)this->field_04 + 0x48) > 2)
    {
        if (a1 != 0)
            ((T4061C0*)a1)->Vt_0(1);
    }
    else
    {
        N4061C0* node = (N4061C0*)sub_5F8FF0(1, 8);
        node->obj_0 = (char*)a1;
        node->next_4 = this->field_08;
        this->field_08 = node;
        ((T4061C0*)a1)->Vt_7(1);
    }
}

MATCH_FUNC(0x406060)
void C_vt61CAB4::M_406060(int a1)
{
    if (*(unsigned char*)((char*)this->field_04 + 0x48) > 2)
    {
        if (a1 != 0)
            ((T4061C0*)a1)->Vt_0(1);
    }
    else
    {
        N4061C0* node = (N4061C0*)sub_5F8FF0(1, 8);
        node->obj_0 = (char*)a1;
        node->next_4 = this->field_08;
        this->field_08 = node;
    }
}

MATCH_FUNC(0x406020)
void* C_vt61CAB4::M_406020()
{
    N4061C0* node = this->field_08;
    void* obj = 0;
    if (node != 0)
    {
        this->field_08 = node->next_4;
        obj = node->obj_0;
        sub_5F90B0(node);
        N4061C0* next = this->field_08;
        if (next != 0 && *(unsigned char*)((char*)this->field_04 + 0x48) < 3)
            ((T4061C0*)next->obj_0)->Vt_7(0);
    }
    return obj;
}

MATCH_FUNC(0x4061C0)
void C_vt61CAB4::M_4061C0(int v)
{
    N4061C0* n = field_08;
    while (n != 0) {
        ((T4061C0*)n->obj_0)->Vat_40(v);
        n = n->next_4;
    }
}

MATCH_FUNC(0x406220)
void C_vt61CAB4::Clear_406220(char* p)
{
    *p = 0;
}
