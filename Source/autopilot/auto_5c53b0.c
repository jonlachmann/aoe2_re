
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_5c53b0(_DWORD *self)
{
  _DWORD *result; // eax
  int v2; // edx

  result = self + 595;
  v2 = 10;
  do
  {
    *(result - 10) = 0;
    *result++ = 0;
    --v2;
  }
  while ( v2 );
  self[605] = 0;
  return result;
}
