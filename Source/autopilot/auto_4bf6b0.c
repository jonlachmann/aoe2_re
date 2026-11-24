
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__stdcall auto_4bf6b0(_DWORD *a1)
{
  _DWORD *result; // eax

  result = a1;
  *a1 = -1;
  a1[1] = -1;
  a1[4] = 0;
  a1[5] = 0;
  a1[2] = 0;
  a1[3] = 0;
  return result;
}
