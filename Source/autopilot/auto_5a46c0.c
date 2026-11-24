
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_5a46c0(_DWORD *self)
{
  _DWORD *result; // eax
  int v2; // ecx

  result = self + 1810;
  v2 = 5;
  do
  {
    *(result - 2) = 0;
    *result = 0;
    result += 4;
    --v2;
  }
  while ( v2 );
  return result;
}
