
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

double __thiscall auto_5a5ad0(_DWORD *self, int a2)
{
  double result; // st7
  int v3; // eax
  float *v4; // ecx
  _WORD *v5; // eax
  int v6; // edx

  result = 0.0;
  v3 = *(_DWORD *)(self[29] + 4 * a2);
  if ( v3 )
  {
    v4 = (float *)(v3 + 120);
    v5 = (_WORD *)(v3 + 114);
    v6 = 3;
    do
    {
      if ( *v5 == 4 )
        result = result - *v4;
      ++v5;
      ++v4;
      --v6;
    }
    while ( v6 );
  }
  return result;
}
