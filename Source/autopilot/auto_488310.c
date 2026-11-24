
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_488310(_DWORD *self, int a2, int a3, int a4)
{
  _DWORD *result; // eax

  result = self;
  *self = a2;
  self[1] = a3;
  self[2] = a4;
  return result;
}
