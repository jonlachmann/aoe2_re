
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_4a22f0(_DWORD *self, _DWORD *a2)
{
  _DWORD *result; // eax

  result = a2;
  *a2 = self[36];
  a2[1] = self[37];
  a2[2] = self[38];
  a2[3] = self[39];
  return result;
}
