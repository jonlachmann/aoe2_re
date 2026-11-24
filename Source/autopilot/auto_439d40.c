
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_439d40(_DWORD *self)
{
  _DWORD *result; // eax
  int v2; // edx

  result = self + 16;
  v2 = 55;
  do
  {
    *(result - 1) = 0;
    *result = 0;
    result[1] = 0;
    result[2] = 0;
    result[3] = 0;
    result[4] = 0;
    result[5] = 0;
    result[6] = 0;
    *(result - 2) = 0;
    result += 9;
    --v2;
  }
  while ( v2 );
  return result;
}
