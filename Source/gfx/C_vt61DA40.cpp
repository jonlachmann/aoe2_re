#include "C_vt61DA40.hpp"

extern float g_61dd2c;

MATCH_FUNC(0x41A030)
void C_vt61DA40::M_41A030(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
}

MATCH_FUNC(0x41A040)
int __stdcall C_vt61DA40::M_41A040(int a1, int a2, int a3, int a4, int* out)
{
    (void)a1; (void)a2; (void)a3; (void)a4;
    *out = 0;
    return -1;
}

MATCH_FUNC(0x41A050)
bool C_vt61DA40::M_41A050(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    return false;
}

MATCH_FUNC(0x41A060)
int C_vt61DA40::Get_41A060(int a, int b, int c, int d)
{
    (void)a; (void)b; (void)c; (void)d;
    return *(int*)((char*)this + 0x8);
}

MATCH_FUNC(0x41A070)
int C_vt61DA40::M_41A070(int a, int b, int c, int d, int e, int f, int g,
                         int h, int i)
{
    (void)a; (void)b; (void)c; (void)d; (void)e; (void)f; (void)g;
    (void)h; (void)i;
    return 0;
}

MATCH_FUNC(0x41A080)
int C_vt61DA40::M_41A080(int a, int b, int c, int d, int e, int f, int g,
                         int h, int i, int j, int k, int l)
{
    (void)a; (void)b; (void)c; (void)d; (void)e; (void)f; (void)g;
    (void)h; (void)i; (void)j; (void)k; (void)l;
    return 0;
}

MATCH_FUNC(0x41A090)
float C_vt61DA40::Get_41A090(int a, int b, int c)
{
    (void)a; (void)b; (void)c;
    return g_61dd2c;
}

MATCH_FUNC(0x41A0B0)
int C_vt61DA40::M_41A0B0()
{
    return 0x7fffffff;
}

MATCH_FUNC(0x41A0C0)
int C_vt61DA40::M_41A0C0(int a, int b, int c)
{
    (void)a; (void)b; (void)c;
    return -1;
}

MATCH_FUNC(0x41A0D0)
S41A0D0Triple C_vt61DA40::M_41A0D0(int a2, int a3)
{
    (void)a2;
    (void)a3;
    S41A0D0Triple t(0.0f, 0.0f, 0.0f);
    return t;
}

MATCH_FUNC(0x41A110)
S41A0D0Triple C_vt61DA40::M_41A110()
{
    S41A0D0Triple t(0.0f, 0.0f, 0.0f);
    return t;
}

MATCH_FUNC(0x474810)
float C_vt61DA40::Get_474810()
{
    return g_61dd2c;
}

MATCH_FUNC(0x52C430)
S41A0D0Triple C_vt61DA40::Copy_52C430()
{
    S41A0D0Triple t(field_38, field_40, field_3C);
    return t;
}

MATCH_FUNC(0x52C610)
float C_vt61DA40::Get_52C610()
{
    return *(float*)((char*)field_08 + 0x2c);
}

MATCH_FUNC(0x547EE0)
bool C_vt61DA40::M_547EE0()
{
    return false;
}
