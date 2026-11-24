
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_45ab10(_DWORD *self, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  _DWORD *result; // eax

  *a5 = a4 * (a2 + 30) + 2 * self[102] + 30;
  result = a6;
  *a6 = a3 + 2 * self[102] + 8;
  return result;
}
