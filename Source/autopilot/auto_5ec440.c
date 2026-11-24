
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_5ec440(_DWORD *self, int a2)
{
  _DWORD *result; // eax

  result = self;
  self[2] = a2;
  *self = 0;
  self[1] = 0;
  return result;
}
