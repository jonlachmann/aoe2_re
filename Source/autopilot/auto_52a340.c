
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

double __thiscall auto_52a340(int self, float a2)
{
  double result; // st7

  if ( *(_BYTE *)(*(_DWORD *)(self + 8) + 112) )
  {
    result = *(float *)(self + 64);
    if ( *(_BYTE *)(*(_DWORD *)(self + 8) + 112) != 1 )
      return result;
    if ( result < a2 )
    {
      *(float *)(self + 64) = a2;
      return *(float *)(self + 64);
    }
  }
  else
  {
    *(float *)(self + 64) = a2;
  }
  return *(float *)(self + 64);
}
