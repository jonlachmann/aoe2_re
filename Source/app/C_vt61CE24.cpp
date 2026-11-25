#include "C_vt61CE24.hpp"

extern float g_61c598;
extern float g_61c5a8;
extern float g_61c584;
extern float g_61C584;
extern void __stdcall sub_48CB50(int a1);

MATCH_FUNC(0x407E30)
void C_vt61CE24::M_407E30()
{
    if (this->field_130 != 0)
        this->field_130->Clear_4058C0();
    this->Hook_526CA0();
}

MATCH_FUNC(0x407FB0)
void C_vt61CE24::M_407FB0()
{
    this->Hook_529AF0();
    this->field_130->Clear_405860();
}

MATCH_FUNC(0x408010)
void C_vt61CE24::M_408010(int a1)
{
    sub_48CB50(a1);
    this->field_130->Clear_4058C0();
}

MATCH_FUNC(0x408030)
void C_vt61CE24::M_408030()
{
    this->field_130->Clear_4058C0();
    this->Hook_52A990();
}

MATCH_FUNC(0x408060)
void C_vt61CE24::M_408060(void* a1, int a2, int a3, int a4)
{
    if (a1 != (void*)this)
    {
        Vat_308(a1, a2, a3, a4, 0, -1);
        this->byte_134++;
    }
}

MATCH_FUNC(0x407E50)
void C_vt61CE24::M_407E50(int a1, int a2, int a3, int a4, int a5)
{
    this->Hook_48C240(a1, a2, a3, a4, a5);
    this->byte_12c = 0;
}

MATCH_FUNC(0x407B30)
bool C_vt61CE24::M_407B30()
{
    return false;
}

MATCH_FUNC(0x407B40)
int C_vt61CE24::M_407B40()
{
    return 0;
}

MATCH_FUNC(0x407B80)
int C_vt61CE24::M_407B80(int unused)
{
    (void)unused;
    return 0;
}

MATCH_FUNC(0x407B90)
float C_vt61CE24::Get_407B90(int unused)
{
    (void)unused;
    return g_61c598;
}

MATCH_FUNC(0x407BA0)
int C_vt61CE24::M_407BA0()
{
    return -1;
}

MATCH_FUNC(0x407BB0)
float C_vt61CE24::Get_407BB0()
{
    return g_61c5a8;
}

MATCH_FUNC(0x407BC0)
bool C_vt61CE24::M_407BC0(int unused)
{
    (void)unused;
    return false;
}

MATCH_FUNC(0x407BD0)
bool C_vt61CE24::M_407BD0(int unused)
{
    (void)unused;
    return true;
}

MATCH_FUNC(0x407BE0)
bool C_vt61CE24::M_407BE0()
{
    return true;
}

MATCH_FUNC(0x407BF0)
void C_vt61CE24::M_407BF0(int a, int b, int c, int d, int e, int f)
{
    (void)a; (void)b; (void)c; (void)d; (void)e; (void)f;
}

MATCH_FUNC(0x407C30)
int C_vt61CE24::M_407C30(int a, int b, int c, int d, int e, int f)
{
    (void)a; (void)b; (void)c; (void)d; (void)e; (void)f;
    return 0;
}

MATCH_FUNC(0x407C50)
void C_vt61CE24::M_407C50(int unused)
{
    (void)unused;
}

MATCH_FUNC(0x407C60)
int C_vt61CE24::M_407C60(int unused)
{
    (void)unused;
    return -1;
}

MATCH_FUNC(0x407C70)
float C_vt61CE24::Get_407C70()
{
    return *(float*)((char*)this + 0xa4);
}

MATCH_FUNC(0x407C80)
float C_vt61CE24::Get_407C80()
{
    return *(float*)((char*)this + 0xb8);
}

MATCH_FUNC(0x407C90)
void C_vt61CE24::Set_407C90()
{
    *(int*)((char*)this + 0xdc) = 0x0;
}

MATCH_FUNC(0x407CA0)
int C_vt61CE24::Get_407CA0()
{
    return *(int*)((char*)this + 0xdc);
}

MATCH_FUNC(0x407CB0)
S407CB0Vec3 C_vt61CE24::CopyE4_407CB0()
{
    return vec_E4;
}

MATCH_FUNC(0x407CE0)
int C_vt61CE24::Get_407CE0()
{
    return *(int*)((char*)this + 0x108);
}

MATCH_FUNC(0x407CF0)
int C_vt61CE24::Get_407CF0()
{
    return *(int*)((char*)this + 0x114);
}

MATCH_FUNC(0x407D00)
S407CB0Vec3 C_vt61CE24::CopyF0_407D00()
{
    return vec_F0;
}

MATCH_FUNC(0x408650)
void C_vt61CE24::M_408650(int unused)
{
    (void)unused;
}

MATCH_FUNC(0x408660)
void C_vt61CE24::Wrap_408660()
{
    ((S408660Target*)field_08)->Vat_30(field_0C);
}

MATCH_FUNC(0x408670)
void C_vt61CE24::Wrap_408670()
{
    ((S408660Target*)field_08)->Vat_34(field_0C);
}

MATCH_FUNC(0x408BC0)
float C_vt61CE24::Get_408BC0()
{
    return *(float*)((char*)field_08 + 0x100);
}

MATCH_FUNC(0x41A0A0)
float C_vt61CE24::Get_41A0A0(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    return g_61c584;
}

MATCH_FUNC(0x41A410)
char C_vt61CE24::Dec_41A410(int unused)
{
    (void)unused;
    unsigned char result = this->field_4F;
    if (result > 0) {
        result = --result;
        this->field_4F = result;
    }
    return (char)result;
}

MATCH_FUNC(0x4747F0)
float C_vt61CE24::Get_4747F0(int unused)
{
    (void)unused;
    return g_61c584;
}

MATCH_FUNC(0x474800)
float C_vt61CE24::Get_474800()
{
    return g_61c584;
}

MATCH_FUNC(0x48CB90)
unsigned char C_vt61CE24::M_48CB90()
{
    if (field_A4 > g_61C584)
        return 1;
    return 0;
}

MATCH_FUNC(0x48CBB0)
void C_vt61CE24::Set_48CBB0()
{
    *(int*)((char*)this + 0xa4) = 0x0;
}

MATCH_FUNC(0x48E2D0)
double C_vt61CE24::Get_48E2D0()
{
    int* v1 = (int*)this->field_10;
    if (v1 && *(float*)((char*)v1 + 100) > 0.0)
        return *(float*)((char*)this->field_08 + 196) * *(float*)((char*)v1 + 100);
    else
        return *(float*)((char*)this->field_08 + 196);
}

MATCH_FUNC(0x48E330)
void C_vt61CE24::SetByte_48E330(unsigned char v)
{
    *(unsigned char*)((char*)this + 0xd4) = v;
}

MATCH_FUNC(0x48E340)
int C_vt61CE24::Get_48E340(int index)
{
    if (index < 0 || index >= this->count)
        return 0;
    else
        return (int)this->records + 12 * index;
}

MATCH_FUNC(0x48F470)
float C_vt61CE24::M_48F470()
{
    if (field_110 != 0)
        return *(float*)((char*)field_110 + 8);
    return g_61C584;
}

MATCH_FUNC(0x48F520)
float C_vt61CE24::M_48F520()
{
    if (field_110 != 0)
        return *(float*)((char*)field_110 + 0x14);
    return g_61C584;
}

MATCH_FUNC(0x48F950)
void C_vt61CE24::M_48F950(int v)
{
    char* p = (char*)field_108;
    if (p != 0)
        *(int*)(p + 0x28) = v;
}

MATCH_FUNC(0x48F970)
int C_vt61CE24::Get_48F970()
{
    return *(int*)((char*)this + 0x4);
}

MATCH_FUNC(0x4919A0)
double C_vt61CE24::Get_4919A0(int unused)
{
    (void)unused;
    int* v2 = (int*)this->field_10;
    if (v2 && *(float*)((char*)v2 + 100) > 0.0)
        return *(float*)((char*)this->field_08 + 196) * *(float*)((char*)v2 + 100);
    else
        return *(float*)((char*)this->field_08 + 196);
}

MATCH_FUNC(0x4921B0)
int C_vt61CE24::UseCC_4921B0()
{
    int* p = ((S492100Sub*)field_08)->field_cc;
    if (p != 0) {
        Vat_40(p);
        return 1;
    }
    return 0;
}

MATCH_FUNC(0x4921D0)
int C_vt61CE24::UseC8_4921D0()
{
    int* p = ((S492100Sub*)field_08)->field_c8;
    if (p != 0) {
        Vat_40(p);
        return 1;
    }
    return 0;
}

MATCH_FUNC(0x4921F0)
int C_vt61CE24::M_4921F0()
{
    char* q = ((T4921F0*)field_08)->field_18;
    if (q != 0) {
        Vat_40(q);
        return 1;
    }
    return 0;
}

MATCH_FUNC(0x52A440)
void C_vt61CE24::M_52A440(int v)
{
    if (field_18 != 0)
        ((T41A820*)field_18)->Other_41A820(v);
}

MATCH_FUNC(0x52AE20)
bool C_vt61CE24::Less_52AE20()
{
    if (Value() < ((S52AE20B*)field_08)->field_30)
        return true;
    return false;
}

MATCH_FUNC(0x52B330)
void C_vt61CE24::Set_52B330(unsigned short a, int b)
{
    field_4C = a;
    field_44 = b;
}

MATCH_FUNC(0x52BC80)
char C_vt61CE24::Get_52BC80()
{
    return *(char*)((char*)this + 0x76);
}

MATCH_FUNC(0x52BC90)
void C_vt61CE24::SetByte_52BC90(unsigned char v)
{
    *(unsigned char*)((char*)this + 0x76) = v;
}

MATCH_FUNC(0x52C6A0)
int C_vt61CE24::Get_52C6A0()
{
    int* result = (int*)this->field_24;
    if (!result)
        return (int)result;
    return *(int*)((char*)result + 4);
}

MATCH_FUNC(0x52AF30)
void C_vt61CE24::M_52AF30()
{
    T52AF30Sub* sub = field_20;
    if (sub)
        sub->Vat_EC(this);
}

MATCH_FUNC(0x48D470)
void C_vt61CE24::M_48D470(void* p)
{
    *(void**)((char*)this + 0xb8) = p;
    Vat_2F4();
}
